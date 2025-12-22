#pragma once
#include "Resource.h"

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
		string getSaveSpecifics();
	private:
		string location;
		int capacity;
		string resourceType = "StudyRoom";
};


