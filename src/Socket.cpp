/*
 * Socket.cpp
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#include "Socket.h"

#include "boost_throw_exception.h"
#include "SocketException.h"

#include <boost/thread.hpp>

#include <sys/types.h>
#include <sys/socket.h>

using namespace std;

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

void Socket::init(const struct ip_mreqn *mreq, const struct sockaddr_in* bindaddr)
{
	this->sockfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if( this->sockfd != 0 )
	{
		BOOST_THROW_EXCEPTION(SocketException("Could not construct socket."));
	}

	if (bind(this->sockfd, (const struct sockaddr*)bindaddr, sizeof(struct sockaddr_in)) < 0)
	{
		// FIXME: Create BindException
		BOOST_THROW_EXCEPTION(SocketException("Could not bind to multicast address + port."));
	}

	if (setsockopt(this->sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, mreq, sizeof(struct ip_mreqn)) < 0)
	{
		// FIXME: Create MulticastAddException
		BOOST_THROW_EXCEPTION(SocketException("Could not join the multicast group."));
	}

	boost::thread(this->th);
}

void Socket::run()
{
	ssize_t msglen;
	struct msghdr msg;

	while ((msglen = recvmsg(this->sockfd, &msg, 0)) > 0)
	{
		// TODO: Thread Cancellation?
	}
}

}

}

}
