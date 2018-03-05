#pragma once
#include<iostream>

enum class kind{diamond,club,heart,spade,king};

class Card
{
    private:
        int ID;                   //  牌的编号
        int number;               //  牌面数字
        std::string printNumber;  //  打印时候的数字
        kind huase;               //  牌面的花色

    public:
        Card();
        void set_ID(int);
        int get_ID();
        void set_number(int);
        int get_number();
        void set_printNumber(std::string);
        std::string get_printNumber();
        void set_huase(kind);
        kind get_huase();
};
