import gtk

def main():
	w = gtk.Window()
	l = gtk.Label("Hello World")
	l.set_property("cursor-position", 3)
	w.add(l)
	w.show_all()
	gtk.main();

if __name__ == "__main__":
	main()
