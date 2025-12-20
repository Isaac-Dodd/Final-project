#include "Reservation.h"

Reservation::Reservation(int setID, string setUsername, Dates setResPeriod)
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
void Reservation::setResPeriod(Dates setResPeriod)
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
Dates Reservation::getResPeriod() const
{
	return(resPeriod);
}

bool Reservation::operator==(const Reservation& rightside) const
{
	if (resourceID != rightside.getID())
	{
		return false;
	}
	else if (username != rightside.getUsername())
	{
		return false;
	}
	else if (!(resPeriod == rightside.resPeriod))
	{

	}
	else
	{
	return true;
	}
}
