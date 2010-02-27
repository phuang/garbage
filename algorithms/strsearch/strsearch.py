#!/usr/bin/env python

import sys

def search(buf, s):
    slen = len(s)
    skip = slen + 1
    pos = [skip] * 256
    for i in xrange (slen - 1, -1, -1): # len - 1 to 0
        c = ord(s[i])
        if pos[c] == skip:
            pos[c] = skip - i

    i = 0
    while i < len(buf) - slen + 1:
        for j in xrange(0, slen):
            if s[j] != buf[i + j]:
                break
        else:
            print "found pos=", i
            i += slen
            continue
        if i + 1 >= len(buf):
            break
        i += pos[ord(buf[i+1])]
        if i & 0xfffff == 0:
            print i

def main():
    import mmap
    with open("data", "r") as f:
        map = mmap.mmap(f.fileno(), 0, mmap.MAP_PRIVATE)
        search(map, "Ubuntu")

if __name__ == "__main__":
    main()
