#!/usr/bin/env python

import gtk
from gtk.gdk import threads_init
import gobject
import MemWindow
def main():
	threads_init()
	gobject.threads_init()
	win = MemWindow.MemWindow()
	win.show_all()
	gtk.main()

if __name__ == "__main__":
	main()
