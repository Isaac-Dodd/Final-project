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

    void listResources() const;
    bool availableID(int wantedID);

    Storage* getStorage();
    ReservationList* getReservationList();


    //void printUserReservations(User currentStudent) const;
    //void printResourceReservations(int) const;
    //void printAvailable();

    // Use of maps makes this impossible to make const
    vector<Reservation> getById(int);
    vector<Reservation> getByUser(User* user) const;
    //vector<Reservation> passAll() const;

    void removeResources(int id);
    void removeReservation(Reservation wantRemoved);
    
    vector<Resource*> getAvailable();
    bool nonConflict(Reservation potentialRes);
};

// to check if a resource is available use the 
// bool nonConflict(Reservation potentialRes);
// and if now creates a conflict don't display
