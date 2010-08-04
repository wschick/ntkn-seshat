/*
 * IndicatorMessage.h
 *
 *  Created on: Aug 4, 2010
 *      Author: will.schick
 */

#ifndef INDICATORMESSAGE_H_
#define INDICATORMESSAGE_H_

#include <stdint.h>
#include <vector>
namespace com {

namespace ntkn {


enum FieldType{
	FLOAT = 0,
	FLOAT_RANGE = 1,
	SHORT = 2,
	LONG = 3,
	DOUBLE = 4,
	DATE = 5,
	BOOLEAN = 6,
	YES_NO_NA = 7,
	DIRECTIONAL = 8,
	INT = 9,
	TIME = 10
};

enum FieldSize{
	FLOAT_SIZE = 4,
	FLOAT_RANGE_SIZE = 8,
	SHORT_SIZE = 2,
	LONG_SIZE = 8,
	DOUBLE_SIZE = 8,
	DATE_SIZE = 4,
	BOOLEAN_SIZE = 1,
	YES_NO_NA_SIZE = 1,
	DIRECTIONAL_SIZE = 1,
	INT_SIZE = 4,
	TIME_SIZE = 3
};

typedef struct MessageField{
public:
	MessageField(uint8_t fieldType,uint16_t fieldId, float floatValue):
		fieldType(fieldType),fieldId(fieldId)
	{
		fieldValue.floatValue = floatValue;
	}

	MessageField(uint8_t fieldType,uint16_t fieldId, double doubleValue):
			fieldType(fieldType),fieldId(fieldId)
	{
		fieldValue.doubleValue = doubleValue;
	}

	MessageField(uint8_t fieldType,uint16_t fieldId, uint32_t intValue):
			fieldType(fieldType),fieldId(fieldId)
	{
		fieldValue.intValue = intValue;
	}

	MessageField(uint8_t fieldType,uint16_t fieldId, uint16_t shortValue):
				fieldType(fieldType),fieldId(fieldId)
	{
		fieldValue.shortValue = shortValue;
	}

	MessageField(uint8_t fieldType,uint16_t fieldId, uint64_t longValue):
					fieldType(fieldType),fieldId(fieldId)
		{
			fieldValue.longValue = longValue;
		}

	MessageField(uint8_t fieldType,uint16_t fieldId, bool boolValue):
				fieldType(fieldType),fieldId(fieldId)
	{
		fieldValue.booleanValue = boolValue;
	}

	MessageField(uint8_t fieldType,uint16_t fieldId, uint8_t byteValue):
					fieldType(fieldType),fieldId(fieldId)
	{
		fieldValue.byteValue = byteValue;
	}

	uint8_t fieldType;
	uint16_t fieldId;

	union {
		float floatValue;
		uint64_t longValue;
		uint32_t intValue;
		uint16_t shortValue;
		uint8_t byteValue;
		double doubleValue;
		bool booleanValue;
	} fieldValue;

};

/**
 * An abstract indicator message class. Provides methods to
 * access header fields and
 */
class IndicatorMessage {
public:
	IndicatorMessage();
	virtual ~IndicatorMessage();

	/**
	 * Length of message byte array
	 */
	virtual int getLength() = 0;

	/**
	 * The transmit Id of
	 */
	virtual int getTransmitId() = 0;

	/**
	 *
	 */
	virtual int getTypeId() = 0;

	/**
	 *
	 */
	virtual int getVersion() = 0;

	/**
	 * The category Id of the indicator
	 */
	virtual int getCategoryId() = 0;

	/**
	 *
	 */
	virtual int getMessageId() = 0;

	virtual int getCrc()=0;

	virtual std::vector<MessageField> getFields() = 0;

};

}
}
#endif /* INDICATORMESSAGE_H_ */
