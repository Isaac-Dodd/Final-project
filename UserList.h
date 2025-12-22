#pragma once
#include "User.h"
#include "Admin.h"
#include "Student.h"
#include <vector>
#include <algorithm>
#include <fstream>
class UserList
{
public:
    UserList();
    ~UserList();
    string typeMatchingName(string username);
    User* pointerFromName(string username);
    bool isInList(string name); 
    
private:
    vector<User*> allUsers;
};

