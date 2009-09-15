/* vim:set et sts=4: */

#include <ibus.h>
#include <string.h>
#include "PinyinEngine.h"

namespace PY {

/* init static members */
guint PinyinEngine::m_option = 0x0;

/* constructor */
PinyinEngine::PinyinEngine (IBusEngine *engine)
    : m_engine (engine),
      m_need_update (0),
      m_lookup_table (NULL),
      m_mode_prop (NULL),
      m_props (NULL)

{
    m_lookup_table = ibus_lookup_table_new (10, 0, TRUE, FALSE);
}

/* destructor */
PinyinEngine::~PinyinEngine (void)
{
}

gboolean
PinyinEngine::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{

    // ignore release event
    if (modifiers & IBUS_RELEASE_MASK) {
        return TRUE;
    }

    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK );

    /* process letter at first */
    if (G_LIKELY (keyval >= IBUS_a && keyval <= IBUS_z)) {
        if (G_LIKELY (modifiers == 0)) {
            if (m_pinyin_editor.insert (keyval)) {
                update (FALSE);
            }
        }
        return !m_pinyin_editor.isEmpty ();
    }

    /* process ' */
    if (keyval == IBUS_apostrophe) {
        if (G_UNLIKELY (m_pinyin_editor.isEmpty ()))
            return FALSE;
        if (G_LIKELY (modifiers == 0))
            if (m_pinyin_editor.insert (IBUS_apostrophe))
                update (FALSE);
        return TRUE;
    }

    if (G_UNLIKELY (m_pinyin_editor.isEmpty ()))
        return FALSE;

    if (keyval >= IBUS_0 && keyval <= IBUS_9) {
        guint i;
        if (G_UNLIKELY (keyval == IBUS_0))
            i = 10;
        else
            i = keyval - IBUS_1;
        selectCandidate (i);
        return TRUE;
    }

    /* process some cursor control keys */
    gboolean _update = FALSE;
    switch (keyval) {
    case IBUS_space:
        commit ();
        break;
    case IBUS_BackSpace:
        if (G_LIKELY (modifiers == 0))
            _update = m_pinyin_editor.removeCharBefore ();
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK))
            _update = m_pinyin_editor.removeWordBefore ();
        break;

    case IBUS_Delete:
        if (G_LIKELY (modifiers == 0))
            _update = m_pinyin_editor.removeCharAfter ();
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK))
            _update = m_pinyin_editor.removeWordAfter ();
        break;

    case IBUS_Left:
        if (G_LIKELY (modifiers == 0)) {
            // move left single char
            _update = m_pinyin_editor.moveCursorLeft ();
        }
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK)) {
            // move left one pinyin
            _update = m_pinyin_editor.moveCursorLeftByWord ();
        }
        break;

    case IBUS_Right:
        if (G_LIKELY (modifiers == 0)) {
            // move right single char
            _update = m_pinyin_editor.moveCursorRight ();
        }
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK)) {
            // move right to end
            _update = m_pinyin_editor.moveCursorToEnd ();
        }
        break;

    case IBUS_Home:
        if (G_LIKELY (modifiers == 0)) {
            // move to begin
            _update = m_pinyin_editor.moveCursorToBegin ();
        }
        break;

    case IBUS_End:
        if (G_LIKELY (modifiers == 0)) {
            // move to end
            _update = m_pinyin_editor.moveCursorToEnd ();
        }
        break;

    case IBUS_Up:
        cursorUp (); break;
    case IBUS_Down:
        cursorDown (); break;
    case IBUS_Page_Up:
        pageUp (); break;
    case IBUS_Page_Down:
        pageDown (); break;
    case IBUS_Escape:
        reset (); break;
    default:
        return TRUE;
    }
    if (G_LIKELY (_update))
        update (FALSE);
    return TRUE;
}

void
PinyinEngine::pageUp (void)
{
    if (ibus_lookup_table_page_up (m_lookup_table)) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

void
PinyinEngine::pageDown (void)
{
    if (ibus_lookup_table_page_down (m_lookup_table)) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

void
PinyinEngine::cursorUp (void)
{
    if (ibus_lookup_table_cursor_up (m_lookup_table)) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

void
PinyinEngine::cursorDown (void)
{
    if (ibus_lookup_table_cursor_down (m_lookup_table)) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

void
PinyinEngine::updatePreeditText (void)
{
    if (G_UNLIKELY ((!m_phrase_editor.string1 ()) && (!m_phrase_editor.string2 ()))) {
        ibus_engine_hide_preedit_text (m_engine);
        return;
    }

    m_buffer.truncate (0);
    m_buffer << m_phrase_editor.string1 ();

    if (m_phrase_editor.string1 () && m_phrase_editor.string2 ())
        m_buffer << ' ';

    m_buffer << m_phrase_editor.string2 ();
    m_buffer << m_pinyin_editor.textAfterPinyin ();

    Pointer<IBusText> preedit_text = ibus_text_new_from_static_string ((const gchar *) m_buffer);
    ibus_text_append_attribute (preedit_text, IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, -1);
    ibus_engine_update_preedit_text (m_engine, preedit_text, m_buffer.length (), TRUE);
}

void
PinyinEngine::updateAuxiliaryText (void)
{

    /* clear pinyin array */
    if (G_UNLIKELY (m_pinyin_editor.isEmpty ())) {
        ibus_engine_hide_auxiliary_text (m_engine);
        return;
    }

    guint cursor_pos;
    guint len;

    m_buffer.truncate (0);
    if (G_UNLIKELY (m_phrase_editor.string1 ())) {
        m_buffer << m_phrase_editor.string1 () << ' ';
    }

    for (guint i = m_phrase_editor.cursor (); i < m_pinyin_editor.pinyin().length (); ++i) {
        if (G_LIKELY (i != m_phrase_editor.cursor ()))
            m_buffer << '\'';
        const Pinyin *p = m_pinyin_editor.pinyin()[i];
        m_buffer << p->sheng;
        m_buffer << p->yun;
    }

    len = m_buffer.length ();
    if (G_UNLIKELY (m_pinyin_editor.pinyinLength () == m_pinyin_editor.cursor ())) {
        /* aux = pinyin + non-pinyin */
        cursor_pos =  m_buffer.utf8Length ();
        m_buffer << '|' << m_pinyin_editor.textAfterPinyin ();
    }
    else {
        /* aux = pinyin + non-pinyin before cursor + non-pinyin after cursor */
        m_buffer.append (m_pinyin_editor.textAfterPinyin (),
                     m_pinyin_editor.cursor () - m_pinyin_editor.pinyinLength ());
        cursor_pos =  m_buffer.utf8Length ();
        m_buffer  << '|' << m_pinyin_editor.textAfterCursor ();
    }

    Pointer<IBusText> aux_text = ibus_text_new_from_static_string (m_buffer);
    ibus_text_append_attribute (aux_text, IBUS_ATTR_TYPE_FOREGROUND, 0x00afafaf, len, cursor_pos);
    ibus_text_append_attribute (aux_text, IBUS_ATTR_TYPE_FOREGROUND, 0x00afafaf, cursor_pos + 1, -1);
    ibus_engine_update_auxiliary_text (m_engine, aux_text, TRUE);
}

void
PinyinEngine::updateLookupTable (void)
{
    ibus_lookup_table_clear (m_lookup_table);
    guint candidate_nr = m_phrase_editor.candidateNumber ();

    if (G_UNLIKELY (candidate_nr == 0)) {
        ibus_engine_hide_lookup_table (m_engine);
        return;
    }

    Pointer<IBusText> text;
    for (guint i = 0; i < candidate_nr; i++) {
        text = ibus_text_new_from_static_string (m_phrase_editor.candidate (i));
        ibus_lookup_table_append_candidate (m_lookup_table, text);
    }

    ibus_engine_update_lookup_table_fast (m_engine,
                                          m_lookup_table,
                                          TRUE);
}

void
PinyinEngine::updatePhraseEditor (void)
{
    m_phrase_editor.update (m_pinyin_editor.pinyin ());
}

void
PinyinEngine::commit (void)
{
    if (m_phrase_editor.string1 () || m_phrase_editor.string2 ()) {
        m_buffer.truncate (0);
        m_buffer << m_phrase_editor.string1 () << m_phrase_editor.string2 () << m_pinyin_editor.textAfterPinyin ();
        Pointer<IBusText> text = ibus_text_new_from_static_string (m_buffer);
        ibus_engine_commit_text (m_engine, text);
        m_phrase_editor.commit ();
        reset ();
    }
}

gboolean
PinyinEngine::selectCandidate (guint i)
{
    guint page_size = ibus_lookup_table_get_page_size (m_lookup_table);
    guint cursor_pos = ibus_lookup_table_get_cursor_pos (m_lookup_table);
    i += (cursor_pos / page_size) * page_size;

    if (G_LIKELY (i == 0)) {

    }
    if (m_phrase_editor.selectCandidate (i)) {
        if (G_UNLIKELY (m_phrase_editor.cursor () == m_pinyin_editor.pinyin ().length ())) {
            commit ();
        }
        else {
            updatePreeditText ();
            updateAuxiliaryText ();
            updateLookupTable ();
        }
    }
    return TRUE;
}

};

