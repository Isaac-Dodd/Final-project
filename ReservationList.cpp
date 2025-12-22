#include "ReservationList.h"

ReservationList::ReservationList()
{
	fstream myStream("Reservations.txt", ios::in);
	string ID;
	string username;

	string startMin;
	string startHr;
	string startDay;
	string startMonth;
	string startYear;

	string endMin;
	string endHr;
	string endDay;
	string endMonth;
	string endYear;

	double loadEndTime;

	time_t t = time(nullptr);
	tm now{};
	localtime_s(&now, &t);

	int year = now.tm_year + 1900;
	int month = now.tm_mon + 1;
	int day = now.tm_mday;
	double hr = now.tm_hour;
	double min = now.tm_min;

	double today = min / 10000 + hr / 100 + day + month * 100 + year * 10000;

	if (!myStream.is_open())
	{
		return;
	}

	// The txt file is formatted as
	// ID, username, start day, month, year
	// then end day, month, year
	if (myStream.peek() == EOF)
	{
		return;
	}

	while (!myStream.eof())
	{
		getline(myStream, ID, ',');		// delimiting based on space, can do comma
		getline(myStream, username, ',');
		getline(myStream, startMin, ',');
		getline(myStream, startHr, ',');
		getline(myStream, startDay, ',');
		getline(myStream, startMonth, ',');
		getline(myStream, startYear, ',');
		getline(myStream, endMin, ',');
		getline(myStream, endHr, ',');
		getline(myStream, endDay, ',');
		getline(myStream, endMonth, ',');
		getline(myStream, endYear, '\n');

		loadEndTime = stod(endMin) / 10000 + stod(endHr) / 100 + stoi(endDay) + stoi(endMonth) * 100 + stoi(endYear) * 10000;

		if (today <= loadEndTime)
		{
			logByID[stoi(ID)].push_back(Reservation({ stoi(ID),username,
				Dates{stoi(startMin),stoi(startHr),stoi(startDay),stoi(startMonth),stoi(startYear),
				stoi(endMin),stoi(endHr),stoi(endDay),stoi(endMonth),stoi(endYear)} }));
		}
	}

	myStream.close();
}

// 1234,idodd0,30,4,20,4,2025,30,5,21,4,2026

void ReservationList::createReservation(Reservation newReservation)
{
	logByID[newReservation.getID()].push_back(newReservation);
}

void ReservationList::cancelReservation(Reservation removeReservation)
{
	auto myTem = find(logByID[removeReservation.getID()].begin(), logByID[removeReservation.getID()].end(), removeReservation);
	logByID[removeReservation.getID()].erase(myTem);
}

void ReservationList::cancelID(int id)
{
	logByID.erase(id);
}

void ReservationList::printAll()const
{
	for(auto& i : logByID)
	{
		cout << "Reservations for resource " << i.first << ": \n";
		for(auto& j : i.second)
		{
			cout << j;
		}
	}
}

bool ReservationList::nonConflict(Reservation potentialRes)
{
	int checkId;

	checkId = potentialRes.getID();
	Dates wantedDates = potentialRes.getResPeriod();

	int wantedStartInt = wantedDates.startDay + wantedDates.startMonth * 100 + wantedDates.startYear * 10000;
	int wantedEndInt = wantedDates.endDay + wantedDates.endMonth * 100 + wantedDates.endYear * 10000;

	for (auto times : logByID[checkId])
	{
		Dates setDates = times.getResPeriod();
		int setStartInt = setDates.startDay + setDates.startMonth * 100 + setDates.startYear * 10000;
		int setEndInt = setDates.endDay + setDates.endMonth * 100 + setDates.endYear * 10000;

		// if it doesn't not overlap then there's overlap
		if (!(setEndInt < wantedStartInt || setStartInt > wantedEndInt))
			return false;

	}

	return true;
}


vector<Reservation> ReservationList::getByUsername(string wantedUsername) const
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

vector<Reservation> ReservationList::getById(int wantedID)
{
	return(logByID[wantedID]);
}

vector<Reservation> ReservationList::passAll() const
{
	vector<Reservation> storedReservations;
	for (auto item : logByID)
	{
		for (auto reservation : item.second)
		{
			storedReservations.push_back(reservation);
		}
	}
	return(storedReservations);
}

ReservationList::~ReservationList()
{
	fstream myStream("Reservations.txt", ios::out);

	bool first = true;

	for (auto indReservation : logByID)
	{
		if (indReservation.second.empty())
			continue;

		for (auto reservationData : indReservation.second)
		{
			// Need this to not add a \n to the end of the file
			if (!first)
				myStream << "\n";
			first = false;

			myStream << indReservation.first << ',';
			myStream << reservationData.getUsername() << ',';
			myStream << reservationData.getResPeriod().startMinute << ',';
			myStream << reservationData.getResPeriod().startHour << ',';
			myStream << reservationData.getResPeriod().startDay << ',';
			myStream << reservationData.getResPeriod().startMonth << ',';
			myStream << reservationData.getResPeriod().startYear << ',';
			myStream << reservationData.getResPeriod().endMinute << ',';
			myStream << reservationData.getResPeriod().endHour << ',';
			myStream << reservationData.getResPeriod().endDay << ',';
			myStream << reservationData.getResPeriod().endMonth << ',';
			myStream << reservationData.getResPeriod().endYear;
		}
	}
}