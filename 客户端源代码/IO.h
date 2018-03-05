#pragma once

#include<iostream>
#include <sstream>
#include <string>
#include "Card.h"
#include "Player.h"
#include "mongoose.h"
#include "MyConsole.h"

extern std::string information;
extern std::string players_name;
extern bool is_received;

class IO
{
public:
	static mg_connection *c;
	static void ev_handler(mg_connection *c, int event, void *ev_data);
public:
	IO();
	~IO();
	mg_mgr manager;
	void connect();                                                       //  链接服务端

	void set_players_name();                                              //设置玩家姓名

	void tell_names();                                                    //告诉服务端姓名

	std::string accept_information();                                     //  接收来自服务端的信息

	void analysis_information(std::string, std::string &, std::string &); //  解读来自服务端的信息

	std::string get_command(std::string);                                 //  获取服务端的命令

	std::string get_command_information(std::string);                     //  获取服务端命令内容

	std::string action(std::string, std::string, Player &);               //  客户端执行服务端的命令

	void report_back(const char *);                                        //  客户端回复服务端

	void client_turn(Player &, std::string);                              //  客户端回合行动
};


//static void broadcast(struct mg_connection *nc, const struct mg_str msg);
