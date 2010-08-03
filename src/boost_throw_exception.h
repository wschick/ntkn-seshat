/*
 * boost_throw_exception.h
 *
 * Compatibility wrapper for boost::exceptions
 *
 *  Created on: Aug 3, 2010
 *      Author: james.cape
 */

#ifndef BOOST_THROW_EXCEPTION_H_
#define BOOST_THROW_EXCEPTION_H_

#include <boost/throw_exception.hpp>

#ifndef BOOST_THROW_EXCEPTION
# define BOOST_THROW_EXCEPTION(x) throw x
#endif


#endif /* BOOST_THROW_EXCEPTION_H_ */
