#pragma once
#include <set>
#include <iostream>

#include "RopeBridge.h"

using namespace std;

RopeBridge::RopeBridge()
{
	rope = new Rope(10);
}

void RopeBridge::solve(const std::string& input)
{
	list<string> lines;
	splitString(input, lines, enter);

	set<Vector2Int> visitedPositions1;
	set<Vector2Int> visitedPositions2;
	visitedPositions1.insert(rope->at(1));
	visitedPositions2.insert(rope->tail());
	for (auto line = lines.begin(); line != lines.end(); ++line)
	{
		vector<string> elements;
		splitString(*line, elements, " ");
		string direction = elements.at(0);
		int count = stoi(elements.at(1));

		for (int i = 0; i < count; i++)
		{
			if (direction == "U")
			{
				rope->moveByHeadUp();
			}
			else if (direction == "D")
			{
				rope->moveByHeadDown();
			}
			else if (direction == "L")
			{
			 	rope->moveByHeadLeft();
			}
			else if (direction == "R")
			{
			 	rope->moveByHeadRight();
			}
			//cout << "Move " << direction << " : " << rope->tail() << endl;
			visitedPositions1.insert(rope->at(1));
			visitedPositions2.insert(rope->tail());
		}
	}

	output1 = visitedPositions1.size();
	output2 = visitedPositions2.size();
}

bool RopeBridge::touches(const Vector2Int& first, const Vector2Int& second) const
{
	int horizontalDistance = first.x - second.x;
	int verticalDistance = first.y - second.y;
	return (horizontalDistance <= 1) && (horizontalDistance >= -1)
		&& (verticalDistance <= 1) && (verticalDistance >= -1);
}

RopeBridge::~RopeBridge()
{
	delete rope;
}


ostream& operator<<(ostream& out, const Vector2Int& vector)
{
	return out << "(" << vector.x << ", " << vector.y << ")";
}


