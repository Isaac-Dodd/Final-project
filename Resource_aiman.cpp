#include <string>
using namespace std;

/*
 * Converts a 24-hour integer time into AM/PM format.
 * Example:
 *  9  -> 9:00 AM
 *  12 -> 12:00 PM
 *  15 -> 3:00 PM
 */
string formatTimeAMPM(int hour)
{
    if (hour == 0)  return "12:00 AM";
    if (hour == 12) return "12:00 PM";
    if (hour > 12)  return to_string(hour - 12) + ":00 PM";
    return to_string(hour) + ":00 AM";
}
