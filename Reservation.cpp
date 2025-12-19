#include "Reservation.h"

Reservation::Reservation(int setID, string setUsername, dates setResPeriod)
{
	resourceID = setID;
	username = setUsername;
	resPeriod = setResPeriod;
}

void Reservation::setID(int setID)
{
	resourceID = setID;
}
void Reservation::setUsername(string setUsername)
{
	username = setUsername;
}
void Reservation::setResPeriod(dates setResPeriod)
{
	resPeriod = setResPeriod;
}
int Reservation::getID() const
{
	return(resourceID);
}
string Reservation::getUsername() const
{
	return(username);
}
dates Reservation::getResPeriod() const
{
	return(resPeriod);
}
