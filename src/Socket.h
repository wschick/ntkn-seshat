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
#include "AsyncWorker.h"
#include "Thread.h"

using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

class Socket : public AsyncWorker {
public:
	Socket(const Database &database, const Logger &logger);
	virtual ~Socket();

	void bind(const struct in_addr *ifaddr, const struct sockaddr_in *maddr);

	int sockfd;
	const Database &db;
	const Logger &lg;
	const Thread<Socket> &th;

	void run();
};

}

}

}

#endif /* SOCKET_H_ */
