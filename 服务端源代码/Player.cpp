#include<iostream>
#include<string>
#include "Player.h"
#include "Card.h"
#include "the_presettings.h"

Player::Player()
{
    set_name("none");
    set_ID("000000");
    set_restCardNumber(0);
    set_victoryOrNot(false);
    set_landLord(false);
}
void Player::set_name(std::string n)
{
    name=n;
    return;
}
std::string Player::get_name()
{
    return name;
}
void Player::set_ID(std::string id)
{
    ID=id;
    return;
}
std::string Player::get_ID()
{
    return ID;
}
void Player::set_restCardNumber(int number)
{
    restCardNumber=number;
    return;
}
int Player::get_restCardNumber()
{
    return restCardNumber;
}
void Player::set_victoryOrNot(bool v)
{
    victoryOrNot=v;
    return;
}
bool Player::get_victoryOrNot()
{
    return victoryOrNot;
}
void Player::change_state()
{
    victoryOrNot=!victoryOrNot;
    return;
}
void Player::set_landLord(bool l)
{
    landLord=l;
    return;
}
bool Player::get_landLord()
{
    return landLord;
}
