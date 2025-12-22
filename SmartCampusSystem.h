#pragma once
#include "Storage.h"
#include "ReservationList.h"
#include "Admin.h"
#include "Student.h"

// This is just a user access class

// this lets the user interact with the reservation and storage
//We're gonna need a delete to remove stuff from both Reservations and Storage:
//Reservations is a map and Storage is a vector
class SmartCampusSystem
{
private:
    ReservationList currentReservations;
    Storage currentStorage;
    unordered_map<int, bool> usedIds;

public:
    SmartCampusSystem();

    bool availableID(int wantedID);



    vector<Reservation> getById(int);
    vector<Reservation> getByUser(User* user) const;


    void removeResources(Resource* removeResource);
    void addResource(Resource* newResource);
    void removeReservation(Reservation wantRemoved);
    
    vector<Resource*> getAvailable();
    Storage* getStorage();
    ReservationList* getReservationList();
    bool nonConflict(Reservation potentialRes);
};

// to check if a resource is available use the 
// bool nonConflict(Reservation potentialRes);
// and if now creates a conflict don't display
