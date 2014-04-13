#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT([IAM851 Project1], [1.0])
AM_INIT_AUTOMAKE([-Wall foreign])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Checks for programs.

AC_PROG_CC
AM_PROG_CC_C_O

AC_CONFIG_COMMANDS([mkdir], [$MKDIR_P output])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

echo ""
echo "                       Configure Summary"
echo "                       ================="
echo ""
echo "Compiling Options:"
echo "------------------"
echo "                     C Compiler: $CC"
echo "                       CPPFLAGS: $CPPFLAGS"
echo "                         CFLAGS: $CFLAGS"
echo "                        LDFLAGS: $LDFLAGS"
echo "                           LIBS: $LIBS"

