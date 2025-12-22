#pragma once
#include "Resource.h"
class TutoringSession :public Resource
{
	public: 
		TutoringSession(int setID, string setName, string location, string tutorName, pair<int, int> hours);
		string getTutorName();
		string getLocation();
		
		void setTutorName(string name);
		void setLocation(string locale);
		
		
		string getResourceType();
		void getResourceSpecifics() const;
		string getSaveSpecifics();
		//void setResourceSpecifics(string tutorName, );

	private:
		string tutorName;
		string location;
		string resourceType = "TutoringSession";
};

