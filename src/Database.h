/*
 * Database.h
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "AsyncWorker.h"
#include "Thread.h"

#include <string>

namespace com {

namespace ntkn {

namespace seshat {

class Database : public AsyncWorker {
public:
	Database();
	virtual ~Database();

	void connect(std::string host,
				 std::string username,
				 std::string password);
	void connect(std::string host);
	void connect();
	void insert();
	void insertv();

	void run();

	const Thread<Database> &th;
};

}

}

}

#endif /* DATABASE_H_ */
