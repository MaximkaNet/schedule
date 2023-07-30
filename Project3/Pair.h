#pragma once
#include "Datetime.h"
#include "Group.h"
#include "Subject.h"
#include "Teacher.h"
#include "Menu.h"

class Pair
{
    friend class Database;
    int ID;
    int number;
    int numberClassroom;
    int IDSubject;
    int IDGroup;
    int IDTeacher;
    bool isDelete;
    Datetime start;
    Datetime finish;
public:
    Pair();
    Pair(int number, Datetime start, Datetime finish, int numberClassroom, int IDSubject, int IDGroup, int IDTeacher);
    Pair(int number, Date dateStart, Time timeStart, Date dateFinish, Time timeFinish, int numberClassroom, int IDSubject, int IDGroup, int IDTeacher);
    Pair(const Pair& obj);

    int getID();
    int getNumber();
    Datetime getStart();
    Datetime getFinish();
    int getNumberClassroom();
    Date getDate();
    int getIDSubject();
    int getIDGroup();
    int getIDTeacher();
    bool getIsDelete();

    void setNumber(int number);
    void setStart(Datetime start);
    void setStart(Date dateStart, Time timeStart);
    void setFinish(Datetime finish);
    void setFinish(Date dateFinish, Time timeFinish);
    void setNumberClassroom(int numberClassroom);
    void setIDSubject(int IDSubject, vector<int> DBSubjects);
    void setIDGroup(int IDGroup, vector<int> DBGroups);
    void setIDTeacher(int IDTeacher, vector<int> DBTeachers);

    void show(vector<Teacher> DBTeachers, vector<Subject> DBSubjects);

    bool isEmpty();

    static Pair create(vector<Teacher> DBTeachers, vector<Subject> DBSubjects, vector<Group> DBGroups);
    
    bool operator== (Pair obj);
};

