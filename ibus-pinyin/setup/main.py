import gtk
import ibus

class PreferencesDialog:
    def __init__(self):
        self.__bus = ibus.Bus()
        self.__builder = gtk.Builder()
        self.__builder.add_from_file("ibus-pinyin-preferences.glade")
        self.__dialog = self.__builder.get_object("dialog")

    def run(self):
        return self.__dialog.run()

def main():
    PreferencesDialog().run()


if __name__ == "__main__":
    main()
