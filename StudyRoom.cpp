#pragma once
#include "Resource.h"

/*
* I would change the available hours to ints for the 
* opening hour and minute, and the closing hour and
* minute. Then a string for am and pm
*/

class StudyRoom : public Resource
{
private:
	int capacity;
	string availableHours;
	int capacity;
private:
	StudyRoom(int, string, int);
	string getLocation() const;
	string getAvailabilityHour() const;
	int getCapacity() const;
	void setLocation(string);
	void setAvailabilityHours(string);
	int setCapacity(int);
};


