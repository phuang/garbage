#ifndef __ARRAY_H_
#define __ARRAY_H_

template<typename T>
class Array {

public:
    Array (guint init_size = 0) {
        m_array = g_array_sized_new (FALSE, FALSE, sizeof (T), init_size);
    }

    ~Array () {
        g_array_free (m_array, TRUE);
    }

    T & get (guint i) {
        return g_array_index (m_array, T, i);
    }

    guint size (void) {
        return m_array->len;
    }

    void setSize (guint size) {
        g_array_set_size (m_array, size);
    }

    void removeAll () {
        setSize (0);
    }

    Array<T> & operator << (const T & i) {
        g_array_append_val (m_array, i);
        return *this;
    }

private:
    GArray *m_array;
};

#endif
