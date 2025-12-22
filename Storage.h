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
	~Storage();
	void printAll() const;
	Resource* getResource(int id);
	vector<Resource*>& passAll();
};