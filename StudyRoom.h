#pragma once
#include "Resource.h"

/*
* I would change the available hours to ints for the 
* opening hour and minute, and the closing hour and
* minute. Then a string for am and pm
* 
* I also never set up the virtual. I don't know what
* you want outputted
*/

class StudyRoom : public Resource
{
	public:
		StudyRoom(int setID, string setName, string setLocation, int newCapacity,
			      pair<int, int> hours);

		void setLocation(string setLocation);
		void setAvailabilityHours(pair<int, int> newHours);
		void setCapacity(int newCapacity);

		string getLocation() const;
		int getCapacity() const;

		void getResourceSpecifics() const;
		string getResourceType();
	private:
		string location;
		int capacity;
		string resourceType = "StudyRoom";
};


