/*
 * InvalidPortException.h
 *
 *  Created on: Aug 1, 2010
 *      Author: james.cape
 */

#ifndef INVALIDPORTEXCEPTION_H_
#define INVALIDPORTEXCEPTION_H_

#include <stdexcept>

namespace com {

namespace ntkn {

namespace seshat {

class InvalidPortException : public std::invalid_argument {
public:
	InvalidPortException();
	~InvalidPortException() throw ();
};

}

}

}

#endif /* INVALIDPORTEXCEPTION_H_ */
