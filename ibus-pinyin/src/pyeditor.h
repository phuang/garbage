#ifndef __PY_EDITOR_H_
#define __PY_EDITOR_H_

#include <glib.h>
#include "pystring.h"
#include "pyparser.h"

namespace PY {

class Editor {

public:
    Editor (void);
    const String & text (void) { return m_text; }
    guint cursor (void) { return m_cursor; }
    gboolean isEmpty (void) { return m_text.isEmpty (); }
    const PinYinArray & pinyin (void) { return m_pinyin; }
    guint pinyinLength (void) { return m_pinyin_len; }

    gboolean insert (gint ch);

    static void setOption (guint option) { m_option = option; }
    static guint option (void) { return m_option; }

    gboolean removeCharBefore (void);
    gboolean removeCharAfter (void);
    gboolean removeWordBefore (void);
    gboolean removeWordAfter (void);

    gboolean moveCursorLeft (void);
    gboolean moveCursorRight (void);
    gboolean moveCursorLeftByWord (void);
    gboolean moveCursorRightByWord (void);
    gboolean moveCursorToBegin (void);
    gboolean moveCursorToEnd (void);

    gboolean reset (void) {
        gboolean retval = FALSE;
        if (m_cursor != 0) {
            m_cursor = 0;
            retval = TRUE;
        }

        if (m_text.length () != 0) {
            m_text.truncate (0);
            retval = TRUE;
        }
        
        if (retval)
            updatePinYin ();

        return retval;
    }

private:
    void updatePinYin (void);

private:
    String      m_text;         // text buffer
    guint       m_cursor;       // cursor pos in char
    gboolean    m_invalidate;
    PinYinArray m_pinyin;       // pinyin array
    guint       m_pinyin_len;   // pinyin length in char

private:
    static guint m_option;

private:
    static PinYinParser m_parser; 
};

};

#endif
