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
    ~UserList(); //not sure if this needs to be virutal, check from Addressbook
    string typeMatchingName(string username);
    User* pointerFromName(string username);
    bool isInList(string name); 
    private:
    vector<User*> allUsers;
};

