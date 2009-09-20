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
        self.__fuzzy = self.__builder.get_object("checkbuttonFuzzy")
        self.__fuzzy_c_ch = self.__builder.get_object("checkbuttonFuzzyC_CH")
        self.__fuzzy_z_zh = self.__builder.get_object("checkbuttonFuzzyZ_ZH")
        self.__fuzzy_s_sh = self.__builder.get_object("checkbuttonFuzzyS_SH")
        self.__fuzzy_ch_c = self.__builder.get_object("checkbuttonFuzzyCH_C")
        self.__fuzzy_zh_z = self.__builder.get_object("checkbuttonFuzzyZH_Z")
        self.__fuzzy_sh_s = self.__builder.get_object("checkbuttonFuzzySH_S")
        
        self.__fuzzy_l_n = self.__builder.get_object("checkbuttonFuzzyL_N")
        self.__fuzzy_f_h = self.__builder.get_object("checkbuttonFuzzyF_H")
        self.__fuzzy_l_r = self.__builder.get_object("checkbuttonFuzzyL_R")
        self.__fuzzy_k_g = self.__builder.get_object("checkbuttonFuzzyK_G")
        self.__fuzzy_n_l= self.__builder.get_object("checkbuttonFuzzyN_L")
        self.__fuzzy_h_f= self.__builder.get_object("checkbuttonFuzzyH_F")
        self.__fuzzy_r_l= self.__builder.get_object("checkbuttonFuzzyR_L")
        self.__fuzzy_g_k= self.__builder.get_object("checkbuttonFuzzyG_K")
        
        self.__fuzzy_an_ang = self.__builder.get_object("checkbuttonFuzzyAN_ANG")
        self.__fuzzy_en_eng = self.__builder.get_object("checkbuttonFuzzyEN_ENG")
        self.__fuzzy_in_ing = self.__builder.get_object("checkbuttonFuzzyIN_ING")
        self.__fuzzy_ang_an = self.__builder.get_object("checkbuttonFuzzyANG_AN")
        self.__fuzzy_eng_en = self.__builder.get_object("checkbuttonFuzzyENG_EN")
        self.__fuzzy_ing_in = self.__builder.get_object("checkbuttonFuzzyING_IN")
        
        self.__fuzzy_ian_iang = self.__builder.get_object("checkbuttonFuzzyIAN_IANG")
        self.__fuzzy_uan_uang = self.__builder.get_object("checkbuttonFuzzyUAN_UANG")
        self.__fuzzy_iang_ian = self.__builder.get_object("checkbuttonFuzzyIANG_IAN")
        self.__fuzzy_uang_uan = self.__builder.get_object("checkbuttonFuzzyUANG_UAN")

        def __fuzzy_toggled_cb(w):
            v = w.get_active()



    def run(self):
        return self.__dialog.run()

def main():
    PreferencesDialog().run()


if __name__ == "__main__":
    main()
