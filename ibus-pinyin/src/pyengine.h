/* vim:set et sts=4: */
#ifndef __PY_ENGINE_H__
#define __PY_ENGINE_H__

#include <ibus.h>
#include "pydatabase.h"
#include "pyeditor.h"

namespace PY {

#define IBUS_TYPE_PINYIN_ENGINE	\
	(PY::ibus_pinyin_engine_get_type ())

GType   ibus_pinyin_engine_get_type    (void);

class PinYinEngine {
public:
    PinYinEngine (IBusEngine *engine);
    ~PinYinEngine (void);

    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    void focusIn () {}
    void focusOut () {}

    void reset (gboolean need_update = TRUE) {
        m_editor.reset ();
        update (need_update);
    }

    void enable () {}
    void disable () {}
    void pageUp () {}
    void pageDown () {}
    void cursorUp () {}
    void cursorDown () {}

    void updatePreeditText ();
    void updateAuxiliaryText ();
    void updateLookupTable ();

    void update (gboolean now = TRUE) {
        if (now || m_need_update >= 4) {
            updateLookupTable ();
            updateAuxiliaryText ();
            updatePreeditText ();
            m_need_update = 0;
        } else {
            if (m_need_update == 0) {
                g_idle_add ((GSourceFunc) delayUpdateHandler, this);
            }
            m_need_update ++;
        }
    }

private:
    static gboolean delayUpdateHandler (PinYinEngine *pinyin) {
        if (pinyin->m_need_update > 0)
            pinyin->update (TRUE);
        return FALSE;
    }

private:
    IBusEngine *m_engine;
    Editor m_editor;

    gint m_need_update;

    PhraseArray m_phrases;

    IBusLookupTable *m_lookup_table;
    IBusProperty    *m_mode_prop;
    IBusPropList    *m_props;

private:
    // static members
    static Database m_db;
    static guint m_option;
};


};

#endif
