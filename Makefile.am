SUBDIRS = include src
if TESTS
  SUBDIRS += tests
endif

pkgconfigdir = $(libdir)/pkg-config
pkgincludedir = $(includedir)/snow
pkgconfig_DATA = snow.pc

CLEANFILES = snow.pc

EXTRA_DIST = snow.pc.in

ACLOCAL_AMFLAGS = -I builds/m4

dist-hook: changelog

changelog: $(top_srcdir)/.git/HEAD
	git log --stat > ChangeLog
