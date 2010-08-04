/*
 * LoggerThread.h
 *
 *  Created on: Aug 3, 2010
 *      Author: james.cape
 */

#ifndef LOGGERTHREAD_H_
#define LOGGERTHREAD_H_

#include "AsyncWorker.h"

#include <boost/function.hpp>

namespace com
{

namespace ntkn
{

namespace seshat
{

template <class T>
class Thread : public boost::function0<void>
{
public:
	Thread(const T& aw)
		: worker( aw )
	{
	}

	~Thread()
	{
	}

	void operator()()
	{
		this->worker->run();
	}

	const T& worker;
};

}

}

}

#endif /* LOGGERTHREAD_H_ */
