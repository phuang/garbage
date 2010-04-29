#!/usr/bin/env python
import sys
from common import XKB_DIR

def parse(name):
    filename = "%s/symbols/%s" % (XKB_DIR, name)
    with open(filename) as input:
        for line in input:
            line = line.strip()
            line = line.split("//", 1)[0]
            line = line.strip()
            if not line:
                continue
            print line

def main():
    name = sys.argv[1]
    parse(name)

if __name__ == "__main__":
    main()
