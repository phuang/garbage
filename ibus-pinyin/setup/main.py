import gtk

b = gtk.Builder()
b.add_from_file("ibus-pinyin-preferences.glade")
d = b.get_object("dialog");
d.run()
