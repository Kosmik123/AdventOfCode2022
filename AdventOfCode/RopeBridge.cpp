#pragma once
#include <set>
#include <iostream>

#include "RopeBridge.h"

using namespace std;

void RopeBridge::solve(const std::string& input)
{
	list<string> lines;
	splitString(input, lines, enter);

	int instructionsCount = 0;
	int tailMoves = 0;
	set<Vector2Int> visitedPositions;
	visitedPositions.insert(tailPosition);
	for (auto line = lines.begin(); line != lines.end(); ++line)
	{
		vector<string> elements;
		splitString(*line, elements, " ");
		string direction = elements.at(0);
		int count = stoi(elements.at(1));

		for (int i = 0; i < count; i++)
		{
			Vector2Int prevHeadPosition = headPosition;
			if (direction == "U")
			{
				headPosition.move(0, 1);
			}
			else if (direction == "D")
			{
				headPosition.move(0, -1);
			}
			else if (direction == "L")
			{
				headPosition.move(-1, 0);
			}
			else if (direction == "R")
			{
				headPosition.move(1, 0);
			}

			if (touches(tailPosition, headPosition) == false)
			{
				tailPosition = prevHeadPosition;
			}

			visitedPositions.insert(tailPosition);
		}
		instructionsCount++;
	}

	output1 = visitedPositions.size();
}

bool RopeBridge::touches(const Vector2Int& first, const Vector2Int& second) const
{
	int horizontalDistance = first.x - second.x;
	int verticalDistance = first.y - second.y;
	return (horizontalDistance <= 1) && (horizontalDistance >= -1)
		&& (verticalDistance <= 1) && (verticalDistance >= -1);
}

ostream& operator<<(ostream& out, const Vector2Int& vector)
{
	return out << "(" << vector.x << ", " << vector.y << ")";
}
