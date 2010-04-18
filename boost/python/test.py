#!/usr/bin/env python

import hello

class GGG(hello.World):
    def __init__(self):
        super(GGG, self).__init__("GGG")

    def greet(self):
        return "GGG:" + super(GGG, self).greet()


if __name__ == "__main__":
    print GGG().say()
    
