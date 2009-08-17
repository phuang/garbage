

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

def print_dict(name, d):
    print "%s = {" % name
    for k in sorted(d.iterkeys()):
        v = d[k]
        if len(v) == 1:
            print '    u"%s" : (u"%s", ),  # %04X => %04X' % (k, v[0], ord(k), ord(v[0]))
        else:
            v = sorted(v)
            vd = map(lambda x: '%04X' % ord(x), v)
            vs = map(lambda x: 'u"%s"' % x, v)
            print '    u"%s" : (%s),  # %04X => %s' % (k, ", ".join(vs), ord(k), " ".join(vd))
    print "}"

def parse_csv():
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
    return sdict, tdict

def parse_scim():
    sdict = {}
    tdict = {}
    f = file("scim_sctc_filter_data.h")
    for l in f:
        if "__sc_to_tc_table" in l:
            break
    for l in f:
        l = l.strip()
        l = l.strip("{},")
        v = l.split("},{")
        v = map(lambda x: x.split(","), v)
        v = map(lambda x: (int(x[0].strip(), 16), int(x[1].strip(), 16)), v)
        if v == [(0, 0)]:
            break
        v = map(lambda x: (unichr(x[0]), unichr(x[1])), v)
        for s, t in v:
            sdict[s] = [t]
    
    for l in f:
        if "__tc_to_sc_table" in l:
            break
    for l in f:
        l = l.strip()
        l = l.strip("{},")
        v = l.split("},{")
        v = map(lambda x: x.split(","), v)
        v = map(lambda x: (int(x[0].strip(), 16), int(x[1].strip(), 16)), v)
        if v == [(0, 0)]:
            break
        v = map(lambda x: (unichr(x[0]), unichr(x[1])), v)
        for s, t in v:
            tdict[s] = [t]
    return sdict, tdict




def main():
    d1, d2 = parse_scim()
    print "# -*- coding: utf-8 -*-"
    print
    print "# Simplfied Chinese to Traditional Chinese"
    print_dict("S_2_T", d1)

    print 
    print "# Traditional Chinese to Simplfied Chinese"
    print_dict("T_2_S", d2)

if __name__ == "__main__":
    main()
