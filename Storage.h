#pragma once
#include "Resource.h"
#include "StudyRoom.h"
#include "TutoringSession.h"
#include <vector>
class Storage
{
private:
	vector<Resource*> allResources;
	
public:
	Storage();
	void printAll() const;
	Resource* getResource(int id);
	
	//Admin Commands
	void addResource(Resource* newResource);
	void removeResource(Resource* removeResource);
	vector<Resource*> passAll();
};