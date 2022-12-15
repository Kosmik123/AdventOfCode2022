#include "TuningTrouble.h"

using namespace std;

void TuningTrouble::solve(const std::string& input)
{
	output1 = indexOfMarker(input, 4);
	output2 = indexOfMarker(input, 14);
}

const int TuningTrouble::indexOfMarker(const std::string& data, const int markerLength) const
{
	queue<char> currentlyCheckedData;
	for (int i = 0; i < markerLength; i++)
	{
		currentlyCheckedData.push(data[i]);
	}

	int index = markerLength;
	while (index < data.length())
	{
		if (isStartMarker(currentlyCheckedData))
			break;

		currentlyCheckedData.pop();
		currentlyCheckedData.push(data[index]);
		index++;
	}

	return index;
}

const bool TuningTrouble::isStartMarker(std::queue<char> dataCopy) const
{
	vector<char> dataChars;
	while (dataCopy.empty() == false)
	{
		dataChars.push_back(dataCopy.front());
		dataCopy.pop();
	}

	for (int j = 0; j < dataChars.size() - 1; j++)
	{
		for (int i = j + 1; i < dataChars.size(); i++)
		{
			if (dataChars[i] == dataChars[j])
				return false;
		}
	}

	return true;
}
