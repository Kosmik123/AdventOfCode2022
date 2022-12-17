#pragma once

#include <string>
#include <list>
#include <vector>
#include "Vector2Int.h"

class AdventDay
{
public:
	int output1 = 0;
	int output2 = 0;

	virtual void solve(const std::string& input) = 0;

protected:
	std::string enter = "\n";
	static void splitString(const std::string& text, std::list<std::string>& output, const std::string& delimiter);
	static void splitString(const std::string& text, std::vector<std::string>& output, const std::string& delimiter);
};

