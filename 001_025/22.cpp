#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void extractNames(string &name_string, vector<string> &name_list)
{
	string temp = "";
	bool inName = false;

	for(string::iterator it = name_string.begin(); it != name_string.end(); it++)
	{
		if(!inName)
		{
			if(*it == '\"')
				inName = true;
		}
		else
		{
			if(*it == '\"')
			{
				inName = false;
				name_list.push_back(temp);
				temp = "";
			}
			else
				temp += *it;
		}
	}
}

unsigned long long nameScore(string name)
{
	int size = name.length();
	unsigned long long score = 0;

	for(int i = 0; i < size; i++)
	{
		score += (name[i] - 'A' + 1);
	}
	return score;
}

int main()
{
	vector<string> name_list;
 	ifstream name_file;
	string names_string;

	name_file.open("22.txt");
	name_file >> names_string;
	name_file.close();

	extractNames(names_string, name_list);
	std::sort(name_list.begin(), name_list.end());

	int size = name_list.size();
	unsigned long long sum = 0;

	for(int i = 0; i < size; i++)
	{
		sum += (nameScore(name_list[i]) * (i+1));
	}
	
	cout << sum << endl;
}