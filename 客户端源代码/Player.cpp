#include <iostream>
#include <string>
#include "Card.h"
#include "Player.h"

Player::Player()
{
	bool state = false;
	set_name("none");
	set_identity(state);
	set_turn(false);
	set_victory(state);
	set_number(0);
	set_number(0);
	set_cardNumber(0);
	set_leftNumber(17);
	set_rightNumber(17);
}

void Player::set_name(std::string n)
{
	name = n;
	return;
}
std::string Player::get_name()
{
	return name;
}

void Player::set_identity(bool i)
{
	identity = i;
	return;
}
bool Player::get_identity()
{
	return identity;
}

void Player::set_turn(bool t)
{
	turn = t;
	return;
}
bool Player::get_turn()
{
	return turn;
}
void Player::change_turn()
{
	turn = !turn;
	return;
}

void Player::set_victory(bool v)
{
	victory = v;
	return;
}
bool Player::get_victory()
{
	return victory;
}
void Player::change_victory()
{
	victory = !victory;
	return;
}

void Player::add_hand(int id)
{
	int num = get_cardNumber() + 1;
	switch (id)
	{
	case 0:
	{
		hand[num].set_ID(100);
		hand[num].set_value(0);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("0");
		break;
	}
	case 1:
	{
		hand[num].set_ID(1);
		hand[num].set_value(1);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("A");
		break;
	}
	case 2:
	{
		hand[num].set_ID(2);
		hand[num].set_value(1);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("A");
		break;
	}
	case 3:
	{
		hand[num].set_ID(3);
		hand[num].set_value(1);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("A");
		break;
	}
	case 4:
	{
		hand[num].set_ID(4);
		hand[num].set_value(1);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("A");
		break;
	}
	case 5:
	{
		hand[num].set_ID(5);
		hand[num].set_value(2);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("2");
		break;
	}
	case 6:
	{
		hand[num].set_ID(6);
		hand[num].set_value(2);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("2");
		break;
	}
	case 7:
	{
		hand[num].set_ID(7);
		hand[num].set_value(2);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("2");
		break;
	}
	case 8:
	{
		hand[num].set_ID(8);
		hand[num].set_value(2);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("2");
		break;
	}
	case 9:
	{
		hand[num].set_ID(9);
		hand[num].set_value(3);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("3");
		break;
	}
	case 10:
	{
		hand[num].set_ID(10);
		hand[num].set_value(3);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("3");
		break;
	}
	case 11:
	{
		hand[num].set_ID(11);
		hand[num].set_value(3);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("3");
		break;
	}
	case 12:
	{
		hand[num].set_ID(12);
		hand[num].set_value(3);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("3");
		break;
	}
	case 13:
	{
		hand[num].set_ID(13);
		hand[num].set_value(4);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("4");
		break;
	}
	case 14:
	{
		hand[num].set_ID(14);
		hand[num].set_value(4);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("4");
		break;
	}
	case 15:
	{
		hand[num].set_ID(15);
		hand[num].set_value(4);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("4");
		break;
	}
	case 16:
	{
		hand[num].set_ID(16);
		hand[num].set_value(4);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("4");
		break;
	}
	case 17:
	{
		hand[num].set_ID(17);
		hand[num].set_value(5);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("5");
		break;
	}
	case 18:
	{
		hand[num].set_ID(18);
		hand[num].set_value(5);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("5");
		break;
	}
	case 19:
	{
		hand[num].set_ID(19);
		hand[num].set_value(5);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("5");
		break;
	}
	case 20:
	{
		hand[num].set_ID(20);
		hand[num].set_value(5);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("5");
		break;
	}
	case 21:
	{
		hand[num].set_ID(21);
		hand[num].set_value(6);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("6");
		break;
	}
	case 22:
	{
		hand[num].set_ID(22);
		hand[num].set_value(6);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("6");
		break;
	}
	case 23:
	{
		hand[num].set_ID(23);
		hand[num].set_value(6);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("6");
		break;
	}
	case 24:
	{
		hand[num].set_ID(24);
		hand[num].set_value(6);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("6");
		break;
	}
	case 25:
	{
		hand[num].set_ID(25);
		hand[num].set_value(7);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("7");
		break;
	}
	case 26:
	{
		hand[num].set_ID(26);
		hand[num].set_value(7);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("7");
		break;
	}
	case 27:
	{
		hand[num].set_ID(27);
		hand[num].set_value(7);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("7");
		break;
	}
	case 28:
	{
		hand[num].set_ID(28);
		hand[num].set_value(7);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("7");
		break;
	}
	case 29:
	{
		hand[num].set_ID(29);
		hand[num].set_value(8);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("8");
		break;
	}
	case 30:
	{
		hand[num].set_ID(30);
		hand[num].set_value(8);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("8");
		break;
	}
	case 31:
	{
		hand[num].set_ID(31);
		hand[num].set_value(8);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("8");
		break;
	}
	case 32:
	{
		hand[num].set_ID(32);
		hand[num].set_value(8);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("8");
		break;
	}
	case 33:
	{
		hand[num].set_ID(33);
		hand[num].set_value(9);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("9");
		break;
	}
	case 34:
	{
		hand[num].set_ID(34);
		hand[num].set_value(9);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("9");
		break;
	}
	case 35:
	{
		hand[num].set_ID(35);
		hand[num].set_value(9);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("9");
		break;
	}
	case 36:
	{
		hand[num].set_ID(36);
		hand[num].set_value(9);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("9");
		break;
	}
	case 37:
	{
		hand[num].set_ID(37);
		hand[num].set_value(10);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("10");
		break;
	}
	case 38:
	{
		hand[num].set_ID(38);
		hand[num].set_value(10);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("10");
		break;
	}
	case 39:
	{
		hand[num].set_ID(39);
		hand[num].set_value(10);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("10");
		break;
	}
	case 40:
	{
		hand[num].set_ID(40);
		hand[num].set_value(10);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("10");
		break;
	}
	case 41:
	{
		hand[num].set_ID(41);
		hand[num].set_value(11);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("J");
		break;
	}
	case 42:
	{
		hand[num].set_ID(42);
		hand[num].set_value(11);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("J");
		break;
	}
	case 43:
	{
		hand[num].set_ID(43);
		hand[num].set_value(11);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("J");
		break;
	}
	case 44:
	{
		hand[num].set_ID(44);
		hand[num].set_value(11);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("J");
		break;
	}
	case 45:
	{
		hand[num].set_ID(45);
		hand[num].set_value(12);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("Q");
		break;
	}
	case 46:
	{
		hand[num].set_ID(46);
		hand[num].set_value(12);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("Q");
		break;
	}
	case 47:
	{
		hand[num].set_ID(47);
		hand[num].set_value(12);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("Q");
		break;
	}
	case 48:
	{
		hand[num].set_ID(48);
		hand[num].set_value(12);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("Q");
		break;
	}
	case 49:
	{
		hand[num].set_ID(49);
		hand[num].set_value(13);
		hand[num].set_color(Kind::diamond);
		hand[num].set_huase("·½");
		hand[num].set_number("K");
		break;
	}
	case 50:
	{
		hand[num].set_ID(50);
		hand[num].set_value(13);
		hand[num].set_color(Kind::club);
		hand[num].set_huase("Ã·");
		hand[num].set_number("K");
		break;
	}
	case 51:
	{
		hand[num].set_ID(51);
		hand[num].set_value(13);
		hand[num].set_color(Kind::heart);
		hand[num].set_huase("ºì");
		hand[num].set_number("K");
		break;
	}
	case 52:
	{
		hand[num].set_ID(52);
		hand[num].set_value(13);
		hand[num].set_color(Kind::spade);
		hand[num].set_huase("ºÚ");
		hand[num].set_number("K");
		break;
	}
	case 53:
	{
		hand[num].set_ID(53);
		hand[num].set_value(14);
		hand[num].set_color(Kind::joker);
		hand[num].set_huase("Ğ¡");
		hand[num].set_number("joker");
		break;
	}
	case 54:
	{
		hand[num].set_ID(54);
		hand[num].set_value(15);
		hand[num].set_color(Kind::joker);
		hand[num].set_huase("´ó");
		hand[num].set_number("JOKER");
		break;
	}
	}
	set_cardNumber(num);
	hand[num].set_position(num);
	return;
}
void Player::sort_hand()
{
	//int num = get_cardNumber();
	for (int next = 2; next < 21; ++next)
	{
		Card insert = hand[next];
		int moveItem = next;
		while ((moveItem > 1) && (hand[moveItem - 1].get_ID() > insert.get_ID()))
		{
			hand[moveItem] = hand[moveItem - 1];
			--moveItem;
		}
		hand[moveItem] = insert;
	}
	for (int i = 1; i <= 20; ++i)
	{
		hand[i].set_position(i);
	}
	return;
}
void Player::show_hand(int posi)
{
	std::cout << hand[posi].get_huase() << hand[posi].get_number() << " ";
}
void Player::show_all_hand()
{
	int num = get_cardNumber();
	for (int i = 1; i <= num; ++i)
	{
		show_hand(i);
	}
	return;
}
int Player::get_hand_ID(int posi)
{
	int id = 0;
	id = hand[posi].get_ID();
	return id;
}
void Player::play_hand(int posi)
{
	hand[posi].set_ID(100);
	int num = get_cardNumber() - 1;
	set_cardNumber(num);
	if (num == 0)
	{
		change_victory();
	}
	return;
}
int Player::get_value(int posi)
{
	int value = hand[posi].get_value();
	return value;
}

void Player::set_number(int n)
{
	number = n;
	return;
}
int Player::get_number()
{
	return number;
}

void Player::set_pass(int n)
{
	pass = n;
	return;
}
void Player::add_pass()
{
	int num = get_pass();
	++num;
	set_pass(num);
	return;
}
int Player::get_pass()
{
	return pass;
}

void Player::set_cardNumber(int c)
{
	cardNumber = c;
	return;
}
int Player::get_cardNumber()
{
	return cardNumber;
}

void Player::set_leftNumber(int num)
{
	leftNumber = num;
	return;
}
int Player::get_leftNumber()
{
	return leftNumber;
}

void Player::set_rightNumber(int num)
{
	rightNumber = num;
	return;
}
int Player::get_rightNumber()
{
	return rightNumber;
}