#include "HillClimbingAlgorithm.h"
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

void HillClimbingAlgorithm::solve(const std::string& input)
{
	list<string> lines;
	splitString(input, lines);
	
	length = lines.size();
	width = lines.begin()->size();
	
	heights = new TerrainNode * [length];
	int j = 0;
	for (auto line = lines.begin(); line != lines.end(); ++line)
	{
		if (j >= length)
			break;

		heights[j] = new TerrainNode[width];
		for (int i = 0; i < width; i++)
		{
			char letter = line->at(i);
			if (letter == 'S')
			{
				heights[j][i] = TerrainNode(i, j, (int)'a');
				heights[j][i].distanceFromStart = 0;
				startPosition = Vector2Int(i, j);
			}
			else if (letter == 'E')
			{
				heights[j][i] = TerrainNode(i, j, (int)'z');
				heights[j][i].distanceToEnd = 0;
				endPosition = Vector2Int(i, j);
			}
			else
			{
				heights[j][i] = TerrainNode(i, j, (int)letter);
			}
		}
		j++;
	}


	positionsToCheck.push_back(startPosition);

	while (positionsToCheck.empty() == false)
	{
		Vector2Int currentPosition = getNextPositionToCheck();
		checkNode(currentPosition.x, currentPosition.y);
	}


	cout << "We are at the finish\n";
	TerrainNode* parent = heights[endPosition.y][endPosition.x].parent;
	stack<TerrainNode*> path;
	while (parent != nullptr)
	{
		path.push(parent);
		parent = parent->parent;
	}

	while (path.empty() == false)
	{
		cout << "From " << path.top()->position;
		path.pop();
		cout << " go to " << path.top() << endl;
	}

}


const Vector2Int& HillClimbingAlgorithm::getNextPositionToCheck()
{
	Vector2Int posToCheck = positionsToCheck.front();
	positionsToCheck.pop_front();
	return posToCheck;
}

void HillClimbingAlgorithm::checkNode(int x, int y)
{
	TerrainNode* node = heights[y] + x;

	TerrainNode* neighbour;
	if (y > 0) // up
	{
		neighbour = heights[y - 1] + x;
		setNeighbour(neighbour, node);
		bool willBeChecked = find(positionsToCheck.begin(), positionsToCheck.end(), neighbour->position) != positionsToCheck.end();
		if (alreadyCheckedPositions.find(neighbour->position) == alreadyCheckedPositions.end() && willBeChecked == false)
			positionsToCheck.push_back(neighbour->position);
	}
	if (y < length - 1) // down
	{
		neighbour = heights[y + 1] + x; 
		setNeighbour(neighbour, node);
		bool willBeChecked = (std::find(positionsToCheck.begin(), positionsToCheck.end(), neighbour->position) != positionsToCheck.end());
		if (alreadyCheckedPositions.find(neighbour->position) == alreadyCheckedPositions.end() && willBeChecked == false)
			positionsToCheck.push_back(neighbour->position);
	}

	if (x > 0) // left
	{
		neighbour = heights[y] + x - 1;
		setNeighbour(neighbour, node);		
		bool willBeChecked = (std::find(positionsToCheck.begin(), positionsToCheck.end(), neighbour->position) != positionsToCheck.end());
		if (alreadyCheckedPositions.find(neighbour->position) == alreadyCheckedPositions.end() && willBeChecked == false)
			positionsToCheck.push_back(neighbour->position);
	}

	if (x < width - 1) // right
	{
		neighbour = heights[y] + x + 1;
		setNeighbour(neighbour, node);
		bool willBeChecked = (std::find(positionsToCheck.begin(), positionsToCheck.end(), neighbour->position) != positionsToCheck.end());
		if (alreadyCheckedPositions.find(neighbour->position) == alreadyCheckedPositions.end() && willBeChecked == false)
			positionsToCheck.push_back(neighbour->position);
	}
	alreadyCheckedPositions.insert(node->position);
}

void HillClimbingAlgorithm::setNeighbour(TerrainNode* neighbour, TerrainNode* node)
{
	if (neighbour->height == (int)'g')
		int x = 0;
	if (neighbour->parent == nullptr && neighbour->height <= node->height + 1)
		neighbour->setParent(node);
}






