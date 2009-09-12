#include "PhraseEditor.h"

namespace PY {

/* init static members */
Database PhraseEditor::m_database;
guint PhraseEditor::m_option = 0;

PhraseEditor::PhraseEditor (void)
    : m_candidates (32),
      m_phrases (8),
      m_pinyin (16),
      m_cursor (0)
{
}

PhraseEditor::~PhraseEditor (void)
{
}

void
PhraseEditor::update (const PinyinArray &pinyin, gint cursor)
{
    g_assert (cursor <= (gint)pinyin.length ());

    if (cursor < 0)
        cursor = pinyin.length ();

    m_pinyin = pinyin;
    m_cursor = cursor;

    updateCandidates ();
    updatePhrases ();
}

void
PhraseEditor::updateCandidates (void)
{
    gboolean retval;
    m_candidates.removeAll ();

    for (guint i = m_cursor; i > 0; i--) {
        retval = m_database.query (m_pinyin,
                                   0,
                                   i,
                                   -1,
                                   m_option,
                                   m_candidates);
    }
}

void
PhraseEditor::updatePhrases (void)
{
    guint begin;
    guint end;
    gboolean retval;

    m_phrases.removeAll ();

    if (G_UNLIKELY (m_pinyin.length () == 0))
        return;

    if (G_LIKELY (m_cursor > 0)) {
        m_phrases << m_candidates[0];

        begin = m_phrases[0].len;
        end = m_cursor;

        while (begin != end) {
            for (guint i = end; i > begin; i--) {
                retval = m_database.query (m_pinyin,
                                           begin,
                                           i - begin,
                                           1,
                                           m_option,
                                           m_phrases);
                if (retval > 0) {
                    begin += m_phrases[m_phrases.length () - 1].len;
                    break;
                }
            }
            g_assert (retval > 0);
        }
    }

    begin = m_cursor;
    end = m_pinyin.length ();

    while (begin != end) {
        for (guint i = end; i > begin; i--) {
            retval = m_database.query (m_pinyin,
                                       begin,
                                       i - begin,
                                       1,
                                       m_option,
                                       m_phrases);
            if (retval > 0) {
                begin += m_phrases[m_phrases.length () - 1].len;
                break;
            }
        }
        g_assert (retval > 0);
    }
}

};


