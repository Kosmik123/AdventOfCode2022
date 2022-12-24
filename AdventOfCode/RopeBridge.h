#pragma once
#include "AdventDay.h"
#include "Rope.h"

class RopeBridge :
    public AdventDay
{
public:
    RopeBridge();
    void solve(const std::string& input) override;
    bool touches(const Vector2Int& first, const Vector2Int& second) const;
    ~RopeBridge();

private:
    Rope* rope;

};
