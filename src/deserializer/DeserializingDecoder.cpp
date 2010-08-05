/*
 * DeserializingDecoder.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: will.schick
 */

#include "DeserializingDecoder.h"
#include "DecodedIndicatorMessage.h"
#include <stdint.h>
#include <iostream>

using namespace com::ntkn;

#define HEADER_SIZE 10
#define TRAILER_SIZE 4

/**
 * Pulls a short integer from the byte array, and formats
 */
uint16_t getShort(char * bytes, int offset);
/**
 * Pulls an integer from the byte array, and formats
 */
uint32_t getInt(char * bytes, int offset);
/**
 * Pulls a long from the byte array, and formats
 */
uint64_t getLong(char * bytes, int offset);
/**
 * Decodes a single message field, advances the position variable to the end of the
 * fields poistion in the byte arrary
 */
IndicatorMessageField decodeMessageField(char * bytes, int & position);

DeserializingDecoder::DeserializingDecoder() {
}

DeserializingDecoder::~DeserializingDecoder() {
}


IndicatorMessage * DeserializingDecoder::decodeByteArray(char * bytes)
{
	int messageLength = getShort(bytes,0);
	int txmitId = getInt(bytes,2);
	int typeId = bytes[6];
	int version = bytes[7];
	int categoryId = getShort(bytes,8);
	int messageId = (typeId & 0xFF) << 24 |
						( version & 0xFF) << 16 |
						( categoryId & 0xFFFF) ;

	//temporarily holds all out fields
	std::vector<IndicatorMessageField> fields;

	int position = HEADER_SIZE;

	//pull all fields that appear before the trailer
	while (position < messageLength  - (TRAILER_SIZE))
		fields.push_back(decodeMessageField(bytes,position));

	//pull the crc
	int crc = getInt(bytes,position);


    return new DecodedIndicatorMessage(messageLength, txmitId, typeId, version, categoryId, messageId, crc, fields);
}

/**
 * Decodes a single message field, advances the position variable to the end of the
 * fields poistion in the byte arrary
 */
IndicatorMessageField decodeMessageField(char * bytes, int & position)
{
	//pull type and id
	uint8_t type = bytes[position++];
	uint16_t id = bytes[position++];

	//switch on type, this will determine how many bytes we
	//pull out, and how they are formatted
	switch (type) {
		case FLOAT:
		{
			uint32_t asInt = getInt(bytes,position);
			float f = *(float*)&asInt;
			position+=FLOAT_SIZE;
			return IndicatorMessageField(type,id,f);
			break;
		}
		case SHORT:
		{
			uint16_t asInt = getShort(bytes,position);
			position+=SHORT_SIZE;
			return IndicatorMessageField(type,id,asInt);
			break;
		}
		case INT:
		{
			uint32_t asInt = getInt(bytes,position);
			position+=INT_SIZE;
			return IndicatorMessageField(type,id,asInt);
			break;
		}

		case LONG:
		{
			uint64_t asLong = getLong(bytes,position);
			position+=LONG_SIZE;
			return IndicatorMessageField(type,id,asLong);
			break;
		}

		case DOUBLE:
		{
			uint64_t asLong = getLong(bytes,position);
			double f = *(double*)&asLong;
			position+=DOUBLE_SIZE;
			return IndicatorMessageField(type,id,f);
			break;
		}
		case BOOLEAN:
		{
			return IndicatorMessageField(type,id,(bool)bytes[position++]);
			break;
		}
		case YES_NO_NA:
		case DIRECTIONAL:
		{
			return IndicatorMessageField(type,id,(int8_t)bytes[position++]);
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

const std::vector<IndicatorMessageField> & DecodedIndicatorMessage::getFields()
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

