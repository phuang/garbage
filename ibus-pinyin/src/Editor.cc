#include "Editor.h"

namespace PY {

guint Editor::m_option = 0x0;
PinYinParser Editor::m_parser;

Editor::Editor (void)
    : m_text (64),
      m_cursor (0),
      m_invalidate (0),
      m_pinyin (32),
      m_pinyin_len (0)
{
}


gboolean
Editor::insert (gint ch)
{
    m_text.insert (m_cursor++, ch);
    if (G_UNLIKELY ((m_option & PINYIN_SIMPLE_PINYIN) == 0))
        updatePinYin ();
    else if (G_LIKELY ((m_cursor - 1 == m_pinyin_len) ||
                  (m_cursor - 2 == m_pinyin_len && m_text[m_pinyin_len] == '\'')))
        updatePinYin ();
    return true;
}

gboolean
Editor::removeCharBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;
    
    m_cursor --;
    m_text.erase (m_cursor, 1);
    
    updatePinYin ();

    return TRUE;
}

gboolean
Editor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;
    
    m_text.erase (m_cursor, 1);
    
    return TRUE;
}

gboolean
Editor::removeWordBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;
    
    guint cursor;

    if (G_UNLIKELY (m_cursor > m_pinyin_len)) {
        cursor = m_pinyin_len;
    }
    else {
        const PinYin * p = m_pinyin.pop ();
        cursor = m_cursor - p->len;
        m_pinyin_len -= p->len;
    }

    m_text.erase (cursor, m_cursor - cursor);
    m_cursor = cursor;
    return TRUE;
}

gboolean
Editor::removeWordAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, -1);
    return TRUE;
}

gboolean
Editor::moveCursorLeft (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;
    
    m_cursor --;
    updatePinYin ();

    return TRUE;
}

gboolean
Editor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;
    
    m_cursor ++;
    updatePinYin ();

    return TRUE;
}

gboolean
Editor::moveCursorLeftByWord (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    const PinYin * p = m_pinyin.pop ();
    m_cursor -= p->len;
    m_pinyin_len -= p->len;

    return TRUE;
}

gboolean
Editor::moveCursorRightByWord (void)
{
    return moveCursorToEnd ();
}

gboolean
Editor::moveCursorToBegin (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor = 0;
    m_pinyin.removeAll ();
    m_pinyin_len = 0;
    
    return TRUE;
}

gboolean
Editor::moveCursorToEnd (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor = m_text.length ();
    updatePinYin  ();

    return TRUE;
}

void
Editor::updatePinYin (void)
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


