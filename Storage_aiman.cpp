#include "Storage.h"
#include <sstream>
using namespace std;

static bool safeStoi(const std::string& s, int& out)
{
    try { out = std::stoi(s); return true; }
    catch (...) { return false; }
}

Storage::Storage()
{
    // Load resources on startup (as your ops/UML notes say)
    // :contentReference[oaicite:4]{index=4}
    loadResources("Resources.txt");
}

Storage::~Storage()
{
    for (auto* r : storage) delete r;
    storage.clear();
}

bool Storage::loadResources(const std::string& filename)
{
    std::fstream in(filename, std::ios::in);
    if (!in.is_open()) return false;

    // clear current
    for (auto* r : storage) delete r;
    storage.clear();
    idMap.clear();

    std::string line;
    while (std::getline(in, line))
    {
        if (line.empty()) continue;

        // type,id,name,location,start,end,checkedOut,specifics
        std::stringstream ss(line);
        std::string type, idS, name, loc, startS, endS, checkedS, specifics;

        if (!std::getline(ss, type, ',')) continue;
        if (!std::getline(ss, idS, ',')) continue;
        if (!std::getline(ss, name, ',')) continue;
        if (!std::getline(ss, loc, ',')) continue;
        if (!std::getline(ss, startS, ',')) continue;
        if (!std::getline(ss, endS, ',')) continue;
        if (!std::getline(ss, checkedS, ',')) continue;
        std::getline(ss, specifics); // rest

        int id, start, end, checked;
        if (!safeStoi(idS, id)) continue;
        if (!safeStoi(startS, start)) continue;
        if (!safeStoi(endS, end)) continue;
        if (!safeStoi(checkedS, checked)) continue;

        Resource* r = nullptr;

        if (type == "StudyRoom")
        {
            r = new StudyRoom(id, name, loc, { start, end }, checked == 1, 0, false);
            r->specificsFromCSV(specifics);
        }
        else if (type == "TutoringSession")
        {
            r = new TutoringSession(id, name, loc, { start, end }, checked == 1, "", "");
            r->specificsFromCSV(specifics);
        }
        else
        {
            continue;
        }

        storage.push_back(r);
        idMap[id] = true;
    }

    return true;
}

bool Storage::saveResources(const std::string& filename) const
{
    std::fstream out(filename, std::ios::out | std::ios::trunc);
    if (!out.is_open()) return false;

    for (auto* r : storage)
        out << r->toCSV() << "\n";

    return true;
}

void Storage::listResources() const
{
    for (auto* r : storage)
    {
        r->printBasic();

        // Display availability in AM/PM format
        cout << "Availability: "
            << formatTimeAMPM(r->getAvailability().first)
            << " - "
            << formatTimeAMPM(r->getAvailability().second)
            << endl;

        r->getResourceSpecifics();
        cout << endl;
    }
}

Resource* Storage::findById(int id) const
{
    for (auto* r : storage)
        if (r->getId() == id) return r;
    return nullptr;
}

std::vector<Resource*> Storage::searchByName(const std::string& key) const
{
    std::vector<Resource*> out;
    for (auto* r : storage)
    {
        if (r->getName().find(key) != std::string::npos)
            out.push_back(r);
    }
    return out;
}

bool Storage::addResource(Resource* resource)
{
    if (!resource) return false;
    int id = resource->getId();
    if (idMap.count(id)) return false; // duplicate ID handling
    storage.push_back(resource);
    idMap[id] = true;
    return true;
}

bool Storage::removeResourceById(int id)
{
    for (auto it = storage.begin(); it != storage.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            delete* it;
            storage.erase(it);
            idMap.erase(id);
            return true;
        }
    }
    return false;
}

bool Storage::editResourceName(int id, const std::string& newName)
{
    Resource* r = findById(id);
    if (!r) return false;
    r->setName(newName);
    return true;
}
