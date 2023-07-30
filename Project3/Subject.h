#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::cout;
class Subject
{
    friend class Database;
    int ID;
    string name;
    float termHours;
    bool isDelete;
public:
    Subject();
    Subject(string name, float termHours);
    Subject(const Subject& obj);

    int getID();
    string getName();
    float getTermHours();
    bool getIsDelete();

    void setName(string name);
    void setTermHours(float termHours);

    void show();

    static Subject create();

    bool operator== (Subject obj);
    bool operator!= (Subject obj);
};

