#include "Group.h"

Group::Group()
{
    ID = -1;
    isDelete = false;
}

Group::Group(string name)
{
    ID = -1;
    this->name = name;
    isDelete = false;
}

Group::Group(string name, vector<int> subjects, vector<int> students)
{
    ID = -1;
    this->name = name;
    this->subjects = subjects;
    this->students = students;
    isDelete = false;
}
Group::Group(const Group& obj) {
    ID = obj.ID;
    name = obj.name;
    subjects = obj.subjects;
    students = obj.students;
    isDelete = obj.isDelete;
}

int Group::getID()
{
    return ID;
}

string Group::getName()
{
    return name;
}

vector<int> Group::getSubjects()
{
    return subjects;
}

vector<int> Group::getStudents()
{
    return students;
}

bool Group::getIsDelete()
{
    return isDelete;
}

void Group::setName(string name)
{
    if (name.empty()) {
        cout << "Name is empty!\n";
        return;
    }
    this->name = name;
}

void Group::addSubject(int IDSubject)
{
   if (IDSubject < 0) {
      cout << "ID subject less 0 !\n";
      return;
   }
   subjects.push_back(IDSubject);
   sort(subjects.begin(), subjects.end());
}

void Group::addStudent(int IDStudent)
{
   if (IDStudent < 0) {
      cout << "ID student less 0 !\n";
      return;
   }
   students.push_back(IDStudent);
   sort(students.begin(), students.end());
}

void Group::delSubject(int IDSubject)
{
    vector<int>::iterator it = subjects.begin();
    while (it != subjects.end())
    {
        if (*it == IDSubject) {
            subjects.erase(it);
            return;
        }
        it++;
    }
    cout << "Subject not found!\n";
}

void Group::delStudent(int IDStudent)
{
    vector<int>::iterator it = students.begin();
    while (it != students.end())
    {
        if (*it == IDStudent) {
            students.erase(it);
            return;
        }
        it++;
    }
    cout << "Student not found!\n";
}

Group Group::create()
{
   string name;
   cout << "Creating new group:\n";
   cout << "Name: ";
   std::getline(std::cin, name);
   return Group(name);
}

bool Group::operator==(Group obj)
{
   if (name == obj.getName())
      return true;
   return false;
}
