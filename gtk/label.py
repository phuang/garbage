import gtk
import pango
import glib
import random

def empty_clicked_cb(button, label):
    attrs = pango.AttrList()
    '''
    attrs.insert(pango.AttrBackground(
                    random.randint(256, 256*256),
                    random.randint(256, 256*256),
                    random.randint(256, 256*256), 0, 11))
    '''
    label.set_attributes(attrs)

def random_clicked_cb(button, label):
    attrs = pango.AttrList()
    attrs.insert(pango.AttrBackground(
                    random.randint(256, 256*256),
                    random.randint(256, 256*256),
                    random.randint(256, 256*256), 0, 11))
    label.set_attributes(attrs)

def main():
    global l
    window = gtk.Window()
    vbox=gtk.VBox()
    window.add(vbox)
    
    label = gtk.Label("Hello World")
    vbox.pack_start(label)

    button = gtk.Button("Empty Attributes")
    button.connect("clicked", empty_clicked_cb, label)
    vbox.pack_start(button)
    
    button = gtk.Button("Random Attributes")
    button.connect("clicked", random_clicked_cb, label)
    vbox.pack_start(button)
    
    window.show_all()
    gtk.main();

if __name__ == "__main__":
    main()
