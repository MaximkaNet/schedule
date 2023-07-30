#include "Datetime.h"

Datetime::Datetime()
{
    date = Date();
    time = Time();
}

Datetime::Datetime(int dayOrSecond, int monthOrMinutes, int yearOrHours, bool type)
{
    if (type == 0) {
        date.set_day(dayOrSecond);
        date.set_month(monthOrMinutes);
        date.set_year(yearOrHours);
        return;
    }
    time.setSecond(dayOrSecond);
    time.setMinute(monthOrMinutes);
    time.setHour(yearOrHours);
}

Datetime::Datetime(int day, int month, int year, int seconds, int minutes, int hours)
{
    date.set_day(day);
    date.set_month(month);
    date.set_year(year);
    time.setSecond(seconds);
    time.setMinute(minutes);
    time.setHour(hours);
}

Datetime::Datetime(Date date, Time time)
{
    this->date = date;
    this->time = time;
}

Datetime::Datetime(const Datetime& obj)
{
    date = obj.date;
    time = obj.time;
}

Date Datetime::getDate()
{
    return date;
}

Time Datetime::getTime()
{
    return time;
}

void Datetime::change(int day, int month, int year, int seconds, int minutes, int hours)
{
    date.set_day(day);
    date.set_month(month);
    date.set_year(year);
    time.setSecond(seconds);
    time.setMinute(minutes);
    time.setHour(hours);
}

void Datetime::change(int dayOrSecond, int monthOrMinutes, int yearOrHours, bool type)
{
    if (type == 0) {
        date.set_day(dayOrSecond);
        date.set_month(monthOrMinutes);
        date.set_year(yearOrHours);
        return;
    }
    time.setSecond(dayOrSecond);
    time.setMinute(monthOrMinutes);
    time.setHour(yearOrHours);
}

void Datetime::change(Date date, Time time)
{
    this->date = date;
    this->time = time;
}

string Datetime::getDatetimeStr()
{
    string out = date.to_str();
    out += " ";
    out += time.toStr();
    return out;
}

void Datetime::show()
{
    cout << getDatetimeStr() << "\n";
}

bool Datetime::operator==(Datetime obj)
{
    if (time == obj.getTime() && date == obj.getDate())
        return true;
    return false;
}

bool Datetime::operator!=(Datetime obj)
{
    return !(*this == obj);
}

bool Datetime::operator>=(Datetime obj)
{
    if (date >= obj.getDate() && time >= obj.getTime() ||
        date >= obj.getDate() && time == obj.getTime() || 
        date == obj.getDate() && time >= obj.getTime())
        return true;
    return false;
}

bool Datetime::operator<=(Datetime obj)
{
    if (date <= obj.getDate() && time <= obj.getTime() ||
        date <= obj.getDate() && time == obj.getTime() ||
        date == obj.getDate() && time <= obj.getTime())
        return true;
    return false;
}

bool Datetime::operator>(Datetime obj)
{
    if (date > obj.getDate() && time > obj.getTime() ||
        date == obj.getDate() && time > obj.getTime() ||
        date > obj.getDate() && time == obj.getTime())
        return true;
    return false;
}

bool Datetime::operator<(Datetime obj)
{
    if (date < obj.getDate() && time < obj.getTime() ||
        date == obj.getDate() && time < obj.getTime() ||
        date < obj.getDate() && time == obj.getTime())
        return true;
    return false;
}

void Datetime::operator=(Datetime obj)
{
    date = obj.getDate();
    time = obj.getTime();
}

void Datetime::operator=(Date obj)
{
    date = obj;
}

void Datetime::operator=(Time obj)
{
    time = obj;
}
