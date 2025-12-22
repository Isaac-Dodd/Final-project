#include "UserList.h"


UserList::UserList()
{
    fstream myStream("User.txt", ios::in);

    string username;
    string userType;

    if(!myStream.is_open())
    {
        return;
    }

    if(myStream.peek() == EOF)
    {
        return;
    }
    User* temp;
    while(!myStream.eof())
    {
        getline(myStream, username, '|');
        getline(myStream, userType, '\n');
        if (userType == "Admin")
        {
            allUsers.push_back(new Admin(username));
        }
        else if(userType == "Student")
        {
            allUsers.push_back(new Student(username));
        }
    }

    myStream.close();
}

string UserList::typeMatchingName(string name)
{
    for(int i = 0; i < allUsers.size(); ++i)
    {
        if (allUsers[i]->getUsername() == name)
        {
            return allUsers[i]->getType();
        }
    }
	return NULL;
}

User* UserList::pointerFromName(string name)
{
    for(int i = 0; i < allUsers.size(); ++i)
    {
        if(allUsers[i]->getUsername()== name)
        {
            return allUsers[i];
        }
    }
    return NULL;
}

bool UserList::isInList(string name)
{
    for(auto& item : allUsers)
    {
        if (name == item->getUsername())
        {
            return true;
        }
    }
    return false;
}

UserList::~UserList()
{
    fstream myStream("User.txt", std::ios::out);
    if(!myStream.is_open())
        cout << "Could not open file for saving";
    else
    {
        for(auto item : allUsers)
        {
            myStream << item->getUsername() << '|';
            myStream << item->getType() << '\n';
        }
        cout << "Data has been successfully saved to User.txt";
    }
}