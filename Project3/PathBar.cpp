#include "PathBar.h"

PathBar::PathBar()
{
    separator = "/";
}

PathBar::PathBar(string beginPath)
{
    pathBar.push_back(beginPath);
}

//ACTIONS: add, remove
string PathBar::operator()(const string action, string nameSection)
{
    string outPath;
    if (action == "add") {
        pathBar.push_back(nameSection);
        int length = pathBar.size();
        for (int i = 0; i < length; i++)
        {
            outPath += pathBar[i];
            if (i != length-1) {
                outPath += separator;
            }
        }
    }
    else if (action == "remove") {
        pathBar.pop_back();
    }
    else
        throw "Wrong action";
    return outPath;
}

void PathBar::setSeparator(string separator)
{
    this->separator = separator;
}
