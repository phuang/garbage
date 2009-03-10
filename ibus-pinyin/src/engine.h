/* vim:set et sts=4: */
#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <ibus.h>

#define IBUS_TYPE_PINYIN_ENGINE	\
	(ibus_pinyin_engine_get_type ())

GType   ibus_pinyin_engine_get_type    (void);

void    ibus_pinyin_init (IBusBus *bus);
void    ibus_pinyin_exit (void);

#endif
