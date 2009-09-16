#ifndef __PY_UTIL_H_
#define __PY_UTIL_H_

#include <uuid/uuid.h>
#include <sys/utsname.h>

namespace PY {

class UUID {
public:
    UUID (void) {
        uuid_t u;
        uuid_generate (u);
        uuid_unparse (u, m_uuid);
    }

    operator const gchar * (void) const {
        return m_uuid;        
    }

private:
    gchar m_uuid[40];
};

class Uname {
public:
    Uname (void) {
        uname (&m_buf);
    }

    const gchar *hostname (void) const { return m_buf.nodename; }
private:
    struct utsname m_buf;
};

class Hostname : public Uname {
public:
    operator const gchar * (void) const {
        return hostname ();
    }
};

};
#endif
