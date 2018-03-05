#include <iostream>
#include <sstream>
#include <string>
#include "Card.h"
#include "IO.h"
#include "Player.h"
#include "MyConsole.h"
#include <thread>

extern Player player;
extern IO io;

using std::string;
extern MyConsole console;
std::string information;
std::string players_name;
bool is_received;
mg_connection *IO::c;
static bool changed = false;
static string msg;
IO::IO()
{
	
}

IO::~IO()
{
	// mg_mgr_free(&manager);
}

void IO::connect()
{
	std::string connection_orders;
	connection_orders += "connect ";
	report_back(connection_orders.c_str());
}
//链接服务端

void IO::tell_names()
{
	report_back(players_name.c_str());
}
//将名字告诉服务端

void IO::set_players_name()
{
	std::cin >> players_name;
}
//输入玩家姓名

std::string IO::accept_information()
{
	is_received = false;
	while (!is_received);
	console.set_text_color(WHITE);
	//std::cout << information;
	return information;
}
static void turn()
{
	std::string command, info = information;
	std::string command_information;
	io.analysis_information(info, command, command_information);

	//std::cout << command << std::endl << command_information << std::endl;

	std::string report = io.action(command, command_information, player);

	io.report_back(report.c_str());

	return;
}
void IO::ev_handler(struct mg_connection *nc, int ev, void *ev_data) {

	struct websocket_message *wm = (struct websocket_message *) ev_data;


	

	switch (ev)
	{

	case MG_EV_CONNECT:

		break;


	case MG_EV_WEBSOCKET_HANDSHAKE_DONE:

		break;


	case MG_EV_POLL:
		if (changed)
		{
			//console.set_background_color(WHITE);
			//std::cout << msg << std::endl;
			mg_send_websocket_frame(nc, WEBSOCKET_OP_TEXT, msg.c_str(), msg.size());
			changed = false;
		}
		break;



	case MG_EV_WEBSOCKET_FRAME:

	{
		//printf("%.*s\n", (int)wm->size, wm->data);
		*((char*)wm->data + wm->size) = '\0';
		information = (const char *)wm->data;

		//std::cout << information;

		std::thread fuck(turn);
		fuck.detach();

		is_received = true;

		break;
	}



	case MG_EV_CLOSE:

		break;


	}

}

void IO::analysis_information(std::string information, std::string &command, std::string &command_information)
{
	command = get_command(information);
	command_information = get_command_information(information);

	return;
}

std::string IO::get_command(std::string information)
{
	std::string command;
	std::stringstream ss(information);
	ss >> command;//////// 注释掉前面的空格
	ss >> command;
	return command;
}

std::string IO::get_command_information(std::string information)
{
	std::string command_information;
	std::stringstream ss(information);
	std::string command;
	ss >> command;
	ss >> command;
	getline(ss, command_information);

	return command_information;
}

std::string IO::action(std::string command, std::string command_information, Player &p)
{
	std::string report = "error";
	std::string nothing;

	if (command == "set_the_hand")
	{
		console.clean_up();
		int id = 0;
		std::stringstream ss(command_information);
		while (ss >> id)
		{
			p.add_hand(id);
		}
		p.sort_hand();
		console.self_flesh(p);
		console.left_flesh(17);
		console.right_flesh(17);
		

		//report = "player set_the_hand yes";
		return report;
	}

	else if (command == "these_are_the_three_cards")
	{
		int id = 0;
		std::stringstream ss(command_information);
		while (ss >> id)
		{
			p.add_hand(id);
		}
		p.sort_hand();
		//console.self_flesh(p);
		//getline(ss, nothing);
		//report = "player these_ard_the_three yes";
		return report;
	}

	else if (command == "you_are_the_one")
	{
		console.self_flesh(p);
		/*
		std::cout << std::endl;
		std::cout << "Do you wanna play the role of landlord?" << std::endl;
		std::cout << "1: Yes!  2: No!  Your answer: ";
		int answer = 0;
		std::cin >> answer;

		std::getline(std::cin, nothing);  //  把换行符读掉
		*/

		bool answer = console.to_be_UI(p);
		if (!answer)
		{
			report = "0";
			p.set_identity(false);
		}
		else
		{
			report = "1";
			p.set_identity(true);
		}

		return report;
	}

	else if (command == "play")
	{
		bool play = console.chupai(p, report);
		//report = play;
		return report;
	}
	else if (command == "pass")
	{
		int turn = 0;
		std::stringstream ss(command_information);
		ss >> turn;

		int people = (turn - p.get_number()) % 3;

		if (people == 2)
		{
			p.add_pass();
			console.draw(36, 2, 43, 4, true);
			console.go_to(39, 3);
			console.set_text_color(WHITE);
			std::cout << "pass";
			console.set_text_color(BLACK);
			Sleep(1000);
			for (int i = 2; i <= 4; ++i)
			{
				console.go_to(36, i);
				std::cout << "        ";
			}
			console.go_to(0, 0);
		}
		else if(people == 1)
		{
			p.add_pass();
			console.draw(106, 2, 113, 4, true);
			console.go_to(109, 3);
			console.set_text_color(WHITE, true);
			std::cout << "pass";
			console.set_text_color(BLACK);
			Sleep(1000);
			for (int i = 2; i <= 4; ++i)
			{
				console.go_to(106, i);
				std::cout << "        ";
			}
			console.go_to(0, 0);
		}
		else
		{
			console.draw(50, 26, 57, 28, true);
			console.go_to(53, 27);
			console.set_text_color(WHITE, true);
			std::cout << "pass";
			console.set_text_color(BLACK);
			console.go_to(0, 0);
			Sleep(1000);
			for (int i = 26; i <= 28; ++i)
			{
				console.go_to(50, 26);
				std::cout << "        ";
			}
		}

		return report;
	}

	else if (command == "show")
	{

		int ca[25] = { 0 };
		std::stringstream ss(command_information);
		int turn = 0;
		ss >> turn;
		int people = (turn - p.get_number()) % 3;

		int num = 0;
		int i = 0;
		int sum = 0;
		while (ss >> num)
		{
			ca[i] = num;
			++sum;
			++i;
		}
		if (people == 1)
		{
			p.set_rightNumber(p.get_rightNumber() - sum);
			console.right_flesh(p.get_rightNumber());
		}
		else
		{
			p.set_leftNumber(p.get_leftNumber() - sum);
			console.left_flesh(p.get_leftNumber());
		}
		for (int j = 0; j != sum; ++j)
		{
			console.show(j + 1, sum, ca[j], true);
		}

		console.self_flesh(p);
		console.right_flesh(p.get_rightNumber());
		console.left_flesh(p.get_leftNumber());

	}
	else if (command == "tell_the_name")
	{
		std::cout << "recev tell";
		//console.set_background_color(GREEN);
		//std::cout << "ok";
		console.startUI(&p, 150, 40,report);
		//std::stringstream ss;
		
		//getline(std::cin, nothing);
		return report;
	}
	else if (command == "sit")
	{
		std::stringstream ss(command_information);
		int num = 0;
		ss >> num;


		p.set_number(num);
		//console.set_background_color(GREEN);
		//std::cout << num << std::endl;
		if (num == 1)
		{
			console.draw_head(3, 27, true);
		}
		else
		{
			console.draw_head(3, 27, false);
		}
		console.write_name(p.get_name(), 3, 35);

		int n;
		ss >> n;
		if ((num == 1 && n == 2) || (num == 2 && n == 3) || (num == 3 && n == 1))
		{
			std::string name;
			ss >> name;
			if(n==1)
			{
				console.draw_head(130, 3, true);
				console.write_name(name, 130, 11);
				p.set_rightNumber(20);
			}
			else
			{
				console.draw_head(130, 3, false);
				console.write_name(name, 130, 11);
				p.set_rightNumber(17);
			}
			ss >> n;
			ss >> name;
			if (n == 1)
			{
				console.draw_head(3, 3, true);
				console.write_name(name, 3, 11);
				p.set_leftNumber(20);
			}
			else
			{
				console.draw_head(3, 3, false);
				console.write_name(name, 3, 11);
				p.set_leftNumber(17);
			}
		}
		else
		{
			std::string name;
			ss >> name;
			if (n == 1)
			{
				console.draw_head(3, 3, true);
				console.write_name(name, 3, 11);
				p.set_leftNumber(20);
			}
			else
			{
				console.draw_head(3, 3, false);
				console.write_name(name, 3, 11);
				p.set_leftNumber(17);
			}
			ss >> n;
			ss >> name;
			if (n == 1)
			{
				console.draw_head(130, 3, true);
				console.write_name(name, 130, 11);
				p.set_rightNumber(20);
			}
			else
			{
				console.draw_head(130, 3, false);
				console.write_name(name, 130, 11);
				p.set_rightNumber(17);
			}
		}
		console.self_flesh(p);
		console.right_flesh(p.get_rightNumber());
		console.left_flesh(p.get_leftNumber());
	}
	else if (command == "success")
	{
		report = "ok";
		return report;
	}

	else if (command == "victory")
	{
		std::stringstream ss(command_information);
		std::string identity;
		std::string name;
		ss >> identity;
		ss >> name;
		console.endUI(p, identity, name);
	}
	return report;
}

void IO::report_back(const char * report)
{
	msg = report;
	changed = true;
	//mg_send_websocket_frame(c, WEBSOCKET_OP_TEXT, report, strlen(report));
	return;
}

void IO::client_turn(Player &p,std::string information)
{
	//std::string information = accept_information();

	std::string command;
	std::string command_information;
	analysis_information(information, command, command_information);

	std::string report = action(command, command_information, p);

	report_back(report.c_str());

	return;
}

