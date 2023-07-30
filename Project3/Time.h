#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::to_string;
class Time
{
    int hour;
    int minute;
    int second;
public:
    Time();
    Time(int hour, int minute, int second);
    Time(const Time& obj);

    int getHour();
    int getMinute();
    int getSecond();

    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);

    void show();
    string toStr();
    bool isEmpty();
    void autoFill();

    bool operator== (Time obj);
    bool operator!= (Time obj);
    bool operator >= (Time obj);
    bool operator <= (Time obj);
    bool operator > (Time obj);
    bool operator < (Time obj);

    Time& operator = (Time obj);
};

