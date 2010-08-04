/*
 * Database.cpp
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#include "Database.h"

#include <boost/thread.hpp>

using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

Database::Database()
	: th( *(new Thread<Database>(*this)) )
{

}

Database::~Database()
{
}

void Database::connect()
{

}

void Database::connect(string host)
{

}

void Database::connect(string host, string username, string secret)
{
	boost::thread(this->th);
}

void Database::run()
{

}

void Database::insert()
{

}

void Database::insertv()
{

}

}

}

}
