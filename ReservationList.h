#pragma once
#include "Reservation.h"
#include <vector>
#include <fstream>

class ReservationList
{
private:
	vector<Reservation> currentReservations;
	bool succesfulLoad;
public:
	ReservationList();
	void createReservation(int, string, pair<double, double>);
	void cancelReservation(int ID);
	bool isConflict();
};

