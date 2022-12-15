#include "DiskContent.h"

using namespace std;

const string DiskContent::getName() const
{
	return name;
}

DiskContent::DiskContent(const std::string name)
{
	this->name = name;
}

