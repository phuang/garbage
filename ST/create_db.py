import sqlite3
from pydict import *
import ts

con1 = sqlite3.connect("py.db")
# con2 = sqlite3.connect("py-new.db")
# con2.execute ("PRAGMA synchronous = NORMAL;")
# con2.execute ("PRAGMA temp_store = MEMORY;")
# con2.execute ("PRAGMA default_cache_size = 5000;")
# 
# sql = "create table py_phrase_%d (phrase text, freq integer, %s)"
# 
# for i in range(0, 16):
#     column= []
#     for j in range(0, i + 1):
#         column.append ("s%d integer" % j)
#         column.append ("y%d integer" % j)
#     column = ",".join(column)
#     con2.execute(sql % (i, column))
# con2.commit()

def get_sheng_yun(pinyin):
    if pinyin == None:
        return None, None
    if pinyin == "ng":
        return "", "en"
    for i in xrange(2, 0, -1):
        t = pinyin[:i]
        if t in SHENGMU_DICT:
            return t, pinyin[len(t):]
    return "", pinyin

def encode_pinyin(pinyin):
    if pinyin == None or pinyin == "":
        return 0
    e = 0
    for c in pinyin:
        e = (e << 5) + (ord(c) - ord('a') + 1)
    return e

# insert_sql = "insert into py_phrase_%d values (%s);"
# con2.commit()
new_freq = 0
freq = 0
for r in con1.execute("select * from py_phrase order by freq"):
    
    ylen = r[0]
    phrase = r[10]
    if r[11] > freq:
        freq = r[11]
        new_freq += 1

    if ylen <= 4:
        pys = map(lambda id: ID_PINYIN_DICT[id], r[1: 1 + ylen])
    else:
        pys = map(lambda id: ID_PINYIN_DICT[id], r[1: 5]) + r[5].encode("utf8").split("'")

    i = ylen - 1
    if i >= 15:
        i = 15

    pys = pys[0:16]

    sheng_yun = []
    for s, y in map(get_sheng_yun, pys):
        sheng_yun.append(s)
        sheng_yun.append(y)
    
    
    column = [phrase, new_freq] + map(encode_pinyin, sheng_yun)
    if any(map(lambda x: x in ts.T_2_S, phrase)) and len(phrase) > 1:
        print phrase

#     sql = insert_sql % (i, ",".join(["?"] * len(column)))
#     con2.execute (sql, column)
# 
# con2.commit()
# 
# con2.execute("create index index_0_0 on py_phrase_0(s0, y0)")
# 
# for i in xrange(1, 16):
#     con2.execute("create index index_%d_0 on py_phrase_%d(s0, y0, s1, y1)" % (i, i))
#     con2.execute("create index index_%d_1 on py_phrase_%d(s0, s1, y1)" % (i, i))
# 
# con2.execute("vacuum")
# con2.commit()
