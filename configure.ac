dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([Seshat], [0.1], [it@ntkn.com], [ntkn-seshat], [https://wiki.ntkn.com/Seshat])

AC_CANONICAL_SYSTEM
AM_MAINTAINER_MODE
AM_INIT_AUTOMAKE([no-define])

AC_PROG_CXX
AC_PROG_RANLIB

PKG_CHECK_MODULES(NTKN_SESHAT, [log4cpp >= 1.0])

AC_ARG_WITH([boost],
  [AS_HELP_STRING([--with-boost], [prefix of the Boost installation])],
  [BOOST_LIBS="-L$withval -lboost_program_options -lboost_thread -lboost_filesystem"
   BOOST_CXXFLAGS="-I$withval"],
  [BOOST_LIBS='-lboost_program_options -lboost_thread -lboost_filesystem'
   BOOST_CXXFLAGS=""])
AC_SUBST([BOOST_LIBS])
AC_SUBST([BOOST_CXXFLAGS])

AC_ARG_WITH([mongo],
  [AS_HELP_STRING([--with-mongo], [prefix of the Mongo installation])],
  [MONGO_LIBS="-L$withval -lmongoclient"
   MONGO_CFLAGS="-I$withval/mongo"],
  [MONGO_LIBS="-lmongoclient"
   MONGO_CXXFLAGS="-I$includedir/mongo"])
AC_SUBST([MONGO_LIBS])
AC_SUBST([MONGO_CXXFLAGS])

AC_CONFIG_FILES(Makefile src/Makefile tests/Makefile)
AC_OUTPUT

