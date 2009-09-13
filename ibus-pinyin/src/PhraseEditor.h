#ifndef __PY_PHRASE_EDITOR_H_
#define __PY_PHRASE_EDITOR_H_

#include "Database.h"
#include "PhraseArray.h"

namespace PY {

class PhraseEditor {
public:
    PhraseEditor(void);
    ~PhraseEditor(void);

    const PhraseArray & candidates (void) const { return m_candidates; }
    const PhraseArray & phrases1 (void) const { return m_phrases1; }
    const PhraseArray & phrases2 (void) const { return m_phrases2; }
    const PinyinArray & pinyin (void) const { return m_pinyin; }
    guint cursor (void) const { return m_cursor; }

    const Phrase & candidate (guint i) const {
        return m_candidates[i];
    }

    const Phrase & phrase1 (guint i) const {
        return m_phrases1[i];
    }

    const Phrase & phrase2 (guint i) const {
        return m_phrases2[i];
    }

    void reset (void) {
        m_candidates.removeAll ();
        m_phrases1.removeAll ();
        m_phrases2.removeAll ();
        m_cursor = 0;
    }

    void update (const PinyinArray &pinyin);
    gboolean selectCandidate (guint i);

private:
    void updateCandidates (void);
    void updatePhrases (void);

private:
    PhraseArray m_candidates;   // candidates phrase array
    PhraseArray m_phrases1;     // phrases before cursor
    PhraseArray m_phrases2;     // phrases after cursor
    PinyinArray m_pinyin;
    guint m_cursor;

private:
    static Database m_database;
    static guint m_option;
};

};

#endif
