/*
 * IndicatorMessageField.h
 *
 *  Created on: Aug 5, 2010
 *      Author: will.schick
 */

//TODO - fix namespace

#ifndef INDICATORMESSAGEFIELD_H_
#define INDICATORMESSAGEFIELD_H_
#include <stdint.h>
#include <vector>
#include <sstream>

/**
 * Enumeration of message value types. These corresponds to the "field type" field in the
 * message binary.
 *
 * TODO - describe in detail the output format of the string.
 *
 * TODO - double, triple, quadrouple check types used, make sure all will jive
 */
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

/**
 * The size (in bytes) of various message types
 */
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

/**
 * Holds a single message field value. It can be constructed with various types, and formats the
 * data as a string for retrieval.
 */
class IndicatorMessageField {
public:

	IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, float floatValue);
	IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, double doubleValue);
	IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, uint32_t intValue);
	IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, uint16_t shortValue);
	IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, uint64_t longValue);
	IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, bool boolValue);
	IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, int8_t byteValue);

	/**
	 * Gets the field type
	 */
	uint8_t  getFieldType() const;
	/**
	 * Id (releative to category) of this datum
	 */
	uint16_t  getFieldId() const;
	/**
	 * Gets a formatted string representation of the value of this field
	 *
	 * TODO - describe formatting in detail, and make sure implementation is agrees
	 */
	std::string getValueAsString() const;

private:
	uint8_t fieldType;
	uint16_t fieldId;

	union {
		float floatValue;
		int64_t longValue;
		int32_t intValue;
		int16_t shortValue;
		uint8_t byteValue;
		double doubleValue;
		bool booleanValue;
	} fieldValue;
};

#endif /* INDICATORMESSAGEFIELD_H_ */
