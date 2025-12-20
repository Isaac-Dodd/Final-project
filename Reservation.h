#pragma once
#include "Dates.h"
#include <string>
using namespace std;



class Reservation
{
private:
	int resourceID;
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
};

