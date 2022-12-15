#include "File.h"

File::File(const std::string& name, const int size) :
	DiskContent(name),
	size(size)
{ }

const int File::getSize() const
{
	return size;
}

const std::string File::toString(int depth) const
{
	return "- " + name + " (file, size=" + std::to_string(size) + ")\n";
}
