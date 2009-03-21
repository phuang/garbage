# vim:set noet ts=4:
#
# ibus-pinyin - The Chinese PinYin engine for IBus
#
# Copyright (c) 2007-2008 Huang Peng <shawn.p.huang@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

AM_CFLAGS = \
	@IBUS_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	$(NULL)
AM_LDFLAGS = \
	@IBUS_LIBS@ \
	$(NULL)

AM_YFLAGS = \
	-d \
	--verbose \
	$(NULL)

AM_LFLAGS = \
	--outfile=$(LEX_OUTPUT_ROOT).c \
	--header-file=$(LEX_OUTPUT_ROOT).h \
	$(NULL)

check_PROGRAMS = \
	$(NULL)

TESTS = \
	$(check_PROGRAMS) \
	$(NULL)

libexec_PROGRAMS = ibus-engine-pinyin

ibus_engine_c_sources = \
	main.c \
	pygrammar.y \
	pyscanner.l \
	pyparser.c \
	engine.c \
	$(ibus_engine_built_c_sources) \
	$(NULL)
ibus_engine_h_sources = \
	pinyin.h \
	pyparser.h \
	engine.h \
	$(ibus_engine_built_h_sources) \
	$(NULL)
ibus_engine_pinyin_SOURCES = \
	$(ibus_engine_c_sources) \
	$(ibus_engine_h_sources) \
	$(NULL)
ibus_engine_pinyin_CFLAGS = \
	@IBUS_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	$(NULL)
ibus_engine_pinyin_LDFLAGS = \
	@IBUS_LIBS@ \
	$(NULL)

BUILT_SOURCES = \
	$(NULL)

component_DATA = \
	pinyin.xml \
	$(NULL)
componentdir = @datadir@/ibus/component

EXTRA_DIST = \
	pinyin.xml.in \
	genpy.py \
	pydict.py \
	pyparser.y \
	$(NULL)

CLEANFILES = \
	pinyin.xml \
	pypscanner.l \
	$(NULL)

pyscanner.l: genpy.py
	python $(srcdir)/genpy.py > $@

pinyin.xml: pinyin.xml.in
	( \
		libexecdir=${libexecdir}; \
		pkgdatadir=${pkgdatadir}; \
		s=`cat $<`; \
		eval "echo \"$${s}\""; \
	) > $@

test: ibus-engine-pinyin
	$(builddir)/ibus-engine-pinyin


.l.c:
	$(am__skiplex) $(SHELL) $(YLWRAP) $< $(LEX_OUTPUT_ROOT).c $@ $(LEX_OUTPUT_ROOT).h $*.h -- $(LEXCOMPILE)
