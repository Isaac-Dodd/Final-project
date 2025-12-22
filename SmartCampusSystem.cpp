#include "SmartCampusSystem.h"

SmartCampusSystem::SmartCampusSystem()
{
	currentReservations = ReservationList();
    currentStorage = Storage();

    for(auto& i : currentStorage.passAll())
    {
        usedIds[i->getId()] = true;
    }
}

void SmartCampusSystem::listResources() const
{
	
}

bool SmartCampusSystem::availableID(int wantedID)
{
	return !usedIds[wantedID];
}

void SmartCampusSystem::removeResources(int id)
{
	currentReservations.cancelID(id);
	usedIds[id] = false;
}

void SmartCampusSystem::removeReservation(Reservation wantRemoved)
{
	currentReservations.cancelReservation(wantRemoved);
}

//void SmartCampusSystem::printUserReservations(Student currentStudent) const
//{
//	vector<Reservation> studentsReservation;
//	studentsReservation = currentReservations.getByUsername(currentStudent.getUsername());
//
//	if (!studentsReservation.empty())
//	{
//		for (auto reservation : studentsReservation)
//		{
//			Dates reservedTime = reservation.getResPeriod();
//
//			cout << reservation.getID() << endl;
//			cout << "Start:\n";
//			cout << reservedTime.startHour << ":" << reservedTime.startMinute
//				<< " " << reservedTime.startMonth << '-' << reservedTime.startDay
//				<< '-' << reservedTime.startYear << endl;
//
//
//			cout << "Ends:\n";
//			cout << reservedTime.endHour << ":" << reservedTime.endMinute
//				<< " " << reservedTime.endMonth << '-' << reservedTime.endDay
//				<< '-' << reservedTime.endYear << endl;
//		}
//	}
//}

//void SmartCampusSystem::printResourceReservations(int) const
//{
//
//}

vector<Reservation> SmartCampusSystem::getById(int id)
{
	return(currentReservations.getById(id));
}

vector<Reservation> SmartCampusSystem::getByUser(User* user) const
{
	return(currentReservations.getByUsername(user->getUsername()));
}

//vector<Reservation> SmartCampusSystem::passAll() const;

// Check in debugging
Storage* SmartCampusSystem::getStorage()
{
	return &currentStorage;
}
ReservationList* SmartCampusSystem::getReservationList()
{
    return &currentReservations;
}

vector<Resource*> SmartCampusSystem::getAvailable()
{
	int checkID;
	vector<Resource*> available;

	time_t t = time(nullptr);
	tm now{};
	localtime_s(&now, &t);

	int year = now.tm_year + 1900;
	int month = now.tm_mon + 1;
	int day = now.tm_mday;
	int hr = now.tm_hour;
	int min = now.tm_min;
	Dates currentTime{ min,hr,day,month,year,min,hr,day,month,year };
	
	for (auto resource : currentStorage.passAll() )
	{
		checkID = (*resource).getId();
		if (nonConflict(Reservation(checkID, "", currentTime)))
		{
			available.push_back(resource);
		}
	}

	return(available);
}

bool SmartCampusSystem::nonConflict(Reservation potentialRes)
{
	return currentReservations.nonConflict(potentialRes);
}