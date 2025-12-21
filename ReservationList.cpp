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

	int loadEndTime;

	time_t t = time(nullptr);
	tm now{};
	localtime_s(&now, &t);  // MSVC-safe version
	int year = now.tm_year + 1900;
	int month = now.tm_mon + 1;
	int day = now.tm_mday;

	int today = day + month * 100 + year * 10000;

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
		
		loadEndTime = stoi(endDay) + stoi(endMonth) * 100 + stoi(endYear) * 10000;

		if (today <= loadEndTime)
		{
		logByID[stoi(ID)].push_back( Reservation({ stoi(ID),username,
			Dates{stoi(startDay),stoi(startMonth),stoi(startYear),stoi(endDay),stoi(endMonth),stoi(endYear)} }) );
		}
	}

	myStream.close();

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

bool ReservationList::validTimes(Reservation potentialRes)
{
	int checkId;

	checkId = potentialRes.getID();
	Dates wantedDates = potentialRes.getResPeriod();

	int wantedStartInt = wantedDates.startDay + wantedDates.startMonth * 100 + wantedDates.startYear * 10000;
	int wantedEndInt = wantedDates.dueDay + wantedDates.dueMonth * 100 + wantedDates.dueYear * 10000;

	for (auto times : logByID[checkId])
	{
		Dates setDates = times.getResPeriod();
		int setStartInt = setDates.startDay + setDates.startMonth * 100 + setDates.startYear * 10000;
		int setEndInt = setDates.dueDay + setDates.dueMonth * 100 + setDates.dueYear * 10000;

		// if it doesn't not overlap then there's overlap
		if (!(setEndInt < wantedStartInt || setStartInt > wantedEndInt))
			return false;
		
	}

	return true;
}


vector<Reservation> ReservationList::getByUsername(string wantedUsername)
{
	vector<Reservation> returnVec;

	for (auto reservationVec : logByID)
	{
		for (auto indReservation : reservationVec.second)
		{
			if (indReservation.getUsername() == wantedUsername)
				returnVec.push_back(indReservation);
		}
	}

	return(returnVec);
}

ReservationList::~ReservationList()
{
	fstream myStream("Reservations.txt", ios::out);

	bool first = true;

	for (auto indReservation : logByID)
	{
		for (auto reservationData : indReservation.second)
		{
		// Need this to not add a \n to the end of the file
		if (!first)
			myStream << "\n";
		first = false;

		myStream << indReservation.first << ',';
		myStream << reservationData.getUsername() << ',';
		myStream << reservationData.getResPeriod().startDay << ',';
		myStream << reservationData.getResPeriod().startMonth << ',';
		myStream << reservationData.getResPeriod().startYear << ',';
		myStream << reservationData.getResPeriod().dueDay << ',';
		myStream << reservationData.getResPeriod().dueMonth << ',';
		myStream << reservationData.getResPeriod().dueYear;
		}
	}
}

