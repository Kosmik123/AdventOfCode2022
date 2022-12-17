#pragma once
#include "AdventDay.h"

class RopeBridge :
    public AdventDay
{
public:
    void solve(const std::string& input) override;
    bool touches(const Vector2Int& first, const Vector2Int& second) const;

private:
    Vector2Int headPosition;
    Vector2Int tailPosition;
};

std::ostream& operator<<(std::ostream& out, const Vector2Int& vector);
