#include "RucksackReorganization.h"
#include <iostream>
#include <set>
#include <map>
using namespace std;

void RucksackReorganization::solve(const std::string& input)
{
	list<string> lines;
	splitString(input, lines, enter);

	int badgesSum = 0;
	int prioritiesSum = 0;
	int elfIndex = 0;
	set<char> groupItems;
	for (auto line = lines.begin(); line != lines.end(); ++line)
	{
		int allItemsCount = line->length();
		int compartmentCount = allItemsCount / 2;
		string compartment1 = line->substr(0, compartmentCount);
		string compartment2 = line->substr(compartmentCount, compartmentCount);

		set<char> rucksackItems;
		set<char> duplicateItems;
		for (int j = 0; j < compartmentCount; j++)
		{
			char item = compartment1.at(j);
			rucksackItems.insert(item);
			rucksackItems.insert(compartment2.at(j));
			if (elfIndex == 0) 
			{
				groupItems.insert(item);
				groupItems.insert(compartment2.at(j));
			}
			for (int i = 0; i < compartmentCount; i++)
			{
				if (item == compartment2.at(i))
				{
					duplicateItems.insert(item);
				}
			}
		}

		set<char> tempGroupItems;
		for (auto item = groupItems.begin(); item != groupItems.end(); ++item)
		{
			if (rucksackItems.find(*item) != rucksackItems.end())
			{
				tempGroupItems.insert(*item);
			}
		}
		groupItems = tempGroupItems;

		for (auto item = duplicateItems.begin(); item != duplicateItems.end(); ++item)
		{
			int priority = getItemPriority(*item);
			prioritiesSum += priority;
		}

		if (elfIndex == 2)
		{
			char badge = *groupItems.begin();
			badgesSum += getItemPriority(badge);

			groupItems.clear();
			elfIndex = 0;
		}
		else
			elfIndex++;
	}

	output1 = prioritiesSum;
	output2 = badgesSum;
}

const int RucksackReorganization::getItemPriority(const char item) const
{
	if (item >= 'a' && item <= 'z')
		return (int)item - 96;

	if (item >= 'A' && item <= 'Z')
		return (int)item - 38;

	return 0;
}


