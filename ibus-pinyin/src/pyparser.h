/* vim:set et sts=4: */
#ifndef __PY_PARSER_H__
#define __PY_PARSER_H__

#include <glib.h>
#include "pinyin.h"


gint         py_parse_pinyin        (const gchar    *str,
                                     gint            len,
                                     gint            option,
                                     GArray         *result);

#endif
