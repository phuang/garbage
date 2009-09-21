#include "Config.h"
#include "DoublePinyinEditor.h"

namespace PY {


DoublePinyinEditor::DoublePinyinEditor (void)
{
}


gboolean
DoublePinyinEditor::insert (gint ch)
{
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return FALSE;

    m_text.insert (m_cursor++, ch);

    if (G_UNLIKELY ((Config::option () & PINYIN_SIMPLE_PINYIN) == 0)) {
        updatePinyin ();
    }
    else {
        if (G_LIKELY ((m_cursor - 1 == m_pinyin_len) ||
                      (m_cursor - 2 == m_pinyin_len &&
                       m_text[m_pinyin_len] == '\''))) {
            updatePinyin ();
        }
    }
    return TRUE;
}

gboolean
DoublePinyinEditor::removeCharBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    m_text.erase (m_cursor, 1);

    updatePinyin ();

    return TRUE;
}

gboolean
DoublePinyinEditor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, 1);

    return TRUE;
}

gboolean
DoublePinyinEditor::removeWordBefore (void)
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
DoublePinyinEditor::removeWordAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, -1);
    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorLeft (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    updatePinyin ();

    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor ++;
    updatePinyin ();

    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorLeftByWord (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    if (G_UNLIKELY (m_cursor > m_pinyin_len)) {
        m_cursor = m_pinyin_len;
        return TRUE;
    }

    const Pinyin * p = m_pinyin.pop ();
    m_cursor -= p->len;
    m_pinyin_len -= p->len;

    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorRightByWord (void)
{
    return moveCursorToEnd ();
}

gboolean
DoublePinyinEditor::moveCursorToBegin (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor = 0;
    m_pinyin.removeAll ();
    m_pinyin_len = 0;

    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorToEnd (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor = m_text.length ();
    updatePinyin  ();

    return TRUE;
}

void
DoublePinyinEditor::updatePinyin (void)
{
    if (G_UNLIKELY (m_text.isEmpty ())) {
        m_pinyin.removeAll ();
        m_pinyin_len = 0;
    }
    else {
        m_pinyin_len = m_parser.parse (m_text,
                                       m_cursor,
                                       Config::option (),
                                       m_pinyin,
                                       MAX_PHRASE_LEN);
    }
}

};


