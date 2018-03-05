#pragma once

#include <iostream>
#include <string>

enum class Kind   //  ��ɫ
{
	diamond = 1,  //  ����
	club,         //  ÷��
	heart,        //  ����
	spade,        //  ����
	joker         //  ����
};

class Card
{
private:
	int          ID;        //  �Ƶı�ţ�1~54��
	int          value;     //  ����ֵ��1��2��������12��13��14��С����15�������
	int          position;  //  ��������ҵ�hand�����е�λ��
	Kind         color;     //  ���滨ɫ
	std::string  huase;     //  ��ӡ�õĻ�ɫ
	std::string  number;    //  ��ӡʱ������ֵ��A��2��������J,Q,K,JOKER)

public:
	Card();

	void set_ID(int);              //  �����Ʊ��
	int get_ID();                  //  ��ȡ�Ʊ��

	void set_value(int);           //  ��������ֵ
	int get_value();               //  ��ȡ����ֵ

	void set_position(int);        //  д������λ��
	int get_position();            //  ��ȡ����λ��

	void set_color(Kind);          //  ���û�ɫ
	Kind get_color();              //  ��ȡ��ɫ

	void set_huase(std::string);   //  ���ô�ӡ�õĻ�ɫ
	std::string get_huase();       //  ��ȡ��ӡ�õĻ�ɫ

	void set_number(std::string);  //  ��������ֵ
	std::string get_number();      //  ��ȡ����ֵ
};