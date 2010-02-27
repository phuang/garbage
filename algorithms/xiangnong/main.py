#!/usr/bin/env python
import math

status_p = (0.6, 0.1, 0.1, 0.2)

def cal():
    return -sum(map(lambda p: p * math.log(p, 2), status_p))

def main():
    print cal()


if __name__ == "__main__":
    main()
