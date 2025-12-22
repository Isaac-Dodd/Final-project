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

void viewUpcoming(SmartCampusSystem& system, User* user);
void cancelReservationMenu(SmartCampusSystem& system, User* user);
void viewReservationMenu(SmartCampusSystem& system, User* user);
Resource* createResource(SmartCampusSystem& system);
Resource* destroyResource(SmartCampusSystem& system);
void createReservationMenu(SmartCampusSystem& system, User* studentUser);
void studentMenu(SmartCampusSystem& system, User* studentUser);
void adminMenu(SmartCampusSystem& system);

int main()
{
    SmartCampusSystem system;
    //              id      name        location capacity  available hours
    StudyRoom room1(1234, "Eagle Room", "West Wing", 4, { 12, 19 });
    //                   id       name          tutor   location      available hours
    TutoringSession sesh1(1235, "Penguin Room", "North Wing", "Issac", { 8, 17 });

    (system.getStorage())->addResource(&room1);
    (system.getStorage())->addResource(&sesh1);

    /*Student scott("scott");
    Student issac("issac");
    Student james("james");
    Student lawrence("lawrence");
    Admin   homi("homi");*/

    UserList theList;
    /* theList.allUsers.push_back(scott&);
     theList.allUsers.push_back(issac&);
     theList.allUsers.push_back(james&);
     theList.allUsers.push_back(lawrence&);
     theList.allUsers.push_back(homi&);*/

    string  username;
    //    while (option != 0)
    //{
    //    // cout << "-----Smart Campus System-----\n";
    //    // cout << "1. Student\n";
    //    // cout << "2. Admin\n";
    //    // cout << "0. Exit\n";
    //    // cin >> option;
    while (true)
    {
        try
        {
            cout << "Please enter your username: ";
            getline(cin, username);

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
            cerr << "Error: " << string.what() << endl
                << "Press enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    // switch (option){
    //     case 1:
    //         string username;
    //         cout << "Enter username: ";
    //         cin >> username;
    //         studentMenu(system, username);
    //         break;
    //     case 2:
    //         adminMenu(system);
    //     case 0:
    //         break;
    //     default:
    //     // }


}

void viewUpcoming(SmartCampusSystem& system, User* user)
{
    vector<Reservation> userRes = system.getByUser(user);

    if (userRes.empty())
        cout << "\nNothing to display\n";

    else
        for (auto indReservation : userRes)
            cout << indReservation << endl;
}

void cancelReservationMenu(SmartCampusSystem& system, User* user)
{
    // display numbered reservations owned by the user
    // pass back which one to cancel
    vector<Reservation> userReservations = system.getByUser(user);
    int reservationCount = 0;
    int wantedDeleted;

    while (true)
    {
        try
        {
        cout << "Which reservation do you want to cancel (Enter 0 to exit)\n";
        for (auto indReservation : userReservations)
        {
            ++reservationCount;
            cout << "Reservation #" << reservationCount << endl;
            cout << indReservation;
        }
        
            cin >> wantedDeleted;
            if (cin.fail())
            {
                throw runtime_error("Invalid input: Please enter an integer (Press Enter to continue)");
            }
            // error handle values < 0 or > reservationCount
            else if (wantedDeleted < 0 || wantedDeleted > reservationCount)
            {
                throw out_of_range("Out of range. (Press Enter to continue)");
            }
            else if (wantedDeleted == 0)
                return;
            else
                system.removeReservation(userReservations[wantedDeleted - 1]);
        }
        catch (runtime_error& string)
        {
            cin.clear();
            cerr << "Error: " << string.what() << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (out_of_range& string)
        {
            cout << "Error: " << string.what() << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                    }
                }

                catch(runtime_error& string)
                {
                    cout << "Error: " << string.what() << endl
                        << "Press enter to continue...";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
			
            cout << endl << "Enter the name of the resource: ";
            cin >> name;
            switch(option)
            {
                case 1: 
                    cout << endl << "Enter the tutor's name: ";
                    getline(cin, tutorName);
                    cout << endl << "Enter the location of the tutoring session: ";
                    getline(cin, location);
                    cout << endl << "Enter the hour of the day" 
                    "the tutoring session starts (in military time): ";
                    cin >> start;
                    cout << endl << "Enter the hour of the day"
                        "that the tutoring session ends (in military time): ";
                    cin >> end;
                    hours = { start, end };
                    tempResource = new TutoringSession(id, name, location, tutorName, hours);
                    return tempResource;
					break;
                case 2:
                    cout << endl << "Enter the location of the study room: ";
                    cin >> location;
                    cout << endl << "Enter the capacity of the study room: ";
                    cin >> capacity;
                    cout << endl << "Enter the hour that the study room"
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
Resource* destroyResource(SmartCampusSystem& system)
{
    int id;
    system.getStorage()->printAll();
    cout << "Which resource do you want to remove(id): ";
    cin >> id;
    if(!system.availableID(id))
    {
        for(auto& i : system.getStorage()->passAll())
        {
            if(i->getId() == id) return i;
        }
    }
    else
    {
        cout << "id not found.\n";
    }
    return nullptr;
}

void adminMenu(SmartCampusSystem& system){
    int option = -1;
    while (option != 0)
    {
        cout << "-----Admin Menu-----\n"
             << "1. List resources\n"
             << "2. Add a resource\n"
             << "3. Remove a resource\n"
             //<< "4. List reservations\n"
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
                    system.getStorage()->addResource(createResource(system));
                }
                catch(runtime_error& string){
                    cout << "Error: " << string.what() << endl;
                }

                break;
            case 3:
                std::system("cls");
                system.getStorage()->removeResource(destroyResource(system));
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
            << "4. View reservations\n"
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

            cout << "Resource ID: ";
            cin >> resourceID;
            //asks for reservation dates n times
            cout << "START (month day year hour minute): ";
            cin >> dates.startMonth >> dates.startDay >> dates.startYear >> dates.startHour >> dates.startMinute;
            cout << "END (month day year hour minute): ";
            cin >> dates.endMonth >> dates.endDay >> dates.endYear >> dates.endHour >> dates.endMinute;

            if (cin.fail())
            {
                throw runtime_error("Invalid input: Please enter only integers (Press Enter to continue)");
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
            if (system.availableID(resourceID))
            {
                // check if the availability hours match                             
                if (dates.startHour < (system.getStorage())->getResource(resourceID)->getAvailability().first ||
                    dates.endHour   >(system.getStorage())->getResource(resourceID)->getAvailability().second)
                {
                    cout << "Invalid hours/n/n";
                }
                else // hours are within the availability
                {
                    // check if not conflicting with existing reservation
                    if (system.nonConflict(res))
                    {
                        //create reservation object to give to system
                        system.getReservationList()->createReservation(res);

                        cout << "Reservation Successfully added/n/n";
                        valid = true;
                    }
                }
            }
            else // if resource does not exist
            {
                cout << "Resource does not exist/n/n";
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