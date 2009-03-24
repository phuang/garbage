# vim:set et sts=4:

from pydict import *

pinyin_list = PINYIN_DICT.keys()
pinyin_list.sort()

shengmu_list = SHENGMU_DICT.keys()
shengmu_list.remove("")
shengmu_list.sort()

yunmu_list = [
    "a", "an", "ai", "ang", "ao",
    "o", "ou", "ong",
    "e", "en", "eng", "ei",
    "i", "in", "ing", "ie", "iu", "ian", "iang", "iong", "iao",
    "u", "uo", "ue", "ui", "uai", "uan", "uang",
    "v"]

def get_sheng_yun(pinyin):
    if pinyin == None:
        return None, None
    if pinyin == "ng":
        return "", "ng"
    for i in range(2, 0, -1):
        s = pinyin[:i]
        if s in shengmu_list:
            return s, pinyin[i:]
    return "", pinyin

yunmu_list = set([])
for p in pinyin_list:
    s, y = get_sheng_yun(p)
    yunmu_list |= set([y])

auto_correct = [("ng", "gn"), ("ng", "mg"), ("iu", "iou"), ("ui", "uei"), ("un", "uen"), ("ue", "ve")]
fuzzy_shengmu = [("c", "ch"), ("z", "zh"), ("s", "sh"), ("l", "n"), ("f", "h"), ("r", "l"), ("k", "g")]
fuzzy_yunmu = [("an", "ang"), ("en", "eng"), ("in", "ing"), ("uan", "uang")]

fuzzy_shengmu_dict = {}
for s1, s2 in fuzzy_shengmu:
    fuzzy_shengmu_dict[s1] = s2
    fuzzy_shengmu_dict[s2] = s1

fuzzy_yunmu_dict = {}
for y1, y2 in fuzzy_yunmu:
    fuzzy_yunmu_dict[y1] = y2
    fuzzy_yunmu_dict[y2] = y1

def encode_pinyin(pinyin):
    if pinyin == None or pinyin == "":
        return 0
    e = 0
    for c in pinyin:
        e = (e << 5) + (ord(c) - ord('a') + 1)
    return e

def get_pinyin():
    for p in pinyin_list:
        s, y = get_sheng_yun(p)
        yield p, s, y, len(p), []
        
    for s in shengmu_list:
        yield s, s, "", len(s), ["PINYIN_SIMPLE_PINYIN"]

    for c, w in auto_correct:
        flag = "PINYIN_CORRECT_%s_TO_%s" % (w.upper(), c.upper())
        for p in pinyin_list:
            if p.endswith(c) and p != c:
                wp = p.replace(c, w)
                s, y = get_sheng_yun(p)
                yield wp, s, y, len(wp), [flag]

    for s1, s2 in fuzzy_shengmu:
        flag = "PINYIN_FUZZY_%s_%s" % (s1.upper(), s2.upper())
        for y in  yunmu_list:
            if s1 + y not in pinyin_list and s2 + y in pinyin_list:
                yield s1 + y, s1, y, len(s1) + len(y),  [flag]
            if s2 + y not in pinyin_list and s1 + y in pinyin_list:
                yield s2 + y, s2, y, len (s2) + len(y), [flag]

    for y1, y2 in fuzzy_yunmu:
        flag = "PINYIN_FUZZY_%s_%s" % (y1.upper(), y2.upper())
        for s in shengmu_list:
            if s + y1 not in pinyin_list and s + y2 in pinyin_list:
                yield s + y1, s, y1, len(s) + len(y1), [flag]
            if s + y2 not in pinyin_list and s + y1 in pinyin_list:
                yield s + y2, s, y2, len(s) + len(y2), [flag]


def get_pinyin_with_fuzzy():
    for text, s, y, l, flags in get_pinyin():
        fs = fuzzy_shengmu_dict.get(s, "")
        fy = fuzzy_yunmu_dict.get(y, "")

        if fs and fs + y not in pinyin_list and (fy and fs + fy not in pinyin_list):
            fs = ""
        if fy and s + fy not in pinyin_list and (fs and fs + fy not in pinyin_list):
            fy = ""
        yield text, s, y, encode_pinyin(s), encode_pinyin(y), encode_pinyin(fs), encode_pinyin(fy), l, flags


def gen_header():
    print '''

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
'''

def union_dups(a):
    n = {}
    for r in a:
        if r[:-1] in n:
            n[r[:-1]] += r[-1]
        else:
            n[r[:-1]] = r[-1]
    na = []
    for k, flags in n.items():
        na.append (tuple(list(k) + [" | ".join(flags) if flags else 0]))
    na.sort()
    return na

def gen_tables():
    _dict = {}
    
    for c in "abcdefghijklmnopqrstuvwxyz":
        _dict[c] = {}
        _dict[c][-1] = False
        for i in xrange(1, 7):
            _dict[c][i] = []

    for text, s, y, s_id, y_id, fs_id, fy_id, l, flags in get_pinyin_with_fuzzy():
        _dict[text[0]][l].append((text, s, y, s_id, y_id, fs_id, fy_id, l, flags))
        _dict[text[0]][-1] = True

    for c in "abcdefghijklmnopqrstuvwxyz":
        a = _dict[c]
        if not a[-1]:
            continue
        for i in xrange(1, 7):
            if a[i]:
                a[i] = union_dups(a[i])
                print 'static const PinYin pinyin_%s_%d[] = {' % (c, i)
                for ps in a[i]:
                    print '    { "%s", "%s", "%s", %d, %d, %d, %d, %d, %s },' % ps
                print '    { 0 },'
                print '};'
                print
        
        print 'static const PinYin *pinyin_%s[] = {' % c
        print '    0,'
        for i in xrange(1, 7):
            if not a[i]:
                print '    0,'
            else:
                print '    pinyin_%s_%d,' % (c, i)
        print '};'
        print
 
    print "static const PinYin **pinyin_table[] = {"
    for c in "abcdefghijklmnopqrstuvwxyz":
        if _dict[c][-1]:
            print '    pinyin_%s,' % c
        else:
            print '    0,'
    print '};'
    print


def main():
    gen_header()
    gen_tables()


if __name__ == "__main__":
    main()
 
