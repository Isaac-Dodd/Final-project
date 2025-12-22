#include "Resource.h"

Resource::Resource(int setID, string setName, pair<int, int> hours)
{
	id = setID;
	name = setName;
	hours = this->hours;
	//checkedOut = setChecked;
}

//Resource::Resource(const Resource& otherObject)
//{
//	this->id = otherObject.getId();
//	this->name = otherObject.getName();
//	this->resourceType = getResourceType();
//}

void Resource::setId(int setID)
{
	id = setID;
}
void Resource::setName(string setName)
{
	name = setName;
}
void Resource::setAvailability(pair<int, int> hours)
{
	hours = this->hours;
}
//void Resource::setCheckedOut(bool setChecked)
//{
//	checkedOut = setChecked;
//}

// The reservation is tied to the 
// reservations class, not this one
// getReservation() const;

//bool Resource::isCheckedOut() const
//{
//	return(checkedOut);
//}
int Resource::getId() const
{
	return(id);
}
string Resource::getName() const
{
	return(name);
}
pair<int, int> Resource::getAvailability()
{
	return hours;
}

ostream& operator<<(ostream& out, const Resource& resource)
{
	out << "ID: " << resource.id << endl
		<< "Name: " << resource.name << endl;
	resource.getResourceSpecifics();
	return out;
}