#include "CampCleanup.h"

using namespace std;

void CampCleanup::solve(const std::string& input)
{
	list<string> lines;
	splitString(input, lines, enter);
	int wholeContainments = 0;
	int overlapsCount = 0;
	for (auto line = lines.begin(); line != lines.end(); ++line)
	{
		list<string> elfsRanges;
		splitString(*line, elfsRanges, ",");

		pair<int, int> sections[2];
		int index = 0;
		for (auto range = elfsRanges.begin(); range != elfsRanges.end(); ++range)
		{
			auto section = extractSection(*range);
			sections[index] = section;
			index++;
		}

		if (isSectionContained(sections[0], sections[1]) || isSectionContained(sections[1], sections[0]))
		{
			wholeContainments++;
		}
			
		if (overlaps(sections[0], sections[1]))
			overlapsCount++;
	}

	output1 = wholeContainments;
	output2 = overlapsCount;
}

const pair<int, int> CampCleanup::extractSection(const string& rangeString) const
{
	list<string> sectionIDs;
	splitString(rangeString, sectionIDs, "-");

	auto iterator = sectionIDs.begin();
	int sectionStart = stoi(*iterator);
	++iterator;
	int sectionEnd = stoi(*iterator);
	pair<int, int> section(sectionStart, sectionEnd);
	return section;
}

const bool CampCleanup::isSectionContained(const std::pair<int, int> section, const std::pair<int, int> containment) const
{
	return (section.first >= containment.first && section.second <= containment.second);
}

const bool CampCleanup::overlaps(const std::pair<int, int> section1, const std::pair<int, int> section2) const
{
	return (section1.first <= section2.second && section2.first <= section1.second);
}
