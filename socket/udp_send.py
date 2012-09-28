#!/usr/bin/env python

import os
import sys
import socket
import struct
import time

ip = "239.255.255.250"
port = 9131
def main():
  udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  
  # Set TTL to allow broadcast packages pass routers
  udp_socket.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 4)

  # Allow broadcast on this socket.
  udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

  i = 0
  while True:
    print "Send message i=%d" % i
    udp_socket.sendto("Hello(%d)" % i, (ip, port))
    i += 1
    time.sleep(1)

if __name__ == "__main__":
  main()
