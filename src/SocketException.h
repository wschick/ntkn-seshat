/*
 * SocketException.h
 *
 *  Created on: Aug 1, 2010
 *      Author: james.cape
 */

#ifndef SOCKETEXCEPTION_H_
#define SOCKETEXCEPTION_H_

#include <string>
#include <stdexcept>

namespace com {

namespace ntkn {

namespace seshat {

class SocketException : public std::runtime_error {
public:
	SocketException(const std::string& perr);
	virtual ~SocketException() throw ();
};

}

}

}

#endif /* SOCKETEXCEPTION_H_ */
