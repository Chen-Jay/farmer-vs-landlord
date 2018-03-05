#include <iostream>
#include <ctime>
#include <sstream>
using std::stringstream;
#include <cstring>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::fstream;
#include <string>
using std::string;
#define _CRT_SECURE_NO_WARNINGS
#include "Card.h"

#include "Player.h"
#include "distribute_the_card.h"
#include "the_presettings.h"
#include "IO.h"
#include "choose_the_one.h"
#include "playing_the_cards.h"

mg_connection* conns[4] = {nullptr};

IO::IO()
{
	mg_mgr_init(&manager, NULL);
	c = mg_bind(&manager, "6666", IO::eventhandler);
	mg_set_protocol_http_websocket(c);
}
void IO::run()
{
	std::cout << "start polling" << std::endl;
	for( ; ;)
		mg_mgr_poll(&manager, 200);
}
IO::~IO()
{
	mg_mgr_free(&manager);
}

static void broadcast(struct mg_connection *nc, const struct mg_str msg)
{
	struct mg_connection *c;
	char buf[500];
	char addr[32];
	mg_sock_addr_to_str(&nc->sa, addr, sizeof(addr),
		MG_SOCK_STRINGIFY_IP | MG_SOCK_STRINGIFY_PORT);
#ifndef WIN32
	snprintf(buf, sizeof(buf), "%s %.*s", addr, (int)msg.len, msg.p);
#else
	_snprintf_s(buf, sizeof(buf), "%s %.*s", addr, (int)msg.len, msg.p);
#endif
	printf("%s\n", buf); /* Local echo. */
	mg_send_websocket_frame(nc, WEBSOCKET_OP_TEXT, buf, strlen(buf));
}

/*************************************************************待处理**********************************************************************/
void IO::eventhandler(mg_connection *c, int event, void *ev_data) 
{
	websocket_message *wm;
	// std::cout << "evdata: " << ev_data << std::endl;
	switch (event)
	{
		case MG_EV_WEBSOCKET_HANDSHAKE_DONE:
			std::cout << "handshake done" << std::endl; 
			break;
		case MG_EV_WEBSOCKET_FRAME:
			wm = (websocket_message*)ev_data;
			wm->data[wm->size] = '\0';
			shared = (char*)(wm->data);
			std::cout << "received: " << shared << std::endl;
			if (shared[0] == 'c' && shared[1] == 'o')				// protocal => connect
			{
				std::cout << "connected" << std::endl;
				for (int i = 1; i <= 3; ++i)
				{
					if (conns[i] == nullptr)
					{
						conns[i] = c;
						//broadcast(c, mg_str{ "set_the_hand 1 2 3 4", 20 });
						break;
					}
				}
			}
			else if (shared[0] == 'e'&&shared[1] == 'r'&&shared[2] == 'r')
			{
				break;
			}

			else
				is_received = true;
			break;
		case MG_EV_CLOSE:
		default:;
	}
}
/*********************************************************************************************************************************************************/

void IO::set_the_hand(int client)
{
	string cache;

	int start;
	int end;
	switch (client)
	{
	case 1:
		start = 1;
		end = 17;
		break;
	case 2:
		start = 18;
		end = 34;
		break;
	case 3:
		start = 35;
		end = 51;
		break;
	}

	cache = "set_the_hand ";
	for (int i = start; i <= end; i++)
	{
		std::stringstream ss;
		ss << the_ID_of_the_cards[i];
		cache += ss.str() += ' ';
	}
	write(client, cache.c_str());
}

int IO::you_are_the_one(int clientx)
{
	cout << "进入了you_are_the_one" << endl;
	int the_one;
	if (clientx == 0)
	{
		the_one = rand()%3+1;
	}
	else
	{
		the_one = clientx;
	}
	cout << "下一个玩家是： " << the_one;
	string cache;
	cache = "you_are_the_one";
	write(the_one, cache.c_str());
	cout << "已发送地主请求---->"<< the_one << endl;
	return the_one;
}

void IO::these_are_the_three_cards(int client)
{
	string cache;
	cache = "these_are_the_three_cards";
	cache += ' ';
	stringstream ss;
	for (int i = 0; i <= 2; i++)
	{
		ss << the_ID_of_the_three_cards[i];
		cache += ss.str() += ' ';
		ss.str("");
	}
	write(client, cache.c_str());
}

void IO::you_are_the_farmer(int client)
{
	string cache;
	cache = "farmer";
	write(client, cache.c_str());
}

void IO::you_are_the_landlord(int client)
{
	string cache;
	cache = "landlord";
	write(client, cache.c_str());
}

void IO::it_is_your_turn(int client)
{
	string cache;
	cache = "play";
	in_and_out.write(client, cache.c_str());
}

void IO::cards_to_play(int server, string cards)
{
	string cache;
	cache = "1 "; 
	cache += cards;
	write(server, cache.c_str());
}

void IO::tell_me_your_name(int server)
{
	string cache = "tell_the_name";
	write(server, cache.c_str());
}

void IO::write(int dest, const char * str)
{
	broadcast(conns[dest], mg_str{ str, strlen(str) });
}

string IO::read()
{
	/*string cache;
	while (1)
	{
		
		if (the_server_file.peek()==EOF)
		{
			the_server_file.clear();
			
		}
		else
		{
			getline(the_server_file, cache);
			break;
		}
	}
	the_server_file.close();
	the_server_file.open(the_servers_files_name,  std::ios::out);
	the_server_file.close();
	the_server_file.open(the_servers_files_name, std::ios::in);
	
	
	return cache;*/
	is_received = false;
	while (!is_received);
	return shared;
}

string IO::read_a_word(string &the_orders_without_the_first_word)
{
	string cache;
	stringstream ss;
	cache = in_and_out.read();
	ss << cache;
	//cout << "read函数read到了： " << cache << endl;
	string the_word;
	ss >> the_word;
	/*int the_begin_of_the_contents;
	for (int i = 0; cache[i] != ' '; i++)
	{
		the_word[i] = cache[i];
		the_begin_of_the_contents = i + 2;
	}
	cout << "已经将第一个有效单词读取" << endl;
	int n = 0;
	for (int i = the_begin_of_the_contents; cache[i] != '\0'; i++)
	{
		the_orders_without_the_first_word[n] = cache[i];
		n++;
	}*/
	string zhongzhuan;
	while (ss >> zhongzhuan)
	{
		the_orders_without_the_first_word += zhongzhuan += " ";
	}
	//cout << "read_a-word over" << endl;
	return the_word;
	
}

void IO::cards_to_show(int client,string cards)
{
	string cache;
	stringstream ss;
	ss << number_of_rounds;
	string rounds_number;
	 ss>>rounds_number;
	
	cache = "show ";
	cache += rounds_number+=" ";
	cache += cards;
	write(client, cache.c_str());
}

void IO::these_are_your_seat_information(int bianhao, int duiyingdewanjia)
{
	string information;
	information += "sit ";
	//当前玩家编号
	{
		if (bianhao == 1)
		{
			Sleep(1000);
			information += "1 ";
		}
		else if (bianhao == 2)
		{
			information += "2 ";
		}
		else if (bianhao == 3)
		{
			information += "3 ";
		}
	}

	//下家编号
	switch ((bianhao % 3) + 1)
	{
	case 1:
		information += "1 ";
		break;
	case 2:
		information += "2 ";
		break;
	case 3:
		information += "3 ";
		break;
	}

	//下家名字
	switch ((duiyingdewanjia%3)+ 1)
	{
	case 1:
		information += name_of_player1+=" ";
		break;
	case 2:
		information += name_of_player2+=" ";
		break;
	case 3:
		information += name_of_player3+=" ";
		break;
	}

	//下下家编号
	switch (((bianhao + 1) % 3) + 1)
	{
	case 1:
		information += "1 ";
		break;
	case 2:
		information += "2 ";
		break;
	case 3:
		information += "3 ";
		break;
	}

	//下下家名字
	switch (((duiyingdewanjia +1) %3) +1)
	{
	case 1:
		information += name_of_player1 += " ";
		break;
	case 2:
		information += name_of_player2 += " ";
		break;
	case 3:
		information += name_of_player3 += " ";
		break;
	}

	in_and_out.write(duiyingdewanjia, information.c_str());
}

void IO::show_pass(int client)
{
	string info;
	string cache;
	info = "pass ";
	stringstream ss;
	ss << number_of_rounds;
	getline(ss, cache);
	info += cache;
	write(client, info.c_str());
}

void IO::show_farmer_victory(int win_farmer)
{
	string info;
	info = "victory ";
	info += "farmer ";
	if (win_farmer == 1)
	{
		info += name_of_player1;
	}
	else if (win_farmer == 2)
	{
		info += name_of_player2;
	}
	else if(win_farmer == 3)
	{
		info += name_of_player3;
	}
	for (int i = 1; i <= 3; i++)
	{
		write(i, info.c_str());
	}
	
}
void IO::show_landlord_victory(int landlord)
{
	string info;
	info = "victory ";
	info += "landlord ";
	switch (nb_of_1)
	{
	case 1:
		info += name_of_player1;
		break;
	case 2:
		info += name_of_player2;
		break;
	case 3:
		info += name_of_player3;
		break;
	}
	for (int i = 1; i <= 3; i++)
	{
		write(i, info.c_str());
	}
	
}