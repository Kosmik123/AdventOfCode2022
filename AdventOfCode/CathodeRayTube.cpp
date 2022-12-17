#include "CathodeRayTube.h"
#include <iostream>
using namespace std;

void CathodeRayTube::solve(const std::string& input)
{
	list<string> lines;
	splitString(input, lines);

	int currentCycle = 0;
	int currentRegister = 1;
	registerValuesByCycle.insert(std::pair<int, int>(currentCycle, currentRegister));

	for (auto line = lines.begin(); line != lines.end(); ++line)
	{
		if (line->at(0) == 'n')
		{
			currentCycle++;
		}
		else
		{
			vector<string> args; 
			currentCycle += 2;
			splitString(*line, args, " ");
			int value = stoi(args[1]);
			currentRegister += value;
			registerValuesByCycle.insert(std::pair<int, int>(currentCycle, currentRegister));
		}
	}

	for (int i = 0; i < currentCycle; i++)
	{
		int registerValue = getRegisterValueAfterCycle(i);
		int horizontalPos = i % 40;
		if ((horizontalPos  == registerValue) 
			|| (horizontalPos == registerValue - 1) 
			|| (horizontalPos == registerValue + 1))
			screen[i] = true;
	}

	output1 = getRegisterValueDuringCycle(20) * 20
		+ getRegisterValueDuringCycle(60) * 60
		+ getRegisterValueDuringCycle(100) * 100
		+ getRegisterValueDuringCycle(140) * 140
		+ getRegisterValueDuringCycle(180) * 180 
		+ getRegisterValueDuringCycle(220) * 220; 

	drawScreen();
}

int CathodeRayTube::getRegisterValueAfterCycle(int cycle)
{
	auto lastSmallerOrEqual = --registerValuesByCycle.upper_bound(cycle);
	return lastSmallerOrEqual->second;
}

int CathodeRayTube::getRegisterValueDuringCycle(int cycle)
{
	return getRegisterValueAfterCycle(cycle - 1);
}

void CathodeRayTube::drawScreen()
{
	int width = 40;
	int height = 6;

	cout << endl;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			int index = j * width + i;
			cout << (screen[index] ? (char)219 : ' ');
		}
		cout << endl;
	}
	cout << endl;
}

