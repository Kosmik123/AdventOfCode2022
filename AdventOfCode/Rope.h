

class Rope
{
public:
    Rope(int length = 2, const Vector2Int& startPosition = Vector2Int(0, 0))
    {
        for (int i = 0; i < length; i++)
        {
            nodes.push_back(startPosition);
        }
    }

    const int size() const
    {
        return nodes.size();
    }

    const Vector2Int head() const
    {
        return nodes.at(0);
    }

    const Vector2Int tail() const
    {
        return nodes.at(nodes.size() - 1);
    }

    const Vector2Int at(int index)
    {
        return nodes.at(index);
    }

    void moveByHeadUp()
    {
        moveNode(0, 0, 1);
    }

    void moveByHeadDown()
    {
        moveNode(0, 0, - 1);
    }

    void moveByHeadLeft()
    {
        moveNode(0, -1, 0);
    }

    void moveByHeadRight()
    {
        moveNode(0, 1, 0);
    }


private:
    std::vector<Vector2Int> nodes;

    void moveNode(int nodeIndex, int x, int y)
    {
        Vector2Int previousPosition = nodes[nodeIndex];
        nodes[nodeIndex].move(x, y); 
        Vector2Int currentNode = nodes[nodeIndex]; 

        int nextNodeIndex = nodeIndex + 1;
        if (nextNodeIndex >= size())
            return;

        Vector2Int nextNode = nodes[nextNodeIndex];
        if (touches(nextNode, currentNode) == false)
        {
            if (areInTheSameAxis(nextNode, previousPosition))
            {
                if (areInTheSameAxis(nextNode, currentNode))
                {
                    // repeat the same move or move to position of previous none (doesnt matter)
                    moveNode(nextNodeIndex, x, y);
                }
                else
                {
                    // repeat the same move 
                    moveNode(nextNodeIndex, x, y);
                }
            }
            else
            {
                if (areInTheSameAxis(nextNode, currentNode))
                {
                    // weirdest situation. Calculate mean position
                    int xNew = (currentNode.x + nextNode.x) / 2;
                    int yNew = (currentNode.y + nextNode.y) / 2;
                    int xDiff = xNew - nextNode.x;
                    int yDiff = yNew - nextNode.y;
                    moveNode(nextNodeIndex, xDiff, yDiff);
                }
                else
                {
                    // move to position of previous none
                    int xDiff = previousPosition.x - nextNode.x;
                    int yDiff = previousPosition.y - nextNode.y;
                    moveNode(nextNodeIndex, xDiff, yDiff);
                }
            }
        }
    }

    void moveNode(int nodeIndex, const Vector2Int& position)
    {
        moveNode(nodeIndex, position.x, position.y);
    }

    bool touches(const Vector2Int& first, const Vector2Int& second) const
    {
        int horizontalDistance = first.x - second.x;
        int verticalDistance = first.y - second.y;
        return (horizontalDistance <= 1) && (horizontalDistance >= -1)
            && (verticalDistance <= 1) && (verticalDistance >= -1);
    }

    bool areInTheSameAxis(const Vector2Int& node1, const Vector2Int& node2) const
    {
        return node1.x == node2.x || node1.y == node2.y;
    }

};
