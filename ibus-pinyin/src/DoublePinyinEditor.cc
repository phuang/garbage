#include "Config.h"
#include "DoublePinyinEditor.h"

namespace PY {

#include "DoublePinyinTable.h"

DoublePinyinEditor::DoublePinyinEditor (void)
{
}

static inline gint
char_to_id (gint ch)
{
    switch (ch) {
    case 'a' ... 'z':
        return ch - 'a';
    case ';':
        return 26;
    default:
        return -1;
    }
}


gboolean
DoublePinyinEditor::insert (gint ch)
{
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return FALSE;

    gint i = char_to_id (ch);
    if (i < 0)
        return FALSE;

    m_text.insert (m_cursor++, ch);

    if (m_cursor != m_pinyin_len + 2)
        return TRUE;

    const Pinyin *pinyin;
    gint schema = Config::doublePinyinSchema ();
    gint prev_ch = m_text[m_cursor - 2];
    gint j = char_to_id (prev_ch);
    gint sheng = double_pinyin_map[schema].sheng[j];
    gint yun = double_pinyin_map[schema].yun[i][0];

    if (sheng == PINYIN_ID_VOID && yun == PINYIN_ID_VOID)
        return TRUE;
    pinyin = m_parser.isPinyin (sheng, yun, Config::option () & PINYIN_FUZZY_ALL);
    if (pinyin == NULL) {
        yun = double_pinyin_map[schema].yun[i][1];
        pinyin = m_parser.isPinyin (sheng, yun, Config::option () & PINYIN_FUZZY_ALL);
    }

    if (pinyin == NULL)
        return TRUE;
    m_pinyin << pinyin;
    m_pinyin_len += 2;
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
gboolean
DoublePinyinEditor::reset (void)
{
        gboolean retval = FALSE;
        if (m_cursor != 0) {
            m_cursor = 0;
            retval = TRUE;
        }

        if (m_text.length () != 0) {
            m_text.truncate (0);
            retval = TRUE;
        }

        if (retval)
            updatePinyin ();

        return retval;
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


