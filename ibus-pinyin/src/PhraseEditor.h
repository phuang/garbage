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
    const PhraseArray & phrases (void) const { return m_phrases; }
    const PinyinArray & pinyin (void) const { return m_pinyin; }
    guint cursor (void) const { return m_cursor; }

    const Phrase & candidate (guint i) const {
        return m_candidates[i];
    }
    const Phrase & phrase (guint i) const {
        return m_phrases[i];
    }

    void reset (void) {
        m_candidates.setSize (0);
        m_phrases.setSize (0);
        m_cursor = 0;
    }

    void setPinyin (const PinyinArray &pinyin, gboolean only);

private:
    PhraseArray m_candidates;
    PhraseArray m_phrases;
    PinyinArray m_pinyin;
    guint m_cursor;

private:
    static Database m_database;
    static guint m_option;
};

};

#endif
