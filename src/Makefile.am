AM_CFLAGS = $(MORE_CFLAGS)
AM_CPPFLAGS = $(MORE_CPPFLAGS)
AM_LDFLAGS = $(MORE_LDFLAGS)

bin_PROGRAMS = iris_readout tests
dist_man_MANS = iris_readout.8

## TODO:5000 When you want to add more files, add them below.
## TODO:5000 Automake will find dependencies by itself. Run
## TODO:5000 ./autogen.sh after modifying this file.

iris_readout_SOURCES  = log.c log.h iris_readout.h iris_readout.c drsrop.c drsrop.h 
iris_readout_CFLAGS   = $(AM_CFLAGS) ##@JANSSON_CFLAGS@
iris_readout_LDFLAGS  = $(AM_LDFLAGS) ##@JANSSON_LIBS@

tests_SOURCES  = tests.c iris_readout.h drsrop.c drsrop.h
tests_CFLAGS   = $(AM_CFLAGS) ##@JANSSON_CFLAGS@
tests_LDFLAGS  = $(AM_LDFLAGS) ##@JANSSON_LIBS@

## TODO:2004 Each time you have used `PKG_CHECK_MODULES` macro
## TODO:2004 in `configure.ac`, you get two variables that
## TODO:2004 you can substitute like above.
