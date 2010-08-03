/*
 * Database.h
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <string>

namespace com {

namespace ntkn {

namespace seshat {

class Database {
public:
	Database();
	virtual ~Database();

	void connect(std::string host,
				 std::string username,
				 std::string password);
	void connect(std::string host);
	void connect();
	void run();
	void insert();
	void insertv();
};

}

}

}

#endif /* DATABASE_H_ */
