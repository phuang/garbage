# vim:set et sts=4:

import sys
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

def gen_header():
    header = """
%{
#include <stdio.h>
#include <glib.h>
#include <string.h>
#include "pygrammar.h"

#define USE_PINYIN_NEW
#include "pinyin.h"

%}

%option reentrant
%option extra-type="guint"
%option noinput
%option noyywrap
%option nounput

%%"""
    print header
def output_action(token, text, pinyin, comment=None, flag=None, invflag=None):
    if comment == None:
        comment = "parse %s for %s" % (text, pinyin)
    print "%s {" % text
    print "    /* %s */" % comment

    if flag != None:
        print "    if ((yyextra & %s) == 0) REJECT;" % flag
    if invflag != None:
        print "    if ((yyextra & %s)) REJECT;" % invflag

    sheng, yun = get_sheng_yun(pinyin)
    fsheng = fuzzy_shengmu_dict.get(sheng, "")
    fyun = fuzzy_yunmu_dict.get(yun, "")

    if fsheng:
        if fsheng + yun not in pinyin_list and fsheng + fyun not in pinyin_list:
            fsheng = ""
    if fyun:
        if sheng + fyun not in pinyin_list and fsheng + fyun not in pinyin_list:
            fyun = ""
    print '    yylval.py = pinyin_new ("%s", "%s",' % (text, pinyin)
    print '                            "%s", "%s",' % (sheng, yun)
    print '                            %d, %d,'     % (encode_pinyin(sheng), encode_pinyin(yun))
    print '                            %s, %s,'     % ('"%s"' % fsheng if fsheng else "NULL", '"%s"' % fyun if fyun else "NULL")
    print '                            %d, %d,'     % (encode_pinyin(fsheng), encode_pinyin(fyun))
    print '                            %d);'        % (len(text))
    print '    return %s;' % token
    print '}'

def gen_pinyin_rule():
    l = pinyin_list
    for p in pinyin_list:
        output_action("PINYIN", p, p, "parse pinyin %s" % p)

def gen_shengm_rule():
    for p in shengmu_list:
        output_action("SHENGMU", p, p, "parse sheng %s" % p, invflag="PINYIN_FULL_PINYIN")

def gen_auto_correct_rules():
    for c, w in auto_correct:
        flag = "PINYIN_CORRECT_%s_TO_%s" % (w.upper(), c.upper())
        l = []
        for p in pinyin_list:
            if p.endswith(c) and p != c:
                wp = p.replace(c, w)
                output_action("PINYIN", wp, p, "parse wrong pinyin %s" % wp, flag=flag)

def gen_fuzzy_shengmu_rules():
    for s1, s2 in fuzzy_shengmu:
        flag = "PINYIN_FUZZY_%s_%s" % (s1.upper(), s2.upper())
        for p in pinyin_list:
            s, y = get_sheng_yun(p)
            if s in (s1, s2):
                fp = None
                if s1 + y not in pinyin_list:
                    fp = s1 + y
                if s2 + y not in pinyin_list:
                    fp = s2 + y
                if fp != None:
                    output_action("PINYIN", fp, fp, "parse fuzzy pinyin %s (%s == %s)" % (fp, s1, s2), flag=flag)

def gen_fuzzy_yunmu_rules():
    for y1, y2 in fuzzy_yunmu:
        flag = "PINYIN_FUZZY_%s_%s" % (y1.upper(), y2.upper())
        for p in pinyin_list:
            s, y = get_sheng_yun(p)
            if y in (y1, y2):
                fp = None
                if s + y1 not in pinyin_list:
                    fp = s + y1
                if s + y2 not in pinyin_list:
                    fp = s + y2
                if fp != None:
                    output_action("PINYIN", fp, fp, "parse fuzzy pinyin %s (%s == %s)" % (fp, y1, y2), flag=flag)

def gen_special_rules():
    for p1, p2 in compair_special():
        gen_special_rule(p1 + p2, (p1, p2))
    # gen_special_rule("tiananmen", ("tian", "an", "men"))
    # gen_special_rule("zongai", ("zong", "ai"))

def gen_special_rule(text, pys):
    print '%s { /* parse special rule for %s => %s */' % (text, text, "'".join(pys))
    i = 0
    for p in pys:
        sheng, yun = get_sheng_yun(p)
        fsheng = fuzzy_shengmu_dict.get(sheng, "")
        fyun = fuzzy_yunmu_dict.get(yun, "")

        if fsheng:
            if fsheng + yun not in pinyin_list and fsheng + fyun not in pinyin_list:
                fsheng = ""
        if fyun:
            if sheng + fyun not in pinyin_list and fsheng + fyun not in pinyin_list:
                fyun = ""
        print '    yylval.list[%d] = pinyin_new ("%s", "%s", "%s", "%s", %d, %d, %s, %s, %d, %d, %d);' % \
                                            (i, p, p, sheng, yun, encode_pinyin(sheng), encode_pinyin(yun), \
                                             '"%s"' % fsheng if fsheng else "NULL", '"%s"' % fyun if fyun else "NULL", \
                                             encode_pinyin(fsheng), encode_pinyin(fyun), \
                                            len(p))
        i = i + 1
    print '    yylval.list[%d] = NULL;' % i
    print '    return PINYIN_LIST;'
    print '}'


def gen_other_rules():
    print ".|' { return yytext[0]; }"


def get_all_special():
    for p in pinyin_list:
        if p[-1] in ["n", "g", "r"]:
            for yun in yunmu_list:
                # if yun not in pinyin_list:
                #    continue
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


def compair_special():
    import sqlite3
    db = sqlite3.connect("py.db")

    for p1, p2, p3, p4 in get_all_special():
        if p1 not in pinyin_list or p2 not in pinyin_list:
            yield p3, p4
            continue

        if p3 not in pinyin_list or p4 not in pinyin_list:
            continue

        a1 = get_freq_sum_2(db, p1, p2)
        a2 = get_freq_sum_2(db, p3, p4)
        if a1 == a2:
            a1 = get_freq_sum_1(db, p1) + get_freq_sum_1(db, p2)
            a2 = get_freq_sum_1(db, p3) + get_freq_sum_1(db, p4)
        if a2 > a1:
            yield p3, p4
            # print "%s'%s => %5s       %s'%s => %5s" % (p1, p2, c1, p3, p4, c2)

def gen_pinyin_lex():
    gen_header()
    gen_pinyin_rule()
    gen_shengm_rule()
    gen_auto_correct_rules()
    gen_fuzzy_shengmu_rules()
    gen_fuzzy_yunmu_rules()
    gen_other_rules()
    gen_special_rules()
    print "%%"

if __name__ == "__main__":
    gen_pinyin_lex()
