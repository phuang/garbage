/* vim:set et sts=4: */
#ifndef __PY_PARSER_H__
#define __PY_PARSER_H__

#include <glib.h>
#include "pystring.h"
#include "pyarray.h"
#include "pytypes.h"

namespace PY {

typedef Array<const PinYin *> PinYinArray;

class PinYinParser {

public:
    PinYinParser (void) {};
    ~PinYinParser (void) {}

    guint parse (const String  &pinyin, gint len, guint option, PinYinArray &result);
};

};
#endif
