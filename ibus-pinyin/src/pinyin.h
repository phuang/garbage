#ifndef __PINYIN_H_
#define __PINYIN_H_

#define PINYIN_FULL_PINYIN	  (1 << 0)
#define PINYIN_CORRECT_GN_TO_NG   (1 << 1)
#define PINYIN_CORRECT_MG_TO_NG   (1 << 2)
#define PINYIN_CORRECT_IOU_TO_IU  (1 << 3)
#define PINYIN_CORRECT_UEI_TO_UI  (1 << 4)
#define PINYIN_CORRECT_UEN_TO_UN  (1 << 5)
#define PINYIN_CORRECT_VE_TO_UE   (1 << 6)

struct pinyin_t {
	const char *py;
	const char *origin_py;
};

#endif
