/*
 * InvalidIfaceException.h
 *
 *  Created on: Aug 1, 2010
 *      Author: james.cape
 */

#ifndef INVALIDIFACEEXCEPTION_H_
#define INVALIDIFACEEXCEPTION_H_

#include <string>
#include <stdexcept>
#include "boost_throw_exception.h"

namespace com {

namespace ntkn {

namespace seshat {

class InvalidIfaceException : public std::invalid_argument {
public:
	InvalidIfaceException(const std::string& __arg);
	virtual ~InvalidIfaceException() throw ();
};

}

}

}

#endif /* INVALIDIFACEEXCEPTION_H_ */
