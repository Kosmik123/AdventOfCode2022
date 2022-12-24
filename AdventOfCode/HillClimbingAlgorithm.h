#pragma once
#include "AdventDay.h"
#include <queue>
#include <set>

struct TerrainNode;

class HillClimbingAlgorithm :
    public AdventDay
{
public:
    void solve(const std::string& input) override;



private:
    int width = 0;
    int length = 0;
    TerrainNode** heights = nullptr;
    Vector2Int startPosition;
    Vector2Int endPosition;
    std::list<Vector2Int> positionsToCheck;
    std::set<Vector2Int> alreadyCheckedPositions;

    void checkNode(int x, int y);
    void setNeighbour(TerrainNode* neighbour, TerrainNode* node);

    const Vector2Int& getNextPositionToCheck();

};


struct TerrainNode
{
    Vector2Int position;
    TerrainNode* parent = nullptr;
    int height = -1;

    unsigned int distanceFromStart = -1;
    unsigned int distanceToEnd = -1;

    TerrainNode ()
    {

    }

    TerrainNode(int x, int y, int height)
        : height(height)
    {
        position = Vector2Int(x, y);
    }

    TerrainNode(int x, int y, int height, TerrainNode* parent)
        : TerrainNode(x, y, height)
    {
        this->parent = parent;
    }

    void setParent(TerrainNode* parent)
    {
        unsigned int newDistance = parent->distanceFromStart + 1;
        if (newDistance < distanceFromStart)
        {
            this->parent = parent;
            distanceFromStart = newDistance;
        }
    }

};
