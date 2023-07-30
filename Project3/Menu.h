#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::to_string;
using std::getline;
using std::vector;
class Menu
{
    int choice;
    string in;
    string menuTitle;
    vector<string> sections;
public:
    Menu();
    Menu(string menuTitle);

    int operator()();

    bool toInt();
    void addSection(string section);
};

