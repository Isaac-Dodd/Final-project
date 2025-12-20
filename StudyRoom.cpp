#include "StudyRoom.h"

StudyRoom::StudyRoom(int setID, string setName, bool setChecked,
	int newCapacity, string setLocation, string setHours)
	: Resource(setID, setName, setChecked)
{
	capacity = newCapacity;
	location = setLocation;
	availableHours = setHours;
}

void StudyRoom::setCapacity(int newCapacity)
{
	capacity = newCapacity;
}
void StudyRoom::setLocation(string setLocation)
{
	location = setLocation;
}
void StudyRoom::setAvailabilityHours(string setHours)
{
	availableHours = setHours;
}

string StudyRoom::getLocation() const
{
	return(location);
}
string StudyRoom::getAvailabilityHour() const
{
	return(availableHours);
}
int StudyRoom::getCapacity() const
{
	return(capacity);
}

void StudyRoom::getResourceSpecifics()
{

}
