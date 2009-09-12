/* vim:set et sts=4: */
#ifndef __PY_DATABASE_H__
#define __PY_DATABASE_H__

#include <sqlite3.h>
#include "Types.h"
#include "Array.h"
#include "String.h"
#include "PinyinArray.h"
#include "PhraseArray.h"

namespace PY {

class Database {
public:
    Database ();
    ~Database ();
    gint query (const PinyinArray &pinyin,
                guint              m,
                guint              option,
                PhraseArray       &result);

    gint query (const PinyinArray &pinyin,
                guint              pinyin_begin,
                guint              pinyin_len,
                gint               m,
                guint              option,
                PhraseArray       &result);

    String *string (guint i) {
        guint j;
        for (j = m_strings.length (); j <= i; j++) {
            m_strings.append (new String (256));
        }
        return &(m_strings[i]->truncate (0));
    }

    void conditionsDouble (void);
    void conditionsTriple (void);

private:
    sqlite3 *m_db;
    String   m_sql;
    Array<String *> m_conditions;
    Array<String *> m_strings;
};

};

#endif
