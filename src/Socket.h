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

#include <netinet/ip.h>

using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

class Socket : public AsyncWorker {
public:
	Socket(const Database &database, const Logger &logger);
	virtual ~Socket();

	void init(const struct ip_mreqn *mreq, const struct sockaddr_in *bindaddr);

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
