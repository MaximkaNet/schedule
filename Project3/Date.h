#pragma once
#include <iostream>
#include <string>
using std::string;
using std::to_string;
class Date
{
private:
    int day;
    int month;
    int year;
    bool isLeapYear();
    int daysInMonth();

public:
    Date();
    Date(int day, int month, int year);
    Date(const Date&);

    Date& operator++(); // префиксная форма ++i
    Date& operator++(int);// постфиксная форма i++
    Date& operator--();
    Date& operator--(int);
    Date& operator+(int);
    Date& operator-(int);
    int operator-(Date&);
    Date& operator = (Date);

    bool operator > (Date);
    bool operator < (Date);
    bool operator <= (Date);
    bool operator >= (Date);
    bool operator == (Date);
    bool operator != (Date);

    void show();

    int get_day();
    int get_month();
    int get_year();

    void set_day(int day);
    void set_month(int month);
    void set_year(int year);
    string to_str();

    void autoFill();

    bool isEmpty();
};

