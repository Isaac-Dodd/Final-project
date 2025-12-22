#include <iostream>
#include <string>
#include "SmartCampusSystem.h"
#include "UserList.h"

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


void cancelReservationMenu(SmartCampusSystem& system, User* user);
void viewReservationMenu(SmartCampusSystem& system, User* user);
Resource* createResource(SmartCampusSystem& system);
void destroyResource(SmartCampusSystem& system);
void createReservationMenu(SmartCampusSystem& system, User* studentUser);
void studentMenu(SmartCampusSystem& system, User* studentUser);
void adminMenu(SmartCampusSystem& system);

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

void cancelReservationMenu(SmartCampusSystem& system, User* user)
{
    // display numbered reservations owned by the user
    // pass back which one to cancel
    //vector<Reservation> userReservations = system.getByUser(user);
    //int reservationCount = 0;
    int wantedDeleted;

    while (true)
    {
        try
        {
            auto userReservations = system.getByUser(user);

            if (userReservations.empty()) {
                cout << "No reservations to cancel.\n";
                return;
            }

            int reservationCount = 0;
            cout << "Which reservation do you want to cancel (Enter 0 to exit)\n";

            for (const auto& res : userReservations)
            {
                cout << "Reservation #" << ++reservationCount << '\n';
                cout << res;
            }

            cin >> wantedDeleted;

            if (cin.fail())
                throw runtime_error("Invalid input: enter a number.");

            if (wantedDeleted < 0 || wantedDeleted > reservationCount)
                throw out_of_range("Selection out of range.");

            if (wantedDeleted == 0)
                return;

            system.removeReservation(userReservations[wantedDeleted - 1]);
            cout << "Reservation canceled successfully.\n";
        }
        catch (const runtime_error& e)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Error: " << e.what() << endl;
        }
        catch (const out_of_range& e)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void viewReservationMenu(SmartCampusSystem& system, User* user)
{
    vector<Reservation> userReservations = system.getByUser(user);
    
    if (userReservations.empty())
    {
        cout << "Error: No reservation found.\n";
        return;
    }
    
    cout << "--Reservations--\n";
    for (int i = 0; i < userReservations.size(); ++i)
    {
        cout << userReservations[i];
    }
}

Resource* createResource(SmartCampusSystem& system)
{
    int option;
    int id;
    string name;
    string tutorName;
    string location;
    int capacity;
    int start, end;
    pair <int, int> hours;
    Resource* tempResource;
    ////if this is true the id is available, if it's false it's taken
    //system.availableID(id);
    while (true)
    {
        try
        {
            cout << "Please select the type of resource you want to add:" << endl
                << "1. Tutoring Session" << endl
                << "2. Study Room" << endl
                << "Choice: ";
            cin >> option;
            if (option != 1 && option != 2)
            {
                throw runtime_error("Invalid input, please enter 1 or 2");
            }
            
            while(true)
            {
                try
                {
					cout << "Enter a unique ID: ";
					cin >> id;
					if(!system.availableID(id))
                    {
                        throw runtime_error("This ID is already in use, please enter a different one");
                        continue;
                    }
                }

                catch(runtime_error& string)
                {
                    cout << "Error: " << string.what() << endl
                        << "Press enter to continue...";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                break;
            }
			
            cout << endl << "Enter the name of the resource: ";
            cin >> name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch(option)
            {
                case 1: 
                    cout << endl << "Enter the location of the tutoring session: ";
                    getline(cin, location);
                    cout << endl << "Enter the tutor's name: ";
                    getline(cin, tutorName);
                    
                    cout << endl << "Enter the hour " 
                    "the tutoring session starts (in military time): ";
                    cin >> start;
                    cout << endl << "Enter the hour "
                        "that the tutoring session ends (in military time): ";
                    cin >> end;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
			        hours = {start, end};
                    tempResource = new TutoringSession(id, name, location, tutorName, hours);
                    return tempResource;
					break;
                case 2:
                    cout << endl << "Enter the location of the study room: ";
                    getline(cin, location);
                    cout << endl << "Enter the capacity of the study room: ";
                    cin >> capacity;
                    cout << endl << "Enter the hour that the study room "
                                    "opens (in military time): ";
                    cin >> start;
                    cout << endl << "Enter the hour that the study room "
                        "closes (in military time): ";
                    cin >> end;
                    hours = { start, end };
                    tempResource = new StudyRoom(id, name, location, capacity, hours);
                    return tempResource;
                    break;
                default:
                    cout << option << " is not a valid option. Please input 1 or 2" << endl
                         << "Press enter to continue...";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
            }
        }

		catch (runtime_error& string)
		{
			cin.clear();
			cerr << "Error: " << string.what() << endl
				 << "Press enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
    }
}

void destroyResource(SmartCampusSystem& system)
{
    int id;
    system.getStorage()->printAll();
    cout << "Which resource do you want to remove(id): ";
    cin >> id;
    if(!system.availableID(id))
    {
        for(int i = 0; i < system.getStorage()->passAll().size(); ++i)
        {
            if(system.getStorage()->passAll()[i]->getId() == id) system.removeResources(system.getStorage()->passAll()[i]);
        }
    }
    else
    {
        cout << "id not found.\n\n";
    }
    return;
}

void adminMenu(SmartCampusSystem& system){
    int option = -1;
    while (option != 0)
    {
        cout << "-----Admin Menu-----\n"
             << "1. List resources\n"
             << "2. Add a resource\n"
             << "3. Remove a resource\n"
             << "4. List all reservations\n"
             << "0. Exit\n"
             << "Your choice: ";
        cin >> option;

        switch(option){
            case 1:
                std::system("cls");
                system.getStorage()->printAll();
                cout << endl << endl;
                break;
            case 2:
                try
                {
                    system.addResource(createResource(system));
                }
                catch(runtime_error& string){
                    cout << "Error: " << string.what() << endl;
                }
                break;
            case 3:
                std::system("cls");
                destroyResource(system);
                break;
            case 4:
                std::system("cls");
                system.getReservationList()->printAll();
                break;
            case 0:
                cin.ignore();
                break;
            default:
                std::system("cls");

                cout << "Invalid option.\n";
        }
    }
}

void studentMenu(SmartCampusSystem& system, User* studentUser)
{
    while (true)
    {
        int option = -1;
        cout << "-----Student Menu-----\n"
            << "1. List resources\n"
            << "2. Create reservation\n"
            << "3. Cancel reservation\n"
            << "4. View upcoming reservations\n"
            << "5. View all reservations\n"
            << "0. Exit\n"
            << "Choice: ";
        cin >> option;

        switch (option) {
        case 1:
            system.getStorage()->printAll();
            break;
        case 2:
            createReservationMenu(system, studentUser);
            break;
        case 3:
            cancelReservationMenu(system, studentUser);
            break;
        case 4:
            viewReservationMenu(system, studentUser);
            break;
        case 5:
            system.getReservationList()->printAll();
            break;
        case 0:
            return;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}

void createReservationMenu(SmartCampusSystem& system, User* studentUser)
{
    Dates dates;
    int resourceID;
    bool valid = false;
    bool invalidID = true;

    time_t t = time(nullptr);
    tm now{};
    localtime_s(&now, &t);

    int year = now.tm_year + 1900;
    int month = now.tm_mon + 1;
    int day = now.tm_mday;
    double hr = now.tm_hour;
    double min = now.tm_min;

    double today = min / 10000 + hr / 100 + day + month * 100 + year * 10000;
    double wantedTime;

    do
    {
        try
        {
            while (invalidID)
            {
            cout << "Resource ID: ";
            cin >> resourceID;
            if (system.availableID(resourceID))
                cout << "Unavailable\n\n\n";
            else
                invalidID = false;
            }

            // ERROR HANDLE THIS

            //asks for reservation dates n times
            cout << "START (month day year hour minute): ";
            cin >> dates.startMonth >> dates.startDay >> dates.startYear >> dates.startHour >> dates.startMinute;
            cout << "END (month day year hour minute): ";
            cin >> dates.endMonth >> dates.endDay >> dates.endYear >> dates.endHour >> dates.endMinute;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input: Please enter only integers");
            }

            wantedTime = dates.endMinute / 10000 + dates.endHour / 100 + dates.endDay
                + dates.endMonth * 100 + dates.endYear * 10000;

            //checking if the time is in the future
            if (wantedTime < today)
            {
                throw(range_error("Invalid input: Please enter a time in the future (Press Enter to continue)"));
            }
            // create reservation variable
            Reservation res(resourceID, studentUser->getUsername(), dates);

            // check if the Resource exists
            if (!system.availableID(resourceID))
            {
                // check if the availability hours match                             
                if (dates.startHour < (system.getStorage())->getResource(resourceID)->getAvailability().first ||
                    dates.endHour   > (system.getStorage())->getResource(resourceID)->getAvailability().second)
                {
                    cout << "Invalid hours\n\n";
                }
                else // hours are within the availability
                {
                    // check if not conflicting with existing reservation
                    if (system.nonConflict(res))
                    {
                        //create reservation object to give to system
                        system.getReservationList()->createReservation(res);

                        cout << "Reservation Successfully added\n\n";
                        valid = true;
                    }
                }
            }
            else // if resource does not exist
            {
                cout << "Resource does not exist\n\n";
            }
        }

        catch (range_error& string)
        {
            cout << "Error: " << string.what() << endl
                << "Press enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
		catch (runtime_error& string)
		{
			cout << "Error: " << string.what() << endl
				<< "Press enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
        
    } while(!valid);
}