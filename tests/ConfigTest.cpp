/*
 * ConfigTest.cpp
 *
 *  Created on: Jul 30, 2010
 *      Author: james.cape
 */

#include "ntkn-seshat-test.h"

#include <Config.h>
#include <SocketException.h>
#include <InvalidGroupException.h>
#include <InvalidIfaceException.h>
#include <InvalidPortException.h>

#include <iostream>

using namespace std;
using namespace com::ntkn::seshat;

#define BOOST_TEST_MODULE TestConfig

BOOST_AUTO_TEST_SUITE( config_parse_srcgrouport );

// Test Valid Input #1
BOOST_AUTO_TEST_CASE( config_parse_srcgroupport_inaddr_any )
{
	Config cfg;
	group_listen_address addr = { 0 };
	const string str_addr = "*:224.0.1.1:1";

	addr.bindaddr.sin_family = PF_INET;
	addr.bindaddr.sin_addr.s_addr = htonl(0xe0000101);
	addr.bindaddr.sin_port = 1;
	addr.req.imr_multiaddr.s_addr = htonl(0xe0000101);
	addr.req.imr_address.s_addr = INADDR_ANY;
	addr.req.imr_ifindex = 0;

	cfg.add_srcgroupport(str_addr);

	BOOST_REQUIRE( memcmp(&addr, &(cfg.addrv[0]), sizeof(group_listen_address)) == 0 );
}

// Test valid input #2
BOOST_AUTO_TEST_CASE( config_add_srcgroupport_srcaddr )
{
	Config cfg;
	group_listen_address addr = { 0 };
	const string str_addr = "127.0.0.1:224.0.1.1:1";

	addr.bindaddr.sin_family = PF_INET;
	addr.bindaddr.sin_addr.s_addr = htonl(0xe0000101);
	addr.bindaddr.sin_port = 1;
	addr.req.imr_multiaddr.s_addr = htonl(0xe0000101);
	addr.req.imr_address.s_addr = htonl(0x7f000001);
	addr.req.imr_ifindex = 0;

	cfg.add_srcgroupport(str_addr);

	BOOST_REQUIRE( memcmp(&addr, &(cfg.addrv[0]), sizeof(group_listen_address)) == 0 );
}

BOOST_AUTO_TEST_CASE( config_add_srcgrouport_invalid_if )
{
	Config cfg;

	BOOST_REQUIRE_THROW( cfg.add_srcgroupport("0.1.1.1:224.0.1.1:1"), InvalidIfaceException );
}

BOOST_AUTO_TEST_CASE( config_add_srcgroupport_invalid_group )
{
	Config cfg;

	BOOST_REQUIRE_THROW( cfg.add_srcgroupport("127.0.0.1:1.1.1.1:1"), InvalidGroupException );
}

BOOST_AUTO_TEST_CASE( config_add_srcgroupport_invalid_port )
{
	Config cfg;

	BOOST_REQUIRE_THROW( cfg.add_srcgroupport("127.0.0.1:224.0.1.1:123123123"), InvalidPortException );
}

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE( config_parse_argv );

BOOST_AUTO_TEST_CASE( config_parse_argv_onegroup )
{

}

BOOST_AUTO_TEST_CASE( config_parse_argv_twogroup )
{

}

BOOST_AUTO_TEST_SUITE_END();
