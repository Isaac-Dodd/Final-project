#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <string>
#include <iostream>
#include <sstream>
#include <utility>

/*
 * Resource.h
 * -----------
 * Abstract base class for all reservable resources.
 * Supports polymorphism for StudyRoom and TutoringSession.
 */

class Resource
{
private:
    int id;
    std::string name;
    std::string location;
    std::pair<int, int> availability; // e.g. 9:00 to 17:00 (military-ish)
    bool checkedOut;

public:
    Resource(int id, std::string n, std::string l, std::pair<int, int> a, bool co)
        : id(id), name(n), location(l), availability(a), checkedOut(co) {
    }

    virtual ~Resource() = default;

    // Returns the specific resource type (StudyRoom or TutoringSession)
    virtual std::string getType() const = 0;

    // Outputs resource-specific information
    virtual void getResourceSpecifics() const = 0;

    // for saving/loading
    virtual std::string specificsToCSV() const = 0;
    virtual void specificsFromCSV(const std::string& csv) = 0;

    // getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getLocation() const { return location; }
    bool isCheckedOut() const { return checkedOut; }
    std::pair<int, int> getAvailability() const { return availability; }

    // setters
    void setId(int newId) { id = newId; }
    void setName(const std::string& n) { name = n; }
    void setLocation(const std::string& l) { location = l; }
    void setAvailability(std::pair<int, int> a) { availability = a; }
    void setCheckedOut(bool c) { checkedOut = c; }

    std::string toCSV() const
    {
        // type,id,name,location,start,end,checkedOut,specifics
        std::ostringstream oss;
        oss << getType() << ","
            << id << ","
            << name << ","
            << location << ","
            << availability.first << ","
            << availability.second << ","
            << (checkedOut ? 1 : 0) << ","
            << specificsToCSV();
        return oss.str();
    }

    void printBasic() const
    {
        std::cout << "[" << getType() << "] "
            << "ID: " << id
            << " | Name: " << name
            << " | Location: " << location
            << " | Hours: " << availability.first << "-" << availability.second
            << "\n";
    }
};

#endif
