import struct
f = open("/dev/input/event3")
while f:
    s = f.read(24)
    print struct.unpack("llhhi", s)
