#pragma once
#include "AdventDay.h"
#include "Monkey.h"

class MonkeyInTheMiddle :
    public AdventDay
{
public:
    void solve(const std::string& input) override;

private:
    std::vector<Monkey> monkeys;
    std::vector<int> inspectionCounts;

    void createMonkeys(std::list<std::string>& monkeyDatas);
    void processRound();
};



