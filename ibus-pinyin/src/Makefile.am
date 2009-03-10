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

check_PROGRAMS = \
	$(NULL)

TESTS = \
	$(check_PROGRAMS) \
	$(NULL)

libexec_PROGRAMS = ibus-engine-pinyin

ibus_engine_pinyin_SOURCES = \
	main.c \
	engine.c \
	engine.h \
	$(NULL)
ibus_engine_pinyin_CFLAGS = \
	@IBUS_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	$(NULL)
ibus_engine_pinyin_LDFLAGS = \
	@IBUS_LIBS@ \
	$(NULL)

component_DATA = \
	pinyin.xml \
	$(NULL)
componentdir = @datadir@/ibus/component

EXTRA_DIST = \
	pinyin.xml.in \
	$(NULL)

CLEANFILES = \
	pinyin.xml \
	$(NULL)

pinyin.xml: pinyin.xml.in
	( \
		libexecdir=${libexecdir}; \
		pkgdatadir=${pkgdatadir}; \
		s=`cat $<`; \
		eval "echo \"$${s}\""; \
	) > $@

test: ibus-engine-pinyin
	$(builddir)/ibus-engine-pinyin
