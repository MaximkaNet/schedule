#include "Database.h"

void Database::loadOptions()
{
   FILE* file;
   fopen_s(&file, nameFile_Options.c_str(), "rb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_OPTIONS");
   }
   for (int i = 0; i < countTables; i++)
   {
      int data;
      fread(&data, sizeof(data), 1, file);
      lastID_table[i] = data;
   }
   fclose(file);
}

void Database::loadTeachers()
{
   FILE* file;
   fopen_s(&file, nameFile_Teachers.c_str(), "rb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_TEACHERS");
   }

   int tchSize = 0;
   fread(&tchSize, sizeof(tchSize), 1, file);
   for (int i = 0; i < tchSize; i++)
   {
      // write ID
      int ID = 0;
      fread(&ID, sizeof(ID), 1, file);

      //Get values
      bool isDelete;
      string name;
      string surname;
      string patronymic;
      string login;
      string password;
      int day;
      int month;
      int year;

      //write values
      fread(&isDelete, sizeof(isDelete), 1, file);

      char* buffer = nullptr;
      int size = 1;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      login = buffer;
      delete[]buffer;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      password = buffer;
      delete[]buffer;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      name = buffer;
      delete[]buffer;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      surname = buffer;
      delete[]buffer;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      patronymic = buffer;
      delete[]buffer;

      fread(&day, sizeof(day), 1, file);
      fread(&month, sizeof(month), 1, file);
      fread(&year, sizeof(year), 1, file);

      map<string, string> additional;

      int sizeAdditional = 0;
      fread(&sizeAdditional, sizeof(int), 1, file);
      if (sizeAdditional != 0)
      {
         for (int j = 0; j < sizeAdditional; j++)
         {
            int sizeAdditionalElement = 0;
            string first;
            string second;

            fread(&size, sizeof(int), 1, file);
            buffer = new char[size + 1]{};
            fread(&*buffer, sizeof(char) * size, 1, file);
            first = buffer;
            delete[]buffer;

            fread(&size, sizeof(int), 1, file);
            buffer = new char[size + 1]{};
            fread(&*buffer, sizeof(char) * size, 1, file);
            second = buffer;
            delete[]buffer;

            additional.emplace(piecewise_construct, forward_as_tuple(first), forward_as_tuple(second));
         }
      }

      //get values
      string position;
      string speciality;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      position = buffer;
      delete[]buffer;

      if (position == "NOT_FOUND")
         position.clear();

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      speciality = buffer;
      delete[]buffer;

      if (speciality == "NOT_FOUND")
         speciality.clear();

      vector<int> subjects;
      int length;

      fread(&length, sizeof(int), 1, file);

      if (length != 0)
      {
         for (int i = 0; i < length; i++)
         {
            int data;
            fread(&data, sizeof(data), 1, file);
            subjects.push_back(data);
         }
      }

      Teacher temp(name, surname, patronymic, Date(day, month, year), additional, position, speciality, subjects);
      temp.isDelete = isDelete;
      temp.ID = ID;
      temp.login = login;
      temp.password = password;
      teachers.emplace(piecewise_construct, forward_as_tuple(ID), forward_as_tuple(temp));
   }
   fclose(file);
}

void Database::loadStudents()
{
   FILE* file;
   fopen_s(&file, nameFile_Students.c_str(), "rb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_STUDENTS");
   }

   int studSize = 0;
   fread(&studSize, sizeof(studSize), 1, file);
   for (int i = 0; i < studSize; i++)
   {
      // write ID
      int ID = 0;
      fread(&ID, sizeof(ID), 1, file);

      //Get values
      bool isDelete;
      string name;
      string surname;
      string patronymic;
      string login;
      string password;
      int day;
      int month;
      int year;

      //write values
      fread(&isDelete, sizeof(isDelete), 1, file);

      char* buffer = nullptr;
      int size = 1;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      login = buffer;
      delete[]buffer;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      password = buffer;
      delete[]buffer;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      name = buffer;
      delete[]buffer;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      surname = buffer;
      delete[]buffer;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      patronymic = buffer;
      delete[]buffer;

      fread(&day, sizeof(day), 1, file);
      fread(&month, sizeof(month), 1, file);
      fread(&year, sizeof(year), 1, file);

      map<string, string> additional;

      int sizeAdditional = 0;
      fread(&sizeAdditional, sizeof(int), 1, file);
      if (sizeAdditional != 0)
      {
         for (int j = 0; j < sizeAdditional; j++)
         {
            int sizeAdditionalElement = 0;
            string first;
            string second;

            fread(&size, sizeof(int), 1, file);
            buffer = new char[size + 1]{};
            fread(&*buffer, sizeof(char) * size, 1, file);
            first = buffer;
            delete[]buffer;

            fread(&size, sizeof(int), 1, file);
            buffer = new char[size + 1]{};
            fread(&*buffer, sizeof(char) * size, 1, file);
            second = buffer;
            delete[]buffer;

            additional.emplace(piecewise_construct, forward_as_tuple(first), forward_as_tuple(second));
         }
      }
      int IDGroup;
      fread(&IDGroup, sizeof(int), 1, file);

      //get values
      string residencePlace;
      string studyPlace;

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      residencePlace = buffer;
      delete[]buffer;

      if (residencePlace == "NOT_FOUND")
         residencePlace.clear();

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      studyPlace = buffer;
      delete[]buffer;

      if (studyPlace == "NOT_FOUND")
         studyPlace.clear();

      Student temp(name, surname, patronymic, Date(day, month, year), IDGroup, studyPlace, residencePlace);
      temp.isDelete = isDelete;
      temp.ID = ID;
      temp.login = login;
      temp.password = password;
      students.emplace(piecewise_construct, forward_as_tuple(ID), forward_as_tuple(temp));
   }
   fclose(file);
}

void Database::loadGroups()
{
   FILE* file;
   fopen_s(&file, nameFile_Groups.c_str(), "rb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_GROUPS");
   }

   int groupSize = 0;
   fread(&groupSize, sizeof(groupSize), 1, file);
   for (int i = 0; i < groupSize; i++)
   {
      // write ID
      int ID = 0;
      fread(&ID, sizeof(ID), 1, file);

      //Get values
      bool isDelete;
      string name;
      int sizeSubjects;
      int sizeStudents;
      vector<int> subjects, students;
      char* buffer = nullptr;
      int size = 1;

      //write values
      fread(&isDelete, sizeof(isDelete), 1, file);

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      name = buffer;
      delete[]buffer;

      fread(&sizeSubjects, sizeof(int), 1, file);
      for (int j = 0; j < sizeSubjects; j++)
      {
         int data;
         fread(&data, sizeof(int), 1, file);
         subjects.push_back(data);
      }

      fread(&sizeStudents, sizeof(int), 1, file);
      for (int j = 0; j < sizeStudents; j++)
      {
         int data;
         fread(&data, sizeof(int), 1, file);
         students.push_back(data);
      }

      Group temp(name, subjects, students);
      temp.isDelete = isDelete;
      temp.ID = ID;
      groups.emplace(piecewise_construct, forward_as_tuple(ID), forward_as_tuple(temp));
   }
   fclose(file);
}

void Database::loadSubjects()
{
   FILE* file;
   fopen_s(&file, nameFile_Subjects.c_str(), "rb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_SUBJECTS");
   }

   int subjectSize = 0;
   fread(&subjectSize, sizeof(subjectSize), 1, file);
   for (int i = 0; i < subjectSize; i++)
   {
      // write ID
      int ID = 0;
      fread(&ID, sizeof(ID), 1, file);

      //Get values
      bool isDelete;
      string name;
      float termHours;

      char* buffer = nullptr;
      int size = 1;

      //write values
      fread(&isDelete, sizeof(isDelete), 1, file);

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      name = buffer;
      delete[]buffer;

      fread(&termHours, sizeof(termHours), 1, file);

      Subject temp(name, termHours);
      temp.isDelete = isDelete;
      temp.ID = ID;
      subjects.emplace(piecewise_construct, forward_as_tuple(ID), forward_as_tuple(temp));
   }
   fclose(file);
}

void Database::loadLessons()
{
   FILE* file;
   fopen_s(&file, nameFile_Lessons.c_str(), "rb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_LESSONS");
   }

   int lessonSize = 0;
   fread(&lessonSize, sizeof(lessonSize), 1, file);
   for (int i = 0; i < lessonSize; i++)
   {
      // write ID
      int ID = 0;
      fread(&ID, sizeof(ID), 1, file);

      //Get values
      bool isDelete;
      string topic;
      int IDPair;

      char* buffer = nullptr;
      int size = 1;

      //write values
      fread(&isDelete, sizeof(isDelete), 1, file);

      fread(&size, sizeof(int), 1, file);
      buffer = new char[size + 1]{};
      fread(&*buffer, sizeof(char) * size, 1, file);
      topic = buffer;
      delete[]buffer;

      fread(&IDPair, sizeof(int), 1, file);

      Lesson temp(topic, IDPair);
      temp.isDelete = isDelete;
      temp.ID = ID;
      lessons.emplace(piecewise_construct, forward_as_tuple(ID), forward_as_tuple(temp));
   }
   fclose(file);
}

void Database::loadPairs()
{
   FILE* file;
   fopen_s(&file, nameFile_Pairs.c_str(), "rb");
   if (file == NULL)
   {
      throw string("NOT_FOUND_PAIRS");
   }

   int lessonSize = 0;
   fread(&lessonSize, sizeof(lessonSize), 1, file);
   for (int i = 0; i < lessonSize; i++)
   {
      // write ID
      int ID = 0;
      fread(&ID, sizeof(ID), 1, file);

      //Get values
      bool isDelete;
      int number;
      int numberClassroom;
      int IDSubject;
      int IDGroup;
      int IDTeacher;
      Datetime start;
      Datetime finish;
      int day, month, year, seconds, minutes, hours;

      char* buffer = nullptr;
      int size = 1;

      //write values
      fread(&isDelete, sizeof(isDelete), 1, file);
      fread(&number, sizeof(int), 1, file);
      fread(&numberClassroom, sizeof(int), 1, file);
      fread(&IDSubject, sizeof(int), 1, file);
      fread(&IDGroup, sizeof(int), 1, file);
      fread(&IDTeacher, sizeof(int), 1, file);

      fread(&day, sizeof(int), 1, file);
      fread(&month, sizeof(int), 1, file);
      fread(&year, sizeof(int), 1, file);
      fread(&seconds, sizeof(int), 1, file);
      fread(&minutes, sizeof(int), 1, file);
      fread(&hours, sizeof(int), 1, file);

      start = Date(day, month, year);
      start = Time(hours, minutes, seconds);

      fread(&day, sizeof(int), 1, file);
      fread(&month, sizeof(int), 1, file);
      fread(&year, sizeof(int), 1, file);
      fread(&seconds, sizeof(int), 1, file);
      fread(&minutes, sizeof(int), 1, file);
      fread(&hours, sizeof(int), 1, file);

      finish = Date(day, month, year);
      finish = Time(hours, minutes, seconds);

      Pair temp(number, start, finish, numberClassroom, IDSubject, IDGroup, IDTeacher);
      temp.isDelete = isDelete;
      temp.ID = ID;
      pairs.emplace(piecewise_construct, forward_as_tuple(ID), forward_as_tuple(temp));
   }
   fclose(file);
}