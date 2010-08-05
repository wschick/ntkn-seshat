/*
 * MessageDecoder.h
 *
 *  Created on: Aug 4, 2010
 *      Author: will.schick
 */

#ifndef MESSAGEDECODER_H_
#define MESSAGEDECODER_H_

#include "IndicatorMessage.h"

using namespace com::ntkn;

/**
 * Interface for decoder which converts a byte array to c++ object
 */
class MessageDecoder {
public:
	MessageDecoder();
	virtual ~MessageDecoder();

	/**
	 * Decodes an LB message byte array into a c++ object
	 *
	 * Note - you will have to free the memory manually with "delete" op if you use this method.
	 * TODO - Is this a good convention to use for memory? Requires client to call "delete" operator
	 */
	virtual IndicatorMessage * decodeByteArray(char * byte) =0;
};

#endif /* MESSAGEDECODER_H_ */
