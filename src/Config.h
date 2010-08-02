/*
 * Config.h
 *
 *  Created on: Jul 29, 2010
 *      Author: james.cape
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <vector>
#include <map>
#include <netinet/in.h>
#include <net/if.h>

namespace com {

namespace ntkn {

namespace seshat {

typedef struct _group_listen_address group_listen_address;

struct _group_listen_address {
	struct sockaddr_in bindaddr;
	struct ip_mreqn req;
};

class Config {
public:
	Config();
	virtual ~Config();

	void parse_argv(int argc, char *argv[]);
	void add_srcgroupport(const std::string srcgroupport);
	void add_srcgroupport(const std::string src, const std::string group, int port);

	void _init_if_list();

	std::vector <group_listen_address> addrv;

	std::string db_host;
	std::string db_username;
	std::string db_password;

	std::string log4cpp_filename;

	std::vector <struct sockaddr_in> _if_list;
};

}

}

}

#endif /* CONFIG_H_ */
