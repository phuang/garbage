/* vim:set et sts=4: */
#ifndef __PY_PARSER_H__
#define __PY_PARSER_H__

#include <glib.h>
#include "String.h"
#include "PinyinArray.h"

namespace PY {

class PinyinParser {

public:
    PinyinParser (void) {}
    ~PinyinParser (void) {}

    guint parse (const String  &pinyin, gint len, guint option, PinyinArray &result);
};

};
#endif
