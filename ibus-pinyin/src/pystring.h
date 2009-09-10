#ifndef __PY_STRING_H_
#define __PY_STRING_H_
#include <glib.h>

namespace PY {

class String {
public:
    String (const gchar *init) {
        m_string = g_string_new (init);
    }

    String (const gchar *init, gssize len) {
        m_string = g_string_new_len (init, len);
    }

    String (gsize init_size = 0) {
        m_string = g_string_sized_new (init_size);
    }

    ~String (void) {
        g_string_free (m_string, TRUE);
    }

    gsize length (void) {
        return m_string->len; 
    }

    String & operator = (const gchar *str) {
        g_string_assign (m_string, str);
        return *this;
    }

    String & operator += (const gchar *str) {
        g_string_append (m_string, str);
        return *this;
    }

    gchar operator[] (guint i) {
        if (i >= length ())
            return 0;
        return m_string->str[i];
    }

    operator const gchar *() {
        return m_string->str;
    }

private:
    GString *m_string;
};
};
#endif
