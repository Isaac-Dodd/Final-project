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
		return false;
	}
	else
	{
	return true;
	}
}

ostream& operator <<(ostream& out, const Reservation& item)
{
	Dates reservedTime = item.getResPeriod();

	out << item.getUsername() << " " << item.getID() << endl

		<< "Start:\n"
		<< reservedTime.startHour << ":" << reservedTime.startMinute
		<< " " << reservedTime.startMonth << '-' << reservedTime.startDay
		<< '-' << reservedTime.startYear << endl


		<< "Ends:\n"
		<< reservedTime.endHour << ":" << reservedTime.endMinute
		<< " " << reservedTime.endMonth << '-' << reservedTime.endDay
		<< '-' << reservedTime.endYear << endl;

	return(out); 
}