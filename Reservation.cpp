#include "Reservation.h"

Reservation::Reservation(int newID, string newUsername, pair<double, double> newReservation)
{
	resourceID = newID;
	username = newUsername;
	reservationTime = newReservation;
}

void Reservation::setResourceID(int newID)
{
	resourceID = newID;
}
void Reservation::setUsername(string newUsername)
{
	username = newUsername;
}
void Reservation::setReservation(pair<double, double> newReservation)
{
	reservationTime = newReservation;
}

int Reservation::getResourceID() const
{
	return(resourceID);
}
string Reservation::getUsername() const
{
	return(username);
}
pair<double, double> Reservation::getReservation() const
{
	return(reservationTime);
}
