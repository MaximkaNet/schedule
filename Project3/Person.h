#pragma once
#include "Date.h"
#include <string>
#include <map>
#include <algorithm>

using std::string;
using std::map;
using std::piecewise_construct;
using std::cout;
using std::sort;

class Person
{
    friend class Database;
protected:
    int ID;
    string name;
    string surname;
    string patronymic;
    bool isDelete;
    Date birthday;
    map<string, string> additional;
    string login;
    string password;
public:
    Person();
    Person(string name, string surname, string patronymic, Date birthday, map<string, string> additional);
    Person(string name, string surname, string patronymic, Date birthday);
    Person(const Person& obj);

    int getID();
    string getLogin();
    string getName();
    string getSurname();
    string getPatronymic();
    string getFIO();
    Date getBirthday();
    map<string, string> getAdditional();
    bool getIsDelete();

    void addAdditional(string name, string value);
    void changeAdditional(string name, string value);
    void delAdditional(string name);

    void changeBirthday(Date obj);
    void changeBirthday(int day, int month, int year);
    bool changePassword(string oldPassword ,string newPassword);

    bool isEmpty();
};

