
#include "MainFunctions.h"

using namespace std;

/*
* Add exception handling with try catch
*/
/*
X List all available resources
X Search by name or ID
- Filter by resource type or attribute
X View their upcoming reservations
- Invalid input
X Duplicate IDs
X Failed file reads/writes
X Conflicting reservation attempts
X Adding resources
X Removing resources
X Creating reservations
X Canceling or modifying reservations
X Detecting collisions
X Saving and loading data
*/

/* ============ ERRORS ================
* Exception handle the chars in the options
*/

int main()
{
    SmartCampusSystem system;
    UserList theList;
    string  username;

    while (true)
    {
        try
        {
            cout << "Please enter your username(enter \"0\" to save and end the program): ";
            getline(cin, username);

            if (username == "0")
                return 0;

            if (!theList.isInList(username))
            {
                throw runtime_error("Invalid username, please try again.");
            }

            string type = theList.typeMatchingName(username);
            if (type == "Student")
            {
                User* studentUser = theList.pointerFromName(username);
                studentMenu(system, studentUser);
            }
            else if (type == "Admin")
            {
                adminMenu(system);
            }

        }

        catch (runtime_error& string)
        {
            cin.clear();
            std::system("cls");
            cerr << "Error: " << string.what() << endl
                << "Press enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
