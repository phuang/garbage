/* vim:set et sts=4: */
#ifndef __PY_DB_H__
#define __PY_DB_H__

#include <sqlite3.h>
#include "pytypes.h"
#include "pyarray.h"
#include "pyparser.h"
#include "pystring.h"
#include "pyphrasearray.h"

namespace PY {

class Database {
public:
    Database ();
    ~Database ();
    gboolean query (const PinYinArray &pinyin,
                    guint              m,
                    guint              option,
                    PhraseArray       &result);

private:
    gboolean queryInternal (const PinYinArray &pinyin,
                            gint               pinyin_begin,
                            gint               pinyin_len,
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
