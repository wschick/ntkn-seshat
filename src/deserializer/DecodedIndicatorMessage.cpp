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

uint16_t getShort(char * bytes, int offset);
uint32_t getInt(char * bytes, int offset);
uint64_t getLong(char * bytes, int offset);
MessageField decodeMessageField(char * bytes, int & position);

DecodedIndicatorMessage::DecodedIndicatorMessage(char * bytes) {
		this->messageLength = getShort(bytes,0);
		this->txmitId = getInt(bytes,2);
		this->typeId = bytes[6];
		this->version = bytes[7];
		this->categoryId = getShort(bytes,8);
		this->messageId = (typeId & 0xFF) << 24 |
							( version & 0xFF) << 16 |
							( categoryId & 0xFFFF) ;

		int position = HEADER_SIZE;

		std::cout <<"Message Length: "<< messageLength << "\n";
		while (position < messageLength  - (TRAILER_SIZE))
		{
			std::cout << position << "\n";
			this->fields.push_back(decodeMessageField(bytes,position));
		}

		this->crc = getInt(bytes,position);
}

DecodedIndicatorMessage::~DecodedIndicatorMessage() {
	// TODO Auto-generated destructor stub
}

int DecodedIndicatorMessage::getCategoryId()
{
	return this->categoryId;
}



int DecodedIndicatorMessage::getTransmitId()
{
	return this->txmitId;
}

int DecodedIndicatorMessage::getLength()
{
	return this->messageLength;
}
int DecodedIndicatorMessage::getTypeId()
{
	return this->typeId;
}
int DecodedIndicatorMessage::getVersion()
{
	return this->version;
}
int DecodedIndicatorMessage::getMessageId()
{
	return this->messageId;
}

int DecodedIndicatorMessage::getCrc()
{
	return this->crc;
}

MessageField decodeMessageField(char * bytes, int & position)
{
	uint8_t type = bytes[position++];
	uint16_t id = bytes[position++];

	switch (type) {
		case FLOAT:
		{
			uint32_t asInt = getInt(bytes,position);
			float f = *(float*)&asInt;
			position+=4;
			return MessageField(type,id,f);
			break;
		}
		case SHORT:
		{
			uint16_t asInt = getShort(bytes,position);
			position+=2;
			return MessageField(type,id,asInt);
			break;
		}
		case INT:
		{
			uint32_t asInt = getInt(bytes,position);
			position+=4;
			return MessageField(type,id,asInt);
			break;
		}

		case LONG:
		{
			uint64_t asLong = getLong(bytes,position);
			position+=8;
			return MessageField(type,id,asLong);
			break;
		}

		case DOUBLE:
		{
			uint64_t asLong = getLong(bytes,position);
			double f = *(double*)&asLong;
			position+=8;
			return MessageField(type,id,f);
			break;
		}
		case BOOLEAN:
		{
			return MessageField(type,id,(bool)bytes[position++]);
			break;
		}
		case YES_NO_NA:
		case DIRECTIONAL:
		{
			return MessageField(type,id,(uint8_t)bytes[position++]);
			break;
		}
		case FLOAT_RANGE:
		case DATE:
		case TIME:

		default:
			std::cout <<"Unhandled type: "<< (int)type << "\n";
			throw new std::exception();
			break;
	}
}

std::vector<MessageField> DecodedIndicatorMessage::getFields()
{
	return this->fields;
}

uint16_t getShort(char * bytes, int offset)
{
	return (0x00FF & bytes[0 + offset]) << 8 |
			(0x00FF & bytes[1+offset]) << 0;
}

uint32_t getInt(char * bytes, int offset)
{
	return (0x000000FF & bytes[offset]) << 24 |
			(0x000000FF & bytes[offset + 1]) << 16 |
			(0x000000FF & bytes[offset + 2]) << 8 |
	       (0x000000FF & bytes[offset + 3]) << 0;
}

uint64_t getLong(char * bytes, int offset)
{
	return ((uint64_t)(0x00000000000000FF & bytes[offset])) << 56 |
			((uint64_t)(0x00000000000000FF & bytes[offset + 1])) << 48 |
			((uint64_t)(0x00000000000000FF & bytes[offset + 2])) << 40 |
			((uint64_t)(0x00000000000000FF & bytes[offset + 3])) << 32 |
			(0x00000000000000FF & bytes[offset + 4]) << 24 |
			(0x00000000000000FF & bytes[offset + 5]) << 16 |
			(0x00000000000000FF & bytes[offset + 6]) << 8 |
		   (0x00000000000000FF & bytes[offset + 7]) << 0;
}



