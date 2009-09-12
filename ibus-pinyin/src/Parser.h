/* vim:set et sts=4: */
#ifndef __PY_PARSER_H__
#define __PY_PARSER_H__

#include <glib.h>
#include "String.h"
#include "Array.h"
#include "Types.h"

namespace PY {

typedef Array<const PinYin *> PinYinArray;

class PinYinParser {

public:
    PinYinParser (void) {}
    ~PinYinParser (void) {}

    guint parse (const String  &pinyin, gint len, guint option, PinYinArray &result);
};

};
#endif
