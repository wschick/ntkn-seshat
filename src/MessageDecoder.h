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


class MessageDecoder {
public:
	MessageDecoder();
	virtual ~MessageDecoder();

	/**
	 * Note - you will have to free the memory manually with "delete" op if you use this method.
	 * TODO - think about a better way to do this
	 */
	virtual IndicatorMessage * decodeByteArray(char * byte) =0;
};

#endif /* MESSAGEDECODER_H_ */
