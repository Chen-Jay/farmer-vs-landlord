#include <iostream>
#include <string>
#include "Card.h"

Card::Card()
{
	set_ID(100);               //  初始化牌编号为0
	set_value(0);              //  初始化牌数值为0
	set_position(0);           //  初始化位置为0
	set_color(Kind::diamond);  //  初始化为方块
	set_huase("方");           //  初始化为方块
	set_number("0");           //  初始化牌面值为0
}

void Card::set_ID(int i)
{
	ID = i;
	return;
}
int Card::get_ID()
{
	return ID;
}

void Card::set_value(int v)
{
	value = v;
	return;
}
int Card::get_value()
{
	return value;
}

void Card::set_position(int p)
{
	position = p;
	return;
}
int Card::get_position()
{
	return position;
}

void Card::set_color(Kind c)
{
	color = c;
	return;
}
Kind Card::get_color()
{
	return color;
}

void Card::set_huase(std::string h)
{
	huase = h;
	return;
}
std::string Card::get_huase()
{
	return huase;
}

void Card::set_number(std::string n)
{
	number = n;
	return;
}
std::string Card::get_number()
{
	return number;
}