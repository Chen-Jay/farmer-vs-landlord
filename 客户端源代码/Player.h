#pragma once

#include <iostream>
#include <string>
#include "Card.h"

class Player
{
private:
	std::string  name;        //  玩家昵称
	bool         identity;    //  玩家身份（true是地主，false是平民）
	bool         turn;        //  判断当前是否是自己的回合
	bool         victory;     //  判断是否胜利（true胜利）
	Card         hand[21];    //  手牌
	int          number;      //  游戏编号
	int          pass;        //  记录pass了多少回合，再次轮到自己的时候是否一定要出牌
	int          cardNumber;  //  剩余手牌数
	int          leftNumber;  //  左边玩家手牌数
	int          rightNumber; //  右边玩家手牌数

public:
	Player();

	void set_name(std::string);  //  设置玩家昵称
	std::string get_name();      //  读取玩家昵称

	void set_identity(bool);     //  设置玩家身份
	bool get_identity();         //  读取玩家身份

	void set_turn(bool);         //  设置玩家回合状态
	bool get_turn();             //  获取玩家回合状态
	void change_turn();          //  改变玩家回合状态

	void set_victory(bool);      //  设置玩家状态
	bool get_victory();          //  读取玩家状态
	void change_victory();       //  更改玩家状态

	void add_hand(int);          //  加入手牌
	void sort_hand();            //  整理手牌
	void show_hand(int);         //  展示单张手牌
	void show_all_hand();        //  展示所有手牌
	int get_hand_ID(int);        //  获取手牌的ID
	void play_hand(int);         //  出牌
	int get_value(int);          //  获取手牌值

	void set_number(int);        //  设置游戏编号
	int get_number();            //  读取游戏编号

	void set_pass(int);          //  设置pass回合数
	void add_pass();             //  增加一次pass数
	int get_pass();              //  读取pass回合数

	void set_cardNumber(int);    //  设置手牌数量
	int get_cardNumber();        //  读取手牌数量

	void set_leftNumber(int);    //  设置左边玩家手牌数
	int get_leftNumber();        //  获取左边玩家手牌数

	void set_rightNumber(int);   //  设置右边玩家手牌数
	int get_rightNumber();       //  获取右边玩家手牌数
};