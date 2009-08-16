import gzip

def get_charset(name):
    filename = "/usr/share/i18n/charmaps/%s.gz" % name
    s = []
    for l in gzip.open(filename):
        l = l.strip()
        v = l.split()
        if len(v) < 3:
            continue
        if v[2] != "<CJK>":
            continue
        v = v[0]
        if v.startswith("<U") and v.endswith(">"):
            c = v[2:-1]
            try:
                c = unichr(int(c, 16))
                s.append(c)
            except:
                pass
    return s

def main():
    gb2312 = set(get_charset("GB2312"))
    gbk = set(get_charset("GBK"))
    big5 = set(get_charset("BIG5"))
    print "GB2312", len(gb2312)
    print "GBK", len(gbk)
    print "BIG5", len(big5)
    u = gb2312 - big5
    print "GB2312 - BIG5", len(u)
    
    for c in sorted(list(u)):
        print c
    
    u = gbk & big5
    print "GBK & BIG5", len(u)

if __name__ == "__main__":
    main()

