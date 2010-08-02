/*
 * InvalidGroupException.h
 *
 *  Created on: Aug 1, 2010
 *      Author: james.cape
 */

#ifndef INVALIDGROUPEXCEPTION_H_
#define INVALIDGROUPEXCEPTION_H_

#include <string>
#include <stdexcept>

namespace com {

namespace ntkn {

namespace seshat {

class InvalidGroupException : public std::invalid_argument {
public:
	InvalidGroupException(const std::string& group);
	~InvalidGroupException() throw ();
};

}

}

}

#endif /* INVALIDGROUPEXCEPTION_H_ */
