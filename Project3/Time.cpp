#include "Time.h"

Time::Time()
{
    hour = minute = second = 0;
}

Time::Time(int hour, int minute, int second)
{
    if (hour > 23) {
        this->hour = 23;
    }
    else if(hour < 0){
        this->hour = 0;
    }
    else {
        this->hour = hour;
    }
    if (minute > 59) {
        this->minute = 59;
    }
    else if (hour < 0) {
        this->minute = 0;
    }
    else {
        this->minute = minute;
    }
    if (second > 59) {
        this->second = 59;
    }
    else if (second < 0) {
        this->second = 0;
    }
    else {
        this->second = second;
    }
}

Time::Time(const Time& obj)
{
    this->hour = obj.hour;
    this->minute = obj.minute;
    this->second = obj.second;
}

int Time::getHour()
{
    return hour;
}

int Time::getMinute()
{
    return minute;
}

int Time::getSecond()
{
    return second;
}

void Time::setHour(int hour)
{
    if (hour > 23) {
        this->hour = 23;
    }
    else if (hour < 0) {
        this->hour = 0;
    }
    else
    {
       this->hour = hour;
    }
}

void Time::setMinute(int minute)
{
    if (minute > 59) {
        this->minute = 59;
    }
    else if (minute < 0) {
        this->minute = 0;
    }
    else {
        this->minute = minute;
    }
}

void Time::setSecond(int second)
{
    if (second > 59) {
        this->second = 59;
    }
    else if (second < 0) {
        this->second = 0;
    }
    else {
        this->second = second;
    }
}

void Time::show()
{
    cout << hour / 10 << hour % 10 << ":";
    cout << minute / 10 << minute % 10 << ":";
    cout << second / 10 << second % 10 << "\n";
}

string Time::toStr()
{
    string out;
    out += to_string(hour / 10);
    out += to_string(hour % 10);
    out += ":";
    out += to_string(minute / 10);
    out += to_string(minute % 10);
    out += ":";
    out += to_string(second / 10);
    out += to_string(second % 10);
    return out;
}

bool Time::isEmpty()
{
    if (hour != 0 && minute != 0 && second != 0)
        return true;
    return false;
}

void Time::autoFill()
{
   // создаем стд объект даты и времени 
   struct tm* tim = new tm;
   // определяем текущую млисекунду 
   time_t tt = time(NULL);
   //заполняем все поля стд структуры 
   localtime_s(tim, &tt);
   //заполняем нужные поля нашей структуры 
   hour = tim->tm_hour;
   minute = tim->tm_min;
   second = tim->tm_sec;
}

bool Time::operator==(Time obj)
{
    if (hour == obj.getHour()) {
        if (minute == obj.getMinute()) {
            if (second = obj.getSecond()) {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    return false;
}

bool Time::operator!=(Time obj)
{
    return !(*this == obj);
}

bool Time::operator>=(Time obj)
{
    if (*this > obj || *this == obj)
        return true;
    return false;
}

bool Time::operator<=(Time obj)
{
    if (*this < obj || *this == obj)
        return true;
    return false;
}

bool Time::operator>(Time obj)
{
    if (second > obj.getSecond() && minute == obj.getMinute() && hour == obj.getHour() || 
        second == obj.getSecond() && minute > obj.getMinute() && hour == obj.getHour() || 
        second == obj.getSecond() && minute == obj.getMinute() && hour > obj.getHour() ||
        second > obj.getSecond() && minute > obj.getMinute() && hour > obj.getHour())
        return true;
    return false;
}

bool Time::operator<(Time obj)
{
    if (second < obj.getSecond() && minute == obj.getMinute() && hour == obj.getHour() ||
        second == obj.getSecond() && minute < obj.getMinute() && hour == obj.getHour() ||
        second == obj.getSecond() && minute == obj.getMinute() && hour < obj.getHour() ||
        second < obj.getSecond() && minute < obj.getMinute() && hour < obj.getHour())
        return true;
    return false;
}

Time& Time::operator=(Time obj)
{
    hour = obj.getHour();
    minute = obj.getMinute();
    second = obj.getSecond();
    return *this;
}
