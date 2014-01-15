#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(snow, 0.1, ned.rihine@gmail.com)
SNOW_DESCRIPTION='maybe common lisp'
AC_SUBST(SNOW_DESCRIPTION)
AC_CANONICAL_SYSTEM

# Initialize Libtool
LT_INIT
# Initialize automake
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_AWK
AC_PROG_LN_S
AC_PROG_MAKE_SET

AC_LIBTOOL_WIN32_DLL

# addtion command line options
# 
# --enable-gc
# 
AC_ARG_ENABLE(gc,
    AC_HELP_STRING([--enable-gc],
        [Enable GC suppert [default=yes]]),
    ,enable_gc=yes)
# 
# --enable-tests
# 
AC_ARG_ENABLE(tests,
    AC_HELP_STRING([--enable-tests],
    [enable test suites [default=no]]),
    ,enable_tests=no)
# 
# --enable-debug
# 
AC_ARG_ENABLE(debug,
    AC_HELP_STRING([--enable-debug],
        [use 'DEBUG' configuration [default=no]]),
        , enable_debug=no)

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADER_STDBOOL
AC_CHECK_HEADERS([stddef.h stdint.h])

AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for typedefs, structures, and compiler characteristics.
## Keywords
AC_C_INLINE
AC_C_VOLATILE
AC_C_STRINGIZE
AC_C_CONST
AC_C_RESTRICT
## Types
AC_CHECK_SIZEOF(void *)
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

## Makefile.am variables
AM_CONDITIONAL(TESTS, test x$enable_tests = xyes)

AC_CONFIG_MACRO_DIR([builds/m4])
AC_CONFIG_SRCDIR([include/snow/snow.h])
AC_CONFIG_HEADERS([include/config.h])

AC_CONFIG_FILES([Makefile
    include/Makefile
    include/snow/Makefile
    src/Makefile])
AC_CONFIG_FILES([snow.pc:snow.pc.in])
AC_OUTPUT
