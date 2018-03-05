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
#include "the_presettings.h"
#include "IO.h"
#include "choose_the_one.h"
#include "playing_the_cards.h"
#include "distribute_the_card.h"

bool victory = false;
int number_of_rounds=1;

int in_the_first_turn()
{   
	
	int next_player=to_know_the_next_one_to_choose(the_landlord);
	/*switch (the_landlord)
	{
	case 1:
		the_hands_pointer = &(the_hands_of_player1[0]);
		break;
	case 2:
		the_hands_pointer = &(the_hands_of_player2[0]);
		break;
	case 3:
		the_hands_pointer = &(the_hands_of_player3[0]);
		break;
	}*/
	
	in_and_out.it_is_your_turn(the_landlord);
	cout << "�Ѿ������˵������" << endl;
	show_the_hands(the_landlord);
	string cache;
	string the_rest_orders;
	stringstream ss;
	cache = in_and_out.read_a_word(the_rest_orders);
	
	ss << cache;
	int order;
	ss >> order;
	ss.str("");
	if (order == 0)
	{
		return next_player;
	}
	//ȷ�ϳ��ƺ�ִ�����²���
	else
	{
		cache = the_rest_orders;
		//cout << "���µ��ַ����� " << cache << endl;
		//��������������ҳ���ʲô��
		for (int i = 1; i <= 3; i++)
		{
			if (i != the_landlord)
			{
				in_and_out.cards_to_show(i, cache);
			}
		}	
		Sleep(1000);
		stringstream ss2;
		ss2<< cache;
		int the_card;

		//���������ڶ�Ӧ�������������
		//cout << "start to judge" << endl;
		while (ss2 >> the_card)
		{
			//cout << "the_card is: " << the_card<<"       ";
			switch (the_landlord)
			{
			case 1:
				for (int i = 0; i < 25; i++)
				{
					if (the_hands_of_player1[i] == the_card)
					{
						the_hands_of_player1[i] = 0;
						//cout << "the " << the_hands_of_player1[i] << " card is become 0"<<endl;
						break;
					}
				}
				break;
			case 2:
				for (int i = 0; i < 25; i++)
				{
					if (the_hands_of_player2[i] == the_card)
					{
						the_hands_of_player2[i] = 0;
						//cout << "the " << the_hands_of_player2[i] << " card is become 0"<<endl;
						break;
					}
				}
				break;
			case 3:
				for (int i = 0; i < 25; i++)
				{
					if (the_hands_of_player3[i] == the_card)
					{
						the_hands_of_player3[i] = 0;
						//cout << "the " << the_hands_of_player3[i] << " card is become 0" << endl;
						break;
					}
				}
				break;
			}
		}

		//�ж��Ƿ�����һ�ʤ
		int if_win = 0;
		switch (the_landlord)
		{
		case 1:
			for (int i = 0; i < 21; i++)
			{
				if (the_hands_of_player1[i] != 0)
				{
					cout << "player1 don't win" << endl;
					if_win++;
					break;
				}
			}
			break;
		case 2:
			for (int i = 0; i < 21; i++)
			{
				if (the_hands_of_player2[i] != 0)
				{
					cout << "player2 don't win" << endl;
					if_win++;
					break;
				}
			}
			break;
		case 3:
			for (int i = 0; i < 21; i++)
			{
				if (the_hands_of_player3[i] != 0)
				{
					cout << "player3 don't win" << endl;
					if_win++;
					break;
				}
			}
			break;
		}
		if (if_win == 0)
		{
			victory = true;
			cout << "the landlord win" << endl;
		}

		return next_player;
	}

}


int in_one_turn(int now)
{
	show_the_hands(now);
	int next_player = to_know_the_next_one_to_choose(now);
	/*int(*the_hands_pointer);
	  switch (now)
	{
	case 1:
		the_hands_pointer = &(the_hands_of_player1[0]);
		break;
	case 2:
		the_hands_pointer = &(the_hands_of_player2[0]);
		break;
	case 3:
		the_hands_pointer = &(the_hands_of_player3[0]);
		break;
	}*/
	//���Ӧ����ҷ��͡�������Ļغϡ�
	in_and_out.it_is_your_turn(now);
	Sleep(1000);

	//��ȡ�Ƿ���Ƶ���Ϣ��1��0��
	stringstream ss;
	string the_rest_orders;
	string &the_rest = the_rest_orders;
	ss << in_and_out.read_a_word(the_rest);
	int order;
	ss >> order;
	ss.str("");

	if (order == 0)
	{
		for(int i = 1; i <= 3; i++)
		{
				in_and_out.show_pass(i);
		}
		Sleep(1000);
		return next_player;
	}

	//��ѡ�������ִ�����²���
	else
	{
		//��������������ҳ�����
		string cache = the_rest_orders;
		for (int i = 1; i <= 3; i++)
		{
			if (i != now)
			{
				in_and_out.cards_to_show(i, cache);
			}
			
		}
		Sleep(1000);
		stringstream ss2;
		ss2 << cache;
		int the_card;

		//���������ڶ�Ӧ���������������
		while (ss2 >> the_card)
		{
			//cout << "the_card is: " << the_card << "       ";
			switch (now)
			{
			case 1:
				for (int i = 0; i < 21; i++)
				{
					if (the_hands_of_player1[i] == the_card)
					{
						//cout << "the " << the_hands_of_player1[i] << " card is become 0" << endl;
						the_hands_of_player1[i] = 0;
						break;
					}
					
				}
				break;
			case 2:
				for (int i = 0; i < 21; i++)
				{
					if (the_hands_of_player2[i] == the_card)
					{
					//	cout << "the " << the_hands_of_player2[i] << " card is become 0" << endl;
						the_hands_of_player2[i] = 0;
						break;
					}
				}
				break;
			case 3:
				for (int i = 0; i < 21; i++)
				{
					if (the_hands_of_player3[i] == the_card)
					{
						the_hands_of_player3[i] = 0;
					//	cout << "the " << the_hands_of_player1[i] << " card is become 0" << endl;
						break;
					}
					
				}
				break;
			}
		}

		//�ж��Ƿ������ʤ��
		int if_win=0;
		switch (now)
		{
		case 1:
			for (int i = 0; i < 21; i++)
			{
				if (the_hands_of_player1[i] != 0)
				{
					cout << "player1 don't win" << endl;
					if_win++;
					break;
				}
				
			}
			break;
		case 2:
			for (int i = 0; i < 21; i++)
			{
				if (the_hands_of_player2[i] != 0)
				{
					cout << "player2 don't win" << endl;
					if_win++;
					break;
				}
				
			}
			break;
		case 3:
			for (int i = 0; i < 21; i++)
			{
				if (the_hands_of_player3[i] !=0)
				{
					cout << "player3 don't win" << endl;
					if_win++;
					break;
				}
				
			}
			break;
		}
		if (if_win == 0)
		{
			victory = true;
			cout << "the " << now << " player wins" << endl;
			if (now == nb_of_1)
			{
				in_and_out.show_landlord_victory(now);
			}
			else
			{
				in_and_out.show_farmer_victory(now);
			}
		
		}
		
		return next_player;
	}

}


void playing_cards()
{
	
	int next_player = in_the_first_turn();
	number_of_rounds++;
	while (victory==false)
	{
		int nex;
		nex= in_one_turn(next_player);
		next_player = nex;
		number_of_rounds++;
		cout << "�������" << endl;
	}

	/*int count1 = 0;
	int next_player = in_the_first_turn();
	while (count1 <= 10)
	{
		next_player = in_one_turn(next_player);
		count1++;
		string play="";
		stringstream ss;
		for (int i = 0; i < 10; i++)
		{
			int ID=rand()%54+1;
			ss << ID;
			play += ss.str();
			play += " ";
			ss.str("");
		}
		in_and_out.cards_to_play(0, play);
		cout << "�������" << endl;
		system("pause");
	}*/
	
	cout << "���ƽ���" << endl;
	

}