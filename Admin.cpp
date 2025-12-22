#include "Admin.h"

Admin::Admin(string username) : User(username, "Admin"){}


string Admin::getType() const
{
    return type;
}
