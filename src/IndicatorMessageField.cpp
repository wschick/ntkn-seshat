/*
 * IndicatorMessageField.cpp
 *
 *  Created on: Aug 5, 2010
 *      Author: will.schick
 */

#include "IndicatorMessageField.h"



IndicatorMessageField::IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, float floatValue):
			fieldType(fieldType),fieldId(fieldId){
	fieldValue.floatValue = floatValue;
}

IndicatorMessageField::IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, double doubleValue):
				fieldType(fieldType),fieldId(fieldId){
	fieldValue.doubleValue = doubleValue;
}

IndicatorMessageField::IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, uint32_t intValue):
				fieldType(fieldType),fieldId(fieldId){
	fieldValue.intValue = intValue;
}

IndicatorMessageField::IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, uint16_t shortValue):
					fieldType(fieldType),fieldId(fieldId){
	fieldValue.shortValue = shortValue;
}

IndicatorMessageField::IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, uint64_t longValue):
					fieldType(fieldType),fieldId(fieldId){
	fieldValue.longValue = longValue;
}

IndicatorMessageField::IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, bool boolValue):
					fieldType(fieldType),fieldId(fieldId){
	fieldValue.booleanValue = boolValue;
}

IndicatorMessageField::IndicatorMessageField(uint8_t fieldType,uint16_t fieldId, int8_t byteValue):
						fieldType(fieldType),fieldId(fieldId){
	fieldValue.byteValue = byteValue;
}

uint8_t  IndicatorMessageField::getFieldType() const{
	return fieldType;
}

uint16_t  IndicatorMessageField::getFieldId() const{
	return fieldId;
}

std::string IndicatorMessageField::getValueAsString() const
{
	std::ostringstream os;
	os.setf(std::ostringstream::showpoint);

	//check the type to know how to format string
	//TODO - this convers all data in spec as of 8/5/2010, but not all types - so it passes
	//unit test, but is not complete
	if (fieldType == FLOAT)
		os <<fieldValue.floatValue;
	if (fieldType == INT)
		os << fieldValue.intValue;
	if (fieldType == SHORT)
		os << fieldValue.shortValue;
	if (fieldType == YES_NO_NA)
		os << (int32_t)fieldValue.byteValue;

	return os.str();
}
