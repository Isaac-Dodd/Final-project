#pragma once
#include "User.h"
class Student : public User
{
	public:
	Student(string name);
	string getType() const;
};

