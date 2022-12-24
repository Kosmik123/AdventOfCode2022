#pragma once
#include <string>
#include <queue>

enum class OperationType
{
    None,
    Addition,
    Multiplication,
    Exponentiation,
};

class Monkey
{
public:
    Monkey();
    Monkey(const std::string& inputData, bool doLog = false);
    bool hasItems() const;
    void inspectItem(int& targetIndex, int& worryLevel) const;
    void removeFirstItem();
    void addItem(int worryValue);

    void setOperation(OperationType type, int value);

private:
    bool log;

    std::queue<int> items;

    OperationType operationType = OperationType::None;
    int operationValue = 0;

    int divisibilityTest;

    int trueTarget;
    int falseTarget;
};
