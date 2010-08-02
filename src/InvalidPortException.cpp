/*
 * InvalidPortException.cpp
 *
 *  Created on: Aug 1, 2010
 *      Author: james.cape
 */

#include "InvalidPortException.h"

#include <string>

#include <boost/format.hpp>

using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

InvalidPortException::InvalidPortException() :
	std::invalid_argument::invalid_argument("Invalid port given.")
{
}

InvalidPortException::~InvalidPortException() throw ()
{
}

}

}

}
