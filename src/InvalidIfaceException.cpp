/*
 * InvalidIfaceException.cpp
 *
 *  Created on: Aug 1, 2010
 *      Author: james.cape
 */

#include "InvalidIfaceException.h"

using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

InvalidIfaceException::InvalidIfaceException(const string& addr) :
		std::invalid_argument::invalid_argument("The given interface address `"+addr+"' is invalid")
{
}

InvalidIfaceException::~InvalidIfaceException() throw ()
{
}

}

}

}
