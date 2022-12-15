#pragma once
#include "DiskContent.h"

class File :
    public DiskContent
{
public:
    File(const std::string& name, const int size = 0);
    const int getSize() const override;
    const std::string toString(int depth = 0) const override;

protected:
    int size;

private:


};
