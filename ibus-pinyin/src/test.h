

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

// ('an', 'a', 'a', 'na')
// ('an', 'ai', 'a', 'nai')
// ('an', 'ei', 'a', 'nei')
// ('an', 'eng', 'a', 'neng')
// ('an', 'i', 'a', 'ni')
// ('an', 'ia', 'a', 'nia')
// ('an', 'ian', 'a', 'nian')
// ('an', 'iang', 'a', 'niang')
// ('an', 'iao', 'a', 'niao')
// ('an', 'ie', 'a', 'nie')
// ('an', 'in', 'a', 'nin')
// ('an', 'ing', 'a', 'ning')
// ('an', 'iong', 'a', 'niong')
// ('an', 'iu', 'a', 'niu')
// ('an', 'ong', 'a', 'nong')
// ('an', 'u', 'a', 'nu')
// ('an', 'ua', 'a', 'nua')
// ('an', 'uai', 'a', 'nuai')
// ('an', 'uan', 'a', 'nuan')
// ('an', 'uang', 'a', 'nuang')
// ('an', 'ue', 'a', 'nue')
// ('an', 'ui', 'a', 'nui')
// ('an', 'un', 'a', 'nun')
// ('an', 'uo', 'a', 'nuo')
// ('an', 'v', 'a', 'nv')
// ('ang', 'a', 'an', 'ga')
// ('ang', 'ai', 'an', 'gai')
// ('ang', 'an', 'an', 'gan')
// ('ang', 'ang', 'an', 'gang')
// ('ang', 'ao', 'an', 'gao')
// ('ang', 'e', 'an', 'ge')
// ('ang', 'ei', 'an', 'gei')
// ('ang', 'en', 'an', 'gen')
// ('ang', 'eng', 'an', 'geng')
// ('ang', 'i', 'an', 'gi')
// ('ang', 'ia', 'an', 'gia')
// ('ang', 'ian', 'an', 'gian')
// ('ang', 'iang', 'an', 'giang')
// ('ang', 'iao', 'an', 'giao')
// ('ang', 'ie', 'an', 'gie')
// ('ang', 'in', 'an', 'gin')
// ('ang', 'ing', 'an', 'ging')
// ('ang', 'iong', 'an', 'giong')
// ('ang', 'iu', 'an', 'giu')
// ('ang', 'ong', 'an', 'gong')
// ('ang', 'ou', 'an', 'gou')
// ('ang', 'u', 'an', 'gu')
// ('ang', 'ua', 'an', 'gua')
// ('ang', 'uai', 'an', 'guai')
// ('ang', 'uan', 'an', 'guan')
// ('ang', 'uang', 'an', 'guang')
// ('ang', 'ue', 'an', 'gue')
// ('ang', 'ui', 'an', 'gui')
// ('ang', 'un', 'an', 'gun')
// ('ang', 'uo', 'an', 'guo')
// ('ang', 'v', 'an', 'gv')
// ('ban', 'a', 'ba', 'na')
// ('ban', 'ei', 'ba', 'nei')
// ('ban', 'eng', 'ba', 'neng')
// ('ban', 'i', 'ba', 'ni')
// ('ban', 'ia', 'ba', 'nia')
// ('ban', 'ian', 'ba', 'nian')
// ('ban', 'iang', 'ba', 'niang')
// ('ban', 'iao', 'ba', 'niao')
// ('ban', 'ie', 'ba', 'nie')
// ('ban', 'in', 'ba', 'nin')
// ('ban', 'ing', 'ba', 'ning')
// ('ban', 'iong', 'ba', 'niong')
// ('ban', 'iu', 'ba', 'niu')
// ('ban', 'ong', 'ba', 'nong')
// ('ban', 'u', 'ba', 'nu')
// ('ban', 'ua', 'ba', 'nua')
// ('ban', 'uai', 'ba', 'nuai')
// ('ban', 'uan', 'ba', 'nuan')
// ('ban', 'uang', 'ba', 'nuang')
// ('ban', 'ue', 'ba', 'nue')
// ('ban', 'ui', 'ba', 'nui')
// ('ban', 'un', 'ba', 'nun')
// ('ban', 'uo', 'ba', 'nuo')
// ('ban', 'v', 'ba', 'nv')
// ('bang', 'ai', 'ban', 'gai')
// ('bang', 'ang', 'ban', 'gang')
// ('bang', 'ao', 'ban', 'gao')
// ('bang', 'e', 'ban', 'ge')
// ('bang', 'ei', 'ban', 'gei')
// ('bang', 'en', 'ban', 'gen')
// ('bang', 'eng', 'ban', 'geng')
// ('bang', 'i', 'ban', 'gi')
// ('bang', 'ia', 'ban', 'gia')
// ('bang', 'ian', 'ban', 'gian')
// ('bang', 'iang', 'ban', 'giang')
// ('bang', 'iao', 'ban', 'giao')
// ('bang', 'ie', 'ban', 'gie')
// ('bang', 'in', 'ban', 'gin')
// ('bang', 'ing', 'ban', 'ging')
// ('bang', 'iong', 'ban', 'giong')
// ('bang', 'iu', 'ban', 'giu')
// ('bang', 'ong', 'ban', 'gong')
// ('bang', 'u', 'ban', 'gu')
// ('bang', 'ua', 'ban', 'gua')
// ('bang', 'uai', 'ban', 'guai')
// ('bang', 'uan', 'ban', 'guan')
// ('bang', 'uang', 'ban', 'guang')
// ('bang', 'ue', 'ban', 'gue')
// ('bang', 'ui', 'ban', 'gui')
// ('bang', 'un', 'ban', 'gun')
// ('bang', 'uo', 'ban', 'guo')
// ('bang', 'v', 'ban', 'gv')
// ('ben', 'eng', 'be', 'neng')
// ('ben', 'i', 'be', 'ni')
// ('ben', 'ia', 'be', 'nia')
// ('ben', 'ian', 'be', 'nian')
// ('ben', 'iang', 'be', 'niang')
// ('ben', 'iao', 'be', 'niao')
// ('ben', 'ie', 'be', 'nie')
// ('ben', 'in', 'be', 'nin')
// ('ben', 'ing', 'be', 'ning')
// ('ben', 'iong', 'be', 'niong')
// ('ben', 'iu', 'be', 'niu')
// ('ben', 'ong', 'be', 'nong')
// ('ben', 'u', 'be', 'nu')
// ('ben', 'ua', 'be', 'nua')
// ('ben', 'uai', 'be', 'nuai')
// ('ben', 'uan', 'be', 'nuan')
// ('ben', 'uang', 'be', 'nuang')
// ('ben', 'ue', 'be', 'nue')
// ('ben', 'ui', 'be', 'nui')
// ('ben', 'un', 'be', 'nun')
// ('ben', 'uo', 'be', 'nuo')
// ('ben', 'v', 'be', 'nv')
// ('beng', 'a', 'ben', 'ga')
// ('beng', 'ai', 'ben', 'gai')
// ('beng', 'an', 'ben', 'gan')
// ('beng', 'ang', 'ben', 'gang')
// ('beng', 'ao', 'ben', 'gao')
// ('beng', 'e', 'ben', 'ge')
// ('beng', 'ei', 'ben', 'gei')
// ('beng', 'en', 'ben', 'gen')
// ('beng', 'eng', 'ben', 'geng')
// ('beng', 'i', 'ben', 'gi')
// ('beng', 'ia', 'ben', 'gia')
// ('beng', 'ian', 'ben', 'gian')
// ('beng', 'iang', 'ben', 'giang')
// ('beng', 'iao', 'ben', 'giao')
// ('beng', 'ie', 'ben', 'gie')
// ('beng', 'in', 'ben', 'gin')
// ('beng', 'ing', 'ben', 'ging')
// ('beng', 'iong', 'ben', 'giong')
// ('beng', 'iu', 'ben', 'giu')
// ('beng', 'ong', 'ben', 'gong')
// ('beng', 'ou', 'ben', 'gou')
// ('beng', 'u', 'ben', 'gu')
// ('beng', 'ua', 'ben', 'gua')
// ('beng', 'uai', 'ben', 'guai')
// ('beng', 'uan', 'ben', 'guan')
// ('beng', 'uang', 'ben', 'guang')
// ('beng', 'ue', 'ben', 'gue')
// ('beng', 'ui', 'ben', 'gui')
// ('beng', 'un', 'ben', 'gun')
// ('beng', 'uo', 'ben', 'guo')
// ('beng', 'v', 'ben', 'gv')
// ('bian', 'eng', 'bia', 'neng')
// ('bian', 'i', 'bia', 'ni')
// ('bian', 'ia', 'bia', 'nia')
// ('bian', 'ian', 'bia', 'nian')
// ('bian', 'iang', 'bia', 'niang')
// ('bian', 'iao', 'bia', 'niao')
// ('bian', 'ie', 'bia', 'nie')
// ('bian', 'in', 'bia', 'nin')
// ('bian', 'ing', 'bia', 'ning')
// ('bian', 'iong', 'bia', 'niong')
// ('bian', 'iu', 'bia', 'niu')
// ('bian', 'ong', 'bia', 'nong')
// ('bian', 'u', 'bia', 'nu')
// ('bian', 'ua', 'bia', 'nua')
// ('bian', 'uai', 'bia', 'nuai')
// ('bian', 'uan', 'bia', 'nuan')
// ('bian', 'uang', 'bia', 'nuang')
// ('bian', 'ue', 'bia', 'nue')
// ('bian', 'ui', 'bia', 'nui')
// ('bian', 'un', 'bia', 'nun')
// ('bian', 'uo', 'bia', 'nuo')
// ('bian', 'v', 'bia', 'nv')
// ('bin', 'a', 'bi', 'na')
// ('bin', 'ai', 'bi', 'nai')
// ('bin', 'an', 'bi', 'nan')
// ('bin', 'ao', 'bi', 'nao')
// ('bin', 'e', 'bi', 'ne')
// ('bin', 'ei', 'bi', 'nei')
// ('bin', 'eng', 'bi', 'neng')
// ('bin', 'i', 'bi', 'ni')
// ('bin', 'ia', 'bi', 'nia')
// ('bin', 'ian', 'bi', 'nian')
// ('bin', 'iang', 'bi', 'niang')
// ('bin', 'iao', 'bi', 'niao')
// ('bin', 'ie', 'bi', 'nie')
// ('bin', 'in', 'bi', 'nin')
// ('bin', 'ing', 'bi', 'ning')
// ('bin', 'iong', 'bi', 'niong')
// ('bin', 'iu', 'bi', 'niu')
// ('bin', 'ong', 'bi', 'nong')
// ('bin', 'u', 'bi', 'nu')
// ('bin', 'ua', 'bi', 'nua')
// ('bin', 'uai', 'bi', 'nuai')
// ('bin', 'uan', 'bi', 'nuan')
// ('bin', 'uang', 'bi', 'nuang')
// ('bin', 'ue', 'bi', 'nue')
// ('bin', 'ui', 'bi', 'nui')
// ('bin', 'un', 'bi', 'nun')
// ('bin', 'uo', 'bi', 'nuo')
// ('bin', 'v', 'bi', 'nv')
// ('bing', 'ang', 'bin', 'gang')
// ('bing', 'e', 'bin', 'ge')
// ('bing', 'ei', 'bin', 'gei')
// ('bing', 'en', 'bin', 'gen')
// ('bing', 'eng', 'bin', 'geng')
// ('bing', 'i', 'bin', 'gi')
// ('bing', 'ia', 'bin', 'gia')
// ('bing', 'ian', 'bin', 'gian')
// ('bing', 'iang', 'bin', 'giang')
// ('bing', 'iao', 'bin', 'giao')
// ('bing', 'ie', 'bin', 'gie')
// ('bing', 'in', 'bin', 'gin')
// ('bing', 'ing', 'bin', 'ging')
// ('bing', 'iong', 'bin', 'giong')
// ('bing', 'iu', 'bin', 'giu')
// ('bing', 'ong', 'bin', 'gong')
// ('bing', 'u', 'bin', 'gu')
// ('bing', 'ua', 'bin', 'gua')
// ('bing', 'uai', 'bin', 'guai')
// ('bing', 'uan', 'bin', 'guan')
// ('bing', 'uang', 'bin', 'guang')
// ('bing', 'ue', 'bin', 'gue')
// ('bing', 'ui', 'bin', 'gui')
// ('bing', 'un', 'bin', 'gun')
// ('bing', 'uo', 'bin', 'guo')
// ('bing', 'v', 'bin', 'gv')
// ('can', 'ei', 'ca', 'nei')
// ('can', 'eng', 'ca', 'neng')
// ('can', 'i', 'ca', 'ni')
// ('can', 'ia', 'ca', 'nia')
// ('can', 'ian', 'ca', 'nian')
// ('can', 'iang', 'ca', 'niang')
// ('can', 'iao', 'ca', 'niao')
// ('can', 'ie', 'ca', 'nie')
// ('can', 'in', 'ca', 'nin')
// ('can', 'ing', 'ca', 'ning')
// ('can', 'iong', 'ca', 'niong')
// ('can', 'iu', 'ca', 'niu')
// ('can', 'ong', 'ca', 'nong')
// ('can', 'u', 'ca', 'nu')
// ('can', 'ua', 'ca', 'nua')
// ('can', 'uai', 'ca', 'nuai')
// ('can', 'uan', 'ca', 'nuan')
// ('can', 'uang', 'ca', 'nuang')
// ('can', 'ue', 'ca', 'nue')
// ('can', 'ui', 'ca', 'nui')
// ('can', 'un', 'ca', 'nun')
// ('can', 'uo', 'ca', 'nuo')
// ('can', 'v', 'ca', 'nv')
// ('cang', 'a', 'can', 'ga')
// ('cang', 'an', 'can', 'gan')
// ('cang', 'ang', 'can', 'gang')
// ('cang', 'e', 'can', 'ge')
// ('cang', 'ei', 'can', 'gei')
// ('cang', 'en', 'can', 'gen')
// ('cang', 'eng', 'can', 'geng')
// ('cang', 'i', 'can', 'gi')
// ('cang', 'ia', 'can', 'gia')
// ('cang', 'ian', 'can', 'gian')
// ('cang', 'iang', 'can', 'giang')
// ('cang', 'iao', 'can', 'giao')
// ('cang', 'ie', 'can', 'gie')
// ('cang', 'in', 'can', 'gin')
// ('cang', 'ing', 'can', 'ging')
// ('cang', 'iong', 'can', 'giong')
// ('cang', 'iu', 'can', 'giu')
// ('cang', 'ong', 'can', 'gong')
// ('cang', 'ou', 'can', 'gou')
// ('cang', 'u', 'can', 'gu')
// ('cang', 'ua', 'can', 'gua')
// ('cang', 'uai', 'can', 'guai')
// ('cang', 'uan', 'can', 'guan')
// ('cang', 'uang', 'can', 'guang')
// ('cang', 'ue', 'can', 'gue')
// ('cang', 'ui', 'can', 'gui')
// ('cang', 'un', 'can', 'gun')
// ('cang', 'uo', 'can', 'guo')
// ('cang', 'v', 'can', 'gv')
// ('cen', 'a', 'ce', 'na')
// ('cen', 'ai', 'ce', 'nai')
// ('cen', 'an', 'ce', 'nan')
// ('cen', 'ang', 'ce', 'nang')
// ('cen', 'ao', 'ce', 'nao')
// ('cen', 'e', 'ce', 'ne')
// ('cen', 'ei', 'ce', 'nei')
// ('cen', 'en', 'ce', 'nen')
// ('cen', 'eng', 'ce', 'neng')
// ('cen', 'i', 'ce', 'ni')
// ('cen', 'ia', 'ce', 'nia')
// ('cen', 'ian', 'ce', 'nian')
// ('cen', 'iang', 'ce', 'niang')
// ('cen', 'iao', 'ce', 'niao')
// ('cen', 'ie', 'ce', 'nie')
// ('cen', 'in', 'ce', 'nin')
// ('cen', 'ing', 'ce', 'ning')
// ('cen', 'iong', 'ce', 'niong')
// ('cen', 'iu', 'ce', 'niu')
// ('cen', 'ong', 'ce', 'nong')
// ('cen', 'u', 'ce', 'nu')
// ('cen', 'ua', 'ce', 'nua')
// ('cen', 'uai', 'ce', 'nuai')
// ('cen', 'uan', 'ce', 'nuan')
// ('cen', 'uang', 'ce', 'nuang')
// ('cen', 'ue', 'ce', 'nue')
// ('cen', 'ui', 'ce', 'nui')
// ('cen', 'un', 'ce', 'nun')
// ('cen', 'uo', 'ce', 'nuo')
// ('cen', 'v', 'ce', 'nv')
// ('ceng', 'ei', 'cen', 'gei')
// ('ceng', 'eng', 'cen', 'geng')
// ('ceng', 'i', 'cen', 'gi')
// ('ceng', 'ia', 'cen', 'gia')
// ('ceng', 'ian', 'cen', 'gian')
// ('ceng', 'iang', 'cen', 'giang')
// ('ceng', 'iao', 'cen', 'giao')
// ('ceng', 'ie', 'cen', 'gie')
// ('ceng', 'in', 'cen', 'gin')
// ('ceng', 'ing', 'cen', 'ging')
// ('ceng', 'iong', 'cen', 'giong')
// ('ceng', 'iu', 'cen', 'giu')
// ('ceng', 'ong', 'cen', 'gong')
// ('ceng', 'u', 'cen', 'gu')
// ('ceng', 'ua', 'cen', 'gua')
// ('ceng', 'uai', 'cen', 'guai')
// ('ceng', 'uan', 'cen', 'guan')
// ('ceng', 'uang', 'cen', 'guang')
// ('ceng', 'ue', 'cen', 'gue')
// ('ceng', 'ui', 'cen', 'gui')
// ('ceng', 'un', 'cen', 'gun')
// ('ceng', 'uo', 'cen', 'guo')
// ('ceng', 'v', 'cen', 'gv')
// ('chan', 'a', 'cha', 'na')
// ('chan', 'ei', 'cha', 'nei')
// ('chan', 'eng', 'cha', 'neng')
// ('chan', 'i', 'cha', 'ni')
// ('chan', 'ia', 'cha', 'nia')
// ('chan', 'ian', 'cha', 'nian')
// ('chan', 'iang', 'cha', 'niang')
// ('chan', 'iao', 'cha', 'niao')
// ('chan', 'ie', 'cha', 'nie')
// ('chan', 'in', 'cha', 'nin')
// ('chan', 'ing', 'cha', 'ning')
// ('chan', 'iong', 'cha', 'niong')
// ('chan', 'iu', 'cha', 'niu')
// ('chan', 'ong', 'cha', 'nong')
// ('chan', 'u', 'cha', 'nu')
// ('chan', 'ua', 'cha', 'nua')
// ('chan', 'uai', 'cha', 'nuai')
// ('chan', 'uan', 'cha', 'nuan')
// ('chan', 'uang', 'cha', 'nuang')
// ('chan', 'ue', 'cha', 'nue')
// ('chan', 'ui', 'cha', 'nui')
// ('chan', 'un', 'cha', 'nun')
// ('chan', 'uo', 'cha', 'nuo')
// ('chan', 'v', 'cha', 'nv')
// ('chang', 'ang', 'chan', 'gang')
// ('chang', 'ao', 'chan', 'gao')
// ('chang', 'ei', 'chan', 'gei')
// ('chang', 'en', 'chan', 'gen')
// ('chang', 'eng', 'chan', 'geng')
// ('chang', 'i', 'chan', 'gi')
// ('chang', 'ia', 'chan', 'gia')
// ('chang', 'ian', 'chan', 'gian')
// ('chang', 'iang', 'chan', 'giang')
// ('chang', 'iao', 'chan', 'giao')
// ('chang', 'ie', 'chan', 'gie')
// ('chang', 'in', 'chan', 'gin')
// ('chang', 'ing', 'chan', 'ging')
// ('chang', 'iong', 'chan', 'giong')
// ('chang', 'iu', 'chan', 'giu')
// ('chang', 'ong', 'chan', 'gong')
// ('chang', 'ou', 'chan', 'gou')
// ('chang', 'u', 'chan', 'gu')
// ('chang', 'ua', 'chan', 'gua')
// ('chang', 'uai', 'chan', 'guai')
// ('chang', 'uan', 'chan', 'guan')
// ('chang', 'uang', 'chan', 'guang')
// ('chang', 'ue', 'chan', 'gue')
// ('chang', 'ui', 'chan', 'gui')
// ('chang', 'un', 'chan', 'gun')
// ('chang', 'uo', 'chan', 'guo')
// ('chang', 'v', 'chan', 'gv')
// ('chen', 'a', 'che', 'na')
// ('chen', 'an', 'che', 'nan')
// ('chen', 'e', 'che', 'ne')
// ('chen', 'ei', 'che', 'nei')
// ('chen', 'eng', 'che', 'neng')
// ('chen', 'i', 'che', 'ni')
// ('chen', 'ia', 'che', 'nia')
// ('chen', 'ian', 'che', 'nian')
// ('chen', 'iang', 'che', 'niang')
// ('chen', 'iao', 'che', 'niao')
// ('chen', 'ie', 'che', 'nie')
// ('chen', 'in', 'che', 'nin')
// ('chen', 'ing', 'che', 'ning')
// ('chen', 'iong', 'che', 'niong')
// ('chen', 'iu', 'che', 'niu')
// ('chen', 'ong', 'che', 'nong')
// ('chen', 'u', 'che', 'nu')
// ('chen', 'ua', 'che', 'nua')
// ('chen', 'uai', 'che', 'nuai')
// ('chen', 'uan', 'che', 'nuan')
// ('chen', 'uang', 'che', 'nuang')
// ('chen', 'ue', 'che', 'nue')
// ('chen', 'ui', 'che', 'nui')
// ('chen', 'un', 'che', 'nun')
// ('chen', 'uo', 'che', 'nuo')
// ('chen', 'v', 'che', 'nv')
// ('cheng', 'ang', 'chen', 'gang')
// ('cheng', 'ei', 'chen', 'gei')
// ('cheng', 'eng', 'chen', 'geng')
// ('cheng', 'i', 'chen', 'gi')
// ('cheng', 'ia', 'chen', 'gia')
// ('cheng', 'ian', 'chen', 'gian')
// ('cheng', 'iang', 'chen', 'giang')
// ('cheng', 'iao', 'chen', 'giao')
// ('cheng', 'ie', 'chen', 'gie')
// ('cheng', 'in', 'chen', 'gin')
// ('cheng', 'ing', 'chen', 'ging')
// ('cheng', 'iong', 'chen', 'giong')
// ('cheng', 'iu', 'chen', 'giu')
// ('cheng', 'ong', 'chen', 'gong')
// ('cheng', 'ou', 'chen', 'gou')
// ('cheng', 'u', 'chen', 'gu')
// ('cheng', 'ua', 'chen', 'gua')
// ('cheng', 'uai', 'chen', 'guai')
// ('cheng', 'uan', 'chen', 'guan')
// ('cheng', 'uang', 'chen', 'guang')
// ('cheng', 'ue', 'chen', 'gue')
// ('cheng', 'ui', 'chen', 'gui')
// ('cheng', 'un', 'chen', 'gun')
// ('cheng', 'uo', 'chen', 'guo')
// ('cheng', 'v', 'chen', 'gv')
// ('chong', 'eng', 'chon', 'geng')
// ('chong', 'i', 'chon', 'gi')
// ('chong', 'ia', 'chon', 'gia')
// ('chong', 'ian', 'chon', 'gian')
// ('chong', 'iang', 'chon', 'giang')
// ('chong', 'iao', 'chon', 'giao')
// ('chong', 'ie', 'chon', 'gie')
// ('chong', 'in', 'chon', 'gin')
// ('chong', 'ing', 'chon', 'ging')
// ('chong', 'iong', 'chon', 'giong')
// ('chong', 'iu', 'chon', 'giu')
// ('chong', 'ong', 'chon', 'gong')
// ('chong', 'u', 'chon', 'gu')
// ('chong', 'ua', 'chon', 'gua')
// ('chong', 'uai', 'chon', 'guai')
// ('chong', 'uan', 'chon', 'guan')
// ('chong', 'uang', 'chon', 'guang')
// ('chong', 'ue', 'chon', 'gue')
// ('chong', 'ui', 'chon', 'gui')
// ('chong', 'un', 'chon', 'gun')
// ('chong', 'uo', 'chon', 'guo')
// ('chong', 'v', 'chon', 'gv')
// ('chuan', 'eng', 'chua', 'neng')
// ('chuan', 'i', 'chua', 'ni')
// ('chuan', 'ia', 'chua', 'nia')
// ('chuan', 'ian', 'chua', 'nian')
// ('chuan', 'iang', 'chua', 'niang')
// ('chuan', 'iao', 'chua', 'niao')
// ('chuan', 'ie', 'chua', 'nie')
// ('chuan', 'in', 'chua', 'nin')
// ('chuan', 'ing', 'chua', 'ning')
// ('chuan', 'iong', 'chua', 'niong')
// ('chuan', 'iu', 'chua', 'niu')
// ('chuan', 'ong', 'chua', 'nong')
// ('chuan', 'u', 'chua', 'nu')
// ('chuan', 'ua', 'chua', 'nua')
// ('chuan', 'uai', 'chua', 'nuai')
// ('chuan', 'uan', 'chua', 'nuan')
// ('chuan', 'uang', 'chua', 'nuang')
// ('chuan', 'ue', 'chua', 'nue')
// ('chuan', 'ui', 'chua', 'nui')
// ('chuan', 'un', 'chua', 'nun')
// ('chuan', 'uo', 'chua', 'nuo')
// ('chuan', 'v', 'chua', 'nv')
// ('chuang', 'ai', 'chuan', 'gai')
// ('chuang', 'an', 'chuan', 'gan')
// ('chuang', 'ang', 'chuan', 'gang')
// ('chuang', 'ao', 'chuan', 'gao')
// ('chuang', 'e', 'chuan', 'ge')
// ('chuang', 'ei', 'chuan', 'gei')
// ('chuang', 'en', 'chuan', 'gen')
// ('chuang', 'eng', 'chuan', 'geng')
// ('chuang', 'i', 'chuan', 'gi')
// ('chuang', 'ia', 'chuan', 'gia')
// ('chuang', 'ian', 'chuan', 'gian')
// ('chuang', 'iang', 'chuan', 'giang')
// ('chuang', 'iao', 'chuan', 'giao')
// ('chuang', 'ie', 'chuan', 'gie')
// ('chuang', 'in', 'chuan', 'gin')
// ('chuang', 'ing', 'chuan', 'ging')
// ('chuang', 'iong', 'chuan', 'giong')
// ('chuang', 'iu', 'chuan', 'giu')
// ('chuang', 'ong', 'chuan', 'gong')
// ('chuang', 'ou', 'chuan', 'gou')
// ('chuang', 'u', 'chuan', 'gu')
// ('chuang', 'ua', 'chuan', 'gua')
// ('chuang', 'uai', 'chuan', 'guai')
// ('chuang', 'uan', 'chuan', 'guan')
// ('chuang', 'uang', 'chuan', 'guang')
// ('chuang', 'ue', 'chuan', 'gue')
// ('chuang', 'ui', 'chuan', 'gui')
// ('chuang', 'un', 'chuan', 'gun')
// ('chuang', 'uo', 'chuan', 'guo')
// ('chuang', 'v', 'chuan', 'gv')
// ('chun', 'a', 'chu', 'na')
// ('chun', 'an', 'chu', 'nan')
// ('chun', 'e', 'chu', 'ne')
// ('chun', 'ei', 'chu', 'nei')
// ('chun', 'eng', 'chu', 'neng')
// ('chun', 'i', 'chu', 'ni')
// ('chun', 'ia', 'chu', 'nia')
// ('chun', 'ian', 'chu', 'nian')
// ('chun', 'iang', 'chu', 'niang')
// ('chun', 'iao', 'chu', 'niao')
// ('chun', 'ie', 'chu', 'nie')
// ('chun', 'in', 'chu', 'nin')
// ('chun', 'ing', 'chu', 'ning')
// ('chun', 'iong', 'chu', 'niong')
// ('chun', 'iu', 'chu', 'niu')
// ('chun', 'ong', 'chu', 'nong')
// ('chun', 'u', 'chu', 'nu')
// ('chun', 'ua', 'chu', 'nua')
// ('chun', 'uai', 'chu', 'nuai')
// ('chun', 'uan', 'chu', 'nuan')
// ('chun', 'uang', 'chu', 'nuang')
// ('chun', 'ue', 'chu', 'nue')
// ('chun', 'ui', 'chu', 'nui')
// ('chun', 'un', 'chu', 'nun')
// ('chun', 'uo', 'chu', 'nuo')
// ('chun', 'v', 'chu', 'nv')
// ('cong', 'eng', 'con', 'geng')
// ('cong', 'i', 'con', 'gi')
// ('cong', 'ia', 'con', 'gia')
// ('cong', 'ian', 'con', 'gian')
// ('cong', 'iang', 'con', 'giang')
// ('cong', 'iao', 'con', 'giao')
// ('cong', 'ie', 'con', 'gie')
// ('cong', 'in', 'con', 'gin')
// ('cong', 'ing', 'con', 'ging')
// ('cong', 'iong', 'con', 'giong')
// ('cong', 'iu', 'con', 'giu')
// ('cong', 'ong', 'con', 'gong')
// ('cong', 'u', 'con', 'gu')
// ('cong', 'ua', 'con', 'gua')
// ('cong', 'uai', 'con', 'guai')
// ('cong', 'uan', 'con', 'guan')
// ('cong', 'uang', 'con', 'guang')
// ('cong', 'ue', 'con', 'gue')
// ('cong', 'ui', 'con', 'gui')
// ('cong', 'un', 'con', 'gun')
// ('cong', 'uo', 'con', 'guo')
// ('cong', 'v', 'con', 'gv')
// ('cuan', 'eng', 'cua', 'neng')
// ('cuan', 'i', 'cua', 'ni')
// ('cuan', 'ia', 'cua', 'nia')
// ('cuan', 'ian', 'cua', 'nian')
// ('cuan', 'iang', 'cua', 'niang')
// ('cuan', 'iao', 'cua', 'niao')
// ('cuan', 'ie', 'cua', 'nie')
// ('cuan', 'in', 'cua', 'nin')
// ('cuan', 'ing', 'cua', 'ning')
// ('cuan', 'iong', 'cua', 'niong')
// ('cuan', 'iu', 'cua', 'niu')
// ('cuan', 'ong', 'cua', 'nong')
// ('cuan', 'u', 'cua', 'nu')
// ('cuan', 'ua', 'cua', 'nua')
// ('cuan', 'uai', 'cua', 'nuai')
// ('cuan', 'uan', 'cua', 'nuan')
// ('cuan', 'uang', 'cua', 'nuang')
// ('cuan', 'ue', 'cua', 'nue')
// ('cuan', 'ui', 'cua', 'nui')
// ('cuan', 'un', 'cua', 'nun')
// ('cuan', 'uo', 'cua', 'nuo')
// ('cuan', 'v', 'cua', 'nv')
// ('cun', 'a', 'cu', 'na')
// ('cun', 'ei', 'cu', 'nei')
// ('cun', 'eng', 'cu', 'neng')
// ('cun', 'i', 'cu', 'ni')
// ('cun', 'ia', 'cu', 'nia')
// ('cun', 'ian', 'cu', 'nian')
// ('cun', 'iang', 'cu', 'niang')
// ('cun', 'iao', 'cu', 'niao')
// ('cun', 'ie', 'cu', 'nie')
// ('cun', 'in', 'cu', 'nin')
// ('cun', 'ing', 'cu', 'ning')
// ('cun', 'iong', 'cu', 'niong')
// ('cun', 'iu', 'cu', 'niu')
// ('cun', 'ong', 'cu', 'nong')
// ('cun', 'u', 'cu', 'nu')
// ('cun', 'ua', 'cu', 'nua')
// ('cun', 'uai', 'cu', 'nuai')
// ('cun', 'uan', 'cu', 'nuan')
// ('cun', 'uang', 'cu', 'nuang')
// ('cun', 'ue', 'cu', 'nue')
// ('cun', 'ui', 'cu', 'nui')
// ('cun', 'un', 'cu', 'nun')
// ('cun', 'uo', 'cu', 'nuo')
// ('cun', 'v', 'cu', 'nv')
// ('dan', 'a', 'da', 'na')
// ('dan', 'ai', 'da', 'nai')
// ('dan', 'an', 'da', 'nan')
// ('dan', 'ao', 'da', 'nao')
// ('dan', 'e', 'da', 'ne')
// ('dan', 'ei', 'da', 'nei')
// ('dan', 'eng', 'da', 'neng')
// ('dan', 'i', 'da', 'ni')
// ('dan', 'ia', 'da', 'nia')
// ('dan', 'ian', 'da', 'nian')
// ('dan', 'iang', 'da', 'niang')
// ('dan', 'iao', 'da', 'niao')
// ('dan', 'ie', 'da', 'nie')
// ('dan', 'in', 'da', 'nin')
// ('dan', 'ing', 'da', 'ning')
// ('dan', 'iong', 'da', 'niong')
// ('dan', 'iu', 'da', 'niu')
// ('dan', 'ong', 'da', 'nong')
// ('dan', 'u', 'da', 'nu')
// ('dan', 'ua', 'da', 'nua')
// ('dan', 'uai', 'da', 'nuai')
// ('dan', 'uan', 'da', 'nuan')
// ('dan', 'uang', 'da', 'nuang')
// ('dan', 'ue', 'da', 'nue')
// ('dan', 'ui', 'da', 'nui')
// ('dan', 'un', 'da', 'nun')
// ('dan', 'uo', 'da', 'nuo')
// ('dan', 'v', 'da', 'nv')
// ('dang', 'ai', 'dan', 'gai')
// ('dang', 'ang', 'dan', 'gang')
// ('dang', 'ao', 'dan', 'gao')
// ('dang', 'e', 'dan', 'ge')
// ('dang', 'ei', 'dan', 'gei')
// ('dang', 'en', 'dan', 'gen')
// ('dang', 'eng', 'dan', 'geng')
// ('dang', 'i', 'dan', 'gi')
// ('dang', 'ia', 'dan', 'gia')
// ('dang', 'ian', 'dan', 'gian')
// ('dang', 'iang', 'dan', 'giang')
// ('dang', 'iao', 'dan', 'giao')
// ('dang', 'ie', 'dan', 'gie')
// ('dang', 'in', 'dan', 'gin')
// ('dang', 'ing', 'dan', 'ging')
// ('dang', 'iong', 'dan', 'giong')
// ('dang', 'iu', 'dan', 'giu')
// ('dang', 'ong', 'dan', 'gong')
// ('dang', 'u', 'dan', 'gu')
// ('dang', 'ua', 'dan', 'gua')
// ('dang', 'uai', 'dan', 'guai')
// ('dang', 'uan', 'dan', 'guan')
// ('dang', 'uang', 'dan', 'guang')
// ('dang', 'ue', 'dan', 'gue')
// ('dang', 'ui', 'dan', 'gui')
// ('dang', 'un', 'dan', 'gun')
// ('dang', 'uo', 'dan', 'guo')
// ('dang', 'v', 'dan', 'gv')
// ('deng', 'eng', 'den', 'geng')
// ('deng', 'i', 'den', 'gi')
// ('deng', 'ia', 'den', 'gia')
// ('deng', 'ian', 'den', 'gian')
// ('deng', 'iang', 'den', 'giang')
// ('deng', 'iao', 'den', 'giao')
// ('deng', 'ie', 'den', 'gie')
// ('deng', 'in', 'den', 'gin')
// ('deng', 'ing', 'den', 'ging')
// ('deng', 'iong', 'den', 'giong')
// ('deng', 'iu', 'den', 'giu')
// ('deng', 'ong', 'den', 'gong')
// ('deng', 'u', 'den', 'gu')
// ('deng', 'ua', 'den', 'gua')
// ('deng', 'uai', 'den', 'guai')
// ('deng', 'uan', 'den', 'guan')
// ('deng', 'uang', 'den', 'guang')
// ('deng', 'ue', 'den', 'gue')
// ('deng', 'ui', 'den', 'gui')
// ('deng', 'un', 'den', 'gun')
// ('deng', 'uo', 'den', 'guo')
// ('deng', 'v', 'den', 'gv')
// ('dian', 'ei', 'dia', 'nei')
// ('dian', 'eng', 'dia', 'neng')
// ('dian', 'i', 'dia', 'ni')
// ('dian', 'ia', 'dia', 'nia')
// ('dian', 'ian', 'dia', 'nian')
// ('dian', 'iang', 'dia', 'niang')
// ('dian', 'iao', 'dia', 'niao')
// ('dian', 'ie', 'dia', 'nie')
// ('dian', 'in', 'dia', 'nin')
// ('dian', 'ing', 'dia', 'ning')
// ('dian', 'iong', 'dia', 'niong')
// ('dian', 'iu', 'dia', 'niu')
// ('dian', 'ong', 'dia', 'nong')
// ('dian', 'u', 'dia', 'nu')
// ('dian', 'ua', 'dia', 'nua')
// ('dian', 'uai', 'dia', 'nuai')
// ('dian', 'uan', 'dia', 'nuan')
// ('dian', 'uang', 'dia', 'nuang')
// ('dian', 'ue', 'dia', 'nue')
// ('dian', 'ui', 'dia', 'nui')
// ('dian', 'un', 'dia', 'nun')
// ('dian', 'uo', 'dia', 'nuo')
// ('dian', 'v', 'dia', 'nv')
// ('ding', 'eng', 'din', 'geng')
// ('ding', 'i', 'din', 'gi')
// ('ding', 'ia', 'din', 'gia')
// ('ding', 'ian', 'din', 'gian')
// ('ding', 'iang', 'din', 'giang')
// ('ding', 'iao', 'din', 'giao')
// ('ding', 'ie', 'din', 'gie')
// ('ding', 'in', 'din', 'gin')
// ('ding', 'ing', 'din', 'ging')
// ('ding', 'iong', 'din', 'giong')
// ('ding', 'iu', 'din', 'giu')
// ('ding', 'ong', 'din', 'gong')
// ('ding', 'u', 'din', 'gu')
// ('ding', 'ua', 'din', 'gua')
// ('ding', 'uai', 'din', 'guai')
// ('ding', 'uan', 'din', 'guan')
// ('ding', 'uang', 'din', 'guang')
// ('ding', 'ue', 'din', 'gue')
// ('ding', 'ui', 'din', 'gui')
// ('ding', 'un', 'din', 'gun')
// ('ding', 'uo', 'din', 'guo')
// ('ding', 'v', 'din', 'gv')
// ('dong', 'eng', 'don', 'geng')
// ('dong', 'i', 'don', 'gi')
// ('dong', 'ia', 'don', 'gia')
// ('dong', 'ian', 'don', 'gian')
// ('dong', 'iang', 'don', 'giang')
// ('dong', 'iao', 'don', 'giao')
// ('dong', 'ie', 'don', 'gie')
// ('dong', 'in', 'don', 'gin')
// ('dong', 'ing', 'don', 'ging')
// ('dong', 'iong', 'don', 'giong')
// ('dong', 'iu', 'don', 'giu')
// ('dong', 'ong', 'don', 'gong')
// ('dong', 'u', 'don', 'gu')
// ('dong', 'ua', 'don', 'gua')
// ('dong', 'uai', 'don', 'guai')
// ('dong', 'uan', 'don', 'guan')
// ('dong', 'uang', 'don', 'guang')
// ('dong', 'ue', 'don', 'gue')
// ('dong', 'ui', 'don', 'gui')
// ('dong', 'un', 'don', 'gun')
// ('dong', 'uo', 'don', 'guo')
// ('dong', 'v', 'don', 'gv')
// ('duan', 'eng', 'dua', 'neng')
// ('duan', 'i', 'dua', 'ni')
// ('duan', 'ia', 'dua', 'nia')
// ('duan', 'ian', 'dua', 'nian')
// ('duan', 'iang', 'dua', 'niang')
// ('duan', 'iao', 'dua', 'niao')
// ('duan', 'ie', 'dua', 'nie')
// ('duan', 'in', 'dua', 'nin')
// ('duan', 'ing', 'dua', 'ning')
// ('duan', 'iong', 'dua', 'niong')
// ('duan', 'iu', 'dua', 'niu')
// ('duan', 'ong', 'dua', 'nong')
// ('duan', 'u', 'dua', 'nu')
// ('duan', 'ua', 'dua', 'nua')
// ('duan', 'uai', 'dua', 'nuai')
// ('duan', 'uan', 'dua', 'nuan')
// ('duan', 'uang', 'dua', 'nuang')
// ('duan', 'ue', 'dua', 'nue')
// ('duan', 'ui', 'dua', 'nui')
// ('duan', 'un', 'dua', 'nun')
// ('duan', 'uo', 'dua', 'nuo')
// ('duan', 'v', 'dua', 'nv')
// ('dun', 'a', 'du', 'na')
// ('dun', 'ai', 'du', 'nai')
// ('dun', 'an', 'du', 'nan')
// ('dun', 'ang', 'du', 'nang')
// ('dun', 'ao', 'du', 'nao')
// ('dun', 'e', 'du', 'ne')
// ('dun', 'ei', 'du', 'nei')
// ('dun', 'en', 'du', 'nen')
// ('dun', 'eng', 'du', 'neng')
// ('dun', 'i', 'du', 'ni')
// ('dun', 'ia', 'du', 'nia')
// ('dun', 'ian', 'du', 'nian')
// ('dun', 'iang', 'du', 'niang')
// ('dun', 'iao', 'du', 'niao')
// ('dun', 'ie', 'du', 'nie')
// ('dun', 'in', 'du', 'nin')
// ('dun', 'ing', 'du', 'ning')
// ('dun', 'iong', 'du', 'niong')
// ('dun', 'iu', 'du', 'niu')
// ('dun', 'ong', 'du', 'nong')
// ('dun', 'u', 'du', 'nu')
// ('dun', 'ua', 'du', 'nua')
// ('dun', 'uai', 'du', 'nuai')
// ('dun', 'uan', 'du', 'nuan')
// ('dun', 'uang', 'du', 'nuang')
// ('dun', 'ue', 'du', 'nue')
// ('dun', 'ui', 'du', 'nui')
// ('dun', 'un', 'du', 'nun')
// ('dun', 'uo', 'du', 'nuo')
// ('dun', 'v', 'du', 'nv')
// ('en', 'an', 'e', 'nan')
// ('en', 'ang', 'e', 'nang')
// ('en', 'ao', 'e', 'nao')
// ('en', 'e', 'e', 'ne')
// ('en', 'ei', 'e', 'nei')
// ('en', 'eng', 'e', 'neng')
// ('en', 'i', 'e', 'ni')
// ('en', 'ia', 'e', 'nia')
// ('en', 'ian', 'e', 'nian')
// ('en', 'iang', 'e', 'niang')
// ('en', 'iao', 'e', 'niao')
// ('en', 'ie', 'e', 'nie')
// ('en', 'in', 'e', 'nin')
// ('en', 'ing', 'e', 'ning')
// ('en', 'iong', 'e', 'niong')
// ('en', 'iu', 'e', 'niu')
// ('en', 'ong', 'e', 'nong')
// ('en', 'u', 'e', 'nu')
// ('en', 'ua', 'e', 'nua')
// ('en', 'uai', 'e', 'nuai')
// ('en', 'uan', 'e', 'nuan')
// ('en', 'uang', 'e', 'nuang')
// ('en', 'ue', 'e', 'nue')
// ('en', 'ui', 'e', 'nui')
// ('en', 'un', 'e', 'nun')
// ('en', 'uo', 'e', 'nuo')
// ('en', 'v', 'e', 'nv')
// ('er', 'an', 'e', 'ran')
// ('er', 'ang', 'e', 'rang')
// ('er', 'en', 'e', 'ren')
// ('er', 'eng', 'e', 'reng')
// ('er', 'i', 'e', 'ri')
// ('er', 'ia', 'e', 'ria')
// ('er', 'ian', 'e', 'rian')
// ('er', 'iang', 'e', 'riang')
// ('er', 'iao', 'e', 'riao')
// ('er', 'ie', 'e', 'rie')
// ('er', 'in', 'e', 'rin')
// ('er', 'ing', 'e', 'ring')
// ('er', 'iong', 'e', 'riong')
// ('er', 'iu', 'e', 'riu')
// ('er', 'ong', 'e', 'rong')
// ('er', 'ou', 'e', 'rou')
// ('er', 'u', 'e', 'ru')
// ('er', 'ua', 'e', 'rua')
// ('er', 'uai', 'e', 'ruai')
// ('er', 'uan', 'e', 'ruan')
// ('er', 'uang', 'e', 'ruang')
// ('er', 'ue', 'e', 'rue')
// ('er', 'ui', 'e', 'rui')
// ('er', 'un', 'e', 'run')
// ('er', 'uo', 'e', 'ruo')
// ('er', 'v', 'e', 'rv')
// ('fan', 'ao', 'fa', 'nao')
// ('fan', 'ei', 'fa', 'nei')
// ('fan', 'eng', 'fa', 'neng')
// ('fan', 'i', 'fa', 'ni')
// ('fan', 'ia', 'fa', 'nia')
// ('fan', 'ian', 'fa', 'nian')
// ('fan', 'iang', 'fa', 'niang')
// ('fan', 'iao', 'fa', 'niao')
// ('fan', 'ie', 'fa', 'nie')
// ('fan', 'in', 'fa', 'nin')
// ('fan', 'ing', 'fa', 'ning')
// ('fan', 'iong', 'fa', 'niong')
// ('fan', 'iu', 'fa', 'niu')
// ('fan', 'ong', 'fa', 'nong')
// ('fan', 'u', 'fa', 'nu')
// ('fan', 'ua', 'fa', 'nua')
// ('fan', 'uai', 'fa', 'nuai')
// ('fan', 'uan', 'fa', 'nuan')
// ('fan', 'uang', 'fa', 'nuang')
// ('fan', 'ue', 'fa', 'nue')
// ('fan', 'ui', 'fa', 'nui')
// ('fan', 'un', 'fa', 'nun')
// ('fan', 'uo', 'fa', 'nuo')
// ('fan', 'v', 'fa', 'nv')
// ('fang', 'ang', 'fan', 'gang')
// ('fang', 'ao', 'fan', 'gao')
// ('fang', 'e', 'fan', 'ge')
// ('fang', 'ei', 'fan', 'gei')
// ('fang', 'en', 'fan', 'gen')
// ('fang', 'eng', 'fan', 'geng')
// ('fang', 'i', 'fan', 'gi')
// ('fang', 'ia', 'fan', 'gia')
// ('fang', 'ian', 'fan', 'gian')
// ('fang', 'iang', 'fan', 'giang')
// ('fang', 'iao', 'fan', 'giao')
// ('fang', 'ie', 'fan', 'gie')
// ('fang', 'in', 'fan', 'gin')
// ('fang', 'ing', 'fan', 'ging')
// ('fang', 'iong', 'fan', 'giong')
// ('fang', 'iu', 'fan', 'giu')
// ('fang', 'ong', 'fan', 'gong')
// ('fang', 'u', 'fan', 'gu')
// ('fang', 'ua', 'fan', 'gua')
// ('fang', 'uai', 'fan', 'guai')
// ('fang', 'uan', 'fan', 'guan')
// ('fang', 'uang', 'fan', 'guang')
// ('fang', 'ue', 'fan', 'gue')
// ('fang', 'ui', 'fan', 'gui')
// ('fang', 'un', 'fan', 'gun')
// ('fang', 'uo', 'fan', 'guo')
// ('fang', 'v', 'fan', 'gv')
// ('fen', 'eng', 'fe', 'neng')
// ('fen', 'i', 'fe', 'ni')
// ('fen', 'ia', 'fe', 'nia')
// ('fen', 'ian', 'fe', 'nian')
// ('fen', 'iang', 'fe', 'niang')
// ('fen', 'iao', 'fe', 'niao')
// ('fen', 'ie', 'fe', 'nie')
// ('fen', 'in', 'fe', 'nin')
// ('fen', 'ing', 'fe', 'ning')
// ('fen', 'iong', 'fe', 'niong')
// ('fen', 'iu', 'fe', 'niu')
// ('fen', 'ong', 'fe', 'nong')
// ('fen', 'u', 'fe', 'nu')
// ('fen', 'ua', 'fe', 'nua')
// ('fen', 'uai', 'fe', 'nuai')
// ('fen', 'uan', 'fe', 'nuan')
// ('fen', 'uang', 'fe', 'nuang')
// ('fen', 'ue', 'fe', 'nue')
// ('fen', 'ui', 'fe', 'nui')
// ('fen', 'un', 'fe', 'nun')
// ('fen', 'uo', 'fe', 'nuo')
// ('fen', 'v', 'fe', 'nv')
// ('feng', 'ang', 'fen', 'gang')
// ('feng', 'ao', 'fen', 'gao')
// ('feng', 'e', 'fen', 'ge')
// ('feng', 'ei', 'fen', 'gei')
// ('feng', 'en', 'fen', 'gen')
// ('feng', 'eng', 'fen', 'geng')
// ('feng', 'i', 'fen', 'gi')
// ('feng', 'ia', 'fen', 'gia')
// ('feng', 'ian', 'fen', 'gian')
// ('feng', 'iang', 'fen', 'giang')
// ('feng', 'iao', 'fen', 'giao')
// ('feng', 'ie', 'fen', 'gie')
// ('feng', 'in', 'fen', 'gin')
// ('feng', 'ing', 'fen', 'ging')
// ('feng', 'iong', 'fen', 'giong')
// ('feng', 'iu', 'fen', 'giu')
// ('feng', 'ong', 'fen', 'gong')
// ('feng', 'ou', 'fen', 'gou')
// ('feng', 'u', 'fen', 'gu')
// ('feng', 'ua', 'fen', 'gua')
// ('feng', 'uai', 'fen', 'guai')
// ('feng', 'uan', 'fen', 'guan')
// ('feng', 'uang', 'fen', 'guang')
// ('feng', 'ue', 'fen', 'gue')
// ('feng', 'ui', 'fen', 'gui')
// ('feng', 'un', 'fen', 'gun')
// ('feng', 'uo', 'fen', 'guo')
// ('feng', 'v', 'fen', 'gv')
// ('gan', 'e', 'ga', 'ne')
// ('gan', 'ei', 'ga', 'nei')
// ('gan', 'eng', 'ga', 'neng')
// ('gan', 'i', 'ga', 'ni')
// ('gan', 'ia', 'ga', 'nia')
// ('gan', 'ian', 'ga', 'nian')
// ('gan', 'iang', 'ga', 'niang')
// ('gan', 'iao', 'ga', 'niao')
// ('gan', 'ie', 'ga', 'nie')
// ('gan', 'in', 'ga', 'nin')
// ('gan', 'ing', 'ga', 'ning')
// ('gan', 'iong', 'ga', 'niong')
// ('gan', 'iu', 'ga', 'niu')
// ('gan', 'ong', 'ga', 'nong')
// ('gan', 'u', 'ga', 'nu')
// ('gan', 'ua', 'ga', 'nua')
// ('gan', 'uai', 'ga', 'nuai')
// ('gan', 'uan', 'ga', 'nuan')
// ('gan', 'uang', 'ga', 'nuang')
// ('gan', 'ue', 'ga', 'nue')
// ('gan', 'ui', 'ga', 'nui')
// ('gan', 'un', 'ga', 'nun')
// ('gan', 'uo', 'ga', 'nuo')
// ('gan', 'v', 'ga', 'nv')
// ('gang', 'a', 'gan', 'ga')
// ('gang', 'ai', 'gan', 'gai')
// ('gang', 'an', 'gan', 'gan')
// ('gang', 'ang', 'gan', 'gang')
// ('gang', 'e', 'gan', 'ge')
// ('gang', 'ei', 'gan', 'gei')
// ('gang', 'en', 'gan', 'gen')
// ('gang', 'eng', 'gan', 'geng')
// ('gang', 'i', 'gan', 'gi')
// ('gang', 'ia', 'gan', 'gia')
// ('gang', 'ian', 'gan', 'gian')
// ('gang', 'iang', 'gan', 'giang')
// ('gang', 'iao', 'gan', 'giao')
// ('gang', 'ie', 'gan', 'gie')
// ('gang', 'in', 'gan', 'gin')
// ('gang', 'ing', 'gan', 'ging')
// ('gang', 'iong', 'gan', 'giong')
// ('gang', 'iu', 'gan', 'giu')
// ('gang', 'ong', 'gan', 'gong')
// ('gang', 'ou', 'gan', 'gou')
// ('gang', 'u', 'gan', 'gu')
// ('gang', 'ua', 'gan', 'gua')
// ('gang', 'uai', 'gan', 'guai')
// ('gang', 'uan', 'gan', 'guan')
// ('gang', 'uang', 'gan', 'guang')
// ('gang', 'ue', 'gan', 'gue')
// ('gang', 'ui', 'gan', 'gui')
// ('gang', 'un', 'gan', 'gun')
// ('gang', 'uo', 'gan', 'guo')
// ('gang', 'v', 'gan', 'gv')
// ('gen', 'a', 'ge', 'na')
// ('gen', 'an', 'ge', 'nan')
// ('gen', 'ang', 'ge', 'nang')
// ('gen', 'ao', 'ge', 'nao')
// ('gen', 'e', 'ge', 'ne')
// ('gen', 'ei', 'ge', 'nei')
// ('gen', 'eng', 'ge', 'neng')
// ('gen', 'i', 'ge', 'ni')
// ('gen', 'ia', 'ge', 'nia')
// ('gen', 'ian', 'ge', 'nian')
// ('gen', 'iang', 'ge', 'niang')
// ('gen', 'iao', 'ge', 'niao')
// ('gen', 'ie', 'ge', 'nie')
// ('gen', 'in', 'ge', 'nin')
// ('gen', 'ing', 'ge', 'ning')
// ('gen', 'iong', 'ge', 'niong')
// ('gen', 'iu', 'ge', 'niu')
// ('gen', 'ong', 'ge', 'nong')
// ('gen', 'u', 'ge', 'nu')
// ('gen', 'ua', 'ge', 'nua')
// ('gen', 'uai', 'ge', 'nuai')
// ('gen', 'uan', 'ge', 'nuan')
// ('gen', 'uang', 'ge', 'nuang')
// ('gen', 'ue', 'ge', 'nue')
// ('gen', 'ui', 'ge', 'nui')
// ('gen', 'un', 'ge', 'nun')
// ('gen', 'uo', 'ge', 'nuo')
// ('gen', 'v', 'ge', 'nv')
// ('geng', 'ang', 'gen', 'gang')
// ('geng', 'ao', 'gen', 'gao')
// ('geng', 'e', 'gen', 'ge')
// ('geng', 'ei', 'gen', 'gei')
// ('geng', 'en', 'gen', 'gen')
// ('geng', 'eng', 'gen', 'geng')
// ('geng', 'i', 'gen', 'gi')
// ('geng', 'ia', 'gen', 'gia')
// ('geng', 'ian', 'gen', 'gian')
// ('geng', 'iang', 'gen', 'giang')
// ('geng', 'iao', 'gen', 'giao')
// ('geng', 'ie', 'gen', 'gie')
// ('geng', 'in', 'gen', 'gin')
// ('geng', 'ing', 'gen', 'ging')
// ('geng', 'iong', 'gen', 'giong')
// ('geng', 'iu', 'gen', 'giu')
// ('geng', 'ong', 'gen', 'gong')
// ('geng', 'ou', 'gen', 'gou')
// ('geng', 'u', 'gen', 'gu')
// ('geng', 'ua', 'gen', 'gua')
// ('geng', 'uai', 'gen', 'guai')
// ('geng', 'uan', 'gen', 'guan')
// ('geng', 'uang', 'gen', 'guang')
// ('geng', 'ue', 'gen', 'gue')
// ('geng', 'ui', 'gen', 'gui')
// ('geng', 'un', 'gen', 'gun')
// ('geng', 'uo', 'gen', 'guo')
// ('geng', 'v', 'gen', 'gv')
// ('gong', 'eng', 'gon', 'geng')
// ('gong', 'i', 'gon', 'gi')
// ('gong', 'ia', 'gon', 'gia')
// ('gong', 'ian', 'gon', 'gian')
// ('gong', 'iang', 'gon', 'giang')
// ('gong', 'iao', 'gon', 'giao')
// ('gong', 'ie', 'gon', 'gie')
// ('gong', 'in', 'gon', 'gin')
// ('gong', 'ing', 'gon', 'ging')
// ('gong', 'iong', 'gon', 'giong')
// ('gong', 'iu', 'gon', 'giu')
// ('gong', 'ong', 'gon', 'gong')
// ('gong', 'u', 'gon', 'gu')
// ('gong', 'ua', 'gon', 'gua')
// ('gong', 'uai', 'gon', 'guai')
// ('gong', 'uan', 'gon', 'guan')
// ('gong', 'uang', 'gon', 'guang')
// ('gong', 'ue', 'gon', 'gue')
// ('gong', 'ui', 'gon', 'gui')
// ('gong', 'un', 'gon', 'gun')
// ('gong', 'uo', 'gon', 'guo')
// ('gong', 'v', 'gon', 'gv')
// ('guan', 'ei', 'gua', 'nei')
// ('guan', 'eng', 'gua', 'neng')
// ('guan', 'i', 'gua', 'ni')
// ('guan', 'ia', 'gua', 'nia')
// ('guan', 'ian', 'gua', 'nian')
// ('guan', 'iang', 'gua', 'niang')
// ('guan', 'iao', 'gua', 'niao')
// ('guan', 'ie', 'gua', 'nie')
// ('guan', 'in', 'gua', 'nin')
// ('guan', 'ing', 'gua', 'ning')
// ('guan', 'iong', 'gua', 'niong')
// ('guan', 'iu', 'gua', 'niu')
// ('guan', 'ong', 'gua', 'nong')
// ('guan', 'u', 'gua', 'nu')
// ('guan', 'ua', 'gua', 'nua')
// ('guan', 'uai', 'gua', 'nuai')
// ('guan', 'uan', 'gua', 'nuan')
// ('guan', 'uang', 'gua', 'nuang')
// ('guan', 'ue', 'gua', 'nue')
// ('guan', 'ui', 'gua', 'nui')
// ('guan', 'un', 'gua', 'nun')
// ('guan', 'uo', 'gua', 'nuo')
// ('guan', 'v', 'gua', 'nv')
// ('guang', 'ai', 'guan', 'gai')
// ('guang', 'ang', 'guan', 'gang')
// ('guang', 'ao', 'guan', 'gao')
// ('guang', 'e', 'guan', 'ge')
// ('guang', 'ei', 'guan', 'gei')
// ('guang', 'en', 'guan', 'gen')
// ('guang', 'eng', 'guan', 'geng')
// ('guang', 'i', 'guan', 'gi')
// ('guang', 'ia', 'guan', 'gia')
// ('guang', 'ian', 'guan', 'gian')
// ('guang', 'iang', 'guan', 'giang')
// ('guang', 'iao', 'guan', 'giao')
// ('guang', 'ie', 'guan', 'gie')
// ('guang', 'in', 'guan', 'gin')
// ('guang', 'ing', 'guan', 'ging')
// ('guang', 'iong', 'guan', 'giong')
// ('guang', 'iu', 'guan', 'giu')
// ('guang', 'ong', 'guan', 'gong')
// ('guang', 'u', 'guan', 'gu')
// ('guang', 'ua', 'guan', 'gua')
// ('guang', 'uai', 'guan', 'guai')
// ('guang', 'uan', 'guan', 'guan')
// ('guang', 'uang', 'guan', 'guang')
// ('guang', 'ue', 'guan', 'gue')
// ('guang', 'ui', 'guan', 'gui')
// ('guang', 'un', 'guan', 'gun')
// ('guang', 'uo', 'guan', 'guo')
// ('guang', 'v', 'guan', 'gv')
// ('gun', 'ai', 'gu', 'nai')
// ('gun', 'an', 'gu', 'nan')
// ('gun', 'ao', 'gu', 'nao')
// ('gun', 'e', 'gu', 'ne')
// ('gun', 'ei', 'gu', 'nei')
// ('gun', 'en', 'gu', 'nen')
// ('gun', 'eng', 'gu', 'neng')
// ('gun', 'i', 'gu', 'ni')
// ('gun', 'ia', 'gu', 'nia')
// ('gun', 'ian', 'gu', 'nian')
// ('gun', 'iang', 'gu', 'niang')
// ('gun', 'iao', 'gu', 'niao')
// ('gun', 'ie', 'gu', 'nie')
// ('gun', 'in', 'gu', 'nin')
// ('gun', 'ing', 'gu', 'ning')
// ('gun', 'iong', 'gu', 'niong')
// ('gun', 'iu', 'gu', 'niu')
// ('gun', 'ong', 'gu', 'nong')
// ('gun', 'u', 'gu', 'nu')
// ('gun', 'ua', 'gu', 'nua')
// ('gun', 'uai', 'gu', 'nuai')
// ('gun', 'uan', 'gu', 'nuan')
// ('gun', 'uang', 'gu', 'nuang')
// ('gun', 'ue', 'gu', 'nue')
// ('gun', 'ui', 'gu', 'nui')
// ('gun', 'un', 'gu', 'nun')
// ('gun', 'uo', 'gu', 'nuo')
// ('gun', 'v', 'gu', 'nv')
// ('han', 'ei', 'ha', 'nei')
// ('han', 'eng', 'ha', 'neng')
// ('han', 'i', 'ha', 'ni')
// ('han', 'ia', 'ha', 'nia')
// ('han', 'ian', 'ha', 'nian')
// ('han', 'iang', 'ha', 'niang')
// ('han', 'iao', 'ha', 'niao')
// ('han', 'ie', 'ha', 'nie')
// ('han', 'in', 'ha', 'nin')
// ('han', 'ing', 'ha', 'ning')
// ('han', 'iong', 'ha', 'niong')
// ('han', 'iu', 'ha', 'niu')
// ('han', 'ong', 'ha', 'nong')
// ('han', 'u', 'ha', 'nu')
// ('han', 'ua', 'ha', 'nua')
// ('han', 'uai', 'ha', 'nuai')
// ('han', 'uan', 'ha', 'nuan')
// ('han', 'uang', 'ha', 'nuang')
// ('han', 'ue', 'ha', 'nue')
// ('han', 'ui', 'ha', 'nui')
// ('han', 'un', 'ha', 'nun')
// ('han', 'uo', 'ha', 'nuo')
// ('han', 'v', 'ha', 'nv')
// ('hang', 'ai', 'han', 'gai')
// ('hang', 'ang', 'han', 'gang')
// ('hang', 'ao', 'han', 'gao')
// ('hang', 'e', 'han', 'ge')
// ('hang', 'ei', 'han', 'gei')
// ('hang', 'en', 'han', 'gen')
// ('hang', 'eng', 'han', 'geng')
// ('hang', 'i', 'han', 'gi')
// ('hang', 'ia', 'han', 'gia')
// ('hang', 'ian', 'han', 'gian')
// ('hang', 'iang', 'han', 'giang')
// ('hang', 'iao', 'han', 'giao')
// ('hang', 'ie', 'han', 'gie')
// ('hang', 'in', 'han', 'gin')
// ('hang', 'ing', 'han', 'ging')
// ('hang', 'iong', 'han', 'giong')
// ('hang', 'iu', 'han', 'giu')
// ('hang', 'ong', 'han', 'gong')
// ('hang', 'ou', 'han', 'gou')
// ('hang', 'u', 'han', 'gu')
// ('hang', 'ua', 'han', 'gua')
// ('hang', 'uai', 'han', 'guai')
// ('hang', 'uan', 'han', 'guan')
// ('hang', 'uang', 'han', 'guang')
// ('hang', 'ue', 'han', 'gue')
// ('hang', 'ui', 'han', 'gui')
// ('hang', 'un', 'han', 'gun')
// ('hang', 'uo', 'han', 'guo')
// ('hang', 'v', 'han', 'gv')
// ('hen', 'a', 'he', 'na')
// ('hen', 'an', 'he', 'nan')
// ('hen', 'ei', 'he', 'nei')
// ('hen', 'eng', 'he', 'neng')
// ('hen', 'i', 'he', 'ni')
// ('hen', 'ia', 'he', 'nia')
// ('hen', 'ian', 'he', 'nian')
// ('hen', 'iang', 'he', 'niang')
// ('hen', 'iao', 'he', 'niao')
// ('hen', 'ie', 'he', 'nie')
// ('hen', 'in', 'he', 'nin')
// ('hen', 'ing', 'he', 'ning')
// ('hen', 'iong', 'he', 'niong')
// ('hen', 'iu', 'he', 'niu')
// ('hen', 'ong', 'he', 'nong')
// ('hen', 'u', 'he', 'nu')
// ('hen', 'ua', 'he', 'nua')
// ('hen', 'uai', 'he', 'nuai')
// ('hen', 'uan', 'he', 'nuan')
// ('hen', 'uang', 'he', 'nuang')
// ('hen', 'ue', 'he', 'nue')
// ('hen', 'ui', 'he', 'nui')
// ('hen', 'un', 'he', 'nun')
// ('hen', 'uo', 'he', 'nuo')
// ('hen', 'v', 'he', 'nv')
// ('heng', 'a', 'hen', 'ga')
// ('heng', 'ai', 'hen', 'gai')
// ('heng', 'an', 'hen', 'gan')
// ('heng', 'ang', 'hen', 'gang')
// ('heng', 'ao', 'hen', 'gao')
// ('heng', 'ei', 'hen', 'gei')
// ('heng', 'en', 'hen', 'gen')
// ('heng', 'eng', 'hen', 'geng')
// ('heng', 'i', 'hen', 'gi')
// ('heng', 'ia', 'hen', 'gia')
// ('heng', 'ian', 'hen', 'gian')
// ('heng', 'iang', 'hen', 'giang')
// ('heng', 'iao', 'hen', 'giao')
// ('heng', 'ie', 'hen', 'gie')
// ('heng', 'in', 'hen', 'gin')
// ('heng', 'ing', 'hen', 'ging')
// ('heng', 'iong', 'hen', 'giong')
// ('heng', 'iu', 'hen', 'giu')
// ('heng', 'ong', 'hen', 'gong')
// ('heng', 'ou', 'hen', 'gou')
// ('heng', 'u', 'hen', 'gu')
// ('heng', 'ua', 'hen', 'gua')
// ('heng', 'uai', 'hen', 'guai')
// ('heng', 'uan', 'hen', 'guan')
// ('heng', 'uang', 'hen', 'guang')
// ('heng', 'ue', 'hen', 'gue')
// ('heng', 'ui', 'hen', 'gui')
// ('heng', 'un', 'hen', 'gun')
// ('heng', 'uo', 'hen', 'guo')
// ('heng', 'v', 'hen', 'gv')
// ('hong', 'eng', 'hon', 'geng')
// ('hong', 'i', 'hon', 'gi')
// ('hong', 'ia', 'hon', 'gia')
// ('hong', 'ian', 'hon', 'gian')
// ('hong', 'iang', 'hon', 'giang')
// ('hong', 'iao', 'hon', 'giao')
// ('hong', 'ie', 'hon', 'gie')
// ('hong', 'in', 'hon', 'gin')
// ('hong', 'ing', 'hon', 'ging')
// ('hong', 'iong', 'hon', 'giong')
// ('hong', 'iu', 'hon', 'giu')
// ('hong', 'ong', 'hon', 'gong')
// ('hong', 'u', 'hon', 'gu')
// ('hong', 'ua', 'hon', 'gua')
// ('hong', 'uai', 'hon', 'guai')
// ('hong', 'uan', 'hon', 'guan')
// ('hong', 'uang', 'hon', 'guang')
// ('hong', 'ue', 'hon', 'gue')
// ('hong', 'ui', 'hon', 'gui')
// ('hong', 'un', 'hon', 'gun')
// ('hong', 'uo', 'hon', 'guo')
// ('hong', 'v', 'hon', 'gv')
// ('huan', 'a', 'hua', 'na')
// ('huan', 'an', 'hua', 'nan')
// ('huan', 'e', 'hua', 'ne')
// ('huan', 'ei', 'hua', 'nei')
// ('huan', 'en', 'hua', 'nen')
// ('huan', 'eng', 'hua', 'neng')
// ('huan', 'i', 'hua', 'ni')
// ('huan', 'ia', 'hua', 'nia')
// ('huan', 'ian', 'hua', 'nian')
// ('huan', 'iang', 'hua', 'niang')
// ('huan', 'iao', 'hua', 'niao')
// ('huan', 'ie', 'hua', 'nie')
// ('huan', 'in', 'hua', 'nin')
// ('huan', 'ing', 'hua', 'ning')
// ('huan', 'iong', 'hua', 'niong')
// ('huan', 'iu', 'hua', 'niu')
// ('huan', 'ong', 'hua', 'nong')
// ('huan', 'u', 'hua', 'nu')
// ('huan', 'ua', 'hua', 'nua')
// ('huan', 'uai', 'hua', 'nuai')
// ('huan', 'uan', 'hua', 'nuan')
// ('huan', 'uang', 'hua', 'nuang')
// ('huan', 'ue', 'hua', 'nue')
// ('huan', 'ui', 'hua', 'nui')
// ('huan', 'un', 'hua', 'nun')
// ('huan', 'uo', 'hua', 'nuo')
// ('huan', 'v', 'hua', 'nv')
// ('huang', 'ai', 'huan', 'gai')
// ('huang', 'ang', 'huan', 'gang')
// ('huang', 'ao', 'huan', 'gao')
// ('huang', 'e', 'huan', 'ge')
// ('huang', 'ei', 'huan', 'gei')
// ('huang', 'eng', 'huan', 'geng')
// ('huang', 'i', 'huan', 'gi')
// ('huang', 'ia', 'huan', 'gia')
// ('huang', 'ian', 'huan', 'gian')
// ('huang', 'iang', 'huan', 'giang')
// ('huang', 'iao', 'huan', 'giao')
// ('huang', 'ie', 'huan', 'gie')
// ('huang', 'in', 'huan', 'gin')
// ('huang', 'ing', 'huan', 'ging')
// ('huang', 'iong', 'huan', 'giong')
// ('huang', 'iu', 'huan', 'giu')
// ('huang', 'ong', 'huan', 'gong')
// ('huang', 'ou', 'huan', 'gou')
// ('huang', 'u', 'huan', 'gu')
// ('huang', 'ua', 'huan', 'gua')
// ('huang', 'uai', 'huan', 'guai')
// ('huang', 'uan', 'huan', 'guan')
// ('huang', 'uang', 'huan', 'guang')
// ('huang', 'ue', 'huan', 'gue')
// ('huang', 'ui', 'huan', 'gui')
// ('huang', 'un', 'huan', 'gun')
// ('huang', 'uo', 'huan', 'guo')
// ('huang', 'v', 'huan', 'gv')
// ('hun', 'an', 'hu', 'nan')
// ('hun', 'ao', 'hu', 'nao')
// ('hun', 'ei', 'hu', 'nei')
// ('hun', 'eng', 'hu', 'neng')
// ('hun', 'i', 'hu', 'ni')
// ('hun', 'ia', 'hu', 'nia')
// ('hun', 'ian', 'hu', 'nian')
// ('hun', 'iang', 'hu', 'niang')
// ('hun', 'iao', 'hu', 'niao')
// ('hun', 'ie', 'hu', 'nie')
// ('hun', 'in', 'hu', 'nin')
// ('hun', 'ing', 'hu', 'ning')
// ('hun', 'iong', 'hu', 'niong')
// ('hun', 'iu', 'hu', 'niu')
// ('hun', 'ong', 'hu', 'nong')
// ('hun', 'u', 'hu', 'nu')
// ('hun', 'ua', 'hu', 'nua')
// ('hun', 'uai', 'hu', 'nuai')
// ('hun', 'uan', 'hu', 'nuan')
// ('hun', 'uang', 'hu', 'nuang')
// ('hun', 'ue', 'hu', 'nue')
// ('hun', 'ui', 'hu', 'nui')
// ('hun', 'un', 'hu', 'nun')
// ('hun', 'uo', 'hu', 'nuo')
// ('hun', 'v', 'hu', 'nv')
// ('jian', 'a', 'jia', 'na')
// ('jian', 'ai', 'jia', 'nai')
// ('jian', 'e', 'jia', 'ne')
// ('jian', 'ei', 'jia', 'nei')
// ('jian', 'eng', 'jia', 'neng')
// ('jian', 'i', 'jia', 'ni')
// ('jian', 'ia', 'jia', 'nia')
// ('jian', 'ian', 'jia', 'nian')
// ('jian', 'iang', 'jia', 'niang')
// ('jian', 'iao', 'jia', 'niao')
// ('jian', 'ie', 'jia', 'nie')
// ('jian', 'in', 'jia', 'nin')
// ('jian', 'ing', 'jia', 'ning')
// ('jian', 'iong', 'jia', 'niong')
// ('jian', 'iu', 'jia', 'niu')
// ('jian', 'ong', 'jia', 'nong')
// ('jian', 'u', 'jia', 'nu')
// ('jian', 'ua', 'jia', 'nua')
// ('jian', 'uai', 'jia', 'nuai')
// ('jian', 'uan', 'jia', 'nuan')
// ('jian', 'uang', 'jia', 'nuang')
// ('jian', 'ue', 'jia', 'nue')
// ('jian', 'ui', 'jia', 'nui')
// ('jian', 'un', 'jia', 'nun')
// ('jian', 'uo', 'jia', 'nuo')
// ('jian', 'v', 'jia', 'nv')
// ('jiang', 'ang', 'jian', 'gang')
// ('jiang', 'ao', 'jian', 'gao')
// ('jiang', 'e', 'jian', 'ge')
// ('jiang', 'ei', 'jian', 'gei')
// ('jiang', 'eng', 'jian', 'geng')
// ('jiang', 'i', 'jian', 'gi')
// ('jiang', 'ia', 'jian', 'gia')
// ('jiang', 'ian', 'jian', 'gian')
// ('jiang', 'iang', 'jian', 'giang')
// ('jiang', 'iao', 'jian', 'giao')
// ('jiang', 'ie', 'jian', 'gie')
// ('jiang', 'in', 'jian', 'gin')
// ('jiang', 'ing', 'jian', 'ging')
// ('jiang', 'iong', 'jian', 'giong')
// ('jiang', 'iu', 'jian', 'giu')
// ('jiang', 'ong', 'jian', 'gong')
// ('jiang', 'ou', 'jian', 'gou')
// ('jiang', 'u', 'jian', 'gu')
// ('jiang', 'ua', 'jian', 'gua')
// ('jiang', 'uai', 'jian', 'guai')
// ('jiang', 'uan', 'jian', 'guan')
// ('jiang', 'uang', 'jian', 'guang')
// ('jiang', 'ue', 'jian', 'gue')
// ('jiang', 'ui', 'jian', 'gui')
// ('jiang', 'un', 'jian', 'gun')
// ('jiang', 'uo', 'jian', 'guo')
// ('jiang', 'v', 'jian', 'gv')
// ('jin', 'a', 'ji', 'na')
// ('jin', 'an', 'ji', 'nan')
// ('jin', 'ao', 'ji', 'nao')
// ('jin', 'ei', 'ji', 'nei')
// ('jin', 'eng', 'ji', 'neng')
// ('jin', 'i', 'ji', 'ni')
// ('jin', 'ia', 'ji', 'nia')
// ('jin', 'ian', 'ji', 'nian')
// ('jin', 'iang', 'ji', 'niang')
// ('jin', 'iao', 'ji', 'niao')
// ('jin', 'ie', 'ji', 'nie')
// ('jin', 'in', 'ji', 'nin')
// ('jin', 'ing', 'ji', 'ning')
// ('jin', 'iong', 'ji', 'niong')
// ('jin', 'iu', 'ji', 'niu')
// ('jin', 'ong', 'ji', 'nong')
// ('jin', 'u', 'ji', 'nu')
// ('jin', 'ua', 'ji', 'nua')
// ('jin', 'uai', 'ji', 'nuai')
// ('jin', 'uan', 'ji', 'nuan')
// ('jin', 'uang', 'ji', 'nuang')
// ('jin', 'ue', 'ji', 'nue')
// ('jin', 'ui', 'ji', 'nui')
// ('jin', 'un', 'ji', 'nun')
// ('jin', 'uo', 'ji', 'nuo')
// ('jin', 'v', 'ji', 'nv')
// ('jing', 'ang', 'jin', 'gang')
// ('jing', 'ao', 'jin', 'gao')
// ('jing', 'ei', 'jin', 'gei')
// ('jing', 'en', 'jin', 'gen')
// ('jing', 'eng', 'jin', 'geng')
// ('jing', 'i', 'jin', 'gi')
// ('jing', 'ia', 'jin', 'gia')
// ('jing', 'ian', 'jin', 'gian')
// ('jing', 'iang', 'jin', 'giang')
// ('jing', 'iao', 'jin', 'giao')
// ('jing', 'ie', 'jin', 'gie')
// ('jing', 'in', 'jin', 'gin')
// ('jing', 'ing', 'jin', 'ging')
// ('jing', 'iong', 'jin', 'giong')
// ('jing', 'iu', 'jin', 'giu')
// ('jing', 'ong', 'jin', 'gong')
// ('jing', 'ou', 'jin', 'gou')
// ('jing', 'u', 'jin', 'gu')
// ('jing', 'ua', 'jin', 'gua')
// ('jing', 'uai', 'jin', 'guai')
// ('jing', 'uan', 'jin', 'guan')
// ('jing', 'uang', 'jin', 'guang')
// ('jing', 'ue', 'jin', 'gue')
// ('jing', 'ui', 'jin', 'gui')
// ('jing', 'un', 'jin', 'gun')
// ('jing', 'uo', 'jin', 'guo')
// ('jing', 'v', 'jin', 'gv')
// ('jiong', 'eng', 'jion', 'geng')
// ('jiong', 'i', 'jion', 'gi')
// ('jiong', 'ia', 'jion', 'gia')
// ('jiong', 'ian', 'jion', 'gian')
// ('jiong', 'iang', 'jion', 'giang')
// ('jiong', 'iao', 'jion', 'giao')
// ('jiong', 'ie', 'jion', 'gie')
// ('jiong', 'in', 'jion', 'gin')
// ('jiong', 'ing', 'jion', 'ging')
// ('jiong', 'iong', 'jion', 'giong')
// ('jiong', 'iu', 'jion', 'giu')
// ('jiong', 'ong', 'jion', 'gong')
// ('jiong', 'u', 'jion', 'gu')
// ('jiong', 'ua', 'jion', 'gua')
// ('jiong', 'uai', 'jion', 'guai')
// ('jiong', 'uan', 'jion', 'guan')
// ('jiong', 'uang', 'jion', 'guang')
// ('jiong', 'ue', 'jion', 'gue')
// ('jiong', 'ui', 'jion', 'gui')
// ('jiong', 'un', 'jion', 'gun')
// ('jiong', 'uo', 'jion', 'guo')
// ('jiong', 'v', 'jion', 'gv')
// ('juan', 'eng', 'jua', 'neng')
// ('juan', 'i', 'jua', 'ni')
// ('juan', 'ia', 'jua', 'nia')
// ('juan', 'ian', 'jua', 'nian')
// ('juan', 'iang', 'jua', 'niang')
// ('juan', 'iao', 'jua', 'niao')
// ('juan', 'ie', 'jua', 'nie')
// ('juan', 'in', 'jua', 'nin')
// ('juan', 'ing', 'jua', 'ning')
// ('juan', 'iong', 'jua', 'niong')
// ('juan', 'iu', 'jua', 'niu')
// ('juan', 'ong', 'jua', 'nong')
// ('juan', 'u', 'jua', 'nu')
// ('juan', 'ua', 'jua', 'nua')
// ('juan', 'uai', 'jua', 'nuai')
// ('juan', 'uan', 'jua', 'nuan')
// ('juan', 'uang', 'jua', 'nuang')
// ('juan', 'ue', 'jua', 'nue')
// ('juan', 'ui', 'jua', 'nui')
// ('juan', 'un', 'jua', 'nun')
// ('juan', 'uo', 'jua', 'nuo')
// ('juan', 'v', 'jua', 'nv')
// ('jun', 'a', 'ju', 'na')
// ('jun', 'ai', 'ju', 'nai')
// ('jun', 'e', 'ju', 'ne')
// ('jun', 'ei', 'ju', 'nei')
// ('jun', 'eng', 'ju', 'neng')
// ('jun', 'i', 'ju', 'ni')
// ('jun', 'ia', 'ju', 'nia')
// ('jun', 'ian', 'ju', 'nian')
// ('jun', 'iang', 'ju', 'niang')
// ('jun', 'iao', 'ju', 'niao')
// ('jun', 'ie', 'ju', 'nie')
// ('jun', 'in', 'ju', 'nin')
// ('jun', 'ing', 'ju', 'ning')
// ('jun', 'iong', 'ju', 'niong')
// ('jun', 'iu', 'ju', 'niu')
// ('jun', 'ong', 'ju', 'nong')
// ('jun', 'u', 'ju', 'nu')
// ('jun', 'ua', 'ju', 'nua')
// ('jun', 'uai', 'ju', 'nuai')
// ('jun', 'uan', 'ju', 'nuan')
// ('jun', 'uang', 'ju', 'nuang')
// ('jun', 'ue', 'ju', 'nue')
// ('jun', 'ui', 'ju', 'nui')
// ('jun', 'un', 'ju', 'nun')
// ('jun', 'uo', 'ju', 'nuo')
// ('jun', 'v', 'ju', 'nv')
// ('kan', 'ei', 'ka', 'nei')
// ('kan', 'eng', 'ka', 'neng')
// ('kan', 'i', 'ka', 'ni')
// ('kan', 'ia', 'ka', 'nia')
// ('kan', 'ian', 'ka', 'nian')
// ('kan', 'iang', 'ka', 'niang')
// ('kan', 'iao', 'ka', 'niao')
// ('kan', 'ie', 'ka', 'nie')
// ('kan', 'in', 'ka', 'nin')
// ('kan', 'ing', 'ka', 'ning')
// ('kan', 'iong', 'ka', 'niong')
// ('kan', 'iu', 'ka', 'niu')
// ('kan', 'ong', 'ka', 'nong')
// ('kan', 'u', 'ka', 'nu')
// ('kan', 'ua', 'ka', 'nua')
// ('kan', 'uai', 'ka', 'nuai')
// ('kan', 'uan', 'ka', 'nuan')
// ('kan', 'uang', 'ka', 'nuang')
// ('kan', 'ue', 'ka', 'nue')
// ('kan', 'ui', 'ka', 'nui')
// ('kan', 'un', 'ka', 'nun')
// ('kan', 'uo', 'ka', 'nuo')
// ('kan', 'v', 'ka', 'nv')
// ('kang', 'a', 'kan', 'ga')
// ('kang', 'an', 'kan', 'gan')
// ('kang', 'ang', 'kan', 'gang')
// ('kang', 'ao', 'kan', 'gao')
// ('kang', 'e', 'kan', 'ge')
// ('kang', 'ei', 'kan', 'gei')
// ('kang', 'en', 'kan', 'gen')
// ('kang', 'eng', 'kan', 'geng')
// ('kang', 'i', 'kan', 'gi')
// ('kang', 'ia', 'kan', 'gia')
// ('kang', 'ian', 'kan', 'gian')
// ('kang', 'iang', 'kan', 'giang')
// ('kang', 'iao', 'kan', 'giao')
// ('kang', 'ie', 'kan', 'gie')
// ('kang', 'in', 'kan', 'gin')
// ('kang', 'ing', 'kan', 'ging')
// ('kang', 'iong', 'kan', 'giong')
// ('kang', 'iu', 'kan', 'giu')
// ('kang', 'ong', 'kan', 'gong')
// ('kang', 'ou', 'kan', 'gou')
// ('kang', 'u', 'kan', 'gu')
// ('kang', 'ua', 'kan', 'gua')
// ('kang', 'uai', 'kan', 'guai')
// ('kang', 'uan', 'kan', 'guan')
// ('kang', 'uang', 'kan', 'guang')
// ('kang', 'ue', 'kan', 'gue')
// ('kang', 'ui', 'kan', 'gui')
// ('kang', 'un', 'kan', 'gun')
// ('kang', 'uo', 'kan', 'guo')
// ('kang', 'v', 'kan', 'gv')
// ('ken', 'a', 'ke', 'na')
// ('ken', 'ai', 'ke', 'nai')
// ('ken', 'an', 'ke', 'nan')
// ('ken', 'ao', 'ke', 'nao')
// ('ken', 'e', 'ke', 'ne')
// ('ken', 'ei', 'ke', 'nei')
// ('ken', 'eng', 'ke', 'neng')
// ('ken', 'i', 'ke', 'ni')
// ('ken', 'ia', 'ke', 'nia')
// ('ken', 'ian', 'ke', 'nian')
// ('ken', 'iang', 'ke', 'niang')
// ('ken', 'iao', 'ke', 'niao')
// ('ken', 'ie', 'ke', 'nie')
// ('ken', 'in', 'ke', 'nin')
// ('ken', 'ing', 'ke', 'ning')
// ('ken', 'iong', 'ke', 'niong')
// ('ken', 'iu', 'ke', 'niu')
// ('ken', 'ong', 'ke', 'nong')
// ('ken', 'u', 'ke', 'nu')
// ('ken', 'ua', 'ke', 'nua')
// ('ken', 'uai', 'ke', 'nuai')
// ('ken', 'uan', 'ke', 'nuan')
// ('ken', 'uang', 'ke', 'nuang')
// ('ken', 'ue', 'ke', 'nue')
// ('ken', 'ui', 'ke', 'nui')
// ('ken', 'un', 'ke', 'nun')
// ('ken', 'uo', 'ke', 'nuo')
// ('ken', 'v', 'ke', 'nv')
// ('keng', 'a', 'ken', 'ga')
// ('keng', 'ai', 'ken', 'gai')
// ('keng', 'an', 'ken', 'gan')
// ('keng', 'ang', 'ken', 'gang')
// ('keng', 'ao', 'ken', 'gao')
// ('keng', 'e', 'ken', 'ge')
// ('keng', 'ei', 'ken', 'gei')
// ('keng', 'en', 'ken', 'gen')
// ('keng', 'eng', 'ken', 'geng')
// ('keng', 'i', 'ken', 'gi')
// ('keng', 'ia', 'ken', 'gia')
// ('keng', 'ian', 'ken', 'gian')
// ('keng', 'iang', 'ken', 'giang')
// ('keng', 'iao', 'ken', 'giao')
// ('keng', 'ie', 'ken', 'gie')
// ('keng', 'in', 'ken', 'gin')
// ('keng', 'ing', 'ken', 'ging')
// ('keng', 'iong', 'ken', 'giong')
// ('keng', 'iu', 'ken', 'giu')
// ('keng', 'ong', 'ken', 'gong')
// ('keng', 'ou', 'ken', 'gou')
// ('keng', 'u', 'ken', 'gu')
// ('keng', 'ua', 'ken', 'gua')
// ('keng', 'uai', 'ken', 'guai')
// ('keng', 'uan', 'ken', 'guan')
// ('keng', 'uang', 'ken', 'guang')
// ('keng', 'ue', 'ken', 'gue')
// ('keng', 'ui', 'ken', 'gui')
// ('keng', 'un', 'ken', 'gun')
// ('keng', 'uo', 'ken', 'guo')
// ('keng', 'v', 'ken', 'gv')
// ('kong', 'eng', 'kon', 'geng')
// ('kong', 'i', 'kon', 'gi')
// ('kong', 'ia', 'kon', 'gia')
// ('kong', 'ian', 'kon', 'gian')
// ('kong', 'iang', 'kon', 'giang')
// ('kong', 'iao', 'kon', 'giao')
// ('kong', 'ie', 'kon', 'gie')
// ('kong', 'in', 'kon', 'gin')
// ('kong', 'ing', 'kon', 'ging')
// ('kong', 'iong', 'kon', 'giong')
// ('kong', 'iu', 'kon', 'giu')
// ('kong', 'ong', 'kon', 'gong')
// ('kong', 'u', 'kon', 'gu')
// ('kong', 'ua', 'kon', 'gua')
// ('kong', 'uai', 'kon', 'guai')
// ('kong', 'uan', 'kon', 'guan')
// ('kong', 'uang', 'kon', 'guang')
// ('kong', 'ue', 'kon', 'gue')
// ('kong', 'ui', 'kon', 'gui')
// ('kong', 'un', 'kon', 'gun')
// ('kong', 'uo', 'kon', 'guo')
// ('kong', 'v', 'kon', 'gv')
// ('kuan', 'a', 'kua', 'na')
// ('kuan', 'ei', 'kua', 'nei')
// ('kuan', 'eng', 'kua', 'neng')
// ('kuan', 'i', 'kua', 'ni')
// ('kuan', 'ia', 'kua', 'nia')
// ('kuan', 'ian', 'kua', 'nian')
// ('kuan', 'iang', 'kua', 'niang')
// ('kuan', 'iao', 'kua', 'niao')
// ('kuan', 'ie', 'kua', 'nie')
// ('kuan', 'in', 'kua', 'nin')
// ('kuan', 'ing', 'kua', 'ning')
// ('kuan', 'iong', 'kua', 'niong')
// ('kuan', 'iu', 'kua', 'niu')
// ('kuan', 'ong', 'kua', 'nong')
// ('kuan', 'u', 'kua', 'nu')
// ('kuan', 'ua', 'kua', 'nua')
// ('kuan', 'uai', 'kua', 'nuai')
// ('kuan', 'uan', 'kua', 'nuan')
// ('kuan', 'uang', 'kua', 'nuang')
// ('kuan', 'ue', 'kua', 'nue')
// ('kuan', 'ui', 'kua', 'nui')
// ('kuan', 'un', 'kua', 'nun')
// ('kuan', 'uo', 'kua', 'nuo')
// ('kuan', 'v', 'kua', 'nv')
// ('kuang', 'ang', 'kuan', 'gang')
// ('kuang', 'e', 'kuan', 'ge')
// ('kuang', 'ei', 'kuan', 'gei')
// ('kuang', 'en', 'kuan', 'gen')
// ('kuang', 'eng', 'kuan', 'geng')
// ('kuang', 'i', 'kuan', 'gi')
// ('kuang', 'ia', 'kuan', 'gia')
// ('kuang', 'ian', 'kuan', 'gian')
// ('kuang', 'iang', 'kuan', 'giang')
// ('kuang', 'iao', 'kuan', 'giao')
// ('kuang', 'ie', 'kuan', 'gie')
// ('kuang', 'in', 'kuan', 'gin')
// ('kuang', 'ing', 'kuan', 'ging')
// ('kuang', 'iong', 'kuan', 'giong')
// ('kuang', 'iu', 'kuan', 'giu')
// ('kuang', 'ong', 'kuan', 'gong')
// ('kuang', 'u', 'kuan', 'gu')
// ('kuang', 'ua', 'kuan', 'gua')
// ('kuang', 'uai', 'kuan', 'guai')
// ('kuang', 'uan', 'kuan', 'guan')
// ('kuang', 'uang', 'kuan', 'guang')
// ('kuang', 'ue', 'kuan', 'gue')
// ('kuang', 'ui', 'kuan', 'gui')
// ('kuang', 'un', 'kuan', 'gun')
// ('kuang', 'uo', 'kuan', 'guo')
// ('kuang', 'v', 'kuan', 'gv')
// ('kun', 'an', 'ku', 'nan')
// ('kun', 'ao', 'ku', 'nao')
// ('kun', 'e', 'ku', 'ne')
// ('kun', 'ei', 'ku', 'nei')
// ('kun', 'eng', 'ku', 'neng')
// ('kun', 'i', 'ku', 'ni')
// ('kun', 'ia', 'ku', 'nia')
// ('kun', 'ian', 'ku', 'nian')
// ('kun', 'iang', 'ku', 'niang')
// ('kun', 'iao', 'ku', 'niao')
// ('kun', 'ie', 'ku', 'nie')
// ('kun', 'in', 'ku', 'nin')
// ('kun', 'ing', 'ku', 'ning')
// ('kun', 'iong', 'ku', 'niong')
// ('kun', 'iu', 'ku', 'niu')
// ('kun', 'ong', 'ku', 'nong')
// ('kun', 'u', 'ku', 'nu')
// ('kun', 'ua', 'ku', 'nua')
// ('kun', 'uai', 'ku', 'nuai')
// ('kun', 'uan', 'ku', 'nuan')
// ('kun', 'uang', 'ku', 'nuang')
// ('kun', 'ue', 'ku', 'nue')
// ('kun', 'ui', 'ku', 'nui')
// ('kun', 'un', 'ku', 'nun')
// ('kun', 'uo', 'ku', 'nuo')
// ('kun', 'v', 'ku', 'nv')
// ('lan', 'a', 'la', 'na')
// ('lan', 'ei', 'la', 'nei')
// ('lan', 'eng', 'la', 'neng')
// ('lan', 'i', 'la', 'ni')
// ('lan', 'ia', 'la', 'nia')
// ('lan', 'ian', 'la', 'nian')
// ('lan', 'iang', 'la', 'niang')
// ('lan', 'iao', 'la', 'niao')
// ('lan', 'ie', 'la', 'nie')
// ('lan', 'in', 'la', 'nin')
// ('lan', 'ing', 'la', 'ning')
// ('lan', 'iong', 'la', 'niong')
// ('lan', 'iu', 'la', 'niu')
// ('lan', 'ong', 'la', 'nong')
// ('lan', 'u', 'la', 'nu')
// ('lan', 'ua', 'la', 'nua')
// ('lan', 'uai', 'la', 'nuai')
// ('lan', 'uan', 'la', 'nuan')
// ('lan', 'uang', 'la', 'nuang')
// ('lan', 'ue', 'la', 'nue')
// ('lan', 'ui', 'la', 'nui')
// ('lan', 'un', 'la', 'nun')
// ('lan', 'uo', 'la', 'nuo')
// ('lan', 'v', 'la', 'nv')
// ('lang', 'ai', 'lan', 'gai')
// ('lang', 'an', 'lan', 'gan')
// ('lang', 'ang', 'lan', 'gang')
// ('lang', 'ao', 'lan', 'gao')
// ('lang', 'e', 'lan', 'ge')
// ('lang', 'ei', 'lan', 'gei')
// ('lang', 'en', 'lan', 'gen')
// ('lang', 'eng', 'lan', 'geng')
// ('lang', 'i', 'lan', 'gi')
// ('lang', 'ia', 'lan', 'gia')
// ('lang', 'ian', 'lan', 'gian')
// ('lang', 'iang', 'lan', 'giang')
// ('lang', 'iao', 'lan', 'giao')
// ('lang', 'ie', 'lan', 'gie')
// ('lang', 'in', 'lan', 'gin')
// ('lang', 'ing', 'lan', 'ging')
// ('lang', 'iong', 'lan', 'giong')
// ('lang', 'iu', 'lan', 'giu')
// ('lang', 'ong', 'lan', 'gong')
// ('lang', 'ou', 'lan', 'gou')
// ('lang', 'u', 'lan', 'gu')
// ('lang', 'ua', 'lan', 'gua')
// ('lang', 'uai', 'lan', 'guai')
// ('lang', 'uan', 'lan', 'guan')
// ('lang', 'uang', 'lan', 'guang')
// ('lang', 'ue', 'lan', 'gue')
// ('lang', 'ui', 'lan', 'gui')
// ('lang', 'un', 'lan', 'gun')
// ('lang', 'uo', 'lan', 'guo')
// ('lang', 'v', 'lan', 'gv')
// ('leng', 'eng', 'len', 'geng')
// ('leng', 'i', 'len', 'gi')
// ('leng', 'ia', 'len', 'gia')
// ('leng', 'ian', 'len', 'gian')
// ('leng', 'iang', 'len', 'giang')
// ('leng', 'iao', 'len', 'giao')
// ('leng', 'ie', 'len', 'gie')
// ('leng', 'in', 'len', 'gin')
// ('leng', 'ing', 'len', 'ging')
// ('leng', 'iong', 'len', 'giong')
// ('leng', 'iu', 'len', 'giu')
// ('leng', 'ong', 'len', 'gong')
// ('leng', 'u', 'len', 'gu')
// ('leng', 'ua', 'len', 'gua')
// ('leng', 'uai', 'len', 'guai')
// ('leng', 'uan', 'len', 'guan')
// ('leng', 'uang', 'len', 'guang')
// ('leng', 'ue', 'len', 'gue')
// ('leng', 'ui', 'len', 'gui')
// ('leng', 'un', 'len', 'gun')
// ('leng', 'uo', 'len', 'guo')
// ('leng', 'v', 'len', 'gv')
// ('lian', 'ei', 'lia', 'nei')
// ('lian', 'eng', 'lia', 'neng')
// ('lian', 'i', 'lia', 'ni')
// ('lian', 'ia', 'lia', 'nia')
// ('lian', 'ian', 'lia', 'nian')
// ('lian', 'iang', 'lia', 'niang')
// ('lian', 'iao', 'lia', 'niao')
// ('lian', 'ie', 'lia', 'nie')
// ('lian', 'in', 'lia', 'nin')
// ('lian', 'ing', 'lia', 'ning')
// ('lian', 'iong', 'lia', 'niong')
// ('lian', 'iu', 'lia', 'niu')
// ('lian', 'ong', 'lia', 'nong')
// ('lian', 'u', 'lia', 'nu')
// ('lian', 'ua', 'lia', 'nua')
// ('lian', 'uai', 'lia', 'nuai')
// ('lian', 'uan', 'lia', 'nuan')
// ('lian', 'uang', 'lia', 'nuang')
// ('lian', 'ue', 'lia', 'nue')
// ('lian', 'ui', 'lia', 'nui')
// ('lian', 'un', 'lia', 'nun')
// ('lian', 'uo', 'lia', 'nuo')
// ('lian', 'v', 'lia', 'nv')
// ('liang', 'ai', 'lian', 'gai')
// ('liang', 'ang', 'lian', 'gang')
// ('liang', 'ao', 'lian', 'gao')
// ('liang', 'e', 'lian', 'ge')
// ('liang', 'ei', 'lian', 'gei')
// ('liang', 'en', 'lian', 'gen')
// ('liang', 'eng', 'lian', 'geng')
// ('liang', 'i', 'lian', 'gi')
// ('liang', 'ia', 'lian', 'gia')
// ('liang', 'ian', 'lian', 'gian')
// ('liang', 'iang', 'lian', 'giang')
// ('liang', 'iao', 'lian', 'giao')
// ('liang', 'ie', 'lian', 'gie')
// ('liang', 'in', 'lian', 'gin')
// ('liang', 'ing', 'lian', 'ging')
// ('liang', 'iong', 'lian', 'giong')
// ('liang', 'iu', 'lian', 'giu')
// ('liang', 'ong', 'lian', 'gong')
// ('liang', 'ou', 'lian', 'gou')
// ('liang', 'u', 'lian', 'gu')
// ('liang', 'ua', 'lian', 'gua')
// ('liang', 'uai', 'lian', 'guai')
// ('liang', 'uan', 'lian', 'guan')
// ('liang', 'uang', 'lian', 'guang')
// ('liang', 'ue', 'lian', 'gue')
// ('liang', 'ui', 'lian', 'gui')
// ('liang', 'un', 'lian', 'gun')
// ('liang', 'uo', 'lian', 'guo')
// ('liang', 'v', 'lian', 'gv')
// ('lin', 'a', 'li', 'na')
// ('lin', 'ai', 'li', 'nai')
// ('lin', 'an', 'li', 'nan')
// ('lin', 'ao', 'li', 'nao')
// ('lin', 'e', 'li', 'ne')
// ('lin', 'ei', 'li', 'nei')
// ('lin', 'eng', 'li', 'neng')
// ('lin', 'i', 'li', 'ni')
// ('lin', 'ia', 'li', 'nia')
// ('lin', 'ian', 'li', 'nian')
// ('lin', 'iang', 'li', 'niang')
// ('lin', 'iao', 'li', 'niao')
// ('lin', 'ie', 'li', 'nie')
// ('lin', 'in', 'li', 'nin')
// ('lin', 'ing', 'li', 'ning')
// ('lin', 'iong', 'li', 'niong')
// ('lin', 'iu', 'li', 'niu')
// ('lin', 'ong', 'li', 'nong')
// ('lin', 'u', 'li', 'nu')
// ('lin', 'ua', 'li', 'nua')
// ('lin', 'uai', 'li', 'nuai')
// ('lin', 'uan', 'li', 'nuan')
// ('lin', 'uang', 'li', 'nuang')
// ('lin', 'ue', 'li', 'nue')
// ('lin', 'ui', 'li', 'nui')
// ('lin', 'un', 'li', 'nun')
// ('lin', 'uo', 'li', 'nuo')
// ('lin', 'v', 'li', 'nv')
// ('ling', 'ang', 'lin', 'gang')
// ('ling', 'ao', 'lin', 'gao')
// ('ling', 'e', 'lin', 'ge')
// ('ling', 'ei', 'lin', 'gei')
// ('ling', 'en', 'lin', 'gen')
// ('ling', 'eng', 'lin', 'geng')
// ('ling', 'i', 'lin', 'gi')
// ('ling', 'ia', 'lin', 'gia')
// ('ling', 'ian', 'lin', 'gian')
// ('ling', 'iang', 'lin', 'giang')
// ('ling', 'iao', 'lin', 'giao')
// ('ling', 'ie', 'lin', 'gie')
// ('ling', 'in', 'lin', 'gin')
// ('ling', 'ing', 'lin', 'ging')
// ('ling', 'iong', 'lin', 'giong')
// ('ling', 'iu', 'lin', 'giu')
// ('ling', 'ong', 'lin', 'gong')
// ('ling', 'u', 'lin', 'gu')
// ('ling', 'ua', 'lin', 'gua')
// ('ling', 'uai', 'lin', 'guai')
// ('ling', 'uan', 'lin', 'guan')
// ('ling', 'uang', 'lin', 'guang')
// ('ling', 'ue', 'lin', 'gue')
// ('ling', 'ui', 'lin', 'gui')
// ('ling', 'un', 'lin', 'gun')
// ('ling', 'uo', 'lin', 'guo')
// ('ling', 'v', 'lin', 'gv')
// ('long', 'eng', 'lon', 'geng')
// ('long', 'i', 'lon', 'gi')
// ('long', 'ia', 'lon', 'gia')
// ('long', 'ian', 'lon', 'gian')
// ('long', 'iang', 'lon', 'giang')
// ('long', 'iao', 'lon', 'giao')
// ('long', 'ie', 'lon', 'gie')
// ('long', 'in', 'lon', 'gin')
// ('long', 'ing', 'lon', 'ging')
// ('long', 'iong', 'lon', 'giong')
// ('long', 'iu', 'lon', 'giu')
// ('long', 'ong', 'lon', 'gong')
// ('long', 'u', 'lon', 'gu')
// ('long', 'ua', 'lon', 'gua')
// ('long', 'uai', 'lon', 'guai')
// ('long', 'uan', 'lon', 'guan')
// ('long', 'uang', 'lon', 'guang')
// ('long', 'ue', 'lon', 'gue')
// ('long', 'ui', 'lon', 'gui')
// ('long', 'un', 'lon', 'gun')
// ('long', 'uo', 'lon', 'guo')
// ('long', 'v', 'lon', 'gv')
// ('luan', 'eng', 'lua', 'neng')
// ('luan', 'i', 'lua', 'ni')
// ('luan', 'ia', 'lua', 'nia')
// ('luan', 'ian', 'lua', 'nian')
// ('luan', 'iang', 'lua', 'niang')
// ('luan', 'iao', 'lua', 'niao')
// ('luan', 'ie', 'lua', 'nie')
// ('luan', 'in', 'lua', 'nin')
// ('luan', 'ing', 'lua', 'ning')
// ('luan', 'iong', 'lua', 'niong')
// ('luan', 'iu', 'lua', 'niu')
// ('luan', 'ong', 'lua', 'nong')
// ('luan', 'u', 'lua', 'nu')
// ('luan', 'ua', 'lua', 'nua')
// ('luan', 'uai', 'lua', 'nuai')
// ('luan', 'uan', 'lua', 'nuan')
// ('luan', 'uang', 'lua', 'nuang')
// ('luan', 'ue', 'lua', 'nue')
// ('luan', 'ui', 'lua', 'nui')
// ('luan', 'un', 'lua', 'nun')
// ('luan', 'uo', 'lua', 'nuo')
// ('luan', 'v', 'lua', 'nv')
// ('lun', 'a', 'lu', 'na')
// ('lun', 'ai', 'lu', 'nai')
// ('lun', 'an', 'lu', 'nan')
// ('lun', 'ao', 'lu', 'nao')
// ('lun', 'e', 'lu', 'ne')
// ('lun', 'ei', 'lu', 'nei')
// ('lun', 'eng', 'lu', 'neng')
// ('lun', 'i', 'lu', 'ni')
// ('lun', 'ia', 'lu', 'nia')
// ('lun', 'ian', 'lu', 'nian')
// ('lun', 'iang', 'lu', 'niang')
// ('lun', 'iao', 'lu', 'niao')
// ('lun', 'ie', 'lu', 'nie')
// ('lun', 'in', 'lu', 'nin')
// ('lun', 'ing', 'lu', 'ning')
// ('lun', 'iong', 'lu', 'niong')
// ('lun', 'iu', 'lu', 'niu')
// ('lun', 'ong', 'lu', 'nong')
// ('lun', 'u', 'lu', 'nu')
// ('lun', 'ua', 'lu', 'nua')
// ('lun', 'uai', 'lu', 'nuai')
// ('lun', 'uan', 'lu', 'nuan')
// ('lun', 'uang', 'lu', 'nuang')
// ('lun', 'ue', 'lu', 'nue')
// ('lun', 'ui', 'lu', 'nui')
// ('lun', 'un', 'lu', 'nun')
// ('lun', 'uo', 'lu', 'nuo')
// ('lun', 'v', 'lu', 'nv')
// ('man', 'ai', 'ma', 'nai')
// ('man', 'an', 'ma', 'nan')
// ('man', 'ao', 'ma', 'nao')
// ('man', 'e', 'ma', 'ne')
// ('man', 'ei', 'ma', 'nei')
// ('man', 'eng', 'ma', 'neng')
// ('man', 'i', 'ma', 'ni')
// ('man', 'ia', 'ma', 'nia')
// ('man', 'ian', 'ma', 'nian')
// ('man', 'iang', 'ma', 'niang')
// ('man', 'iao', 'ma', 'niao')
// ('man', 'ie', 'ma', 'nie')
// ('man', 'in', 'ma', 'nin')
// ('man', 'ing', 'ma', 'ning')
// ('man', 'iong', 'ma', 'niong')
// ('man', 'iu', 'ma', 'niu')
// ('man', 'ong', 'ma', 'nong')
// ('man', 'u', 'ma', 'nu')
// ('man', 'ua', 'ma', 'nua')
// ('man', 'uai', 'ma', 'nuai')
// ('man', 'uan', 'ma', 'nuan')
// ('man', 'uang', 'ma', 'nuang')
// ('man', 'ue', 'ma', 'nue')
// ('man', 'ui', 'ma', 'nui')
// ('man', 'un', 'ma', 'nun')
// ('man', 'uo', 'ma', 'nuo')
// ('man', 'v', 'ma', 'nv')
// ('mang', 'ai', 'man', 'gai')
// ('mang', 'an', 'man', 'gan')
// ('mang', 'ang', 'man', 'gang')
// ('mang', 'ao', 'man', 'gao')
// ('mang', 'e', 'man', 'ge')
// ('mang', 'ei', 'man', 'gei')
// ('mang', 'en', 'man', 'gen')
// ('mang', 'eng', 'man', 'geng')
// ('mang', 'i', 'man', 'gi')
// ('mang', 'ia', 'man', 'gia')
// ('mang', 'ian', 'man', 'gian')
// ('mang', 'iang', 'man', 'giang')
// ('mang', 'iao', 'man', 'giao')
// ('mang', 'ie', 'man', 'gie')
// ('mang', 'in', 'man', 'gin')
// ('mang', 'ing', 'man', 'ging')
// ('mang', 'iong', 'man', 'giong')
// ('mang', 'iu', 'man', 'giu')
// ('mang', 'ong', 'man', 'gong')
// ('mang', 'ou', 'man', 'gou')
// ('mang', 'u', 'man', 'gu')
// ('mang', 'ua', 'man', 'gua')
// ('mang', 'uai', 'man', 'guai')
// ('mang', 'uan', 'man', 'guan')
// ('mang', 'uang', 'man', 'guang')
// ('mang', 'ue', 'man', 'gue')
// ('mang', 'ui', 'man', 'gui')
// ('mang', 'un', 'man', 'gun')
// ('mang', 'uo', 'man', 'guo')
// ('mang', 'v', 'man', 'gv')
// ('men', 'e', 'me', 'ne')
// ('men', 'ei', 'me', 'nei')
// ('men', 'eng', 'me', 'neng')
// ('men', 'i', 'me', 'ni')
// ('men', 'ia', 'me', 'nia')
// ('men', 'ian', 'me', 'nian')
// ('men', 'iang', 'me', 'niang')
// ('men', 'iao', 'me', 'niao')
// ('men', 'ie', 'me', 'nie')
// ('men', 'in', 'me', 'nin')
// ('men', 'ing', 'me', 'ning')
// ('men', 'iong', 'me', 'niong')
// ('men', 'iu', 'me', 'niu')
// ('men', 'ong', 'me', 'nong')
// ('men', 'u', 'me', 'nu')
// ('men', 'ua', 'me', 'nua')
// ('men', 'uai', 'me', 'nuai')
// ('men', 'uan', 'me', 'nuan')
// ('men', 'uang', 'me', 'nuang')
// ('men', 'ue', 'me', 'nue')
// ('men', 'ui', 'me', 'nui')
// ('men', 'un', 'me', 'nun')
// ('men', 'uo', 'me', 'nuo')
// ('men', 'v', 'me', 'nv')
// ('meng', 'ai', 'men', 'gai')
// ('meng', 'ang', 'men', 'gang')
// ('meng', 'ao', 'men', 'gao')
// ('meng', 'e', 'men', 'ge')
// ('meng', 'ei', 'men', 'gei')
// ('meng', 'eng', 'men', 'geng')
// ('meng', 'i', 'men', 'gi')
// ('meng', 'ia', 'men', 'gia')
// ('meng', 'ian', 'men', 'gian')
// ('meng', 'iang', 'men', 'giang')
// ('meng', 'iao', 'men', 'giao')
// ('meng', 'ie', 'men', 'gie')
// ('meng', 'in', 'men', 'gin')
// ('meng', 'ing', 'men', 'ging')
// ('meng', 'iong', 'men', 'giong')
// ('meng', 'iu', 'men', 'giu')
// ('meng', 'ong', 'men', 'gong')
// ('meng', 'ou', 'men', 'gou')
// ('meng', 'u', 'men', 'gu')
// ('meng', 'ua', 'men', 'gua')
// ('meng', 'uai', 'men', 'guai')
// ('meng', 'uan', 'men', 'guan')
// ('meng', 'uang', 'men', 'guang')
// ('meng', 'ue', 'men', 'gue')
// ('meng', 'ui', 'men', 'gui')
// ('meng', 'un', 'men', 'gun')
// ('meng', 'uo', 'men', 'guo')
// ('meng', 'v', 'men', 'gv')
// ('mian', 'eng', 'mia', 'neng')
// ('mian', 'i', 'mia', 'ni')
// ('mian', 'ia', 'mia', 'nia')
// ('mian', 'ian', 'mia', 'nian')
// ('mian', 'iang', 'mia', 'niang')
// ('mian', 'iao', 'mia', 'niao')
// ('mian', 'ie', 'mia', 'nie')
// ('mian', 'in', 'mia', 'nin')
// ('mian', 'ing', 'mia', 'ning')
// ('mian', 'iong', 'mia', 'niong')
// ('mian', 'iu', 'mia', 'niu')
// ('mian', 'ong', 'mia', 'nong')
// ('mian', 'u', 'mia', 'nu')
// ('mian', 'ua', 'mia', 'nua')
// ('mian', 'uai', 'mia', 'nuai')
// ('mian', 'uan', 'mia', 'nuan')
// ('mian', 'uang', 'mia', 'nuang')
// ('mian', 'ue', 'mia', 'nue')
// ('mian', 'ui', 'mia', 'nui')
// ('mian', 'un', 'mia', 'nun')
// ('mian', 'uo', 'mia', 'nuo')
// ('mian', 'v', 'mia', 'nv')
// ('min', 'a', 'mi', 'na')
// ('min', 'ei', 'mi', 'nei')
// ('min', 'eng', 'mi', 'neng')
// ('min', 'i', 'mi', 'ni')
// ('min', 'ia', 'mi', 'nia')
// ('min', 'ian', 'mi', 'nian')
// ('min', 'iang', 'mi', 'niang')
// ('min', 'iao', 'mi', 'niao')
// ('min', 'ie', 'mi', 'nie')
// ('min', 'in', 'mi', 'nin')
// ('min', 'ing', 'mi', 'ning')
// ('min', 'iong', 'mi', 'niong')
// ('min', 'iu', 'mi', 'niu')
// ('min', 'ong', 'mi', 'nong')
// ('min', 'u', 'mi', 'nu')
// ('min', 'ua', 'mi', 'nua')
// ('min', 'uai', 'mi', 'nuai')
// ('min', 'uan', 'mi', 'nuan')
// ('min', 'uang', 'mi', 'nuang')
// ('min', 'ue', 'mi', 'nue')
// ('min', 'ui', 'mi', 'nui')
// ('min', 'un', 'mi', 'nun')
// ('min', 'uo', 'mi', 'nuo')
// ('min', 'v', 'mi', 'nv')
// ('ming', 'an', 'min', 'gan')
// ('ming', 'ang', 'min', 'gang')
// ('ming', 'ao', 'min', 'gao')
// ('ming', 'e', 'min', 'ge')
// ('ming', 'ei', 'min', 'gei')
// ('ming', 'eng', 'min', 'geng')
// ('ming', 'i', 'min', 'gi')
// ('ming', 'ia', 'min', 'gia')
// ('ming', 'ian', 'min', 'gian')
// ('ming', 'iang', 'min', 'giang')
// ('ming', 'iao', 'min', 'giao')
// ('ming', 'ie', 'min', 'gie')
// ('ming', 'in', 'min', 'gin')
// ('ming', 'ing', 'min', 'ging')
// ('ming', 'iong', 'min', 'giong')
// ('ming', 'iu', 'min', 'giu')
// ('ming', 'ong', 'min', 'gong')
// ('ming', 'u', 'min', 'gu')
// ('ming', 'ua', 'min', 'gua')
// ('ming', 'uai', 'min', 'guai')
// ('ming', 'uan', 'min', 'guan')
// ('ming', 'uang', 'min', 'guang')
// ('ming', 'ue', 'min', 'gue')
// ('ming', 'ui', 'min', 'gui')
// ('ming', 'un', 'min', 'gun')
// ('ming', 'uo', 'min', 'guo')
// ('ming', 'v', 'min', 'gv')
// ('nan', 'a', 'na', 'na')
// ('nan', 'e', 'na', 'ne')
// ('nan', 'ei', 'na', 'nei')
// ('nan', 'eng', 'na', 'neng')
// ('nan', 'i', 'na', 'ni')
// ('nan', 'ia', 'na', 'nia')
// ('nan', 'ian', 'na', 'nian')
// ('nan', 'iang', 'na', 'niang')
// ('nan', 'iao', 'na', 'niao')
// ('nan', 'ie', 'na', 'nie')
// ('nan', 'in', 'na', 'nin')
// ('nan', 'ing', 'na', 'ning')
// ('nan', 'iong', 'na', 'niong')
// ('nan', 'iu', 'na', 'niu')
// ('nan', 'ong', 'na', 'nong')
// ('nan', 'u', 'na', 'nu')
// ('nan', 'ua', 'na', 'nua')
// ('nan', 'uai', 'na', 'nuai')
// ('nan', 'uan', 'na', 'nuan')
// ('nan', 'uang', 'na', 'nuang')
// ('nan', 'ue', 'na', 'nue')
// ('nan', 'ui', 'na', 'nui')
// ('nan', 'un', 'na', 'nun')
// ('nan', 'uo', 'na', 'nuo')
// ('nan', 'v', 'na', 'nv')
// ('nang', 'a', 'nan', 'ga')
// ('nang', 'ai', 'nan', 'gai')
// ('nang', 'an', 'nan', 'gan')
// ('nang', 'ang', 'nan', 'gang')
// ('nang', 'ao', 'nan', 'gao')
// ('nang', 'e', 'nan', 'ge')
// ('nang', 'ei', 'nan', 'gei')
// ('nang', 'en', 'nan', 'gen')
// ('nang', 'eng', 'nan', 'geng')
// ('nang', 'i', 'nan', 'gi')
// ('nang', 'ia', 'nan', 'gia')
// ('nang', 'ian', 'nan', 'gian')
// ('nang', 'iang', 'nan', 'giang')
// ('nang', 'iao', 'nan', 'giao')
// ('nang', 'ie', 'nan', 'gie')
// ('nang', 'in', 'nan', 'gin')
// ('nang', 'ing', 'nan', 'ging')
// ('nang', 'iong', 'nan', 'giong')
// ('nang', 'iu', 'nan', 'giu')
// ('nang', 'ong', 'nan', 'gong')
// ('nang', 'ou', 'nan', 'gou')
// ('nang', 'u', 'nan', 'gu')
// ('nang', 'ua', 'nan', 'gua')
// ('nang', 'uai', 'nan', 'guai')
// ('nang', 'uan', 'nan', 'guan')
// ('nang', 'uang', 'nan', 'guang')
// ('nang', 'ue', 'nan', 'gue')
// ('nang', 'ui', 'nan', 'gui')
// ('nang', 'un', 'nan', 'gun')
// ('nang', 'uo', 'nan', 'guo')
// ('nang', 'v', 'nan', 'gv')
// ('nen', 'a', 'ne', 'na')
// ('nen', 'ai', 'ne', 'nai')
// ('nen', 'an', 'ne', 'nan')
// ('nen', 'ao', 'ne', 'nao')
// ('nen', 'e', 'ne', 'ne')
// ('nen', 'ei', 'ne', 'nei')
// ('nen', 'en', 'ne', 'nen')
// ('nen', 'eng', 'ne', 'neng')
// ('nen', 'i', 'ne', 'ni')
// ('nen', 'ia', 'ne', 'nia')
// ('nen', 'ian', 'ne', 'nian')
// ('nen', 'iang', 'ne', 'niang')
// ('nen', 'iao', 'ne', 'niao')
// ('nen', 'ie', 'ne', 'nie')
// ('nen', 'in', 'ne', 'nin')
// ('nen', 'ing', 'ne', 'ning')
// ('nen', 'iong', 'ne', 'niong')
// ('nen', 'iu', 'ne', 'niu')
// ('nen', 'ong', 'ne', 'nong')
// ('nen', 'u', 'ne', 'nu')
// ('nen', 'ua', 'ne', 'nua')
// ('nen', 'uai', 'ne', 'nuai')
// ('nen', 'uan', 'ne', 'nuan')
// ('nen', 'uang', 'ne', 'nuang')
// ('nen', 'ue', 'ne', 'nue')
// ('nen', 'ui', 'ne', 'nui')
// ('nen', 'un', 'ne', 'nun')
// ('nen', 'uo', 'ne', 'nuo')
// ('nen', 'v', 'ne', 'nv')
// ('neng', 'e', 'nen', 'ge')
// ('neng', 'ei', 'nen', 'gei')
// ('neng', 'eng', 'nen', 'geng')
// ('neng', 'i', 'nen', 'gi')
// ('neng', 'ia', 'nen', 'gia')
// ('neng', 'ian', 'nen', 'gian')
// ('neng', 'iang', 'nen', 'giang')
// ('neng', 'iao', 'nen', 'giao')
// ('neng', 'ie', 'nen', 'gie')
// ('neng', 'in', 'nen', 'gin')
// ('neng', 'ing', 'nen', 'ging')
// ('neng', 'iong', 'nen', 'giong')
// ('neng', 'iu', 'nen', 'giu')
// ('neng', 'ong', 'nen', 'gong')
// ('neng', 'u', 'nen', 'gu')
// ('neng', 'ua', 'nen', 'gua')
// ('neng', 'uai', 'nen', 'guai')
// ('neng', 'uan', 'nen', 'guan')
// ('neng', 'uang', 'nen', 'guang')
// ('neng', 'ue', 'nen', 'gue')
// ('neng', 'ui', 'nen', 'gui')
// ('neng', 'un', 'nen', 'gun')
// ('neng', 'uo', 'nen', 'guo')
// ('neng', 'v', 'nen', 'gv')
// ('nian', 'eng', 'nia', 'neng')
// ('nian', 'i', 'nia', 'ni')
// ('nian', 'ia', 'nia', 'nia')
// ('nian', 'ian', 'nia', 'nian')
// ('nian', 'iang', 'nia', 'niang')
// ('nian', 'iao', 'nia', 'niao')
// ('nian', 'ie', 'nia', 'nie')
// ('nian', 'in', 'nia', 'nin')
// ('nian', 'ing', 'nia', 'ning')
// ('nian', 'iong', 'nia', 'niong')
// ('nian', 'iu', 'nia', 'niu')
// ('nian', 'ong', 'nia', 'nong')
// ('nian', 'u', 'nia', 'nu')
// ('nian', 'ua', 'nia', 'nua')
// ('nian', 'uai', 'nia', 'nuai')
// ('nian', 'uan', 'nia', 'nuan')
// ('nian', 'uang', 'nia', 'nuang')
// ('nian', 'ue', 'nia', 'nue')
// ('nian', 'ui', 'nia', 'nui')
// ('nian', 'un', 'nia', 'nun')
// ('nian', 'uo', 'nia', 'nuo')
// ('nian', 'v', 'nia', 'nv')
// ('niang', 'ai', 'nian', 'gai')
// ('niang', 'an', 'nian', 'gan')
// ('niang', 'ang', 'nian', 'gang')
// ('niang', 'ao', 'nian', 'gao')
// ('niang', 'e', 'nian', 'ge')
// ('niang', 'ei', 'nian', 'gei')
// ('niang', 'en', 'nian', 'gen')
// ('niang', 'eng', 'nian', 'geng')
// ('niang', 'i', 'nian', 'gi')
// ('niang', 'ia', 'nian', 'gia')
// ('niang', 'ian', 'nian', 'gian')
// ('niang', 'iang', 'nian', 'giang')
// ('niang', 'iao', 'nian', 'giao')
// ('niang', 'ie', 'nian', 'gie')
// ('niang', 'in', 'nian', 'gin')
// ('niang', 'ing', 'nian', 'ging')
// ('niang', 'iong', 'nian', 'giong')
// ('niang', 'iu', 'nian', 'giu')
// ('niang', 'ong', 'nian', 'gong')
// ('niang', 'ou', 'nian', 'gou')
// ('niang', 'u', 'nian', 'gu')
// ('niang', 'ua', 'nian', 'gua')
// ('niang', 'uai', 'nian', 'guai')
// ('niang', 'uan', 'nian', 'guan')
// ('niang', 'uang', 'nian', 'guang')
// ('niang', 'ue', 'nian', 'gue')
// ('niang', 'ui', 'nian', 'gui')
// ('niang', 'un', 'nian', 'gun')
// ('niang', 'uo', 'nian', 'guo')
// ('niang', 'v', 'nian', 'gv')
// ('nin', 'a', 'ni', 'na')
// ('nin', 'an', 'ni', 'nan')
// ('nin', 'ao', 'ni', 'nao')
// ('nin', 'e', 'ni', 'ne')
// ('nin', 'ei', 'ni', 'nei')
// ('nin', 'eng', 'ni', 'neng')
// ('nin', 'i', 'ni', 'ni')
// ('nin', 'ia', 'ni', 'nia')
// ('nin', 'ian', 'ni', 'nian')
// ('nin', 'iang', 'ni', 'niang')
// ('nin', 'iao', 'ni', 'niao')
// ('nin', 'ie', 'ni', 'nie')
// ('nin', 'in', 'ni', 'nin')
// ('nin', 'ing', 'ni', 'ning')
// ('nin', 'iong', 'ni', 'niong')
// ('nin', 'iu', 'ni', 'niu')
// ('nin', 'ong', 'ni', 'nong')
// ('nin', 'u', 'ni', 'nu')
// ('nin', 'ua', 'ni', 'nua')
// ('nin', 'uai', 'ni', 'nuai')
// ('nin', 'uan', 'ni', 'nuan')
// ('nin', 'uang', 'ni', 'nuang')
// ('nin', 'ue', 'ni', 'nue')
// ('nin', 'ui', 'ni', 'nui')
// ('nin', 'un', 'ni', 'nun')
// ('nin', 'uo', 'ni', 'nuo')
// ('nin', 'v', 'ni', 'nv')
// ('ning', 'ai', 'nin', 'gai')
// ('ning', 'ang', 'nin', 'gang')
// ('ning', 'ao', 'nin', 'gao')
// ('ning', 'ei', 'nin', 'gei')
// ('ning', 'en', 'nin', 'gen')
// ('ning', 'eng', 'nin', 'geng')
// ('ning', 'i', 'nin', 'gi')
// ('ning', 'ia', 'nin', 'gia')
// ('ning', 'ian', 'nin', 'gian')
// ('ning', 'iang', 'nin', 'giang')
// ('ning', 'iao', 'nin', 'giao')
// ('ning', 'ie', 'nin', 'gie')
// ('ning', 'in', 'nin', 'gin')
// ('ning', 'ing', 'nin', 'ging')
// ('ning', 'iong', 'nin', 'giong')
// ('ning', 'iu', 'nin', 'giu')
// ('ning', 'ong', 'nin', 'gong')
// ('ning', 'ou', 'nin', 'gou')
// ('ning', 'u', 'nin', 'gu')
// ('ning', 'ua', 'nin', 'gua')
// ('ning', 'uai', 'nin', 'guai')
// ('ning', 'uan', 'nin', 'guan')
// ('ning', 'uang', 'nin', 'guang')
// ('ning', 'ue', 'nin', 'gue')
// ('ning', 'ui', 'nin', 'gui')
// ('ning', 'un', 'nin', 'gun')
// ('ning', 'uo', 'nin', 'guo')
// ('ning', 'v', 'nin', 'gv')
// ('nong', 'eng', 'non', 'geng')
// ('nong', 'i', 'non', 'gi')
// ('nong', 'ia', 'non', 'gia')
// ('nong', 'ian', 'non', 'gian')
// ('nong', 'iang', 'non', 'giang')
// ('nong', 'iao', 'non', 'giao')
// ('nong', 'ie', 'non', 'gie')
// ('nong', 'in', 'non', 'gin')
// ('nong', 'ing', 'non', 'ging')
// ('nong', 'iong', 'non', 'giong')
// ('nong', 'iu', 'non', 'giu')
// ('nong', 'ong', 'non', 'gong')
// ('nong', 'u', 'non', 'gu')
// ('nong', 'ua', 'non', 'gua')
// ('nong', 'uai', 'non', 'guai')
// ('nong', 'uan', 'non', 'guan')
// ('nong', 'uang', 'non', 'guang')
// ('nong', 'ue', 'non', 'gue')
// ('nong', 'ui', 'non', 'gui')
// ('nong', 'un', 'non', 'gun')
// ('nong', 'uo', 'non', 'guo')
// ('nong', 'v', 'non', 'gv')
// ('nuan', 'eng', 'nua', 'neng')
// ('nuan', 'i', 'nua', 'ni')
// ('nuan', 'ia', 'nua', 'nia')
// ('nuan', 'ian', 'nua', 'nian')
// ('nuan', 'iang', 'nua', 'niang')
// ('nuan', 'iao', 'nua', 'niao')
// ('nuan', 'ie', 'nua', 'nie')
// ('nuan', 'in', 'nua', 'nin')
// ('nuan', 'ing', 'nua', 'ning')
// ('nuan', 'iong', 'nua', 'niong')
// ('nuan', 'iu', 'nua', 'niu')
// ('nuan', 'ong', 'nua', 'nong')
// ('nuan', 'u', 'nua', 'nu')
// ('nuan', 'ua', 'nua', 'nua')
// ('nuan', 'uai', 'nua', 'nuai')
// ('nuan', 'uan', 'nua', 'nuan')
// ('nuan', 'uang', 'nua', 'nuang')
// ('nuan', 'ue', 'nua', 'nue')
// ('nuan', 'ui', 'nua', 'nui')
// ('nuan', 'un', 'nua', 'nun')
// ('nuan', 'uo', 'nua', 'nuo')
// ('nuan', 'v', 'nua', 'nv')
// ('pan', 'a', 'pa', 'na')
// ('pan', 'e', 'pa', 'ne')
// ('pan', 'ei', 'pa', 'nei')
// ('pan', 'eng', 'pa', 'neng')
// ('pan', 'i', 'pa', 'ni')
// ('pan', 'ia', 'pa', 'nia')
// ('pan', 'ian', 'pa', 'nian')
// ('pan', 'iang', 'pa', 'niang')
// ('pan', 'iao', 'pa', 'niao')
// ('pan', 'ie', 'pa', 'nie')
// ('pan', 'in', 'pa', 'nin')
// ('pan', 'ing', 'pa', 'ning')
// ('pan', 'iong', 'pa', 'niong')
// ('pan', 'iu', 'pa', 'niu')
// ('pan', 'ong', 'pa', 'nong')
// ('pan', 'u', 'pa', 'nu')
// ('pan', 'ua', 'pa', 'nua')
// ('pan', 'uai', 'pa', 'nuai')
// ('pan', 'uan', 'pa', 'nuan')
// ('pan', 'uang', 'pa', 'nuang')
// ('pan', 'ue', 'pa', 'nue')
// ('pan', 'ui', 'pa', 'nui')
// ('pan', 'un', 'pa', 'nun')
// ('pan', 'uo', 'pa', 'nuo')
// ('pan', 'v', 'pa', 'nv')
// ('pang', 'ai', 'pan', 'gai')
// ('pang', 'ang', 'pan', 'gang')
// ('pang', 'ao', 'pan', 'gao')
// ('pang', 'e', 'pan', 'ge')
// ('pang', 'ei', 'pan', 'gei')
// ('pang', 'en', 'pan', 'gen')
// ('pang', 'eng', 'pan', 'geng')
// ('pang', 'i', 'pan', 'gi')
// ('pang', 'ia', 'pan', 'gia')
// ('pang', 'ian', 'pan', 'gian')
// ('pang', 'iang', 'pan', 'giang')
// ('pang', 'iao', 'pan', 'giao')
// ('pang', 'ie', 'pan', 'gie')
// ('pang', 'in', 'pan', 'gin')
// ('pang', 'ing', 'pan', 'ging')
// ('pang', 'iong', 'pan', 'giong')
// ('pang', 'iu', 'pan', 'giu')
// ('pang', 'ong', 'pan', 'gong')
// ('pang', 'ou', 'pan', 'gou')
// ('pang', 'u', 'pan', 'gu')
// ('pang', 'ua', 'pan', 'gua')
// ('pang', 'uai', 'pan', 'guai')
// ('pang', 'uan', 'pan', 'guan')
// ('pang', 'uang', 'pan', 'guang')
// ('pang', 'ue', 'pan', 'gue')
// ('pang', 'ui', 'pan', 'gui')
// ('pang', 'un', 'pan', 'gun')
// ('pang', 'uo', 'pan', 'guo')
// ('pang', 'v', 'pan', 'gv')
// ('pen', 'eng', 'pe', 'neng')
// ('pen', 'i', 'pe', 'ni')
// ('pen', 'ia', 'pe', 'nia')
// ('pen', 'ian', 'pe', 'nian')
// ('pen', 'iang', 'pe', 'niang')
// ('pen', 'iao', 'pe', 'niao')
// ('pen', 'ie', 'pe', 'nie')
// ('pen', 'in', 'pe', 'nin')
// ('pen', 'ing', 'pe', 'ning')
// ('pen', 'iong', 'pe', 'niong')
// ('pen', 'iu', 'pe', 'niu')
// ('pen', 'ong', 'pe', 'nong')
// ('pen', 'u', 'pe', 'nu')
// ('pen', 'ua', 'pe', 'nua')
// ('pen', 'uai', 'pe', 'nuai')
// ('pen', 'uan', 'pe', 'nuan')
// ('pen', 'uang', 'pe', 'nuang')
// ('pen', 'ue', 'pe', 'nue')
// ('pen', 'ui', 'pe', 'nui')
// ('pen', 'un', 'pe', 'nun')
// ('pen', 'uo', 'pe', 'nuo')
// ('pen', 'v', 'pe', 'nv')
// ('peng', 'ei', 'pen', 'gei')
// ('peng', 'eng', 'pen', 'geng')
// ('peng', 'i', 'pen', 'gi')
// ('peng', 'ia', 'pen', 'gia')
// ('peng', 'ian', 'pen', 'gian')
// ('peng', 'iang', 'pen', 'giang')
// ('peng', 'iao', 'pen', 'giao')
// ('peng', 'ie', 'pen', 'gie')
// ('peng', 'in', 'pen', 'gin')
// ('peng', 'ing', 'pen', 'ging')
// ('peng', 'iong', 'pen', 'giong')
// ('peng', 'iu', 'pen', 'giu')
// ('peng', 'ong', 'pen', 'gong')
// ('peng', 'u', 'pen', 'gu')
// ('peng', 'ua', 'pen', 'gua')
// ('peng', 'uai', 'pen', 'guai')
// ('peng', 'uan', 'pen', 'guan')
// ('peng', 'uang', 'pen', 'guang')
// ('peng', 'ue', 'pen', 'gue')
// ('peng', 'ui', 'pen', 'gui')
// ('peng', 'un', 'pen', 'gun')
// ('peng', 'uo', 'pen', 'guo')
// ('peng', 'v', 'pen', 'gv')
// ('pian', 'eng', 'pia', 'neng')
// ('pian', 'i', 'pia', 'ni')
// ('pian', 'ia', 'pia', 'nia')
// ('pian', 'ian', 'pia', 'nian')
// ('pian', 'iang', 'pia', 'niang')
// ('pian', 'iao', 'pia', 'niao')
// ('pian', 'ie', 'pia', 'nie')
// ('pian', 'in', 'pia', 'nin')
// ('pian', 'ing', 'pia', 'ning')
// ('pian', 'iong', 'pia', 'niong')
// ('pian', 'iu', 'pia', 'niu')
// ('pian', 'ong', 'pia', 'nong')
// ('pian', 'u', 'pia', 'nu')
// ('pian', 'ua', 'pia', 'nua')
// ('pian', 'uai', 'pia', 'nuai')
// ('pian', 'uan', 'pia', 'nuan')
// ('pian', 'uang', 'pia', 'nuang')
// ('pian', 'ue', 'pia', 'nue')
// ('pian', 'ui', 'pia', 'nui')
// ('pian', 'un', 'pia', 'nun')
// ('pian', 'uo', 'pia', 'nuo')
// ('pian', 'v', 'pia', 'nv')
// ('pin', 'a', 'pi', 'na')
// ('pin', 'ang', 'pi', 'nang')
// ('pin', 'ei', 'pi', 'nei')
// ('pin', 'eng', 'pi', 'neng')
// ('pin', 'i', 'pi', 'ni')
// ('pin', 'ia', 'pi', 'nia')
// ('pin', 'ian', 'pi', 'nian')
// ('pin', 'iang', 'pi', 'niang')
// ('pin', 'iao', 'pi', 'niao')
// ('pin', 'ie', 'pi', 'nie')
// ('pin', 'in', 'pi', 'nin')
// ('pin', 'ing', 'pi', 'ning')
// ('pin', 'iong', 'pi', 'niong')
// ('pin', 'iu', 'pi', 'niu')
// ('pin', 'ong', 'pi', 'nong')
// ('pin', 'u', 'pi', 'nu')
// ('pin', 'ua', 'pi', 'nua')
// ('pin', 'uai', 'pi', 'nuai')
// ('pin', 'uan', 'pi', 'nuan')
// ('pin', 'uang', 'pi', 'nuang')
// ('pin', 'ue', 'pi', 'nue')
// ('pin', 'ui', 'pi', 'nui')
// ('pin', 'un', 'pi', 'nun')
// ('pin', 'uo', 'pi', 'nuo')
// ('pin', 'v', 'pi', 'nv')
// ('ping', 'ang', 'pin', 'gang')
// ('ping', 'ao', 'pin', 'gao')
// ('ping', 'e', 'pin', 'ge')
// ('ping', 'ei', 'pin', 'gei')
// ('ping', 'en', 'pin', 'gen')
// ('ping', 'eng', 'pin', 'geng')
// ('ping', 'i', 'pin', 'gi')
// ('ping', 'ia', 'pin', 'gia')
// ('ping', 'ian', 'pin', 'gian')
// ('ping', 'iang', 'pin', 'giang')
// ('ping', 'iao', 'pin', 'giao')
// ('ping', 'ie', 'pin', 'gie')
// ('ping', 'in', 'pin', 'gin')
// ('ping', 'ing', 'pin', 'ging')
// ('ping', 'iong', 'pin', 'giong')
// ('ping', 'iu', 'pin', 'giu')
// ('ping', 'ong', 'pin', 'gong')
// ('ping', 'ou', 'pin', 'gou')
// ('ping', 'u', 'pin', 'gu')
// ('ping', 'ua', 'pin', 'gua')
// ('ping', 'uai', 'pin', 'guai')
// ('ping', 'uan', 'pin', 'guan')
// ('ping', 'uang', 'pin', 'guang')
// ('ping', 'ue', 'pin', 'gue')
// ('ping', 'ui', 'pin', 'gui')
// ('ping', 'un', 'pin', 'gun')
// ('ping', 'uo', 'pin', 'guo')
// ('ping', 'v', 'pin', 'gv')
// ('qian', 'ei', 'qia', 'nei')
// ('qian', 'eng', 'qia', 'neng')
// ('qian', 'i', 'qia', 'ni')
// ('qian', 'ia', 'qia', 'nia')
// ('qian', 'ian', 'qia', 'nian')
// ('qian', 'iang', 'qia', 'niang')
// ('qian', 'iao', 'qia', 'niao')
// ('qian', 'ie', 'qia', 'nie')
// ('qian', 'in', 'qia', 'nin')
// ('qian', 'ing', 'qia', 'ning')
// ('qian', 'iong', 'qia', 'niong')
// ('qian', 'iu', 'qia', 'niu')
// ('qian', 'ong', 'qia', 'nong')
// ('qian', 'u', 'qia', 'nu')
// ('qian', 'ua', 'qia', 'nua')
// ('qian', 'uai', 'qia', 'nuai')
// ('qian', 'uan', 'qia', 'nuan')
// ('qian', 'uang', 'qia', 'nuang')
// ('qian', 'ue', 'qia', 'nue')
// ('qian', 'ui', 'qia', 'nui')
// ('qian', 'un', 'qia', 'nun')
// ('qian', 'uo', 'qia', 'nuo')
// ('qian', 'v', 'qia', 'nv')
// ('qiang', 'ai', 'qian', 'gai')
// ('qiang', 'an', 'qian', 'gan')
// ('qiang', 'ang', 'qian', 'gang')
// ('qiang', 'ao', 'qian', 'gao')
// ('qiang', 'e', 'qian', 'ge')
// ('qiang', 'ei', 'qian', 'gei')
// ('qiang', 'en', 'qian', 'gen')
// ('qiang', 'eng', 'qian', 'geng')
// ('qiang', 'i', 'qian', 'gi')
// ('qiang', 'ia', 'qian', 'gia')
// ('qiang', 'ian', 'qian', 'gian')
// ('qiang', 'iang', 'qian', 'giang')
// ('qiang', 'iao', 'qian', 'giao')
// ('qiang', 'ie', 'qian', 'gie')
// ('qiang', 'in', 'qian', 'gin')
// ('qiang', 'ing', 'qian', 'ging')
// ('qiang', 'iong', 'qian', 'giong')
// ('qiang', 'iu', 'qian', 'giu')
// ('qiang', 'ong', 'qian', 'gong')
// ('qiang', 'ou', 'qian', 'gou')
// ('qiang', 'u', 'qian', 'gu')
// ('qiang', 'ua', 'qian', 'gua')
// ('qiang', 'uai', 'qian', 'guai')
// ('qiang', 'uan', 'qian', 'guan')
// ('qiang', 'uang', 'qian', 'guang')
// ('qiang', 'ue', 'qian', 'gue')
// ('qiang', 'ui', 'qian', 'gui')
// ('qiang', 'un', 'qian', 'gun')
// ('qiang', 'uo', 'qian', 'guo')
// ('qiang', 'v', 'qian', 'gv')
// ('qin', 'a', 'qi', 'na')
// ('qin', 'ang', 'qi', 'nang')
// ('qin', 'ao', 'qi', 'nao')
// ('qin', 'e', 'qi', 'ne')
// ('qin', 'ei', 'qi', 'nei')
// ('qin', 'eng', 'qi', 'neng')
// ('qin', 'i', 'qi', 'ni')
// ('qin', 'ia', 'qi', 'nia')
// ('qin', 'ian', 'qi', 'nian')
// ('qin', 'iang', 'qi', 'niang')
// ('qin', 'iao', 'qi', 'niao')
// ('qin', 'ie', 'qi', 'nie')
// ('qin', 'in', 'qi', 'nin')
// ('qin', 'ing', 'qi', 'ning')
// ('qin', 'iong', 'qi', 'niong')
// ('qin', 'iu', 'qi', 'niu')
// ('qin', 'ong', 'qi', 'nong')
// ('qin', 'u', 'qi', 'nu')
// ('qin', 'ua', 'qi', 'nua')
// ('qin', 'uai', 'qi', 'nuai')
// ('qin', 'uan', 'qi', 'nuan')
// ('qin', 'uang', 'qi', 'nuang')
// ('qin', 'ue', 'qi', 'nue')
// ('qin', 'ui', 'qi', 'nui')
// ('qin', 'un', 'qi', 'nun')
// ('qin', 'uo', 'qi', 'nuo')
// ('qin', 'v', 'qi', 'nv')
// ('qing', 'ang', 'qin', 'gang')
// ('qing', 'ao', 'qin', 'gao')
// ('qing', 'e', 'qin', 'ge')
// ('qing', 'ei', 'qin', 'gei')
// ('qing', 'en', 'qin', 'gen')
// ('qing', 'eng', 'qin', 'geng')
// ('qing', 'i', 'qin', 'gi')
// ('qing', 'ia', 'qin', 'gia')
// ('qing', 'ian', 'qin', 'gian')
// ('qing', 'iang', 'qin', 'giang')
// ('qing', 'iao', 'qin', 'giao')
// ('qing', 'ie', 'qin', 'gie')
// ('qing', 'in', 'qin', 'gin')
// ('qing', 'ing', 'qin', 'ging')
// ('qing', 'iong', 'qin', 'giong')
// ('qing', 'iu', 'qin', 'giu')
// ('qing', 'ong', 'qin', 'gong')
// ('qing', 'u', 'qin', 'gu')
// ('qing', 'ua', 'qin', 'gua')
// ('qing', 'uai', 'qin', 'guai')
// ('qing', 'uan', 'qin', 'guan')
// ('qing', 'uang', 'qin', 'guang')
// ('qing', 'ue', 'qin', 'gue')
// ('qing', 'ui', 'qin', 'gui')
// ('qing', 'un', 'qin', 'gun')
// ('qing', 'uo', 'qin', 'guo')
// ('qing', 'v', 'qin', 'gv')
// ('qiong', 'eng', 'qion', 'geng')
// ('qiong', 'i', 'qion', 'gi')
// ('qiong', 'ia', 'qion', 'gia')
// ('qiong', 'ian', 'qion', 'gian')
// ('qiong', 'iang', 'qion', 'giang')
// ('qiong', 'iao', 'qion', 'giao')
// ('qiong', 'ie', 'qion', 'gie')
// ('qiong', 'in', 'qion', 'gin')
// ('qiong', 'ing', 'qion', 'ging')
// ('qiong', 'iong', 'qion', 'giong')
// ('qiong', 'iu', 'qion', 'giu')
// ('qiong', 'ong', 'qion', 'gong')
// ('qiong', 'u', 'qion', 'gu')
// ('qiong', 'ua', 'qion', 'gua')
// ('qiong', 'uai', 'qion', 'guai')
// ('qiong', 'uan', 'qion', 'guan')
// ('qiong', 'uang', 'qion', 'guang')
// ('qiong', 'ue', 'qion', 'gue')
// ('qiong', 'ui', 'qion', 'gui')
// ('qiong', 'un', 'qion', 'gun')
// ('qiong', 'uo', 'qion', 'guo')
// ('qiong', 'v', 'qion', 'gv')
// ('quan', 'eng', 'qua', 'neng')
// ('quan', 'i', 'qua', 'ni')
// ('quan', 'ia', 'qua', 'nia')
// ('quan', 'ian', 'qua', 'nian')
// ('quan', 'iang', 'qua', 'niang')
// ('quan', 'iao', 'qua', 'niao')
// ('quan', 'ie', 'qua', 'nie')
// ('quan', 'in', 'qua', 'nin')
// ('quan', 'ing', 'qua', 'ning')
// ('quan', 'iong', 'qua', 'niong')
// ('quan', 'iu', 'qua', 'niu')
// ('quan', 'ong', 'qua', 'nong')
// ('quan', 'u', 'qua', 'nu')
// ('quan', 'ua', 'qua', 'nua')
// ('quan', 'uai', 'qua', 'nuai')
// ('quan', 'uan', 'qua', 'nuan')
// ('quan', 'uang', 'qua', 'nuang')
// ('quan', 'ue', 'qua', 'nue')
// ('quan', 'ui', 'qua', 'nui')
// ('quan', 'un', 'qua', 'nun')
// ('quan', 'uo', 'qua', 'nuo')
// ('quan', 'v', 'qua', 'nv')
// ('qun', 'a', 'qu', 'na')
// ('qun', 'ai', 'qu', 'nai')
// ('qun', 'an', 'qu', 'nan')
// ('qun', 'ao', 'qu', 'nao')
// ('qun', 'e', 'qu', 'ne')
// ('qun', 'ei', 'qu', 'nei')
// ('qun', 'eng', 'qu', 'neng')
// ('qun', 'i', 'qu', 'ni')
// ('qun', 'ia', 'qu', 'nia')
// ('qun', 'ian', 'qu', 'nian')
// ('qun', 'iang', 'qu', 'niang')
// ('qun', 'iao', 'qu', 'niao')
// ('qun', 'ie', 'qu', 'nie')
// ('qun', 'in', 'qu', 'nin')
// ('qun', 'ing', 'qu', 'ning')
// ('qun', 'iong', 'qu', 'niong')
// ('qun', 'iu', 'qu', 'niu')
// ('qun', 'ong', 'qu', 'nong')
// ('qun', 'u', 'qu', 'nu')
// ('qun', 'ua', 'qu', 'nua')
// ('qun', 'uai', 'qu', 'nuai')
// ('qun', 'uan', 'qu', 'nuan')
// ('qun', 'uang', 'qu', 'nuang')
// ('qun', 'ue', 'qu', 'nue')
// ('qun', 'ui', 'qu', 'nui')
// ('qun', 'un', 'qu', 'nun')
// ('qun', 'uo', 'qu', 'nuo')
// ('qun', 'v', 'qu', 'nv')
// ('ran', 'eng', 'ra', 'neng')
// ('ran', 'i', 'ra', 'ni')
// ('ran', 'ia', 'ra', 'nia')
// ('ran', 'ian', 'ra', 'nian')
// ('ran', 'iang', 'ra', 'niang')
// ('ran', 'iao', 'ra', 'niao')
// ('ran', 'ie', 'ra', 'nie')
// ('ran', 'in', 'ra', 'nin')
// ('ran', 'ing', 'ra', 'ning')
// ('ran', 'iong', 'ra', 'niong')
// ('ran', 'iu', 'ra', 'niu')
// ('ran', 'ong', 'ra', 'nong')
// ('ran', 'u', 'ra', 'nu')
// ('ran', 'ua', 'ra', 'nua')
// ('ran', 'uai', 'ra', 'nuai')
// ('ran', 'uan', 'ra', 'nuan')
// ('ran', 'uang', 'ra', 'nuang')
// ('ran', 'ue', 'ra', 'nue')
// ('ran', 'ui', 'ra', 'nui')
// ('ran', 'un', 'ra', 'nun')
// ('ran', 'uo', 'ra', 'nuo')
// ('ran', 'v', 'ra', 'nv')
// ('rang', 'ang', 'ran', 'gang')
// ('rang', 'ao', 'ran', 'gao')
// ('rang', 'ei', 'ran', 'gei')
// ('rang', 'en', 'ran', 'gen')
// ('rang', 'eng', 'ran', 'geng')
// ('rang', 'i', 'ran', 'gi')
// ('rang', 'ia', 'ran', 'gia')
// ('rang', 'ian', 'ran', 'gian')
// ('rang', 'iang', 'ran', 'giang')
// ('rang', 'iao', 'ran', 'giao')
// ('rang', 'ie', 'ran', 'gie')
// ('rang', 'in', 'ran', 'gin')
// ('rang', 'ing', 'ran', 'ging')
// ('rang', 'iong', 'ran', 'giong')
// ('rang', 'iu', 'ran', 'giu')
// ('rang', 'ong', 'ran', 'gong')
// ('rang', 'u', 'ran', 'gu')
// ('rang', 'ua', 'ran', 'gua')
// ('rang', 'uai', 'ran', 'guai')
// ('rang', 'uan', 'ran', 'guan')
// ('rang', 'uang', 'ran', 'guang')
// ('rang', 'ue', 'ran', 'gue')
// ('rang', 'ui', 'ran', 'gui')
// ('rang', 'un', 'ran', 'gun')
// ('rang', 'uo', 'ran', 'guo')
// ('rang', 'v', 'ran', 'gv')
// ('ren', 'ao', 're', 'nao')
// ('ren', 'e', 're', 'ne')
// ('ren', 'ei', 're', 'nei')
// ('ren', 'eng', 're', 'neng')
// ('ren', 'i', 're', 'ni')
// ('ren', 'ia', 're', 'nia')
// ('ren', 'ian', 're', 'nian')
// ('ren', 'iang', 're', 'niang')
// ('ren', 'iao', 're', 'niao')
// ('ren', 'ie', 're', 'nie')
// ('ren', 'in', 're', 'nin')
// ('ren', 'ing', 're', 'ning')
// ('ren', 'iong', 're', 'niong')
// ('ren', 'iu', 're', 'niu')
// ('ren', 'ong', 're', 'nong')
// ('ren', 'u', 're', 'nu')
// ('ren', 'ua', 're', 'nua')
// ('ren', 'uai', 're', 'nuai')
// ('ren', 'uan', 're', 'nuan')
// ('ren', 'uang', 're', 'nuang')
// ('ren', 'ue', 're', 'nue')
// ('ren', 'ui', 're', 'nui')
// ('ren', 'un', 're', 'nun')
// ('ren', 'uo', 're', 'nuo')
// ('ren', 'v', 're', 'nv')
// ('reng', 'a', 'ren', 'ga')
// ('reng', 'ai', 'ren', 'gai')
// ('reng', 'an', 'ren', 'gan')
// ('reng', 'ang', 'ren', 'gang')
// ('reng', 'ao', 'ren', 'gao')
// ('reng', 'e', 'ren', 'ge')
// ('reng', 'ei', 'ren', 'gei')
// ('reng', 'en', 'ren', 'gen')
// ('reng', 'eng', 'ren', 'geng')
// ('reng', 'i', 'ren', 'gi')
// ('reng', 'ia', 'ren', 'gia')
// ('reng', 'ian', 'ren', 'gian')
// ('reng', 'iang', 'ren', 'giang')
// ('reng', 'iao', 'ren', 'giao')
// ('reng', 'ie', 'ren', 'gie')
// ('reng', 'in', 'ren', 'gin')
// ('reng', 'ing', 'ren', 'ging')
// ('reng', 'iong', 'ren', 'giong')
// ('reng', 'iu', 'ren', 'giu')
// ('reng', 'ong', 'ren', 'gong')
// ('reng', 'ou', 'ren', 'gou')
// ('reng', 'u', 'ren', 'gu')
// ('reng', 'ua', 'ren', 'gua')
// ('reng', 'uai', 'ren', 'guai')
// ('reng', 'uan', 'ren', 'guan')
// ('reng', 'uang', 'ren', 'guang')
// ('reng', 'ue', 'ren', 'gue')
// ('reng', 'ui', 'ren', 'gui')
// ('reng', 'un', 'ren', 'gun')
// ('reng', 'uo', 'ren', 'guo')
// ('reng', 'v', 'ren', 'gv')
// ('rong', 'eng', 'ron', 'geng')
// ('rong', 'i', 'ron', 'gi')
// ('rong', 'ia', 'ron', 'gia')
// ('rong', 'ian', 'ron', 'gian')
// ('rong', 'iang', 'ron', 'giang')
// ('rong', 'iao', 'ron', 'giao')
// ('rong', 'ie', 'ron', 'gie')
// ('rong', 'in', 'ron', 'gin')
// ('rong', 'ing', 'ron', 'ging')
// ('rong', 'iong', 'ron', 'giong')
// ('rong', 'iu', 'ron', 'giu')
// ('rong', 'ong', 'ron', 'gong')
// ('rong', 'u', 'ron', 'gu')
// ('rong', 'ua', 'ron', 'gua')
// ('rong', 'uai', 'ron', 'guai')
// ('rong', 'uan', 'ron', 'guan')
// ('rong', 'uang', 'ron', 'guang')
// ('rong', 'ue', 'ron', 'gue')
// ('rong', 'ui', 'ron', 'gui')
// ('rong', 'un', 'ron', 'gun')
// ('rong', 'uo', 'ron', 'guo')
// ('rong', 'v', 'ron', 'gv')
// ('ruan', 'eng', 'rua', 'neng')
// ('ruan', 'i', 'rua', 'ni')
// ('ruan', 'ia', 'rua', 'nia')
// ('ruan', 'ian', 'rua', 'nian')
// ('ruan', 'iang', 'rua', 'niang')
// ('ruan', 'iao', 'rua', 'niao')
// ('ruan', 'ie', 'rua', 'nie')
// ('ruan', 'in', 'rua', 'nin')
// ('ruan', 'ing', 'rua', 'ning')
// ('ruan', 'iong', 'rua', 'niong')
// ('ruan', 'iu', 'rua', 'niu')
// ('ruan', 'ong', 'rua', 'nong')
// ('ruan', 'u', 'rua', 'nu')
// ('ruan', 'ua', 'rua', 'nua')
// ('ruan', 'uai', 'rua', 'nuai')
// ('ruan', 'uan', 'rua', 'nuan')
// ('ruan', 'uang', 'rua', 'nuang')
// ('ruan', 'ue', 'rua', 'nue')
// ('ruan', 'ui', 'rua', 'nui')
// ('ruan', 'un', 'rua', 'nun')
// ('ruan', 'uo', 'rua', 'nuo')
// ('ruan', 'v', 'rua', 'nv')
// ('run', 'a', 'ru', 'na')
// ('run', 'ai', 'ru', 'nai')
// ('run', 'an', 'ru', 'nan')
// ('run', 'ang', 'ru', 'nang')
// ('run', 'ao', 'ru', 'nao')
// ('run', 'e', 'ru', 'ne')
// ('run', 'ei', 'ru', 'nei')
// ('run', 'en', 'ru', 'nen')
// ('run', 'eng', 'ru', 'neng')
// ('run', 'i', 'ru', 'ni')
// ('run', 'ia', 'ru', 'nia')
// ('run', 'ian', 'ru', 'nian')
// ('run', 'iang', 'ru', 'niang')
// ('run', 'iao', 'ru', 'niao')
// ('run', 'ie', 'ru', 'nie')
// ('run', 'in', 'ru', 'nin')
// ('run', 'ing', 'ru', 'ning')
// ('run', 'iong', 'ru', 'niong')
// ('run', 'iu', 'ru', 'niu')
// ('run', 'ong', 'ru', 'nong')
// ('run', 'u', 'ru', 'nu')
// ('run', 'ua', 'ru', 'nua')
// ('run', 'uai', 'ru', 'nuai')
// ('run', 'uan', 'ru', 'nuan')
// ('run', 'uang', 'ru', 'nuang')
// ('run', 'ue', 'ru', 'nue')
// ('run', 'ui', 'ru', 'nui')
// ('run', 'un', 'ru', 'nun')
// ('run', 'uo', 'ru', 'nuo')
// ('run', 'v', 'ru', 'nv')
// ('san', 'a', 'sa', 'na')
// ('san', 'ei', 'sa', 'nei')
// ('san', 'eng', 'sa', 'neng')
// ('san', 'i', 'sa', 'ni')
// ('san', 'ia', 'sa', 'nia')
// ('san', 'ian', 'sa', 'nian')
// ('san', 'iang', 'sa', 'niang')
// ('san', 'iao', 'sa', 'niao')
// ('san', 'ie', 'sa', 'nie')
// ('san', 'in', 'sa', 'nin')
// ('san', 'ing', 'sa', 'ning')
// ('san', 'iong', 'sa', 'niong')
// ('san', 'iu', 'sa', 'niu')
// ('san', 'ong', 'sa', 'nong')
// ('san', 'u', 'sa', 'nu')
// ('san', 'ua', 'sa', 'nua')
// ('san', 'uai', 'sa', 'nuai')
// ('san', 'uan', 'sa', 'nuan')
// ('san', 'uang', 'sa', 'nuang')
// ('san', 'ue', 'sa', 'nue')
// ('san', 'ui', 'sa', 'nui')
// ('san', 'un', 'sa', 'nun')
// ('san', 'uo', 'sa', 'nuo')
// ('san', 'v', 'sa', 'nv')
// ('sang', 'a', 'san', 'ga')
// ('sang', 'ai', 'san', 'gai')
// ('sang', 'an', 'san', 'gan')
// ('sang', 'ang', 'san', 'gang')
// ('sang', 'ao', 'san', 'gao')
// ('sang', 'e', 'san', 'ge')
// ('sang', 'ei', 'san', 'gei')
// ('sang', 'en', 'san', 'gen')
// ('sang', 'eng', 'san', 'geng')
// ('sang', 'i', 'san', 'gi')
// ('sang', 'ia', 'san', 'gia')
// ('sang', 'ian', 'san', 'gian')
// ('sang', 'iang', 'san', 'giang')
// ('sang', 'iao', 'san', 'giao')
// ('sang', 'ie', 'san', 'gie')
// ('sang', 'in', 'san', 'gin')
// ('sang', 'ing', 'san', 'ging')
// ('sang', 'iong', 'san', 'giong')
// ('sang', 'iu', 'san', 'giu')
// ('sang', 'ong', 'san', 'gong')
// ('sang', 'u', 'san', 'gu')
// ('sang', 'ua', 'san', 'gua')
// ('sang', 'uai', 'san', 'guai')
// ('sang', 'uan', 'san', 'guan')
// ('sang', 'uang', 'san', 'guang')
// ('sang', 'ue', 'san', 'gue')
// ('sang', 'ui', 'san', 'gui')
// ('sang', 'un', 'san', 'gun')
// ('sang', 'uo', 'san', 'guo')
// ('sang', 'v', 'san', 'gv')
// ('sen', 'a', 'se', 'na')
// ('sen', 'ai', 'se', 'nai')
// ('sen', 'an', 'se', 'nan')
// ('sen', 'ei', 'se', 'nei')
// ('sen', 'eng', 'se', 'neng')
// ('sen', 'i', 'se', 'ni')
// ('sen', 'ia', 'se', 'nia')
// ('sen', 'ian', 'se', 'nian')
// ('sen', 'iang', 'se', 'niang')
// ('sen', 'iao', 'se', 'niao')
// ('sen', 'ie', 'se', 'nie')
// ('sen', 'in', 'se', 'nin')
// ('sen', 'ing', 'se', 'ning')
// ('sen', 'iong', 'se', 'niong')
// ('sen', 'iu', 'se', 'niu')
// ('sen', 'ong', 'se', 'nong')
// ('sen', 'u', 'se', 'nu')
// ('sen', 'ua', 'se', 'nua')
// ('sen', 'uai', 'se', 'nuai')
// ('sen', 'uan', 'se', 'nuan')
// ('sen', 'uang', 'se', 'nuang')
// ('sen', 'ue', 'se', 'nue')
// ('sen', 'ui', 'se', 'nui')
// ('sen', 'un', 'se', 'nun')
// ('sen', 'uo', 'se', 'nuo')
// ('sen', 'v', 'se', 'nv')
// ('seng', 'a', 'sen', 'ga')
// ('seng', 'ai', 'sen', 'gai')
// ('seng', 'an', 'sen', 'gan')
// ('seng', 'ang', 'sen', 'gang')
// ('seng', 'ao', 'sen', 'gao')
// ('seng', 'e', 'sen', 'ge')
// ('seng', 'ei', 'sen', 'gei')
// ('seng', 'en', 'sen', 'gen')
// ('seng', 'eng', 'sen', 'geng')
// ('seng', 'i', 'sen', 'gi')
// ('seng', 'ia', 'sen', 'gia')
// ('seng', 'ian', 'sen', 'gian')
// ('seng', 'iang', 'sen', 'giang')
// ('seng', 'iao', 'sen', 'giao')
// ('seng', 'ie', 'sen', 'gie')
// ('seng', 'in', 'sen', 'gin')
// ('seng', 'ing', 'sen', 'ging')
// ('seng', 'iong', 'sen', 'giong')
// ('seng', 'iu', 'sen', 'giu')
// ('seng', 'ong', 'sen', 'gong')
// ('seng', 'ou', 'sen', 'gou')
// ('seng', 'u', 'sen', 'gu')
// ('seng', 'ua', 'sen', 'gua')
// ('seng', 'uai', 'sen', 'guai')
// ('seng', 'uan', 'sen', 'guan')
// ('seng', 'uang', 'sen', 'guang')
// ('seng', 'ue', 'sen', 'gue')
// ('seng', 'ui', 'sen', 'gui')
// ('seng', 'un', 'sen', 'gun')
// ('seng', 'uo', 'sen', 'guo')
// ('seng', 'v', 'sen', 'gv')
// ('shan', 'a', 'sha', 'na')
// ('shan', 'an', 'sha', 'nan')
// ('shan', 'ei', 'sha', 'nei')
// ('shan', 'eng', 'sha', 'neng')
// ('shan', 'i', 'sha', 'ni')
// ('shan', 'ia', 'sha', 'nia')
// ('shan', 'ian', 'sha', 'nian')
// ('shan', 'iang', 'sha', 'niang')
// ('shan', 'iao', 'sha', 'niao')
// ('shan', 'ie', 'sha', 'nie')
// ('shan', 'in', 'sha', 'nin')
// ('shan', 'ing', 'sha', 'ning')
// ('shan', 'iong', 'sha', 'niong')
// ('shan', 'iu', 'sha', 'niu')
// ('shan', 'ong', 'sha', 'nong')
// ('shan', 'u', 'sha', 'nu')
// ('shan', 'ua', 'sha', 'nua')
// ('shan', 'uai', 'sha', 'nuai')
// ('shan', 'uan', 'sha', 'nuan')
// ('shan', 'uang', 'sha', 'nuang')
// ('shan', 'ue', 'sha', 'nue')
// ('shan', 'ui', 'sha', 'nui')
// ('shan', 'un', 'sha', 'nun')
// ('shan', 'uo', 'sha', 'nuo')
// ('shan', 'v', 'sha', 'nv')
// ('shang', 'ai', 'shan', 'gai')
// ('shang', 'ang', 'shan', 'gang')
// ('shang', 'ao', 'shan', 'gao')
// ('shang', 'e', 'shan', 'ge')
// ('shang', 'ei', 'shan', 'gei')
// ('shang', 'en', 'shan', 'gen')
// ('shang', 'eng', 'shan', 'geng')
// ('shang', 'i', 'shan', 'gi')
// ('shang', 'ia', 'shan', 'gia')
// ('shang', 'ian', 'shan', 'gian')
// ('shang', 'iang', 'shan', 'giang')
// ('shang', 'iao', 'shan', 'giao')
// ('shang', 'ie', 'shan', 'gie')
// ('shang', 'in', 'shan', 'gin')
// ('shang', 'ing', 'shan', 'ging')
// ('shang', 'iong', 'shan', 'giong')
// ('shang', 'iu', 'shan', 'giu')
// ('shang', 'ong', 'shan', 'gong')
// ('shang', 'ou', 'shan', 'gou')
// ('shang', 'u', 'shan', 'gu')
// ('shang', 'ua', 'shan', 'gua')
// ('shang', 'uai', 'shan', 'guai')
// ('shang', 'uan', 'shan', 'guan')
// ('shang', 'uang', 'shan', 'guang')
// ('shang', 'ue', 'shan', 'gue')
// ('shang', 'ui', 'shan', 'gui')
// ('shang', 'un', 'shan', 'gun')
// ('shang', 'uo', 'shan', 'guo')
// ('shang', 'v', 'shan', 'gv')
// ('shen', 'ei', 'she', 'nei')
// ('shen', 'eng', 'she', 'neng')
// ('shen', 'i', 'she', 'ni')
// ('shen', 'ia', 'she', 'nia')
// ('shen', 'ian', 'she', 'nian')
// ('shen', 'iang', 'she', 'niang')
// ('shen', 'iao', 'she', 'niao')
// ('shen', 'ie', 'she', 'nie')
// ('shen', 'in', 'she', 'nin')
// ('shen', 'ing', 'she', 'ning')
// ('shen', 'iong', 'she', 'niong')
// ('shen', 'iu', 'she', 'niu')
// ('shen', 'ong', 'she', 'nong')
// ('shen', 'u', 'she', 'nu')
// ('shen', 'ua', 'she', 'nua')
// ('shen', 'uai', 'she', 'nuai')
// ('shen', 'uan', 'she', 'nuan')
// ('shen', 'uang', 'she', 'nuang')
// ('shen', 'ue', 'she', 'nue')
// ('shen', 'ui', 'she', 'nui')
// ('shen', 'un', 'she', 'nun')
// ('shen', 'uo', 'she', 'nuo')
// ('shen', 'v', 'she', 'nv')
// ('sheng', 'an', 'shen', 'gan')
// ('sheng', 'ang', 'shen', 'gang')
// ('sheng', 'ao', 'shen', 'gao')
// ('sheng', 'e', 'shen', 'ge')
// ('sheng', 'ei', 'shen', 'gei')
// ('sheng', 'eng', 'shen', 'geng')
// ('sheng', 'i', 'shen', 'gi')
// ('sheng', 'ia', 'shen', 'gia')
// ('sheng', 'ian', 'shen', 'gian')
// ('sheng', 'iang', 'shen', 'giang')
// ('sheng', 'iao', 'shen', 'giao')
// ('sheng', 'ie', 'shen', 'gie')
// ('sheng', 'in', 'shen', 'gin')
// ('sheng', 'ing', 'shen', 'ging')
// ('sheng', 'iong', 'shen', 'giong')
// ('sheng', 'iu', 'shen', 'giu')
// ('sheng', 'ong', 'shen', 'gong')
// ('sheng', 'ou', 'shen', 'gou')
// ('sheng', 'u', 'shen', 'gu')
// ('sheng', 'ua', 'shen', 'gua')
// ('sheng', 'uai', 'shen', 'guai')
// ('sheng', 'uan', 'shen', 'guan')
// ('sheng', 'uang', 'shen', 'guang')
// ('sheng', 'ue', 'shen', 'gue')
// ('sheng', 'ui', 'shen', 'gui')
// ('sheng', 'un', 'shen', 'gun')
// ('sheng', 'uo', 'shen', 'guo')
// ('sheng', 'v', 'shen', 'gv')
// ('shuan', 'a', 'shua', 'na')
// ('shuan', 'ai', 'shua', 'nai')
// ('shuan', 'an', 'shua', 'nan')
// ('shuan', 'ang', 'shua', 'nang')
// ('shuan', 'ao', 'shua', 'nao')
// ('shuan', 'e', 'shua', 'ne')
// ('shuan', 'ei', 'shua', 'nei')
// ('shuan', 'en', 'shua', 'nen')
// ('shuan', 'eng', 'shua', 'neng')
// ('shuan', 'i', 'shua', 'ni')
// ('shuan', 'ia', 'shua', 'nia')
// ('shuan', 'ian', 'shua', 'nian')
// ('shuan', 'iang', 'shua', 'niang')
// ('shuan', 'iao', 'shua', 'niao')
// ('shuan', 'ie', 'shua', 'nie')
// ('shuan', 'in', 'shua', 'nin')
// ('shuan', 'ing', 'shua', 'ning')
// ('shuan', 'iong', 'shua', 'niong')
// ('shuan', 'iu', 'shua', 'niu')
// ('shuan', 'ong', 'shua', 'nong')
// ('shuan', 'u', 'shua', 'nu')
// ('shuan', 'ua', 'shua', 'nua')
// ('shuan', 'uai', 'shua', 'nuai')
// ('shuan', 'uan', 'shua', 'nuan')
// ('shuan', 'uang', 'shua', 'nuang')
// ('shuan', 'ue', 'shua', 'nue')
// ('shuan', 'ui', 'shua', 'nui')
// ('shuan', 'un', 'shua', 'nun')
// ('shuan', 'uo', 'shua', 'nuo')
// ('shuan', 'v', 'shua', 'nv')
// ('shuang', 'ei', 'shuan', 'gei')
// ('shuang', 'eng', 'shuan', 'geng')
// ('shuang', 'i', 'shuan', 'gi')
// ('shuang', 'ia', 'shuan', 'gia')
// ('shuang', 'ian', 'shuan', 'gian')
// ('shuang', 'iang', 'shuan', 'giang')
// ('shuang', 'iao', 'shuan', 'giao')
// ('shuang', 'ie', 'shuan', 'gie')
// ('shuang', 'in', 'shuan', 'gin')
// ('shuang', 'ing', 'shuan', 'ging')
// ('shuang', 'iong', 'shuan', 'giong')
// ('shuang', 'iu', 'shuan', 'giu')
// ('shuang', 'ong', 'shuan', 'gong')
// ('shuang', 'u', 'shuan', 'gu')
// ('shuang', 'ua', 'shuan', 'gua')
// ('shuang', 'uai', 'shuan', 'guai')
// ('shuang', 'uan', 'shuan', 'guan')
// ('shuang', 'uang', 'shuan', 'guang')
// ('shuang', 'ue', 'shuan', 'gue')
// ('shuang', 'ui', 'shuan', 'gui')
// ('shuang', 'un', 'shuan', 'gun')
// ('shuang', 'uo', 'shuan', 'guo')
// ('shuang', 'v', 'shuan', 'gv')
// ('shun', 'an', 'shu', 'nan')
// ('shun', 'e', 'shu', 'ne')
// ('shun', 'ei', 'shu', 'nei')
// ('shun', 'eng', 'shu', 'neng')
// ('shun', 'i', 'shu', 'ni')
// ('shun', 'ia', 'shu', 'nia')
// ('shun', 'ian', 'shu', 'nian')
// ('shun', 'iang', 'shu', 'niang')
// ('shun', 'iao', 'shu', 'niao')
// ('shun', 'ie', 'shu', 'nie')
// ('shun', 'in', 'shu', 'nin')
// ('shun', 'ing', 'shu', 'ning')
// ('shun', 'iong', 'shu', 'niong')
// ('shun', 'iu', 'shu', 'niu')
// ('shun', 'ong', 'shu', 'nong')
// ('shun', 'u', 'shu', 'nu')
// ('shun', 'ua', 'shu', 'nua')
// ('shun', 'uai', 'shu', 'nuai')
// ('shun', 'uan', 'shu', 'nuan')
// ('shun', 'uang', 'shu', 'nuang')
// ('shun', 'ue', 'shu', 'nue')
// ('shun', 'ui', 'shu', 'nui')
// ('shun', 'un', 'shu', 'nun')
// ('shun', 'uo', 'shu', 'nuo')
// ('shun', 'v', 'shu', 'nv')
// ('song', 'eng', 'son', 'geng')
// ('song', 'i', 'son', 'gi')
// ('song', 'ia', 'son', 'gia')
// ('song', 'ian', 'son', 'gian')
// ('song', 'iang', 'son', 'giang')
// ('song', 'iao', 'son', 'giao')
// ('song', 'ie', 'son', 'gie')
// ('song', 'in', 'son', 'gin')
// ('song', 'ing', 'son', 'ging')
// ('song', 'iong', 'son', 'giong')
// ('song', 'iu', 'son', 'giu')
// ('song', 'ong', 'son', 'gong')
// ('song', 'u', 'son', 'gu')
// ('song', 'ua', 'son', 'gua')
// ('song', 'uai', 'son', 'guai')
// ('song', 'uan', 'son', 'guan')
// ('song', 'uang', 'son', 'guang')
// ('song', 'ue', 'son', 'gue')
// ('song', 'ui', 'son', 'gui')
// ('song', 'un', 'son', 'gun')
// ('song', 'uo', 'son', 'guo')
// ('song', 'v', 'son', 'gv')
// ('suan', 'eng', 'sua', 'neng')
// ('suan', 'i', 'sua', 'ni')
// ('suan', 'ia', 'sua', 'nia')
// ('suan', 'ian', 'sua', 'nian')
// ('suan', 'iang', 'sua', 'niang')
// ('suan', 'iao', 'sua', 'niao')
// ('suan', 'ie', 'sua', 'nie')
// ('suan', 'in', 'sua', 'nin')
// ('suan', 'ing', 'sua', 'ning')
// ('suan', 'iong', 'sua', 'niong')
// ('suan', 'iu', 'sua', 'niu')
// ('suan', 'ong', 'sua', 'nong')
// ('suan', 'u', 'sua', 'nu')
// ('suan', 'ua', 'sua', 'nua')
// ('suan', 'uai', 'sua', 'nuai')
// ('suan', 'uan', 'sua', 'nuan')
// ('suan', 'uang', 'sua', 'nuang')
// ('suan', 'ue', 'sua', 'nue')
// ('suan', 'ui', 'sua', 'nui')
// ('suan', 'un', 'sua', 'nun')
// ('suan', 'uo', 'sua', 'nuo')
// ('suan', 'v', 'sua', 'nv')
// ('sun', 'a', 'su', 'na')
// ('sun', 'an', 'su', 'nan')
// ('sun', 'ang', 'su', 'nang')
// ('sun', 'ei', 'su', 'nei')
// ('sun', 'eng', 'su', 'neng')
// ('sun', 'i', 'su', 'ni')
// ('sun', 'ia', 'su', 'nia')
// ('sun', 'ian', 'su', 'nian')
// ('sun', 'iang', 'su', 'niang')
// ('sun', 'iao', 'su', 'niao')
// ('sun', 'ie', 'su', 'nie')
// ('sun', 'in', 'su', 'nin')
// ('sun', 'ing', 'su', 'ning')
// ('sun', 'iong', 'su', 'niong')
// ('sun', 'iu', 'su', 'niu')
// ('sun', 'ong', 'su', 'nong')
// ('sun', 'u', 'su', 'nu')
// ('sun', 'ua', 'su', 'nua')
// ('sun', 'uai', 'su', 'nuai')
// ('sun', 'uan', 'su', 'nuan')
// ('sun', 'uang', 'su', 'nuang')
// ('sun', 'ue', 'su', 'nue')
// ('sun', 'ui', 'su', 'nui')
// ('sun', 'un', 'su', 'nun')
// ('sun', 'uo', 'su', 'nuo')
// ('sun', 'v', 'su', 'nv')
// ('tan', 'a', 'ta', 'na')
// ('tan', 'e', 'ta', 'ne')
// ('tan', 'ei', 'ta', 'nei')
// ('tan', 'eng', 'ta', 'neng')
// ('tan', 'i', 'ta', 'ni')
// ('tan', 'ia', 'ta', 'nia')
// ('tan', 'ian', 'ta', 'nian')
// ('tan', 'iang', 'ta', 'niang')
// ('tan', 'iao', 'ta', 'niao')
// ('tan', 'ie', 'ta', 'nie')
// ('tan', 'in', 'ta', 'nin')
// ('tan', 'ing', 'ta', 'ning')
// ('tan', 'iong', 'ta', 'niong')
// ('tan', 'iu', 'ta', 'niu')
// ('tan', 'ong', 'ta', 'nong')
// ('tan', 'u', 'ta', 'nu')
// ('tan', 'ua', 'ta', 'nua')
// ('tan', 'uai', 'ta', 'nuai')
// ('tan', 'uan', 'ta', 'nuan')
// ('tan', 'uang', 'ta', 'nuang')
// ('tan', 'ue', 'ta', 'nue')
// ('tan', 'ui', 'ta', 'nui')
// ('tan', 'un', 'ta', 'nun')
// ('tan', 'uo', 'ta', 'nuo')
// ('tan', 'v', 'ta', 'nv')
// ('tang', 'a', 'tan', 'ga')
// ('tang', 'ai', 'tan', 'gai')
// ('tang', 'an', 'tan', 'gan')
// ('tang', 'ang', 'tan', 'gang')
// ('tang', 'e', 'tan', 'ge')
// ('tang', 'ei', 'tan', 'gei')
// ('tang', 'eng', 'tan', 'geng')
// ('tang', 'i', 'tan', 'gi')
// ('tang', 'ia', 'tan', 'gia')
// ('tang', 'ian', 'tan', 'gian')
// ('tang', 'iang', 'tan', 'giang')
// ('tang', 'iao', 'tan', 'giao')
// ('tang', 'ie', 'tan', 'gie')
// ('tang', 'in', 'tan', 'gin')
// ('tang', 'ing', 'tan', 'ging')
// ('tang', 'iong', 'tan', 'giong')
// ('tang', 'iu', 'tan', 'giu')
// ('tang', 'ong', 'tan', 'gong')
// ('tang', 'ou', 'tan', 'gou')
// ('tang', 'u', 'tan', 'gu')
// ('tang', 'ua', 'tan', 'gua')
// ('tang', 'uai', 'tan', 'guai')
// ('tang', 'uan', 'tan', 'guan')
// ('tang', 'uang', 'tan', 'guang')
// ('tang', 'ue', 'tan', 'gue')
// ('tang', 'ui', 'tan', 'gui')
// ('tang', 'un', 'tan', 'gun')
// ('tang', 'uo', 'tan', 'guo')
// ('tang', 'v', 'tan', 'gv')
// ('teng', 'eng', 'ten', 'geng')
// ('teng', 'i', 'ten', 'gi')
// ('teng', 'ia', 'ten', 'gia')
// ('teng', 'ian', 'ten', 'gian')
// ('teng', 'iang', 'ten', 'giang')
// ('teng', 'iao', 'ten', 'giao')
// ('teng', 'ie', 'ten', 'gie')
// ('teng', 'in', 'ten', 'gin')
// ('teng', 'ing', 'ten', 'ging')
// ('teng', 'iong', 'ten', 'giong')
// ('teng', 'iu', 'ten', 'giu')
// ('teng', 'ong', 'ten', 'gong')
// ('teng', 'u', 'ten', 'gu')
// ('teng', 'ua', 'ten', 'gua')
// ('teng', 'uai', 'ten', 'guai')
// ('teng', 'uan', 'ten', 'guan')
// ('teng', 'uang', 'ten', 'guang')
// ('teng', 'ue', 'ten', 'gue')
// ('teng', 'ui', 'ten', 'gui')
// ('teng', 'un', 'ten', 'gun')
// ('teng', 'uo', 'ten', 'guo')
// ('teng', 'v', 'ten', 'gv')
// ('tian', 'eng', 'tia', 'neng')
// ('tian', 'i', 'tia', 'ni')
// ('tian', 'ia', 'tia', 'nia')
// ('tian', 'ian', 'tia', 'nian')
// ('tian', 'iang', 'tia', 'niang')
// ('tian', 'iao', 'tia', 'niao')
// ('tian', 'ie', 'tia', 'nie')
// ('tian', 'in', 'tia', 'nin')
// ('tian', 'ing', 'tia', 'ning')
// ('tian', 'iong', 'tia', 'niong')
// ('tian', 'iu', 'tia', 'niu')
// ('tian', 'ong', 'tia', 'nong')
// ('tian', 'u', 'tia', 'nu')
// ('tian', 'ua', 'tia', 'nua')
// ('tian', 'uai', 'tia', 'nuai')
// ('tian', 'uan', 'tia', 'nuan')
// ('tian', 'uang', 'tia', 'nuang')
// ('tian', 'ue', 'tia', 'nue')
// ('tian', 'ui', 'tia', 'nui')
// ('tian', 'un', 'tia', 'nun')
// ('tian', 'uo', 'tia', 'nuo')
// ('tian', 'v', 'tia', 'nv')
// ('ting', 'eng', 'tin', 'geng')
// ('ting', 'i', 'tin', 'gi')
// ('ting', 'ia', 'tin', 'gia')
// ('ting', 'ian', 'tin', 'gian')
// ('ting', 'iang', 'tin', 'giang')
// ('ting', 'iao', 'tin', 'giao')
// ('ting', 'ie', 'tin', 'gie')
// ('ting', 'in', 'tin', 'gin')
// ('ting', 'ing', 'tin', 'ging')
// ('ting', 'iong', 'tin', 'giong')
// ('ting', 'iu', 'tin', 'giu')
// ('ting', 'ong', 'tin', 'gong')
// ('ting', 'u', 'tin', 'gu')
// ('ting', 'ua', 'tin', 'gua')
// ('ting', 'uai', 'tin', 'guai')
// ('ting', 'uan', 'tin', 'guan')
// ('ting', 'uang', 'tin', 'guang')
// ('ting', 'ue', 'tin', 'gue')
// ('ting', 'ui', 'tin', 'gui')
// ('ting', 'un', 'tin', 'gun')
// ('ting', 'uo', 'tin', 'guo')
// ('ting', 'v', 'tin', 'gv')
// ('tong', 'eng', 'ton', 'geng')
// ('tong', 'i', 'ton', 'gi')
// ('tong', 'ia', 'ton', 'gia')
// ('tong', 'ian', 'ton', 'gian')
// ('tong', 'iang', 'ton', 'giang')
// ('tong', 'iao', 'ton', 'giao')
// ('tong', 'ie', 'ton', 'gie')
// ('tong', 'in', 'ton', 'gin')
// ('tong', 'ing', 'ton', 'ging')
// ('tong', 'iong', 'ton', 'giong')
// ('tong', 'iu', 'ton', 'giu')
// ('tong', 'ong', 'ton', 'gong')
// ('tong', 'u', 'ton', 'gu')
// ('tong', 'ua', 'ton', 'gua')
// ('tong', 'uai', 'ton', 'guai')
// ('tong', 'uan', 'ton', 'guan')
// ('tong', 'uang', 'ton', 'guang')
// ('tong', 'ue', 'ton', 'gue')
// ('tong', 'ui', 'ton', 'gui')
// ('tong', 'un', 'ton', 'gun')
// ('tong', 'uo', 'ton', 'guo')
// ('tong', 'v', 'ton', 'gv')
// ('tuan', 'eng', 'tua', 'neng')
// ('tuan', 'i', 'tua', 'ni')
// ('tuan', 'ia', 'tua', 'nia')
// ('tuan', 'ian', 'tua', 'nian')
// ('tuan', 'iang', 'tua', 'niang')
// ('tuan', 'iao', 'tua', 'niao')
// ('tuan', 'ie', 'tua', 'nie')
// ('tuan', 'in', 'tua', 'nin')
// ('tuan', 'ing', 'tua', 'ning')
// ('tuan', 'iong', 'tua', 'niong')
// ('tuan', 'iu', 'tua', 'niu')
// ('tuan', 'ong', 'tua', 'nong')
// ('tuan', 'u', 'tua', 'nu')
// ('tuan', 'ua', 'tua', 'nua')
// ('tuan', 'uai', 'tua', 'nuai')
// ('tuan', 'uan', 'tua', 'nuan')
// ('tuan', 'uang', 'tua', 'nuang')
// ('tuan', 'ue', 'tua', 'nue')
// ('tuan', 'ui', 'tua', 'nui')
// ('tuan', 'un', 'tua', 'nun')
// ('tuan', 'uo', 'tua', 'nuo')
// ('tuan', 'v', 'tua', 'nv')
// ('tun', 'a', 'tu', 'na')
// ('tun', 'ai', 'tu', 'nai')
// ('tun', 'an', 'tu', 'nan')
// ('tun', 'ang', 'tu', 'nang')
// ('tun', 'ao', 'tu', 'nao')
// ('tun', 'e', 'tu', 'ne')
// ('tun', 'ei', 'tu', 'nei')
// ('tun', 'en', 'tu', 'nen')
// ('tun', 'eng', 'tu', 'neng')
// ('tun', 'i', 'tu', 'ni')
// ('tun', 'ia', 'tu', 'nia')
// ('tun', 'ian', 'tu', 'nian')
// ('tun', 'iang', 'tu', 'niang')
// ('tun', 'iao', 'tu', 'niao')
// ('tun', 'ie', 'tu', 'nie')
// ('tun', 'in', 'tu', 'nin')
// ('tun', 'ing', 'tu', 'ning')
// ('tun', 'iong', 'tu', 'niong')
// ('tun', 'iu', 'tu', 'niu')
// ('tun', 'ong', 'tu', 'nong')
// ('tun', 'u', 'tu', 'nu')
// ('tun', 'ua', 'tu', 'nua')
// ('tun', 'uai', 'tu', 'nuai')
// ('tun', 'uan', 'tu', 'nuan')
// ('tun', 'uang', 'tu', 'nuang')
// ('tun', 'ue', 'tu', 'nue')
// ('tun', 'ui', 'tu', 'nui')
// ('tun', 'un', 'tu', 'nun')
// ('tun', 'uo', 'tu', 'nuo')
// ('tun', 'v', 'tu', 'nv')
// ('wan', 'ei', 'wa', 'nei')
// ('wan', 'eng', 'wa', 'neng')
// ('wan', 'i', 'wa', 'ni')
// ('wan', 'ia', 'wa', 'nia')
// ('wan', 'ian', 'wa', 'nian')
// ('wan', 'iang', 'wa', 'niang')
// ('wan', 'iao', 'wa', 'niao')
// ('wan', 'ie', 'wa', 'nie')
// ('wan', 'in', 'wa', 'nin')
// ('wan', 'ing', 'wa', 'ning')
// ('wan', 'iong', 'wa', 'niong')
// ('wan', 'iu', 'wa', 'niu')
// ('wan', 'ong', 'wa', 'nong')
// ('wan', 'u', 'wa', 'nu')
// ('wan', 'ua', 'wa', 'nua')
// ('wan', 'uai', 'wa', 'nuai')
// ('wan', 'uan', 'wa', 'nuan')
// ('wan', 'uang', 'wa', 'nuang')
// ('wan', 'ue', 'wa', 'nue')
// ('wan', 'ui', 'wa', 'nui')
// ('wan', 'un', 'wa', 'nun')
// ('wan', 'uo', 'wa', 'nuo')
// ('wan', 'v', 'wa', 'nv')
// ('wang', 'ang', 'wan', 'gang')
// ('wang', 'ao', 'wan', 'gao')
// ('wang', 'e', 'wan', 'ge')
// ('wang', 'ei', 'wan', 'gei')
// ('wang', 'eng', 'wan', 'geng')
// ('wang', 'i', 'wan', 'gi')
// ('wang', 'ia', 'wan', 'gia')
// ('wang', 'ian', 'wan', 'gian')
// ('wang', 'iang', 'wan', 'giang')
// ('wang', 'iao', 'wan', 'giao')
// ('wang', 'ie', 'wan', 'gie')
// ('wang', 'in', 'wan', 'gin')
// ('wang', 'ing', 'wan', 'ging')
// ('wang', 'iong', 'wan', 'giong')
// ('wang', 'iu', 'wan', 'giu')
// ('wang', 'ong', 'wan', 'gong')
// ('wang', 'ou', 'wan', 'gou')
// ('wang', 'u', 'wan', 'gu')
// ('wang', 'ua', 'wan', 'gua')
// ('wang', 'uai', 'wan', 'guai')
// ('wang', 'uan', 'wan', 'guan')
// ('wang', 'uang', 'wan', 'guang')
// ('wang', 'ue', 'wan', 'gue')
// ('wang', 'ui', 'wan', 'gui')
// ('wang', 'un', 'wan', 'gun')
// ('wang', 'uo', 'wan', 'guo')
// ('wang', 'v', 'wan', 'gv')
// ('wen', 'eng', 'we', 'neng')
// ('wen', 'i', 'we', 'ni')
// ('wen', 'ia', 'we', 'nia')
// ('wen', 'ian', 'we', 'nian')
// ('wen', 'iang', 'we', 'niang')
// ('wen', 'iao', 'we', 'niao')
// ('wen', 'ie', 'we', 'nie')
// ('wen', 'in', 'we', 'nin')
// ('wen', 'ing', 'we', 'ning')
// ('wen', 'iong', 'we', 'niong')
// ('wen', 'iu', 'we', 'niu')
// ('wen', 'ong', 'we', 'nong')
// ('wen', 'u', 'we', 'nu')
// ('wen', 'ua', 'we', 'nua')
// ('wen', 'uai', 'we', 'nuai')
// ('wen', 'uan', 'we', 'nuan')
// ('wen', 'uang', 'we', 'nuang')
// ('wen', 'ue', 'we', 'nue')
// ('wen', 'ui', 'we', 'nui')
// ('wen', 'un', 'we', 'nun')
// ('wen', 'uo', 'we', 'nuo')
// ('wen', 'v', 'we', 'nv')
// ('weng', 'a', 'wen', 'ga')
// ('weng', 'ai', 'wen', 'gai')
// ('weng', 'an', 'wen', 'gan')
// ('weng', 'ang', 'wen', 'gang')
// ('weng', 'ao', 'wen', 'gao')
// ('weng', 'e', 'wen', 'ge')
// ('weng', 'ei', 'wen', 'gei')
// ('weng', 'en', 'wen', 'gen')
// ('weng', 'eng', 'wen', 'geng')
// ('weng', 'i', 'wen', 'gi')
// ('weng', 'ia', 'wen', 'gia')
// ('weng', 'ian', 'wen', 'gian')
// ('weng', 'iang', 'wen', 'giang')
// ('weng', 'iao', 'wen', 'giao')
// ('weng', 'ie', 'wen', 'gie')
// ('weng', 'in', 'wen', 'gin')
// ('weng', 'ing', 'wen', 'ging')
// ('weng', 'iong', 'wen', 'giong')
// ('weng', 'iu', 'wen', 'giu')
// ('weng', 'ong', 'wen', 'gong')
// ('weng', 'ou', 'wen', 'gou')
// ('weng', 'u', 'wen', 'gu')
// ('weng', 'ua', 'wen', 'gua')
// ('weng', 'uai', 'wen', 'guai')
// ('weng', 'uan', 'wen', 'guan')
// ('weng', 'uang', 'wen', 'guang')
// ('weng', 'ue', 'wen', 'gue')
// ('weng', 'ui', 'wen', 'gui')
// ('weng', 'un', 'wen', 'gun')
// ('weng', 'uo', 'wen', 'guo')
// ('weng', 'v', 'wen', 'gv')
// ('xian', 'a', 'xia', 'na')
// ('xian', 'ao', 'xia', 'nao')
// ('xian', 'ei', 'xia', 'nei')
// ('xian', 'eng', 'xia', 'neng')
// ('xian', 'i', 'xia', 'ni')
// ('xian', 'ia', 'xia', 'nia')
// ('xian', 'ian', 'xia', 'nian')
// ('xian', 'iang', 'xia', 'niang')
// ('xian', 'iao', 'xia', 'niao')
// ('xian', 'ie', 'xia', 'nie')
// ('xian', 'in', 'xia', 'nin')
// ('xian', 'ing', 'xia', 'ning')
// ('xian', 'iong', 'xia', 'niong')
// ('xian', 'iu', 'xia', 'niu')
// ('xian', 'ong', 'xia', 'nong')
// ('xian', 'u', 'xia', 'nu')
// ('xian', 'ua', 'xia', 'nua')
// ('xian', 'uai', 'xia', 'nuai')
// ('xian', 'uan', 'xia', 'nuan')
// ('xian', 'uang', 'xia', 'nuang')
// ('xian', 'ue', 'xia', 'nue')
// ('xian', 'ui', 'xia', 'nui')
// ('xian', 'un', 'xia', 'nun')
// ('xian', 'uo', 'xia', 'nuo')
// ('xian', 'v', 'xia', 'nv')
// ('xiang', 'ang', 'xian', 'gang')
// ('xiang', 'ao', 'xian', 'gao')
// ('xiang', 'ei', 'xian', 'gei')
// ('xiang', 'en', 'xian', 'gen')
// ('xiang', 'eng', 'xian', 'geng')
// ('xiang', 'i', 'xian', 'gi')
// ('xiang', 'ia', 'xian', 'gia')
// ('xiang', 'ian', 'xian', 'gian')
// ('xiang', 'iang', 'xian', 'giang')
// ('xiang', 'iao', 'xian', 'giao')
// ('xiang', 'ie', 'xian', 'gie')
// ('xiang', 'in', 'xian', 'gin')
// ('xiang', 'ing', 'xian', 'ging')
// ('xiang', 'iong', 'xian', 'giong')
// ('xiang', 'iu', 'xian', 'giu')
// ('xiang', 'ong', 'xian', 'gong')
// ('xiang', 'ou', 'xian', 'gou')
// ('xiang', 'u', 'xian', 'gu')
// ('xiang', 'ua', 'xian', 'gua')
// ('xiang', 'uai', 'xian', 'guai')
// ('xiang', 'uan', 'xian', 'guan')
// ('xiang', 'uang', 'xian', 'guang')
// ('xiang', 'ue', 'xian', 'gue')
// ('xiang', 'ui', 'xian', 'gui')
// ('xiang', 'un', 'xian', 'gun')
// ('xiang', 'uo', 'xian', 'guo')
// ('xiang', 'v', 'xian', 'gv')
// ('xin', 'a', 'xi', 'na')
// ('xin', 'an', 'xi', 'nan')
// ('xin', 'e', 'xi', 'ne')
// ('xin', 'ei', 'xi', 'nei')
// ('xin', 'en', 'xi', 'nen')
// ('xin', 'eng', 'xi', 'neng')
// ('xin', 'i', 'xi', 'ni')
// ('xin', 'ia', 'xi', 'nia')
// ('xin', 'ian', 'xi', 'nian')
// ('xin', 'iang', 'xi', 'niang')
// ('xin', 'iao', 'xi', 'niao')
// ('xin', 'ie', 'xi', 'nie')
// ('xin', 'in', 'xi', 'nin')
// ('xin', 'ing', 'xi', 'ning')
// ('xin', 'iong', 'xi', 'niong')
// ('xin', 'iu', 'xi', 'niu')
// ('xin', 'ong', 'xi', 'nong')
// ('xin', 'u', 'xi', 'nu')
// ('xin', 'ua', 'xi', 'nua')
// ('xin', 'uai', 'xi', 'nuai')
// ('xin', 'uan', 'xi', 'nuan')
// ('xin', 'uang', 'xi', 'nuang')
// ('xin', 'ue', 'xi', 'nue')
// ('xin', 'ui', 'xi', 'nui')
// ('xin', 'un', 'xi', 'nun')
// ('xin', 'uo', 'xi', 'nuo')
// ('xin', 'v', 'xi', 'nv')
// ('xing', 'an', 'xin', 'gan')
// ('xing', 'ang', 'xin', 'gang')
// ('xing', 'ao', 'xin', 'gao')
// ('xing', 'e', 'xin', 'ge')
// ('xing', 'ei', 'xin', 'gei')
// ('xing', 'en', 'xin', 'gen')
// ('xing', 'eng', 'xin', 'geng')
// ('xing', 'i', 'xin', 'gi')
// ('xing', 'ia', 'xin', 'gia')
// ('xing', 'ian', 'xin', 'gian')
// ('xing', 'iang', 'xin', 'giang')
// ('xing', 'iao', 'xin', 'giao')
// ('xing', 'ie', 'xin', 'gie')
// ('xing', 'in', 'xin', 'gin')
// ('xing', 'ing', 'xin', 'ging')
// ('xing', 'iong', 'xin', 'giong')
// ('xing', 'iu', 'xin', 'giu')
// ('xing', 'ong', 'xin', 'gong')
// ('xing', 'ou', 'xin', 'gou')
// ('xing', 'u', 'xin', 'gu')
// ('xing', 'ua', 'xin', 'gua')
// ('xing', 'uai', 'xin', 'guai')
// ('xing', 'uan', 'xin', 'guan')
// ('xing', 'uang', 'xin', 'guang')
// ('xing', 'ue', 'xin', 'gue')
// ('xing', 'ui', 'xin', 'gui')
// ('xing', 'un', 'xin', 'gun')
// ('xing', 'uo', 'xin', 'guo')
// ('xing', 'v', 'xin', 'gv')
// ('xiong', 'eng', 'xion', 'geng')
// ('xiong', 'i', 'xion', 'gi')
// ('xiong', 'ia', 'xion', 'gia')
// ('xiong', 'ian', 'xion', 'gian')
// ('xiong', 'iang', 'xion', 'giang')
// ('xiong', 'iao', 'xion', 'giao')
// ('xiong', 'ie', 'xion', 'gie')
// ('xiong', 'in', 'xion', 'gin')
// ('xiong', 'ing', 'xion', 'ging')
// ('xiong', 'iong', 'xion', 'giong')
// ('xiong', 'iu', 'xion', 'giu')
// ('xiong', 'ong', 'xion', 'gong')
// ('xiong', 'u', 'xion', 'gu')
// ('xiong', 'ua', 'xion', 'gua')
// ('xiong', 'uai', 'xion', 'guai')
// ('xiong', 'uan', 'xion', 'guan')
// ('xiong', 'uang', 'xion', 'guang')
// ('xiong', 'ue', 'xion', 'gue')
// ('xiong', 'ui', 'xion', 'gui')
// ('xiong', 'un', 'xion', 'gun')
// ('xiong', 'uo', 'xion', 'guo')
// ('xiong', 'v', 'xion', 'gv')
// ('xuan', 'eng', 'xua', 'neng')
// ('xuan', 'i', 'xua', 'ni')
// ('xuan', 'ia', 'xua', 'nia')
// ('xuan', 'ian', 'xua', 'nian')
// ('xuan', 'iang', 'xua', 'niang')
// ('xuan', 'iao', 'xua', 'niao')
// ('xuan', 'ie', 'xua', 'nie')
// ('xuan', 'in', 'xua', 'nin')
// ('xuan', 'ing', 'xua', 'ning')
// ('xuan', 'iong', 'xua', 'niong')
// ('xuan', 'iu', 'xua', 'niu')
// ('xuan', 'ong', 'xua', 'nong')
// ('xuan', 'u', 'xua', 'nu')
// ('xuan', 'ua', 'xua', 'nua')
// ('xuan', 'uai', 'xua', 'nuai')
// ('xuan', 'uan', 'xua', 'nuan')
// ('xuan', 'uang', 'xua', 'nuang')
// ('xuan', 'ue', 'xua', 'nue')
// ('xuan', 'ui', 'xua', 'nui')
// ('xuan', 'un', 'xua', 'nun')
// ('xuan', 'uo', 'xua', 'nuo')
// ('xuan', 'v', 'xua', 'nv')
// ('xun', 'ei', 'xu', 'nei')
// ('xun', 'eng', 'xu', 'neng')
// ('xun', 'i', 'xu', 'ni')
// ('xun', 'ia', 'xu', 'nia')
// ('xun', 'ian', 'xu', 'nian')
// ('xun', 'iang', 'xu', 'niang')
// ('xun', 'iao', 'xu', 'niao')
// ('xun', 'ie', 'xu', 'nie')
// ('xun', 'in', 'xu', 'nin')
// ('xun', 'ing', 'xu', 'ning')
// ('xun', 'iong', 'xu', 'niong')
// ('xun', 'iu', 'xu', 'niu')
// ('xun', 'ong', 'xu', 'nong')
// ('xun', 'u', 'xu', 'nu')
// ('xun', 'ua', 'xu', 'nua')
// ('xun', 'uai', 'xu', 'nuai')
// ('xun', 'uan', 'xu', 'nuan')
// ('xun', 'uang', 'xu', 'nuang')
// ('xun', 'ue', 'xu', 'nue')
// ('xun', 'ui', 'xu', 'nui')
// ('xun', 'un', 'xu', 'nun')
// ('xun', 'uo', 'xu', 'nuo')
// ('xun', 'v', 'xu', 'nv')
// ('yan', 'a', 'ya', 'na')
// ('yan', 'ei', 'ya', 'nei')
// ('yan', 'eng', 'ya', 'neng')
// ('yan', 'i', 'ya', 'ni')
// ('yan', 'ia', 'ya', 'nia')
// ('yan', 'ian', 'ya', 'nian')
// ('yan', 'iang', 'ya', 'niang')
// ('yan', 'iao', 'ya', 'niao')
// ('yan', 'ie', 'ya', 'nie')
// ('yan', 'in', 'ya', 'nin')
// ('yan', 'ing', 'ya', 'ning')
// ('yan', 'iong', 'ya', 'niong')
// ('yan', 'iu', 'ya', 'niu')
// ('yan', 'ong', 'ya', 'nong')
// ('yan', 'u', 'ya', 'nu')
// ('yan', 'ua', 'ya', 'nua')
// ('yan', 'uai', 'ya', 'nuai')
// ('yan', 'uan', 'ya', 'nuan')
// ('yan', 'uang', 'ya', 'nuang')
// ('yan', 'ue', 'ya', 'nue')
// ('yan', 'ui', 'ya', 'nui')
// ('yan', 'un', 'ya', 'nun')
// ('yan', 'uo', 'ya', 'nuo')
// ('yan', 'v', 'ya', 'nv')
// ('yang', 'ai', 'yan', 'gai')
// ('yang', 'an', 'yan', 'gan')
// ('yang', 'ang', 'yan', 'gang')
// ('yang', 'ao', 'yan', 'gao')
// ('yang', 'e', 'yan', 'ge')
// ('yang', 'ei', 'yan', 'gei')
// ('yang', 'eng', 'yan', 'geng')
// ('yang', 'i', 'yan', 'gi')
// ('yang', 'ia', 'yan', 'gia')
// ('yang', 'ian', 'yan', 'gian')
// ('yang', 'iang', 'yan', 'giang')
// ('yang', 'iao', 'yan', 'giao')
// ('yang', 'ie', 'yan', 'gie')
// ('yang', 'in', 'yan', 'gin')
// ('yang', 'ing', 'yan', 'ging')
// ('yang', 'iong', 'yan', 'giong')
// ('yang', 'iu', 'yan', 'giu')
// ('yang', 'ong', 'yan', 'gong')
// ('yang', 'ou', 'yan', 'gou')
// ('yang', 'u', 'yan', 'gu')
// ('yang', 'ua', 'yan', 'gua')
// ('yang', 'uai', 'yan', 'guai')
// ('yang', 'uan', 'yan', 'guan')
// ('yang', 'uang', 'yan', 'guang')
// ('yang', 'ue', 'yan', 'gue')
// ('yang', 'ui', 'yan', 'gui')
// ('yang', 'un', 'yan', 'gun')
// ('yang', 'uo', 'yan', 'guo')
// ('yang', 'v', 'yan', 'gv')
// ('yin', 'a', 'yi', 'na')
// ('yin', 'ai', 'yi', 'nai')
// ('yin', 'an', 'yi', 'nan')
// ('yin', 'ao', 'yi', 'nao')
// ('yin', 'ei', 'yi', 'nei')
// ('yin', 'eng', 'yi', 'neng')
// ('yin', 'i', 'yi', 'ni')
// ('yin', 'ia', 'yi', 'nia')
// ('yin', 'ian', 'yi', 'nian')
// ('yin', 'iang', 'yi', 'niang')
// ('yin', 'iao', 'yi', 'niao')
// ('yin', 'ie', 'yi', 'nie')
// ('yin', 'in', 'yi', 'nin')
// ('yin', 'ing', 'yi', 'ning')
// ('yin', 'iong', 'yi', 'niong')
// ('yin', 'iu', 'yi', 'niu')
// ('yin', 'ong', 'yi', 'nong')
// ('yin', 'u', 'yi', 'nu')
// ('yin', 'ua', 'yi', 'nua')
// ('yin', 'uai', 'yi', 'nuai')
// ('yin', 'uan', 'yi', 'nuan')
// ('yin', 'uang', 'yi', 'nuang')
// ('yin', 'ue', 'yi', 'nue')
// ('yin', 'ui', 'yi', 'nui')
// ('yin', 'un', 'yi', 'nun')
// ('yin', 'uo', 'yi', 'nuo')
// ('yin', 'v', 'yi', 'nv')
// ('ying', 'ai', 'yin', 'gai')
// ('ying', 'ang', 'yin', 'gang')
// ('ying', 'ao', 'yin', 'gao')
// ('ying', 'ei', 'yin', 'gei')
// ('ying', 'en', 'yin', 'gen')
// ('ying', 'eng', 'yin', 'geng')
// ('ying', 'i', 'yin', 'gi')
// ('ying', 'ia', 'yin', 'gia')
// ('ying', 'ian', 'yin', 'gian')
// ('ying', 'iang', 'yin', 'giang')
// ('ying', 'iao', 'yin', 'giao')
// ('ying', 'ie', 'yin', 'gie')
// ('ying', 'in', 'yin', 'gin')
// ('ying', 'ing', 'yin', 'ging')
// ('ying', 'iong', 'yin', 'giong')
// ('ying', 'iu', 'yin', 'giu')
// ('ying', 'ong', 'yin', 'gong')
// ('ying', 'ou', 'yin', 'gou')
// ('ying', 'u', 'yin', 'gu')
// ('ying', 'ua', 'yin', 'gua')
// ('ying', 'uai', 'yin', 'guai')
// ('ying', 'uan', 'yin', 'guan')
// ('ying', 'uang', 'yin', 'guang')
// ('ying', 'ue', 'yin', 'gue')
// ('ying', 'ui', 'yin', 'gui')
// ('ying', 'un', 'yin', 'gun')
// ('ying', 'uo', 'yin', 'guo')
// ('ying', 'v', 'yin', 'gv')
// ('yong', 'eng', 'yon', 'geng')
// ('yong', 'i', 'yon', 'gi')
// ('yong', 'ia', 'yon', 'gia')
// ('yong', 'ian', 'yon', 'gian')
// ('yong', 'iang', 'yon', 'giang')
// ('yong', 'iao', 'yon', 'giao')
// ('yong', 'ie', 'yon', 'gie')
// ('yong', 'in', 'yon', 'gin')
// ('yong', 'ing', 'yon', 'ging')
// ('yong', 'iong', 'yon', 'giong')
// ('yong', 'iu', 'yon', 'giu')
// ('yong', 'ong', 'yon', 'gong')
// ('yong', 'u', 'yon', 'gu')
// ('yong', 'ua', 'yon', 'gua')
// ('yong', 'uai', 'yon', 'guai')
// ('yong', 'uan', 'yon', 'guan')
// ('yong', 'uang', 'yon', 'guang')
// ('yong', 'ue', 'yon', 'gue')
// ('yong', 'ui', 'yon', 'gui')
// ('yong', 'un', 'yon', 'gun')
// ('yong', 'uo', 'yon', 'guo')
// ('yong', 'v', 'yon', 'gv')
// ('yuan', 'eng', 'yua', 'neng')
// ('yuan', 'i', 'yua', 'ni')
// ('yuan', 'ia', 'yua', 'nia')
// ('yuan', 'ian', 'yua', 'nian')
// ('yuan', 'iang', 'yua', 'niang')
// ('yuan', 'iao', 'yua', 'niao')
// ('yuan', 'ie', 'yua', 'nie')
// ('yuan', 'in', 'yua', 'nin')
// ('yuan', 'ing', 'yua', 'ning')
// ('yuan', 'iong', 'yua', 'niong')
// ('yuan', 'iu', 'yua', 'niu')
// ('yuan', 'ong', 'yua', 'nong')
// ('yuan', 'u', 'yua', 'nu')
// ('yuan', 'ua', 'yua', 'nua')
// ('yuan', 'uai', 'yua', 'nuai')
// ('yuan', 'uan', 'yua', 'nuan')
// ('yuan', 'uang', 'yua', 'nuang')
// ('yuan', 'ue', 'yua', 'nue')
// ('yuan', 'ui', 'yua', 'nui')
// ('yuan', 'un', 'yua', 'nun')
// ('yuan', 'uo', 'yua', 'nuo')
// ('yuan', 'v', 'yua', 'nv')
// ('yun', 'a', 'yu', 'na')
// ('yun', 'ai', 'yu', 'nai')
// ('yun', 'an', 'yu', 'nan')
// ('yun', 'e', 'yu', 'ne')
// ('yun', 'ei', 'yu', 'nei')
// ('yun', 'eng', 'yu', 'neng')
// ('yun', 'i', 'yu', 'ni')
// ('yun', 'ia', 'yu', 'nia')
// ('yun', 'ian', 'yu', 'nian')
// ('yun', 'iang', 'yu', 'niang')
// ('yun', 'iao', 'yu', 'niao')
// ('yun', 'ie', 'yu', 'nie')
// ('yun', 'in', 'yu', 'nin')
// ('yun', 'ing', 'yu', 'ning')
// ('yun', 'iong', 'yu', 'niong')
// ('yun', 'iu', 'yu', 'niu')
// ('yun', 'ong', 'yu', 'nong')
// ('yun', 'u', 'yu', 'nu')
// ('yun', 'ua', 'yu', 'nua')
// ('yun', 'uai', 'yu', 'nuai')
// ('yun', 'uan', 'yu', 'nuan')
// ('yun', 'uang', 'yu', 'nuang')
// ('yun', 'ue', 'yu', 'nue')
// ('yun', 'ui', 'yu', 'nui')
// ('yun', 'un', 'yu', 'nun')
// ('yun', 'uo', 'yu', 'nuo')
// ('yun', 'v', 'yu', 'nv')
// ('zan', 'a', 'za', 'na')
// ('zan', 'ei', 'za', 'nei')
// ('zan', 'eng', 'za', 'neng')
// ('zan', 'i', 'za', 'ni')
// ('zan', 'ia', 'za', 'nia')
// ('zan', 'ian', 'za', 'nian')
// ('zan', 'iang', 'za', 'niang')
// ('zan', 'iao', 'za', 'niao')
// ('zan', 'ie', 'za', 'nie')
// ('zan', 'in', 'za', 'nin')
// ('zan', 'ing', 'za', 'ning')
// ('zan', 'iong', 'za', 'niong')
// ('zan', 'iu', 'za', 'niu')
// ('zan', 'ong', 'za', 'nong')
// ('zan', 'u', 'za', 'nu')
// ('zan', 'ua', 'za', 'nua')
// ('zan', 'uai', 'za', 'nuai')
// ('zan', 'uan', 'za', 'nuan')
// ('zan', 'uang', 'za', 'nuang')
// ('zan', 'ue', 'za', 'nue')
// ('zan', 'ui', 'za', 'nui')
// ('zan', 'un', 'za', 'nun')
// ('zan', 'uo', 'za', 'nuo')
// ('zan', 'v', 'za', 'nv')
// ('zang', 'an', 'zan', 'gan')
// ('zang', 'ang', 'zan', 'gang')
// ('zang', 'ao', 'zan', 'gao')
// ('zang', 'e', 'zan', 'ge')
// ('zang', 'ei', 'zan', 'gei')
// ('zang', 'en', 'zan', 'gen')
// ('zang', 'eng', 'zan', 'geng')
// ('zang', 'i', 'zan', 'gi')
// ('zang', 'ia', 'zan', 'gia')
// ('zang', 'ian', 'zan', 'gian')
// ('zang', 'iang', 'zan', 'giang')
// ('zang', 'iao', 'zan', 'giao')
// ('zang', 'ie', 'zan', 'gie')
// ('zang', 'in', 'zan', 'gin')
// ('zang', 'ing', 'zan', 'ging')
// ('zang', 'iong', 'zan', 'giong')
// ('zang', 'iu', 'zan', 'giu')
// ('zang', 'ong', 'zan', 'gong')
// ('zang', 'ou', 'zan', 'gou')
// ('zang', 'u', 'zan', 'gu')
// ('zang', 'ua', 'zan', 'gua')
// ('zang', 'uai', 'zan', 'guai')
// ('zang', 'uan', 'zan', 'guan')
// ('zang', 'uang', 'zan', 'guang')
// ('zang', 'ue', 'zan', 'gue')
// ('zang', 'ui', 'zan', 'gui')
// ('zang', 'un', 'zan', 'gun')
// ('zang', 'uo', 'zan', 'guo')
// ('zang', 'v', 'zan', 'gv')
// ('zen', 'a', 'ze', 'na')
// ('zen', 'an', 'ze', 'nan')
// ('zen', 'ei', 'ze', 'nei')
// ('zen', 'eng', 'ze', 'neng')
// ('zen', 'i', 'ze', 'ni')
// ('zen', 'ia', 'ze', 'nia')
// ('zen', 'ian', 'ze', 'nian')
// ('zen', 'iang', 'ze', 'niang')
// ('zen', 'iao', 'ze', 'niao')
// ('zen', 'ie', 'ze', 'nie')
// ('zen', 'in', 'ze', 'nin')
// ('zen', 'ing', 'ze', 'ning')
// ('zen', 'iong', 'ze', 'niong')
// ('zen', 'iu', 'ze', 'niu')
// ('zen', 'ong', 'ze', 'nong')
// ('zen', 'u', 'ze', 'nu')
// ('zen', 'ua', 'ze', 'nua')
// ('zen', 'uai', 'ze', 'nuai')
// ('zen', 'uan', 'ze', 'nuan')
// ('zen', 'uang', 'ze', 'nuang')
// ('zen', 'ue', 'ze', 'nue')
// ('zen', 'ui', 'ze', 'nui')
// ('zen', 'un', 'ze', 'nun')
// ('zen', 'uo', 'ze', 'nuo')
// ('zen', 'v', 'ze', 'nv')
// ('zeng', 'ai', 'zen', 'gai')
// ('zeng', 'an', 'zen', 'gan')
// ('zeng', 'ang', 'zen', 'gang')
// ('zeng', 'ao', 'zen', 'gao')
// ('zeng', 'ei', 'zen', 'gei')
// ('zeng', 'en', 'zen', 'gen')
// ('zeng', 'eng', 'zen', 'geng')
// ('zeng', 'i', 'zen', 'gi')
// ('zeng', 'ia', 'zen', 'gia')
// ('zeng', 'ian', 'zen', 'gian')
// ('zeng', 'iang', 'zen', 'giang')
// ('zeng', 'iao', 'zen', 'giao')
// ('zeng', 'ie', 'zen', 'gie')
// ('zeng', 'in', 'zen', 'gin')
// ('zeng', 'ing', 'zen', 'ging')
// ('zeng', 'iong', 'zen', 'giong')
// ('zeng', 'iu', 'zen', 'giu')
// ('zeng', 'ong', 'zen', 'gong')
// ('zeng', 'ou', 'zen', 'gou')
// ('zeng', 'u', 'zen', 'gu')
// ('zeng', 'ua', 'zen', 'gua')
// ('zeng', 'uai', 'zen', 'guai')
// ('zeng', 'uan', 'zen', 'guan')
// ('zeng', 'uang', 'zen', 'guang')
// ('zeng', 'ue', 'zen', 'gue')
// ('zeng', 'ui', 'zen', 'gui')
// ('zeng', 'un', 'zen', 'gun')
// ('zeng', 'uo', 'zen', 'guo')
// ('zeng', 'v', 'zen', 'gv')
// ('zhan', 'ei', 'zha', 'nei')
// ('zhan', 'eng', 'zha', 'neng')
// ('zhan', 'i', 'zha', 'ni')
// ('zhan', 'ia', 'zha', 'nia')
// ('zhan', 'ian', 'zha', 'nian')
// ('zhan', 'iang', 'zha', 'niang')
// ('zhan', 'iao', 'zha', 'niao')
// ('zhan', 'ie', 'zha', 'nie')
// ('zhan', 'in', 'zha', 'nin')
// ('zhan', 'ing', 'zha', 'ning')
// ('zhan', 'iong', 'zha', 'niong')
// ('zhan', 'iu', 'zha', 'niu')
// ('zhan', 'ong', 'zha', 'nong')
// ('zhan', 'u', 'zha', 'nu')
// ('zhan', 'ua', 'zha', 'nua')
// ('zhan', 'uai', 'zha', 'nuai')
// ('zhan', 'uan', 'zha', 'nuan')
// ('zhan', 'uang', 'zha', 'nuang')
// ('zhan', 'ue', 'zha', 'nue')
// ('zhan', 'ui', 'zha', 'nui')
// ('zhan', 'un', 'zha', 'nun')
// ('zhan', 'uo', 'zha', 'nuo')
// ('zhan', 'v', 'zha', 'nv')
// ('zhang', 'an', 'zhan', 'gan')
// ('zhang', 'ang', 'zhan', 'gang')
// ('zhang', 'ao', 'zhan', 'gao')
// ('zhang', 'e', 'zhan', 'ge')
// ('zhang', 'ei', 'zhan', 'gei')
// ('zhang', 'en', 'zhan', 'gen')
// ('zhang', 'eng', 'zhan', 'geng')
// ('zhang', 'i', 'zhan', 'gi')
// ('zhang', 'ia', 'zhan', 'gia')
// ('zhang', 'ian', 'zhan', 'gian')
// ('zhang', 'iang', 'zhan', 'giang')
// ('zhang', 'iao', 'zhan', 'giao')
// ('zhang', 'ie', 'zhan', 'gie')
// ('zhang', 'in', 'zhan', 'gin')
// ('zhang', 'ing', 'zhan', 'ging')
// ('zhang', 'iong', 'zhan', 'giong')
// ('zhang', 'iu', 'zhan', 'giu')
// ('zhang', 'ong', 'zhan', 'gong')
// ('zhang', 'ou', 'zhan', 'gou')
// ('zhang', 'u', 'zhan', 'gu')
// ('zhang', 'ua', 'zhan', 'gua')
// ('zhang', 'uai', 'zhan', 'guai')
// ('zhang', 'uan', 'zhan', 'guan')
// ('zhang', 'uang', 'zhan', 'guang')
// ('zhang', 'ue', 'zhan', 'gue')
// ('zhang', 'ui', 'zhan', 'gui')
// ('zhang', 'un', 'zhan', 'gun')
// ('zhang', 'uo', 'zhan', 'guo')
// ('zhang', 'v', 'zhan', 'gv')
// ('zhen', 'a', 'zhe', 'na')
// ('zhen', 'an', 'zhe', 'nan')
// ('zhen', 'ao', 'zhe', 'nao')
// ('zhen', 'e', 'zhe', 'ne')
// ('zhen', 'ei', 'zhe', 'nei')
// ('zhen', 'eng', 'zhe', 'neng')
// ('zhen', 'i', 'zhe', 'ni')
// ('zhen', 'ia', 'zhe', 'nia')
// ('zhen', 'ian', 'zhe', 'nian')
// ('zhen', 'iang', 'zhe', 'niang')
// ('zhen', 'iao', 'zhe', 'niao')
// ('zhen', 'ie', 'zhe', 'nie')
// ('zhen', 'in', 'zhe', 'nin')
// ('zhen', 'ing', 'zhe', 'ning')
// ('zhen', 'iong', 'zhe', 'niong')
// ('zhen', 'iu', 'zhe', 'niu')
// ('zhen', 'ong', 'zhe', 'nong')
// ('zhen', 'u', 'zhe', 'nu')
// ('zhen', 'ua', 'zhe', 'nua')
// ('zhen', 'uai', 'zhe', 'nuai')
// ('zhen', 'uan', 'zhe', 'nuan')
// ('zhen', 'uang', 'zhe', 'nuang')
// ('zhen', 'ue', 'zhe', 'nue')
// ('zhen', 'ui', 'zhe', 'nui')
// ('zhen', 'un', 'zhe', 'nun')
// ('zhen', 'uo', 'zhe', 'nuo')
// ('zhen', 'v', 'zhe', 'nv')
// ('zheng', 'ai', 'zhen', 'gai')
// ('zheng', 'an', 'zhen', 'gan')
// ('zheng', 'ang', 'zhen', 'gang')
// ('zheng', 'ao', 'zhen', 'gao')
// ('zheng', 'e', 'zhen', 'ge')
// ('zheng', 'ei', 'zhen', 'gei')
// ('zheng', 'en', 'zhen', 'gen')
// ('zheng', 'eng', 'zhen', 'geng')
// ('zheng', 'i', 'zhen', 'gi')
// ('zheng', 'ia', 'zhen', 'gia')
// ('zheng', 'ian', 'zhen', 'gian')
// ('zheng', 'iang', 'zhen', 'giang')
// ('zheng', 'iao', 'zhen', 'giao')
// ('zheng', 'ie', 'zhen', 'gie')
// ('zheng', 'in', 'zhen', 'gin')
// ('zheng', 'ing', 'zhen', 'ging')
// ('zheng', 'iong', 'zhen', 'giong')
// ('zheng', 'iu', 'zhen', 'giu')
// ('zheng', 'ong', 'zhen', 'gong')
// ('zheng', 'ou', 'zhen', 'gou')
// ('zheng', 'u', 'zhen', 'gu')
// ('zheng', 'ua', 'zhen', 'gua')
// ('zheng', 'uai', 'zhen', 'guai')
// ('zheng', 'uan', 'zhen', 'guan')
// ('zheng', 'uang', 'zhen', 'guang')
// ('zheng', 'ue', 'zhen', 'gue')
// ('zheng', 'ui', 'zhen', 'gui')
// ('zheng', 'un', 'zhen', 'gun')
// ('zheng', 'uo', 'zhen', 'guo')
// ('zheng', 'v', 'zhen', 'gv')
// ('zhong', 'eng', 'zhon', 'geng')
// ('zhong', 'i', 'zhon', 'gi')
// ('zhong', 'ia', 'zhon', 'gia')
// ('zhong', 'ian', 'zhon', 'gian')
// ('zhong', 'iang', 'zhon', 'giang')
// ('zhong', 'iao', 'zhon', 'giao')
// ('zhong', 'ie', 'zhon', 'gie')
// ('zhong', 'in', 'zhon', 'gin')
// ('zhong', 'ing', 'zhon', 'ging')
// ('zhong', 'iong', 'zhon', 'giong')
// ('zhong', 'iu', 'zhon', 'giu')
// ('zhong', 'ong', 'zhon', 'gong')
// ('zhong', 'u', 'zhon', 'gu')
// ('zhong', 'ua', 'zhon', 'gua')
// ('zhong', 'uai', 'zhon', 'guai')
// ('zhong', 'uan', 'zhon', 'guan')
// ('zhong', 'uang', 'zhon', 'guang')
// ('zhong', 'ue', 'zhon', 'gue')
// ('zhong', 'ui', 'zhon', 'gui')
// ('zhong', 'un', 'zhon', 'gun')
// ('zhong', 'uo', 'zhon', 'guo')
// ('zhong', 'v', 'zhon', 'gv')
// ('zhuan', 'ao', 'zhua', 'nao')
// ('zhuan', 'ei', 'zhua', 'nei')
// ('zhuan', 'eng', 'zhua', 'neng')
// ('zhuan', 'i', 'zhua', 'ni')
// ('zhuan', 'ia', 'zhua', 'nia')
// ('zhuan', 'ian', 'zhua', 'nian')
// ('zhuan', 'iang', 'zhua', 'niang')
// ('zhuan', 'iao', 'zhua', 'niao')
// ('zhuan', 'ie', 'zhua', 'nie')
// ('zhuan', 'in', 'zhua', 'nin')
// ('zhuan', 'ing', 'zhua', 'ning')
// ('zhuan', 'iong', 'zhua', 'niong')
// ('zhuan', 'iu', 'zhua', 'niu')
// ('zhuan', 'ong', 'zhua', 'nong')
// ('zhuan', 'u', 'zhua', 'nu')
// ('zhuan', 'ua', 'zhua', 'nua')
// ('zhuan', 'uai', 'zhua', 'nuai')
// ('zhuan', 'uan', 'zhua', 'nuan')
// ('zhuan', 'uang', 'zhua', 'nuang')
// ('zhuan', 'ue', 'zhua', 'nue')
// ('zhuan', 'ui', 'zhua', 'nui')
// ('zhuan', 'un', 'zhua', 'nun')
// ('zhuan', 'uo', 'zhua', 'nuo')
// ('zhuan', 'v', 'zhua', 'nv')
// ('zhuang', 'ai', 'zhuan', 'gai')
// ('zhuang', 'an', 'zhuan', 'gan')
// ('zhuang', 'ang', 'zhuan', 'gang')
// ('zhuang', 'ao', 'zhuan', 'gao')
// ('zhuang', 'e', 'zhuan', 'ge')
// ('zhuang', 'ei', 'zhuan', 'gei')
// ('zhuang', 'en', 'zhuan', 'gen')
// ('zhuang', 'eng', 'zhuan', 'geng')
// ('zhuang', 'i', 'zhuan', 'gi')
// ('zhuang', 'ia', 'zhuan', 'gia')
// ('zhuang', 'ian', 'zhuan', 'gian')
// ('zhuang', 'iang', 'zhuan', 'giang')
// ('zhuang', 'iao', 'zhuan', 'giao')
// ('zhuang', 'ie', 'zhuan', 'gie')
// ('zhuang', 'in', 'zhuan', 'gin')
// ('zhuang', 'ing', 'zhuan', 'ging')
// ('zhuang', 'iong', 'zhuan', 'giong')
// ('zhuang', 'iu', 'zhuan', 'giu')
// ('zhuang', 'ong', 'zhuan', 'gong')
// ('zhuang', 'ou', 'zhuan', 'gou')
// ('zhuang', 'u', 'zhuan', 'gu')
// ('zhuang', 'ua', 'zhuan', 'gua')
// ('zhuang', 'uai', 'zhuan', 'guai')
// ('zhuang', 'uan', 'zhuan', 'guan')
// ('zhuang', 'uang', 'zhuan', 'guang')
// ('zhuang', 'ue', 'zhuan', 'gue')
// ('zhuang', 'ui', 'zhuan', 'gui')
// ('zhuang', 'un', 'zhuan', 'gun')
// ('zhuang', 'uo', 'zhuan', 'guo')
// ('zhuang', 'v', 'zhuan', 'gv')
// ('zhun', 'a', 'zhu', 'na')
// ('zhun', 'an', 'zhu', 'nan')
// ('zhun', 'ao', 'zhu', 'nao')
// ('zhun', 'e', 'zhu', 'ne')
// ('zhun', 'ei', 'zhu', 'nei')
// ('zhun', 'eng', 'zhu', 'neng')
// ('zhun', 'i', 'zhu', 'ni')
// ('zhun', 'ia', 'zhu', 'nia')
// ('zhun', 'ian', 'zhu', 'nian')
// ('zhun', 'iang', 'zhu', 'niang')
// ('zhun', 'iao', 'zhu', 'niao')
// ('zhun', 'ie', 'zhu', 'nie')
// ('zhun', 'in', 'zhu', 'nin')
// ('zhun', 'ing', 'zhu', 'ning')
// ('zhun', 'iong', 'zhu', 'niong')
// ('zhun', 'iu', 'zhu', 'niu')
// ('zhun', 'ong', 'zhu', 'nong')
// ('zhun', 'u', 'zhu', 'nu')
// ('zhun', 'ua', 'zhu', 'nua')
// ('zhun', 'uai', 'zhu', 'nuai')
// ('zhun', 'uan', 'zhu', 'nuan')
// ('zhun', 'uang', 'zhu', 'nuang')
// ('zhun', 'ue', 'zhu', 'nue')
// ('zhun', 'ui', 'zhu', 'nui')
// ('zhun', 'un', 'zhu', 'nun')
// ('zhun', 'uo', 'zhu', 'nuo')
// ('zhun', 'v', 'zhu', 'nv')
// ('zong', 'eng', 'zon', 'geng')
// ('zong', 'i', 'zon', 'gi')
// ('zong', 'ia', 'zon', 'gia')
// ('zong', 'ian', 'zon', 'gian')
// ('zong', 'iang', 'zon', 'giang')
// ('zong', 'iao', 'zon', 'giao')
// ('zong', 'ie', 'zon', 'gie')
// ('zong', 'in', 'zon', 'gin')
// ('zong', 'ing', 'zon', 'ging')
// ('zong', 'iong', 'zon', 'giong')
// ('zong', 'iu', 'zon', 'giu')
// ('zong', 'ong', 'zon', 'gong')
// ('zong', 'u', 'zon', 'gu')
// ('zong', 'ua', 'zon', 'gua')
// ('zong', 'uai', 'zon', 'guai')
// ('zong', 'uan', 'zon', 'guan')
// ('zong', 'uang', 'zon', 'guang')
// ('zong', 'ue', 'zon', 'gue')
// ('zong', 'ui', 'zon', 'gui')
// ('zong', 'un', 'zon', 'gun')
// ('zong', 'uo', 'zon', 'guo')
// ('zong', 'v', 'zon', 'gv')
// ('zuan', 'eng', 'zua', 'neng')
// ('zuan', 'i', 'zua', 'ni')
// ('zuan', 'ia', 'zua', 'nia')
// ('zuan', 'ian', 'zua', 'nian')
// ('zuan', 'iang', 'zua', 'niang')
// ('zuan', 'iao', 'zua', 'niao')
// ('zuan', 'ie', 'zua', 'nie')
// ('zuan', 'in', 'zua', 'nin')
// ('zuan', 'ing', 'zua', 'ning')
// ('zuan', 'iong', 'zua', 'niong')
// ('zuan', 'iu', 'zua', 'niu')
// ('zuan', 'ong', 'zua', 'nong')
// ('zuan', 'u', 'zua', 'nu')
// ('zuan', 'ua', 'zua', 'nua')
// ('zuan', 'uai', 'zua', 'nuai')
// ('zuan', 'uan', 'zua', 'nuan')
// ('zuan', 'uang', 'zua', 'nuang')
// ('zuan', 'ue', 'zua', 'nue')
// ('zuan', 'ui', 'zua', 'nui')
// ('zuan', 'un', 'zua', 'nun')
// ('zuan', 'uo', 'zua', 'nuo')
// ('zuan', 'v', 'zua', 'nv')
// ('zun', 'a', 'zu', 'na')
// ('zun', 'an', 'zu', 'nan')
// ('zun', 'ao', 'zu', 'nao')
// ('zun', 'ei', 'zu', 'nei')
// ('zun', 'eng', 'zu', 'neng')
// ('zun', 'i', 'zu', 'ni')
// ('zun', 'ia', 'zu', 'nia')
// ('zun', 'ian', 'zu', 'nian')
// ('zun', 'iang', 'zu', 'niang')
// ('zun', 'iao', 'zu', 'niao')
// ('zun', 'ie', 'zu', 'nie')
// ('zun', 'in', 'zu', 'nin')
// ('zun', 'ing', 'zu', 'ning')
// ('zun', 'iong', 'zu', 'niong')
// ('zun', 'iu', 'zu', 'niu')
// ('zun', 'ong', 'zu', 'nong')
// ('zun', 'u', 'zu', 'nu')
// ('zun', 'ua', 'zu', 'nua')
// ('zun', 'uai', 'zu', 'nuai')
// ('zun', 'uan', 'zu', 'nuan')
// ('zun', 'uang', 'zu', 'nuang')
// ('zun', 'ue', 'zu', 'nue')
// ('zun', 'ui', 'zu', 'nui')
// ('zun', 'un', 'zu', 'nun')
// ('zun', 'uo', 'zu', 'nuo')
// ('zun', 'v', 'zu', 'nv')
