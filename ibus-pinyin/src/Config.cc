#include "Types.h"
#include "Config.h"
#include "Util.h"

namespace PY {

guint Config::m_option = PINYIN_SIMPLE_PINYIN | PINYIN_CORRECT_ALL;
guint Config::m_option_mask = PINYIN_SIMPLE_PINYIN | PINYIN_CORRECT_ALL;
guint Config::m_page_size = 5;

static const StaticString engine_pinyin ("engine/Pinyin");
static const StaticString correct_pinyin ("CorrectPinyin");
static const StaticString fuzzy_pinyin ("FuzzyPinyin");
static const StaticString page_size ("LookupTablePageSize");

static const struct {
    StaticString name;
    guint option;
    bool defval;
} options [] = {
    { StaticString ("SimplePinyin"),       PINYIN_SIMPLE_PINYIN,       TRUE },
    /* correct */
    { StaticString ("CorrectPinyin_GN_NG"),    PINYIN_CORRECT_GN_TO_NG,    TRUE },
    { StaticString ("CorrectPinyin_GN_NG"),    PINYIN_CORRECT_GN_TO_NG,    TRUE },
    { StaticString ("CorrectPinyin_MG_NG"),    PINYIN_CORRECT_MG_TO_NG,    TRUE },
    { StaticString ("CorrectPinyin_IOU_IU"),   PINYIN_CORRECT_IOU_TO_IU,   TRUE },
    { StaticString ("CorrectPinyin_UEI_UI"),   PINYIN_CORRECT_UEI_TO_UI,   TRUE },
    { StaticString ("CorrectPinyin_UEN_UN"),   PINYIN_CORRECT_UEN_TO_UN,   TRUE },
    { StaticString ("CorrectPinyin_VE_UE"),    PINYIN_CORRECT_VE_TO_UE,    TRUE },
    /* fuzzy pinyin */
    { StaticString ("FuzzyPinyin_C_CH"),      PINYIN_FUZZY_C_CH,  FALSE },
    { StaticString ("FuzzyPinyin_CH_C"),      PINYIN_FUZZY_CH_C,  FALSE },
    { StaticString ("FuzzyPinyin_Z_ZH"),      PINYIN_FUZZY_Z_ZH,  FALSE },
    { StaticString ("FuzzyPinyin_ZH_Z"),      PINYIN_FUZZY_ZH_Z,  FALSE },
    { StaticString ("FuzzyPinyin_S_SH"),      PINYIN_FUZZY_S_SH,  FALSE },
    { StaticString ("FuzzyPinyin_SH_S"),      PINYIN_FUZZY_SH_S,  FALSE },
    { StaticString ("FuzzyPinyin_L_N"),       PINYIN_FUZZY_L_N,   FALSE },
    { StaticString ("FuzzyPinyin_N_L"),       PINYIN_FUZZY_N_L,   FALSE },
    { StaticString ("FuzzyPinyin_F_H"),       PINYIN_FUZZY_F_H,   FALSE },
    { StaticString ("FuzzyPinyin_H_F"),       PINYIN_FUZZY_H_F,   FALSE },
    { StaticString ("FuzzyPinyin_L_R"),       PINYIN_FUZZY_L_R,   FALSE },
    { StaticString ("FuzzyPinyin_R_L"),       PINYIN_FUZZY_R_L,   FALSE },
    { StaticString ("FuzzyPinyin_K_G"),       PINYIN_FUZZY_K_G,   FALSE },
    { StaticString ("FuzzyPinyin_G_K"),       PINYIN_FUZZY_G_K,   FALSE },
    { StaticString ("FuzzyPinyin_AN_ANG"),    PINYIN_FUZZY_AN_ANG,    FALSE },
    { StaticString ("FuzzyPinyin_ANG_AN"),    PINYIN_FUZZY_ANG_AN,    FALSE },
    { StaticString ("FuzzyPinyin_EN_ENG"),    PINYIN_FUZZY_EN_ENG,    FALSE },
    { StaticString ("FuzzyPinyin_ENG_EN"),    PINYIN_FUZZY_ENG_EN,    FALSE },
    { StaticString ("FuzzyPinyin_IN_ING"),    PINYIN_FUZZY_IN_ING,    FALSE },
    { StaticString ("FuzzyPinyin_ING_IN"),    PINYIN_FUZZY_ING_IN,    FALSE },
    { StaticString ("FuzzyPinyin_UAN_UANG"),  PINYIN_FUZZY_UAN_UANG,  FALSE },
    { StaticString ("FuzzyPinyin_UANG_UAN"),  PINYIN_FUZZY_UANG_UAN,  FALSE },
};

void
Config::readDefaultValues (void)
{
    if (read (engine_pinyin, correct_pinyin, true))
        m_option_mask |= PINYIN_CORRECT_ALL;
    else
        m_option_mask ^= PINYIN_CORRECT_ALL;

    if (read (engine_pinyin, fuzzy_pinyin, false))
        m_option_mask |= PINYIN_FUZZY_ALL;
    else
        m_option_mask ^= PINYIN_FUZZY_ALL;

    /* read values */
    for (guint i = 0;i < sizeof (options) / sizeof (options[0]); i++) {
        if (read (engine_pinyin, options[i].name, options[i].defval))
            m_option |= options[i].option;
        else
            m_option ^= options[i].option;
    }

    m_page_size = read (engine_pinyin, page_size, 5);
}

inline bool
Config::read (const gchar *section, const gchar *name, bool defval)
{
    GValue value = {0};
    if (ibus_config_get_value (m_config, section, name, &value)) {
        if (G_VALUE_TYPE (&value) == G_TYPE_BOOLEAN)
            return g_value_get_boolean (&value);
    }
    return defval;
}

inline gint
Config::read (const gchar *section, const gchar *name, gint defval)
{
    GValue value = {0};
    if (ibus_config_get_value (m_config, section, name, &value)) {
        if (G_VALUE_TYPE (&value) == G_TYPE_INT)
            return g_value_get_int (&value);
    }
    return defval;
}

void
Config::valueChangedCallback (IBusConfig    *config,
                              const gchar   *section,
                              const gchar   *name,
                              const GValue  *value,
                              Config        *self)
{
    if (engine_pinyin != section)
        return;

    /* correct pinyin */
    if (correct_pinyin == name) {
        gboolean v = TRUE;
        if (G_LIKELY (value != NULL && G_VALUE_TYPE (value) == G_TYPE_BOOLEAN))
            v = g_value_get_boolean (value);
        if (v)
            m_option_mask |= PINYIN_CORRECT_ALL;
        else
            m_option_mask ^= PINYIN_CORRECT_ALL;
    }

    /* fuzzy pinyin */
    if (fuzzy_pinyin == name) {
        gboolean v = TRUE;
        if (G_LIKELY (value != NULL && G_VALUE_TYPE (value) == G_TYPE_BOOLEAN))
            v = g_value_get_boolean (value);
        if (v)
            m_option_mask |= PINYIN_FUZZY_ALL;
        else
            m_option_mask ^= PINYIN_FUZZY_ALL;
    }

    for (guint i = 0;i < sizeof (options) / sizeof (options[0]); i++) {
        if (G_LIKELY (options[i].name != name))
            continue;

        gboolean v = options[i].defval;
        if (G_LIKELY (value != NULL && G_VALUE_TYPE (value) == G_TYPE_BOOLEAN))
            v = g_value_get_boolean (value);
        if (v)
            m_option |= options[i].option;
        else
            m_option ^= options[i].option;
    }

    /* lookup table page size */
    if (page_size == name) {
        if (value != NULL && G_VALUE_TYPE (value) == G_TYPE_INT)
            m_page_size = g_value_get_int (value);
    }
}


};
