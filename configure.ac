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

AC_ARG_WITH([cassandra],
  [AS_HELP_STRING([--with-cassandra], [prefix of the libcassandra installation])],
  [CASSANDRA_LIBS="-L$withval"
   CASSANDRA_CFLAGS="-I$withval/libcassandra"],
  [CASSANDRA_LIBS=""
   CASSANDRA_CXXFLAGS="-I$includedir/libcassandra"])
AC_SUBST([CASSANDRA_LIBS])
AC_SUBST([CASSANDRA_CXXFLAGS])

AC_CONFIG_FILES(Makefile src/Makefile tests/Makefile)
AC_OUTPUT

