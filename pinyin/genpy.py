from pydict import *

def reverse(s):
	s = list(s)
	s.reverse()
	return "".join(s)


pinyin_list = PINYIN_DICT.keys()
pinyin_list.sort()

shengmu_list = SHENGMU_DICT.keys()
shengmu_list.sort()

auto_correct = [("ng", "gn"), ("ng", "mg"), ("iu", "iou"), ("ui", "uei"), ("un", "uen"), ("ue", "ve")]


for c, w in auto_correct:
	for p in pinyin_list:
		if p.endswith(c) and p != c:
			print p.replace(c, w),
	print
