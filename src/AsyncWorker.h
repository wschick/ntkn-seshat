/*
 * AsyncWorker.h
 *
 *  Created on: Aug 3, 2010
 *      Author: james.cape
 */

#ifndef ASYNCWORKER_H_
#define ASYNCWORKER_H_

namespace com
{

namespace ntkn
{

namespace seshat
{

class AsyncWorker
{
public:
	virtual void run() = 0;
};

}

}

}

#endif /* ASYNCWORKER_H_ */
