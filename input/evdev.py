import struct

fmt = 'llhhi'
f = open('/dev/input/event3')
size = struct.calcsize(fmt)
while f:
    s = f.read(size)
    print struct.unpack(fmt, s)
