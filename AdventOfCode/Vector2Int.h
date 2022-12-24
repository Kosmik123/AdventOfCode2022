#pragma once
#include <ostream>

struct Vector2Int
{
    int x;
    int y;

    Vector2Int();
    Vector2Int(int x, int y);
    void move(const Vector2Int& direction);
    void move(int x, int y);

    inline bool operator<(const Vector2Int& other) const
    {
        if (x < other.x)
            return true;
        else if (x > other.x)
            return false;
        else
            return y < other.y;
    }

    bool operator==(const Vector2Int& other);





private:
    static const int quarterInt = sizeof(int) / 4;
};

std::ostream& operator<<(std::ostream& stream, const Vector2Int& vector);

