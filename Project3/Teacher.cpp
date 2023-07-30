#include "Teacher.h"
Teacher::Teacher()
{
    ID = -1;
    name = "userName";
    surname = "userSurname";
    patronymic = "userPatronymic";
    position = "userPosition";
    speciality = "userSpeciality";
}

Teacher::Teacher(string name, string surname, string patronymic, Date birthday, map<string, string> additional, string position, string speciality, vector<int> subjects) :Person(name, surname, patronymic, birthday, additional)
{
    this->position = position;
    this->speciality = speciality;
    this->subjects = subjects;
}

Teacher::Teacher(string name, string surname, string patronymic, Date birthday, string position, string speciality) : Person(name, surname, patronymic, birthday)
{
    this->position = position;
    this->speciality = speciality;
}

Teacher::Teacher(const Teacher& obj)
{
    ID = obj.ID;
    name = obj.name;
    surname = obj.surname;
    patronymic = obj.patronymic;
    birthday = obj.birthday;
    additional = obj.additional;
    position = obj.position;
    speciality = obj.speciality;
    subjects = obj.subjects;
    login = obj.login;
    password = obj.password;
}

string Teacher::getPosition()
{
    return position;
}

string Teacher::getSpeciality()
{
    return speciality;
}

vector<int> Teacher::getSubjects()
{
    return subjects;
}

void Teacher::setPosition(string name)
{
    if (name.empty()) {
        cout << "Value is empty!\n";
        return;
    }
    position = name;
}

void Teacher::setSpeciality(string name)
{
    if (name.empty()) {
        cout << "Value is empty!\n";
        return;
    }
    speciality = name;
}

void Teacher::addSubject(int idSubject)
{
    subjects.push_back(idSubject);
    sort(subjects.begin(), subjects.end());
}

void Teacher::removeSubject(int idSubject)
{
    vector<int>::iterator it = subjects.begin();
    while (it != subjects.end())
    {
        int temp = *it;
        if (idSubject == temp) {
            subjects.erase(it);
            return;
        }
        it++;
    }
    cout << "Subject not found!\n";
}

void Teacher::show(vector<Subject> DBSubjects)
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
        map<string, string>::iterator it = additional.begin();
        while (it != additional.end()) {
            cout << "\n - ";
            cout << it->first << ": " << it->second << "\n";
            it++;
        }
    }
    cout << "Position: " << position << "\n";
    cout << "Speciality: " << speciality << "\n";
    cout << "Subjects: ";
    if (subjects.size() == 0) {
        cout << "subjects array is empty!\n";
    }
    else {
        int sizeSubjects = this->subjects.size();
        int sizeDBSubjects = DBSubjects.size();
        //Можно доработать алгоритм
        for (int i = 0; i < sizeSubjects; i++)
        {
            for (int j = i; j < sizeDBSubjects; j++)
            {
                if (DBSubjects[j].getID() == subjects[i]) {
                    cout << "\n - "<< DBSubjects[j].getName() << "  " << DBSubjects[j].getTermHours() << "h(s)\n";
                }
            }
            
        }
    }
}

//for binary
string Teacher::toStr()
{
   string out = name;
   out += " ";
   out += surname;
   out += " ";
   out += patronymic;
   out += " ";
   out += birthday.get_day();
   out += " ";
   if (additional.size() == 0) {
      out += "NOT_FOUND";
   }
   else {
      map<string, string>::iterator it = additional.begin();
      while (it != additional.end()) {
         out += it->first;
         out += " ";
         out += it->second;
         it++;
      }
   }
   out += " ";
   if (position.empty())
      out += "NOT_FOUND";
   else
      out += position;
   out += " ";
   if (speciality.empty())
      out += "NOT_FOUND";
   else
      out += speciality;
   out += " ";
   if (subjects.size() == 0) {
      out += "NOT_FOUND";
   }
   else {
      int sizeSubjects = subjects.size();
      //Можно доработать алгоритм
      for (int i = 0; i < sizeSubjects; i++)
      {
         out += to_string(subjects[i]);
         out += " ";
      }
   }
   return string(out);
}

Teacher Teacher::create()
{
    string name;
    string surname;
    string patronymic;
    Date birthday;
    string position;
    string speciality;

    cout << "Creating new teacher: \n";
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
       catch (const string& exeption) {
          if (exeption == "ValNotCorrect")
             cout << "Please, enter correct values\n";
       }
    }
    cout << "Position: ";
    cin.ignore();
    getline(cin, position);
    cout << "Speciality: ";
    getline(cin, speciality);
    return Teacher(name, surname, patronymic, birthday, position, speciality);
}

bool Teacher::operator==(Teacher obj)
{
    if (name == obj.getName() &&
        surname == obj.getSurname() &&
        patronymic == obj.getPatronymic())
        return true;
    return false;
}

bool Teacher::operator!=(Teacher obj)
{
    return !(*this == obj);
}
