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

void Logger_run()
{

}

Logger::Logger()
	: th( *(new Thread<Logger>(*this) ) )
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



void Logger::debug(std::string msg)
{

}

void Logger::info(std::string msg)
{

}

void Logger::notice(std::string msg)
{

}

void Logger::warn(std::string msg)
{

}

void Logger::error(std::string msg)
{

}

void Logger::crit(std::string msg)
{

}

}

}

}
