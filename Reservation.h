#pragma once

#include <string>
using namespace std;

struct Dates
{
	int startDay;
	int startMonth;
	int startYear;

	int dueDay;
	int dueMonth;
	int dueYear;

	bool operator ==(const Dates& rightSide) const
	{
		if (startDay != rightSide.startDay || dueDay != rightSide.dueDay)
			return false;

		else if (startMonth!= rightSide.startMonth || dueMonth != rightSide.dueMonth)
			return false;

		else if (startYear!= rightSide.startYear || dueYear != rightSide.dueYear)
			return false;

		else
			return true;
	}
};

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

