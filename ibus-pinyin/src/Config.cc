#include "Types.h"
#include "Config.h"
#include "Util.h"

namespace PY {

guint Config::m_option = PINYIN_SIMPLE_PINYIN | PINYIN_CORRECT_ALL;
guint Config::m_option_mask = PINYIN_SIMPLE_PINYIN | PINYIN_CORRECT_ALL;

void
Config::value_changed_cb (IBusConfig    *config,
                          const gchar   *section,
                          const gchar   *name,
                          const GValue  *value,
                          Config        *self)
{
    static const StaticString engine_pinyin ("engine/PinYin");
    static const StaticString correct_pinyin ("CORRECT_PINYIN");
    static const StaticString fuzzy_pinyin ("FUZZY_PINYIN");

    static const struct {
        StaticString name;
        guint option;
        gboolean _default;
    } options [] = {
        { StaticString ("SIMPLE_PINYIN"),       PINYIN_SIMPLE_PINYIN,       TRUE },
        /* correct */
        { StaticString ("CORRECT_GN_TO_NG"),    PINYIN_CORRECT_GN_TO_NG,    TRUE },
        { StaticString ("CORRECT_GN_TO_NG"),    PINYIN_CORRECT_GN_TO_NG,    TRUE },
        { StaticString ("CORRECT_MG_TO_NG"),    PINYIN_CORRECT_MG_TO_NG,    TRUE },
        { StaticString ("CORRECT_IOU_TO_IU"),   PINYIN_CORRECT_IOU_TO_IU,   TRUE },
        { StaticString ("CORRECT_UEI_TO_UI"),   PINYIN_CORRECT_UEI_TO_UI,   TRUE },
        { StaticString ("CORRECT_UEN_TO_UN"),   PINYIN_CORRECT_UEN_TO_UN,   TRUE },
        { StaticString ("CORRECT_VE_TO_UE"),    PINYIN_CORRECT_VE_TO_UE,    TRUE },
        /* fuzzy pinyin */
        { StaticString ("FUZZY_C_CH"),      PINYIN_FUZZY_C_CH,  FALSE },
        { StaticString ("FUZZY_CH_C"),      PINYIN_FUZZY_CH_C,  FALSE },
        { StaticString ("FUZZY_Z_ZH"),      PINYIN_FUZZY_Z_ZH,  FALSE },
        { StaticString ("FUZZY_ZH_Z"),      PINYIN_FUZZY_ZH_Z,  FALSE },
        { StaticString ("FUZZY_S_SH"),      PINYIN_FUZZY_S_SH,  FALSE },
        { StaticString ("FUZZY_SH_S"),      PINYIN_FUZZY_SH_S,  FALSE },
        { StaticString ("FUZZY_L_N"),       PINYIN_FUZZY_L_N,   FALSE },
        { StaticString ("FUZZY_N_L"),       PINYIN_FUZZY_N_L,   FALSE },
        { StaticString ("FUZZY_F_H"),       PINYIN_FUZZY_F_H,   FALSE },
        { StaticString ("FUZZY_H_F"),       PINYIN_FUZZY_H_F,   FALSE },
        { StaticString ("FUZZY_L_R"),       PINYIN_FUZZY_L_R,   FALSE },
        { StaticString ("FUZZY_R_L"),       PINYIN_FUZZY_R_L,   FALSE },
        { StaticString ("FUZZY_K_G"),       PINYIN_FUZZY_K_G,   FALSE },
        { StaticString ("FUZZY_G_K"),       PINYIN_FUZZY_G_K,   FALSE },
        { StaticString ("FUZZY_AN_ANG"),    PINYIN_FUZZY_AN_ANG,    FALSE },
        { StaticString ("FUZZY_ANG_AN"),    PINYIN_FUZZY_ANG_AN,    FALSE },
        { StaticString ("FUZZY_EN_ENG"),    PINYIN_FUZZY_EN_ENG,    FALSE },
        { StaticString ("FUZZY_ENG_EN"),    PINYIN_FUZZY_ENG_EN,    FALSE },
        { StaticString ("FUZZY_IN_ING"),    PINYIN_FUZZY_IN_ING,    FALSE },
        { StaticString ("FUZZY_ING_IN"),    PINYIN_FUZZY_ING_IN,    FALSE },
        { StaticString ("FUZZY_UAN_UANG"),  PINYIN_FUZZY_UAN_UANG,  FALSE },
        { StaticString ("FUZZY_UANG_UAN"),  PINYIN_FUZZY_UANG_UAN,  FALSE },
    };

    if (engine_pinyin != section)
        return;

    if (correct_pinyin == name) {
        gboolean v = TRUE;
        if (G_LIKELY (value != NULL || G_VALUE_TYPE (value) == G_TYPE_BOOLEAN))
            v = g_value_get_boolean (value);
        if (v)
            m_option_mask |= PINYIN_CORRECT_ALL;
        else
            m_option_mask ^= PINYIN_CORRECT_ALL;
    }

    if (fuzzy_pinyin == name) {
        gboolean v = TRUE;
        if (G_LIKELY (value != NULL || G_VALUE_TYPE (value) == G_TYPE_BOOLEAN))
            v = g_value_get_boolean (value);
        if (v)
            m_option_mask |= PINYIN_FUZZY_ALL;
        else
            m_option_mask ^= PINYIN_FUZZY_ALL;
    }

    for (guint i = 0;i < sizeof (options) / sizeof (options[0]); i++) {
        if (G_LIKELY (options[i].name != name))
            continue;

        gboolean v = options[i]._default;
        if (G_LIKELY (value != NULL || G_VALUE_TYPE (value) == G_TYPE_BOOLEAN))
            v = g_value_get_boolean (value);
        if (v)
            m_option |= options[i].option;
        else
            m_option ^= options[i].option;
    }
}


};
