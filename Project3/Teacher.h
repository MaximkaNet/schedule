#pragma once
#include "Person.h"
#include "Subject.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::getline;
using std::cin;
using std::sort;

class Teacher :
    public Person
{
private:
    string position;
    string speciality;
    vector<int> subjects;
public:
    Teacher();
    Teacher(string name, string surname, string patronymic, Date birthday, map<string, string> additional, string position, string speciality, vector<int> subjects);
    Teacher(string name, string surname, string patronymic, Date birthday, string position, string speciality);
    Teacher(const Teacher& obj);

    string getPosition();
    string getSpeciality();
    vector<int> getSubjects();

    void setPosition(string name);
    void setSpeciality(string name);

    void addSubject(int idSubject);
    void removeSubject(int idSubject);

    void show(vector<Subject> DBsubjects);
    string toStr();

    static Teacher create();

    bool operator== (Teacher obj);
    bool operator!= (Teacher obj);
};

