#pragma once
#include "AdventDay.h"
#include <stack>
#include <vector>

class SupplyStacks :
    public AdventDay
{
    struct CratesMove
    {
    public:
        int cratesCount;
        int from;
        int to;

        static CratesMove parse(const std::string& text);

    private:
        CratesMove(int count, int from, int to);


    };

public:
    void solve(const std::string& input) override;


private:
    const int getStacksCount(const std::string& stackInfo) const;
    void applyMove(std::vector<std::stack<char>>& stacksVector, const CratesMove move);
    void applyMoveStacked(std::vector<std::stack<char>>& stacksVector, const CratesMove move);
};
