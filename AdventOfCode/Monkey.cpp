#include "Monkey.h"
#include "AdventDay.h"
#include <iostream>

using namespace std;

Monkey::Monkey(const string& inputData, bool doLog)
{
	log = doLog;
	vector<string> lines;
	AdventDay::splitString(inputData, lines);

	vector<string> currentLineSplitted;
	vector<string> arguments;

	// starting items
	AdventDay::splitString(lines[1], currentLineSplitted, ": ");
	AdventDay::splitString(currentLineSplitted[1], arguments, ", ");
	for (int i = 0; i < arguments.size(); i++)
		items.push(stoi(arguments[i]));

	// operation
	AdventDay::splitString(lines[2], currentLineSplitted, ": ");
	AdventDay::splitString(currentLineSplitted[1], arguments, " ");
	if (arguments[4] == "old")
	{
		operationType = Exponentiation;
		operationValue = 2;
	}
	else
	{
		if (arguments[3] == "*")
			operationType = Multiplication;
		else
			operationType = Addition;
		operationValue = stoi(arguments[4]);
	}
	// test
	AdventDay::splitString(lines[3], currentLineSplitted, ": ");
	AdventDay::splitString(currentLineSplitted[1], arguments, " ");
	divisibilityTest = stoi(arguments[2]);

	// true
	AdventDay::splitString(lines[4], currentLineSplitted, ": ");
	AdventDay::splitString(currentLineSplitted[1], arguments, " ");
	trueTarget = stoi(arguments[3]);

	// false
	AdventDay::splitString(lines[5], currentLineSplitted, ": ");
	AdventDay::splitString(currentLineSplitted[1], arguments, " ");
	falseTarget = stoi(arguments[3]);
}

void Monkey::inspectItem(int& targetIndex, int& worryLevel) const
{
	int item = items.front();
	if (log)
		cout << "  Monkey inspects an item with a worry level of " << item << endl;
	switch (operationType)
	{
	case Addition:
		item += operationValue;
		if (log)
			cout << "    Worry level increases by " << operationValue << " to " << item << endl;
		break;
	
	case Multiplication:
		item *= operationValue;
		if (log)
			cout << "    Worry level is multiplied by " << operationValue << " to " << item << endl;
		break;
	
	case Exponentiation:
		item *= item;
		if (log)
			cout << "    Worry level is multiplied by itself to " << item << endl;
		break;
	}

	item /= 3;
	if (log)
		cout << "    Monkey gets bored with item. Worry level is divided by 3 to " << item << endl;
	
	if (item % divisibilityTest == 0)
	{
		if (log)
			cout << "    Current worry level is divisible by " << divisibilityTest << endl;
		targetIndex = trueTarget;
	}
	else
	{
		if (log)
			cout << "    Current worry level is not divisible by " << divisibilityTest << endl;
		targetIndex = falseTarget;
	}
	worryLevel = item;
	if (log)
		cout << "    Item with worry level " << worryLevel << " is thrown to monkey " << targetIndex << endl;
}

void Monkey::removeFirstItem()
{
	items.pop();
}

void Monkey::addItem(int worryValue)
{

	items.push(worryValue);
}

bool Monkey::hasItems() const
{
	return items.size() > 0;
}
