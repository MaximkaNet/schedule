#include "Database.h"

void Database::saveOptions()
{
   FILE* file;
   fopen_s(&file, nameFile_Options.c_str(), "wb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_OPTIONS");
   }
   for (int i = 0; i < countTables; i++)
   {
      int data = lastID_table[i];
      fwrite(&data, sizeof(data), 1, file);
   }
   fclose(file);
}

void Database::saveTeachers()
{
   FILE* file;
   fopen_s(&file, nameFile_Teachers.c_str(), "wb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_TEACHERS");
   }

   int tchSize = teachers.size();
   fwrite(&tchSize, sizeof(tchSize), 1, file);
   if (teachers.size() != 0)
   {
      map<int, Teacher>::iterator itTch = teachers.begin();
      while (itTch != teachers.end()) {
         // write ID
         int ID = itTch->first;
         fwrite(&ID, sizeof(ID), 1, file);

         //Get values
         bool isDelete = itTch->second.getIsDelete();

         char* buffer = nullptr;
         int size = 1;

         int day = itTch->second.getBirthday().get_day();
         int month = itTch->second.getBirthday().get_month();
         int year = itTch->second.getBirthday().get_year();

         //write values
         fwrite(&isDelete, sizeof(isDelete), 1, file);

         size = itTch->second.getLogin().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itTch->second.getLogin().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         size = itTch->second.password.size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itTch->second.password.c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         size = itTch->second.getName().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itTch->second.getName().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         size = itTch->second.getSurname().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itTch->second.getSurname().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         size = itTch->second.getPatronymic().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itTch->second.getPatronymic().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         fwrite(&day, sizeof(day), 1, file);
         fwrite(&month, sizeof(month), 1, file);
         fwrite(&year, sizeof(year), 1, file);

         map<string, string> additional = itTch->second.getAdditional();

         int sizeAdditional = additional.size();
         fwrite(&sizeAdditional, sizeof(int), 1, file);
         if (additional.size() != 0)
         {
            map<string, string>::iterator it = additional.begin();
            while (it != additional.end()) {

               size = it->first.size();
               buffer = new char[size + 1]{};
               strcpy_s(buffer, sizeof(char) * size + 1, it->first.c_str());
               fwrite(&size, sizeof(int), 1, file);
               fwrite(&*buffer, sizeof(char) * size, 1, file);
               delete[]buffer;

               size = it->second.size();
               buffer = new char[size + 1]{};
               strcpy_s(buffer, sizeof(char) * size + 1, it->second.c_str());
               fwrite(&size, sizeof(int), 1, file);
               fwrite(&*buffer, sizeof(char) * size, 1, file);
               delete[]buffer;

               it++;
            }
         }

         //get values
         string position = itTch->second.getPosition();
         string speciality = itTch->second.getSpeciality();
         string NOT_FOUND = "NOT_FOUND";

         if (position.empty())
            position = NOT_FOUND;

         size = position.size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, position.c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         if (speciality.empty())
            speciality = NOT_FOUND;

         size = speciality.size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, speciality.c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         vector<int> subjects = itTch->second.getSubjects();
         int length = subjects.size();

         fwrite(&length, sizeof(int), 1, file);

         if (length != 0)
         {
            for (int i = 0; i < length; i++)
            {
               fwrite(&subjects[i], sizeof(subjects[i]), 1, file);
            }
         }
         itTch++;
      }
   }
   fclose(file);
}

void Database::saveStudents()
{
   FILE* file;
   fopen_s(&file, nameFile_Students.c_str(), "wb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_STUDENTS");
   }

   int studSize = students.size();
   fwrite(&studSize, sizeof(studSize), 1, file);
   if (students.size() != 0)
   {
      map<int, Student>::iterator itStud = students.begin();
      while (itStud != students.end()) {
         // write ID
         int ID = itStud->first;
         fwrite(&ID, sizeof(ID), 1, file);

         //Get values
         bool isDelete = itStud->second.getIsDelete();

         char* buffer = nullptr;
         int size = 1;

         int day = itStud->second.getBirthday().get_day();
         int month = itStud->second.getBirthday().get_month();
         int year = itStud->second.getBirthday().get_year();

         //write values
         fwrite(&isDelete, sizeof(isDelete), 1, file);

         size = itStud->second.getLogin().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itStud->second.getLogin().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         size = itStud->second.password.size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itStud->second.password.c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         size = itStud->second.getName().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itStud->second.getName().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         size = itStud->second.getSurname().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itStud->second.getSurname().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         size = itStud->second.getPatronymic().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itStud->second.getPatronymic().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         fwrite(&day, sizeof(day), 1, file);
         fwrite(&month, sizeof(month), 1, file);
         fwrite(&year, sizeof(year), 1, file);

         map<string, string> additional = itStud->second.getAdditional();

         int sizeAdditional = additional.size();
         fwrite(&sizeAdditional, sizeof(int), 1, file);
         if (additional.size() != 0)
         {
            map<string, string>::iterator it = additional.begin();
            while (it != additional.end()) {

               size = it->first.size();
               buffer = new char[size + 1]{};
               strcpy_s(buffer, sizeof(char) * size + 1, it->first.c_str());
               fwrite(&size, sizeof(int), 1, file);
               fwrite(&*buffer, sizeof(char) * size, 1, file);
               delete[]buffer;

               size = it->second.size();
               buffer = new char[size + 1]{};
               strcpy_s(buffer, sizeof(char) * size + 1, it->second.c_str());
               fwrite(&size, sizeof(int), 1, file);
               fwrite(&*buffer, sizeof(char) * size, 1, file);
               delete[]buffer;

               it++;
            }
         }

         int IDGroup = itStud->second.getIDGroup();
         fwrite(&IDGroup, sizeof(int), 1, file);

         //get values
         string residencePlace = itStud->second.getResidencePlace();
         string studyPlace = itStud->second.getStudyPlace();
         string NOT_FOUND = "NOT_FOUND";

         if (residencePlace.empty())
            residencePlace = NOT_FOUND;

         size = residencePlace.size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, residencePlace.c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         if (studyPlace.empty())
            studyPlace = NOT_FOUND;

         size = studyPlace.size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, studyPlace.c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         itStud++;
      }
   }
   fclose(file);
}

void Database::saveGroups()
{
   FILE* file;
   fopen_s(&file, nameFile_Groups.c_str(), "wb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_GROUPS");
   }

   int groupSize = groups.size();
   fwrite(&groupSize, sizeof(groupSize), 1, file);
   if (groups.size() != 0)
   {
      map<int, Group>::iterator itGroup = groups.begin();
      while (itGroup != groups.end()) {
         // write ID
         int ID = itGroup->first;
         fwrite(&ID, sizeof(ID), 1, file);

         //Get values
         bool isDelete = itGroup->second.getIsDelete();

         char* buffer = nullptr;
         int size = 1;

         //write values
         fwrite(&isDelete, sizeof(isDelete), 1, file);

         size = itGroup->second.getName().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itGroup->second.getName().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         vector<int> subjects = itGroup->second.getSubjects();

         int sizeSubjects = subjects.size();
         fwrite(&sizeSubjects, sizeof(int), 1, file);
         for (int i = 0; i < sizeSubjects; i++)
         {
            fwrite(&subjects[i], sizeof(subjects[i]), 1, file);
         }

         vector<int> students = itGroup->second.getStudents();

         int sizeStudents = students.size();
         fwrite(&sizeStudents, sizeof(int), 1, file);
         for (int i = 0; i < sizeStudents; i++)
         {
            fwrite(&students[i], sizeof(students[i]), 1, file);
         }
         itGroup++;
      }
   }
   fclose(file);
}

void Database::saveSubjects()
{
   FILE* file;
   fopen_s(&file, nameFile_Subjects.c_str(), "wb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_SUBJECTS");
   }

   int subjectSize = subjects.size();
   fwrite(&subjectSize, sizeof(subjectSize), 1, file);
   if (subjectSize != 0)
   {
      map<int, Subject>::iterator itStubject = subjects.begin();
      while (itStubject != subjects.end()) {
         // write ID
         int ID = itStubject->first;
         fwrite(&ID, sizeof(ID), 1, file);

         //Get values
         bool isDelete = itStubject->second.getIsDelete();

         char* buffer = nullptr;
         int size = 1;

         //write values
         fwrite(&isDelete, sizeof(isDelete), 1, file);

         size = itStubject->second.getName().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itStubject->second.getName().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         float termHours = itStubject->second.getTermHours();

         fwrite(&termHours, sizeof(termHours), 1, file);

         itStubject++;
      }
   }
   fclose(file);
}

void Database::saveLessons()
{
   FILE* file;
   fopen_s(&file, nameFile_Lessons.c_str(), "wb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_LESSONS");
   }

   int lessonSize = lessons.size();
   fwrite(&lessonSize, sizeof(lessonSize), 1, file);
   if (lessonSize != 0)
   {
      map<int, Lesson>::iterator itLessons = lessons.begin();
      while (itLessons != lessons.end()) {
         // write ID
         int ID = itLessons->first;
         fwrite(&ID, sizeof(ID), 1, file);

         //Get values
         bool isDelete = itLessons->second.getIsDelete();

         char* buffer = nullptr;
         int size = 1;

         //write values
         fwrite(&isDelete, sizeof(isDelete), 1, file);

         size = itLessons->second.getTopic().size();
         buffer = new char[size + 1]{};
         strcpy_s(buffer, sizeof(char) * size + 1, itLessons->second.getTopic().c_str());
         fwrite(&size, sizeof(int), 1, file);
         fwrite(&*buffer, sizeof(char) * size, 1, file);
         delete[]buffer;

         int IDPair = itLessons->second.getIDPair();

         fwrite(&IDPair, sizeof(IDPair), 1, file);

         itLessons++;
      }
   }
   fclose(file);
}

void Database::savePairs()
{
   FILE* file;
   fopen_s(&file, nameFile_Pairs.c_str(), "wb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_PAIRS");
   }

   int pairSize = pairs.size();
   fwrite(&pairSize, sizeof(pairSize), 1, file);
   if (pairSize != 0)
   {
      map<int, Pair>::iterator itPair = pairs.begin();
      while (itPair != pairs.end()) {
         // write ID
         int ID = itPair->first;
         fwrite(&ID, sizeof(ID), 1, file);

         //Get values
         bool isDelete = itPair->second.getIsDelete();
         int number = itPair->second.getNumber();
         int numberClassroom = itPair->second.getNumberClassroom();
         int IDSubject = itPair->second.getIDSubject();
         int IDGroup = itPair->second.getIDGroup();
         int IDTeacher = itPair->second.getIDTeacher();
         int day, month, year, seconds, minutes, hours;

         char* buffer = nullptr;
         int size = 1;

         //write values
         fwrite(&isDelete, sizeof(isDelete), 1, file);
         fwrite(&number, sizeof(int), 1, file);
         fwrite(&numberClassroom, sizeof(int), 1, file);
         fwrite(&IDSubject, sizeof(int), 1, file);
         fwrite(&IDGroup, sizeof(int), 1, file);
         fwrite(&IDTeacher, sizeof(int), 1, file);

         // start 

         Date temp = itPair->second.getStart().getDate();
         Time temp2 = itPair->second.getStart().getTime();
         day = temp.get_day();
         month = temp.get_month();
         year = temp.get_year();
         seconds = temp2.getSecond();
         minutes = temp2.getMinute();
         hours = temp2.getHour();

         fwrite(&day, sizeof(int), 1, file);
         fwrite(&month, sizeof(int), 1, file);
         fwrite(&year, sizeof(int), 1, file);
         fwrite(&seconds, sizeof(int), 1, file);
         fwrite(&minutes, sizeof(int), 1, file);
         fwrite(&hours, sizeof(int), 1, file);

         // finish

         temp = itPair->second.getFinish().getDate();
         temp2 = itPair->second.getFinish().getTime();
         day = temp.get_day();
         month = temp.get_month();
         year = temp.get_year();
         seconds = temp2.getSecond();
         minutes = temp2.getMinute();
         hours = temp2.getHour();

         fwrite(&day, sizeof(int), 1, file);
         fwrite(&month, sizeof(int), 1, file);
         fwrite(&year, sizeof(int), 1, file);
         fwrite(&seconds, sizeof(int), 1, file);
         fwrite(&minutes, sizeof(int), 1, file);
         fwrite(&hours, sizeof(int), 1, file);

         itPair++;
      }
   }
   fclose(file);
}