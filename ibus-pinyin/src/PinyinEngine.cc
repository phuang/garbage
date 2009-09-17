/* vim:set et sts=4: */

#include <ibus.h>
#include <string.h>
#include "PinyinEngine.h"
#include "HalfFullConverter.h"
#include "Config.h"
#include "Text.h"
#include "Util.h"

namespace PY {

/* constructor */
PinyinEngine::PinyinEngine (IBusEngine *engine)
    : m_engine (engine),
      m_need_update (0),
      m_lookup_table (NULL),
      m_prop_chinese (NULL),
      m_prop_full_letter (NULL),
      m_prop_full_punct (NULL),
      m_props (NULL),
      m_mode_chinese (TRUE),
      m_mode_full_letter (TRUE),
      m_mode_full_punct (TRUE),
      m_quote (TRUE),
      m_double_quote (TRUE)
{
    /* create lookup table */
    m_lookup_table = ibus_lookup_table_new (10, 0, TRUE, FALSE);

    /* create properties */
    m_props = ibus_prop_list_new ();
    m_prop_chinese = ibus_property_new ("mode.chinese",
                                        PROP_TYPE_NORMAL,
                                        Text ("CH"),
                                        NULL,
                                        Text ("Chinese"),
                                        TRUE,
                                        TRUE,
                                        PROP_STATE_UNCHECKED,
                                        NULL);
    ibus_prop_list_append (m_props, m_prop_chinese);

    m_prop_full_letter = ibus_property_new ("mode.full_letter",
                                            PROP_TYPE_NORMAL,
                                            Text ("Aa"),
                                            NULL,
                                            Text ("Full/Half width letter"),
                                            TRUE,
                                            TRUE,
                                            PROP_STATE_UNCHECKED,
                                            NULL);
    ibus_prop_list_append (m_props, m_prop_full_letter);

    m_prop_full_punct = ibus_property_new ("mode.full_punct",
                                           PROP_TYPE_NORMAL,
                                           Text (",."),
                                           NULL,
                                           Text ("Full/Half width punctuation"),
                                           TRUE,
                                           TRUE,
                                           PROP_STATE_UNCHECKED,
                                           NULL);
    ibus_prop_list_append (m_props, m_prop_full_punct);
}

/* destructor */
PinyinEngine::~PinyinEngine (void)
{
}

#define MASK_FILTER(modifiers) (modifiers & (IBUS_CONTROL_MASK | IBUS_MOD1_MASK | IBUS_SUPER_MASK | IBUS_HYPER_MASK | IBUS_META_MASK))

/**
 * process ascii letter
 */
inline gboolean
PinyinEngine::processPinyin (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (MASK_FILTER(modifiers) != 0))
        return FALSE;

    if (G_UNLIKELY (m_mode_chinese == FALSE ||
                    modifiers & (IBUS_SHIFT_MASK | IBUS_LOCK_MASK))) {
        if (G_LIKELY (m_pinyin_editor.isEmpty ())) {
            if (m_mode_full_letter)
                commit (HalfFullConverter::toFull (keyval));
            else
                commit ((gchar) keyval);
            return TRUE;
        }
    }

    if (m_pinyin_editor.insert (keyval)) {
        update (FALSE);
    }
    return TRUE;
}

inline gboolean
PinyinEngine::processNumber (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (m_pinyin_editor.isEmpty ())) {
        if (G_UNLIKELY (MASK_FILTER(modifiers) != 0))
            return FALSE;
        commit ((gunichar) m_mode_full_letter ? HalfFullConverter::toFull (keyval) : keyval);
        return TRUE;
    }

    guint i;
    if (G_UNLIKELY (keyval == IBUS_0))
        i = 10;
    else
        i = keyval - IBUS_1;

    if (modifiers == 0)
        selectCandidate (i);
    else if ((modifiers & ~ IBUS_LOCK_MASK) == IBUS_CONTROL_MASK)
        resetCandidate (i);
    return TRUE;
}

inline gboolean
PinyinEngine::processPunct (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (MASK_FILTER(modifiers) != 0))
        return FALSE;

    if (G_UNLIKELY (isEmpty ())) {
        if (m_mode_full_punct) {
            switch (keyval) {
            case '.':
                commit ("。"); break;
            case '\\':
                commit ("、"); break;
            case '^':
                commit ("……"); break;
            case '_':
                commit ("——"); break;
            case '$':
                commit ("￥"); break;
            case '<':
                commit ("《"); break;
            case '>':
                commit ("》"); break;
            case '"':
                commit (m_double_quote ? "“" : "”");
                m_double_quote = !m_double_quote;
                break;
            case '\'':
                commit (m_quote ? "‘" : "’");
                m_quote = !m_quote;
                break;
            default:
                commit (HalfFullConverter::toFull (keyval));
                break;
            }
        }
        else {
            commit (keyval);
        }
        return TRUE;
    }
    else {
        switch (keyval) {
        case IBUS_space:
            commit (); return TRUE;
        case IBUS_apostrophe:
            return processPinyin (keyval, keycode, modifiers);
        case IBUS_comma:
        case IBUS_minus:
            pageUp (); return TRUE;
        case IBUS_period:
        case IBUS_equal:
            pageDown (); return TRUE;
        }
    }
    return TRUE;
}

inline gboolean
PinyinEngine::processOthers (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (isEmpty ()))
        return FALSE;

    /* process some cursor control keys */
    gboolean _update = FALSE;
    switch (keyval) {
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
    }
    if (G_LIKELY (_update))
        update (FALSE);
    return TRUE;
}

gboolean
PinyinEngine::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{

    // ignore release event
    if (modifiers & IBUS_RELEASE_MASK)
        return TRUE;

    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK |
                  IBUS_LOCK_MASK);

    switch (keyval) {
    case IBUS_a ... IBUS_z:
    case IBUS_A ... IBUS_Z:
        return processPinyin (keyval, keycode, modifiers);
    case IBUS_0 ... IBUS_9:
        return processNumber (keyval, keycode, modifiers);
    case IBUS_space ... IBUS_slash:
    case IBUS_colon ... IBUS_at:
    case IBUS_bracketleft ... IBUS_quoteleft:
    case IBUS_braceleft ... IBUS_asciitilde:
        return processPunct (keyval, keycode, modifiers);
    default:
        return processOthers (keyval, keycode, modifiers);
    }

    return TRUE;
}

inline void
PinyinEngine::pageUp (void)
{
    if (ibus_lookup_table_page_up (m_lookup_table)) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

inline void
PinyinEngine::pageDown (void)
{
    if (ibus_lookup_table_page_down (m_lookup_table)) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

inline void
PinyinEngine::cursorUp (void)
{
    if (ibus_lookup_table_cursor_up (m_lookup_table)) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

inline void
PinyinEngine::cursorDown (void)
{
    if (ibus_lookup_table_cursor_down (m_lookup_table)) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

void
PinyinEngine::propertyActivate (const gchar *prop_name, guint prop_state)
{
    const static StaticString mode_chinese ("mode.chinese");
    const static StaticString mode_full_letter ("mode.full_letter");
    const static StaticString mode_full_punct ("mode.full_punct");

    if (mode_chinese == prop_name) {
    }
    else if (mode_full_letter == prop_name) {
    }
    else if (mode_full_punct == prop_name) {
    }
}

void
PinyinEngine::updatePreeditText (void)
{
    if (G_UNLIKELY (m_phrase_editor.isEmpty () && m_pinyin_editor.isEmpty ())) {
        ibus_engine_hide_preedit_text (m_engine);
        return;
    }

    m_buffer.truncate (0);
    if (G_UNLIKELY (m_phrase_editor.string1 ()))
        m_buffer << m_phrase_editor.string1 () << ' ';

    m_buffer << m_phrase_editor.string2 ()
             << m_pinyin_editor.textAfterPinyin ();

    Pointer<IBusText> preedit_text = ibus_text_new_from_static_string ((const gchar *) m_buffer);
    ibus_text_append_attribute (preedit_text, IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, -1);
    ibus_engine_update_preedit_text (m_engine, preedit_text, m_buffer.length (), TRUE);
}

void
PinyinEngine::updateAuxiliaryText (void)
{

    /* clear pinyin array */
    if (G_UNLIKELY (isEmpty ())) {
        ibus_engine_hide_auxiliary_text (m_engine);
        return;
    }

    guint cursor_pos;
    guint len;

    m_buffer.truncate (0);
    if (G_UNLIKELY (m_phrase_editor.string1 ())) {
        m_buffer << m_phrase_editor.string1 ();
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

inline void
PinyinEngine::commit (gchar ch)
{
    gchar str[2] = {ch, 0};
    Pointer<IBusText> text = ibus_text_new_from_static_string (str);
    ibus_engine_commit_text (m_engine, text);
}

inline void
PinyinEngine::commit (gunichar ch)
{
    Pointer<IBusText> text = ibus_text_new_from_unichar (ch);
    ibus_engine_commit_text (m_engine, text);
}

inline void
PinyinEngine::commit (const gchar *str)
{
    Pointer<IBusText> text = ibus_text_new_from_static_string (str);
    ibus_engine_commit_text (m_engine, text);
}

inline void
PinyinEngine::commit (void)
{
    if (G_UNLIKELY (m_pinyin_editor.isEmpty ()))
        return;

    m_buffer.truncate (0);
    m_buffer << m_phrase_editor.string1 () << m_phrase_editor.string2 ();
    const gchar *p = m_pinyin_editor.textAfterPinyin ();
    if (G_UNLIKELY (m_mode_full_letter)) {
        while (*p != 0)
            m_buffer.appendUnichar (HalfFullConverter::toFull (*p++));
    }
    else {
        m_buffer << p;
    }
    commit ((const gchar *)m_buffer);
    m_phrase_editor.commit ();
    reset ();
}

inline gboolean
PinyinEngine::selectCandidate (guint i)
{
    guint page_size = ibus_lookup_table_get_page_size (m_lookup_table);
    guint cursor_pos = ibus_lookup_table_get_cursor_pos (m_lookup_table);
    i += (cursor_pos / page_size) * page_size;

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

inline gboolean
PinyinEngine::resetCandidate (guint i)
{
    guint page_size = ibus_lookup_table_get_page_size (m_lookup_table);
    guint cursor_pos = ibus_lookup_table_get_cursor_pos (m_lookup_table);
    i += (cursor_pos / page_size) * page_size;

    if (m_phrase_editor.resetCandidate (i)) {
        updatePreeditText ();
        updateAuxiliaryText ();
        updateLookupTable ();
    }
    return TRUE;
}

};

