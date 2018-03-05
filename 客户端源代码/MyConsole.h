#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "IO.h"
#include <windows.h>

//  �ı���ɫ
enum TextColor  //  ö�ٻ�����ɫ
{
	BLACK = 0,  //  ��ɫ
	RED = 1,    //  ��ɫ
	BLUE = 2,   //  ��ɫ
	GREEN = 3,  //  ��ɫ
	PURPLE = 4,   //  ��ɫ 
	INDIGO = 5, //  ����ɫ
	YELLOW = 6, //  ��ɫ
	WHITE = 7   //  ��ɫ
};


class MyConsole
{
private:
	HANDLE                      hIn;      //  ��ű�׼������
	HANDLE                      hOut;     //  ��ű�׼������
	CONSOLE_SCREEN_BUFFER_INFO  bInfo;    //  ������Ϣ�ṹ����Ŵ�����Ϣ
	WORD tColor;                          //  ����ı���ɫ
	WORD bColor;                          //  ��ű�����ɫ

public:
	MyConsole();
	~MyConsole();

	void clean_up();                                         //  ����
	//void clean_row(int row = 0);                           //  ����
	void set_title(const TCHAR *);                           //  ���ô��ڱ���
	void go_to(int, int);                                    //  �ı���λ��
	void set_size(int, int);                                 //  ���ô��ڴ�С
	void set_text_color(int, bool tIntensity = false);       //  �����ı���ɫ
	void set_background_color(int, bool bIntensity = false); //  ���ñ�����ɫ
	void show_cursor(DWORD size = 20);                       //  ��ʾ���
	void hide_cursor();                                      //  ���ع��
	void draw(int, int, int, int, bool);                     //  ����             
	void delete_line(int, int, int, int, char);              //  ɾ��ָ���鲢��������������
	void key_event();                                        //  ���̲���
	void mouse_event(int &x, int &y);                        //  ������
	void startUI(Player *, int len, int wid,std::string &name);                //  ��ʼ����
	void left_flesh(int);                                    //  ������������ˢ��
	void right_flesh(int);                                   //  �ұ����������ˢ��
	void self_flesh(Player &);                               //  �Լ�����ˢ��
	void playUI();                                           //  ��Ϸ�н���
	bool to_be_UI(Player &);                                 //  ѡ��������
	bool chupai(Player &, std::string &);                                   //  ���ƽ���
	//void endUI(bool); //��������
	void endUI(Player &p,std::string identity, std::string name);   //  ��������
	void draw_head(int, int, bool);                          //  ��ͷ��
	void write_name(std::string, int, int);                  //  д����
	void other_play(int, int, Player &);                     //  ������ҳ��ƣ����ٽ��������
	void show(int, int, int, bool);                          //  չʾ��һ���������������
};