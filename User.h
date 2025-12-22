#pragma once
#include <string>
#include <iostream>
using namespace std;
class User
{
public:
	User(string username, string t);
	virtual ~User() {};
	virtual string getType() const = 0;
	string getUsername() const;

protected:
	string userName;
	string type;
};

