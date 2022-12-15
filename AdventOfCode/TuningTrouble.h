#pragma once
#include "AdventDay.h"

#include<queue>

class TuningTrouble :
    public AdventDay
{
public:
    void solve(const std::string& input) override;


private:
    const bool isStartMarker(std::queue<char> dataCopy) const;
    const int indexOfMarker(const std::string& data, const int markerLength) const;
};

