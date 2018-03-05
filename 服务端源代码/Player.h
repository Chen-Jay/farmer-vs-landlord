#pragma once
#include<iostream>
#include<string>
#include"Card.h"
class Player
{
    private:
        std::string name;  //  玩家名字
        std::string ID;    //  玩家ID
        int         restCardNumber;  //  剩余的手牌数
        bool        victoryOrNot;    //  判断是否胜利
        bool        landLord;        //  判断是否是地主

		
    public:
        Player();
        void set_name(std::string);
        std::string get_name();
        void set_ID(std::string);
        std::string get_ID();
        void set_restCardNumber(int);
        int get_restCardNumber();
        void set_victoryOrNot(bool);
        bool get_victoryOrNot();
        void change_state();
        void set_landLord(bool);
        bool get_landLord();


};
