/*
 * Thread.cpp
 *
 *  Created on: Aug 3, 2010
 *      Author: james.cape
 */

#include "Thread.h"

namespace com
{

namespace ntkn
{

namespace seshat
{

template <class T>
Thread<T>::Thread(const T& object)
	: obj( object )
{
}

template <class T>
Thread<T>::~Thread()
{
}

template <class T>
void Thread<T>::operator()()
{
	this->obj->run();
}

}

}

}
