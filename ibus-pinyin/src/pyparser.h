/* vim:set et sts=4: */
#ifndef __PY_PARSER_H__
#define __PY_PARSER_H__

#include <glib.h>
#include "pinyin.h"

struct _PYParser;
typedef struct _PYParser PYParser;

PYParser    *py_parser_new          (guint          option);
void         py_parser_destroy      (PYParser       *parser);
gint         py_parser_parse        (PYParser       *parser,
                                     const gchar    *str,
                                     gint            len,
                                     GList          **list);
void         py_parse_free_result   (GList          *result);
void         py_parse_set_option    (PYParser       *parser,
                                     guint           option);
guint        py_parse_get_option    (PYParser       *parser);

#endif