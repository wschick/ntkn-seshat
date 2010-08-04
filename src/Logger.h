/*
 * Logger.h
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "AsyncWorker.h"
#include "Thread.h"

#include <string>
#include <log4cpp/Category.hh>

namespace com {

namespace ntkn {

namespace seshat {

class Logger : AsyncWorker {
public:
	Logger();
	virtual ~Logger();

	void init(std::string filename);

	void debug(std::string msg);
	void info(std::string msg);
	void notice(std::string msg);
	void warn(std::string msg);
	void error(std::string msg);
	void crit(std::string msg);

	void run();

	log4cpp::Category *category;
	const Thread<Logger> &th;
};

}

}

}

#endif /* LOGGER_H_ */
