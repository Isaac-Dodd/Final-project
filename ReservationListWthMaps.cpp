#include "ReservationList.h"


ReservationList::ReservationList()
{
	fstream myStream("Reservations.txt", ios::in);
	string ID;
	string username;
	string startDay;
	string startMonth;
	string startYear;
	string endDay;
	string endMonth;
	string endYear;

	if (!myStream.is_open())
	{
		return;
	}
	
	// The txt file is formatted as
	// ID, username, start day, month, year
	// then end day, month, year
	while (!myStream.eof())
	{
		getline(myStream, ID, ',');		// delimiting based on space, can do comma
		getline(myStream, username, ',');
		getline(myStream, startDay, ',');
		getline(myStream, startMonth, ',');
		getline(myStream, startYear, ',');
		getline(myStream, endDay, ',');
		getline(myStream, endMonth, ',');
		getline(myStream, endYear, '\n');
		
		
		logByID[stoi(ID)].push_back( Reservation({ stoi(ID),username,
			Dates{stoi(startDay),stoi(startMonth),stoi(startYear),stoi(endDay),stoi(endMonth),stoi(endYear)} }) );
	}
}

void ReservationList::createReservation(Reservation newReservation)
{
	logByID[newReservation.getID()].push_back(newReservation);
}

void ReservationList::cancelReservation(Reservation endReservation)
{
	auto myTem = find(logByID[endReservation.getID()].begin(), logByID[endReservation.getID()].end(), endReservation);
	logByID[endReservation.getID()].erase(myTem);
}

void ReservationList::displayReservations()
{
	for (auto reservationbyID : logByID)
	{
		for (auto individualRes : reservationbyID.second)
		{
			// outputting all the mapped values
		}
	}
}
// It's probably a good idea to let the user extend their reservation
// if they interfere with their reservation
/*
bool ReservationList::doesCollide(Reservation potentialRes)
{
	int checkId;

	checkId = potentialRes.getID();
	Dates wantedDates = potentialRes.getResPeriod();


	//scheduling must look like {}[] or []{}, not [{]}, {[}], [{}], or {[]}

	for (auto times : logByID[checkId])
	{
		// ALL starts and ends must be greater than or less than the start/end of the other
		Dates setDates = times.getResPeriod();

		// checking for reservations that start while the other thing is reserved
		if(wantedDates.startDay <= setDates.dueYear && wantedDates.startMonth <= setDates)
		
	}

	return false;
}
*/
