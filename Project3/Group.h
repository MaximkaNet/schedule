#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::sort;
class Group
{
    friend class Database;
    int ID;
    string name;
    bool isDelete;
    vector<int> subjects;
    vector<int> students;
public:
    Group();
    Group(string name);
    Group(string name, vector<int> subjects, vector<int> students);
    Group(const Group& obj);

    int getID();
    string getName();
    vector<int> getSubjects();
    vector<int> getStudents();
    bool getIsDelete();

    void setName(string name);

    void addSubject(int IDSubject);
    void addStudent(int IDStudent);

    void delSubject(int IDSubject);
    void delStudent(int IDStudent);

    static Group create();

    bool operator== (Group obj);
};

