

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

static const PinYin pinyin_a_1[] = {
    { "a", "", "a", 0, 1, 0, 0, 1, 0 },
    { 0 },
};

static const PinYin pinyin_a_2[] = {
    { "ai", "", "ai", 0, 41, 0, 0, 2, 0 },
    { "an", "", "an", 0, 46, 0, 1479, 2, 0 },
    { "ao", "", "ao", 0, 47, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_a_3[] = {
    { "agn", "", "ang", 0, 1479, 0, 46, 3, PINYIN_CORRECT_GN_TO_NG },
    { "amg", "", "ang", 0, 1479, 0, 46, 3, PINYIN_CORRECT_MG_TO_NG },
    { "ang", "", "ang", 0, 1479, 0, 46, 3, 0 },
    { 0 },
};

static const PinYin *pinyin_a[] = {
    0,
    pinyin_a_1,
    pinyin_a_2,
    pinyin_a_3,
    0,
    0,
    0,
};

static const PinYin pinyin_b_1[] = {
    { "b", "b", "", 2, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_b_2[] = {
    { "ba", "b", "a", 2, 1, 0, 0, 2, 0 },
    { "bi", "b", "i", 2, 9, 0, 0, 2, 0 },
    { "bo", "b", "o", 2, 15, 0, 0, 2, 0 },
    { "bu", "b", "u", 2, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_b_3[] = {
    { "bai", "b", "ai", 2, 41, 0, 0, 3, 0 },
    { "ban", "b", "an", 2, 46, 0, 1479, 3, 0 },
    { "bao", "b", "ao", 2, 47, 0, 0, 3, 0 },
    { "bei", "b", "ei", 2, 169, 0, 0, 3, 0 },
    { "ben", "b", "en", 2, 174, 0, 5575, 3, 0 },
    { "bie", "b", "ie", 2, 293, 0, 0, 3, 0 },
    { "bin", "b", "in", 2, 302, 0, 9671, 3, 0 },
    { 0 },
};

static const PinYin pinyin_b_4[] = {
    { "bagn", "b", "ang", 2, 1479, 0, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "bamg", "b", "ang", 2, 1479, 0, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "bang", "b", "ang", 2, 1479, 0, 46, 4, 0 },
    { "begn", "b", "eng", 2, 5575, 0, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "bemg", "b", "eng", 2, 5575, 0, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "beng", "b", "eng", 2, 5575, 0, 174, 4, 0 },
    { "bian", "b", "ian", 2, 9262, 0, 0, 4, 0 },
    { "biao", "b", "iao", 2, 9263, 0, 0, 4, 0 },
    { "bign", "b", "ing", 2, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "bimg", "b", "ing", 2, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "bing", "b", "ing", 2, 9671, 0, 302, 4, 0 },
    { 0 },
};

static const PinYin *pinyin_b[] = {
    0,
    pinyin_b_1,
    pinyin_b_2,
    pinyin_b_3,
    pinyin_b_4,
    0,
    0,
};

static const PinYin pinyin_c_1[] = {
    { "c", "c", "", 3, 0, 104, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_c_2[] = {
    { "ca", "c", "a", 3, 1, 104, 0, 2, 0 },
    { "ce", "c", "e", 3, 5, 104, 0, 2, 0 },
    { "ch", "ch", "", 104, 0, 3, 0, 2, PINYIN_SIMPLE_PINYIN },
    { "ci", "c", "i", 3, 9, 104, 0, 2, 0 },
    { "cu", "c", "u", 3, 21, 104, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_c_3[] = {
    { "cai", "c", "ai", 3, 41, 104, 0, 3, 0 },
    { "can", "c", "an", 3, 46, 104, 1479, 3, 0 },
    { "cao", "c", "ao", 3, 47, 104, 0, 3, 0 },
    { "cen", "c", "en", 3, 174, 104, 5575, 3, 0 },
    { "cha", "ch", "a", 104, 1, 3, 0, 3, 0 },
    { "che", "ch", "e", 104, 5, 3, 0, 3, 0 },
    { "chi", "ch", "i", 104, 9, 3, 0, 3, 0 },
    { "chu", "ch", "u", 104, 21, 3, 0, 3, 0 },
    { "cou", "c", "ou", 3, 501, 104, 0, 3, 0 },
    { "cui", "c", "ui", 3, 681, 104, 0, 3, 0 },
    { "cun", "c", "un", 3, 686, 104, 0, 3, 0 },
    { "cuo", "c", "uo", 3, 687, 104, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_c_4[] = {
    { "cagn", "c", "ang", 3, 1479, 104, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "camg", "c", "ang", 3, 1479, 104, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "cang", "c", "ang", 3, 1479, 104, 46, 4, 0 },
    { "cegn", "c", "eng", 3, 5575, 104, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "cemg", "c", "eng", 3, 5575, 104, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "ceng", "c", "eng", 3, 5575, 104, 174, 4, 0 },
    { "chai", "ch", "ai", 104, 41, 3, 0, 4, 0 },
    { "chan", "ch", "an", 104, 46, 3, 1479, 4, 0 },
    { "chao", "ch", "ao", 104, 47, 3, 0, 4, 0 },
    { "chen", "ch", "en", 104, 174, 3, 5575, 4, 0 },
    { "chou", "ch", "ou", 104, 501, 3, 0, 4, 0 },
    { "chui", "ch", "ui", 104, 681, 3, 0, 4, 0 },
    { "chun", "ch", "un", 104, 686, 3, 0, 4, 0 },
    { "chuo", "ch", "uo", 104, 687, 3, 0, 4, 0 },
    { "cogn", "c", "ong", 3, 15815, 104, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "comg", "c", "ong", 3, 15815, 104, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "cong", "c", "ong", 3, 15815, 104, 0, 4, 0 },
    { "cuai", "c", "uai", 3, 21545, 104, 0, 4, PINYIN_FUZZY_C_CH },
    { "cuan", "c", "uan", 3, 21550, 104, 689607, 4, 0 },
    { "cuei", "c", "ui", 3, 681, 104, 0, 4, PINYIN_CORRECT_UEI_TO_UI },
    { "cuen", "c", "un", 3, 686, 104, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_c_5[] = {
    { "chagn", "ch", "ang", 104, 1479, 3, 46, 5, PINYIN_CORRECT_GN_TO_NG },
    { "chamg", "ch", "ang", 104, 1479, 3, 46, 5, PINYIN_CORRECT_MG_TO_NG },
    { "chang", "ch", "ang", 104, 1479, 3, 46, 5, 0 },
    { "chegn", "ch", "eng", 104, 5575, 3, 174, 5, PINYIN_CORRECT_GN_TO_NG },
    { "chemg", "ch", "eng", 104, 5575, 3, 174, 5, PINYIN_CORRECT_MG_TO_NG },
    { "cheng", "ch", "eng", 104, 5575, 3, 174, 5, 0 },
    { "chogn", "ch", "ong", 104, 15815, 3, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "chomg", "ch", "ong", 104, 15815, 3, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "chong", "ch", "ong", 104, 15815, 3, 0, 5, 0 },
    { "chuai", "ch", "uai", 104, 21545, 3, 0, 5, 0 },
    { "chuan", "ch", "uan", 104, 21550, 3, 689607, 5, 0 },
    { "chuei", "ch", "ui", 104, 681, 3, 0, 5, PINYIN_CORRECT_UEI_TO_UI },
    { "chuen", "ch", "un", 104, 686, 3, 0, 5, PINYIN_CORRECT_UEN_TO_UN },
    { "cuang", "c", "uang", 3, 689607, 104, 21550, 5, PINYIN_FUZZY_C_CH | PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin pinyin_c_6[] = {
    { "chuagn", "ch", "uang", 104, 689607, 3, 21550, 6, PINYIN_CORRECT_GN_TO_NG },
    { "chuamg", "ch", "uang", 104, 689607, 3, 21550, 6, PINYIN_CORRECT_MG_TO_NG },
    { "chuang", "ch", "uang", 104, 689607, 3, 21550, 6, 0 },
    { 0 },
};

static const PinYin *pinyin_c[] = {
    0,
    pinyin_c_1,
    pinyin_c_2,
    pinyin_c_3,
    pinyin_c_4,
    pinyin_c_5,
    pinyin_c_6,
};

static const PinYin pinyin_d_1[] = {
    { "d", "d", "", 4, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_d_2[] = {
    { "da", "d", "a", 4, 1, 0, 0, 2, 0 },
    { "de", "d", "e", 4, 5, 0, 0, 2, 0 },
    { "di", "d", "i", 4, 9, 0, 0, 2, 0 },
    { "du", "d", "u", 4, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_d_3[] = {
    { "dai", "d", "ai", 4, 41, 0, 0, 3, 0 },
    { "dan", "d", "an", 4, 46, 0, 1479, 3, 0 },
    { "dao", "d", "ao", 4, 47, 0, 0, 3, 0 },
    { "dei", "d", "ei", 4, 169, 0, 0, 3, 0 },
    { "den", "d", "en", 4, 174, 0, 5575, 3, PINYIN_FUZZY_EN_ENG },
    { "dia", "d", "ia", 4, 289, 0, 0, 3, 0 },
    { "die", "d", "ie", 4, 293, 0, 0, 3, 0 },
    { "din", "d", "in", 4, 302, 0, 9671, 3, PINYIN_FUZZY_IN_ING },
    { "diu", "d", "iu", 4, 309, 0, 0, 3, 0 },
    { "dou", "d", "ou", 4, 501, 0, 0, 3, 0 },
    { "dui", "d", "ui", 4, 681, 0, 0, 3, 0 },
    { "dun", "d", "un", 4, 686, 0, 0, 3, 0 },
    { "duo", "d", "uo", 4, 687, 0, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_d_4[] = {
    { "dagn", "d", "ang", 4, 1479, 0, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "damg", "d", "ang", 4, 1479, 0, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "dang", "d", "ang", 4, 1479, 0, 46, 4, 0 },
    { "degn", "d", "eng", 4, 5575, 0, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "demg", "d", "eng", 4, 5575, 0, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "deng", "d", "eng", 4, 5575, 0, 174, 4, 0 },
    { "dian", "d", "ian", 4, 9262, 0, 0, 4, 0 },
    { "diao", "d", "iao", 4, 9263, 0, 0, 4, 0 },
    { "dign", "d", "ing", 4, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "dimg", "d", "ing", 4, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "ding", "d", "ing", 4, 9671, 0, 302, 4, 0 },
    { "diou", "d", "iu", 4, 309, 0, 0, 4, PINYIN_CORRECT_IOU_TO_IU },
    { "dogn", "d", "ong", 4, 15815, 0, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "domg", "d", "ong", 4, 15815, 0, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "dong", "d", "ong", 4, 15815, 0, 0, 4, 0 },
    { "duan", "d", "uan", 4, 21550, 0, 689607, 4, 0 },
    { "duei", "d", "ui", 4, 681, 0, 0, 4, PINYIN_CORRECT_UEI_TO_UI },
    { "duen", "d", "un", 4, 686, 0, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_d_5[] = {
    { "duang", "d", "uang", 4, 689607, 0, 21550, 5, PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin *pinyin_d[] = {
    0,
    pinyin_d_1,
    pinyin_d_2,
    pinyin_d_3,
    pinyin_d_4,
    pinyin_d_5,
    0,
};

static const PinYin pinyin_e_1[] = {
    { "e", "", "e", 0, 5, 0, 0, 1, 0 },
    { 0 },
};

static const PinYin pinyin_e_2[] = {
    { "ei", "", "ei", 0, 169, 0, 0, 2, 0 },
    { "en", "", "en", 0, 174, 0, 5575, 2, 0 },
    { "er", "", "er", 0, 178, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin *pinyin_e[] = {
    0,
    pinyin_e_1,
    pinyin_e_2,
    0,
    0,
    0,
    0,
};

static const PinYin pinyin_f_1[] = {
    { "f", "f", "", 6, 0, 8, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_f_2[] = {
    { "fa", "f", "a", 6, 1, 8, 0, 2, 0 },
    { "fe", "f", "e", 6, 5, 8, 0, 2, PINYIN_FUZZY_F_H },
    { "fo", "f", "o", 6, 15, 8, 0, 2, 0 },
    { "fu", "f", "u", 6, 21, 8, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_f_3[] = {
    { "fai", "f", "ai", 6, 41, 8, 0, 3, PINYIN_FUZZY_F_H },
    { "fan", "f", "an", 6, 46, 8, 1479, 3, 0 },
    { "fao", "f", "ao", 6, 47, 8, 0, 3, PINYIN_FUZZY_F_H },
    { "fei", "f", "ei", 6, 169, 8, 0, 3, 0 },
    { "fen", "f", "en", 6, 174, 8, 5575, 3, 0 },
    { "fou", "f", "ou", 6, 501, 8, 0, 3, 0 },
    { "fua", "f", "ua", 6, 673, 8, 0, 3, PINYIN_FUZZY_F_H },
    { "fui", "f", "ui", 6, 681, 8, 0, 3, PINYIN_FUZZY_F_H },
    { "fun", "f", "un", 6, 686, 8, 0, 3, PINYIN_FUZZY_F_H },
    { "fuo", "f", "uo", 6, 687, 8, 0, 3, PINYIN_FUZZY_F_H },
    { 0 },
};

static const PinYin pinyin_f_4[] = {
    { "fagn", "f", "ang", 6, 1479, 8, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "famg", "f", "ang", 6, 1479, 8, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "fang", "f", "ang", 6, 1479, 8, 46, 4, 0 },
    { "fegn", "f", "eng", 6, 5575, 8, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "femg", "f", "eng", 6, 5575, 8, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "feng", "f", "eng", 6, 5575, 8, 174, 4, 0 },
    { "fong", "f", "ong", 6, 15815, 8, 0, 4, PINYIN_FUZZY_F_H },
    { "fuai", "f", "uai", 6, 21545, 8, 0, 4, PINYIN_FUZZY_F_H },
    { "fuan", "f", "uan", 6, 21550, 8, 689607, 4, PINYIN_FUZZY_F_H },
    { 0 },
};

static const PinYin pinyin_f_5[] = {
    { "fuang", "f", "uang", 6, 689607, 8, 21550, 5, PINYIN_FUZZY_F_H },
    { 0 },
};

static const PinYin *pinyin_f[] = {
    0,
    pinyin_f_1,
    pinyin_f_2,
    pinyin_f_3,
    pinyin_f_4,
    pinyin_f_5,
    0,
};

static const PinYin pinyin_g_1[] = {
    { "g", "g", "", 7, 0, 11, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_g_2[] = {
    { "ga", "g", "a", 7, 1, 11, 0, 2, 0 },
    { "ge", "g", "e", 7, 5, 11, 0, 2, 0 },
    { "gu", "g", "u", 7, 21, 11, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_g_3[] = {
    { "gai", "g", "ai", 7, 41, 11, 0, 3, 0 },
    { "gan", "g", "an", 7, 46, 11, 1479, 3, 0 },
    { "gao", "g", "ao", 7, 47, 11, 0, 3, 0 },
    { "gei", "g", "ei", 7, 169, 11, 0, 3, 0 },
    { "gen", "g", "en", 7, 174, 11, 5575, 3, 0 },
    { "gou", "g", "ou", 7, 501, 11, 0, 3, 0 },
    { "gua", "g", "ua", 7, 673, 11, 0, 3, 0 },
    { "gui", "g", "ui", 7, 681, 11, 0, 3, 0 },
    { "gun", "g", "un", 7, 686, 11, 0, 3, 0 },
    { "guo", "g", "uo", 7, 687, 11, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_g_4[] = {
    { "gagn", "g", "ang", 7, 1479, 11, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "gamg", "g", "ang", 7, 1479, 11, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "gang", "g", "ang", 7, 1479, 11, 46, 4, 0 },
    { "gegn", "g", "eng", 7, 5575, 11, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "gemg", "g", "eng", 7, 5575, 11, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "geng", "g", "eng", 7, 5575, 11, 174, 4, 0 },
    { "gogn", "g", "ong", 7, 15815, 11, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "gomg", "g", "ong", 7, 15815, 11, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "gong", "g", "ong", 7, 15815, 11, 0, 4, 0 },
    { "guai", "g", "uai", 7, 21545, 11, 0, 4, 0 },
    { "guan", "g", "uan", 7, 21550, 11, 689607, 4, 0 },
    { "guei", "g", "ui", 7, 681, 11, 0, 4, PINYIN_CORRECT_UEI_TO_UI },
    { "guen", "g", "un", 7, 686, 11, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_g_5[] = {
    { "guagn", "g", "uang", 7, 689607, 11, 21550, 5, PINYIN_CORRECT_GN_TO_NG },
    { "guamg", "g", "uang", 7, 689607, 11, 21550, 5, PINYIN_CORRECT_MG_TO_NG },
    { "guang", "g", "uang", 7, 689607, 11, 21550, 5, 0 },
    { 0 },
};

static const PinYin *pinyin_g[] = {
    0,
    pinyin_g_1,
    pinyin_g_2,
    pinyin_g_3,
    pinyin_g_4,
    pinyin_g_5,
    0,
};

static const PinYin pinyin_h_1[] = {
    { "h", "h", "", 8, 0, 6, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_h_2[] = {
    { "ha", "h", "a", 8, 1, 6, 0, 2, 0 },
    { "he", "h", "e", 8, 5, 6, 0, 2, 0 },
    { "ho", "h", "o", 8, 15, 6, 0, 2, PINYIN_FUZZY_F_H },
    { "hu", "h", "u", 8, 21, 6, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_h_3[] = {
    { "hai", "h", "ai", 8, 41, 6, 0, 3, 0 },
    { "han", "h", "an", 8, 46, 6, 1479, 3, 0 },
    { "hao", "h", "ao", 8, 47, 6, 0, 3, 0 },
    { "hei", "h", "ei", 8, 169, 6, 0, 3, 0 },
    { "hen", "h", "en", 8, 174, 6, 5575, 3, 0 },
    { "hou", "h", "ou", 8, 501, 6, 0, 3, 0 },
    { "hua", "h", "ua", 8, 673, 6, 0, 3, 0 },
    { "hui", "h", "ui", 8, 681, 6, 0, 3, 0 },
    { "hun", "h", "un", 8, 686, 6, 0, 3, 0 },
    { "huo", "h", "uo", 8, 687, 6, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_h_4[] = {
    { "hagn", "h", "ang", 8, 1479, 6, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "hamg", "h", "ang", 8, 1479, 6, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "hang", "h", "ang", 8, 1479, 6, 46, 4, 0 },
    { "hegn", "h", "eng", 8, 5575, 6, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "hemg", "h", "eng", 8, 5575, 6, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "heng", "h", "eng", 8, 5575, 6, 174, 4, 0 },
    { "hogn", "h", "ong", 8, 15815, 6, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "homg", "h", "ong", 8, 15815, 6, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "hong", "h", "ong", 8, 15815, 6, 0, 4, 0 },
    { "huai", "h", "uai", 8, 21545, 6, 0, 4, 0 },
    { "huan", "h", "uan", 8, 21550, 0, 689607, 4, 0 },
    { "huei", "h", "ui", 8, 681, 6, 0, 4, PINYIN_CORRECT_UEI_TO_UI },
    { "huen", "h", "un", 8, 686, 6, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_h_5[] = {
    { "huagn", "h", "uang", 8, 689607, 0, 21550, 5, PINYIN_CORRECT_GN_TO_NG },
    { "huamg", "h", "uang", 8, 689607, 0, 21550, 5, PINYIN_CORRECT_MG_TO_NG },
    { "huang", "h", "uang", 8, 689607, 0, 21550, 5, 0 },
    { 0 },
};

static const PinYin *pinyin_h[] = {
    0,
    pinyin_h_1,
    pinyin_h_2,
    pinyin_h_3,
    pinyin_h_4,
    pinyin_h_5,
    0,
};

static const PinYin pinyin_j_1[] = {
    { "j", "j", "", 10, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_j_2[] = {
    { "ji", "j", "i", 10, 9, 0, 0, 2, 0 },
    { "ju", "j", "u", 10, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_j_3[] = {
    { "jia", "j", "ia", 10, 289, 0, 0, 3, 0 },
    { "jie", "j", "ie", 10, 293, 0, 0, 3, 0 },
    { "jin", "j", "in", 10, 302, 0, 9671, 3, 0 },
    { "jiu", "j", "iu", 10, 309, 0, 0, 3, 0 },
    { "jue", "j", "ue", 10, 677, 0, 0, 3, 0 },
    { "jun", "j", "un", 10, 686, 0, 0, 3, 0 },
    { "jve", "j", "ue", 10, 677, 0, 0, 3, PINYIN_CORRECT_VE_TO_UE },
    { 0 },
};

static const PinYin pinyin_j_4[] = {
    { "jian", "j", "ian", 10, 9262, 0, 0, 4, 0 },
    { "jiao", "j", "iao", 10, 9263, 0, 0, 4, 0 },
    { "jign", "j", "ing", 10, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "jimg", "j", "ing", 10, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "jing", "j", "ing", 10, 9671, 0, 302, 4, 0 },
    { "jiou", "j", "iu", 10, 309, 0, 0, 4, PINYIN_CORRECT_IOU_TO_IU },
    { "juan", "j", "uan", 10, 21550, 0, 689607, 4, 0 },
    { "juen", "j", "un", 10, 686, 0, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_j_5[] = {
    { "jiagn", "j", "iang", 10, 296391, 0, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "jiamg", "j", "iang", 10, 296391, 0, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "jiang", "j", "iang", 10, 296391, 0, 0, 5, 0 },
    { "jiogn", "j", "iong", 10, 310727, 0, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "jiomg", "j", "iong", 10, 310727, 0, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "jiong", "j", "iong", 10, 310727, 0, 0, 5, 0 },
    { "juang", "j", "uang", 10, 689607, 0, 21550, 5, PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin *pinyin_j[] = {
    0,
    pinyin_j_1,
    pinyin_j_2,
    pinyin_j_3,
    pinyin_j_4,
    pinyin_j_5,
    0,
};

static const PinYin pinyin_k_1[] = {
    { "k", "k", "", 11, 0, 7, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_k_2[] = {
    { "ka", "k", "a", 11, 1, 7, 0, 2, 0 },
    { "ke", "k", "e", 11, 5, 7, 0, 2, 0 },
    { "ku", "k", "u", 11, 21, 7, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_k_3[] = {
    { "kai", "k", "ai", 11, 41, 7, 0, 3, 0 },
    { "kan", "k", "an", 11, 46, 7, 1479, 3, 0 },
    { "kao", "k", "ao", 11, 47, 7, 0, 3, 0 },
    { "kei", "k", "ei", 11, 169, 7, 0, 3, PINYIN_FUZZY_K_G },
    { "ken", "k", "en", 11, 174, 7, 5575, 3, 0 },
    { "kou", "k", "ou", 11, 501, 7, 0, 3, 0 },
    { "kua", "k", "ua", 11, 673, 7, 0, 3, 0 },
    { "kui", "k", "ui", 11, 681, 7, 0, 3, 0 },
    { "kun", "k", "un", 11, 686, 7, 0, 3, 0 },
    { "kuo", "k", "uo", 11, 687, 7, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_k_4[] = {
    { "kagn", "k", "ang", 11, 1479, 7, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "kamg", "k", "ang", 11, 1479, 7, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "kang", "k", "ang", 11, 1479, 7, 46, 4, 0 },
    { "kegn", "k", "eng", 11, 5575, 7, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "kemg", "k", "eng", 11, 5575, 7, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "keng", "k", "eng", 11, 5575, 7, 174, 4, 0 },
    { "kogn", "k", "ong", 11, 15815, 7, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "komg", "k", "ong", 11, 15815, 7, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "kong", "k", "ong", 11, 15815, 7, 0, 4, 0 },
    { "kuai", "k", "uai", 11, 21545, 7, 0, 4, 0 },
    { "kuan", "k", "uan", 11, 21550, 7, 689607, 4, 0 },
    { "kuei", "k", "ui", 11, 681, 7, 0, 4, PINYIN_CORRECT_UEI_TO_UI },
    { "kuen", "k", "un", 11, 686, 7, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_k_5[] = {
    { "kuagn", "k", "uang", 11, 689607, 7, 21550, 5, PINYIN_CORRECT_GN_TO_NG },
    { "kuamg", "k", "uang", 11, 689607, 7, 21550, 5, PINYIN_CORRECT_MG_TO_NG },
    { "kuang", "k", "uang", 11, 689607, 7, 21550, 5, 0 },
    { 0 },
};

static const PinYin *pinyin_k[] = {
    0,
    pinyin_k_1,
    pinyin_k_2,
    pinyin_k_3,
    pinyin_k_4,
    pinyin_k_5,
    0,
};

static const PinYin pinyin_l_1[] = {
    { "l", "l", "", 12, 0, 18, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_l_2[] = {
    { "la", "l", "a", 12, 1, 18, 0, 2, 0 },
    { "le", "l", "e", 12, 5, 18, 0, 2, 0 },
    { "li", "l", "i", 12, 9, 18, 0, 2, 0 },
    { "lo", "l", "o", 12, 15, 18, 0, 2, 0 },
    { "lu", "l", "u", 12, 21, 18, 0, 2, 0 },
    { "lv", "l", "v", 12, 22, 18, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_l_3[] = {
    { "lai", "l", "ai", 12, 41, 18, 0, 3, 0 },
    { "lan", "l", "an", 12, 46, 18, 1479, 3, 0 },
    { "lao", "l", "ao", 12, 47, 18, 0, 3, 0 },
    { "lei", "l", "ei", 12, 169, 18, 0, 3, 0 },
    { "len", "l", "en", 12, 174, 18, 5575, 3, PINYIN_FUZZY_L_N | PINYIN_FUZZY_R_L | PINYIN_FUZZY_EN_ENG },
    { "lia", "l", "ia", 12, 289, 18, 0, 3, 0 },
    { "lie", "l", "ie", 12, 293, 18, 0, 3, 0 },
    { "lin", "l", "in", 12, 302, 0, 9671, 3, 0 },
    { "liu", "l", "iu", 12, 309, 18, 0, 3, 0 },
    { "lou", "l", "ou", 12, 501, 18, 0, 3, 0 },
    { "lue", "l", "ue", 12, 677, 18, 0, 3, 0 },
    { "lui", "l", "ui", 12, 681, 18, 0, 3, PINYIN_FUZZY_R_L },
    { "lun", "l", "un", 12, 686, 18, 0, 3, 0 },
    { "luo", "l", "uo", 12, 687, 18, 0, 3, 0 },
    { "lve", "l", "ue", 12, 677, 18, 0, 3, PINYIN_CORRECT_VE_TO_UE },
    { 0 },
};

static const PinYin pinyin_l_4[] = {
    { "lagn", "l", "ang", 12, 1479, 18, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "lamg", "l", "ang", 12, 1479, 18, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "lang", "l", "ang", 12, 1479, 18, 46, 4, 0 },
    { "legn", "l", "eng", 12, 5575, 18, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "lemg", "l", "eng", 12, 5575, 18, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "leng", "l", "eng", 12, 5575, 18, 174, 4, 0 },
    { "lian", "l", "ian", 12, 9262, 18, 0, 4, 0 },
    { "liao", "l", "iao", 12, 9263, 18, 0, 4, 0 },
    { "lign", "l", "ing", 12, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "limg", "l", "ing", 12, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "ling", "l", "ing", 12, 9671, 0, 302, 4, 0 },
    { "liou", "l", "iu", 12, 309, 18, 0, 4, PINYIN_CORRECT_IOU_TO_IU },
    { "logn", "l", "ong", 12, 15815, 18, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "lomg", "l", "ong", 12, 15815, 18, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "long", "l", "ong", 12, 15815, 18, 0, 4, 0 },
    { "luan", "l", "uan", 12, 21550, 18, 0, 4, 0 },
    { "luen", "l", "un", 12, 686, 18, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_l_5[] = {
    { "liagn", "l", "iang", 12, 296391, 18, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "liamg", "l", "iang", 12, 296391, 18, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "liang", "l", "iang", 12, 296391, 18, 0, 5, 0 },
    { "luang", "l", "uang", 12, 689607, 18, 21550, 5, PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin *pinyin_l[] = {
    0,
    pinyin_l_1,
    pinyin_l_2,
    pinyin_l_3,
    pinyin_l_4,
    pinyin_l_5,
    0,
};

static const PinYin pinyin_m_1[] = {
    { "m", "m", "", 13, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_m_2[] = {
    { "ma", "m", "a", 13, 1, 0, 0, 2, 0 },
    { "me", "m", "e", 13, 5, 0, 0, 2, 0 },
    { "mi", "m", "i", 13, 9, 0, 0, 2, 0 },
    { "mo", "m", "o", 13, 15, 0, 0, 2, 0 },
    { "mu", "m", "u", 13, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_m_3[] = {
    { "mai", "m", "ai", 13, 41, 0, 0, 3, 0 },
    { "man", "m", "an", 13, 46, 0, 1479, 3, 0 },
    { "mao", "m", "ao", 13, 47, 0, 0, 3, 0 },
    { "mei", "m", "ei", 13, 169, 0, 0, 3, 0 },
    { "men", "m", "en", 13, 174, 0, 5575, 3, 0 },
    { "mie", "m", "ie", 13, 293, 0, 0, 3, 0 },
    { "min", "m", "in", 13, 302, 0, 9671, 3, 0 },
    { "miu", "m", "iu", 13, 309, 0, 0, 3, 0 },
    { "mou", "m", "ou", 13, 501, 0, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_m_4[] = {
    { "magn", "m", "ang", 13, 1479, 0, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "mamg", "m", "ang", 13, 1479, 0, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "mang", "m", "ang", 13, 1479, 0, 46, 4, 0 },
    { "megn", "m", "eng", 13, 5575, 0, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "memg", "m", "eng", 13, 5575, 0, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "meng", "m", "eng", 13, 5575, 0, 174, 4, 0 },
    { "mian", "m", "ian", 13, 9262, 0, 0, 4, 0 },
    { "miao", "m", "iao", 13, 9263, 0, 0, 4, 0 },
    { "mign", "m", "ing", 13, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "mimg", "m", "ing", 13, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "ming", "m", "ing", 13, 9671, 0, 302, 4, 0 },
    { "miou", "m", "iu", 13, 309, 0, 0, 4, PINYIN_CORRECT_IOU_TO_IU },
    { 0 },
};

static const PinYin *pinyin_m[] = {
    0,
    pinyin_m_1,
    pinyin_m_2,
    pinyin_m_3,
    pinyin_m_4,
    0,
    0,
};

static const PinYin pinyin_n_1[] = {
    { "n", "n", "", 14, 0, 12, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_n_2[] = {
    { "na", "n", "a", 14, 1, 12, 0, 2, 0 },
    { "ne", "n", "e", 14, 5, 12, 0, 2, 0 },
    { "ni", "n", "i", 14, 9, 12, 0, 2, 0 },
    { "no", "n", "o", 14, 15, 12, 0, 2, PINYIN_FUZZY_L_N },
    { "nu", "n", "u", 14, 21, 12, 0, 2, 0 },
    { "nv", "n", "v", 14, 22, 12, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_n_3[] = {
    { "nai", "n", "ai", 14, 41, 12, 0, 3, 0 },
    { "nan", "n", "an", 14, 46, 12, 1479, 3, 0 },
    { "nao", "n", "ao", 14, 47, 12, 0, 3, 0 },
    { "nei", "n", "ei", 14, 169, 12, 0, 3, 0 },
    { "nen", "n", "en", 14, 174, 12, 5575, 3, 0 },
    { "nia", "n", "ia", 14, 289, 12, 0, 3, PINYIN_FUZZY_L_N },
    { "nie", "n", "ie", 14, 293, 12, 0, 3, 0 },
    { "nin", "n", "in", 14, 302, 12, 9671, 3, 0 },
    { "niu", "n", "iu", 14, 309, 12, 0, 3, 0 },
    { "nou", "n", "ou", 14, 501, 12, 0, 3, 0 },
    { "nue", "n", "ue", 14, 677, 12, 0, 3, 0 },
    { "nun", "n", "un", 14, 686, 12, 0, 3, PINYIN_FUZZY_L_N },
    { "nuo", "n", "uo", 14, 687, 12, 0, 3, 0 },
    { "nve", "n", "ue", 14, 677, 12, 0, 3, PINYIN_CORRECT_VE_TO_UE },
    { 0 },
};

static const PinYin pinyin_n_4[] = {
    { "nagn", "n", "ang", 14, 1479, 12, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "namg", "n", "ang", 14, 1479, 12, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "nang", "n", "ang", 14, 1479, 12, 46, 4, 0 },
    { "negn", "n", "eng", 14, 5575, 12, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "nemg", "n", "eng", 14, 5575, 12, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "neng", "n", "eng", 14, 5575, 12, 174, 4, 0 },
    { "nian", "n", "ian", 14, 9262, 12, 0, 4, 0 },
    { "niao", "n", "iao", 14, 9263, 12, 0, 4, 0 },
    { "nign", "n", "ing", 14, 9671, 12, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "nimg", "n", "ing", 14, 9671, 12, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "ning", "n", "ing", 14, 9671, 12, 302, 4, 0 },
    { "niou", "n", "iu", 14, 309, 12, 0, 4, PINYIN_CORRECT_IOU_TO_IU },
    { "nogn", "n", "ong", 14, 15815, 12, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "nomg", "n", "ong", 14, 15815, 12, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "nong", "n", "ong", 14, 15815, 12, 0, 4, 0 },
    { "nuan", "n", "uan", 14, 21550, 12, 0, 4, 0 },
    { 0 },
};

static const PinYin pinyin_n_5[] = {
    { "niagn", "n", "iang", 14, 296391, 12, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "niamg", "n", "iang", 14, 296391, 12, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "niang", "n", "iang", 14, 296391, 12, 0, 5, 0 },
    { "nuang", "n", "uang", 14, 689607, 12, 21550, 5, PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin *pinyin_n[] = {
    0,
    pinyin_n_1,
    pinyin_n_2,
    pinyin_n_3,
    pinyin_n_4,
    pinyin_n_5,
    0,
};

static const PinYin pinyin_o_1[] = {
    { "o", "", "o", 0, 15, 0, 0, 1, 0 },
    { 0 },
};

static const PinYin pinyin_o_2[] = {
    { "ou", "", "ou", 0, 501, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin *pinyin_o[] = {
    0,
    pinyin_o_1,
    pinyin_o_2,
    0,
    0,
    0,
    0,
};

static const PinYin pinyin_p_1[] = {
    { "p", "p", "", 16, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_p_2[] = {
    { "pa", "p", "a", 16, 1, 0, 0, 2, 0 },
    { "pi", "p", "i", 16, 9, 0, 0, 2, 0 },
    { "po", "p", "o", 16, 15, 0, 0, 2, 0 },
    { "pu", "p", "u", 16, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_p_3[] = {
    { "pai", "p", "ai", 16, 41, 0, 0, 3, 0 },
    { "pan", "p", "an", 16, 46, 0, 1479, 3, 0 },
    { "pao", "p", "ao", 16, 47, 0, 0, 3, 0 },
    { "pei", "p", "ei", 16, 169, 0, 0, 3, 0 },
    { "pen", "p", "en", 16, 174, 0, 5575, 3, 0 },
    { "pie", "p", "ie", 16, 293, 0, 0, 3, 0 },
    { "pin", "p", "in", 16, 302, 0, 9671, 3, 0 },
    { "pou", "p", "ou", 16, 501, 0, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_p_4[] = {
    { "pagn", "p", "ang", 16, 1479, 0, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "pamg", "p", "ang", 16, 1479, 0, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "pang", "p", "ang", 16, 1479, 0, 46, 4, 0 },
    { "pegn", "p", "eng", 16, 5575, 0, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "pemg", "p", "eng", 16, 5575, 0, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "peng", "p", "eng", 16, 5575, 0, 174, 4, 0 },
    { "pian", "p", "ian", 16, 9262, 0, 0, 4, 0 },
    { "piao", "p", "iao", 16, 9263, 0, 0, 4, 0 },
    { "pign", "p", "ing", 16, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "pimg", "p", "ing", 16, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "ping", "p", "ing", 16, 9671, 0, 302, 4, 0 },
    { 0 },
};

static const PinYin *pinyin_p[] = {
    0,
    pinyin_p_1,
    pinyin_p_2,
    pinyin_p_3,
    pinyin_p_4,
    0,
    0,
};

static const PinYin pinyin_q_1[] = {
    { "q", "q", "", 17, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_q_2[] = {
    { "qi", "q", "i", 17, 9, 0, 0, 2, 0 },
    { "qu", "q", "u", 17, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_q_3[] = {
    { "qia", "q", "ia", 17, 289, 0, 0, 3, 0 },
    { "qie", "q", "ie", 17, 293, 0, 0, 3, 0 },
    { "qin", "q", "in", 17, 302, 0, 9671, 3, 0 },
    { "qiu", "q", "iu", 17, 309, 0, 0, 3, 0 },
    { "que", "q", "ue", 17, 677, 0, 0, 3, 0 },
    { "qun", "q", "un", 17, 686, 0, 0, 3, 0 },
    { "qve", "q", "ue", 17, 677, 0, 0, 3, PINYIN_CORRECT_VE_TO_UE },
    { 0 },
};

static const PinYin pinyin_q_4[] = {
    { "qian", "q", "ian", 17, 9262, 0, 0, 4, 0 },
    { "qiao", "q", "iao", 17, 9263, 0, 0, 4, 0 },
    { "qign", "q", "ing", 17, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "qimg", "q", "ing", 17, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "qing", "q", "ing", 17, 9671, 0, 302, 4, 0 },
    { "qiou", "q", "iu", 17, 309, 0, 0, 4, PINYIN_CORRECT_IOU_TO_IU },
    { "quan", "q", "uan", 17, 21550, 0, 689607, 4, 0 },
    { "quen", "q", "un", 17, 686, 0, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_q_5[] = {
    { "qiagn", "q", "iang", 17, 296391, 0, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "qiamg", "q", "iang", 17, 296391, 0, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "qiang", "q", "iang", 17, 296391, 0, 0, 5, 0 },
    { "qiogn", "q", "iong", 17, 310727, 0, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "qiomg", "q", "iong", 17, 310727, 0, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "qiong", "q", "iong", 17, 310727, 0, 0, 5, 0 },
    { "quang", "q", "uang", 17, 689607, 0, 21550, 5, PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin *pinyin_q[] = {
    0,
    pinyin_q_1,
    pinyin_q_2,
    pinyin_q_3,
    pinyin_q_4,
    pinyin_q_5,
    0,
};

static const PinYin pinyin_r_1[] = {
    { "r", "r", "", 18, 0, 12, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_r_2[] = {
    { "ra", "r", "a", 18, 1, 12, 0, 2, PINYIN_FUZZY_R_L },
    { "re", "r", "e", 18, 5, 12, 0, 2, 0 },
    { "ri", "r", "i", 18, 9, 12, 0, 2, 0 },
    { "ro", "r", "o", 18, 15, 12, 0, 2, PINYIN_FUZZY_R_L },
    { "ru", "r", "u", 18, 21, 12, 0, 2, 0 },
    { "rv", "r", "v", 18, 22, 12, 0, 2, PINYIN_FUZZY_R_L },
    { 0 },
};

static const PinYin pinyin_r_3[] = {
    { "rai", "r", "ai", 18, 41, 12, 0, 3, PINYIN_FUZZY_R_L },
    { "ran", "r", "an", 18, 46, 12, 1479, 3, 0 },
    { "rao", "r", "ao", 18, 47, 12, 0, 3, 0 },
    { "rei", "r", "ei", 18, 169, 12, 0, 3, PINYIN_FUZZY_R_L },
    { "ren", "r", "en", 18, 174, 12, 5575, 3, 0 },
    { "ria", "r", "ia", 18, 289, 12, 0, 3, PINYIN_FUZZY_R_L },
    { "rie", "r", "ie", 18, 293, 12, 0, 3, PINYIN_FUZZY_R_L },
    { "rin", "r", "in", 18, 302, 12, 9671, 3, PINYIN_FUZZY_R_L },
    { "riu", "r", "iu", 18, 309, 12, 0, 3, PINYIN_FUZZY_R_L },
    { "rou", "r", "ou", 18, 501, 12, 0, 3, 0 },
    { "rue", "r", "ue", 18, 677, 12, 0, 3, PINYIN_FUZZY_R_L },
    { "rui", "r", "ui", 18, 681, 12, 0, 3, 0 },
    { "run", "r", "un", 18, 686, 12, 0, 3, 0 },
    { "ruo", "r", "uo", 18, 687, 12, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_r_4[] = {
    { "ragn", "r", "ang", 18, 1479, 12, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "ramg", "r", "ang", 18, 1479, 12, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "rang", "r", "ang", 18, 1479, 12, 46, 4, 0 },
    { "regn", "r", "eng", 18, 5575, 12, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "remg", "r", "eng", 18, 5575, 12, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "reng", "r", "eng", 18, 5575, 12, 174, 4, 0 },
    { "rian", "r", "ian", 18, 9262, 12, 0, 4, PINYIN_FUZZY_R_L },
    { "riao", "r", "iao", 18, 9263, 12, 0, 4, PINYIN_FUZZY_R_L },
    { "ring", "r", "ing", 18, 9671, 12, 302, 4, PINYIN_FUZZY_R_L },
    { "rogn", "r", "ong", 18, 15815, 12, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "romg", "r", "ong", 18, 15815, 12, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "rong", "r", "ong", 18, 15815, 12, 0, 4, 0 },
    { "ruan", "r", "uan", 18, 21550, 12, 0, 4, 0 },
    { "ruei", "r", "ui", 18, 681, 12, 0, 4, PINYIN_CORRECT_UEI_TO_UI },
    { "ruen", "r", "un", 18, 686, 12, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_r_5[] = {
    { "riang", "r", "iang", 18, 296391, 12, 0, 5, PINYIN_FUZZY_R_L },
    { "ruang", "r", "uang", 18, 689607, 12, 21550, 5, PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin *pinyin_r[] = {
    0,
    pinyin_r_1,
    pinyin_r_2,
    pinyin_r_3,
    pinyin_r_4,
    pinyin_r_5,
    0,
};

static const PinYin pinyin_s_1[] = {
    { "s", "s", "", 19, 0, 616, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_s_2[] = {
    { "sa", "s", "a", 19, 1, 616, 0, 2, 0 },
    { "se", "s", "e", 19, 5, 616, 0, 2, 0 },
    { "sh", "sh", "", 616, 0, 19, 0, 2, PINYIN_SIMPLE_PINYIN },
    { "si", "s", "i", 19, 9, 616, 0, 2, 0 },
    { "su", "s", "u", 19, 21, 616, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_s_3[] = {
    { "sai", "s", "ai", 19, 41, 616, 0, 3, 0 },
    { "san", "s", "an", 19, 46, 616, 1479, 3, 0 },
    { "sao", "s", "ao", 19, 47, 616, 0, 3, 0 },
    { "sei", "s", "ei", 19, 169, 616, 0, 3, PINYIN_FUZZY_S_SH },
    { "sen", "s", "en", 19, 174, 616, 5575, 3, 0 },
    { "sha", "sh", "a", 616, 1, 19, 0, 3, 0 },
    { "she", "sh", "e", 616, 5, 19, 0, 3, 0 },
    { "shi", "sh", "i", 616, 9, 19, 0, 3, 0 },
    { "shu", "sh", "u", 616, 21, 19, 0, 3, 0 },
    { "sou", "s", "ou", 19, 501, 616, 0, 3, 0 },
    { "sua", "s", "ua", 19, 673, 616, 0, 3, PINYIN_FUZZY_S_SH },
    { "sui", "s", "ui", 19, 681, 616, 0, 3, 0 },
    { "sun", "s", "un", 19, 686, 616, 0, 3, 0 },
    { "suo", "s", "uo", 19, 687, 616, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_s_4[] = {
    { "sagn", "s", "ang", 19, 1479, 616, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "samg", "s", "ang", 19, 1479, 616, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "sang", "s", "ang", 19, 1479, 616, 46, 4, 0 },
    { "segn", "s", "eng", 19, 5575, 616, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "semg", "s", "eng", 19, 5575, 616, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "seng", "s", "eng", 19, 5575, 616, 174, 4, 0 },
    { "shai", "sh", "ai", 616, 41, 19, 0, 4, 0 },
    { "shan", "sh", "an", 616, 46, 19, 1479, 4, 0 },
    { "shao", "sh", "ao", 616, 47, 19, 0, 4, 0 },
    { "shei", "sh", "ei", 616, 169, 19, 0, 4, 0 },
    { "shen", "sh", "en", 616, 174, 19, 5575, 4, 0 },
    { "shou", "sh", "ou", 616, 501, 19, 0, 4, 0 },
    { "shua", "sh", "ua", 616, 673, 19, 0, 4, 0 },
    { "shui", "sh", "ui", 616, 681, 19, 0, 4, 0 },
    { "shun", "sh", "un", 616, 686, 19, 0, 4, 0 },
    { "shuo", "sh", "uo", 616, 687, 19, 0, 4, 0 },
    { "sogn", "s", "ong", 19, 15815, 616, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "somg", "s", "ong", 19, 15815, 616, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "song", "s", "ong", 19, 15815, 616, 0, 4, 0 },
    { "suai", "s", "uai", 19, 21545, 616, 0, 4, PINYIN_FUZZY_S_SH },
    { "suan", "s", "uan", 19, 21550, 616, 689607, 4, 0 },
    { "suei", "s", "ui", 19, 681, 616, 0, 4, PINYIN_CORRECT_UEI_TO_UI },
    { "suen", "s", "un", 19, 686, 616, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_s_5[] = {
    { "shagn", "sh", "ang", 616, 1479, 19, 46, 5, PINYIN_CORRECT_GN_TO_NG },
    { "shamg", "sh", "ang", 616, 1479, 19, 46, 5, PINYIN_CORRECT_MG_TO_NG },
    { "shang", "sh", "ang", 616, 1479, 19, 46, 5, 0 },
    { "shegn", "sh", "eng", 616, 5575, 19, 174, 5, PINYIN_CORRECT_GN_TO_NG },
    { "shemg", "sh", "eng", 616, 5575, 19, 174, 5, PINYIN_CORRECT_MG_TO_NG },
    { "sheng", "sh", "eng", 616, 5575, 19, 174, 5, 0 },
    { "shong", "sh", "ong", 616, 15815, 19, 0, 5, PINYIN_FUZZY_S_SH },
    { "shuai", "sh", "uai", 616, 21545, 19, 0, 5, 0 },
    { "shuan", "sh", "uan", 616, 21550, 19, 689607, 5, 0 },
    { "shuei", "sh", "ui", 616, 681, 19, 0, 5, PINYIN_CORRECT_UEI_TO_UI },
    { "shuen", "sh", "un", 616, 686, 19, 0, 5, PINYIN_CORRECT_UEN_TO_UN },
    { "suang", "s", "uang", 19, 689607, 616, 21550, 5, PINYIN_FUZZY_S_SH | PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin pinyin_s_6[] = {
    { "shuagn", "sh", "uang", 616, 689607, 19, 21550, 6, PINYIN_CORRECT_GN_TO_NG },
    { "shuamg", "sh", "uang", 616, 689607, 19, 21550, 6, PINYIN_CORRECT_MG_TO_NG },
    { "shuang", "sh", "uang", 616, 689607, 19, 21550, 6, 0 },
    { 0 },
};

static const PinYin *pinyin_s[] = {
    0,
    pinyin_s_1,
    pinyin_s_2,
    pinyin_s_3,
    pinyin_s_4,
    pinyin_s_5,
    pinyin_s_6,
};

static const PinYin pinyin_t_1[] = {
    { "t", "t", "", 20, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_t_2[] = {
    { "ta", "t", "a", 20, 1, 0, 0, 2, 0 },
    { "te", "t", "e", 20, 5, 0, 0, 2, 0 },
    { "ti", "t", "i", 20, 9, 0, 0, 2, 0 },
    { "tu", "t", "u", 20, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_t_3[] = {
    { "tai", "t", "ai", 20, 41, 0, 0, 3, 0 },
    { "tan", "t", "an", 20, 46, 0, 1479, 3, 0 },
    { "tao", "t", "ao", 20, 47, 0, 0, 3, 0 },
    { "ten", "t", "en", 20, 174, 0, 5575, 3, PINYIN_FUZZY_EN_ENG },
    { "tie", "t", "ie", 20, 293, 0, 0, 3, 0 },
    { "tin", "t", "in", 20, 302, 0, 9671, 3, PINYIN_FUZZY_IN_ING },
    { "tou", "t", "ou", 20, 501, 0, 0, 3, 0 },
    { "tui", "t", "ui", 20, 681, 0, 0, 3, 0 },
    { "tun", "t", "un", 20, 686, 0, 0, 3, 0 },
    { "tuo", "t", "uo", 20, 687, 0, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_t_4[] = {
    { "tagn", "t", "ang", 20, 1479, 0, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "tamg", "t", "ang", 20, 1479, 0, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "tang", "t", "ang", 20, 1479, 0, 46, 4, 0 },
    { "tegn", "t", "eng", 20, 5575, 0, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "temg", "t", "eng", 20, 5575, 0, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "teng", "t", "eng", 20, 5575, 0, 174, 4, 0 },
    { "tian", "t", "ian", 20, 9262, 0, 0, 4, 0 },
    { "tiao", "t", "iao", 20, 9263, 0, 0, 4, 0 },
    { "tign", "t", "ing", 20, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "timg", "t", "ing", 20, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "ting", "t", "ing", 20, 9671, 0, 302, 4, 0 },
    { "togn", "t", "ong", 20, 15815, 0, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "tomg", "t", "ong", 20, 15815, 0, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "tong", "t", "ong", 20, 15815, 0, 0, 4, 0 },
    { "tuan", "t", "uan", 20, 21550, 0, 689607, 4, 0 },
    { "tuei", "t", "ui", 20, 681, 0, 0, 4, PINYIN_CORRECT_UEI_TO_UI },
    { "tuen", "t", "un", 20, 686, 0, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_t_5[] = {
    { "tuang", "t", "uang", 20, 689607, 0, 21550, 5, PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin *pinyin_t[] = {
    0,
    pinyin_t_1,
    pinyin_t_2,
    pinyin_t_3,
    pinyin_t_4,
    pinyin_t_5,
    0,
};

static const PinYin pinyin_w_1[] = {
    { "w", "w", "", 23, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_w_2[] = {
    { "wa", "w", "a", 23, 1, 0, 0, 2, 0 },
    { "wo", "w", "o", 23, 15, 0, 0, 2, 0 },
    { "wu", "w", "u", 23, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_w_3[] = {
    { "wai", "w", "ai", 23, 41, 0, 0, 3, 0 },
    { "wan", "w", "an", 23, 46, 0, 1479, 3, 0 },
    { "wei", "w", "ei", 23, 169, 0, 0, 3, 0 },
    { "wen", "w", "en", 23, 174, 0, 5575, 3, 0 },
    { 0 },
};

static const PinYin pinyin_w_4[] = {
    { "wagn", "w", "ang", 23, 1479, 0, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "wamg", "w", "ang", 23, 1479, 0, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "wang", "w", "ang", 23, 1479, 0, 46, 4, 0 },
    { "wegn", "w", "eng", 23, 5575, 0, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "wemg", "w", "eng", 23, 5575, 0, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "weng", "w", "eng", 23, 5575, 0, 174, 4, 0 },
    { 0 },
};

static const PinYin *pinyin_w[] = {
    0,
    pinyin_w_1,
    pinyin_w_2,
    pinyin_w_3,
    pinyin_w_4,
    0,
    0,
};

static const PinYin pinyin_x_1[] = {
    { "x", "x", "", 24, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_x_2[] = {
    { "xi", "x", "i", 24, 9, 0, 0, 2, 0 },
    { "xu", "x", "u", 24, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_x_3[] = {
    { "xia", "x", "ia", 24, 289, 0, 0, 3, 0 },
    { "xie", "x", "ie", 24, 293, 0, 0, 3, 0 },
    { "xin", "x", "in", 24, 302, 0, 9671, 3, 0 },
    { "xiu", "x", "iu", 24, 309, 0, 0, 3, 0 },
    { "xue", "x", "ue", 24, 677, 0, 0, 3, 0 },
    { "xun", "x", "un", 24, 686, 0, 0, 3, 0 },
    { "xve", "x", "ue", 24, 677, 0, 0, 3, PINYIN_CORRECT_VE_TO_UE },
    { 0 },
};

static const PinYin pinyin_x_4[] = {
    { "xian", "x", "ian", 24, 9262, 0, 0, 4, 0 },
    { "xiao", "x", "iao", 24, 9263, 0, 0, 4, 0 },
    { "xign", "x", "ing", 24, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "ximg", "x", "ing", 24, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "xing", "x", "ing", 24, 9671, 0, 302, 4, 0 },
    { "xiou", "x", "iu", 24, 309, 0, 0, 4, PINYIN_CORRECT_IOU_TO_IU },
    { "xuan", "x", "uan", 24, 21550, 0, 689607, 4, 0 },
    { "xuen", "x", "un", 24, 686, 0, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_x_5[] = {
    { "xiagn", "x", "iang", 24, 296391, 0, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "xiamg", "x", "iang", 24, 296391, 0, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "xiang", "x", "iang", 24, 296391, 0, 0, 5, 0 },
    { "xiogn", "x", "iong", 24, 310727, 0, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "xiomg", "x", "iong", 24, 310727, 0, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "xiong", "x", "iong", 24, 310727, 0, 0, 5, 0 },
    { "xuang", "x", "uang", 24, 689607, 0, 21550, 5, PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin *pinyin_x[] = {
    0,
    pinyin_x_1,
    pinyin_x_2,
    pinyin_x_3,
    pinyin_x_4,
    pinyin_x_5,
    0,
};

static const PinYin pinyin_y_1[] = {
    { "y", "y", "", 25, 0, 0, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_y_2[] = {
    { "ya", "y", "a", 25, 1, 0, 0, 2, 0 },
    { "ye", "y", "e", 25, 5, 0, 0, 2, 0 },
    { "yi", "y", "i", 25, 9, 0, 0, 2, 0 },
    { "yo", "y", "o", 25, 15, 0, 0, 2, 0 },
    { "yu", "y", "u", 25, 21, 0, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_y_3[] = {
    { "yan", "y", "an", 25, 46, 0, 1479, 3, 0 },
    { "yao", "y", "ao", 25, 47, 0, 0, 3, 0 },
    { "yin", "y", "in", 25, 302, 0, 9671, 3, 0 },
    { "you", "y", "ou", 25, 501, 0, 0, 3, 0 },
    { "yue", "y", "ue", 25, 677, 0, 0, 3, 0 },
    { "yun", "y", "un", 25, 686, 0, 0, 3, 0 },
    { "yve", "y", "ue", 25, 677, 0, 0, 3, PINYIN_CORRECT_VE_TO_UE },
    { 0 },
};

static const PinYin pinyin_y_4[] = {
    { "yagn", "y", "ang", 25, 1479, 0, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "yamg", "y", "ang", 25, 1479, 0, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "yang", "y", "ang", 25, 1479, 0, 46, 4, 0 },
    { "yign", "y", "ing", 25, 9671, 0, 302, 4, PINYIN_CORRECT_GN_TO_NG },
    { "yimg", "y", "ing", 25, 9671, 0, 302, 4, PINYIN_CORRECT_MG_TO_NG },
    { "ying", "y", "ing", 25, 9671, 0, 302, 4, 0 },
    { "yogn", "y", "ong", 25, 15815, 0, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "yomg", "y", "ong", 25, 15815, 0, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "yong", "y", "ong", 25, 15815, 0, 0, 4, 0 },
    { "yuan", "y", "uan", 25, 21550, 0, 689607, 4, 0 },
    { "yuen", "y", "un", 25, 686, 0, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_y_5[] = {
    { "yuang", "y", "uang", 25, 689607, 0, 21550, 5, PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin *pinyin_y[] = {
    0,
    pinyin_y_1,
    pinyin_y_2,
    pinyin_y_3,
    pinyin_y_4,
    pinyin_y_5,
    0,
};

static const PinYin pinyin_z_1[] = {
    { "z", "z", "", 26, 0, 840, 0, 1, PINYIN_SIMPLE_PINYIN },
    { 0 },
};

static const PinYin pinyin_z_2[] = {
    { "za", "z", "a", 26, 1, 840, 0, 2, 0 },
    { "ze", "z", "e", 26, 5, 840, 0, 2, 0 },
    { "zh", "zh", "", 840, 0, 26, 0, 2, PINYIN_SIMPLE_PINYIN },
    { "zi", "z", "i", 26, 9, 840, 0, 2, 0 },
    { "zu", "z", "u", 26, 21, 840, 0, 2, 0 },
    { 0 },
};

static const PinYin pinyin_z_3[] = {
    { "zai", "z", "ai", 26, 41, 840, 0, 3, 0 },
    { "zan", "z", "an", 26, 46, 840, 1479, 3, 0 },
    { "zao", "z", "ao", 26, 47, 840, 0, 3, 0 },
    { "zei", "z", "ei", 26, 169, 840, 0, 3, 0 },
    { "zen", "z", "en", 26, 174, 840, 5575, 3, 0 },
    { "zha", "zh", "a", 840, 1, 26, 0, 3, 0 },
    { "zhe", "zh", "e", 840, 5, 26, 0, 3, 0 },
    { "zhi", "zh", "i", 840, 9, 26, 0, 3, 0 },
    { "zhu", "zh", "u", 840, 21, 26, 0, 3, 0 },
    { "zou", "z", "ou", 26, 501, 840, 0, 3, 0 },
    { "zua", "z", "ua", 26, 673, 840, 0, 3, PINYIN_FUZZY_Z_ZH },
    { "zui", "z", "ui", 26, 681, 840, 0, 3, 0 },
    { "zun", "z", "un", 26, 686, 840, 0, 3, 0 },
    { "zuo", "z", "uo", 26, 687, 840, 0, 3, 0 },
    { 0 },
};

static const PinYin pinyin_z_4[] = {
    { "zagn", "z", "ang", 26, 1479, 840, 46, 4, PINYIN_CORRECT_GN_TO_NG },
    { "zamg", "z", "ang", 26, 1479, 840, 46, 4, PINYIN_CORRECT_MG_TO_NG },
    { "zang", "z", "ang", 26, 1479, 840, 46, 4, 0 },
    { "zegn", "z", "eng", 26, 5575, 840, 174, 4, PINYIN_CORRECT_GN_TO_NG },
    { "zemg", "z", "eng", 26, 5575, 840, 174, 4, PINYIN_CORRECT_MG_TO_NG },
    { "zeng", "z", "eng", 26, 5575, 840, 174, 4, 0 },
    { "zhai", "zh", "ai", 840, 41, 26, 0, 4, 0 },
    { "zhan", "zh", "an", 840, 46, 26, 1479, 4, 0 },
    { "zhao", "zh", "ao", 840, 47, 26, 0, 4, 0 },
    { "zhei", "zh", "ei", 840, 169, 26, 0, 4, PINYIN_FUZZY_Z_ZH },
    { "zhen", "zh", "en", 840, 174, 26, 5575, 4, 0 },
    { "zhou", "zh", "ou", 840, 501, 26, 0, 4, 0 },
    { "zhua", "zh", "ua", 840, 673, 26, 0, 4, 0 },
    { "zhui", "zh", "ui", 840, 681, 26, 0, 4, 0 },
    { "zhun", "zh", "un", 840, 686, 26, 0, 4, 0 },
    { "zhuo", "zh", "uo", 840, 687, 26, 0, 4, 0 },
    { "zogn", "z", "ong", 26, 15815, 840, 0, 4, PINYIN_CORRECT_GN_TO_NG },
    { "zomg", "z", "ong", 26, 15815, 840, 0, 4, PINYIN_CORRECT_MG_TO_NG },
    { "zong", "z", "ong", 26, 15815, 840, 0, 4, 0 },
    { "zuai", "z", "uai", 26, 21545, 840, 0, 4, PINYIN_FUZZY_Z_ZH },
    { "zuan", "z", "uan", 26, 21550, 840, 689607, 4, 0 },
    { "zuei", "z", "ui", 26, 681, 840, 0, 4, PINYIN_CORRECT_UEI_TO_UI },
    { "zuen", "z", "un", 26, 686, 840, 0, 4, PINYIN_CORRECT_UEN_TO_UN },
    { 0 },
};

static const PinYin pinyin_z_5[] = {
    { "zhagn", "zh", "ang", 840, 1479, 26, 46, 5, PINYIN_CORRECT_GN_TO_NG },
    { "zhamg", "zh", "ang", 840, 1479, 26, 46, 5, PINYIN_CORRECT_MG_TO_NG },
    { "zhang", "zh", "ang", 840, 1479, 26, 46, 5, 0 },
    { "zhegn", "zh", "eng", 840, 5575, 26, 174, 5, PINYIN_CORRECT_GN_TO_NG },
    { "zhemg", "zh", "eng", 840, 5575, 26, 174, 5, PINYIN_CORRECT_MG_TO_NG },
    { "zheng", "zh", "eng", 840, 5575, 26, 174, 5, 0 },
    { "zhogn", "zh", "ong", 840, 15815, 26, 0, 5, PINYIN_CORRECT_GN_TO_NG },
    { "zhomg", "zh", "ong", 840, 15815, 26, 0, 5, PINYIN_CORRECT_MG_TO_NG },
    { "zhong", "zh", "ong", 840, 15815, 26, 0, 5, 0 },
    { "zhuai", "zh", "uai", 840, 21545, 26, 0, 5, 0 },
    { "zhuan", "zh", "uan", 840, 21550, 26, 689607, 5, 0 },
    { "zhuei", "zh", "ui", 840, 681, 26, 0, 5, PINYIN_CORRECT_UEI_TO_UI },
    { "zhuen", "zh", "un", 840, 686, 26, 0, 5, PINYIN_CORRECT_UEN_TO_UN },
    { "zuang", "z", "uang", 26, 689607, 840, 21550, 5, PINYIN_FUZZY_Z_ZH | PINYIN_FUZZY_UAN_UANG },
    { 0 },
};

static const PinYin pinyin_z_6[] = {
    { "zhuagn", "zh", "uang", 840, 689607, 26, 21550, 6, PINYIN_CORRECT_GN_TO_NG },
    { "zhuamg", "zh", "uang", 840, 689607, 26, 21550, 6, PINYIN_CORRECT_MG_TO_NG },
    { "zhuang", "zh", "uang", 840, 689607, 26, 21550, 6, 0 },
    { 0 },
};

static const PinYin *pinyin_z[] = {
    0,
    pinyin_z_1,
    pinyin_z_2,
    pinyin_z_3,
    pinyin_z_4,
    pinyin_z_5,
    pinyin_z_6,
};

static const PinYin **pinyin_table[] = {
    pinyin_a,
    pinyin_b,
    pinyin_c,
    pinyin_d,
    pinyin_e,
    pinyin_f,
    pinyin_g,
    pinyin_h,
    0,
    pinyin_j,
    pinyin_k,
    pinyin_l,
    pinyin_m,
    pinyin_n,
    pinyin_o,
    pinyin_p,
    pinyin_q,
    pinyin_r,
    pinyin_s,
    pinyin_t,
    0,
    0,
    pinyin_w,
    pinyin_x,
    pinyin_y,
    pinyin_z,
};

