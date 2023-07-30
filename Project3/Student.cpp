#include "Student.h"

Student::Student()
{
    IDGroup = -1;
}

Student::Student(string name, string surname, string patronymic, Date birthday, map<string, string> additional, int IDGroup, string studyPlace, string residencePlace)
{
    this->ID = -1;
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->birthday = birthday;
    this->additional = additional;
    this->IDGroup = IDGroup;
    this->studyPlace = studyPlace;
    this->residencePlace = residencePlace;
}

Student::Student(string name, string surname, string patronymic, Date birthday, int IDGroup, string studyPlace, string residencePlace)
{
    this->ID = -1;
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->birthday = birthday;
    this->additional = additional;
    this->IDGroup = IDGroup;
    this->studyPlace = studyPlace;
    this->residencePlace = residencePlace;
}

Student::Student(const Student& obj)
{
    this->ID = obj.ID;
    this->name = obj.name;
    this->surname = obj.surname;
    this->patronymic = obj.patronymic;
    this->birthday = obj.birthday;
    this->additional = obj.additional;
    this->IDGroup = obj.IDGroup;
    this->studyPlace = obj.studyPlace;
    this->residencePlace = obj.residencePlace;
    this->login = obj.login;
    this->password = obj.password;
}

int Student::getIDGroup()
{
    return IDGroup;
}

string Student::getStudyPlace()
{
    return studyPlace;
}

string Student::getResidencePlace()
{
    return residencePlace;
}

void Student::setStudyPlace(string studyPlace)
{
    if (studyPlace.empty()) {
        return;
    }
    this->studyPlace = studyPlace;
}

void Student::setResidencePlace(string residencePlace)
{
    if (residencePlace.empty()) {
        return;
    }
    this->residencePlace = residencePlace;
}

void Student::show()
{
   cout << "Name: " << name << "\n";
   cout << "Surname: " << surname << "\n";
   cout << "Patronymic: " << patronymic << "\n";
   cout << "Birthday: ";
   birthday.show();
   cout << "\n";
   cout << "Additional: ";
   if (additional.size() == 0) {
      cout << "additional not found!\n";
   }
   else {
      cout << "\n";
      map<string, string>::iterator it = additional.begin();
      while (it != additional.end()) {
         cout << " - " << it->first << ": " << it->second << "\n";
         it++;
      }
   }
   cout << "ID Group: " << IDGroup << "\n";
   cout << "Study place: " << studyPlace << "\n";
   cout << "Residence place: " << residencePlace << "\n";
}

Student Student::create()
{
    string name;
    string surname;
    string patronymic;
    Date birthday;
    string studyPlace;
    string residencePlace;
    string password;

    cout << "Creating new student: \n";
    cout << "Surname: ";
    getline(cin, surname);
    cout << "Name: ";
    getline(cin, name);
    cout << "Patronymic: ";
    getline(cin, patronymic);
    cout << "Birthday: \n";
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
          birthday.set_day(day);
          birthday.set_month(month);
          birthday.set_year(year);
          break;
       }
       catch(const string& exeption){
          if (exeption == "ValNotCorrect")
             cout << "Please, enter correct values\n";
       }
    }
    
    cout << "Study place: ";
    cin.ignore();
    getline(cin, studyPlace);
    cout << "Residence place: ";
    getline(cin, residencePlace);
    return Student(name, surname, patronymic, birthday, -1, studyPlace, residencePlace);
}

bool Student::operator==(Student obj)
{
    if (name == obj.getName() &&
        surname == obj.getSurname() &&
        patronymic == obj.getPatronymic())
        return true;
    return false;
}

bool Student::operator!=(Student obj)
{
    return !(*this == obj);
}
