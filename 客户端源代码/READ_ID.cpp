#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
#include "READ_ID.h"
#include <fstream>


extern fstream The_IP_file("IP.txt",std::ios::in);

string Read_ID()
{
	string IP;
	The_IP_file >> IP;
	IP += ":6666";
	return IP;

}