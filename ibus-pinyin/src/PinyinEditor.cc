#include "PinyinEditor.h"

namespace PY {

guint PinyinEditor::m_option = 0x0;
PinyinParser PinyinEditor::m_parser;

PinyinEditor::PinyinEditor (void)
    : m_text (64),
      m_cursor (0),
      m_invalidate (0),
      m_pinyin (32),
      m_pinyin_len (0)
{
}


gboolean
PinyinEditor::insert (gint ch)
{
    m_text.insert (m_cursor++, ch);
    if (G_UNLIKELY ((m_option & PINYIN_SIMPLE_PINYIN) == 0))
        updatePinyin ();
    else if (G_LIKELY ((m_cursor - 1 == m_pinyin_len) ||
                  (m_cursor - 2 == m_pinyin_len && m_text[m_pinyin_len] == '\'')))
        updatePinyin ();
    return true;
}

gboolean
PinyinEditor::removeCharBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;
    
    m_cursor --;
    m_text.erase (m_cursor, 1);
    
    updatePinyin ();

    return TRUE;
}

gboolean
PinyinEditor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;
    
    m_text.erase (m_cursor, 1);
    
    return TRUE;
}

gboolean
PinyinEditor::removeWordBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;
    
    guint cursor;

    if (G_UNLIKELY (m_cursor > m_pinyin_len)) {
        cursor = m_pinyin_len;
    }
    else {
        const Pinyin * p = m_pinyin.pop ();
        cursor = m_cursor - p->len;
        m_pinyin_len -= p->len;
    }

    m_text.erase (cursor, m_cursor - cursor);
    m_cursor = cursor;
    return TRUE;
}

gboolean
PinyinEditor::removeWordAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, -1);
    return TRUE;
}

gboolean
PinyinEditor::moveCursorLeft (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;
    
    m_cursor --;
    updatePinyin ();

    return TRUE;
}

gboolean
PinyinEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;
    
    m_cursor ++;
    updatePinyin ();

    return TRUE;
}

gboolean
PinyinEditor::moveCursorLeftByWord (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    const Pinyin * p = m_pinyin.pop ();
    m_cursor -= p->len;
    m_pinyin_len -= p->len;

    return TRUE;
}

gboolean
PinyinEditor::moveCursorRightByWord (void)
{
    return moveCursorToEnd ();
}

gboolean
PinyinEditor::moveCursorToBegin (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor = 0;
    m_pinyin.removeAll ();
    m_pinyin_len = 0;
    
    return TRUE;
}

gboolean
PinyinEditor::moveCursorToEnd (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor = m_text.length ();
    updatePinyin  ();

    return TRUE;
}

void
PinyinEditor::updatePinyin (void)
{
    if (G_UNLIKELY (m_text.isEmpty ())) {
        m_pinyin.removeAll ();
        m_pinyin_len = 0;
    }
    else {
        m_pinyin_len = m_parser.parse (m_text,
                                       m_cursor,
                                       m_option,
                                       m_pinyin);
    }
}

};


