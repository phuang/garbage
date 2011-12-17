from gi.repository import GObject
from gi.repository import Gtk

class MyObject(Gtk.Window):
    __gproperties__ = {
        "int-prop" : (
            int,
            "init prop",
            "A P",
            1, 5, 2,
            GObject.PARAM_READWRITE)
    }

    def __init__(self):
        Gtk.Window.__init__(self)
        self.int_prop = 2

    def do_get_property(self, prop):
        print "do_get_property", prop
        if prop.name == "int-prop":
            return self.int_prop;
        else:
            raise AttributeError, "Unknow property"

    def do_set_property(self, prop, value):
        print "do_set_property", prop
        if prop.name == "int-prop":
            self.int_prop = value
        else:
            raise AttributeError, "Unknow property"

def notify_cb(obj, prop):
    print prop.name, " = ", obj.get_property(prop.name)

def main():
    obj = MyObject()
    obj.connect("notify", notify_cb)
    obj.notify("int-prop")

if __name__ == "__main__":
    main()
