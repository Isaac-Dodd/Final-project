#include "Storage.h"
#include <fstream>

Storage::Storage()
{
	fstream myStream("Resources.txt", ios::in);
	string id;
	string name;
	//string checkedOut = 0;
	string resourceType;
	string capacity;
	string availableHours;
	string location;
	string tutorName;
	
	if (!myStream.is_open())
	{
		return;
	}

	if (myStream.peek() == EOF)
	{
		return;
	}

	while (!myStream.eof())
	{
		getline(myStream, id, '|');
		getline(myStream, name, '|');
		//getline(myStream, checkedOut, '|');
		getline(myStream, resourceType, '|');
		if (resourceType == "TutoringSession")
		{
			getline(myStream, location, '|');
			getline(myStream, tutorName, '|');
			getline(myStream, availableHours, '\n');
			
			// {10, 17}
			string temp = "";
			int start, end;
			for(int i = 1; i < availableHours.size() - 1; ++i)
			{
				
				if(availableHours[i] == ',')
				{
					start = stoi(temp);
					temp.clear();
				}
				else temp += availableHours[i];
			}
			end = stoi(temp);
			pair<int, int> hours = {start, end};
			
			allResources.push_back(new TutoringSession(stoi(id), name, location, tutorName, hours));
		}
		else if (resourceType == "StudyRoom")
		{
			getline(myStream, location, '|');
			getline(myStream, capacity, '|');
			getline(myStream, availableHours, '\n');
			// {10, 17}
			string temp = "";
			int start, end;
			for (int i = 1; i < availableHours.size() - 1; ++i)
			{

				if (availableHours[i] == ',')
				{
					start = stoi(temp);
					temp.clear();
				}
				else temp += availableHours[i];
			}
			end = stoi(temp);
			pair<int, int> hours = { start, end };
			allResources.push_back(new StudyRoom(stoi(id), name, location, stoi(capacity), hours));
		}
		
	}

	myStream.close();
}



void Storage::printAll() const
{
	for (auto item : allResources)
	{
		cout << *item << endl << endl;
	}
}




Resource* Storage::getResource(int resourceId)
{
	for(auto& i : allResources)
	{
		if(i->getId() == resourceId) return i;
	}
	
	return nullptr;
}

vector<Resource*>& Storage::passAll()
{
	return(allResources);
}

Storage::~Storage()
{
	fstream myStream("Resources.txt", ios::out);

	bool first = true;

	for (auto indResource: allResources)
	{
			// Need this to not add a \n to the end of the file
			if (!first)
				myStream << "\n";
			first = false;

			
			myStream << indResource->getId() << '|'
					 << indResource->getName() << '|'
					 << indResource->getResourceType() << '|'
					 << indResource->getSaveSpecifics()
					 << "{" << indResource->getAvailability().first << "," << indResource->getAvailability().second << "}";
	}

	myStream.close();
}