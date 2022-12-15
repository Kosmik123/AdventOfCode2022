#pragma once

#include <string>
#include <list>
#include <vector>

class AdventDay
{
public:
	int output1;
	int output2;

	virtual void solve(const std::string& input) = 0;

protected:
	std::string enter = "\n";
	static void splitString(const std::string& text, std::list<std::string>& output, const std::string& delimiter);
	static void splitString(const std::string& text, std::vector<std::string>& output, const std::string& delimiter);
};

