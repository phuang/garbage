import sqlite3

con2 = sqlite3.connect("py-new.db")
con2.execute ("PRAGMA synchronous = NORMAL;")
con2.execute ("PRAGMA temp_store = MEMORY;")


con2.execute("create index index_0_0 on py_phrase_0(s0, y0)")
print "py_phrase_%d done" % 0

for i in xrange(1, 16):
	con2.execute("create index index_%d_0 on py_phrase_%d(s0, y0, s1, y1)" % (i, i))
	con2.execute("create index index_%d_1 on py_phrase_%d(s0, s1, y1)" % (i, i))
	print "py_phrase_%d done" % i

# con2.execute("vacuum")
con2.commit()
