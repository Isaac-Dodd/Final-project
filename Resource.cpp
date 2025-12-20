#include "Resource.h"

Resource::Resource(int setID, string setName, bool setChecked)
{
	id = setID;
	name = setName;
	checkedOut = setChecked;
}
void Resource::setId(int setID)
{
	id = setID;
}
void Resource::setName(string setName)
{
	name = setName;
}
void Resource::setCheckedOut(bool setChecked)
{
	checkedOut = setChecked;
}

// The reservation is tied to the 
// reservations class, not this one
// getReservation() const;

bool Resource::isCheckedOut() const
{
	return(checkedOut);
}
int Resource::getId() const
{
	return(id);
}
string Resource::getName() const
{
	return(name);
}
