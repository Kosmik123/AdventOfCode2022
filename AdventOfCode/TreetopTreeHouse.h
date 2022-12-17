#pragma once
#include "AdventDay.h"

class TreetopTreeHouse :
    public AdventDay
{
public:
    void solve(const std::string& input) override;

private:
    int width = 0;
    int height = 0;
    int** numbers = nullptr;

    const int countVisibleFromSides() const;
    const bool isTreeVisible(int x, int y) const;
    const int calculateScenicScore(int x, int y) const;
};

