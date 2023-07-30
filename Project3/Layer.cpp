#include "Layer.h"
string Layer::separator = " -> ";
vector<string> Layer::pathBar = vector<string>();
bool Layer::toInt(string in) {
	int currentSize = in.size();
	int tempChoice = atoi(in.c_str());
	string temp = to_string(tempChoice);
	int tempSize = temp.size();
	if (currentSize == tempSize) {
		choiceUser = tempChoice;
		return true;
	}
	return false;
}

Layer::Layer() {
	index = 0;
	parentLayer = -1;
	level = 0;
	choiceUser = -1;
}

Layer::Layer(int level, int index, int parentLayer, string name) {
	this->level = level;
	this->index = index;
	this->parentLayer = parentLayer;
	this->choiceUser = -1;
	this->name = name;
}
Layer::Layer(const Layer& obj) {
	level = obj.level;
	index = obj.index;
	parentLayer = obj.parentLayer;
	inner = obj.inner;
	commands = obj.commands;
	choiceUser = obj.choiceUser;
}
int Layer::getUserChoice() {
	return choiceUser;
}
Layer Layer::setName(string name) {
	this->name = name;
	return *this;
}

Layer Layer::addLayer(string name) {
	//if (choiceUser == -1 && level != 0)
	//	return *this;
	if (inner.size() == 0) {
		this->name = name;
		inner.emplace(piecewise_construct, forward_as_tuple(index), forward_as_tuple(Layer(level + 1, 0, index, this->name)));
		if (inner.empty())
		{
			int length = pathBar.size();
			if (length == 0) {
				pathBar.push_back(this->name);
			}
			else
			{
				if (length - 1 > level) {
					for (int i = length - 1; i > level; i--)
					{
						pathBar.pop_back();
					}
				}
				else
				{
					pathBar.push_back(this->name);
				}
			}
		}
		return Layer(level + 1, 0, index, this->name);
	}
	map<int, Layer>::const_iterator it = inner.cbegin();
	int tIndex, tLayer, tParentLayer;
	tIndex = it->second.index;
	tLayer = it->second.level;
	Layer temp(level + 1, tIndex + 1, index, name);
	inner.emplace(piecewise_construct, forward_as_tuple(tIndex + 1), forward_as_tuple(temp));
	if (inner.empty())
	{
		int length = pathBar.size();
		if (length == 0) {
			pathBar.push_back(this->name);
		}
		else
		{
			if (length - 1 > level) {
				for (int i = length - 1; i > level; i--)
				{
					pathBar.pop_back();
				}
			}
			else
			{
				pathBar.push_back(this->name);
			}
		}
	}
	return temp;
}
Layer Layer::addLayer(Layer obj)
{
	if (choiceUser == -1 && level != 0)
		return *this;
	if (inner.size() == 0) {
		inner.emplace(piecewise_construct, forward_as_tuple(obj.index), forward_as_tuple(obj));
		if (inner.empty())
		{
			int length = pathBar.size();
			if (length == 0) {
				pathBar.push_back(obj.name);
			}
			else
			{
				if (length - 1 > level) {
					for (int i = length - 1; i > level; i--)
					{
						pathBar.pop_back();
					}
				}
				else
				{
					pathBar.push_back(obj.name);
				}
			}
		}
		return obj;
	}
	map<int, Layer>::const_iterator it = inner.cbegin();
	int tIndex, tLayer, tParentLayer;
	obj.index = it->second.index + 1;
	obj.level = it->second.level + 1;
	inner.emplace(piecewise_construct, forward_as_tuple(obj.index), forward_as_tuple(obj));
	if (inner.empty())
	{
		int length = pathBar.size();
		if (length == 0) {
			pathBar.push_back(obj.name);
		}
		else
		{
			if (length - 1 > level) {
				for (int i = length - 1; i > level; i--)
				{
					pathBar.pop_back();
				}
			}
			else
			{
				pathBar.push_back(obj.name);
			}
		}
	}
	return obj;
}
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

//Layer Layer::addCommand(string command, function<void()> func) {
//	if (choiceUser == -1 && level != 0)
//		return *this;
//	commands.emplace(command, func);
//	return *this;
//}
Layer Layer::addCommand(string command, function<void(Database&)> func) {
	/*if (choiceUser == -1 && level != 0)
		return *this;*/
	commands.emplace(command, func);
	return *this;
}
Layer Layer::addCommand(string command, Database& storage) {
	/*if (choiceUser == -1 && level != 0)
		return *this;*/
	commands.emplace(command, [this](Database& storage) {this->chUser(storage); });
	return *this;
}
/*Layer Layer::removeCommand(int index) {
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
Layer Layer::draw() {
	if (choiceUser == -1 && level != 0)
		return *this;

	//draw path bar
	int length = pathBar.size();
	if (length == 0)
		pathBar.push_back("Main");
	cout << pathBar[0];
	for (int i = 1; i < length; i++)
	{
		cout << separator << pathBar[i];
	}
	cout << "\n";

	if (commands.empty() && !inner.empty())
	{
		map<int,Layer>::iterator it = inner.begin();
		int index = 1;
		while (it != inner.end()) {
			// добавляем отступы для слоёв
			for (int i = 0; i < level; i++)
			{
				cout << " ";
			}
			cout << index++ << ". " << it->second.name << "\n";
			it++;
		}
		return *this;
	}
	map<string, function<void(Database&)>>::iterator it = commands.begin();
	int index = 1;
	while (it != commands.end()) {
		// добавляем отступы для слоёв
		for (int i = 0; i < level; i++)
		{
			cout << " ";
		}
		cout << index++ << ". " << it->first << "\n";
		it++;
	}
	return *this;
}
Layer Layer::chUser(Database& storage) {
	if (choiceUser == -1 && level != 0)
		return *this;
	string command;
	while (true) {
		cout << "Ваш выбор: ";
		getline(cin, command);
		int countTry = 0;
		if (!toInt(command)) {
			while (true) {
				cout << "Вы неправильно ввели!\nВаш выбор: ";
				getline(cin, command);
				if (toInt(command)) {
					if (choiceUser <= commands.size() && choiceUser > 0)
					{
						choiceUser -= 1;
						int i = 0;
						map<string, function<void(Database&)>>::iterator it = commands.begin();
						while (it != commands.end())
						{
							if (i == choiceUser) {
								(it->second)(storage);
								choiceUser += 1;
								return *this;
							}
							i++;
							it++;
						}
						choiceUser += 1;
						return *this;
					}
					else if (choiceUser == 0)
					{
						choiceUser = -1;
						return *this;
					}
				}
				countTry++;
				if (countTry > 5) {
					break;
				}
			}
		}
		else
		{
			if (choiceUser <= commands.size() && choiceUser > 0)
			{
				choiceUser -= 1;
				int i = 0;
				map<string, function<void(Database& s)>>::iterator it = commands.begin();
				while (it != commands.end())
				{
					if (i == choiceUser) {
						(it->second)(storage);
						choiceUser += 1;
						return *this;
					}
					i++;
					it++;
				}
				choiceUser += 1;
				return *this;
			}
			else if (choiceUser == 0)
			{
				choiceUser = -1;
				return *this;
			}
		}
	}
	return *this;
}