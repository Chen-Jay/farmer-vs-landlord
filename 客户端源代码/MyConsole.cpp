#include <iostream>
#include <string>
#include "Player.h"
#include "Card.h"
#include "IO.h"
#include "MyConsole.h"
#include <windows.h>

extern MyConsole console;
//extern Player player;

MyConsole::MyConsole()
{
	hIn = GetStdHandle(STD_INPUT_HANDLE);      //  获取标准输入句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);    //  获取标准输出句柄
	GetConsoleScreenBufferInfo(hOut, &bInfo);  //  获取标准输出窗口的信息
}

MyConsole::~MyConsole()
{
	CloseHandle(hIn);                          // 释放标准输入句柄
	CloseHandle(hOut);                         // 释放标准输出句柄
}

void MyConsole::clean_up()
{
	go_to(0, 0);
	for (int i = 0; i != 40; ++i)
	{
		char buff[151];
		for (auto &i : buff)
			i = ' ';
		buff[150] = '\0';
		std::cout << buff << std::endl;
	}

	return;
}

void MyConsole::set_title(const TCHAR *chTitle)
{
	SetConsoleTitle(chTitle);

	return;
}

void MyConsole::go_to(int x, int y)
{
	COORD position = { x,y };
	SetConsoleCursorPosition(hOut, position);

	return;
}

void MyConsole::set_size(int len, int wid)
{
	COORD position = { len,wid };
	SMALL_RECT sr = { 0,0,len - 1,wid - 1 };

	SetConsoleWindowInfo(hOut, true, &sr);       //  设置窗口信息
	SetConsoleScreenBufferSize(hOut, position);  //  设置缓冲区大小

	return;
}

void MyConsole::set_text_color(int color, bool tIntensity)
{
	tColor = 0;

	if (color == RED)
	{
		if (tIntensity)
		{
			tColor = FOREGROUND_RED | FOREGROUND_INTENSITY;
		}
		else
		{
			tColor = FOREGROUND_RED;
		}
	}
	if (color == BLUE)
	{
		if (tIntensity)
		{
			tColor = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		}
		else
		{
			tColor = FOREGROUND_BLUE;
		}
	}
	if (color == GREEN)
	{
		if (tIntensity)
		{
			tColor = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		}
		else
		{
			tColor = FOREGROUND_GREEN;
		}
	}
	if (color == PURPLE)
	{
		if (tIntensity)
		{
			tColor = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		}
		else
		{
			tColor = FOREGROUND_RED | FOREGROUND_BLUE;
		}
	}
	if (color == INDIGO)
	{
		if (tIntensity)
		{
			tColor = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		}
		else
		{
			tColor = FOREGROUND_GREEN | FOREGROUND_BLUE;
		}
	}
	if (color == YELLOW)
	{
		if (tIntensity)
		{
			tColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		}
		else
		{
			tColor = FOREGROUND_RED | FOREGROUND_GREEN;
		}
	}
	if (color == WHITE)
	{
		if (tIntensity)
		{
			tColor = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		}
		else
		{
			tColor = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
		}
	}

	SetConsoleTextAttribute(hOut, tColor | bColor);

	return;
}

void MyConsole::set_background_color(int color, bool bIntensity)
{
	bColor = 0;

	if (color == RED)
	{
		if (bIntensity)
		{
			bColor = BACKGROUND_RED | BACKGROUND_INTENSITY;
		}
		else
		{
			bColor = BACKGROUND_RED;
		}
	}
	if (color == BLUE)
	{
		if (bIntensity)
		{
			bColor = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		}
		else
		{
			bColor = BACKGROUND_BLUE;
		}
	}
	if (color == GREEN)
	{
		if (bIntensity)
		{
			bColor = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		}
		else
		{
			bColor = BACKGROUND_GREEN;
		}
	}
	if (color == PURPLE)
	{
		if (bIntensity)
		{
			bColor = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		}
		else
		{
			bColor = BACKGROUND_RED | BACKGROUND_BLUE;
		}
	}
	if (color == INDIGO)
	{
		if (bIntensity)
		{
			bColor = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		}
		else
		{
			bColor = BACKGROUND_GREEN | BACKGROUND_BLUE;
		}
	}
	if (color == YELLOW)
	{
		if (bIntensity)
		{
			bColor = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		}
		else
		{
			bColor = BACKGROUND_RED | BACKGROUND_GREEN;
		}
	}
	if (color == WHITE)
	{
		if (bIntensity)
		{
			bColor = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		}
		else
		{
			bColor = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN;
		}
	}

	SetConsoleTextAttribute(hOut, tColor | bColor);

	return;
}

void MyConsole::show_cursor(DWORD size)
{
	CONSOLE_CURSOR_INFO cInfo;

	cInfo.dwSize = size;
	cInfo.bVisible = true;

	SetConsoleCursorInfo(hOut, &cInfo);

	return;
}

void MyConsole::hide_cursor()
{
	CONSOLE_CURSOR_INFO cInfo;

	cInfo.dwSize = 20;
	cInfo.bVisible = false;

	SetConsoleCursorInfo(hOut, &cInfo);

	return;
}

void MyConsole::draw(int x1, int y1, int x2, int y2, bool b)
{
	

	int len = x2 - x1;
	int wid = y2 - y1;
	if (b)
	{
		go_to(x1 + 1, y1);
		for (int i = 1; i != len; ++i)
		{
			std::cout << "_";
		}
		go_to(x1, y2);
		for (int i = 0; i <= len; ++i)
		{
			std::cout << "_";
		}
		for (int i = 1; i <= wid; ++i)
		{
			go_to(x1, y1 + i);
			std::cout << "|";
		}
		for (int i = 1; i <= wid; ++i)
		{
			go_to(x2, y1 + i);
			std::cout << "|";
		}
	}
	else
	{
		go_to(x1 + 1, y1);
		for (int i = 1; i != len; ++i)
		{
			std::cout << " ";
		}
		go_to(x1, y2);
		for (int i = 0; i <= len; ++i)
		{
			std::cout << " ";
		}
		for (int i = 1; i <= wid; ++i)
		{
			go_to(x1, y1 + i);
			std::cout << " ";
		}
		for (int i = 1; i <= wid; ++i)
		{
			go_to(x2, y1 + i);
			std::cout << " ";
		}

	}

	return;
}

void MyConsole::delete_line(int frow, int lrow, int lef, int rig, char c)
{
	SMALL_RECT srScroll, srClip;
	COORD position = { lef,frow - 1 };
	CHAR_INFO ch;

	srScroll.Left = lef;
	srScroll.Top = frow;
	srScroll.Right = rig;
	srScroll.Bottom = lrow;

	srClip = srScroll;

	ch.Attributes = bInfo.wAttributes;
	ch.Char.AsciiChar = c;

	ScrollConsoleScreenBuffer(hOut, &srScroll, &srClip, position, &ch);

	return;
}

void MyConsole::key_event()
{
	DWORD res, state = 0;
	INPUT_RECORD keyRec;
	COORD home = { 0,0 }, position;
	bool caps, num, scroll;
	char ch;

	//  输出三个灯的初始状态
	std::cout << "CAPS LOCK:CLOSE    NUM LOCK:CLOSE    SCROLL LOCK:CLOSE" << std::endl;

	bool cycle = true;
	while (cycle)
	{
		ReadConsoleInput(hIn, &keyRec, 1, &res);

		if (keyRec.EventType == KEY_EVENT)
		{
			//  只在键盘按下时判断，弹起时不判断
			if (keyRec.Event.KeyEvent.bKeyDown)
			{
				//  当三个灯的状态发生改变
				if (state != keyRec.Event.KeyEvent.dwControlKeyState)
				{
					state = keyRec.Event.KeyEvent.dwControlKeyState;
					caps = num = scroll = false;

					//  判断三个灯是否有亮
					if (state&CAPSLOCK_ON)
					{
						caps = true;
					}
					if (state&NUMLOCK_ON)
					{
						num = true;
					}
					if (state&SCROLLLOCK_ON)
					{
						scroll = true;
					}

					//  得到控制台信息，包括输出前光标的位置
					GetConsoleScreenBufferInfo(hOut, &bInfo);
					SetConsoleCursorPosition(hOut, home);

					//  输出三个灯的状态
					std::cout << "CAPS LOCK:" << (caps ? "OPEN " : "CLOSE") << "    ";
					std::cout << "NUM LOCK:" << (num ? "OPEN " : "CLOSE") << "    ";
					std::cout << "SCROLL LOCK:" << (scroll ? "OPEN " : "CLOSE");

					//  还原光标位置
					SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition);
				}

				//  基础功能键
				switch (keyRec.Event.KeyEvent.wVirtualKeyCode)
				{
				case VK_RETURN:  //  换行
					std::cout << std::endl;
					break;

				case VK_SPACE:
					std::cout << " ";
					break;

				case VK_BACK:
					GetConsoleScreenBufferInfo(hOut, &bInfo);
					position = bInfo.dwCursorPosition;

					if (position.X != 0)
					{
						position.X -= 1;
					}
					/*
					else
					{
					position.Y -= 1;
					}
					*/
					SetConsoleCursorPosition(hOut, position);
					std::cout << " ";
					SetConsoleCursorPosition(hOut, position);
					break;

				case VK_ESCAPE:
					cycle = false;
					break;

				default:
					break;
				}

				//  打印字符
				ch = keyRec.Event.KeyEvent.uChar.AsciiChar;

				//  输出可以打印的字符
				if (ch > 0x20 && ch < 0x7e)
				{
					putchar(ch);
				}
			}
		}
	}

	return;
}

void MyConsole::mouse_event(int &x, int &y)
{
DWORD res;
INPUT_RECORD mouseRec;
COORD position, home = { 0,39 };

while (1)
{
	ReadConsoleInput(hIn, &mouseRec, 1, &res);

	if (mouseRec.EventType == MOUSE_EVENT)
	{
		position = mouseRec.Event.MouseEvent.dwMousePosition;
		GetConsoleScreenBufferInfo(hOut, &bInfo);
		//SetConsoleCursorPosition(hOut, home);

		//std::cout << "[CURSOR POSITION] X: " << position.X << "  Y: " << position.Y;
		SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition);

		switch (mouseRec.Event.MouseEvent.dwButtonState)
		{
		case FROM_LEFT_1ST_BUTTON_PRESSED:
			x = position.X;
			y = position.Y;
			return;

			break;


		default:
			break;
		}

	}
}

return;
}
/*
void MyConsole::mouse_event()
{
	DWORD res;
	INPUT_RECORD mouseRec;
	COORD position, home = { 0,0 };

	std::cout << "x: 0  y:0";
	while (true)
	{
		//system("pause");
		ReadConsoleInput(hIn, &mouseRec, 1, &res);
		if (mouseRec.EventType == MOUSE_EVENT)
		{
			
			position = mouseRec.Event.MouseEvent.dwMousePosition;
			
			GetConsoleScreenBufferInfo(hOut, &bInfo);
			SetConsoleCursorPosition(hOut, home);
			std::cout << "x: " << position.X << "y: " << position.Y;
			SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition);
			

			switch (mouseRec.Event.MouseEvent.dwButtonState)
			{
			case FROM_LEFT_1ST_BUTTON_PRESSED:
				//FillConsoleOutputCharacter(hOut, 'a', 1, position, &res);
				std::cout << "x: " << position.X << "y: " << position.Y;
				break;
			case RIGHTMOST_BUTTON_PRESSED:
				//FillConsoleOutputCharacter(hOut, 'b', 1, position, &res);
				std::cout << "x: " << position.X << "y: " << position.Y;
				break;
			default:
				break;
			}
		}
	}

	return;
}
*/
void MyConsole::startUI(Player *p, int len, int wid,std::string &name)
{
	// MyConsole console;
	//console.set_size(len, wid);
	//console.hide_cursor();
	/*
	char ch[40][150];
	for (int i = 0; i != 40; ++i)
	{
		for (int j = 0; j != 150; ++j)
		{
			ch[i][j] = ' ';
		}
	}
	for (int i = 0; i != 40; ++i)
	{
		for (int j = 0; j != 150; ++j)
		{
			std::cout << ch[i][j];
		}
	}

	//  f-fight
	for (int i = 3; i != 15; ++i)
	{
		for (int j = 10; j != 12; ++j)
		{
			ch[i][j] = '1';
		}
	}
	for (int j = 12; j != 19; ++j)
	{
		ch[3][j] = '1';
		ch[8][j] = '1';
	}

	//  i-fight
	ch[6][24] = '1';
	ch[6][25] = '1';
	for (int j = 20; j != 26; ++j)
	{
		ch[8][j] = '1';
	}
	for (int j = 24; j != 29; ++j)
	{
		ch[14][j] = '1';
	}
	for (int i = 8; i != 15; ++i)
	{
		ch[i][24] = '1';
		ch[i][25] = '1';
	}

	//  g-fight
	for (int j = 30; j != 39; ++j)
	{
		ch[8][j] = '1';
		ch[14][j] = '1';
		ch[20][j] = '1';
	}
	for (int i = 9; i != 20; ++i)
	{
		ch[i][37] = '1';
		ch[i][38] = '1';
	}
	for (int i = 9; i != 20; ++i)
	{
		ch[i][30] = '1';
		ch[i][31] = '1';
		if (i == 13)
			i = 17;
	}

	//  h-fight
	for (int i = 3; i != 15; ++i)
	{
		ch[i][40] = '1';
		ch[i][41] = '1';
	}
	for (int i = 8; i != 15; ++i)
	{
		ch[i][47] = '1';
		ch[i][48] = '1';
	}
	for (int j = 42; j != 47; ++j)
	{
		ch[8][j] = '1';
	}

	//  t-fight
	for (int j = 50; j != 60; ++j)
	{
		ch[8][j] = '1';
	}
	for (int i = 6; i != 15; ++i)
	{
		ch[i][54] = '1';
		ch[i][55] = '1';
		if (i == 7)
			i = 8;
	}
	for (int j = 56; j != 60; ++j)
	{
		ch[14][j] = '1';
	}
	for (int i = 12; i != 14; ++i)
	{
		for (int j = 58; j != 60; ++j)
		{
			ch[i][j] = '1';
		}
	}

	//  a-against
	for (int i = 8; i != 15; ++i)
	{
		ch[i][70] = '1';
		ch[i][71] = '1';
	}
	for (int j = 72; j != 79; ++j)
	{
		ch[8][j] = '1';
	}
	for (int i = 8; i != 11; ++i)
	{
		ch[i][77] = '1';
		ch[i][78] = '1';
	}
	ch[14][72] = ch[14][73] = ch[14][74] = ch[14][77] = ch[14][78] = '1';
	ch[13][74] = ch[13][75] = ch[13][76] = ch[13][77] = '1';
	ch[12][75] = ch[12][76] = '1';
	ch[11][76] = ch[11][77] = '1';

	//  g-against
	for (int j = 80; j != 89; ++j)
	{
		ch[8][j] = '1';
		ch[14][j] = '1';
		ch[20][j] = '1';
	}
	for (int i = 9; i != 20; ++i)
	{
		ch[i][87] = '1';
		ch[i][88] = '1';
	}
	for (int i = 9; i != 20; ++i)
	{
		ch[i][80] = '1';
		ch[i][81] = '1';
		if (i == 13)
			i = 17;
	}

	//  a-against
	for (int i = 8; i != 15; ++i)
	{
		ch[i][90] = '1';
		ch[i][91] = '1';
	}
	for (int j = 92; j != 99; ++j)
	{
		ch[8][j] = '1';
	}
	for (int i = 8; i != 11; ++i)
	{
		ch[i][97] = '1';
		ch[i][98] = '1';
	}
	ch[14][92] = ch[14][93] = ch[14][94] = ch[14][97] = ch[14][98] = '1';
	ch[13][94] = ch[13][95] = ch[13][96] = ch[13][97] = '1';
	ch[12][95] = ch[12][96] = '1';
	ch[11][96] = ch[11][97] = '1';

	//  i-against
	ch[6][104] = '1';
	ch[6][105] = '1';
	for (int j = 100; j != 106; ++j)
	{
		ch[8][j] = '1';
	}
	for (int j = 104; j != 109; ++j)
	{
		ch[14][j] = '1';
	}
	for (int i = 8; i != 15; ++i)
	{
		ch[i][104] = '1';
		ch[i][105] = '1';
	}

	//  n-against
	for (int i = 8; i != 15; ++i)
	{
		ch[i][110] = '1';
		ch[i][111] = '1';
		ch[i][117] = '1';
		ch[i][118] = '1';
	}
	for (int j = 113; j != 117; ++j)
	{
		ch[8][j] = '1';
	}
	ch[9][112] = ch[9][113] = '1';

	//  s-against
	for (int j = 120; j != 129; ++j)
	{
		ch[8][j] = '1';
		ch[11][j] = '1';
		ch[14][j] = '1';
	}
	for (int i = 9, j = 12; i != 11; ++i, ++j)
	{
		ch[i][120] = '1';
		ch[i][121] = '1';
		ch[j][127] = '1';
		ch[j][128] = '1';
	}

	//  t-against
	for (int j = 130; j != 140; ++j)
	{
		ch[8][j] = '1';
	}
	for (int i = 6; i != 15; ++i)
	{
		ch[i][134] = '1';
		ch[i][135] = '1';
		if (i == 7)
			i = 8;
	}
	for (int j = 136; j != 140; ++j)
	{
		ch[14][j] = '1';
	}
	for (int i = 12; i != 14; ++i)
	{
		for (int j = 138; j != 140; ++j)
		{
			ch[i][j] = '1';
		}
	}

	// l-landlord
	for (int i = 23; i != 35; ++i)
	{
		ch[i][14] = '1';
		ch[i][15] = '1';
	}
	for (int j = 10; j != 14; ++j)
	{
		ch[23][j] = '1';
	}
	for (int j = 16; j != 19; ++j)
	{
		ch[34][j] = '1';
	}

	// a-landlord
	for (int i = 28; i != 35; ++i)
	{
		ch[i][20] = '1';
		ch[i][21] = '1';
	}
	for (int j = 22; j != 29; ++j)
	{
		ch[28][j] = '1';
	}
	for (int i = 28; i != 31; ++i)
	{
		ch[i][27] = '1';
		ch[i][28] = '1';
	}
	ch[34][22] = ch[34][23] = ch[34][24] = ch[34][27] = ch[34][28] = '1';
	ch[33][24] = ch[33][25] = ch[33][26] = ch[33][27] = '1';
	ch[32][25] = ch[32][26] = '1';
	ch[31][26] = ch[31][27] = '1';

	//  n-landlord
	for (int i = 28; i != 35; ++i)
	{
		ch[i][30] = '1';
		ch[i][31] = '1';
		ch[i][37] = '1';
		ch[i][38] = '1';
	}
	for (int j = 33; j != 37; ++j)
	{
		ch[28][j] = '1';
	}
	ch[29][32] = ch[29][33] = '1';

	//  d-landlord
	for (int i = 23; i != 28; ++i)
	{
		ch[i][47] = '1';
		ch[i][48] = '1';
	}
	for (int i = 28; i != 35; ++i)
	{
		ch[i][40] = '1';
		ch[i][41] = '1';
		ch[i][47] = '1';
		ch[i][48] = '1';
	}
	for (int j = 42; j != 47; ++j)
	{
		ch[28][j] = '1';
		ch[34][j] = '1';
	}

	//  l-landlord
	for (int i = 23; i != 35; ++i)
	{
		ch[i][54] = '1';
		ch[i][55] = '1';
	}
	for (int j = 50; j != 54; ++j)
	{
		ch[23][j] = '1';
	}
	for (int j = 56; j != 59; ++j)
	{
		ch[34][j] = '1';
	}

	//  o-landlord
	for (int j = 60; j != 69; ++j)
	{
		ch[28][j] = '1';
		ch[34][j] = '1';
	}
	for (int i = 29; i != 34; ++i)
	{
		ch[i][60] = '1';
		ch[i][61] = '1';
		ch[i][67] = '1';
		ch[i][68] = '1';
	}

	//  r-landlord
	for (int i = 28; i != 35; ++i)
	{
		ch[i][70] = '1';
		ch[i][71] = '1';
	}
	for (int j = 74; j != 79; ++j)
	{
		ch[28][j] = '1';
	}
	ch[30][72] = ch[30][73] = '1';
	ch[29][73] = ch[29][74] = '1';

	//  d-landlord
	for (int i = 23; i != 28; ++i)
	{
		ch[i][87] = '1';
		ch[i][88] = '1';
	}
	for (int i = 28; i != 35; ++i)
	{
		ch[i][80] = '1';
		ch[i][81] = '1';
		ch[i][87] = '1';
		ch[i][88] = '1';
	}
	for (int j = 82; j != 87; ++j)
	{
		ch[28][j] = '1';
		ch[34][j] = '1';
	}
	*/

console.set_background_color(BLACK, true);
console.set_text_color(PURPLE, true);
std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << "          000000000                    00                                                                                                  " << std::endl;
std::cout << "          00                           00                                                                                                 " << std::endl;
std::cout << "          00           00              00            00                                               00                            00    " << std::endl;
std::cout << "          00           00              00            00                                               00                            00    " << std::endl;
std::cout << "          00                           00            00                                                                             00    " << std::endl;
std::cout << "          000000000 00000    000000000 000000000 0000000000          000000000 000000000 000000000 00000    00  00000 000000000 0000000000" << std::endl;
std::cout << "          00           00    00     00 00     00     00              00     00 00     00 00     00    00    00 00  00 00            00    " << std::endl;
std::cout << "          00           00    00     00 00     00     00              00     00 00     00 00     00    00    0000   00 00            00    " << std::endl;
std::cout << "          00           00    00     00 00     00     00              00     00 00     00 00     00    00    00     00 000000000     00    " << std::endl;
std::cout << "          00           00    00     00 00     00     00  00          00    00  00     00 00    00     00    00     00        00     00  00" << std::endl;
std::cout << "          00           00    00     00 00     00     00  00          00  00000 00     00 00  00000    00    00     00        00     00  00" << std::endl;
std::cout << "          00           00000 000000000 00     00     000000          00000  00 000000000 00000  00    00000 00     00 000000000     000000" << std::endl;
std::cout << "                                    00                                                00                                                  " << std::endl;
std::cout << "                                    00                                                00                                                  " << std::endl;
std::cout << "                             00     00                                         00     00                                                  " << std::endl;
std::cout << "                             00     00                                         00     00                                                  " << std::endl;
std::cout << "                             000000000                                         000000000                                                  " << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << "          00                                   00 00                                   00 " << std::endl;
std::cout << "          00                                   00 00                                   00 " << std::endl;
std::cout << "          00                                   00 00                                   00 " << std::endl;
std::cout << "          00                                   00 00                                   00 " << std::endl;
std::cout << "          00                                   00 00                                   00 " << std::endl;
std::cout << "          00        000000000 00  00000 000000000 00        000000000 00  00000 000000000 " << std::endl;
std::cout << "          00        00     00 00 00  00 00     00 00        00     00 00 00     00     00 " << std::endl;
std::cout << "          00        00     00 0000   00 00     00 00        00     00 0000      00     00 " << std::endl;
std::cout << "          00        00     00 00     00 00     00 00        00     00 00        00     00 " << std::endl;
std::cout << "          00        00    00  00     00 00     00 00        00     00 00        00     00 " << std::endl;
std::cout << "          00        00  00000 00     00 00     00 00        00     00 00        00     00 " << std::endl;
std::cout << "          000000000 00000  00 00     00 000000000 000000000 000000000 00        000000000 " << std::endl;

	////////////////////////
	//system("pause");
	//system("cls");
	/*
	for (int i = 0; i != 40; ++i)
	{
		for (int j = 0; j != 150; ++j)
		{

			if (ch[i][j] == '1')
			{
				console.set_background_color(PURPLE);
				console.set_text_color(PURPLE);
			}
			else if (ch[i][j] == ' ')
			{
				console.set_background_color(BLACK);
				console.set_text_color(GREEN);
			}
			else
			{
				console.set_background_color(PURPLE);
				console.set_text_color(PURPLE);
			}
			std::cout << ch[i][j];
		}
		std::cout << std::endl;
	}
	*/
	console.set_text_color(BLUE, true);
	std::string str = "Please input your name:";
	console.go_to(100, 28);
	std::cout << str;
	std::cin >> str;
	name = str;
	p->set_name(str);
	console.go_to(100, 29);


	console.set_background_color(BLACK);
	console.set_text_color(WHITE);
	

	return;
}

void MyConsole::left_flesh(int num)
{
	console.set_text_color(WHITE,true);
	for (int i = 2; i < 29; ++i)
	{
		go_to(25, i);
		std::cout << "            ";
	}
	for (int i = 0; i + 1 < num; ++i)
	{
		draw(25, 2 + i, 34, 3 + i, true);
	}
	if (num != 0)
	draw(25,  1 + num, 34, 5 + num, true);
	go_to(0, 39);
	console.set_text_color(BLACK);

	return;
}

void MyConsole::right_flesh(int num)
{
	console.set_text_color(WHITE, true);
	for (int i = 2; i != 29; ++i)
	{
		go_to(115, i);
		std::cout << "          ";
	}
	for (int i = 0; i + 1 < num; ++i)
	{
		draw(115, 2 + i, 124, 3 + i, true);
	}
	if (num != 0)
	draw(115, 1 + num, 124, 5 + num, true);
	go_to(0, 39);
	console.set_text_color(BLACK);

	return;
}

void MyConsole::self_flesh(Player &p)
{
	int cnum = p.get_cardNumber();
	console.set_text_color(WHITE, true);

	for (int i = 30; i != 39; ++i)
	{
		go_to(30, i);
		std::cout << "                                                                                          ";
	}
	int k = 4;
	for (int i = 0; i + 1 < cnum; ++i)
	{

		draw(30 + k*i, 30, 34 + k*i, 38, true);
	}
	draw(30 + k*(cnum - 1), 30, 39 + k*(cnum - 1), 38, true);
	////////////////////////////////
	for (int i = 1; i <= cnum; ++i)
	{
		int value = p.get_value(i);
		int id = p.get_hand_ID(i);
		int huase = id % 4;
		if (huase == 1 && id < 53)
		{
			console.set_text_color(RED, true);
			go_to(31 + 4 * (i - 1), 31);
			if (value <= 10)
			{
				std::cout << value;
			}
			else
			{
				if (value == 11)
				{
					std::cout << "J";
				}
				else if (value == 12)
				{
					std::cout << "Q";
				}
				else
				{
					std::cout << "K";
				}
			}
			go_to(31 + 4 * (i - 1), 32);
			std::cout << "方";
		}
		else if (huase == 2 && id < 53)
		{
			console.set_text_color(INDIGO, true);
			go_to(31 + 4 * (i - 1), 31);
			if (value <= 10)
			{
				std::cout << value;
			}
			else
			{
				if (value == 11)
				{
					std::cout << "J";
				}
				else if (value == 12)
				{
					std::cout << "Q";
				}
				else
				{
					std::cout << "K";
				}
			}
			go_to(31 + 4 * (i - 1), 32);
			std::cout << "梅";
		}
		else if (huase == 3 && id < 53)
		{
			console.set_text_color(RED, true);
			go_to(31 + 4 * (i - 1), 31);
			if (value <= 10)
			{
				std::cout << value;
			}
			else
			{
				if (value == 11)
				{
					std::cout << "J";
				}
				else if (value == 12)
				{
					std::cout << "Q";
				}
				else
				{
					std::cout << "K";
				}
			}
			go_to(31 + 4 * (i - 1), 32);
			std::cout << "红";
		}
		else if (huase == 0 && id < 53)
		{
			console.set_text_color(INDIGO, true);
			go_to(31 + 4 * (i - 1), 31);
			if (value <= 10)
			{
				std::cout << value;
			}
			else
			{
				if (value == 11)
				{
					std::cout << "J";
				}
				else if (value == 12)
				{
					std::cout << "Q";
				}
				else
				{
					std::cout << "K";
				}
			}
			go_to(31 + 4 * (i - 1), 32);
			std::cout << "黑";
		}
		else
		{
			if (id == 53)
			{
				console.set_text_color(INDIGO, true);
				go_to(31 + 4 * (i - 1), 31);
				std::cout << "j";
				go_to(31 + 4 * (i - 1), 32);
				std::cout << "o";
				go_to(31 + 4 * (i - 1), 33);
				std::cout << "k";
				go_to(31 + 4 * (i - 1), 34);
				std::cout << "e";
				go_to(31 + 4 * (i - 1), 35);
				std::cout << "r";

			}
			else
			{
				console.set_text_color(RED, true);
				go_to(31 + 4 * (i - 1), 31);
				std::cout << "J";
				go_to(31 + 4 * (i - 1), 32);
				std::cout << "O";
				go_to(31 + 4 * (i - 1), 33);
				std::cout << "K";
				go_to(31 + 4 * (i - 1), 34);
				std::cout << "E";
				go_to(31 + 4 * (i - 1), 35);
				std::cout << "R";
			}
		}

	}

	go_to(0, 0);
	console.set_text_color(BLACK);

	return;
}

void MyConsole::playUI()
{
	clean_up();

	draw(2, 2, 20, 10,true);  //  左侧头像栏
	draw(2, 10, 20, 12, true); //  左侧昵称栏
	draw(2, 12, 20, 14, true); //  左侧手牌数栏
	/*
	//  左侧手牌栏
	for (int i = 0; i != 16; ++i)
	{
		draw(25, 2 + i, 34, 3 + i, true);
	}
	draw(25, 18, 34, 22, true);
	*/

	draw(129, 2, 147, 10, true);  //  右边头像栏
	draw(129, 10, 147, 12, true); //  右边昵称栏
	draw(129, 12, 147, 14, true); //  右边手牌数栏
	/*
	//  右侧手牌栏
	for (int i = 0; i != 16; ++i)
	{
		draw(115, 2 + i, 124, 3 + i, true);
	}
	draw(115, 18, 124, 22, true);
	*/

	draw(2, 26, 20, 34, true);  //  自己头像栏
	draw(2, 34, 20, 36, true);  //  自己昵称栏
	draw(2, 36, 20, 38, true);  //  自己手牌数栏
	/*
	//  自己手牌栏
	for (int i = 0, k = 4; i != 16; ++i)
	{
		draw(30 + k*i, 30, 34 + k*i, 38, true);
	}
	draw(94, 30, 103, 38, true);
	*/

	go_to(133, 31);
	std::cout << "PLAY";
	draw(130, 30, 139, 32, true);  //  出牌按钮
	go_to(133, 36);
	std::cout << "PASS";
	draw(130, 35, 139, 37, true);  //  过  按钮

	go_to(0, 39);

	return;
}

bool MyConsole::to_be_UI(Player &p)
{
	show(0, 0, 0, false);

	go_to(50, 10);
	console.set_text_color(YELLOW, true);
	std::cout << "Do you wanna be landlord？";

	console.set_text_color(WHITE, true);
	draw(50, 11, 60, 13, true);
	draw(50, 14, 60, 16, true);

	go_to(54, 12);
	std::cout << "YES";
	go_to(54, 15);
	std::cout << "NO";

	int x = 0, y = 0;
	while (true)
	{
		mouse_event(x, y);
		if (x >= 50 && x <= 60 && y >= 11 && y <= 13)
		{
			go_to(0, 39);
			console.set_text_color(BLACK);

			for (int i = 10; i <= 17; ++i)
			{
				go_to(50, i);
				std::cout << "                         ";
			}

			return true;
			//break;
		}
		else if (x >= 50 && x <= 60 && y >= 14 && y <= 16)
		{
			go_to(0, 39);
			console.set_text_color(BLACK);

			for (int i = 10; i <= 17; ++i)
			{
				go_to(50, i);
				std::cout << "                         ";
			}

			return false;
		}
		else
			continue;

	}


	return false;
}
/*
void MyConsole::endUI(bool victory)
{
	if (victory)
	{
		set_text_color(RED, true);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		///////////////////////
		std::cout << "000               000000               000  000000000  " << std::endl;
		std::cout << "000               000000               000  000000000  " << std::endl;
		std::cout << "000              000  000              000     000     " << std::endl;
		std::cout << " 000            000    000            000      000     " << std::endl;
		std::cout << "  000          000      000          000       000     " << std::endl;
		std::cout << "   000        000        000        000        000     " << std::endl;
		std::cout << "    000      000          000      000         000     " << std::endl;
		std::cout << "     000    000            000    000          000     " << std::endl;
		std::cout << "      000  000              000  000           000     " << std::endl;
		std::cout << "       000000                000000         000000000  " << std::endl;
		std::cout << "       000000                000000         000000000  " << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		/////////////////////////////

	}
	else
	{
		set_text_color(RED, true);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		///////////////////////
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		/////////////////////////////
	}
}
*/
void MyConsole::endUI(Player &p,std::string identity, std::string name)
{
	clean_up();

	bool iden = false;
	if (identity == "landlord")
	{
		iden = true;
	}
	else
	{
		iden = false;
	}

	go_to(70, 20);
	console.set_text_color(YELLOW, true);
	std::cout << name << "先出完手牌！";
	go_to(70, 22);
	{
		if (iden)
		{
			std::cout << "地主获得胜利！";
			go_to(70, 24);
			if (p.get_identity())
			{
				std::cout << "您赢了！";
			}
			else
			{
				std::cout << "您输了！";
			}
		}
		else
		{
			std::cout << "农民获得胜利！";
			go_to(70, 24);
			if (!p.get_identity())
			{
				std::cout << "您赢了！";
			}
			else
			{
				std::cout << "您输了";
			}
		}
	}
	return;
}

bool MyConsole::chupai(Player &p, std::string &report)
{
	go_to(0, 0);
	self_flesh(p);
	int num = p.get_cardNumber();
	int len = (num - 1) * 4 + 39;
	int hands[21] = { 0 };
	for (int i = 1; i <= num; ++i)
	{
		hands[i] = -1;
	}

	if (num == 20 || p.get_pass() == 2)
	{
		console.set_text_color(WHITE, true);
		go_to(133, 31);
		std::cout << "PLAY";
		draw(130, 30, 139, 32, true);  //  出牌按钮
		go_to(0, 0);
	}
	else
	{
		console.set_text_color(WHITE, true);
		go_to(133, 31);
		std::cout << "PLAY";
		draw(130, 30, 139, 32, true);  //  出牌按钮
		go_to(133, 36);
		std::cout << "PASS";
		draw(130, 35, 139, 37, true);  //  过  按钮
		console.set_text_color(BLACK);
		go_to(0, 39);
	}
	
	bool play = false;
	int n = 0;
	int x = 0, y = 0;
	while (true)
	{
		mouse_event(x, y);
		if (x >= 30 && x <= len&&y >= 30 && y <= 38)
		{
			int i = 1;
			while (x > 30 + (i - 1) * 4)
			{
				++i;
			}
			if (hands[i-1] == -1)
			{

				hands[i-1] = p.get_hand_ID(i-1);
				++n;
				go_to(27 + (i - 1) * 4, 28);
				console.set_text_color(YELLOW, true);
				std::cout << "!!";
				console.set_text_color(BLACK);
				go_to(0, 0);
			}
			else if (hands[i-1] == 0)
			{
				continue;
			}
			else
			{
				hands[i-1] = -1;
				--n;
				go_to(27 + (i - 1) * 4, 28);
				console.set_text_color(BLACK);
				std::cout << "  ";
			}

		}
		else if (x >= 130 && x <= 139 && y >= 30 && y <= 32)
		{
			if (n == 0)
			{
				continue;
			}
			else
			{
				play = true;
				report = "1";
				break;
			}
		}
		else if (x >= 130 && x <= 139 && y >= 35 && y <= 37)
		{
			if (num == 20 || p.get_pass() == 2)
			{
				//p.set_pass(0);
				continue;
			}
			else
			{
				play = false;
				report = "0";
				//return false;
				break;
			}
		}
		else
		{
			continue;
		}
	}

	if (play == true)
	{
		p.set_pass(0);
		int cot = 1;
		//Sleep(5000);
		for(int i=1;i<=num;++i)
		{ 
			if (hands[i] > 0)
			{
				std::string id;
				std::stringstream ss;
				ss << hands[i];
				p.play_hand(i);
				ss >> id;
				report = report + " " + id;
				show(cot, n, hands[i], true);
				++cot;
			}
		}
		//Sleep(5000);
		p.sort_hand ();
		self_flesh(p);
		go_to(30, 28);
		console.set_text_color(BLACK);
		//Sleep(8000);
		std::cout << "                                                                                          ";

		
		//Sleep(8000);
		for (int i = 30; i <= 37; ++i)
		{
			go_to(130, i);
			std::cout << "               ";
		}

		go_to(0, 0);

		return true;
	}

	else
	{
		for (int i = 30; i <= 37; ++i)
		{
			go_to(30, 28);
			console.set_text_color(BLACK);
			std::cout << "                                                                                          ";

			go_to(130, i);
			std::cout << "               ";
		}

		go_to(0, 0);
	}

	return true;

}

void MyConsole::draw_head(int x, int y, bool b)
{
	std::string s1, s2, s3, s4, s5, s6, s7;
	if (b)
	{
		char ch[7][17] =
		{  //0   1   2   3   4   5   6   7   8   9   0   1   2   3   4   5   6
			' ',' ',' ',' ',' ',' ',' ',' ','1',' ',' ',' ',' ',' ',' ',' ',' ',
			'1',' ',' ',' ','1',' ',' ','1','1','1',' ',' ','1',' ',' ',' ','1',
			'1','1',' ','1','1','1',' ','1','1','1',' ','1','1','1',' ','1','1',
			'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1',
			' ','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1',' ',
			' ','2','3','3','3','3','3','3','3','3','3','3','3','3','3','2',' ',
			' ','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2',' '
		};

		for (int i = 0; i != 7; ++i)
		{
			go_to(x, y + i);
			for (int j = 0; j != 17; ++j)
			{
				if (ch[i][j] == '1')
				{
					console.set_background_color(YELLOW, true);
					console.set_text_color(YELLOW, true);
				}
				else if (ch[i][j] == '2')
				{
					console.set_background_color(RED, true);
					console.set_text_color(RED, true);
				}
				else if (ch[i][j] == '3')
				{
					console.set_background_color(BLUE, true);
					console.set_text_color(BLUE, true);
				}
				else
				{
					console.set_background_color(BLACK);
					console.set_text_color(BLACK);
				}
				std::cout << " ";
			}
		}

	}

	else
	{
		char ch[6][17] =
		{  //0   1   2   3   4   5   6   7   8   9   0   1   2   3   4   5   6
			' ',' ',' ',' ',' ',' ',' ','1','1','1',' ',' ',' ',' ',' ',' ',' ',
			' ',' ',' ',' ',' ','1','1','1','1','1','1','1',' ',' ',' ',' ',' ',
			' ',' ',' ','1','1','1','1','1','1','1','1','1','1','1',' ',' ',' ',
			' ',' ','1','1','1','1','1','1','1','1','1','1','1','1','1',' ',' ',
			' ',' ','2','2','2','2','2','2','2','2','2','2','2','2','2',' ',' ',
			'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1',
		};
		for (int i = 0; i != 6; ++i)
		{
			go_to(x, y + i);
			for (int j = 0; j != 17; ++j)
			{
				if (ch[i][j] == '1')
				{
					console.set_background_color(YELLOW);
					console.set_text_color(YELLOW, true);
				}
				else if (ch[i][j] == '2')
				{
					console.set_background_color(RED);
					console.set_text_color(RED, true);
				}
				else if (ch[i][j] == '3')
				{
					console.set_background_color(BLUE);
					console.set_text_color(BLUE, true);
				}
				else
				{
					console.set_background_color(BLACK);
					console.set_text_color(BLACK);
				}
				std::cout << " ";
			}
			//std::cout << std::endl;
		}
	}
	
	console.set_background_color(BLACK);
	console.set_text_color(WHITE,true);

	go_to(0, 39);
	return;
}

void MyConsole::write_name(std::string name, int x, int y)
{
	go_to(x, y);
	//console.set_background_color(INDIGO);
	console.set_text_color(PURPLE, true);
	std::cout << name;

	//console.set_text_color(INDIGO);
	go_to(0, 0);
	console.set_text_color(BLACK);
	return;
}

void MyConsole::other_play(int turn, int num, Player &p)
{
	turn = (turn - p.get_number()) % 3;

	if (turn == 1)
	{
		num = p.get_rightNumber() - num;
		right_flesh(num);
	}
	
	if (turn == 2)
	{
		num = p.get_leftNumber() - num;
		left_flesh(num);
	}

	return;
}

void MyConsole::show(int num, int sum, int id, bool b)
{
	if (b)
	{
		if (num == 1)
		{
			for (int i = 0; i <= 8; ++i)
			{
				console.set_text_color(GREEN);
				go_to(40, 10 + i);
				//std::cout << "000000000000000000000000000000000000000000000000000000000000000000000000000";
				std::cout << "                                                                           ";
			}
		}

		console.set_text_color(WHITE);
		int value = id / 4;
		if (id % 4 != 0)
		{
			++value;         //  牌面值
		}
		int huase = id % 4;  //  花色

		go_to(40 + (num - 1) * 4, 10);
		if (num != sum)
		{
			draw(40 + (num - 1) * 4, 10, 44 + (num - 1) * 4, 18, true);
		}
		else
		{
			draw(40 + (num - 1) * 4, 10, 49 + (num - 1) * 4, 18, true);
		}

		//go_to(41 + num * 4, 11);
		if (huase == 1 && id < 53)
		{
			console.set_text_color(RED, true);
			go_to(41 + 4 * (num - 1), 11);
			if (value <= 10)
			{
				std::cout << value;
			}
			else
			{
				if (value == 11)
				{
					std::cout << "J";
				}
				else if (value == 12)
				{
					std::cout << "Q";
				}
				else
				{
					std::cout << "K";
				}
			}
			go_to(41 + 4 * (num - 1), 12);
			std::cout << "方";
		}
		else if (huase == 2 && id < 53)
		{
			console.set_text_color(INDIGO, true);
			go_to(41 + 4 * (num - 1), 11);
			if (value <= 10)
			{
				std::cout << value;
			}
			else
			{
				if (value == 11)
				{
					std::cout << "J";
				}
				else if (value == 12)
				{
					std::cout << "Q";
				}
				else
				{
					std::cout << "K";
				}
			}
			go_to(41 + 4 * (num - 1), 12);
			std::cout << "梅";
		}
		else if (huase == 3 && id < 53)
		{
			console.set_text_color(RED, true);
			go_to(41 + 4 * (num - 1), 11);
			if (value <= 10)
			{
				std::cout << value;
			}
			else
			{
				if (value == 11)
				{
					std::cout << "J";
				}
				else if (value == 12)
				{
					std::cout << "Q";
				}
				else
				{
					std::cout << "K";
				}
			}
			go_to(41 + 4 * (num - 1), 12);
			std::cout << "红";
		}
		else if (huase == 0 && id < 53)
		{
			console.set_text_color(INDIGO, true);
			go_to(41 + 4 * (num - 1), 11);
			if (value <= 10)
			{
				std::cout << value;
			}
			else
			{
				if (value == 11)
				{
					std::cout << "J";
				}
				else if (value == 12)
				{
					std::cout << "Q";
				}
				else
				{
					std::cout << "K";
				}
			}
			go_to(41 + 4 * (num - 1), 12);
			std::cout << "黑";
		}
		else
		{
			if (id == 53)
			{
				console.set_text_color(INDIGO, true);
				go_to(41 + 4 * (num - 1), 11);
				std::cout << "j";
				go_to(41 + 4 * (num - 1), 12);
				std::cout << "o";
				go_to(41 + 4 * (num - 1), 13);
				std::cout << "k";
				go_to(41 + 4 * (num - 1), 14);
				std::cout << "e";
				go_to(41 + 4 * (num - 1), 15);
				std::cout << "r";

			}
			else
			{
				console.set_text_color(RED, true);
				go_to(41 + 4 * (num - 1), 11);
				std::cout << "J";
				go_to(41 + 4 * (num - 1), 12);
				std::cout << "O";
				go_to(41 + 4 * (num - 1), 13);
				std::cout << "K";
				go_to(41 + 4 * (num - 1), 14);
				std::cout << "E";
				go_to(41 + 4 * (num - 1), 15);
				std::cout << "R";
			}
		}

	}

	else
	{
		for (int i = 0; i <= 8; ++i)
		{
			console.set_text_color(BLACK);
			go_to(40, 10 + i);
			std::cout << "                                                                           ";
		}
		console.set_text_color(WHITE, true);
	}




	go_to(0, 0);
	console.set_text_color(BLACK);
	return;
}