#pragma once
#include "DiskContent.h"
#include <vector>

class Folder :
    public DiskContent
{
public:
    Folder(const std::string name);
    const int getSize() const override;
    void addContent(DiskContent* const newContent);
    const std::string toString(int depth = 0) const override;
    Folder* getFolder(const std::string folderName) const;

protected:
    std::vector<DiskContent*> content;

private:

};