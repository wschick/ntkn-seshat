/*
 * DecodedIndicatorMessage.h
 *
 *  Created on: Aug 4, 2010
 *      Author: will.schick
 */

#ifndef DECODEDINDICATORMESSAGE_H_
#define DECODEDINDICATORMESSAGE_H_

#include "IndicatorMessage.h"
//TODO - fix namespace
using namespace com::ntkn;

/**
 * Implemenntation used by the deserializing decoder. It is basically a read only container of
 * message fields.
 */
class DecodedIndicatorMessage: public IndicatorMessage {
public:
	DecodedIndicatorMessage(char * bytes);
	DecodedIndicatorMessage(int messageLength, int txmitId, int typeId,
						int version, int categoryId, int messageId, int crc, const std::vector<IndicatorMessageField> & fields);
	virtual ~DecodedIndicatorMessage();

	int getCategoryId();
	int getTransmitId();
	int getLength();
	int getTypeId();
	int getVersion();
	int getMessageId();
	int getCrc();

	const std::vector<IndicatorMessageField> & getFields();
private:
	int messageLength;
	int txmitId;
	int typeId;
	int version;
	int categoryId;
	int messageId;
	int crc;

	std::vector<IndicatorMessageField> fields;
};

#endif /* DECODEDINDICATORMESSAGE_H_ */
