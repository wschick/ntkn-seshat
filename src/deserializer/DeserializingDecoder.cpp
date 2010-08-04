/*
 * DeserializingDecoder.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: will.schick
 */

#include "DeserializingDecoder.h"
#include "DecodedIndicatorMessage.h"

DeserializingDecoder::DeserializingDecoder() {
	// TODO Auto-generated constructor stub

}

DeserializingDecoder::~DeserializingDecoder() {
	// TODO Auto-generated destructor stub
}


IndicatorMessage * DeserializingDecoder::decodeByteArray(char * bytes)
{
	return new DecodedIndicatorMessage(bytes);
}
