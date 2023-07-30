#pragma once
#include "Teacher.h"
#include "Student.h"
#include "Group.h"
#include "Subject.h"
#include "Time.h"
#include "Lesson.h"
#include "Pair.h"

#include <vector>
#include <map>
#include <algorithm>

using std::map;
using std::vector;
using std::string;
using std::piecewise_construct;
using std::forward_as_tuple;
using std::fstream;

class Database {
   int countTables = 6;
   vector<int> lastID_table;
   map<int, Teacher> teachers;
   map<int, Student> students;
   map<int, Group> groups;
   map<int, Subject> subjects;
   map<int, Lesson> lessons;
   map<int, Pair> pairs;
   string nameFile_Teachers;
   string nameFile_Students;
   string nameFile_Groups;
   string nameFile_Subjects;
   string nameFile_Lessons;
   string nameFile_Pairs;
   string nameFile_Options;
   Database();
   static Database* instance;
   //создать сингелтон
public:
   static Database* getInstance();

   int getNextID(int numberTable);

   void save();
   void load();

   // saves
   void saveOptions();
   void saveTeachers();
   void saveStudents();
   void saveGroups();
   void saveSubjects();
   void saveLessons();
   void savePairs();

   //load
   void loadOptions();
   void loadTeachers();
   void loadStudents();
   void loadGroups();
   void loadSubjects();
   void loadLessons();
   void loadPairs();

   void addTeacher(Teacher obj);
   void addTeacherSubject(int ID, int IDSubject);
   void addAdditionalForTeacher(string first, string second, int IDTeacher);
   void addStudent(Student obj);
   void addStudentInGroup(int IDGroup, int IDStudent);
   void addAdditionalForStudent(string first, string second, int IDStudent);
   void addGroup(Group obj);
   void addSubject(Subject obj);
   void addSubjectInGroup(int IDGroup, int IDStudent);
   void addLesson(Lesson obj);
   void addPair(Pair obj);

   void removeTeacher(int ID);
   void removeTeacherSubject(int ID, int IDSubject);
   void removeAdditionalForTeacher(string name, int IDTeacher);
   void removeStudent(int ID);
   void removeStudentInGroup(int IDGroup, int IDStudent);
   void removeAdditionalForStudent(string name, int IDStudent);
   void removeGroup(int ID);
   void removeSubject(int ID);
   void removeSubjectInGroup(int IDGroup, int IDSubject);
   void removeLesson(int ID);
   void removePair(int ID);

   void changeTeacherPassword(string oldPassword, string newPassword, int IDTeacher);
   void changeStudentPassword(string oldPassword, string newPassword, int IDStudent);

   /* Teacher */
   vector<Teacher> getTeachers();
   Teacher getTeacherByID(int ID);
   Teacher getTeacherByLogin(string login);
   vector<Teacher> getTeachersByName(string name);
   vector<Teacher> getTeachersBySurname(string surname);
   vector<Teacher> getTeachersByPatronymic(string patronymic);
   vector<Teacher> getTeachersByBirthday(Date birthday);

   /* Student */
   vector<Student> getStudents();
   Student getStudentByID(int ID);
   Student getStudentByLogin(string login);
   vector<Student> getStudentsByName(string name);
   vector<Student> getStudentsBySurname(string surname);
   vector<Student> getStudentsByPatronymic(string patronymic);
   vector<Student> getStudentsByBirthday(Date birthday);
   vector<Student> getStudentsByIDGroup(int IDGroup);

   /* Group */
   vector<Group> getGroups();
   Group getGroupByID(int ID);
   vector<Group> getGroupsByName(string name);

   /* Subject */
   vector<Subject> getSubjects();
   Subject getSubjectByID(int ID);
   vector<Subject> getSubjectsByName(string name);
   vector<Subject> getSubjectsByTermHours(float termHours);

   /* Lesson */
   vector<Lesson> getLessons();
   Lesson getLessonByID(int ID);
   vector<Lesson> getLessonsByIDPair(int IDPair);

   /* Pair */
   vector<Pair> getPairs();
   Pair getPairByID(int ID);
   vector<Pair> getPairsByNumber(int number);
   vector<Pair> getPairsByNumberClassroom(int numberClassroom);
   vector<Pair> getPairsByIDSubject(int IDSubject);
   vector<Pair> getPairsByIDGroup(int IDGroup);
   vector<Pair> getPairsByIDTeacher(int IDTeacher);
   vector<Pair> getPairsByDate(Date date);

   Teacher loginTeacher();
   Student loginStudent();
   static string loginGenerator(Person obj);
   static string getNameMonthByNumber(int number);
};
