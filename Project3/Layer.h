#pragma once
#include "Database.h"

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::map;
using std::vector;
using std::string;
using std::function;
using std::to_string;
using std::piecewise_construct;
using std::forward_as_tuple;

class Layer {
	int level;
	int index;
	int parentLayer;
	string name;
	map<int, Layer> inner;
	map<string, function<void(Database&)>> commands;
	int choiceUser;

	// path bar
	static vector<string> pathBar;
	static string separator;

	bool toInt(string in);

public:

	Layer();
	Layer(int level, int index, int parentLayer, string name);
	Layer(const Layer& obj);
	int getUserChoice();
	Layer addLayer(string name);
	Layer addLayer(Layer obj);
	Layer setName(string name);

	/*Layer removeLayer(int index) {
		if (choiceUser == -1)
			return *this;
		map<int, Layer>::iterator it = inner.begin();
		while (it != inner.end()) {
			if (it->first == index)
			{
				inner.erase(it);
				return *this;
			}
			it++;
		}
		return *this;
	}*/

	Layer addCommand(string command, function<void()> func);
	Layer addCommand(string command, function<void(Database& storage)> func);
	Layer addCommand(string command, Database& storage);

	/*Layer removeCommand(int index) {
		if (choiceUser == -1)
			return *this;
		int i = 0;
		map<string, function<void()>>::iterator it = commands.begin();
		while (it != commands.end())
		{
			if (i == index) {
				commands.erase(it);
				return *this;
			}
			i++;
			it++;
		}
		return *this;
	}*/

	Layer draw();
	Layer chUser();
	Layer chUser(Database& storage);
};


