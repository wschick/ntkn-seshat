/*
 * Logger.cpp
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#include "Logger.h"

#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/BasicConfigurator.hh>


using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

Logger::Logger()
{

}

Logger::~Logger()
{
}

void Logger::init(string filename)
{
	// Initialize log4cpp
	try {
		log4cpp::PropertyConfigurator log4cpp_cfg;
		log4cpp_cfg.configure(filename);
	}
	catch (log4cpp::ConfigureFailure e) {
		cout << "Could not create log4cpp, logging to console. Cause: " << e.what() << endl;
		log4cpp::BasicConfigurator log4cpp_cfg;
		log4cpp_cfg.configure();
	}
}

}

}

}