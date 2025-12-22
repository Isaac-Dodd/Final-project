#include "TutoringSession.h"


TutoringSession::TutoringSession(int setId, string setName, string location, 
	string name, pair<int, int> hours) : Resource(setId, setName, hours)
{
	tutorName = name;
	this->location = location;
}

string TutoringSession::getTutorName()
{
	return tutorName;
}

string TutoringSession::getLocation()
{
	return location;
}


void TutoringSession::setTutorName(string name)
{
	tutorName = name;
}

void TutoringSession::setLocation(string locale)
{
	location = locale;
}


void TutoringSession::getResourceSpecifics() const
{
	cout << "Location: " << location << endl
		 << "Tutor's name: " << tutorName << endl
		 << "Available Hours: " << hours.first << " to " << hours.second << endl;
}

string TutoringSession::getSaveSpecifics()
{
	string temp = location + "|" + tutorName + "|";
	return temp;
}
string TutoringSession::getResourceType()
{
	return "TutoringSession";
}
// today at 3:00 pm is 20252120.0300