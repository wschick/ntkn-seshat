/*
 * InvalidGroupException.cpp
 *
 *  Created on: Aug 1, 2010
 *      Author: james.cape
 */

#include "InvalidGroupException.h"
#include <boost/format.hpp>

using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

InvalidGroupException::InvalidGroupException(const string& group)
	: std::invalid_argument("The given multicast group `"+group+"' is invalid.") {
}

InvalidGroupException::~InvalidGroupException() throw () {

}

}

}

}
