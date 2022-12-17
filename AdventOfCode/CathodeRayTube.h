#pragma once
#include "AdventDay.h"
#include <map>

class CathodeRayTube :
    public AdventDay
{
public:
    void solve(const std::string& input) override;

private:
    std::map<int, int> registerValuesByCycle;
    bool screen[240];

    int getRegisterValueAfterCycle(int cycle);
    int getRegisterValueDuringCycle(int cycle);
    void drawScreen();
};

