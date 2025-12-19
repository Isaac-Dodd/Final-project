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
		
		currentReservations.push_back({ stoi(ID),username,
			dates{stoi(startDay),stoi(startMonth),stoi(startYear),stoi(endDay),stoi(endMonth),stoi(endYear)} });
		
		logByID[stoi(ID)].push_back( Reservation({ stoi(ID),username,
			dates{stoi(startDay),stoi(startMonth),stoi(startYear),stoi(endDay),stoi(endMonth),stoi(endYear)} }) );
	}
}
