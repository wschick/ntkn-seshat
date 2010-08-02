/*
 * SocketException.cpp
 *
 *  Created on: Aug 1, 2010
 *      Author: james.cape
 */

#include "SocketException.h"

using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

SocketException::SocketException(const string& perr) :
		runtime_error::runtime_error(perr)
{
}

SocketException::~SocketException() throw()
{
	// TODO Auto-generated destructor stub
}

}

}

}
