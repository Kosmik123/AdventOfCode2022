#include "SupplyStacks.h"
#include <iostream>

using namespace std;

void SupplyStacks::solve(const std::string& input)
{
	list<string> parts; 
	splitString(input, parts, "\n\n");
	auto iterator = parts.begin();

	string cratesConfig = *iterator;
	iterator++;
	string movesProcedure = *iterator;

	// STACKS INFO
	list<string> configLines;
	splitString(cratesConfig, configLines, enter);
	auto lastLine = --configLines.end();
	int stacksCount = getStacksCount(*lastLine);

	// CREATE STACKS
	vector<stack<char>> stacks;
	for (size_t i = 0; i < stacksCount; i++)
	{
		stack<char> newStack;
		stacks.push_back(newStack);
	}
	auto firstLine = ++configLines.rbegin();
	for (auto line = firstLine; line != configLines.rend(); ++line)
	{
		for (int i = 0; i < stacksCount; i++)
		{
			int characterIndex = i * 4 + 1;
			char crate = line->at(characterIndex);
			if (crate != ' ')
				stacks[i].push(crate);
		}
	}

	// CREATE MOVES LIST
	list<string> movesStringsList;
	splitString(movesProcedure, movesStringsList, enter);
	list<CratesMove> cratesMoves;
	for (auto line = movesStringsList.begin(); line != movesStringsList.end(); ++line)
	{
		auto move = CratesMove::parse(*line);
		cratesMoves.push_back(move);
	}

	// DO MOVES CRATEMOVER 9000
	//for (auto move = cratesMoves.begin(); move != cratesMoves.end(); ++move)
	//{
	//	applyMove(stacks, *move);
	//}

	//cout << "9000:";
	//for (int i = 0; i < stacksCount; i++)
	//{
	//	cout << stacks[i].top();
	//}
	//cout << endl;

	// DO MOVES CRATEMOVER 9001
	for (auto move = cratesMoves.begin(); move != cratesMoves.end(); ++move)
	{
		applyMoveStacked(stacks, *move);
	}

	cout << "9001:";
	for (int i = 0; i < stacksCount; i++)
	{
		cout << stacks[i].top();
	}
	cout << endl;
}

const int SupplyStacks::getStacksCount(const std::string& stackInfo) const
{
	int stacksCount = 0;
	list<string> tempStackIndexes;
	splitString(stackInfo, tempStackIndexes, " ");
	for (auto character = tempStackIndexes.begin(); character != tempStackIndexes.end(); ++character)
		if (character->empty() == false)
			stacksCount++;

	return stacksCount;
}


void SupplyStacks::applyMove(std::vector<std::stack<char>>& stacksVector, const CratesMove move)
{
	int from = move.from - 1;
	int to = move.to - 1;

	for (int i = 0; i < move.cratesCount; i++)
	{
		char crate = stacksVector.at(from).top();
		stacksVector.at(from).pop();
		stacksVector.at(to).push(crate);
	}
}

void SupplyStacks::applyMoveStacked(std::vector<std::stack<char>>& stacksVector, const CratesMove move)
{
	int from = move.from - 1;
	int to = move.to - 1;

	stack<char> tempStack;
	for (int i = 0; i < move.cratesCount; i++)
	{
		char crate = stacksVector.at(from).top();
		stacksVector.at(from).pop();
		tempStack.push(crate);
	}

	for (int i = 0; i < move.cratesCount; i++)
	{
		char crate = tempStack.top();
		tempStack.pop();
		stacksVector.at(to).push(crate);
	}
}

SupplyStacks::CratesMove SupplyStacks::CratesMove::parse(const std::string& text)
{
	vector<string> elements;
	splitString(text, elements, " ");
	return CratesMove(stoi(elements[1]), stoi(elements[3]), stoi(elements[5]));
}

SupplyStacks::CratesMove::CratesMove(int count, int from, int to) :
	cratesCount(count), to(to), from(from)
{ }









