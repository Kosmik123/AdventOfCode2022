#pragma once
#include "AdventDay.h"
#include <string>


class NoSpaceLeftOnDevice :
    public AdventDay
{
public:
    const int bigFolderSize = 100000;
    const int wholeMemory = 70000000;
    const int memoryNeededForUpdate = 30000000;
    void solve(const std::string& input) override;

private:



};


