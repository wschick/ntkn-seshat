/*
 * DecodedIndicatorMessage.h
 *
 *  Created on: Aug 4, 2010
 *      Author: will.schick
 */

#ifndef DECODEDINDICATORMESSAGE_H_
#define DECODEDINDICATORMESSAGE_H_

#include "IndicatorMessage.h"

using namespace com::ntkn;

class DecodedIndicatorMessage: public IndicatorMessage {
public:
	DecodedIndicatorMessage(char * bytes);
	virtual ~DecodedIndicatorMessage();

	int getCategoryId();
	int getTransmitId();
	int getLength();
	int getTypeId();
	int getVersion();
	int getMessageId();
	int getCrc();

	std::vector<MessageField> getFields();
private:
	int messageLength;
	int txmitId;
	int typeId;
	int version;
	int categoryId;
	int messageId;
	int crc;

	std::vector<MessageField> fields;
};

#endif /* DECODEDINDICATORMESSAGE_H_ */
