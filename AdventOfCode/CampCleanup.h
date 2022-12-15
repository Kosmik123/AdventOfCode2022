#pragma once
#include "AdventDay.h"
class CampCleanup :
    public AdventDay
{
public:
	void solve(const std::string& input) override;


private:
	const std::pair<int, int> extractSection(const std::string& range) const;
	const bool isSectionContained(const std::pair<int, int> section, const std::pair<int, int> containment) const;
	const bool overlaps(const std::pair<int, int> section1, const std::pair<int, int> section2) const;

};

