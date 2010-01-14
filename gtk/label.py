import gtk
import pango
import glib
import random

def clicked_cb(button, label):
    label.set_attributes(pango.AttrList())

def main():
    global l
    window = gtk.Window()
    vbox=gtk.VBox()
    window.add(vbox)
    
    label = gtk.Label("Hello World")
    attr = pango.AttrList()
    attr.insert(pango.AttrBackground(0, 255*255, 0, 0, 11))
    label.set_attributes(attr)
    vbox.pack_start(label)

    button = gtk.Button("Change Attributes")
    button.connect("clicked", clicked_cb, label)
    vbox.pack_start(button)
    
    window.show_all()
    gtk.main();

if __name__ == "__main__":
    main()
