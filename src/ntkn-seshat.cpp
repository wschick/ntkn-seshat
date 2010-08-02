/*
 ============================================================================
 Name        : ntkn-seshat.cpp
 Author      : James Cape <james.cape@ntkn.com>
 Version     :
 Copyright   : Copyright 2010 Need To Know News, LLC
 Description : Listens for AlphaFlash multicast packets, records the full
			   IP packet to a Cassandra Database.
 ============================================================================
 */

#include <Config.h>
#include <Database.h>

using namespace std;
using namespace com::ntkn::seshat;

int main(int argc, char *argv[])
{
	Config cfg;
	Database db;

	// log4cpp singletons are initalized within. Blech.
	cfg.parse_argv(argc, argv);

	// Threaded
	db.connect(cfg.db_host, cfg.db_username, cfg.db_password);

	return 0;
}
