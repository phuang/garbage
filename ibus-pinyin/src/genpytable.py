# vim:set et sts=4:

from pydict import *

pinyin_list = PINYIN_DICT.keys()
pinyin_list.sort()

d = {}
for c in "abcdefghijklmnopqrstuvwxyz":
    d[c] = {}
    d[c][7] = False
    for i in xrange(1, 7):
        d[c][i] = []

for  p in pinyin_list:
    d[p[0]][len(p)].append(p)
    d[p[0]][7] = True


for c in "abcdefghijklmnopqrstuvwxyz":
    a = d[c]
    if not d[c][7]:
        continue
    for i in xrange(1, 7):
        if a[i]:
            a[i].sort()
            print 'static const char *pinyin_%s_%d[] = {' % (c, i)
            for p in a[i]:
                print '    "%s",' % p
            print '    NULL,'
            print '};'
            print
    
    
    print 'static const char **pinyin_%s[] = {' % c
    print '    NULL,'
    for i in xrange(1, 7):
        if not a[i]:
            print '    NULL,'
        else:
            print '    pinyin_%s_%d,' % (c, i)
    print '};'
    print

print "static const char ***pinyin_table[] = {"
for c in "abcdefghijklmnopqrstuvwxyz":
    if d[c][7]:
        print '    pinyin_%s,' % c
    else:
        print '    NULL,'
print '};'
print

