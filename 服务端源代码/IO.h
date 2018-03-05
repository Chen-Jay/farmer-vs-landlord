#ifndef IO_H
#define IO_H
#include <iostream>
#include <ctime>
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
#include "mongoose.h"


class IO
{
public:
	IO();
	~IO();
	void run();
	string read();
	string read_a_word(string &);
	void set_the_hand(int);
	int you_are_the_one(int);
	void these_are_the_three_cards(int);
	void you_are_the_farmer(int);
	void you_are_the_landlord(int);
	void it_is_your_turn(int);
	void cards_to_show(int,string);
	void cards_to_play(int, string);
	void tell_me_your_name(int client);
	void these_are_your_seat_information(int client, int land_lord);
	void show_pass(int client);
	void show_farmer_victory(int win_farmer);
	void show_landlord_victory(int landlord);
private:
	void write(int, const char*);
	mg_mgr manager;
	mg_connection *c;
	static void eventhandler(mg_connection *c, int event, void *ev_data);
	//string read();
};
#endif