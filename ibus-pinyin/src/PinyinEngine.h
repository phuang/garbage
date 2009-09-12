/* vim:set et sts=4: */
#ifndef __PY_PIN_YIN_ENGINE_H__
#define __PY_PIN_YIN_ENGINE_H__

#include <ibus.h>
#include "Pointer.h"
#include "Database.h"
#include "PinyinEditor.h"
#include "PhraseEditor.h"

namespace PY {

class PinyinEngine {
public:
    PinyinEngine (IBusEngine *engine);
    ~PinyinEngine (void);

    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    void focusIn (void) {}
    void focusOut (void) {}

    void reset (gboolean need_update = TRUE) {
        m_pinyin_editor.reset ();
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
            updatePhraseEditor ();
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
    void updatePhraseEditor (void);

    static gboolean delayUpdateHandler (PinyinEngine *pinyin) {
        if (pinyin->m_need_update > 0)
            pinyin->update (TRUE);
        return FALSE;
    }

private:
    Pointer<IBusEngine>  m_engine;  // engine pointer

    PinyinEditor m_pinyin_editor;   // pinyin editor
    PhraseEditor m_phrase_editor;   // phrase editor

    gint m_need_update;             // need update preedit, aux, or lookup table

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
