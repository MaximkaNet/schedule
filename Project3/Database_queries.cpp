#include "Database.h"

vector<Teacher> Database::getTeachers()
{
   vector<Teacher> out;
   if (teachers.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

Teacher Database::getTeacherByID(int ID)
{
   Teacher temp;
   if (teachers.size() == 0) {
      return temp;
   }
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end())
   {
      if (it->second.getID() == ID && it->second.getIsDelete() == false) {
         return it->second;
      }
      it++;
   }
   return temp;
}

Teacher Database::getTeacherByLogin(string login)
{
   Teacher temp;
   if (teachers.size() == 0) {
      return temp;
   }
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end())
   {
      if (it->second.getLogin() == login && it->second.getIsDelete() == false) {
         return it->second;
      }
      it++;
   }
   return temp;
}

vector<Teacher> Database::getTeachersByName(string name)
{
   vector<Teacher> out;
   if (teachers.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->second.getName() == name && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Teacher> Database::getTeachersBySurname(string surname)
{
   vector<Teacher> out;
   if (teachers.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->second.getSurname() == surname && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Teacher> Database::getTeachersByPatronymic(string patronymic)
{
   vector<Teacher> out;
   if (teachers.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->second.getPatronymic() == patronymic && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Teacher> Database::getTeachersByBirthday(Date birthday)
{
   vector<Teacher> out;
   if (teachers.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->second.getBirthday() == birthday && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Teacher temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Student> Database::getStudents()
{
   vector<Student> out;
   if (students.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

Student Database::getStudentByID(int ID)
{
   Student temp;
   if (students.size() == 0) {
      return temp;
   }
   map<int, Student>::iterator it = students.begin();
   while (it != students.end())
   {
      if (it->second.getID() == ID && it->second.getIsDelete() == false) {
         return it->second;
      }
      it++;
   }
   return temp;
}

Student Database::getStudentByLogin(string login)
{
   Student temp;
   if (students.size() == 0) {
      return temp;
   }
   map<int, Student>::iterator it = students.begin();
   while (it != students.end())
   {
      if (it->second.getLogin() == login && it->second.getIsDelete() == false) {
         return it->second;
      }
      it++;
   }
   return temp;
}

vector<Student> Database::getStudentsByName(string name)
{
   vector<Student> out;
   if (students.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->second.getName() == name && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Student> Database::getStudentsBySurname(string surname)
{
   vector<Student> out;
   if (students.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->second.getSurname() == surname && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Student> Database::getStudentsByPatronymic(string patronymic)
{
   vector<Student> out;
   if (students.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->second.getPatronymic() == patronymic && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Student> Database::getStudentsByBirthday(Date birthday)
{
   vector<Student> out;
   if (students.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->second.getBirthday() == birthday && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Student> Database::getStudentsByIDGroup(int IDGroup)
{
   vector<Student> out;
   if (students.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->second.getIDGroup() == IDGroup && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Student temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Group> Database::getGroups()
{
   vector<Group> out;
   if (groups.size() == 0) {
      Group temp;
      out.push_back(temp);
      return out;
   }
   map<int, Group>::iterator it = groups.begin();
   while (it != groups.end()) {
      if (it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Group temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

Group Database::getGroupByID(int ID)
{
   Group temp;
   if (groups.size() == 0) {
      return temp;
   }
   map<int, Group>::iterator it = groups.begin();
   while (it != groups.end())
   {
      if (it->second.getID() == ID && it->second.getIsDelete() == false) {
         return it->second;
      }
      it++;
   }
   return temp;
}

vector<Group> Database::getGroupsByName(string name)
{
   vector<Group> out;
   if (groups.size() == 0) {
      Group temp;
      out.push_back(temp);
      return out;
   }
   map<int, Group>::iterator it = groups.begin();
   while (it != groups.end()) {
      if (it->second.getName() == name && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Group temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Subject> Database::getSubjects()
{
   vector<Subject> out;
   if (subjects.size() == 0) {
      Subject temp;
      out.push_back(temp);
      return out;
   }
   map<int, Subject>::iterator it = subjects.begin();
   while (it != subjects.end()) {
      if (it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Subject temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

Subject Database::getSubjectByID(int ID)
{
   Subject temp;
   if (subjects.size() == 0) {
      return temp;
   }
   map<int, Subject>::iterator it = subjects.begin();
   while (it != subjects.end())
   {
      if (it->second.getID() == ID && it->second.getIsDelete() == false) {
         return it->second;
      }
      it++;
   }
   return temp;
}

vector<Subject> Database::getSubjectsByName(string name)
{
   vector<Subject> out;
   if (subjects.size() == 0) {
      Subject temp;
      out.push_back(temp);
      return out;
   }
   map<int, Subject>::iterator it = subjects.begin();
   while (it != subjects.end()) {
      if (it->second.getName() == name && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Subject temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Subject> Database::getSubjectsByTermHours(float termHours)
{
   vector<Subject> out;
   if (subjects.size() == 0) {
      Subject temp;
      out.push_back(temp);
      return out;
   }
   map<int, Subject>::iterator it = subjects.begin();
   while (it != subjects.end()) {
      if (it->second.getTermHours() == termHours && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Subject temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Lesson> Database::getLessons()
{
   vector<Lesson> out;
   if (lessons.size() == 0) {
      Lesson temp;
      out.push_back(temp);
      return out;
   }
   map<int, Lesson>::iterator it = lessons.begin();
   while (it != lessons.end()) {
      if (it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Lesson temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

Lesson Database::getLessonByID(int ID)
{
   Lesson temp;
   if (lessons.size() == 0) {
      return temp;
   }
   map<int, Lesson>::iterator it = lessons.begin();
   while (it != lessons.end())
   {
      if (it->second.getID() == ID && it->second.getIsDelete() == false) {
         return it->second;
      }
      it++;
   }
   return temp;
}

vector<Lesson> Database::getLessonsByIDPair(int IDPair)
{
   vector<Lesson> out;
   if (lessons.size() == 0) {
      Lesson temp;
      out.push_back(temp);
      return out;
   }
   map<int, Lesson>::iterator it = lessons.begin();
   while (it != lessons.end()) {
      if (it->second.getIDPair() == IDPair && it->second.getIsDelete() == false) {
         out.push_back(it->second);
      }
      it++;
   }
   if (out.size() == 0) {
      Lesson temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Pair> Database::getPairs()
{
   vector<Pair> out;
   if (pairs.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end()) {
      if (it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

Pair Database::getPairByID(int ID)
{
   Pair out;
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end()) {
      if (it->second.getID() == ID && it->second.getIsDelete() == false)
         return it->second;
      it++;
   }
   return out;
}

vector<Pair> Database::getPairsByNumber(int number)
{
   vector<Pair> out;
   if (pairs.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end()) {
      if (it->second.getNumber() == number && it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Pair> Database::getPairsByNumberClassroom(int numberClassroom)
{
   vector<Pair> out;
   if (pairs.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end()) {
      if (it->second.getNumberClassroom() == numberClassroom && it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Pair> Database::getPairsByIDSubject(int IDSubject)
{
   vector<Pair> out;
   if (pairs.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end()) {
      if (it->second.getIDSubject() == IDSubject && it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Pair> Database::getPairsByIDGroup(int IDGroup)
{
   vector<Pair> out;
   if (pairs.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end()) {
      if (it->second.getIDGroup() == IDGroup && it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Pair> Database::getPairsByIDTeacher(int IDTeacher)
{
   vector<Pair> out;
   if (pairs.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end()) {
      if (it->second.getIDTeacher() == IDTeacher && it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   return out;
}

vector<Pair> Database::getPairsByDate(Date date)
{
   vector<Pair> out;
   if (pairs.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end()) {
      if (it->second.getDate() == date && it->second.getIsDelete() == false)
         out.push_back(it->second);
      it++;
   }
   if (out.size() == 0) {
      Pair temp;
      out.push_back(temp);
      return out;
   }
   return out;
}