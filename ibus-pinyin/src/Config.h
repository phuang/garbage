#ifndef __PY_CONFIG_H_
#define __PY_CONFIG_H_

#include <glib.h>
#include <ibus.h>
#include "Pointer.h"

namespace PY {

class Config : public Pointer<IBusConfig > {
public:
    Config (Pointer<IBusBus> & bus) {
        set (ibus_bus_get_config (bus));
    }
    static guint option (void) { return m_option; }
private:
    static guint m_option;
};

};
#endif
