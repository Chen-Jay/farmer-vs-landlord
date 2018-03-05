#pragma once
#include <stdlib.h>
#include <iostream>
#include <sstream>
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

using std::cin;
using std::cout;
using std::endl;
Card allcards[55];
int the_ID_of_the_cards[55];
int the_ID_of_the_three_cards[3];
int the_hands_of_player1[22];
int the_hands_of_player2[22];
int the_hands_of_player3[22];
void Generated_random_number(int random[], int number, int add)  
{
	//srand(unsigned(time(NULL)));
	int x = 1;    //  数组下标
	while (x <= number)
	{ 
	int y = rand() % number + add;    //  生成一个随机数
	for(int r=0; r!=x; ++r)
	{ 	
		if (y == random[r])
		{         //如果数组中已经有这个数就重新生成
		y = 0;
		break; 	
		} 		
	} 		
	if (y != 0)
	{  
		//  如果数组没有这个数则加入到数组中 
		random[x] = y;
		x++; 		
	} 
	}  
	return;
}

//设定牌组的花色
void set_allcards_kind()
{
	for (int i = 1; i <= 54; i++)
	{
		if (i == 53)
		{
			allcards[i].set_huase(kind::king);
		}
		else if (i == 54)
		{
			allcards[i].set_huase(kind::king);
		}
		else if (i % 4 == 1)
		{

			allcards[i].set_huase(kind::diamond);
		}
		else if (i % 4 == 2)
		{
			allcards[i].set_huase(kind::club);
		}
		else if (i % 4 == 3)
		{
			allcards[i].set_huase(kind::heart);
		}
		else if (i % 4 == 0)
		{
			allcards[i].set_huase(kind::spade);
		}
		
		
	}
}

//设定牌组的ID信息
void set_allcards_ID()
{
	for (int i = 1; i <= 54; i++)
	{
		allcards[i].set_ID(i);
	}
}

//设定牌组的打印信息
void set_allcards_print_number()
{
	allcards[1].set_printNumber("1");
	allcards[2].set_printNumber("1");
	allcards[3].set_printNumber("1");
	allcards[4].set_printNumber("1");
	allcards[5].set_printNumber("2");
	allcards[6].set_printNumber("2");
	allcards[7].set_printNumber("2");
	allcards[8].set_printNumber("2");
	allcards[9].set_printNumber("3");
	allcards[10].set_printNumber("3");
	allcards[11].set_printNumber("3");
	allcards[12].set_printNumber("3");
	allcards[13].set_printNumber("4");
	allcards[14].set_printNumber("4");
	allcards[15].set_printNumber("4");
	allcards[16].set_printNumber("4");
	allcards[17].set_printNumber("5");
	allcards[18].set_printNumber("5");
	allcards[19].set_printNumber("5");
	allcards[20].set_printNumber("5");
	allcards[21].set_printNumber("6");
	allcards[22].set_printNumber("6");
	allcards[23].set_printNumber("6");
	allcards[24].set_printNumber("6");
	allcards[25].set_printNumber("7");
	allcards[26].set_printNumber("7");
	allcards[27].set_printNumber("7");
	allcards[28].set_printNumber("7");
	allcards[29].set_printNumber("8");
	allcards[30].set_printNumber("8");
	allcards[31].set_printNumber("8");
	allcards[32].set_printNumber("8");
	allcards[33].set_printNumber("9");
	allcards[34].set_printNumber("9");
	allcards[35].set_printNumber("9");
	allcards[36].set_printNumber("9");
	allcards[37].set_printNumber("10");
	allcards[38].set_printNumber("10");
	allcards[39].set_printNumber("10");
	allcards[40].set_printNumber("10");
	allcards[41].set_printNumber("J");
	allcards[42].set_printNumber("J");
	allcards[43].set_printNumber("J");
	allcards[44].set_printNumber("J");
	allcards[45].set_printNumber("Q");
	allcards[46].set_printNumber("Q");
	allcards[47].set_printNumber("Q");
	allcards[48].set_printNumber("Q");
	allcards[49].set_printNumber("K");
	allcards[50].set_printNumber("K");
	allcards[51].set_printNumber("K");
	allcards[52].set_printNumber("K");
	allcards[53].set_printNumber("Joker");
	allcards[54].set_printNumber("Joker");
}

//设定牌组的数值信息
void set_allcards_number()
{
	for (int i = 1; i <= 52; i++)
	{
		allcards[i].set_number(((i-1) / 4) + 1);
	}
	allcards[53].set_number(14);
	allcards[54].set_number(15);
}
void set_the_three_cards()
{
	the_ID_of_the_three_cards[0] = the_ID_of_the_cards[52];
	the_ID_of_the_three_cards[1] = the_ID_of_the_cards[53];
	the_ID_of_the_three_cards[2] = the_ID_of_the_cards[54];
}


void store_the_hands(int ID_of_the_hands[])
{
	for (int i = 0; i <17; i++)
	{
		the_hands_of_player1[i] = ID_of_the_hands[i + 1];
	}
	for (int i = 0; i < 17; i++)
	{
		the_hands_of_player2[i] = ID_of_the_hands[i + 18];
	}
	for (int i = 0; i < 17; i++)
	{
		the_hands_of_player3[i] = ID_of_the_hands[i + 35];
	}
}

//发牌函数
void distribute_all_the_card()
{
	Generated_random_number(the_ID_of_the_cards, 54, 1);  //洗牌（生成1-54不重复随机的牌的ID）
	in_and_out.set_the_hand(1);
	in_and_out.set_the_hand(2);
	in_and_out.set_the_hand(3);
	set_the_three_cards();
	store_the_hands(the_ID_of_the_cards);
}


//将牌组以xjbxs的方式打印出来
void show_allcards()
{
	cout << "ID      " <<"print_number      "<< "kind     " << "number     "<<endl;
	for(int i = 1; i <= 54; i++)
	{
		cout << allcards[i].get_ID() << "     ";
		cout << allcards[i].get_printNumber() << "      ";
		if (allcards[i].get_huase() == kind::diamond)
		{
			cout << "diamond";
		}
		else if (allcards[i].get_huase() == kind::club)
		{
			cout << "club";
		}
		else if (allcards[i].get_huase() == kind::heart)
		{
			cout << "heart";
		}
		else if (allcards[i].get_huase() == kind::spade)
		{
			cout << "spade";
		}
		else if (allcards[i].get_huase() == kind::king)
		{
			cout << "king";
		}
		cout << "     ";
		cout << allcards[i].get_number();
		cout << endl;
	}
}
//设定整个牌组的信息
void set_allcards()
{
	set_allcards_ID();
	set_allcards_kind();
	set_allcards_number();
	set_allcards_print_number();
}

void show_the_hands(int client)
{
	switch (client)
	{
	case 1:
		for (int i = 0; i < 20; i++)
		{
			cout << the_hands_of_player1[i] << " ";
		}
		cout << endl;
		break;
	case 2:
		for (int i = 0; i < 20; i++)
		{
			cout << the_hands_of_player2[i] << " ";
		}
		cout << endl;
		break;
	case 3:
		for (int i = 0; i < 20; i++)
		{
			cout << the_hands_of_player3[i] << " ";
		}
		cout << endl;
		break;

	}
	
}
