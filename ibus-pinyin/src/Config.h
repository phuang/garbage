#ifndef __PY_CONFIG_H_
#define __PY_CONFIG_H_

#include <glib.h>

namespace PY {

class Config {
public:
    static guint option (void) { return m_option; }
private:
    static guint m_option;
};

};
#endif
