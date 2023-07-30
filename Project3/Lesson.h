#pragma once

#include "Pair.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
class Lesson
{
    friend class Database;
    int ID;
    string topic;
    int IDPair;
    bool isDelete;
public:
    Lesson();
    Lesson(string topic, int IDPair);
    Lesson(const Lesson& obj);

    int getID();
    int getIDPair();
    string getTopic();
    bool getIsDelete();

    void setTopic(string topic);
    void setIDPair(int IDPair, vector<Pair> DBPairs);

    void show(vector<Group> DBGroups, vector<Teacher> DBTeachers, vector<Subject> DBSubjects, vector<Pair> DBPairs);

    static Lesson create(int IDPair);

    bool operator== (Lesson obj);
    bool operator!= (Lesson obj);
};

