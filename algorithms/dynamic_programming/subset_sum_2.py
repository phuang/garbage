#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys

'''
对于从1到N的连续整集合，能划分成两个子集合，且保证每个集合的数字和是相等的。

举个例子，如果N=3，对于{1，2，3}能划分成两个子集合，他们每个的所有数字和是相等的：

{3} and {1,2}

这是唯一一种分发（交换集合位置被认为是同一种划分方案，因此不会增加划分方案总数）
如果N=7，有四种方法能划分集合{1，2，3，4，5，6，7}，每一种分发的子集合各数字和是相等的:

{1,6,7} and {2,3,4,5} {注 1+6+7=2+3+4+5} 
{2,5,7} and {1,3,4,6} 
{3,4,7} and {1,2,5,6} 
{1,2,4,7} and {3,5,6}

给出N，你的程序应该输出划分方案总数，如果不存在这样的划分方案，则输出0。程序不能预存结果直接输出。

'''
dyn = {}
ccc = 0
def get_subset(*args):
    global ccc
    global dyn
    n, remain = args
    # check cached result
    if args in dyn:
        return dyn[args]

    if remain == 0:
        cnt = 1
    else:
        cnt = 0
        for i in xrange(min(n, remain), 0, -1):
            if ((i * (i + 1)) << 1) < remain:
                break
            cnt += get_subset(i - 1, remain - i)
            ccc += 1
    # put result in cache
    dyn[args] = cnt
    return cnt

def subset_sum(n):
    global ccc
    ccc = 0
    # 求和
    _sum = (n * (n + 1)) / 2
    
    # 和是奇数，没有解
    if _sum & 1:
        return 0

    # 求有多少种组合
    return get_subset(n - 1, (_sum >> 1) - n), ccc

def main():
    for i in sys.argv[1:]:
        try:
            i = int(i)
        except:
            print i, 0
        else:
            print i, subset_sum(i)

if __name__ == "__main__":
    main()
