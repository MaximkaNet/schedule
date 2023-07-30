#include "Subject.h"

Subject::Subject()
{
    ID = -1;
    termHours = -1;
    isDelete = false;
}

Subject::Subject(string name, float termHours)
{
    ID = -1;
    this->name = name;
    this->termHours = termHours;
    isDelete = false;
}

Subject::Subject(const Subject& obj)
{
    this->ID = obj.ID;
    this->name = obj.name;
    this->termHours = obj.termHours;
    this->isDelete = obj.isDelete;
}

int Subject::getID()
{
    return ID;
}

string Subject::getName()
{
    return name;
}

float Subject::getTermHours()
{
    return termHours;
}

bool Subject::getIsDelete()
{
    return isDelete;
}

void Subject::setName(string name)
{
    if (!name.empty()) {
        this->name = name;
        return;
    }
    cout << "Name empty\n";
}

void Subject::setTermHours(float termHours)
{
    if (termHours > 0) {
        this->termHours = termHours;
        return;
    }
    cout << "Term hours don't less 0\n";
}

void Subject::show()
{
    cout << "Name: " << name << "\n";
    cout << "Term hours: " << termHours << "\n";
}

Subject Subject::create()
{
   string name;
   float termHours;
   cout << "Creating subject: \n";
   cout << "Name: ";
   std::getline(std::cin, name);
   cout << "Term hours: ";
   std::cin >> termHours;
   return Subject(name, termHours);
}

bool Subject::operator==(Subject obj)
{
    if (name == obj.getName() &&
        termHours == obj.getTermHours())
        return true;
    return false;
}

bool Subject::operator!=(Subject obj)
{
    return !(*this == obj);
}
