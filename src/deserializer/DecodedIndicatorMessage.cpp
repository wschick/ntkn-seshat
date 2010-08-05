/*
 * DecodedIndicatorMessage.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: will.schick
 */

#include <stdint.h>
#include <iostream>
#include "DecodedIndicatorMessage.h"

using namespace com::ntkn;

#define HEADER_SIZE 10
#define TRAILER_SIZE 4

DecodedIndicatorMessage::DecodedIndicatorMessage(int messageLength, int txmitId, int typeId,
		int version, int categoryId, int messageId, int crc,
		const std::vector<IndicatorMessageField> & fields):
		messageLength(messageLength), txmitId(txmitId), typeId(typeId),
		version(version), categoryId(categoryId), messageId(messageId), crc(crc),fields(fields)
{

}

DecodedIndicatorMessage::~DecodedIndicatorMessage() {
}

int DecodedIndicatorMessage::getCategoryId(){
	return this->categoryId;
}
int DecodedIndicatorMessage::getTransmitId(){
	return this->txmitId;
}
int DecodedIndicatorMessage::getLength(){
	return this->messageLength;
}
int DecodedIndicatorMessage::getTypeId(){
	return this->typeId;
}
int DecodedIndicatorMessage::getVersion(){
	return this->version;
}
int DecodedIndicatorMessage::getMessageId(){
	return this->messageId;
}
int DecodedIndicatorMessage::getCrc(){
	return this->crc;
}





