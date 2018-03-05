#include "the_presettings.h"
#include <iostream>
#include <ctime>
#include <cstring>
#include <thread>
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
#include "choose_the_one.h"
#include "playing_the_cards.h"
static void listen_network()
{
	in_and_out.run();
}
int main()
{
	std::thread io(listen_network);
	io.detach();
	the_presettings();
	//cout << "按下任意键开始服务端运行" << endl;
	set_allcards();
	srand((unsigned)time(NULL));//设置时间种子
	distribute_all_the_card();
	cout << "发牌完毕" << endl;
	Sleep(1000);
	while (choose_the_one() == false)
	{
		cout << "fail to choose the one" << endl;
		distribute_all_the_card();
	}

	cout << "选地主完毕" << endl;
	Sleep(1000);
	playing_cards();
	//show_orders();
	//show_allcards();

}

























/*
#include <iostream>
#include "Card.h"
//#include "分发牌.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
	Card ca;
	ca.set_id(13);
	ca.set_number('k');
	ca.set_huase(Color::diamond);
	cout << ca.get_id();
	cout << endl;
	cout << ca.get_number() << endl;
	if (ca.get_huase() == Color::diamond)
	{
		cout << "yes" << endl;
	}
	if (ca.get_huase() != Color::heart)
	{
		cout << "no" << endl;
	}
	return 0;
}
*/