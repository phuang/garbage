import gtk
from gtk.gdk import threads_enter
from gtk.gdk import threads_leave
import gobject
import os
import thread
import time

class MemWindow(gtk.Window):
	def __init__(self):
		gtk.Window.__init__(self)
		self.da = gtk.DrawingArea()
		self.add(self.da)
		self.da.connect("expose_event", self.expose_cb)
		self.connect("destroy", self.destroy_cb)
		self.max_mapnr = 0
		self.mem_map = None
		self.m_lock = thread.allocate_lock()
		self.gcs = None
		self.resize(800, 600)
		self.set_title("Mem Map")
		self.show_all()
		self.running = True
		thread.start_new(self.start_thread, ())

	def init_gcs(self):
		if self.gcs:
			return
		self.gcs = []
		for i in range(0, 65):
			v = (64 - i) * 65535 / 64;
			gc = gtk.gdk.GC(self.window)
			gc.copy(self.style.white_gc)
			if i == 0:
				gc.set_rgb_fg_color(gtk.gdk.Color(v, v, v));
			else:
				gc.set_rgb_fg_color(gtk.gdk.Color(v, 32767, 16383));
			self.gcs.append(gc)
		
	def destroy_cb(self, e):
		self.running = False
		gtk.main_quit()


	def start_thread(self):
		i = 0
		input = os.popen("exec stap -g -DMAXACTION=100000 mem.stp")
		while self.running:
			line = input.readline()
#			print line
			if line == "":
				gtk.main_quit()
				return
			line = line.strip()
			if (self.max_mapnr == 0):
				t = line.split('=')
				self.max_mapnr = int(t[1])
			else:
				mem_map = line.split(':')
				self.update_mem_map(mem_map);
		input.close()

	def update_mem_map(self, mem_map):
		if self.mem_map == None:
			self.m_lock.acquire()
			self.mem_map = mem_map;
			self.m_lock.release()
			threads_enter()	
			self.expose_cb(self.da, None)
			threads_leave()
		else:
			i ,x ,y = 0, 10, 26
			cx, cy = self.get_size()
			while i < self.max_mapnr:
				if self.mem_map[i] == mem_map[i]:
					pass
				else:
					self.m_lock.acquire()
					self.mem_map[i] = mem_map[i]
					self.m_lock.release()
					threads_enter()
					v =  int(self.mem_map[i], 16)
					self.da.window.draw_rectangle(self.gcs[v], True, x, y , 6, 6)
					self.da.window.draw_rectangle(self.style.black_gc, 
						False, x, y , 6, 6)
					threads_leave()
				x = x + 8
				i = i + 1
				if x>= cx - 8:
					y = y + 8
					x = 10
				
	def expose_cb(self, draw_area, event):
		if self.max_mapnr == 0 or self.mem_map == None:
			return
		self.init_gcs()
		i, x, y = 0, 10, 10
		for i in range (0, 65):
			draw_area.window.draw_rectangle(self.gcs[i], True, x, y , 6, 6)
			draw_area.window.draw_rectangle(self.style.black_gc, 
					False, x, y , 6, 6)
			x = x + 8
		y = y + 16
		x = 10
		self.m_lock.acquire()
		cx , cy = self.get_size()

		i = 0
		while (i < self.max_mapnr):
			v =  int(self.mem_map[i], 16)
			draw_area.window.draw_rectangle(self.gcs[v], True, x, y , 6, 6)
			draw_area.window.draw_rectangle(self.style.black_gc, 
					False, x, y , 6, 6)
			x = x + 8
			i = i + 1
			if x >= cx - 8:
				y = y + 8
				x = 10
		self.m_lock.release()

