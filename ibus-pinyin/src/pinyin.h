/* vim:set et sts=4: */
#ifndef __PINYIN_H_
#define __PINYIN_H_

#define PINYIN_ID_VOID  (0)
#define PINYIN_ID_B     (2)
#define PINYIN_ID_C     (3)
#define PINYIN_ID_D     (4)
#define PINYIN_ID_F     (6)
#define PINYIN_ID_G     (7)
#define PINYIN_ID_H     (8)
#define PINYIN_ID_J     (10)
#define PINYIN_ID_K     (11)
#define PINYIN_ID_L     (12)
#define PINYIN_ID_M     (13)
#define PINYIN_ID_N     (14)
#define PINYIN_ID_P     (16)
#define PINYIN_ID_Q     (17)
#define PINYIN_ID_R     (18)
#define PINYIN_ID_S     (19)
#define PINYIN_ID_T     (20)
#define PINYIN_ID_W     (23)
#define PINYIN_ID_X     (24)
#define PINYIN_ID_Y     (25)
#define PINYIN_ID_Z     (26)
#define PINYIN_ID_CH    (104)
#define PINYIN_ID_SH    (616)
#define PINYIN_ID_ZH    (840)
#define PINYIN_ID_A     (1)
#define PINYIN_ID_E     (5)
#define PINYIN_ID_I     (9)
#define PINYIN_ID_O     (15)
#define PINYIN_ID_U     (21)
#define PINYIN_ID_V     (22)
#define PINYIN_ID_AI    (41)
#define PINYIN_ID_AN    (46)
#define PINYIN_ID_AO    (47)
#define PINYIN_ID_EI    (169)
#define PINYIN_ID_EN    (174)
#define PINYIN_ID_ER    (178)
#define PINYIN_ID_IA    (289)
#define PINYIN_ID_IE    (293)
#define PINYIN_ID_IN    (302)
#define PINYIN_ID_IU    (309)
#define PINYIN_ID_OU    (501)
#define PINYIN_ID_UA    (673)
#define PINYIN_ID_UE    (677)
#define PINYIN_ID_UI    (681)
#define PINYIN_ID_UN    (686)
#define PINYIN_ID_UO    (687)
#define PINYIN_ID_ANG   (1479)
#define PINYIN_ID_ENG   (5575)
#define PINYIN_ID_IAN   (9262)
#define PINYIN_ID_IAO   (9263)
#define PINYIN_ID_ING   (9671)
#define PINYIN_ID_ONG   (15815)
#define PINYIN_ID_UAI   (21545)
#define PINYIN_ID_UAN   (21550)
#define PINYIN_ID_IANG  (296391)
#define PINYIN_ID_IONG  (310727)
#define PINYIN_ID_UANG  (689607)

#define PINYIN_SIMPLE_PINYIN        (1 << 0)
#define PINYIN_CORRECT_GN_TO_NG     (1 << 1)
#define PINYIN_CORRECT_MG_TO_NG     (1 << 2)
#define PINYIN_CORRECT_IOU_TO_IU    (1 << 3)
#define PINYIN_CORRECT_UEI_TO_UI    (1 << 4)
#define PINYIN_CORRECT_UEN_TO_UN    (1 << 5)
#define PINYIN_CORRECT_VE_TO_UE     (1 << 6)

#define PINYIN_FUZZY_C_CH           (1 << 7)
#define PINYIN_FUZZY_Z_ZH           (1 << 8)
#define PINYIN_FUZZY_S_SH           (1 << 9)
#define PINYIN_FUZZY_L_N            (1 << 10)
#define PINYIN_FUZZY_F_H            (1 << 11)
#define PINYIN_FUZZY_R_L            (1 << 12)
#define PINYIN_FUZZY_K_G            (1 << 13)

#define PINYIN_FUZZY_AN_ANG         (1 << 14)
#define PINYIN_FUZZY_EN_ENG         (1 << 15)
#define PINYIN_FUZZY_IN_ING         (1 << 16)
#define PINYIN_FUZZY_UAN_UANG       (1 << 17)

typedef struct _PinYin PinYin;
struct _PinYin {
    const char *text;
    const char *sheng;
    const char *yun;
    const int   sheng_id;
    const int   yun_id;
    const int   fsheng_id;
    const int   fyun_id;
    const int   len;
    const int   flags;
};

#ifdef USE_PINYIN_NEW
static struct pinyin_t *
pinyin_new (const gchar *text,
            const gchar *pinyin,
            const gchar *sheng,
            const gchar *yun,
            gint         sheng_id,
            gint         yun_id,
            const gchar *fsheng,
            const gchar *fyun,
            gint         fsheng_id,
            gint         fyun_id,
            int          len)
{
   struct pinyin_t *py;
   py = g_slice_new (struct pinyin_t);
   py->text = text;
   py->pinyin = pinyin;
   py->sheng = sheng;
   py->yun = yun;
   py->sheng_id = sheng_id;
   py->yun_id = yun_id;
   py->len = len;
   return py;
}
#endif

#define pinyin_free(py) g_slice_free (struct pinyin_t, py)

#define PINYIN_TEXT(p)      (((struct pinyin_t *)p)->text)
#define PINYIN_PINYIN(p)    (((struct pinyin_t *)p)->pinyin)
#define PINYIN_SHENG(p)     (((struct pinyin_t *)p)->sheng)
#define PINYIN_YUN(p)       (((struct pinyin_t *)p)->yun)
#define PINYIN_LEN(p)       (((struct pinyin_t *)p)->len)

#endif
