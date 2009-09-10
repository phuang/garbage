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

    gsize length (void) const {
        return m_string->len; 
    }

    gboolean isEmpty (void) const {
        return m_string->len == 0;
    }

    String & insert (gint pos, gint ch) {
        g_string_insert_c (m_string, pos, ch);
    }

    void truncate (gint len) {
        g_string_truncate (m_string, len);
    }

    void erase (gint pos, gint len) {
        g_string_erase (m_string, pos, len);
    }

    String & operator = (const gchar *str) {
        g_string_assign (m_string, str);
        return *this;
    }

    String & operator += (const gchar *str) {
        g_string_append (m_string, str);
        return *this;
    }

    String & operator += (gint ch) {
        g_string_append_c (m_string, ch);
        return *this;
    }

    gchar operator[] (guint i) {
        if (i >= length ())
            return 0;
        return m_string->str[i];
    }

    operator const gchar *() const {
        return m_string->str;
    }

    operator gboolean () const {
        return m_string->len != 0;
    }

private:
    GString *m_string;
};
};
#endif
