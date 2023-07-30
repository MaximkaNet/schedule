#include "Pair.h"

Pair::Pair()
{
    ID = -1;
    number = -1;
    numberClassroom = -1;
    IDSubject = -1;
    IDGroup = -1;
    IDTeacher = -1;
    isDelete = false;
}

Pair::Pair(int number, Datetime start, Datetime finish, int numberClassroom, int IDSubject, int IDGroup, int IDTeacher)
{
    ID = -1;
    isDelete = false;
    this->number = number;
    this->start = start;
    this->finish = finish;
    this->numberClassroom = numberClassroom;
    this->IDSubject = IDSubject;
    this->IDGroup = IDGroup;
    this->IDTeacher = IDTeacher;
}

Pair::Pair(int number, Date dateStart, Time timeStart, Date dateFinish, Time timeFinish, int numberClassroom, int IDSubject, int IDGroup, int IDTeacher)
{
    ID = -1;
    isDelete = false;
    this->number = number;
    setStart(dateStart, timeStart);
    setFinish(dateFinish, timeFinish);
    this->numberClassroom = numberClassroom;
    this->IDSubject = IDSubject;
    this->IDGroup = IDGroup;
    this->IDTeacher = IDTeacher;
}

Pair::Pair(const Pair& obj)
{
    ID = obj.ID;
    number = obj.number;
    start = obj.start;
    finish = obj.finish;
    numberClassroom = obj.numberClassroom;
    IDSubject = obj.IDSubject;
    IDGroup = obj.IDGroup;
    IDTeacher = obj.IDTeacher;
    isDelete = obj.isDelete;
}

int Pair::getID()
{
    return ID;
}

int Pair::getNumber()
{
    return number;
}

Datetime Pair::getStart()
{
    return start;
}

Datetime Pair::getFinish()
{
    return finish;
}

int Pair::getNumberClassroom()
{
    return numberClassroom;
}

Date Pair::getDate()
{
    return start.getDate();
}

int Pair::getIDSubject()
{
    return IDSubject;
}

int Pair::getIDGroup()
{
    return IDGroup;
}

int Pair::getIDTeacher()
{
    return IDTeacher;
}

bool Pair::getIsDelete()
{
   return isDelete;
}

void Pair::setNumber(int number)
{
    if(number > 0)
        this->number = number;
    throw string("ValNotCorrect");
}

void Pair::setStart(Datetime start)
{
    if(start.getDate().isEmpty() && start.getTime().isEmpty() || start >= finish)
        throw string("ValNotCorrect");
    this->start = start;
}

void Pair::setStart(Date dateStart, Time timeStart)
{
    if (dateStart.isEmpty() && timeStart.isEmpty() || finish.getDate() < dateStart || timeStart >= finish.getTime())
        throw string("ValNotCorrect");
    start = Datetime(dateStart, timeStart);
}

void Pair::setFinish(Datetime finish)
{
    if (finish.getDate().isEmpty() && finish.getTime().isEmpty() || finish <= start)
        throw string("ValNotCorrect");
    this->finish = finish;
}

void Pair::setFinish(Date dateFinish, Time timeFinish)
{
    if (dateFinish.isEmpty() && timeFinish.isEmpty() || start.getDate() > dateFinish || timeFinish <= start.getTime())
        throw string("ValNotCorrect");
    finish = Datetime(dateFinish, timeFinish);
}

void Pair::setNumberClassroom(int numberClassroom)
{
    if (numberClassroom > 0)
        this->numberClassroom = numberClassroom;
    throw string("ValNotCorrect");
}

void Pair::setIDSubject(int IDSubject, vector<int> DBSubjects)
{
    int length = DBSubjects.size();
    for (int i = 0; i < length; i++)
    {
        if (IDSubject == DBSubjects[i]) {
            this->IDSubject = IDSubject;
            return;
        }
    }
    cout << "Subject not found!\n";
}

void Pair::setIDGroup(int IDGroup, vector<int> DBGroups)
{
    int length = DBGroups.size();
    for (int i = 0; i < length; i++)
    {
        if (IDGroup == DBGroups[i]) {
            this->IDGroup = IDGroup;
            return;
        }
    }
    cout << "Group not found!\n";
}

void Pair::setIDTeacher(int IDTeacher, vector<int> DBTeachers)
{
    int length = DBTeachers.size();
    for (int i = 0; i < length; i++)
    {
        if (IDTeacher == DBTeachers[i]) {
            this->IDTeacher = IDTeacher;
            return;
        }
    }
    cout << "Group not found!\n";
}

void Pair::show(vector<Teacher> DBTeachers, vector<Subject> DBSubjects)
{
    int length = DBSubjects.size();
    bool hasObj = false;
    for (int i = 0; i < length; i++)
    {
        if (IDSubject == DBSubjects[i].getID() && IDSubject != -1 && DBSubjects[i].getIsDelete() == false) {
            cout << "Subject: " << DBSubjects[i].getName() << "\n";
            hasObj = true;
        }
    }
    if (hasObj == false) {
        cout << "Subject: not found\n";
    }
    cout << "Date: ";
    start.getDate().show();
    cout << "\n";
    length = DBTeachers.size();
    hasObj = false;
    for (int i = 0; i < length; i++)
    {
        if (IDTeacher == DBTeachers[i].getID() && DBTeachers[i].getIsDelete() == false) {
            cout << "Teacher: " << DBTeachers[i].getSurname() << " " << DBTeachers[i].getName() << " " << DBTeachers[i].getPatronymic() << "\n";
            hasObj = true;
        }
    }
    if (!hasObj) {
        cout << "Teacher: not found\n";
    }
    cout << "Number classroom: " << numberClassroom << "\n";
    cout << "Time: " << start.getTime().getHour() / 10 << start.getTime().getHour() % 10 << ":";
    cout << start.getTime().getMinute() / 10 << start.getTime().getMinute() % 10 << " - ";
    cout << finish.getTime().getHour() / 10 << finish.getTime().getHour() % 10 << ":";
    cout << finish.getTime().getMinute() / 10 << finish.getTime().getMinute() % 10 << "\n";
}

bool Pair::isEmpty()
{
    if (number == -1 && numberClassroom == -1 && IDSubject == -1 && IDGroup == -1 && IDTeacher == -1 && (start.getDate().isEmpty() || start.getTime().isEmpty()) && (finish.getDate().isEmpty() || finish.getTime().isEmpty()))
        return true;
    return false;
}

Pair Pair::create(vector<Teacher> DBTeachers, vector<Subject> DBSubjects, vector<Group> DBGroups)
{
   int number, numberClassroom, IDSubject, IDGroup, IDTeacher;
   Datetime start, finish;

   int chGroup;
   int chSubject;
   int chTeacher;

   while (true)
   {
      Menu groups("Number group: ");
      int length = DBGroups.size();
      for (int i = 0; i < length; i++)
      {
         groups.addSection(DBGroups[i].getName());
      }
      chGroup = groups();
      if (chGroup != 0) {
         chGroup -= 1;
         IDGroup = DBGroups[chGroup].getID();
         break;
      }
      else
         return Pair();
      system("cls");
   }
   bool hasSubject = false;
   bool hasTeacher = false;
   while (true)
   {
      Menu subjects("Number subject: ");
      int length = DBSubjects.size();
      for (int i = 0; i < length; i++)
      {
         int lengthSubjectsInGroup = DBGroups[chGroup].getSubjects().size();
         for (int j = 0; j < lengthSubjectsInGroup; j++)
         {
            if (DBSubjects[i].getID() == DBGroups[chGroup].getSubjects()[i]) {
               hasSubject = true;
               subjects.addSection(DBSubjects[i].getName());
            }
         }
      }
      if (hasSubject == false)
      {
         cout << "Subject not found in group!\n";
         system("pause");
         return Pair();
      }
      chSubject = subjects();
      if (chSubject != 0) {
         chSubject -= 1;
         IDSubject = DBSubjects[chSubject].getID();
         break;
      }
      else
         return Pair();
      system("cls");
   }

   while (true)
   {
      Menu teachers("Number teacher: ");
      int length = DBTeachers.size();
      for (int i = 0; i < length; i++)
      {
         int lengthSubjectsInTeacher = DBTeachers[i].getSubjects().size();
         for (int j = 0; j < lengthSubjectsInTeacher; j++)
         {
            if (DBTeachers[i].getSubjects()[j] == DBSubjects[chSubject].getID())
            {
               hasTeacher = true;
               teachers.addSection(DBTeachers[i].getFIO());
            }
         }
      }
      if (hasTeacher == false) {
         cout << "Teacher not found with this subject!\n";
         system("pause");
         return Pair();
      }
      chTeacher = teachers();
      if (chTeacher != 0) {
         chTeacher -= 1;
         IDTeacher = DBTeachers[chTeacher].getID();
         break;
      }
      else
         return Pair();
      system("cls");
   }

   cout << "Number: ";
   cin >> number;
   cout << "Number classroom: ";
   cin >> numberClassroom;
   cout << "Date: \n";
   int day, month, year;
   while (true)
   {
      try
      {
         cout << "Day: ";
         cin >> day;
         cout << "Month: ";
         cin >> month;
         cout << "Year: ";
         cin >> year;
         start.change(Date(day,month,year), Time());
         break;
      }
      catch (const string& exeption) {
         if (exeption == "ValNotCorrect")
            cout << "Please, enter correct values\n";
      }
   }
   finish = start.getDate();
   cout << "Time start: \n";
   int minute, hour;
   cout << "Hour: ";
   cin >> hour;
   cout << "Minute: ";
   cin >> minute;
   start.change(0, minute, hour, true);
   cout << "Time finish: \n";
   cout << "Hour: ";
   cin >> hour;
   cout << "Minute: ";
   cin >> minute;
   finish.change(0, minute, hour, true);
   return Pair(number, start, finish, numberClassroom, IDSubject, IDGroup, IDTeacher);
}

bool Pair::operator==(Pair obj)
{
    if (number == obj.getNumber() &&
        numberClassroom == obj.getNumberClassroom() &&
        IDSubject == obj.getIDSubject() &&
        IDGroup == obj.getIDGroup() &&
        IDTeacher == obj.getIDTeacher() &&
        start == obj.getStart() &&
        finish == obj.getFinish())
        return true;
    return false;
}
