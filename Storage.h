#ifndef STORAGE_H_
#define STORAGE_H_
#include "Resource.h"

class Storage {
private:
	vector<Resource*> storage;
	unordered_map<int, bool> checkedOutIds;

public:
	Storage();
	~Storage();
	void listResources()
	{
		for(auto& i : storage)
		{
			i.getResourceSpecifics();
		}
	}

	void addResources(Resource* resource)
	{
		storage.push_back(resource);
	}

	void removeResources(Resource* resource)
	{
		auto it = find(storage.begin(), storage.end(), resource);
		storage.erase(it);
	}

	void listReservations();
	bool uniqueId(int id)
	{
		// if id exists return false
		if(checkedOutIds.count(id)) return false;
		return true;
	}
};

#endif

