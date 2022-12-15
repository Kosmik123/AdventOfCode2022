#include "TreetopTreeHouse.h"

using namespace std;

void TreetopTreeHouse::solve(const std::string& input)
{
	vector<string> lines;
	splitString(input, lines, enter);
	height = lines.size();
	width = lines.at(0).size();

	numbers = new int* [height];
	for (int i = 0; i < height; i++)
		numbers[i] = new int[width];

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			char character = lines.at(j).at(i);
			numbers[j][i] = character - '0';
		}
	}

	output1 = countVisibleFromSides();



	int scenic = calculateScenicScore(2, 3);

	int maxScenicScore = 0;
	for (int j = 1; j < height - 1; j++)
	{
		for (int i = 1; i < width - 1; i++)
		{
			int scenicScore = calculateScenicScore(i, j);
			if (scenicScore > maxScenicScore)
				maxScenicScore = scenicScore;
		}
	}

	output2 = maxScenicScore;
}

const int TreetopTreeHouse::countVisibleFromSides() const
{
	int visibleCount = height * width - (height - 2) * (width - 2);
	for (int j = 1; j < height - 1; j++)
	{
		for (int i = 1; i < width - 1; i++)
		{
			if (isTreeVisible(i, j))
				visibleCount++;
		}
	}
	return visibleCount;
}

const bool TreetopTreeHouse::isTreeVisible(int x, int y) const
{
	int tree = numbers[y][x];

	// Check Up
	bool wasHidden = false;
	for (int i = 0; i < y; i++)
	{
		if (numbers[i][x] >= tree)
		{
			wasHidden = true;
			break;
		}
	}
	if (wasHidden == false)
		return true;

	// Check Down
	wasHidden = false;
	for (int i = y + 1; i < height; i++)
	{
		if (numbers[i][x] >= tree)
		{
			wasHidden = true;
			break;
		}
	}
	if (wasHidden == false)
		return true;

	// Check Left
	wasHidden = false;
	for (int i = 0; i < x; i++)
	{
		if (numbers[y][i] >= tree)
		{
			wasHidden = true;
			break;
		}
	}
	if (wasHidden == false)
		return true;

	// Check Right
	wasHidden = false;
	for (int i = x + 1; i < width; i++)
	{
		if (numbers[y][i] >= tree)
		{
			wasHidden = true;
			break;
		}
	}
	if (wasHidden == false)
		return true;

	return false;
}


const int TreetopTreeHouse::calculateScenicScore(int x, int y) const
{
	int tree = numbers[y][x];

	// Look Up
	int i = 1;
	while ((y - i) >= 0)
	{
		if (numbers[y - i][x] >= tree)
		{
			i++;
			break;
		}
		i++;
	}
	int upScore = i - 1;

	// Look Down
	i = 1;
	while ((y + i) < height)
	{
		if (numbers[y + i][x] >= tree)
		{
			i++;
			break;
		}
		i++;
	}
	int downScore = i - 1;

	// Look Left
	i = 1;
	while ((x - i) >= 0)
	{
		if (numbers[y][x - i] >= tree)
		{
			i++;
			break;
		}
		i++;
	}
	int leftScore = i - 1;

	// Look Right
	i = 1;
	while ((x + i) < width)
	{
		if (numbers[y][x + i] >= tree)
		{
			i++;
			break;
		}
		i++;
	}
	int rightScore = i - 1;

	return upScore * downScore * leftScore * rightScore;	
}
