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

AM_CXXFLAGS = $(AM_CFLAGS)
AM_LDFLAGS = $(AM_LDFLAGS)

libexec_PROGRAMS = ibus-engine-pinyin

ibus_engine_built_h_sources = \
	pytable.h \
	$(NULL)

ibus_engine_c_sources = \
	main.cc \
	pyparser.cc \
	pyengine.cc \
	pyphrasearray.cc \
	pydb.cc \
	pyeditor.cc \
	$(NULL)
ibus_engine_h_sources = \
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
	$(GENPYTABLE) \
	pinyin.xml.in \
	pydict.py \
	$(NULL)

CLEANFILES = \
	pinyin.xml \
	$(NULL)

check_PROGRAMS =

check_PROGRAMS += test-pyparser
test_pyparser_SOURCES = \
	pyparser.cc \
	pytable.h \
	$(NULL)
test_pyparser_CFLAGS = \
	$(AM_CFLAGS) \
	-DTEST \
	$(NULL)

# check_PROGRAMS += test-pydb
test_pydb_SOURCES = \
	pydb.cc \
	pydb.h \
	pyphrasearray.cc \
	pyphrasearray.h \
	$(NULL)
test_pydb_CFLAGS = \
	$(AM_CFLAGS) \
	-DTEST \
	$(NULL)

TESTS = \
	$(check_PROGRAMS) \
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

