#include "Vector2Int.h"

Vector2Int::Vector2Int()
{
    x = 0;
    y = 0;
}

Vector2Int::Vector2Int(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Vector2Int::move(const Vector2Int& direction)
{
    move(direction.x, direction.y);
}

void Vector2Int::move(int x, int y)
{
    this->x += x;
    this->y += y;
}
