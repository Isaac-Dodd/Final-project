#pragma once

#include <string>
using namespace std;

struct dates
{
	int startDay;
	int dueDay;

	int startMonth;
	int dueMonth;

	int startYear;
	int dueYear;
};

class Reservation
{
private:
	int resourceID;
	string username; 
	dates resPeriod;
public:
	Reservation(int ID, string username, dates resPeriod);
	void setID(int);
	void setUsername(string);
	void setResPeriod(dates newPeriod);

	int getID() const;
	string getUsername() const;
	dates getResPeriod() const;
};

