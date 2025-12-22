#include "User.h"

User::User(string username, string t): userName(username), type(t){}

string User::getUsername() const
{
	return(userName);
}