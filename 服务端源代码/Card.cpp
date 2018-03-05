#include<iostream>
#include "Card.h"
#include "Player.h"
#include "the_presettings.h"
Card::Card()
{
    set_ID(0);
    set_number(0);
    set_printNumber("0");
    set_huase(kind::diamond);
}
void Card::set_ID(int id)
{
    ID=id;
    return;
}
int Card::get_ID()
{
    return ID;
}
void Card::set_number(int num)
{
    number=num;
    return;
}
int Card::get_number()
{
    return number;
}
void Card::set_printNumber(std::string num)
{
    printNumber=num;
    return;
}
std::string Card::get_printNumber()
{
    return printNumber;
}
void Card::set_huase(kind se)
{
    huase=se;
    return;
}
kind Card::get_huase()
{
    return huase;
}
