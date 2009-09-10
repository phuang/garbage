/* vim:set et sts=4: */
#ifndef __PY_PARSER_H__
#define __PY_PARSER_H__

#include <glib.h>
#include "pytypes.h"

namespace PY {

class PinYinParser {

public:
    PinYinParser (guint option) : m_option (option) {};
    ~PinYinParser () {}

private:
    guint m_option;
};

gint         py_parse_pinyin        (const gchar    *str,
                                     gint            len,
                                     gint            option,
                                     GArray         *result);

};
#endif
