#include "MonkeyInTheMiddle.h"
#include "AdventDay.h"
#include "Monkey.h"
#include <iostream>

using namespace std;

void MonkeyInTheMiddle::solve(const std::string& input)
{
	list<string> monkeyDatas;
	splitString(input, monkeyDatas, "\n\n");

	createMonkeys(monkeyDatas);

	int roundsCount = 20;
	for (int i = 0; i < roundsCount; i++) 
	{
		cout << "Round " << i << endl;
		processRound();
	}

	int highestInspectionCount = 0, secondHighestInspectionCount = 0;
	for (int i = 0; i < inspectionCounts.size(); i++)
	{
		int currentCount = inspectionCounts[i];
		if (currentCount > highestInspectionCount)
		{
			secondHighestInspectionCount = highestInspectionCount;
			highestInspectionCount = currentCount;
		}
		else if (currentCount > secondHighestInspectionCount)
		{
			secondHighestInspectionCount = currentCount;
		}
	}
	output1 = highestInspectionCount * secondHighestInspectionCount;
}

void MonkeyInTheMiddle::createMonkeys(list<string>& monkeyDatas)
{
	monkeys.clear();
	inspectionCounts.clear();
	for (auto data = monkeyDatas.begin(); data != monkeyDatas.end(); ++data)
	{
		Monkey monkey(*data, true);
		monkeys.push_back(monkey);
		inspectionCounts.push_back(0);
	}
}

void MonkeyInTheMiddle::processRound()
{
	for (int i = 0; i < monkeys.size(); i++)
	{
		cout << "Monkey " << i << ":" << endl;
		while (monkeys[i].hasItems())
		{
			int item, target;
			monkeys[i].inspectItem(target, item);
			inspectionCounts.at(i) = inspectionCounts.at(i) + 1;
			monkeys[i].removeFirstItem();
			monkeys[target].addItem(item);
		}
	}
}
