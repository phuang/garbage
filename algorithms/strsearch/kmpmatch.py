#!/usr/bin/env python

import sys

def kmp_match(buf, p):
    n = len(buf)
    m = len(p)
    t = compute_prefix(p)
    q = 0
    result = []
    for i in xrange(0, n):
        while q > 0 and p[q] != buf[i]:
            q = t[q]
        if p[q] == buf[i]:
            q = q + 1
        if q == m:
            result.append(i - m + 1)
            q = t[q - 1]
    return result

def compute_prefix(p):
    m = len(p)
    T = [0] * len(p)
    k = 0
    for q in xrange(1, m):
        while k > 0 and p[k] != p[q]:
            k = T[k]
        if p[k] == p[q]:
            k = k + 1
        T[q] = k
    return T

def main():
    print kmp_match(sys.argv[1], sys.argv[2])

if __name__ == "__main__":
    main()
