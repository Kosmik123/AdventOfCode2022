#pragma once

#include <string>


class DiskContent
{
public:
    virtual const int getSize() const = 0;
    virtual const std::string toString(int depth = 0) const = 0;
    const std::string getName() const;

protected:
    DiskContent(const std::string name);
    std::string name;

};