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

def get_sheng_yun(pinyin):
    if pinyin == None:
        return None, None
    if pinyin == "ng":
        return None, "ng"
    for i in range(2, 0, -1):
        s = pinyin[:i]
        if s in shengmu_list:
            return s, pinyin[i:]
    return None, pinyin

def gen_header():
    header = """
%{
#include <stdio.h>
#include <glib.h>
#include <string.h>
#include "y.tab.h"

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
    print "%s { /* %s */" % (text[::-1], comment)

    if flag != None:
        print "    if ((yyextra & %s) == 0) REJECT;" % flag
    if invflag != None:
        print "    if ((yyextra & %s)) REJECT;" % invflag

    sheng, yun = get_sheng_yun(pinyin)
    if sheng == None:
        sheng = ""
    print '    yylval.py = pinyin_new ("%s", "%s", "%s", "%s", %d );' % (text, pinyin, sheng, yun, len(text))
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
            if s == None:
                s = ""
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
