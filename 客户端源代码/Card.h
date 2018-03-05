#pragma once

#include <iostream>
#include <string>

enum class Kind   //  花色
{
	diamond = 1,  //  方块
	club,         //  梅花
	heart,        //  红桃
	spade,        //  黑桃
	joker         //  鬼牌
};

class Card
{
private:
	int          ID;        //  牌的编号（1~54）
	int          value;     //  牌数值（1，2，……，12，13，14（小鬼），15（大鬼））
	int          position;  //  手牌在玩家的hand数组中的位置
	Kind         color;     //  牌面花色
	std::string  huase;     //  打印用的花色
	std::string  number;    //  打印时候牌面值（A，2，……，J,Q,K,JOKER)

public:
	Card();

	void set_ID(int);              //  设置牌编号
	int get_ID();                  //  读取牌编号

	void set_value(int);           //  设置牌数值
	int get_value();               //  读取牌数值

	void set_position(int);        //  写入手牌位置
	int get_position();            //  读取手牌位置

	void set_color(Kind);          //  设置花色
	Kind get_color();              //  读取花色

	void set_huase(std::string);   //  设置打印用的花色
	std::string get_huase();       //  读取打印用的花色

	void set_number(std::string);  //  设置牌面值
	std::string get_number();      //  读取牌面值
};