#include "ReservationList.h"

ReservationList::ReservationList()
{
	string resourceID;
	string userName;
	string reservationStart;
	string reservationEnd;

	fstream myStream("Reservations.txt", ios::in);

	if (!myStream.is_open())
		succesfulLoad = false;
	else
		succesfulLoad = true;

	while (!myStream.eof())
	{
		// Handling this is gonna come down to what our time is like

		currentReservations.push_back(Reservation(stoi(resourceID), userName, { stod(reservationStart),stod(reservationEnd)}));
	}
}

void ReservationList::createReservation(int resourceID, string userName, pair<double, double> reservation)
{
	currentReservations.push_back(Reservation(resourceID, userName, reservation));
}

// We never discussed how this was gonna get done
void ReservationList::cancelReservation(int ID)
{

}

bool ReservationList::isConflict()
{
	return true;
}
