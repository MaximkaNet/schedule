#include "Date.h"
bool Date::isLeapYear()
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? true : false;
}

int Date::daysInMonth()
{
    switch (month)
    {
    case 4:case 6:case 9:case 11:
        return 30;
    case 2:
        if (isLeapYear())
            return 29;
        return 28;
    default:
        return 31;
    }
    return 0;
}

Date::Date()
{
    day = 1, month = 1, year = 1;
}

Date::Date(const Date& obj)
{
    day = obj.day, month = obj.month, year = obj.year;
}

Date::Date(int day, int month, int year)
{
    try {
        set_day(day);
        set_month(month);
        this->year = year;
    }
    catch (std::string& exeption) {
        if (exeption == "ValNotCorrect") {
            this->day = this->month = this->year = 1;
            std::cout << "Object didn't created! All values reseted!\n";
        }
        return;
    }
    //std::cout << "Object success created!\n";
}

Date& Date::operator++()
{
    day++;
    if (day > daysInMonth())
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date& Date::operator++(int)
{
    Date* tmp = this;
    day++;
    if (day > daysInMonth())
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return *tmp;
}

Date& Date::operator--()
{
    day--;
    if (day < 1)
    {
        month--;
        if (month < 1)
        {
            month = 12;
            year--;
        }
        day = daysInMonth();
    }
    return *this;
}

Date& Date::operator--(int)
{
    Date* tmp = this;
    day--;
    if (day < 1)
    {
        month--;
        if (month < 1)
        {
            month = 12;
            year--;
        }
        day = daysInMonth();
    }
    return *tmp;
}

Date& Date::operator+(int count)
{
    for (int i = 0; i < count; i++)
    {
        (*this)++;
    }
    return *this;
}

Date& Date::operator-(int count)
{
    for (int i = 0; i < count; i++)
    {
        (*this)--;
    }
    return *this;
}

int Date::operator-(Date& obj)
{
    Date tmp = *this;
    int count = 0;
    if (*this < obj)
    {
        while (tmp != obj)
        {
            tmp++;
            count++;
        }
    }
    else
    {
        while (tmp != obj)
        {
            tmp--;
            count--;
        }
    }
    return count;
}

Date& Date::operator=(Date obj)
{
    day = obj.day, month = obj.month, year = obj.year;
    return *this;
}

bool Date::operator>(Date obj)
{
    if (this->year > obj.year
        ||
        this->year == obj.year &&
        this->month > obj.month
        ||
        this->year == obj.year &&
        this->month == obj.month &&
        this->day > obj.day)
        return true;
    return false;
}

bool Date::operator<(Date obj)
{
    if (this->year > obj.year
        ||
        this->year == obj.year &&
        this->month > obj.month
        ||
        this->year == obj.year &&
        this->month == obj.month &&
        this->day > obj.day)
        return false;
    return true;
}

bool Date::operator<=(Date obj)
{
    if (this->year > obj.year
        ||
        this->year == obj.year &&
        this->month > obj.month
        ||
        this->year == obj.year &&
        this->month == obj.month &&
        this->day >= obj.day)
        return true;
    return false;
}

bool Date::operator>=(Date obj)
{
    if (this->year > obj.year
        ||
        this->year == obj.year &&
        this->month > obj.month
        ||
        this->year == obj.year &&
        this->month == obj.month &&
        this->day >= obj.day)
        return false;
    return true;
}

bool Date::operator==(Date obj)
{
    if (this->year == obj.year &&
        this->month == obj.month &&
        this->day == obj.day)
        return true;
    return false;
}

bool Date::operator!=(Date obj)
{
    return !(*this == obj);
}

void Date::show()
{
    std::cout << day / 10 << day % 10 << "/" << month / 10 << month % 10 << "/" << year;
}

int Date::get_day()
{
    return day;
}

int Date::get_month()
{
    return month;
}

int Date::get_year()
{
    return year;
}

void Date::set_day(int day)
{
    if (day<1 || day>daysInMonth()) {
        throw std::string("ValNotCorrect");
    }
    this->day = day;
}

void Date::set_month(int month)
{
    if (month < 1 || month>12)
        throw std::string("ValNotCorrect");
    this->month = month;
}

void Date::set_year(int year)
{
    this->year = year;
}

string Date::to_str()
{
    std::string out;
    out += to_string(day);
    out += ".";
    out += to_string(month);
    out += ".";
    out += to_string(year);
    return out;
}

void Date::autoFill()
{
   // создаем стд объект даты и времени 
   struct tm* tim = new tm;
   // определяем текущую млисекунду 
   time_t tt = time(NULL);
   //заполняем все поля стд структуры 
   localtime_s(tim, &tt);
   //заполняем нужные поля нашей структуры 
   year = 1900 + tim->tm_year;
   month = 1 + tim->tm_mon;
   day = tim->tm_mday;
}

bool Date::isEmpty()
{
    if (day == month == year == 0)
        return true;
    return false;
}
