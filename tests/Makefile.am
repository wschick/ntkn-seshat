TESTS=\
	ntkn-seshat-test-config

check_PROGRAMS=\
	ntkn-seshat-test-config

ntkn_seshat_test_config_CXXFLAGS=\
	-I$(top_srcdir)/src
ntkn_seshat_test_config_LDADD=\
	$(top_srcdir)/src/libntkn-seshat.a \
	$(NTKN_SESHAT_LIBS) \
	$(BOOST_LIBS) \
	$(CASSANDRA_LIBS) \
	-lboost_unit_test_framework
ntkn_seshat_test_config_SOURCES=\
	ConfigTest.cpp
