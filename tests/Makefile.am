TESTS=\
	ntkn-seshat-test-config \
	ntkn-seshat-test-socket \
	ntkn-seshat-test-message

check_PROGRAMS=\
	ntkn-seshat-test-config \
	ntkn-seshat-test-socket \
	ntkn-seshat-test-message

AM_CXXFLAGS=\
	-I$(top_srcdir)/src

LDADD=\
	$(top_srcdir)/src/libntkn-seshat.a \
	$(NTKN_SESHAT_LIBS) \
	$(BOOST_LIBS) \
	$(CASSANDRA_LIBS) \
	-lboost_unit_test_framework

ntkn_seshat_test_config_SOURCES=\
	ConfigTest.cpp

ntkn_seshat_test_socket_SOURCES=\
	SocketTest.cpp
	
ntkn_seshat_test_message_SOURCES=\
	MessageDecoderTest.cpp \
	DecoderTestData.cpp
