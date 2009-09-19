#ifndef __PY_CONFIG_H_
#define __PY_CONFIG_H_

#include <glib.h>
#include <glib-object.h>
#include <ibus.h>
#include "Pointer.h"

namespace PY {

class Config {
public:
    Config (Pointer<IBusBus> & bus) {
        m_config = ibus_bus_get_config (bus);
        g_signal_connect ((IBusConfig *) m_config, "value-changed", G_CALLBACK (value_changed_cb), this);
    }

    static guint option (void) { return m_option; }

private:
    static void value_changed_cb (IBusConfig    *config,
                                  const gchar   *section,
                                  const gchar   *name,
                                  const GValue  *value,
                                  Config        *self);

private:
    Pointer<IBusConfig> m_config;

private:
    static guint m_option;
};

};
#endif
