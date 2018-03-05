// doudizhu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <string>
#include <sstream>
#include "Player.h"
#include "Card.h"
#include "IO.h"
#include "MyConsole.h"
#include "READ_ID.h"
#include <windows.h>
#include <thread>

const int len = 150;
const int wid = 40;

MyConsole console;
IO io;
Player player;
std::string IP_;

static void poll()
{
	mg_mgr_init(&io.manager, NULL);
	io.c = mg_connect_ws(&io.manager, io.ev_handler, IP_.c_str(), "client", NULL);
	//std::cout << io.c;
	for (; ;)
		mg_mgr_poll(&io.manager, 50);
}
int main(int argc, char **argv)
{
	if (argc > 1) {
		The_IP_file = fstream(argv[1], std::ios::in);
	}
	IP_ = Read_ID();



	std::thread network(poll);
	
	//  设置屏幕大小
	console.set_size(len, wid);

	std::string back = "connect";
	io.report_back(back.c_str());
	
	network.join();
    return 0;
}

