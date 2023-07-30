#include "Person.h"
Person::Person()
{
    ID = -1;
    isDelete = false;
}
Person::Person(string name, string surname, string patronymic, Date birthday, map<string, string> additional)
{
    ID = -1;
    isDelete = false;
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->birthday = birthday;
    this->additional = additional;
}
Person::Person(string name, string surname, string patronymic, Date birthday)
{
    ID = -1;
    isDelete = false;
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->birthday = birthday;
}
Person::Person(const Person& obj) {
    ID = obj.ID;
    isDelete = obj.isDelete;
    name = obj.name;
    surname = obj.surname;
    patronymic = obj.patronymic;
    birthday = obj.birthday;
    additional = obj.additional;
    login = obj.login;
    password = obj.password;
}
void Person::addAdditional(string name, string value)
{
   if (name.empty() || value.empty())
   {
      cout << "Uncorrect values!\n";
      system("pause");
      return;
   }
   additional.emplace(piecewise_construct, forward_as_tuple(name), forward_as_tuple(value));
}

void Person::changeAdditional(string name, string value)
{
    if (additional.empty()) {
        cout << "Array additional is empty\n";
        return;
    }
    map<string, string>::iterator it = additional.begin();
    while (it != additional.end()) {
        if (it->first == name) {
            it->second = value;
            return;
        }
        it++;
    }
    cout << "Additional not found\n";
}

void Person::delAdditional(string name)
{
    if (additional.empty()) {
        cout << "Array additional is empty\n";
        return;
    }
    map<string, string>::iterator it = additional.begin();
    while (it != additional.end()) {
        if (it->first == name) {
            additional.erase(it);
            return;
        }
        it++;
    }
    cout << "Additional not found\n";
}

int Person::getID()
{
    return ID;
}

string Person::getLogin()
{
   return login;
}

string Person::getName()
{
    return name;
}

string Person::getSurname()
{
    return surname;
}

string Person::getPatronymic()
{
    return patronymic;
}

string Person::getFIO()
{
    string out = surname;
    out += " ";
    out += name;
    out += " ";
    out += patronymic;
    return out;
}

Date Person::getBirthday()
{
    return birthday;
}

map<string, string> Person::getAdditional()
{
    return additional;
}

bool Person::getIsDelete()
{
    return isDelete;
}

void Person::changeBirthday(Date obj)
{
    Date temp(birthday);
    try {
        birthday.set_day(obj.get_day());
        birthday.set_month(obj.get_month());
        birthday.set_year(obj.get_year());
    }
    catch (string& exeption) {
        if (exeption == "ValNotCorrect") {
            birthday = temp;
            cout << "Change error!\n";
        }
        return;
    }
    cout << "Change success!\n";
}

void Person::changeBirthday(int day, int month, int year)
{
    Date temp(birthday);
    try {
        birthday.set_day(day);
        birthday.set_month(day);
        birthday.set_year(day);
    }
    catch (string& exeption) {
        if (exeption == "ValNotCorrect") {
            // return prev state
            birthday = temp;
            cout << "Change error!\n";
        }
        return;
    }
    cout << "Change success!\n";
}

bool Person::changePassword(string oldPassword ,string newPassword)
{
   if (oldPassword != password) {
      cout << "Не пытайтесь изменить пароль не зная его !\n";
      return false;
   }
   if (newPassword == password) {
      cout << "Этот пароль не доступен к использованию!\n";
      return false;
   }
   this->password = newPassword;
   return true;
}

bool Person::isEmpty()
{
    if (name.empty() && surname.empty() && patronymic.empty())
        return true;
    return false;
}
