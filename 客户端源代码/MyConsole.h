#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "IO.h"
#include <windows.h>

//  文本颜色
enum TextColor  //  枚举基本颜色
{
	BLACK = 0,  //  黑色
	RED = 1,    //  红色
	BLUE = 2,   //  蓝色
	GREEN = 3,  //  绿色
	PURPLE = 4,   //  粉色 
	INDIGO = 5, //  靛青色
	YELLOW = 6, //  黄色
	WHITE = 7   //  白色
};


class MyConsole
{
private:
	HANDLE                      hIn;      //  存放标准输入句柄
	HANDLE                      hOut;     //  存放标准输出句柄
	CONSOLE_SCREEN_BUFFER_INFO  bInfo;    //  窗口信息结构，存放窗口信息
	WORD tColor;                          //  存放文本颜色
	WORD bColor;                          //  存放背景颜色

public:
	MyConsole();
	~MyConsole();

	void clean_up();                                         //  清屏
	//void clean_row(int row = 0);                           //  清行
	void set_title(const TCHAR *);                           //  设置窗口标题
	void go_to(int, int);                                    //  改变光标位置
	void set_size(int, int);                                 //  设置窗口大小
	void set_text_color(int, bool tIntensity = false);       //  设置文本颜色
	void set_background_color(int, bool bIntensity = false); //  设置背景颜色
	void show_cursor(DWORD size = 20);                       //  显示光标
	void hide_cursor();                                      //  隐藏光标
	void draw(int, int, int, int, bool);                     //  画线             
	void delete_line(int, int, int, int, char);              //  删除指定块并将余下内容上移
	void key_event();                                        //  键盘操作
	void mouse_event(int &x, int &y);                        //  鼠标操作
	void startUI(Player *, int len, int wid,std::string &name);                //  开始界面
	void left_flesh(int);                                    //  左边玩家手牌数刷新
	void right_flesh(int);                                   //  右边玩家手牌数刷新
	void self_flesh(Player &);                               //  自己手牌刷新
	void playUI();                                           //  游戏中界面
	bool to_be_UI(Player &);                                 //  选地主界面
	bool chupai(Player &, std::string &);                                   //  出牌界面
	//void endUI(bool); //结束界面
	void endUI(Player &p,std::string identity, std::string name);   //  结束界面
	void draw_head(int, int, bool);                          //  画头像
	void write_name(std::string, int, int);                  //  写名字
	void other_play(int, int, Player &);                     //  其他玩家出牌，减少界面的牌数
	void show(int, int, int, bool);                          //  展示上一个玩家所出的手牌
};