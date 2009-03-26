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
    print '''/* Please do not modify this file. It is generated by script */
#include "pinyin.h"
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
    
    pinyins = list(get_pinyin_with_fuzzy())
    pinyins = union_dups(pinyins)
    
    print 'static const PinYin pinyin_table[] = {'
    i = 0
    for p in pinyins:
        print '    /* %3d */' % i, '{ %s %s %s'% tuple([('"%s",' % s).ljust(9) for s in p[:3]]), '%6d, %6d, %6d, %6d, %6d,' % p[3:-1], '%s },' % str(p[-1]).ljust(24)
        i += 1
    print '};'
    print
    print '#define PINYIN_TABLE_NR (sizeof (pinyin_table) / sizeof (PinYin))'

    return pinyins

def get_all_special():
    for p in pinyin_list:
        if p[-1] in ["n", "g", "r"]:
            for yun in yunmu_list:
                if yun not in pinyin_list:
                    continue
                new_pinyin = p[-1] + yun
                # if new_pinyin in pinyin_list:
                yield p, yun, p[:-1], new_pinyin

def get_freq_sum_2(db, p1, p2):
    s1, y1 = get_sheng_yun(p1)
    s2, y2 = get_sheng_yun(p2)

    sql = "select max(freq), phrase from py_phrase_1 where s0 = %d and y0 = %d and s1 = %d and y1 = %d"

    c = db.execute(sql % (encode_pinyin(s1), encode_pinyin(y1), encode_pinyin(s2), encode_pinyin(y2)))
    for r in c:
        return r[0]
    return 0

def get_freq_sum_1(db, p1):
    s1, y1 = get_sheng_yun(p1)

    sql = "select max(freq), phrase from py_phrase_1 where s0 = %d and y0 = %d"

    c = db.execute(sql % (encode_pinyin(s1), encode_pinyin(y1)))
    for r in c:
        return r[0] if r[0] else 0
    return 0

def compaired_special():
    import sqlite3
    db = sqlite3.connect("py.db")

    for p1, p2, p3, p4 in get_all_special():
        if p3 not in pinyin_list or p4 not in pinyin_list:
            continue
        if p1 not in pinyin_list or p2 not in pinyin_list:
            yield p1, p2, p3, p4
            continue

        if p3 not in pinyin_list or p4 not in pinyin_list:
            continue

        a1 = get_freq_sum_2(db, p1, p2)
        a2 = get_freq_sum_2(db, p3, p4)
        if a1 == a2:
            a1 = get_freq_sum_1(db, p1) + get_freq_sum_1(db, p2)
            a2 = get_freq_sum_1(db, p3) + get_freq_sum_1(db, p4)
        if a1 < a2:
            yield p1, p2, p3, p4

def gen_special_table(pinyins):
    _dict = {}
    for i in xrange(0, len(pinyins)):
        _dict[pinyins[i][0]] = i

    l = list(compaired_special())
    l.sort()
    print 'static const PinYin *special_table[][4] = {'
    for r in l:
        ids =  [("&pinyin_table[%d]," % _dict[py]).ljust(20) for py in r]

        print '    { %s %s %s %s },' % tuple(ids), "/* %s %s => %s %s */" % r
    print '};'
    print
    print '#define SPECIAL_TABLE_NR (sizeof (special_table) / sizeof (special_table[0]))'


def main():
    gen_header()
    pinyins = gen_tables()
    gen_special_table(pinyins)


if __name__ == "__main__":
    main()

