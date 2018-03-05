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
	void connect();                                                       //  ���ӷ����

	void set_players_name();                                              //�����������

	void tell_names();                                                    //���߷��������

	std::string accept_information();                                     //  �������Է���˵���Ϣ

	void analysis_information(std::string, std::string &, std::string &); //  ������Է���˵���Ϣ

	std::string get_command(std::string);                                 //  ��ȡ����˵�����

	std::string get_command_information(std::string);                     //  ��ȡ�������������

	std::string action(std::string, std::string, Player &);               //  �ͻ���ִ�з���˵�����

	void report_back(const char *);                                        //  �ͻ��˻ظ������

	void client_turn(Player &, std::string);                              //  �ͻ��˻غ��ж�
};


//static void broadcast(struct mg_connection *nc, const struct mg_str msg);
