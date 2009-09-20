import gtk
import ibus

DOUBLE_PINYIN_SCHEMA = [
    "MS Pinyin",
    "ZRM",
    "ZN ABC",
    "ZG Pinyin",
    "Pinyin JJ",
]

class PreferencesDialog:
    def __init__(self):
        self.__bus = ibus.Bus()
        self.__config = self.__bus.get_config()
        self.__builder = gtk.Builder()
        self.__builder.add_from_file("ibus-pinyin-preferences.glade")
        self.__dialog = self.__builder.get_object("dialog")

        # pinyin
        self.__full_pinyin = self.__builder.get_object("FullPinyin")
        self.__simple_pinyin = self.__builder.get_object("SimplePinyin")
        self.__double_pinyin = self.__builder.get_object("DoublePinyin")
        self.__double_pinyin_schema = self.__builder.get_object("DoublePinyinSchema")

        renderer = gtk.CellRendererText()
        self.__double_pinyin_schema.pack_start(renderer)
        self.__double_pinyin_schema.set_attributes(renderer, text=0)

        self.__full_pinyin.set_active(True)
        self.__full_pinyin.connect("toggled",
            lambda w: self.__simple_pinyin.set_sensitive(w.get_active()))
        self.__double_pinyin.connect("toggled",
            lambda w: self.__double_pinyin_schema.set_sensitive(w.get_active()))

        # init state
        self.__init_chinese = self.__builder.get_object("InitChinese")
        self.__init_english = self.__builder.get_object("InitEnglish")
        self.__init_full = self.__builder.get_object("InitFull")
        self.__init_half = self.__builder.get_object("InitHalf")
        self.__init_punct_full = self.__builder.get_object("InitPunctFull")
        self.__init_punct_half = self.__builder.get_object("InitPunctHalf")

        self.__init_chinese.set_active(True)
        self.__init_full.set_active(False)
        self.__init_punct_full.set_active(True)

        #others
        self.__lookup_table_page_size = self.__builder.get_object("LookupTablePageSize")
        renderer = gtk.CellRendererText()
        self.__lookup_table_page_size.pack_start(renderer)
        self.__lookup_table_page_size.set_attributes(renderer, text=0)

        self.__shift_select_candidate = self.__builder.get_object("ShiftSelectCandidate")
        self.__minus_equal_page = self.__builder.get_object("MinusEqualPage")
        self.__comma_period_page = self.__builder.get_object("CommaPeriodPage")
        self.__auto_commit = self.__builder.get_object("AutoCommit")
        self.__half_width_puncts = self.__builder.get_object("HalfWidthPuncts")

        self.__init_correct_pinyin()
        self.__init_fuzzy_pinyin()

    def __init_correct_pinyin(self):
        # auto correct
        self.__correct_pinyin = self.__builder.get_object("CorrectPinyin")
        self.__correct_pinyin_widgets = [
            ("CorrectPinyin_GN_NG", True),
            ("CorrectPinyin_MG_NG", True),
            ("CorrectPinyin_IOU_IU", True),
            ("CorrectPinyin_UEI_UI", True),
            ("CorrectPinyin_UEN_UN", True),
            ("CorrectPinyin_VE_UE", True),
        ]

        def __correct_pinyin_toggled_cb(widget):
            val = widget.get_active()
            map(lambda w: self.__builder.get_object(w[0]).set_sensitive(val),
                self.__correct_pinyin_widgets)
        self.__correct_pinyin.connect("toggled", __correct_pinyin_toggled_cb)

        # init value
        self.__correct_pinyin.set_active(self.__get_value("CorrectPinyin", True))
        for name, defval in self.__correct_pinyin_widgets:
            widget = self.__builder.get_object(name)
            widget.set_active(self.__get_value(name, defval))

        def __toggled_cb(widget, name):
            self.__set_value(name, widget.get_active ())

        self.__correct_pinyin.connect("toggled", __toggled_cb, "CorrectPinyin")
        for name, defval in self.__correct_pinyin_widgets:
            widget = self.__builder.get_object(name)
            widget.connect("toggled", __toggled_cb, name)

    def __init_fuzzy_pinyin(self):
        # fuzzy pinyin
        self.__fuzzy_pinyin = self.__builder.get_object("FuzzyPinyin")
        self.__fuzzy_pinyin_widgets = [
            ("FuzzyPinyin_C_CH", True),
            ("FuzzyPinyin_Z_ZH", True),
            ("FuzzyPinyin_S_SH", True),
            ("FuzzyPinyin_CH_C", False),
            ("FuzzyPinyin_ZH_Z", False),
            ("FuzzyPinyin_SH_S", False),
            ("FuzzyPinyin_L_N", True),
            ("FuzzyPinyin_F_H", True),
            ("FuzzyPinyin_L_R", False),
            ("FuzzyPinyin_K_G", True),
            ("FuzzyPinyin_N_L", False),
            ("FuzzyPinyin_H_F", False),
            ("FuzzyPinyin_R_L", False),
            ("FuzzyPinyin_G_K", False),
            ("FuzzyPinyin_AN_ANG", True),
            ("FuzzyPinyin_EN_ENG", True),
            ("FuzzyPinyin_IN_ING", True),
            ("FuzzyPinyin_ANG_AN", True),
            ("FuzzyPinyin_ENG_EN", True),
            ("FuzzyPinyin_ING_IN", True),
            ("FuzzyPinyin_IAN_IANG", False),
            ("FuzzyPinyin_UAN_UANG", False),
            ("FuzzyPinyin_IANG_IAN", False),
            ("FuzzyPinyin_UANG_UAN", False),
        ]

        def __fuzzy_pinyin_toggled_cb(widget):
            val = widget.get_active()
            map(lambda w: self.__builder.get_object(w[0]).set_sensitive(val),
                self.__fuzzy_pinyin_widgets)
        self.__fuzzy_pinyin.connect("toggled", __fuzzy_pinyin_toggled_cb)

        # init value
        self.__fuzzy_pinyin.set_active(self.__get_value("FuzzyPinyin", False))
        for name, defval in self.__fuzzy_pinyin_widgets:
            widget = self.__builder.get_object(name)
            widget.set_active(self.__get_value(name, defval))

        def __toggled_cb(widget, name):
            self.__set_value(name, widget.get_active ())

        self.__fuzzy_pinyin.connect("toggled", __toggled_cb, "FuzzyPinyin")
        for name, defval in self.__fuzzy_pinyin_widgets:
            widget = self.__builder.get_object(name)
            widget.connect("toggled", __toggled_cb, name)

    def __get_value(self, name, defval):
        return self.__config.get_value("engine/Pinyin", name, defval)

    def __set_value(self, name, val):
        self.__config.set_value("engine/Pinyin", name, val)

    def run(self):
        return self.__dialog.run()

def main():
    PreferencesDialog().run()


if __name__ == "__main__":
    main()
