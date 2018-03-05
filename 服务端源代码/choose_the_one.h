#pragma once
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
#include "choose_the_one.h"
#include "the_presettings.h"
#include "IO.h"
extern int nb_of_1;
extern int nb_of_2;
extern int nb_of_3;

extern int the_landlord;
bool choose_the_one();
bool communicate_with_the_client(int);
int to_know_the_next_one_to_choose(int);
