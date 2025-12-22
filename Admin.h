#pragma once
#include "User.h"
class Admin : public User
{
	public:
	Admin(string username);
	string getType() const;
};