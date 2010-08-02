/*
 * Socket.h
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include "Database.h"
#include "Logger.h"

using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

class Socket {
public:
	Socket(Database &database, Logger &logger);
	virtual ~Socket();

	void bind(const struct in_addr *ifaddr, const struct sockaddr_in *maddr);
	void run();

	int sockfd;
	Database &db;
	Logger &lg;
};

}

}

}

#endif /* SOCKET_H_ */
