#pragma once
#include "AdventDay.h"

class RucksackReorganization :
    public AdventDay
{
public:
    void solve(const std::string& input) override;

private:
    const int getItemPriority(const char item) const;

};
