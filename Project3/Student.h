#pragma once
#include "Group.h"
#include "Person.h"
#include <vector>
using std::vector;
using std::getline;
using std::cin;
class Student :
   public Person
{
   friend class Database;
   int IDGroup;
   string studyPlace;
   string residencePlace;
public:
   Student();
   Student(string name, string surname, string patronymic, Date birthday, map<string, string> additional, int IDGroup, string studyPlace, string residencePlace);
   Student(string name, string surname, string patronymic, Date birthday, int IDGroup, string studyPlace, string residencePlace);
   Student(const Student& obj);

   int getIDGroup();
   string getStudyPlace();
   string getResidencePlace();

   void setStudyPlace(string studyPlace);
   void setResidencePlace(string residencePlace);

   void show();

   static Student create();

   bool operator==(Student obj);
   bool operator!= (Student obj);
};