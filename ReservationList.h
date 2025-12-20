#pragma once

#include "Reservation.h"
#include <vector>
#include <fstream>
#include <unordered_map>
#include <algorithm>

class ReservationList
{
private:
	// This variable hold the reservations by ID, useful
	// for detecting collisions
	unordered_map<int, vector<Reservation> > logByID;
public:
	ReservationList();
	void createReservation(Reservation newReservation);
	void cancelReservation(Reservation endReservation);
	
	bool validTimes(Reservation potentialRes);
	void displayReservations();

	~ReservationList();

};

