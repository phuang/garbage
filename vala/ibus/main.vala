using IBus;
using GLib;

void main (string []argv) {
    var bus = new Bus();
    var name = bus.get_name_owner(argv[1]);
    stdout.printf("%s = %s\n", argv[1], name);


    var engines = bus.list_active_engines();
    foreach (var e in engines) {
        stdout.printf("engine = %s\n", e.name);
    }
    
    var names = bus.list_names();
    foreach (var n in names) {
        stdout.printf("bus = %s\n", n);
    }
}
