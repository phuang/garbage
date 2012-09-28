#!/usr/bin/env python

import os
import sys
import socket
import struct
import time

ip = ""
port = 9131
def main():
  udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

  # Allow applications reuse the same port
  udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

  # Join the mulitcast group
  ip_mreq = struct.pack('4sl', socket.inet_aton("239.255.255.250"), socket.INADDR_ANY)
  udp_socket.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, ip_mreq)

  # Leave the mulitcast group
  # udp_socket.setsockopt(socket.IPPROTO_IP, socket.IP_DROP_MEMBERSHIP, ip_mreq)
  udp_socket.bind((ip, port))
  while True:
    print udp_socket.recvfrom(1024)


if __name__ == "__main__":
  main()
