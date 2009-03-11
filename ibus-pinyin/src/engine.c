/* vim:set et sts=4: */

#include <ibus.h>
#include <string.h>
#include "pyparser.h"
#include "engine.h"

#define IBUS_PINYIN_ENGINE(obj)             \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), IBUS_TYPE_PINYIN_ENGINE, IBusPinyinEngine))
#define IBUS_PINYIN_ENGINE_CLASS(klass)     \
    (G_TYPE_CHECK_CLASS_CAST ((klass), IBUS_TYPE_PINYIN_ENGINE, IBusPinyinEngineClass))
#define IBUS_IS_PINYIN_ENGINE(obj)          \
    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IBUS_TYPE_PINYIN_ENGINE))
#define IBUS_IS_PINYIN_ENGINE_CLASS(klass)  \
    (G_TYPE_CHECK_CLASS_TYPE ((klass), IBUS_TYPE_PINYIN_ENGINE))
#define IBUS_PINYIN_ENGINE_GET_CLASS(obj)   \
    (G_TYPE_INSTANCE_GET_CLASS ((obj), IBUS_TYPE_PINYIN_ENGINE, IBusPinyinEngineClass))


typedef struct _IBusPinyinEngine IBusPinyinEngine;
typedef struct _IBusPinyinEngineClass IBusPinyinEngineClass;

struct _IBusPinyinEngine {
	IBusEngine parent;

    /* members */

    GString *input_buffer;
    guint    input_cursor;

    IBusLookupTable *table;
    IBusProperty    *pinyin_mode_prop;
    IBusPropList    *prop_list;
};

struct _IBusPinyinEngineClass {
	IBusEngineClass parent;

        /* members */
        PYParser *parser;
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

    klass->parser = py_parser_new (0xfffffffe);
}

static void
ibus_pinyin_engine_init (IBusPinyinEngine *pinyin)
{
    pinyin->input_buffer = g_string_new ("");
    pinyin->input_cursor = 0;

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
    if (pinyin->input_buffer) {
        g_string_free (pinyin->input_buffer, TRUE);
        pinyin->input_buffer = NULL;
    }

    pinyin->input_cursor = 0;

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
    IBusText *text;

    if (pinyin->input_buffer) {

        GList *pys, *p;
        GString *preedit_text;
        gint cursor_pos;

        pys = py_parser_parse (IBUS_PINYIN_ENGINE_GET_CLASS (pinyin)->parser, pinyin->input_buffer->str, pinyin->input_cursor);

        p = pys;

        if (p) {
            preedit_text = g_string_new (((struct pinyin_t *) p->data)->py);
        }
        else {
            preedit_text = g_string_new ("");
        }

        for (p = p->next; p != NULL; p = p->next) {
            
            g_string_append_c (preedit_text, '\'');
            g_string_append (preedit_text, ((struct pinyin_t *) p->data)->py);
        }
        cursor_pos = preedit_text->len;

        g_string_append (preedit_text, pinyin->input_buffer->str + pinyin->input_cursor);
        
        py_parse_free_result (pys);
        
        text = ibus_text_new_from_string (preedit_text->str);
        // ibus_text_append_attribute (text, IBUS_ATTR_TYPE_FOREGROUND, 0x00ffffff, 0, -1);
        // ibus_text_append_attribute (text, IBUS_ATTR_TYPE_BACKGROUND, 0x00000000, 0, -1);
        ibus_engine_update_preedit_text ((IBusEngine *)pinyin,
                                         text,
                                         cursor_pos,
                                         TRUE);
        g_object_unref (text);
        g_string_free (preedit_text, TRUE);
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
ibus_pinyin_engine_process_key_event (IBusEngine     *engine,
                                      guint           keyval,
                                      guint           modifiers)
{
    IBusPinyinEngine *pinyin = (IBusPinyinEngine *) engine;

    gboolean retval = FALSE;
    gboolean need_update = FALSE;

    if (modifiers & IBUS_RELEASE_MASK) {
        return TRUE;
    }

    switch (keyval) {
    case IBUS_BackSpace:
        if (pinyin->input_cursor > 0) {
            pinyin->input_cursor --;
            g_string_erase (pinyin->input_buffer, pinyin->input_cursor, 1);
            retval = TRUE;
            need_update = TRUE;
        }
        else {
            if (pinyin->input_buffer->len == 0)
                retval = FALSE;
            else
                retval = TRUE;
        }
        break;
    case IBUS_Delete:
        if (pinyin->input_cursor < pinyin->input_buffer->len) {
            g_string_erase (pinyin->input_buffer, pinyin->input_cursor, 1);
            retval = TRUE;
            need_update = TRUE;
        }
        else {
            if (pinyin->input_buffer->len == 0)
                retval = FALSE;
            else
                retval = TRUE;
        }
        break;
    case IBUS_Escape:
        if (pinyin->input_buffer->len == 0) {
            retval = FALSE;
        }
        else {
            g_string_assign (pinyin->input_buffer, "");
            pinyin->input_cursor = 0;
            retval = TRUE;
            need_update = TRUE;
        }
        break;
    case IBUS_Left:
        if (pinyin->input_buffer->len == 0) {
            retval = FALSE;
        }
        else {
            if (pinyin->input_cursor > 0) {
                pinyin->input_cursor --;
                need_update = TRUE;
            }
            retval = TRUE;
        }
        break;
     case IBUS_Right:
        if (pinyin->input_buffer->len == 0) {
            retval = FALSE;
        }
        else {
            if (pinyin->input_cursor < pinyin->input_buffer->len) {
                pinyin->input_cursor ++;
                need_update = TRUE;
            }
            retval = TRUE;
        }
        break;
    default:
        g_string_insert_c (pinyin->input_buffer, pinyin->input_cursor++, keyval);
        retval = TRUE;
        need_update = TRUE;
        break;
    }

    if (need_update) {
        ibus_pinyin_engine_update_preedit_text (pinyin);
    }
    return retval;
}

static void
ibus_pinyin_engine_toggle_pinyin_mode (IBusPinyinEngine *pinyin)
{
}

static void
ibus_pinyin_engine_focus_in (IBusEngine *engine)
{
    parent_class->focus_in (engine);
}

static void
ibus_pinyin_engine_focus_out (IBusEngine *engine)
{
    parent_class->focus_out (engine);
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
