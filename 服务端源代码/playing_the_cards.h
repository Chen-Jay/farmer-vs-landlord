#pragma once

#include <iostream>
#include <ctime>
#include <sstream>
using std::stringstream;
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::fstream;
#include <string>
using std::string;

int in_the_first_turn();
int in_one_turn(int);
void playing_cards();
extern bool victory;
extern int number_of_rounds;