#pragma once

#include "Reservation.h"
#include <vector>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class ReservationList
{
private:
	// This variable hold the reservations by ID, useful
	// for detecting collisions
	unordered_map<int, vector<Reservation>> logByID;
public:
	ReservationList();
	void createReservation(Reservation newReservation);
	void cancelReservation(Reservation removeReservation);
	void printAll()const;

	void cancelID(int id);
	bool nonConflict(Reservation potentialRes);

	vector<Reservation> getById(int);
	vector<Reservation> getByUsername(string) const;
	vector<Reservation> passAll() const;

	~ReservationList();
};