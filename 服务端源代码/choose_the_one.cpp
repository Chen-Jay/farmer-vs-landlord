#include <iostream>
#include <ctime>

#include <sstream>
using std::stringstream;
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::fstream;
#include <string>
using std::string;

#include "Card.h"
#include "Player.h"
#include "distribute_the_card.h"
#include "the_presettings.h"
#include "IO.h"
#include "choose_the_one.h"
int nb_of_1;
int nb_of_2;
int nb_of_3;

int the_landlord;
bool choose_the_one() //选择地主，同时返回是否选择成功
{
	int the_one;
	the_one=in_and_out.you_are_the_one(0);//向第一个候选人发出信息,同时得到当前候选人编号。
	//the_one = 1;
	cout << "已经向地主发出请求" << "地主是" << the_one << endl;
	int count = 0;
	while (1)
	{
		int huan;
		huan=communicate_with_the_client(the_one);
		if (huan==1)
		{
			count++;
			cout << "玩家愿意做地主" << endl;
			return true;

		}
		else if(huan==0)
		{
			//cout << "communicate with the one is false" << endl;
			count++;
			if (count == 3)
			{
				count = 0;
				return false;
			}
			cout <<the_one<< "号玩家不愿意做地主" << endl;
			the_one = to_know_the_next_one_to_choose(the_one);
			in_and_out.you_are_the_one(the_one);
		}
	}
}


bool communicate_with_the_client(int the_one)  //与地主候选人交流
{
	stringstream ss;
	bool if_be = false;
	int the_number;
	ss<<in_and_out.read();
	ss >> the_number;
	//cout << "the_number is:" << the_number << endl;
	ss.str("");
	//cout << "the_number_to choose the one is :" << the_number << endl;
	if (the_number == 0)
	{
		if_be = false;
	}
	else if (the_number == 1)
	{
		if_be = true;
	}
	
	//cout << "if_be is： " << if_be << endl;
	if (if_be == true)
	{
		
		the_landlord = the_one;
		for (int i = 1; i <= 3; i++)
		{
			if (i == the_one)
			{
				if (i == 1)
				{
					nb_of_1 = 1;
				}
				if (i == 2)
				{
					nb_of_1 = 2;
				}
				if (i == 3)
				{
					nb_of_1 = 3;
				}
			}
			//地主编号设置为1
			else if (i == (the_one % 3) + 1)
			{
				if (i == 1)
				{
					nb_of_2 = 1;
				}
				else if (i == 2)
				{
					nb_of_2 = 2;
				}
				else if (i == 3)
				{
					nb_of_2 = 3;
				}
			}
			//地主下家设置为2
			else if (i == ((the_one+1) % 3) + 1)
			{
				if (i == 1)
				{
					nb_of_3 = 1;
				}
				else if (i == 2)
				{
					nb_of_3 = 2;
				}
				else if (i == 3)
				{
					nb_of_3 = 3;
				}
			}
			//设置第三只玩家编号
		}
		in_and_out.these_are_the_three_cards(the_one);
		//将三张地主牌写入本地地主手牌
		switch (the_one)
		{
		case 1:
			the_hands_of_player1[17] = the_ID_of_the_three_cards[0];
			the_hands_of_player1[18] = the_ID_of_the_three_cards[1];
			the_hands_of_player1[19] = the_ID_of_the_three_cards[2];
			break;
		case 2:
			the_hands_of_player2[17] = the_ID_of_the_three_cards[0];
			the_hands_of_player2[18] = the_ID_of_the_three_cards[1];
			the_hands_of_player2[19] = the_ID_of_the_three_cards[2];
			break;
		case 3:
			the_hands_of_player3[17] = the_ID_of_the_three_cards[0];
			the_hands_of_player3[18] = the_ID_of_the_three_cards[1];
			the_hands_of_player3[19] = the_ID_of_the_three_cards[2];
			break;
		}
		
		/*for (int i = 1; i <=3; i++)
		{
			if (i != the_one)
			{
				in_and_out.you_are_the_farmer(i);
			}
			else
			{
				in_and_out.you_are_the_landlord(i);
			}
		}*/
		in_and_out.these_are_your_seat_information(1, nb_of_1);
		in_and_out.these_are_your_seat_information(2, nb_of_2);
		in_and_out.these_are_your_seat_information(3, nb_of_3);
		return true;
	}
	else
	{
		//cout << "it will return false" << endl;
		return false;
	}
	
}
