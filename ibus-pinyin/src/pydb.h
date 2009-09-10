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
    gboolean query (const PinYinArray &pinyin, guint m, guint option, PhraseArray &result);

private:
    sqlite3 *m_db;
    String   m_sql;
    Array<String *> m_conditions;
    Array<String *> m_strings;
};

};

#endif
