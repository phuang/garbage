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

        # auto correct
        self.__correct_pinyin = self.__builder.get_object("CorrectPinyin")
        self.__correct_pinyin_widgets = [
            "CorrectPinyinGN_NG",
            "CorrectPinyinMG_NG",
            "CorrectPinyinIOU_IU",
            "CorrectPinyinUEI_UI",
            "CorrectPinyinUEN_UN",
            "CorrectPinyinVE_UE",
        ]
        def __correct_pinyin_toggled_cb(w):
            v = w.get_active()
            for name in self.__correct_pinyin_widgets:
                self.__builder.get_object(name).set_sensitive(v)
        self.__correct_pinyin.connect("toggled", __correct_pinyin_toggled_cb)

        # fuzzy pinyin
        self.__fuzzy_pinyin = self.__builder.get_object("FuzzyPinyin")
        self.__fuzzy_pinyin_widgets = [
            "FuzzyPinyinC_CH",
            "FuzzyPinyinC_CH",
            "FuzzyPinyinZ_ZH",
            "FuzzyPinyinS_SH",
            "FuzzyPinyinCH_C",
            "FuzzyPinyinZH_Z",
            "FuzzyPinyinSH_S",
            "FuzzyPinyinL_N",
            "FuzzyPinyinF_H",
            "FuzzyPinyinL_R",
            "FuzzyPinyinK_G",
            "FuzzyPinyinN_L",
            "FuzzyPinyinH_F",
            "FuzzyPinyinR_L",
            "FuzzyPinyinG_K",
            "FuzzyPinyinAN_ANG",
            "FuzzyPinyinEN_ENG",
            "FuzzyPinyinIN_ING",
            "FuzzyPinyinANG_AN",
            "FuzzyPinyinENG_EN",
            "FuzzyPinyinING_IN",
            "FuzzyPinyinIAN_IANG",
            "FuzzyPinyinUAN_UANG",
            "FuzzyPinyinIANG_IAN",
            "FuzzyPinyinUANG_UAN"]

        def __fuzzy_pinyin_toggled_cb(w):
            v = w.get_active()
            for name in self.__fuzzy_pinyin_widgets:
                self.__builder.get_object(name).set_sensitive(v)
        self.__fuzzy_pinyin.connect("toggled", __fuzzy_pinyin_toggled_cb)



    def run(self):
        return self.__dialog.run()

def main():
    PreferencesDialog().run()


if __name__ == "__main__":
    main()
