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
    PinYinParser (guint option) : m_option (option) {};
    ~PinYinParser () {}

    guint parse (const String  &pinyin, gint len, PinYinArray &result);
    guint option (void) { return m_option; }
    void setOption (guint option) { m_option = option; }

private:
    guint m_option;
};

};
#endif
