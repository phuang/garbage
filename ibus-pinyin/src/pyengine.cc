/* vim:set et sts=4: */

#include <ibus.h>
#include <string.h>
#include "pyengine.h"
#include "pydatabase.h"
#include "pyeditor.h"

namespace PY {

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
    static PinYinParser m_parser;
    static guint m_option;
};

Database PinYinEngine::m_db;
guint PinYinEngine::m_option = 0xffffffff;
PinYinParser PinYinEngine::m_parser (PinYinEngine::m_option);

PinYinEngine::PinYinEngine (IBusEngine *engine)
    : m_engine (engine),
      m_need_update (0),
      m_phrases (32),
      m_lookup_table (NULL),
      m_mode_prop (NULL),
      m_props (NULL)

{
    g_object_ref (m_engine);
    m_lookup_table = ibus_lookup_table_new (10, 0, TRUE, FALSE);
}

PinYinEngine::~PinYinEngine (void)
{
    g_object_unref (m_engine);
    g_object_unref (m_lookup_table);
    // g_object_unref (m_mode_prop);
    // g_object_unref (m_props);
}

gboolean
PinYinEngine::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{

    // ignore release event
    if (modifiers & IBUS_RELEASE_MASK) {
        return TRUE;
    }

    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK );

    /* process letter at first */
    if (G_LIKELY (keyval >= IBUS_a && keyval <= IBUS_z)) {
        if (G_LIKELY (modifiers == 0)) {
            if (m_editor.insert (keyval)) {
                update (FALSE);
                return TRUE;
            }
            return FALSE;
        }
        return !m_editor.isEmpty ();
    }

    /* process ' */
    if (keyval == IBUS_apostrophe) {
        if (G_UNLIKELY (m_editor.isEmpty ()))
            return FALSE;
        if (G_LIKELY (modifiers == 0))
            m_editor.insert (IBUS_apostrophe);
        return TRUE;
    }

    if (G_UNLIKELY (m_editor.isEmpty ()))
        return FALSE;

    /* process some cursor control keys */
    gboolean _update = FALSE;
    switch (keyval) {
    case IBUS_BackSpace:
        if (G_LIKELY (modifiers == 0))
            _update = m_editor.removeCharBefore ();
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK))
            _update = m_editor.removeWordBefore ();
        break;

    case IBUS_Delete:
        if (G_LIKELY (modifiers == 0))
            _update = m_editor.removeCharAfter ();
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK))
            _update = m_editor.removeWordAfter ();
        break;

    case IBUS_Left:
        if (G_LIKELY (modifiers == 0)) {
            // move left single char
            _update = m_editor.moveCursorLeft ();
        }
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK)) {
            // move left one pinyin
            _update = m_editor.moveCursorLeftByWord ();
        }
        break;

    case IBUS_Right:
        if (G_LIKELY (modifiers == 0)) {
            // move right single char
            _update = m_editor.moveCursorRight ();
        }
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK)) {
            // move right to end
            _update = m_editor.moveCursorToEnd ();
        }
        break;

    case IBUS_Home:
        if (G_LIKELY (modifiers == 0)) {
            // move to begin
            _update = m_editor.moveCursorToBegin ();
        }
        break;

    case IBUS_End:
        if (G_LIKELY (modifiers == 0)) {
            // move to end
            _update = m_editor.moveCursorToEnd ();
        }
        break;

    case IBUS_Up:
        return TRUE;
    case IBUS_Down:
        return TRUE;
    case IBUS_Page_Up:
        return TRUE;
    case IBUS_Page_Down:
        return TRUE;
    case IBUS_Escape:
        reset ();
        return TRUE;
    default:
        return TRUE;
    }
    if (G_LIKELY (_update))
        update (FALSE);
    return TRUE;
}

void
PinYinEngine::updatePreeditText (void)
{
    /* TODO */
}

void
PinYinEngine::updateAuxiliaryText (void)
{

    /* clear pinyin array */

    if (m_editor.isEmpty ()) {
        IBusText *preedit_text;
        preedit_text = ibus_text_new_from_static_string ("");
        ibus_engine_update_auxiliary_text (m_engine, preedit_text, FALSE);
        g_object_unref (preedit_text);
        return;
    }

    String text(128);
    guint cursor_pos;
    guint len;

    for (guint i = 0; i < m_editor.pinyin().length (); ++i) {
        if (G_LIKELY (i != 0))
            text << '\'';
        const PinYin *p = m_editor.pinyin()[i];
        text << p->sheng;
        text << p->yun;
    }

    len = text.length ();
    if (m_editor.pinyinLength () == m_editor.cursor ()) {
        cursor_pos =  text.length ();
        text << '|' << ((const gchar *)m_editor.text ()) + m_editor.pinyinLength ();
    }
    else {
        text.append (((const gchar *)m_editor.text ()) + m_editor.pinyinLength (), m_editor.cursor () - m_editor.pinyinLength ());
        cursor_pos =  text.length ();
        text << '|' << ((const gchar *)m_editor.text ()) + m_editor.cursor ();
    }

    IBusText *preedit_text;
    preedit_text = ibus_text_new_from_static_string (text);
    ibus_text_append_attribute (preedit_text, IBUS_ATTR_TYPE_FOREGROUND, 0x00afafaf, len, cursor_pos);
    ibus_text_append_attribute (preedit_text, IBUS_ATTR_TYPE_FOREGROUND, 0x00afafaf, cursor_pos + 1, -1);
    ibus_engine_update_auxiliary_text (m_engine,
                                        preedit_text,
                                        TRUE);
    g_object_unref (preedit_text);
}

void
PinYinEngine::updateLookupTable ()
{
    gboolean retval;

    ibus_lookup_table_clear (m_lookup_table);

    if (G_UNLIKELY (m_editor.pinyinLength () == 0)) {
        /*
        ibus_engine_update_lookup_table_fast (m_engine,
                                              m_lookup_table,
                                              FALSE);
        */
        ibus_engine_hide_lookup_table (m_engine);
        return;
    }

    m_phrases.removeAll ();
    retval = m_db.query (m_editor.pinyin (),
                         30,
                         m_option,
                         m_phrases);

    if (G_UNLIKELY (retval == FALSE || m_phrases.length () == 0)) {
        /*
        ibus_engine_update_lookup_table_fast (m_engine,
                                              m_lookup_table,
                                              FALSE);
        */
        ibus_engine_hide_lookup_table (m_engine);
        return;
    }

    for (guint i = 0; i < m_phrases.length (); i++) {
        IBusText *text;
        text = ibus_text_new_from_static_string (m_phrases[i].phrase);
        ibus_lookup_table_append_candidate (m_lookup_table, text);
    }

    ibus_engine_update_lookup_table_fast (m_engine,
                                          m_lookup_table,
                                          TRUE);
}

#if 0
static gboolean
ibus_pinyin_engine_delay_update_cb (IBusPinYinEngine *pinyin)
{
    if (pinyin->need_update > 0) {
        ibus_pinyin_engine_update (pinyin, TRUE);
    }
    return FALSE;
}
#endif


#define IBUS_PINYIN_ENGINE(obj)             \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), IBUS_TYPE_PINYIN_ENGINE, IBusPinYinEngine))
#define IBUS_PINYIN_ENGINE_CLASS(klass)     \
    (G_TYPE_CHECK_CLASS_CAST ((klass), IBUS_TYPE_PINYIN_ENGINE, IBusPinYinEngineClass))
#define IBUS_IS_PINYIN_ENGINE(obj)          \
    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IBUS_TYPE_PINYIN_ENGINE))
#define IBUS_IS_PINYIN_ENGINE_CLASS(klass)  \
    (G_TYPE_CHECK_CLASS_TYPE ((klass), IBUS_TYPE_PINYIN_ENGINE))
#define IBUS_PINYIN_ENGINE_GET_CLASS(obj)   \
    (G_TYPE_INSTANCE_GET_CLASS ((obj), IBUS_TYPE_PINYIN_ENGINE, IBusPinYinEngineClass))


typedef struct _IBusPinYinEngine IBusPinYinEngine;
typedef struct _IBusPinYinEngineClass IBusPinYinEngineClass;

struct _IBusPinYinEngine {
    IBusEngine parent;

    /* members */
    PinYinEngine *engine;
};

struct _IBusPinYinEngineClass {
    IBusEngineClass parent;
};

/* functions prototype */
static void     ibus_pinyin_engine_class_init   (IBusPinYinEngineClass  *klass);
static void     ibus_pinyin_engine_init         (IBusPinYinEngine       *pinyin);
static GObject* ibus_pinyin_engine_constructor  (GType                   type,
                                                 guint                   n_construct_params,
                                                 GObjectConstructParam  *construct_params);
static void     ibus_pinyin_engine_destroy      (IBusPinYinEngine       *pinyin);
static gboolean ibus_pinyin_engine_process_key_event
                                                (IBusEngine             *engine,
                                                 guint                   keyval,
                                                 guint                   keycode,
                                                 guint                   modifiers);
static void     ibus_pinyin_engine_focus_in     (IBusEngine             *engine);
static void     ibus_pinyin_engine_focus_out    (IBusEngine             *engine);
static void     ibus_pinyin_engine_reset        (IBusEngine             *engine);
static void     ibus_pinyin_engine_enable       (IBusEngine             *engine);
static void     ibus_pinyin_engine_disable      (IBusEngine             *engine);

#if 0
static void ibus_engine_set_cursor_location (IBusEngine             *engine,
                                             gint                    x,
                                             gint                    y,
                                             gint                    w,
                                             gint                    h);
static void ibus_pinyin_engine_set_capabilities
                                            (IBusEngine             *engine,
                                             guint                   caps);
#endif

static void     ibus_pinyin_engine_page_up      (IBusEngine             *engine);
static void     ibus_pinyin_engine_page_down    (IBusEngine             *engine);
static void     ibus_pinyin_engine_cursor_up    (IBusEngine             *engine);
static void     ibus_pinyin_engine_cursor_down  (IBusEngine             *engine);
#if 0
static void ibus_pinyin_property_activate   (IBusEngine             *engine,
                                             const gchar            *prop_name,
                                             gint                    prop_state);
static void ibus_pinyin_engine_property_show
                                            (IBusEngine             *engine,
                                             const gchar            *prop_name);
static void ibus_pinyin_engine_property_hide
                                            (IBusEngine             *engine,
                                             const gchar            *prop_name);
#endif

#if 0
static void ibus_config_value_changed       (IBusConfig             *config,
                                             const gchar            *section,
                                             const gchar            *name,
                                             GValue                 *value,
                                             gpointer                user_data);
#endif

static IBusEngineClass *parent_class = NULL;

GType
ibus_pinyin_engine_get_type (void)
{
    static GType type = 0;

    static const GTypeInfo type_info = {
        sizeof (IBusPinYinEngineClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) ibus_pinyin_engine_class_init,
        NULL,
        NULL,
        sizeof (IBusPinYinEngine),
        0,
        (GInstanceInitFunc) ibus_pinyin_engine_init,
    };

    if (type == 0) {
        type = g_type_register_static (IBUS_TYPE_ENGINE,
                                       "IBusPinYinEngine",
                                       &type_info,
                                       (GTypeFlags) 0);
    }

    return type;
}

static void
ibus_pinyin_engine_class_init (IBusPinYinEngineClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);
    IBusObjectClass *ibus_object_class = IBUS_OBJECT_CLASS (klass);
    IBusEngineClass *engine_class = IBUS_ENGINE_CLASS (klass);

    parent_class = (IBusEngineClass *) g_type_class_peek_parent (klass);

    object_class->constructor = ibus_pinyin_engine_constructor;
    ibus_object_class->destroy = (IBusObjectDestroyFunc) ibus_pinyin_engine_destroy;

    engine_class->process_key_event = ibus_pinyin_engine_process_key_event;

    engine_class->reset = ibus_pinyin_engine_reset;
    engine_class->enable = ibus_pinyin_engine_enable;
    engine_class->disable = ibus_pinyin_engine_disable;

    engine_class->focus_in = ibus_pinyin_engine_focus_in;
    engine_class->focus_out = ibus_pinyin_engine_focus_out;

    engine_class->page_up = ibus_pinyin_engine_page_up;
    engine_class->page_down = ibus_pinyin_engine_page_down;

    engine_class->cursor_up = ibus_pinyin_engine_cursor_up;
    engine_class->cursor_down = ibus_pinyin_engine_cursor_down;

}

static void
ibus_pinyin_engine_init (IBusPinYinEngine *pinyin)
{

    pinyin->engine = new PinYinEngine (IBUS_ENGINE (pinyin));
}

static GObject*
ibus_pinyin_engine_constructor (GType                   type,
                                guint                   n_construct_params,
                                GObjectConstructParam  *construct_params)
{
    IBusPinYinEngine *pinyin;

    pinyin = (IBusPinYinEngine *) G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_params,
                                                       construct_params);

    return (GObject *)pinyin;
}


static void
ibus_pinyin_engine_destroy (IBusPinYinEngine *pinyin)
{
    if (pinyin->engine) {
        delete pinyin->engine;
        pinyin->engine = NULL;
    }

    IBUS_OBJECT_CLASS (parent_class)->destroy ((IBusObject *)pinyin);
}




#if 0
static void
ibus_pinyin_engine_commit_current_candidate (IBusPinYinEngine *pinyin)
{
}

static void
ibus_pinyin_engine_open_lookup_table (IBusPinYinEngine *pinyin)
{
}

static void
ibus_pinyin_engine_close_lookup_table (IBusPinYinEngine *pinyin)
{
}

static void
ibus_pinyin_engine_toggle_lookup_table (IBusPinYinEngine *pinyin)
{
}
#endif



static gboolean
ibus_pinyin_engine_process_key_event (IBusEngine     *engine,
                                      guint           keyval,
                                      guint           keycode,
                                      guint           modifiers)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;

    return pinyin->engine->processKeyEvent (keyval, keycode, modifiers);
}

static void
ibus_pinyin_engine_focus_in (IBusEngine *engine)
{

    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    pinyin->engine->focusIn ();

    parent_class->focus_in (engine);
}

static void
ibus_pinyin_engine_focus_out (IBusEngine *engine)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    pinyin->engine->focusOut ();

    parent_class->focus_out (engine);
}

static void
ibus_pinyin_engine_reset (IBusEngine *engine)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    pinyin->engine->reset ();

    parent_class->reset (engine);
}

static void
ibus_pinyin_engine_enable (IBusEngine *engine)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    pinyin->engine->enable ();

    parent_class->enable (engine);
}

static void
ibus_pinyin_engine_disable (IBusEngine *engine)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    pinyin->engine->disable ();

    parent_class->disable (engine);
}

static void
ibus_pinyin_engine_page_up (IBusEngine *engine)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    pinyin->engine->pageUp ();

    parent_class->page_up (engine);
}

static void
ibus_pinyin_engine_page_down (IBusEngine *engine)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    pinyin->engine->pageDown ();

    parent_class->page_down (engine);
}

static void
ibus_pinyin_engine_cursor_up (IBusEngine *engine)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    pinyin->engine->cursorDown ();

    parent_class->cursor_up (engine);
}

static void
ibus_pinyin_engine_cursor_down (IBusEngine *engine)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    pinyin->engine->cursorUp ();

    parent_class->cursor_down (engine);
}

#if 0
static void
ibus_config_value_changed (IBusConfig   *config,
                           const gchar  *section,
                           const gchar  *name,
                           GValue       *value,
                           gpointer      user_data)
{
}
#endif

};

