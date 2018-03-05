#pragma once
#include <stdlib.h>
#include "Card.h"
#include "Player.h"


void distribute_all_the_card();
void set_allcards_kind();
void set_allcards_ID();
void set_allcards_print_number();
void show_allcards();
void set_allcards();
extern int the_ID_of_the_cards[55];//ÅÆµÄÊý×é
extern int the_ID_of_the_three_cards[3];
void set_the_three_cards();
void store_the_hands(int []);
void show_the_hands(int client);
extern int the_hands_of_player1[22];
extern int the_hands_of_player2[22];
extern int the_hands_of_player3[22];
