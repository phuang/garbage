/* vim:set et sts=4: */

#include <ibus.h>
#include <string.h>
#include "engine.h"

typedef struct _IBusPinyinEngine IBusPinyinEngine;
typedef struct _IBusPinyinEngineClass IBusPinyinEngineClass;

struct _IBusPinyinEngine {
	IBusEngine parent;

    /* members */

    IBusLookupTable *table;
    IBusProperty    *pinyin_mode_prop;
    IBusPropList    *prop_list;
};

struct _IBusPinyinEngineClass {
	IBusEngineClass parent;
};

/* functions prototype */
static void	ibus_pinyin_engine_class_init   (IBusPinyinEngineClass  *klass);
static void	ibus_pinyin_engine_init		(IBusPinyinEngine	*pinyin);
static GObject*
            ibus_pinyin_engine_constructor      (GType                   type,
                                                 guint                   n_construct_params,
                                                 GObjectConstructParam  *construct_params);
static void	ibus_pinyin_engine_destroy	(IBusPinyinEngine	*pinyin);
static gboolean	ibus_pinyin_engine_process_key_event
                                                (IBusEngine             *engine,
                                                 guint                   keyval,
                                                 guint                   modifiers);
static void ibus_pinyin_engine_focus_in         (IBusEngine             *engine);
static void ibus_pinyin_engine_focus_out        (IBusEngine             *engine);
static void ibus_pinyin_engine_reset            (IBusEngine             *engine);
static void ibus_pinyin_engine_enable           (IBusEngine             *engine);
static void ibus_pinyin_engine_disable          (IBusEngine             *engine);

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

static void ibus_pinyin_engine_page_up          (IBusEngine             *engine);
static void ibus_pinyin_engine_page_down        (IBusEngine             *engine);
static void ibus_pinyin_engine_cursor_up        (IBusEngine             *engine);
static void ibus_pinyin_engine_cursor_down      (IBusEngine             *engine);
static void ibus_pinyin_engine_toggle_pinyin_mode
                                                (IBusPinyinEngine       *pinyin);
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

static void ibus_pinyin_engine_flush        (IBusPinyinEngine       *pinyin);
static void ibus_pinyin_engine_update_preedit_text
                                            (IBusPinyinEngine       *pinyin);
static void ibus_config_value_changed       (IBusConfig             *config,
                                             const gchar            *section,
                                             const gchar            *name,
                                             GValue                 *value,
                                             gpointer                user_data);

static IBusEngineClass *parent_class = NULL;

GType
ibus_pinyin_engine_get_type (void)
{
	static GType type = 0;

	static const GTypeInfo type_info = {
		sizeof (IBusPinyinEngineClass),
		(GBaseInitFunc) NULL,
		(GBaseFinalizeFunc) NULL,
		(GClassInitFunc) ibus_pinyin_engine_class_init,
		NULL,
		NULL,
		sizeof (IBusPinyinEngine),
		0,
		(GInstanceInitFunc) ibus_pinyin_engine_init,
	};

	if (type == 0) {
		type = g_type_register_static (IBUS_TYPE_ENGINE,
                                               "IBusPinyinEngine",
                                               &type_info,
                                               (GTypeFlags) 0);
	}

	return type;
}

static void
ibus_pinyin_engine_class_init (IBusPinyinEngineClass *klass)
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
ibus_pinyin_engine_init (IBusPinyinEngine *pinyin)
{
    pinyin->pinyin_mode_prop = ibus_property_new ("pinyin_mode_prop",
                                           PROP_TYPE_NORMAL,
                                           NULL,
                                           NULL,
                                           NULL,
                                           TRUE,
                                           FALSE,
                                           0,
                                           NULL);

    pinyin->prop_list = ibus_prop_list_new ();
    ibus_prop_list_append (pinyin->prop_list,  pinyin->pinyin_mode_prop);

    pinyin->table = ibus_lookup_table_new (9, 0, TRUE, FALSE);
}

static GObject*
ibus_pinyin_engine_constructor (GType                   type,
                                guint                   n_construct_params,
                                GObjectConstructParam  *construct_params)
{
    IBusPinyinEngine *pinyin;

    pinyin = (IBusPinyinEngine *) G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_params,
                                                       construct_params);

    return (GObject *)pinyin;
}


static void
ibus_pinyin_engine_destroy (IBusPinyinEngine *pinyin)
{
    if (pinyin->prop_list) {
        g_object_unref (pinyin->prop_list);
        pinyin->prop_list = NULL;
    }

    if (pinyin->pinyin_mode_prop) {
        g_object_unref (pinyin->pinyin_mode_prop);
        pinyin->pinyin_mode_prop = NULL;
    }

    if (pinyin->table) {
        g_object_unref (pinyin->table);
        pinyin->table = NULL;
    }

    IBUS_OBJECT_CLASS (parent_class)->destroy ((IBusObject *)pinyin);
}

static void
ibus_pinyin_engine_update_preedit_text (IBusPinyinEngine *pinyin)
{
    const gunichar *str = L"Hello";;
    IBusText *text;

    if (str != NULL && str[0] != 0) {
        text = ibus_text_new_from_ucs4 (str);
        ibus_text_append_attribute (text, IBUS_ATTR_TYPE_FOREGROUND, 0x00ffffff, 0, -1);
        ibus_text_append_attribute (text, IBUS_ATTR_TYPE_BACKGROUND, 0x00000000, 0, -1);
        ibus_engine_update_preedit_text ((IBusEngine *)pinyin,
                                         text,
                                         ibus_text_get_length (text),
                                         TRUE);
        g_object_unref (text);
    }
    else {
        text = ibus_text_new_from_static_string ("");
        ibus_engine_update_preedit_text ((IBusEngine *)pinyin, text, 0, FALSE);
        g_object_unref (text);
    }
}

static void
ibus_pinyin_engine_update_auxiliary_text (IBusPinyinEngine *pinyin)
{
    guint cursor_pos;
    const char* comment;
    IBusText* text;

    cursor_pos = ibus_lookup_table_get_cursor_pos (pinyin->table);
    comment = hanja_list_get_nth_comment (pinyin->hanja_list, cursor_pos);

    text = ibus_text_new_from_string (comment);
    ibus_engine_update_auxiliary_text ((IBusEngine *)pinyin, text, TRUE);
    g_object_unref (text);
}

static void
ibus_pinyin_engine_update_lookup_table (IBusPinyinEngine *pinyin)
{
    ibus_engine_update_lookup_table ((IBusEngine *)pinyin, pinyin->table, TRUE);
}

static void
ibus_pinyin_engine_commit_current_candidate (IBusPinyinEngine *pinyin)
{
}

static void
ibus_pinyin_engine_open_lookup_table (IBusPinyinEngine *pinyin)
{
}

static void
ibus_pinyin_engine_close_lookup_table (IBusPinyinEngine *pinyin)
{
}

static void
ibus_pinyin_engine_toggle_lookup_table (IBusPinyinEngine *pinyin)
{
}

static gboolean
ibus_pinyin_engine_process_candidate_key_event (IBusPinyinEngine    *pinyin,
                                                guint                keyval,
                                                guint                modifiers)
{
}

static gboolean
ibus_pinyin_engine_process_key_event (IBusEngine     *engine,
                                      guint           keyval,
                                      guint           modifiers)
{
    IBusPinyinEngine *pinyin = (IBusPinyinEngine *) engine;
    
    return TRUE;
}

static void
ibus_pinyin_engine_toggle_pinyin_mode (IBusPinyinEngine *pinyin)
{
    IBusText *text;
    pinyin->pinyin_mode = ! pinyin->pinyin_mode;

    ibus_pinyin_engine_flush (pinyin);

    if (pinyin->pinyin_mode) {
        text = ibus_text_new_from_static_string ("한");
    }
    else {
        text = ibus_text_new_from_static_string ("A");
    }

    ibus_property_set_label (pinyin->pinyin_mode_prop, text);
    ibus_engine_update_property ((IBusEngine *)pinyin, pinyin->pinyin_mode_prop);
    g_object_unref (text);
}

static void
ibus_pinyin_engine_focus_in (IBusEngine *engine)
{
    parent_class->focus_in (engine);
}

static void
ibus_pinyin_engine_focus_out (IBusEngine *engine)
{
    parent_class->focus_out ((IBusEngine *) pinyin);
}

static void
ibus_pinyin_engine_reset (IBusEngine *engine)
{
    parent_class->reset (engine);
}

static void
ibus_pinyin_engine_enable (IBusEngine *engine)
{
    parent_class->enable (engine);
}

static void
ibus_pinyin_engine_disable (IBusEngine *engine)
{
    parent_class->disable (engine);
}

static void
ibus_pinyin_engine_page_up (IBusEngine *engine)
{
    parent_class->page_up (engine);
}

static void
ibus_pinyin_engine_page_down (IBusEngine *engine)
{
    parent_class->page_down (engine);
}

static void
ibus_pinyin_engine_cursor_up (IBusEngine *engine)
{
    parent_class->cursor_up (engine);
}

static void
ibus_pinyin_engine_cursor_down (IBusEngine *engine)
{
    parent_class->cursor_down (engine);
}

static void
ibus_config_value_changed (IBusConfig   *config,
                           const gchar  *section,
                           const gchar  *name,
                           GValue       *value,
                           gpointer      user_data)
{
}
