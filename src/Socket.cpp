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

Socket::Socket(const Database &database, const Logger &logger)
	:db(database),
	 lg(logger),
	 th(*(new Thread<Socket>(*this)))
{

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
