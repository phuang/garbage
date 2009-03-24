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

@MAINTAINER_MODE_FALSE@skip_genpytable=test -f $@ ||
GENPYTABLE = genpytable.py

AM_CFLAGS = \
	@IBUS_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	$(NULL)
AM_LDFLAGS = \
	@IBUS_LIBS@ \
	@SQLITE_LIBS@ \
	$(NULL)

AM_YFLAGS = \
	-d \
	--verbose \
	$(NULL)

AM_LFLAGS = \
	--outfile=$(LEX_OUTPUT_ROOT).c \
	--header-file=$(LEX_OUTPUT_ROOT).h \
	$(NULL)

libexec_PROGRAMS = ibus-engine-pinyin

ibus_engine_built_h_sources = \
	pytable.h \
	$(NULL)

ibus_engine_c_sources = \
	main.c \
	pyparser.c \
	pyengine.c \
	pyphrasearray.c \
	pydb.c \
	$(NULL)
ibus_engine_h_sources = \
	pyscanner.h \
	pinyin.h \
	pyparser.h \
	pyengine.h \
	pyphrasearray.h \
	pydb.h \
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
	@SQLITE_LIBS@ \
	$(NULL)

BUILT_SOURCES = \
	$(ibus_engine_built_c_sources) \
	$(ibus_engine_built_h_sources) \
	$(NULL)

component_DATA = \
	pinyin.xml \
	$(NULL)
componentdir = @datadir@/ibus/component

EXTRA_DIST = \
	$(GENPYSCANNER) \
	pyscanner.l \
	pygrammar.y \
	pinyin.xml.in \
	pydict.py \
	$(NULL)

CLEANFILES = \
	pinyin.xml \
	$(NULL)

check_PROGRAMS = \
	test-pydb \
	test-pyparser \
	$(NULL)

TESTS = \
	$(check_PROGRAMS) \
	$(NULL)

test_pydb_SOURCES = \
	pydb.c \
	pydb.h \
	pyphrasearray.c \
	pyphrasearray.h \
	$(NULL)
test_pydb_CFLAGS = \
	$(AM_CFLAGS) \
	-DTEST \
	$(NULL)

test_pyparser_SOURCES = \
	pyparser.c \
	pytable.h \
	$(NULL)
test_pyparser_CFLAGS = \
	$(AM_CFLAGS) \
	-DTEST \
	$(NULL)

pytable.h: $(GENPYTABLE)
	$(skip_genpytable) $(PYTHON) $(srcdir)/$(GENPYTABLE) > $@

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
