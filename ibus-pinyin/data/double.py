import pydict

for name, (sheng, yun) in pydict.SHUANGPIN_SCHEMAS.items():
    print "static const gint double_pinyin_%s_sheng[] = {" % name.lower()
    for c in "abcdefghijklmnopqrstuvwxyz;":
        s = sheng.get(c, "VOID")
        if s == "'":
            s = "VOID"
        else:
            s = s.upper()
        print "    PINYIN_ID_%s,    // %s" % (s, c.upper())
    print "};"
    
    print "static const gint double_pinyin_%s_yun[][2] = {" % name.lower()
    for c in "abcdefghijklmnopqrstuvwxyz;":
        s = sheng.get(c, ("VOID", "VOID"))
        if len(s) == 1:
            s1 = s[0]
            s2 = "VOID"
        else:
            s1, s2 = s
        if s1 == "'":
            s1 = "VOID"
        if s2 == "'":
            s2 = "VOID"
        s1 = s1.upper()
        s2 = s2.upper()
        print "    { PINYIN_ID_%s, PINYIN_ID_%s },    // %s" % (s1, s2, c.upper())
    print "};"
