#pragma once
#include "IO.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Card.h"
#include "Player.h"
#include "distribute_the_card.h"
#include <fstream>
using std::fstream;
#include <string>
using std::string;

using std::cin;
using std::cout;
using std::endl;

extern string the_servers_files_name;
extern string the_client1_files_name;
extern string the_client2_files_name;
extern string the_client3_files_name;
//extern string buf;

extern fstream the_server_file;
extern fstream the_client1_file;
extern fstream the_client2_file;
extern fstream the_client3_file;

extern IO in_and_out;

extern string shared;
extern bool is_received;
extern string name_of_player1;
extern string name_of_player2;
extern string name_of_player3;

//void show_orders();
int to_know_the_next_one_to_choose(int);

void the_presettings();

