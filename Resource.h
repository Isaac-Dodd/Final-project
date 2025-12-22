#pragma once
#include <string>
#include <iostream>

using namespace std;

class Resource
{
protected:
	int id;
	string name;
	string resourceType;
	pair<int, int> hours;
	//bool checkedOut;
public:
	Resource(int setID, string setName, pair<int, int> hours);
	//Resource(const Resource& otherObject);
	void setId(int setID);
	void setName(string setName);
	void setAvailability(pair<int, int> newHours);
	//void setCheckedOut(bool setChecked);
	

		

	// The reservation is tied to the 
	// reservations class, not this one
	// getReservation() const;
	int getId() const;
	string getName() const;
	pair<int, int> getAvailability();
	//bool isCheckedOut() const;
	virtual void getResourceSpecifics() const = 0;
	virtual string getSaveSpecifics() = 0;
	virtual string getResourceType() = 0;
	//virtual void setResourceType() = 0;
	
	friend ostream& operator<<(ostream& out, const Resource& resource);
	
};

