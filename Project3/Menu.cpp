#include "Menu.h"

Menu::Menu()
{
    choice = -1;
    this->menuTitle = "  Menu";
}

Menu::Menu(string menuTitle)
{
    choice = -1;
    this->menuTitle = menuTitle;
}

int Menu::operator()()
{
    bool flag = true;
    while (flag) {
       cout << menuTitle << "\n";
       int length = sections.size();
       for (int i = 0; i < length; i++)
       {
          cout << " " << i + 1 << ". " << sections[i] << "\n";
       }
       cout << " 0." << " Выход" << "\n";
       cout << "Ваш выбор: ";
       getline(cin, in);
       int countTry = 0;
       if (!toInt()) {
          while (true) {
             cout << "Вы неправильно ввели!\nВаш выбор: ";
             getline(cin, in);
             if (toInt()) {
                flag = false;
                break;
             }
             countTry++;
             if (countTry > 5) {
                break;
             }
          }
       }
       else
          break;
       system("cls");
    }
    return choice;
}

void Menu::addSection(string section)
{
    if (section.empty()) {
        cout << "Section is empty!\n";
        return;
    }
    sections.push_back(section);
}

bool Menu::toInt() {
   int currentSize = in.size();
   int tempChoice = atoi(in.c_str());
   string temp = to_string(tempChoice);
   int tempSize = temp.size();
   if (currentSize == tempSize) {
      choice = tempChoice;
      return true;
   }
   return false;
}