/*
 * Config.cpp
 *
 *  Created on: Jul 29, 2010
 *      Author: james.cape
 */

#include "Config.h"
#include "InvalidGroupException.h"
#include "InvalidIfaceException.h"
#include "InvalidPortException.h"
#include "SocketException.h"

#include <iostream>

#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

#include <arpa/inet.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>

using namespace std;

namespace com {

namespace ntkn {

namespace seshat {

#define CONFIG_IFR_BUF_LEN 2048

Config::Config() {
}

Config::~Config() {
}

void Config::parse_argv(int argc, char *argv[]) {
	vector<string> stringaddrv;

	boost::program_options::options_description opts;
	boost::program_options::variables_map vm;

	opts.add_options()
			("help,h",
			 "Display the help text")
			("multicast-address,a",
			 boost::program_options::value< vector<string> >(&stringaddrv)->multitoken(),
			 "Multicast <address>:<port> to listen to")
			("db-host,h",
			 boost::program_options::value<string>(&this->db_host)->default_value("localhost"),
			 "Database server location <host>:<port>")
			("db-username,u",
			 boost::program_options::value<string>(&this->db_username),
			 "Database username to use")
			("db-password,p",
			 boost::program_options::value<string>(&this->db_password),
			 "Database password")
			("log4cpp-properties,l",
			 boost::program_options::value<string>(&this->log4cpp_filename),
			 "Log4cpp Properties file location");

	boost::program_options::store(boost::program_options::parse_command_line(argc, argv, opts), vm);
	boost::program_options::notify(vm);

	for (int str_i = 0; str_i < stringaddrv.size(); str_i++) {
		this->add_srcgroupport(stringaddrv[str_i]);
	}
}

void Config::_init_if_list()
{
	// We assume there's at least a loopback interface
	if (this->_if_list.size() == 0)
	{
		char ifr_buf[CONFIG_IFR_BUF_LEN];
		struct ifconf ifc;
		struct ifreq* ifr;
		int sockfd, n_ifr, i_ifr;

		sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sockfd < 0)
		{
			BOOST_THROW_EXCEPTION(SocketException("Could not create IP socket"));
		}

		ifc.ifc_len = CONFIG_IFR_BUF_LEN;
		ifc.ifc_req = (struct ifreq*) ifr_buf;

		if (ioctl(sockfd, SIOCGIFCONF, &ifc) < 0)
		{
			close(sockfd);
			BOOST_THROW_EXCEPTION(SocketException("Could not list interfaces"));
		}

		n_ifr = ifc.ifc_len / sizeof(struct ifreq);
		i_ifr = 0;

		ifr = ifc.ifc_req;
		while (i_ifr < n_ifr)
		{
			if (ifr->ifr_ifru.ifru_addr.sa_family == PF_INET)
			{
				this->_if_list.push_back(*((struct sockaddr_in *)&(ifr->ifr_addr)));
			}

			ifr++;
			i_ifr++;
		}

		close(sockfd);
	}
}

void Config::add_srcgroupport(const string src, const string group, int port)
{
	group_listen_address addr = { 0 };

	if (src == "*")
	{
		addr.req.imr_address.s_addr = INADDR_ANY;
		addr.req.imr_ifindex = 0;
	}
	else if (inet_pton(PF_INET, src.c_str(), &(addr.req.imr_address)) < 0)
	{
		BOOST_THROW_EXCEPTION(InvalidIfaceException(src));
	}
	else
	{
		bool found;

		found = false;
		this->_init_if_list();

		for (int if_i = 0; !found && if_i < this->_if_list.size(); if_i++)
		{
			if (this->_if_list[if_i].sin_addr.s_addr == addr.req.imr_address.s_addr)
			{
				found = true;
			}
		}

		if (!found)
		{
			BOOST_THROW_EXCEPTION(InvalidIfaceException(src));
		}
	}

	if (inet_pton(PF_INET, group.c_str(), &(addr.req.imr_multiaddr)) < 0)
	{
		BOOST_THROW_EXCEPTION(InvalidGroupException(group));
	}

	if (((const unsigned char *) &(addr.req.imr_multiaddr.s_addr))[0] < 224 ||
		((const unsigned char *) &(addr.req.imr_multiaddr.s_addr))[0] > 240)
	{
		BOOST_THROW_EXCEPTION(InvalidGroupException(group));
	}

	if (port < 0 || port > 65535)
	{
		BOOST_THROW_EXCEPTION(InvalidPortException());
	}

	addr.bindaddr.sin_family = PF_INET;
	addr.bindaddr.sin_addr = addr.req.imr_multiaddr;
	addr.bindaddr.sin_port = port;

	this->addrv.push_back(addr);
}

void Config::add_srcgroupport(const string srcgroupport)
{
	char *endptr;
	long port;
	vector<string> partv;

	boost::split(partv, srcgroupport, boost::is_any_of(":"));

	endptr = NULL;
	port = strtol(partv[2].c_str(), &endptr, 10);
	if (endptr != NULL && *endptr != 0)
	{
		BOOST_THROW_EXCEPTION(InvalidPortException());
	}

	this->add_srcgroupport(partv[0], partv[1], (int)port);
}

}

}

}
