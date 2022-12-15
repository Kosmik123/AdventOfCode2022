#pragma once

#include "AdventDay.h"

class RockPaperScissors :
    public AdventDay
{
    enum MoveType
    {
        None = 0,
        Rock = 1,
        Paper = 2,
        Scissors = 3,
    };

public:
    void solve(const std::string& input) override;

private:
    const int duel(const MoveType opponentMove, const MoveType myMove) const;
    const MoveType convert(const char letter) const;
    const MoveType getMoveByResult(const MoveType opponent, const char result) const;

};

