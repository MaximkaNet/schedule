#pragma once
#include "Date.h"
#include "Time.h"
class Datetime :
    public Date,
    public Time
{
    Date date;
    Time time;
public:
    Datetime();
    // if type == 0 will be date else type == 1 - time
    Datetime(int dayOrSecond, int monthOrMinutes, int yearOrHours, bool type = 0);
    Datetime(int day, int month, int year, int seconds, int minutes, int hours);
    Datetime(Date date, Time time);
    Datetime(const Datetime& obj);

    Date getDate();
    Time getTime();

    void change(int day, int month, int year, int seconds, int minutes, int hours);
    void change(int dayOrSecond, int monthOrMinutes, int yearOrHours, bool type = 0);
    void change(Date date, Time time);

    string getDatetimeStr();

    void show();

    bool operator == (Datetime obj);
    bool operator != (Datetime obj);
    bool operator >= (Datetime obj);
    bool operator <= (Datetime obj);
    bool operator > (Datetime obj);
    bool operator < (Datetime obj);

    void operator= (Datetime obj);
    void operator= (Date obj);
    void operator= (Time obj);
};

