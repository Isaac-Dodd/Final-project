#pragma once

#include <iostream>
#include <string>
#include "Dates.h"
using namespace std;

class Reservation
{
private:
	int resourceID;
	// tie to the user eventually
	string username; 
	Dates resPeriod;
public:
	Reservation(int ID, string username, Dates resPeriod);
	void setID(int);
	void setUsername(string);
	void setResPeriod(Dates newPeriod);

	int getID() const;
	string getUsername() const;
	Dates getResPeriod() const;

	bool operator==(const Reservation& rightside) const;

	friend ostream& operator <<(ostream& out, const Reservation& item);
};
