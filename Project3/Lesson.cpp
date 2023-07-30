#include "Lesson.h"

Lesson::Lesson()
{
    ID = -1;
    IDPair = -1;
    isDelete = false;
}

Lesson::Lesson(string topic, int IDPair)
{
    ID = -1;
    this->topic = topic;
    this->IDPair = IDPair;
    isDelete = false;
}

Lesson::Lesson(const Lesson& obj)
{
    ID = obj.ID;
    topic = obj.topic;
    IDPair = obj.IDPair;
    isDelete = obj.isDelete;
}

int Lesson::getID()
{
    return ID;
}

int Lesson::getIDPair()
{
    return IDPair;
}

string Lesson::getTopic()
{
    return topic;
}

bool Lesson::getIsDelete()
{
    return isDelete;
}

void Lesson::setTopic(string topic)
{
    if (topic.empty()) {
        cout << "Topic don't be empty!\n";
        return;
    }
    this->topic = topic;
}

void Lesson::setIDPair(int IDPair, vector<Pair> DBPairs)
{
    int length = DBPairs.size();
    for (int i = 0; i < length; i++)
    {
        if (DBPairs[i].getID() == IDPair) {
            this->IDPair = IDPair;
            return;
        }
    }
    cout << "Pair not found!\n";
}

void Lesson::show(vector<Group> DBGroups, vector<Teacher> DBTeachers, vector<Subject> DBSubjects, vector<Pair> DBPairs)
{
    bool flag = false;
    int length = DBPairs.size();
    Pair temp;
    for (int i = 0; i < length; i++)
    {
        if (DBPairs[i].getID() == IDPair) {
            flag = true;
            temp = DBPairs[i];
        }
    }
    if (flag) {
        cout << "Date: " << temp.getDate().to_str() << "\n";
        length = DBSubjects.size();
        int IDSubject = temp.getIDSubject();
        string nameSubject;
        for (int i = 0; i < length; i++)
        {
            if (IDSubject == DBSubjects[i].getID()) {
                nameSubject = DBSubjects[i].getName();
                break;
            }
        }
        if (nameSubject.empty())
            cout << "Subject: not found!\n";
        else
            cout << "Subject: " << nameSubject << "\n";
        cout << temp.getStart().getHour() / 10 << temp.getStart().getHour() % 10 << ":";
        cout << temp.getStart().getMinute() / 10 << temp.getStart().getMinute() % 10 << " - ";
        cout << temp.getFinish().getHour() / 10 << temp.getFinish().getHour() % 10 << ":";
        cout << temp.getFinish().getMinute() / 10 << temp.getFinish().getMinute() % 10 << "\n";
        cout << "Audience: " << temp.getNumberClassroom() << "\n";
        int IDTeacher = temp.getIDTeacher();
        string FIOTeacher;
        for (int i = 0; i < length; i++)
        {
            if (IDTeacher == DBTeachers[i].getID()) {
                FIOTeacher += DBTeachers[i].getFIO();
                break;
            }
        }
        if (FIOTeacher.empty())
            cout << "Teacher: not found!\n";
        else
            cout << "Teacher: " << FIOTeacher << "\n";
    }
    cout << "Pair not found!\n";
}

Lesson Lesson::create(int IDPair)
{
   string temp;
   while (true) {
      cout << "Topic: ";
      getline(cin, temp);
      if (temp.empty()) {
         cout << "Please, enter correct value\n";
      }
      else
         break;
   }

   return Lesson(temp, IDPair);
}

bool Lesson::operator==(Lesson obj)
{
    if (topic == obj.getTopic() && IDPair == obj.getIDPair())
        return true;
    return false;
}

bool Lesson::operator!=(Lesson obj)
{
    return !(*this == obj);
}
