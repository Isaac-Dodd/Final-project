#pragma once

#include "Reservation.h"
#include <vector>
#include <fstream>
#include <unordered_map>

class ReservationList
{
private:
	// This variable holds all the reservations
	vector<Reservation> currentReservations;
	// This variable hold the reservations by ID, useful
	// for detecting collisions
	unordered_map<int, vector<Reservation> > logByID;
public:
	ReservationList();
	//bool doesCollide(Reservation);
};

