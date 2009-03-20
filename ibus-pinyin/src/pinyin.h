#ifndef __PINYIN_H_
#define __PINYIN_H_

#define PINYIN_FULL_PINYIN	  (1 << 0)
#define PINYIN_CORRECT_GN_TO_NG   (1 << 1)
#define PINYIN_CORRECT_MG_TO_NG   (1 << 2)
#define PINYIN_CORRECT_IOU_TO_IU  (1 << 3)
#define PINYIN_CORRECT_UEI_TO_UI  (1 << 4)
#define PINYIN_CORRECT_UEN_TO_UN  (1 << 5)
#define PINYIN_CORRECT_VE_TO_UE   (1 << 6)

#define PINYIN_FUZZY_C_CH	  (1 << 7)
#define PINYIN_FUZZY_Z_ZH	  (1 << 8)
#define PINYIN_FUZZY_S_SH	  (1 << 9)
#define PINYIN_FUZZY_L_N	  (1 << 10)
#define PINYIN_FUZZY_F_H	  (1 << 11)
#define PINYIN_FUZZY_R_L	  (1 << 12)
#define PINYIN_FUZZY_K_G	  (1 << 13)

#define PINYIN_FUZZY_AN_ANG	  (1 << 14)
#define PINYIN_FUZZY_EN_ENG	  (1 << 15)
#define PINYIN_FUZZY_IN_ING	  (1 << 16)
#define PINYIN_FUZZY_UAN_UANG	  (1 << 17)

struct pinyin_t {
	const char *text;
	const char *pinyin;
	gint		len;
};

#define PINYIN_TEXT(p) (((struct pinyin_t *)p)->text)
#define PINYIN_PINYIN(p) (((struct pinyin_t *)p)->pinyin)
#define PINYIN_LEN(p) (((struct pinyin_t *)p)->len)

#endif
