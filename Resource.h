#pragma once
#include <string>

using namespace std;

class Resource
{
private:
	int id;
	string name;
	bool checkedOut;
public:
	Resource(int setID, string setName, bool setChecked);
	void setId(int setID);
	void setName(string setName);
	void setCheckedOut(bool setChecked);

	// The reservation is tied to the 
	// reservations class, not this one
	// getReservation() const;
	int getId() const;
	string getName() const;
	bool isCheckedOut() const;
	virtual void getResourceSpecifics() const = 0;
	
};

