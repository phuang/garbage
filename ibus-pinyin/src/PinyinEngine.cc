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
            m_pinyin_editor.insert (IBUS_apostrophe);
        return TRUE;
    }

    if (G_UNLIKELY (m_pinyin_editor.isEmpty ()))
        return FALSE;

    if (keyval >= IBUS_1 && keyval <= IBUS_0) {
        guint i;
        if (G_UNLIKELY (keyval == IBUS_0))
            i = 10;
        else
            i = keyval - IBUS_1;
        selectPhrase (i);
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
        return TRUE;
    case IBUS_Down:
        return TRUE;
    case IBUS_Page_Up:
        return TRUE;
    case IBUS_Page_Down:
        return TRUE;
    case IBUS_Escape:
        reset ();
        return TRUE;
    default:
        return TRUE;
    }
    if (G_LIKELY (_update))
        update (FALSE);
    return TRUE;
}

void
PinyinEngine::updatePreeditText (void)
{
    const PhraseArray & phrases = m_phrase_editor.phrases ();

    if (G_UNLIKELY (! phrases)) {
        ibus_engine_hide_preedit_text (m_engine);
        return;
    }

    m_buffer.truncate (0);
    for (guint i = 0; i < phrases.length (); i++) {
        m_buffer << phrases[i].phrase;
    }

    Pointer<IBusText> preedit_text = ibus_text_new_from_static_string ((const gchar *) m_buffer);
    ibus_text_append_attribute (preedit_text, IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, 0 -1);
    ibus_engine_update_preedit_text (m_engine, preedit_text, m_phrase_editor.cursor (), TRUE);
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
    for (guint i = 0; i < m_pinyin_editor.pinyin().length (); ++i) {
        if (G_LIKELY (i != 0))
            m_buffer << '\'';
        const Pinyin *p = m_pinyin_editor.pinyin()[i];
        m_buffer << p->sheng;
        m_buffer << p->yun;
    }

    len = m_buffer.length ();
    if (G_UNLIKELY (m_pinyin_editor.pinyinLength () == m_pinyin_editor.cursor ())) {
        cursor_pos =  m_buffer.length ();
        m_buffer << '|' << ((const gchar *)m_pinyin_editor.text ()) + m_pinyin_editor.pinyinLength ();
    }
    else {
        m_buffer.append (((const gchar *)m_pinyin_editor.text ()) + m_pinyin_editor.pinyinLength (),
                     m_pinyin_editor.cursor () - m_pinyin_editor.pinyinLength ());
        cursor_pos =  m_buffer.length ();
        m_buffer << '|' << ((const gchar *)m_pinyin_editor.text ()) + m_pinyin_editor.cursor ();
    }

    Pointer<IBusText> aux_text = ibus_text_new_from_static_string (m_buffer);
    ibus_text_append_attribute (aux_text, IBUS_ATTR_TYPE_FOREGROUND, 0x00afafaf, len, cursor_pos);
    ibus_text_append_attribute (aux_text, IBUS_ATTR_TYPE_FOREGROUND, 0x00afafaf, cursor_pos + 1, -1);
    ibus_engine_update_auxiliary_text (m_engine, aux_text, TRUE);
}

void
PinyinEngine::updateLookupTable (void)
{
    const PhraseArray &candidates = m_phrase_editor.candidates ();

    ibus_lookup_table_clear (m_lookup_table);

    if (G_UNLIKELY (!candidates)) {
        ibus_engine_hide_lookup_table (m_engine);
        return;
    }

    Pointer<IBusText> text;
    for (guint i = 0; i < candidates.length (); i++) {
        text = ibus_text_new_from_static_string (candidates[i].phrase);
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
    const PhraseArray &phrases = m_phrase_editor.phrases ();

    if (G_LIKELY (phrases)) {
        m_buffer.truncate (0);
        for (guint i = 0; i < phrases.length (); i++) {
            m_buffer << phrases[i].phrase;
        }
        Pointer<IBusText> text = ibus_text_new_from_static_string (m_buffer);
        ibus_engine_commit_text (m_engine, text);
        reset ();
    }
}

gboolean
PinyinEngine::selectPhrase (guint i)
{
    return TRUE;
}
};

