bin_PROGRAMS=\
	ntkn-seshat
noinst_LIBRARIES=\
	libntkn-seshat.a

libntkn_seshat_a_SOURCES=\
	Config.cpp \
	Database.cpp \
	Logger.cpp \
	Socket.cpp \
	InvalidGroupException.cpp \
	InvalidIfaceException.cpp \
	InvalidPortException.cpp \
	SocketException.cpp \
	MessageDecoder.cpp \
	IndicatorMessage.cpp \
	IndicatorMessageField.cpp \
	deserializer/DecodedIndicatorMessage.cpp \
	deserializer/DeserializingDecoder.cpp 

ntkn_seshat_CXXFLAGS=\
	$(CASSANDRA_CXXFLAGS) \
	$(BOOST_CXXFLAGS)
ntkn_seshat_LDADD=\
	libntkn-seshat.a \
	$(NTKN_SESHAT_LIBS) \
	$(BOOST_LIBS) \
	$(CASSANDRA_LIBS)
ntkn_seshat_SOURCES=\
	ntkn-seshat.cpp

