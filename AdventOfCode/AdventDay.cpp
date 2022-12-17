#include "AdventDay.h"

using namespace std;

void AdventDay::splitString(const string& text, list<string>& output, const string& delimiter)
{
	output.clear();
	int start = 0;
	int end = text.find(delimiter);
	while (end != -1) {
		output.push_back(text.substr(start, end - start));
		start = end + delimiter.size();
		end = text.find(delimiter, start);
	}
	output.push_back(text.substr(start, end - start));
}

void AdventDay::splitString(const string& text, vector<string>& output, const string& delimiter)
{
	output.clear();
	int start = 0;
	int end = text.find(delimiter);
	while (end != -1) {
		output.push_back(text.substr(start, end - start));
		start = end + delimiter.size();
		end = text.find(delimiter, start);
	}
	output.push_back(text.substr(start, end - start));
}
