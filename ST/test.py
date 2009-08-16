

NAME = "ST.csv"

def parse_1():
    f = file(NAME)
    for l in f:
        l = unicode(l)
        l = l.strip()
        values = l.split(",")
        values = map(lambda x: x.strip("\""), values)
        try:
            s, si, t, ti = values[0], int(values[1], 16), values[2], int(values[3], 16)
        except:
            yield None
            continue
        yield s, si, t, ti

def parse():
    return_values = []
    for values in parse_1():
        if values == None:
            if return_values:
                yield return_values
                return_values = []
            continue
        else:
            return_values.append(values)

    if return_values:
        yield return_values

def main():
    s_to_t, t_to_s_n, s_to_t_n = list(parse())

    sdict = {}
    tdict = {}
    for s, si, t, ti in s_to_t:
        if s not in sdict:
            sdict[s] = []

        sdict[s].append(t)
        if t not in tdict:
            tdict[t] = []
        tdict[t].append(s)
    print "# -*- coding: utf-8 -*-"
    print
    print "# Simplfied Chinese to Traditional Chinese"
    print "S_2_T = {"
    for s in sorted(sdict.iterkeys()):
        ts = sdict[s]
        if len(ts) == 1:
            print '    u"%s" : (u"%s", ),  # %04X => %04X' % (s, ts[0], ord(s), ord(ts[0]))
        else:
            ts = sorted(ts)
            ns = map(lambda x: '%04X' % ord(x), ts)
            ts = map(lambda x: 'u"%s"' % x, ts)
            print '    u"%s" : (%s),  # %04X => %s' % (s, ", ".join(ts), ord(s), " ".join(ns))
    print "}"

    print 
    print "# Traditional Chinese to Simplfied Chinese"
    print "T_2_S = {"
    for t in sorted(tdict.iterkeys()):
        ss = tdict[t]
        if len(ss) == 1:
            print '    u"%s" : (u"%s", ),  # %04X => %04X' % (t, ss[0], ord(t), ord(ss[0]))
        else:
            ss = sorted(ss)
            nt = map(lambda x: '%04X' % ord(x), ss)
            ss = map(lambda x: 'u"%s"' % x, ss)
            print '    u"%s" : (%s),  # %04X => %s' % (t, ", ".join(ss), ord(t), " ".join(nt))
    print "}"

    # print "S_T = {"
    # for s, si, t, ti in s_to_t:
    #     print '    "%s" : "%s",' % (s, t)
    # print "}"

    # print "T_S_N = {"
    # for t, ti, s, si in t_to_s_n:
    #     print '    "%s" : "%s",' % (t, s)
    # print "}"

    # print "S_T_N = {"
    # for s, si, t, ti in s_to_t_n:
    #     print '    "%s" : "%s",' % (s, t)
    # print "}"

if __name__ == "__main__":
    main()
