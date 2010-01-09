all: phuang_classic.pdf

phuang_classic.dvi: phuang_classic.tex
	latex $<

phuang_classic.pdf: phuang_classic.dvi
	dvipdf $<

test: phuang_classic.pdf
	gnome-open $<
