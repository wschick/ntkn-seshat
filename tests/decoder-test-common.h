#ifndef _DECODER_TEST_COMMON_H
#define _DECODER_TEST_COMMON_H

#include <string>

typedef struct TestMessageField{

	TestMessageField(int t,int i,const char * v):
		type(t),id(i),value(v)
	{

	}
	int type;
	int id;
	std::string value;
};

typedef struct MessageHeader{
public:
	MessageHeader(int messageLength,
				int txmitId,
				int typeId,
				int version,
				int categoryId,
				int messageId,
				int crc):
		messageLength(messageLength),
		txmitId(txmitId),
		typeId(typeId),
		version(version),
		categoryId(categoryId),
		messageId(messageId),
		crc(crc)
	{

	}
	int messageLength;
	int txmitId;
	int typeId;
	int version;
	int categoryId;
	int messageId;
	int crc;
};

#endif
