#pragma once
#include <string>
using namespace std;

class Reservation
{
private:
	int resourceID;
	string username;
	pair<double, double> reservationTime;
	// I'm not sure what we're doing here, but any
	// set up is gonna be easy to change. But
	// the current placeholder won't work
public:
	Reservation(int, string, pair<double, double>);

	void setResourceID(int);
	void setUsername(string);
	void setReservation(pair<double, double>);

	int getResourceID() const;
	string getUsername() const;
	pair<double,double> getReservation() const;
};

