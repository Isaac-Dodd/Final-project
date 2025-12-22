#include "Student.h"

Student::Student(string username): User(username, "Student"){}

string Student::getType() const
{
    return type;
}