import gtk


def key_press_cb(w, e):
    print "e.keyval=0x%x, e.hardware_keycode=0x%x, %d" % (e.keyval, e.hardware_keycode, e.hardware_keycode)


def main():
    w = gtk.Window()
    w.connect("delete-event", gtk.main_quit)
    w.connect("key-press-event", key_press_cb)
    w.add_events(gtk.gdk.KEY_PRESS_MASK)
    w.show()
    gtk.main()


if __name__ == "__main__":
    main()
