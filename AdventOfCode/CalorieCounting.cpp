#include "CalorieCounting.h"

using namespace std;

void CalorieCounting::solve(const string& input)
{
	list<string> lines;
	splitString(input, lines, enter);

	int maxCalories = 0;
	int secondMaxCalories = 0;
	int thirdMaxCalories = 0;

	list<int> elfsCalories;
	elfsCalories.push_back(0);
	auto currentElf = elfsCalories.end();
	--currentElf;
	for (auto line = lines.begin(); line != lines.end(); ++line)
	{
		if (line->empty() == false)
		{
			int calories = stoi(*line);
			*currentElf += calories;
		}
		else
		{
			if (*currentElf > maxCalories)
			{
				thirdMaxCalories = secondMaxCalories;
				secondMaxCalories = maxCalories;
				maxCalories = *currentElf;
			}
			else if (*currentElf > secondMaxCalories)
			{
				thirdMaxCalories = secondMaxCalories;
				secondMaxCalories = *currentElf;
			}
			else if (*currentElf > thirdMaxCalories)
				thirdMaxCalories = *currentElf;

			elfsCalories.push_back(0);
			currentElf = elfsCalories.end();
			--currentElf;
		}
	}

	output1 = maxCalories;
	output2 = maxCalories + secondMaxCalories + thirdMaxCalories;
}

