#pragma once
#include "Resource.h"

/*
* I would change the available hours to ints for the 
* opening hour and minute, and the closing hour and
* minute. Then a string for am and pm
* 
* I also never set up the virtual. I don't know what
* you want outputted
*
* If you wanna readd the whiteboard bool go for it
* it's not on the UML though
*/

class StudyRoom : public Resource
{
private:
	int capacity;
	string availableHours;
	string location;
private:
	StudyRoom(int setID, string setName, bool setChecked, 
		int newCapacity, string setLocation, string setHours);

	void setLocation(string setLocation);
	void setAvailabilityHours(string setHours);
	void setCapacity(int newCapacity);
	
	string getLocation() const;
	string getAvailabilityHour() const;
	int getCapacity() const;

	virtual void getResourceSpecifics();
};

