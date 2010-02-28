#!/usr/bin/env python

import sys

def match(buf, p):
    n = len(buf)
    m = len(p)
    t = [m + 1] * 256

    # create skip table
    i = m - 1 
    while i >= 0:
        c = ord(p[i])
        # if t[c] == m + 1:
        if t[c] == m + 1:
            t[c] = m - i
        i -= 1

    # match buf
    result = []
    i = 0
    while i <= n - m - 1:
        j = 0
        while j < m:
            if buf[i + j] != p[j]:
                break
            j += 1
        else:
            result.append(i)
        c = ord(buf[i + m])
        i += t[c]
    if i == n - m:
        j = 0
        while j < m:
            if buf[i + j] != p[j]:
                break
            j += 1
        else:
            result.append(i)

    return result

def main():
    print match("phuang", "phuang")

if __name__ == "__main__":
    main()
