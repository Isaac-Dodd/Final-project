#include "SmartCampusSystem.h"

SmartCampusSystem::SmartCampusSystem()
{

    for(auto& i : currentStorage.passAll())
    {
        usedIds[i->getId()] = true;
    }
}


bool SmartCampusSystem::availableID(int wantedID)
{
	return !usedIds[wantedID];
}

void SmartCampusSystem::removeResources(Resource* removeResource)
{
	int id = removeResource->getId();
	currentReservations.cancelID(id);
	usedIds[id] = false;

	auto item = find(currentStorage.passAll().begin(), currentStorage.passAll().end(), removeResource);
	currentStorage.passAll().erase(item);
}
void SmartCampusSystem::addResource(Resource* newResource)
{
	currentStorage.passAll().push_back(newResource);
	usedIds[newResource->getId()] = true;
}

void SmartCampusSystem::removeReservation(Reservation wantRemoved)
{
	currentReservations.cancelReservation(wantRemoved);
}


vector<Reservation> SmartCampusSystem::getById(int id)
{
	return(currentReservations.getById(id));
}

vector<Reservation> SmartCampusSystem::getByUser(User* user) const
{
	return(currentReservations.getByUsername(user->getUsername()));
}

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