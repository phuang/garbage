import sys
for l in sys.stdin:
	l = l.strip()
	l = list(l)
	l.reverse()
	print "".join(l)
