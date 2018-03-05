#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Card.h"
#include "Player.h"
#include "distribute_the_card.h"
#include "the_presettings.h"
#include "IO.h"
#include <fstream>
using std::fstream;
#include <string>
using std::string;
#include <vector>
using std::vector;

using std::cin;
using std::cout;
using std::endl;
extern mg_connection* conns[4];
 
IO in_and_out;
string shared;
bool is_received;
string name_of_player1;
string name_of_player2;
string name_of_player3;

/*
void show_orders()
{
	string cache;
	char a[25];
	for (int i = 0; i < 17; i++)
	{
		the_client1_file>>a[i];
	}
	for (int i = 0; i < 17; i++)
	{
		cout << a[i] ;
	}
}
*/
int to_know_the_next_one_to_choose(int now)
{
	if (now == 1)
	{
		return 2;
	}
	else if (now == 2)
	{
		return 3;
	}
	else if (now == 3)
	{
		return 1;
	}
}

void the_presettings()
{
	std::cout << "pres" << std::endl;
	while (conns[1] == nullptr || conns[2] == nullptr || conns[3] == nullptr)
	{
		;
	}
	
		for (int i = 1; i <= 3; i++)
		{
			in_and_out.tell_me_your_name(i);
			string name = in_and_out.read();
			if (i == 1)
			{
				name_of_player1 = name;
			}
			else if (i == 2)
			{
				name_of_player2 = name;
			}
			else if (i == 3)
			{
				name_of_player3 = name;
			}
		}
	//将玩家姓名对应
}