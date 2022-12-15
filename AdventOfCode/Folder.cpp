#include "Folder.h"

using namespace std;

Folder::Folder(const string name) :
	DiskContent(name)
{
	content = vector<DiskContent*>();
}

const int Folder::getSize() const
{
	int size = 0;
	for (int i = 0; i < content.size(); i++)
		size += content[i]->getSize();
	
	return size;
}

void Folder::addContent(DiskContent* const newContent)
{
	content.push_back(newContent);
}

const std::string Folder::toString(int depth) const
{
	int myDepth = depth + 1;
	string text = "- " + name + " (dir)\n";
	for (int j = 0; j < content.size(); j++)
	{
		for (int i = 0; i < myDepth; i++)
			text.append("  ");
		
		text.append(content[j]->toString(myDepth));
	}
	return text;
}

Folder* Folder::getFolder(const std::string folderName) const
{
	for (int i = 0; i < content.size(); i++)
		if (content[i]->getName() == folderName)
			return (Folder*)content[i];

	return nullptr;
}


