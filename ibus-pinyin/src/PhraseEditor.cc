#include "PhraseEditor.h"

namespace PY {

/* init static members */
Database PhraseEditor::m_database;
guint PhraseEditor::m_option = 0;

PhraseEditor::PhraseEditor (void)
    : m_candidates (32),
      m_phrases1 (8),
      m_phrases2 (8),
      m_pinyin (16),
      m_cursor (0)
{
}

PhraseEditor::~PhraseEditor (void)
{
}

void
PhraseEditor::update (const PinyinArray &pinyin)
{
    m_pinyin = pinyin;
    m_phrases1.removeAll ();
    m_cursor = 0;

    updateCandidates ();
    updatePhrases ();
}

gboolean
PhraseEditor::selectCandidate (guint i)
{
    if (G_UNLIKELY (i >= m_candidates.length ()))
        return FALSE;

    m_phrases1 << m_candidates[i];
    m_cursor += m_candidates[i].len;
    updateCandidates ();
    updatePhrases ();
    return TRUE;
}

void
PhraseEditor::updateCandidates (void)
{
    gboolean retval;
    m_candidates.removeAll ();

    guint len = MIN (MAX_PHRASE_LEN, m_pinyin.length () - m_cursor);
    for (; len > 0; len--) {
        retval = m_database.query (m_pinyin,
                                   m_cursor,
                                   len,
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

    m_phrases2.removeAll ();

    if (G_UNLIKELY (m_pinyin.length () == 0))
        return;

    if (G_LIKELY (m_cursor < m_pinyin.length ())) {
        m_phrases2 << m_candidates[0];

        begin = m_phrases2[0].len + m_cursor;
        end = m_pinyin.length ();

        while (begin != end) {
            for (guint i = MIN (end, begin + MAX_PHRASE_LEN); i > begin; i--) {
                retval = m_database.query (m_pinyin,
                                           begin,
                                           i - begin,
                                           1,
                                           m_option,
                                           m_phrases2);
                if (G_LIKELY (retval > 0)) {
                    begin += m_phrases2[m_phrases2.length () - 1].len;
                    break;
                }
            }
            g_assert (retval > 0);
        }
    }
}

};


