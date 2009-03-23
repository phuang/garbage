# vim:set et sts=4:

import sys
from pydict import *

pinyin_list = PINYIN_DICT.keys()
pinyin_list.sort()

shengmu_list = SHENGMU_DICT.keys()
shengmu_list.remove("")
shengmu_list.sort()

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
    print "%s {" % text[::-1]
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

def gen_other_rules():
    print "' { return '\\\''; }"
    print ". { return SKIP; }"


def gen_pinyin_lex():
    gen_header()
    gen_pinyin_rule()
    gen_shengm_rule()
    gen_auto_correct_rules()
    gen_fuzzy_shengmu_rules()
    gen_fuzzy_yunmu_rules()
    gen_other_rules()
    print "%%"

if __name__ == "__main__":
    gen_pinyin_lex()
