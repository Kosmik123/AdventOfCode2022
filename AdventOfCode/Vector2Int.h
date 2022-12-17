#pragma once

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

private:
    static const int quarterInt = sizeof(int) / 4;
};

