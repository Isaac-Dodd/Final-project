#include "StudyRoom.h"

StudyRoom::StudyRoom(int setID, string setName, string setLocation, 
					 int newCapacity, pair<int, int> hours)
	: Resource(setID, setName, hours)
{
	capacity = newCapacity;
	location = setLocation;
}

void StudyRoom::setCapacity(int newCapacity)
{
	capacity = newCapacity;
}
void StudyRoom::setLocation(string setLocation)
{
	location = setLocation;
}


string StudyRoom::getLocation() const
{
	return(location);
}

int StudyRoom::getCapacity() const
{
	return(capacity);
}

void StudyRoom::getResourceSpecifics() const
{
	cout << "Location : " << location << endl
		 << "Capacity: " << capacity << endl
		 << "Available Hours: " << hours.first << " to " << hours.second << endl;
}


string StudyRoom::getSaveSpecifics()
{
	return(location + "|" + to_string(capacity) + "|" /*+ "{" + to_string(getAvailability().first) + "," + to_string(getAvailability().second)
		+ "}"*/);
}
//location|capacity|{9,17}

string StudyRoom::getResourceType()
{
	return "StudyRoom";
}