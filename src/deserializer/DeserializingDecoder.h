/*
 * DeserializingDecoder.h
 *
 *  Created on: Aug 4, 2010
 *      Author: will.schick
 */

#ifndef DESERIALIZINGDECODER_H_
#define DESERIALIZINGDECODER_H_
// TODO - fix namespace

#include "MessageDecoder.h"

/**
 * A decoder which deserializes the LB message into object fields.
 */
class DeserializingDecoder: public MessageDecoder {
public:
	DeserializingDecoder();
	virtual ~DeserializingDecoder();

	IndicatorMessage * decodeByteArray(char * bytes);
};

#endif /* DESERIALIZINGDECODER_H_ */
