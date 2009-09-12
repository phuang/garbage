/* vim:set et sts=4: */

#include <ibus.h>
#include <string.h>
#include "Engine.h"
#include "PinYinEngine.h"

namespace PY {
/* code of engine class of GObject */
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
    // GObjectClass *object_class = G_OBJECT_CLASS (klass);
    IBusObjectClass *ibus_object_class = IBUS_OBJECT_CLASS (klass);
    IBusEngineClass *engine_class = IBUS_ENGINE_CLASS (klass);

    parent_class = (IBusEngineClass *) g_type_class_peek_parent (klass);

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

static void
ibus_pinyin_engine_destroy (IBusPinYinEngine *pinyin)
{
    if (pinyin->engine) {
        delete pinyin->engine;
        pinyin->engine = NULL;
    }
    IBUS_OBJECT_CLASS (parent_class)->destroy ((IBusObject *)pinyin);
}

static gboolean
ibus_pinyin_engine_process_key_event (IBusEngine     *engine,
                                      guint           keyval,
                                      guint           keycode,
                                      guint           modifiers)
{
    IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;
    return pinyin->engine->processKeyEvent (keyval, keycode, modifiers);
}

#define FUNCTION(name, Name)                                        \
    static void                                                     \
    ibus_pinyin_engine_##name (IBusEngine *engine)                  \
    {                                                               \
        IBusPinYinEngine *pinyin = (IBusPinYinEngine *) engine;     \
        pinyin->engine->Name ();                                    \
        parent_class->name (engine);                                \
    }
FUNCTION(focus_in,    focusIn)
FUNCTION(focus_out,   focusOut)
FUNCTION(reset,       reset)
FUNCTION(enable,      enable)
FUNCTION(disable,     disable)
FUNCTION(page_up,     pageUp)
FUNCTION(page_down,   pageDown)
FUNCTION(cursor_up,   cursorUp)
FUNCTION(cursor_down, cursorDown)
#undef FUNCTION


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

