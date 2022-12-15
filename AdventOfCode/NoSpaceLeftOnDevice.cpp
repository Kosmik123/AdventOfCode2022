#include "NoSpaceLeftOnDevice.h"
#include <list>
#include <stack>
#include "Folder.h"
#include "File.h"
#include <iostream>

using namespace std;

void NoSpaceLeftOnDevice::solve(const std::string& input)
{

	list<string> lines;
	splitString(input, lines, enter);
	
	Folder* rootFolder = new Folder("/");
	stack<Folder*> visitedFolder;
	
	list<Folder*> allFolders;
	for (auto line = lines.begin(); line != lines.end(); ++line)
	{
		if (line->at(0) == '$')
		{
			vector<string> lineElements;
			splitString(*line, lineElements, " ");
			string command = lineElements[1];
			if (command == "cd")
			{
				string argument = lineElements[2];
				if (argument == "/")
				{
					visitedFolder = stack<Folder*>();
					visitedFolder.push(rootFolder);
				}
				else if (argument == "..")
				{
					visitedFolder.pop();
				}
				else
				{
					Folder* newVisited = visitedFolder.top()->getFolder(argument);
					if (newVisited == nullptr)
						return;
					
					visitedFolder.push(newVisited);
				}
			}
			else // ls
			{
				// WAIT FOR INFO
			}
		}
		else // INFO
		{
			vector<string> lineElements;
			splitString(*line, lineElements, " ");
			string type = lineElements[0];
			string name = lineElements[1];
			if (type == "dir")
			{
				auto newFolder = new Folder(name);
				visitedFolder.top()->addContent(newFolder);
				allFolders.push_back(newFolder);
			}
			else  // FILE
			{
				int size = stoi(type);
				visitedFolder.top()->addContent(new File(name, size));
			}
		}
	}

	list<Folder*> smallFolders;
	for (auto iterator = allFolders.begin(); iterator != allFolders.end(); ++iterator)
	{
		Folder* folder = *iterator;
		if (folder->getSize() <= bigFolderSize)
			smallFolders.push_back(folder);
	}

	int sum = 0;
	for (auto iterator = smallFolders.begin(); iterator != smallFolders.end(); ++iterator)
	{
		sum += (*iterator)->getSize();
	}
	output1 = sum;

	int takenMemory = rootFolder->getSize();
	int remainingMemory = wholeMemory - takenMemory;
	int sizeToFree = memoryNeededForUpdate - remainingMemory;

	Folder* smallestValidFolder = nullptr;
	for (auto folder = allFolders.begin(); folder != allFolders.end(); ++folder)
	{
		int folderSize = (*folder)->getSize();
		if (folderSize > sizeToFree)
			if (smallestValidFolder == nullptr || folderSize < smallestValidFolder->getSize())
				smallestValidFolder = *folder;
	}

	output2 = smallestValidFolder->getSize();

	//cout << "Whole size: " << takenMemory << endl;
	//cout << rootFolder->toString();
}
