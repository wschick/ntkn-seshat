/*
 * Socket.cpp
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#include "Socket.h"

namespace com {

namespace ntkn {

namespace seshat {

Socket::Socket(Database &database, Logger &logger)
	:db(database),
	 lg(logger){

}

Socket::~Socket() {
}

void Socket::bind(const struct in_addr *ifaddr, const struct sockaddr_in *maddr)
{

}

void Socket::run()
{

}

}

}

}
