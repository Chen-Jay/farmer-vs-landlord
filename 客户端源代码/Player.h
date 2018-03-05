#pragma once

#include <iostream>
#include <string>
#include "Card.h"

class Player
{
private:
	std::string  name;        //  ����ǳ�
	bool         identity;    //  �����ݣ�true�ǵ�����false��ƽ��
	bool         turn;        //  �жϵ�ǰ�Ƿ����Լ��Ļغ�
	bool         victory;     //  �ж��Ƿ�ʤ����trueʤ����
	Card         hand[21];    //  ����
	int          number;      //  ��Ϸ���
	int          pass;        //  ��¼pass�˶��ٻغϣ��ٴ��ֵ��Լ���ʱ���Ƿ�һ��Ҫ����
	int          cardNumber;  //  ʣ��������
	int          leftNumber;  //  ������������
	int          rightNumber; //  �ұ����������

public:
	Player();

	void set_name(std::string);  //  ��������ǳ�
	std::string get_name();      //  ��ȡ����ǳ�

	void set_identity(bool);     //  ����������
	bool get_identity();         //  ��ȡ������

	void set_turn(bool);         //  ������һغ�״̬
	bool get_turn();             //  ��ȡ��һغ�״̬
	void change_turn();          //  �ı���һغ�״̬

	void set_victory(bool);      //  �������״̬
	bool get_victory();          //  ��ȡ���״̬
	void change_victory();       //  �������״̬

	void add_hand(int);          //  ��������
	void sort_hand();            //  ��������
	void show_hand(int);         //  չʾ��������
	void show_all_hand();        //  չʾ��������
	int get_hand_ID(int);        //  ��ȡ���Ƶ�ID
	void play_hand(int);         //  ����
	int get_value(int);          //  ��ȡ����ֵ

	void set_number(int);        //  ������Ϸ���
	int get_number();            //  ��ȡ��Ϸ���

	void set_pass(int);          //  ����pass�غ���
	void add_pass();             //  ����һ��pass��
	int get_pass();              //  ��ȡpass�غ���

	void set_cardNumber(int);    //  ������������
	int get_cardNumber();        //  ��ȡ��������

	void set_leftNumber(int);    //  ����������������
	int get_leftNumber();        //  ��ȡ������������

	void set_rightNumber(int);   //  �����ұ����������
	int get_rightNumber();       //  ��ȡ�ұ����������
};