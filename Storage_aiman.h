#ifndef STORAGE_H_
#define STORAGE_H_

#include "Resource.h"
#include "StudyRoom.h"
#include "TutoringSession.h"
#include "ReservationList.h"

#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>

/*
 * Storage
 * --------
 * Manages all resources in the system.
 * Handles loading/saving resources and searching.
 */

 // Forward declaration for time formatting helper
std::string formatTimeAMPM(int hour);

class Storage
{
private:
    std::vector<Resource*> storage;
    std::unordered_map<int, bool> idMap; // for unique IDs

public:
    Storage();
    ~Storage();

    bool loadResources(const std::string& filename = "Resources.txt");
    bool saveResources(const std::string& filename = "Resources.txt") const;

    /* Resources.txt example :
       StudyRoom,123456,Study Room 2,Library,9,12,0,5|1
       StudyRoom,786567,Study Room 3,Library,9,17,0,5|1
       TutoringSession,546389,Tutoring Session,BSTIC,10,15,0,Lily Hawthorne|CS1C
       TutoringSession,786490,Tutoring Session,BSTIC,8,15,0,Hannah Brown|CS1C
        StudyRoom,892748,Study Room 2,Library,9,18,0,3|1
    */
    
    // Lists all resources with availability displayed in AM/PM format
    void listResources() const;

    // Finds a resource by ID
    Resource* findById(int id) const;
    std::vector<Resource*> searchByName(const std::string& key) const;

    // Adds a resource if its ID is unique
    bool addResource(Resource* resource);   // checks unique ID
    bool removeResourceById(int id);        // deletes object
    bool editResourceName(int id, const std::string& newName);
};

#endif
