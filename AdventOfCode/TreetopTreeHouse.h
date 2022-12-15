#pragma once
#include "AdventDay.h"
class TreetopTreeHouse :
    public AdventDay
{
public:
    void solve(const std::string& input) override;

private:
    int width;
    int height;
    int** numbers;

    const int countVisibleFromSides() const;
    const bool isTreeVisible(int x, int y) const;
    const int calculateScenicScore(int x, int y) const;
};

