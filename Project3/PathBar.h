#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;
class PathBar
{
    vector<string> pathBar;
    string separator;
public:
    PathBar();
    PathBar(string beginPath);
    //ACTIONS: add, remove
    string operator()(const string action, string nameSection = "");

    void setSeparator(string separator);
};

