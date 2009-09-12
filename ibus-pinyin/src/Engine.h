/* vim:set et sts=4: */
#ifndef __PY_ENGINE_H__
#define __PY_ENGINE_H__

#include <ibus.h>
#include "Database.h"
#include "Editor.h"
#include "Pointer.h"

namespace PY {

#define IBUS_TYPE_PINYIN_ENGINE	\
	(PY::ibus_pinyin_engine_get_type ())

GType   ibus_pinyin_engine_get_type    (void);

class PinYinEngine {
public:
    PinYinEngine (IBusEngine *engine);
    ~PinYinEngine (void);

    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    void focusIn (void) {}
    void focusOut (void) {}

    void reset (gboolean need_update = TRUE) {
        m_editor.reset ();
        update (need_update);
    }

    void enable (void) {}
    void disable (void) {}
    void pageUp (void) {}
    void pageDown (void) {}
    void cursorUp (void) {}
    void cursorDown (void) {}

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
    void commit (void);
    gboolean selectPhrase (guint i);
    void updatePreeditText (void);
    void updateAuxiliaryText (void);
    void updateLookupTable (void);
    void updatePhrases (void);

    static gboolean delayUpdateHandler (PinYinEngine *pinyin) {
        if (pinyin->m_need_update > 0)
            pinyin->update (TRUE);
        return FALSE;
    }

private:
    Pointer<IBusEngine>  m_engine;  // engine pointer

    Editor m_editor;                // pinyin editor

    gint m_need_update;             // need update preedit, aux, or lookup table

    PhraseArray m_candidates;       // candidates array
    PhraseArray m_phrases;          // phrases array (preedit text)
    guint       m_phrases_len;      // sum of length of all phrases

    Pointer<IBusLookupTable> m_lookup_table;
    Pointer<IBusProperty>    m_mode_prop;
    Pointer<IBusPropList>    m_props;

private:
    // static members
    static Database m_db;           // phrases database
    static guint m_option;          // option
};


};

#endif
