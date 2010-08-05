/*
 * IndicatorMessage.h
 *
 *  Created on: Aug 4, 2010
 *      Author: will.schick
 */

#ifndef INDICATORMESSAGE_H_
#define INDICATORMESSAGE_H_
#include "IndicatorMessageField.h"
#include <stdint.h>
#include <vector>
#include <sstream>
namespace com {

namespace ntkn {

/**
 * Handy enumeration of message types
 */
enum MessageType{
	RELEASE,
	ESTIMATE,
	SYSTEM
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
	 * The transmit Id of message
	 */
	virtual int getTransmitId() = 0;

	/**
	 * Type id of message of message
	 */
	virtual int getTypeId() = 0;

	/**
	 * Version of message
	 */
	virtual int getVersion() = 0;

	/**
	 * The category Id of the indicator
	 */
	virtual int getCategoryId() = 0;

	/**
	 *The message id of the message. This is calculated as:
	 * (typeId & 0xFF) << 24 |
	 * ( version & 0xFF) << 16 |
	 * ( categoryId & 0xFFFF) ;
	 *
	 */
	virtual int getMessageId() = 0;

	/**
	 * The crc from the message packet. This is taken from the message bytes, and is not calculated.
	 */
	virtual int getCrc()=0;

	/**
	 * The set of message fields
	 */
	virtual const std::vector<IndicatorMessageField> & getFields() = 0;

};

}
}
#endif /* INDICATORMESSAGE_H_ */
