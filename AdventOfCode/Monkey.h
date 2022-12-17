#pragma once
#include <string>
#include <queue>

class Monkey
{
    enum OperationType
    {
        None,
        Addition,
        Multiplication,
        Exponentiation,
    };

public:
    Monkey(const std::string& inputData, bool doLog = false);
    bool hasItems() const;
    void inspectItem(int& targetIndex, int& worryLevel) const;
    void removeFirstItem();
    void addItem(int worryValue);

private:
    bool log;

    std::queue<int> items;

    OperationType operationType = None;
    int operationValue = 0;

    int divisibilityTest;

    int trueTarget;
    int falseTarget;
};


