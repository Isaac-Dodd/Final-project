#pragma once
struct Dates
{
	int startMinute;
	int startHour;
	int startDay;
	int startMonth;
	int startYear;

	int endMinute;
	int endHour;
	int endDay;
	int endMonth;
	int endYear;

	bool operator ==(const Dates& rightSide) const
	{
		if (startMinute != rightSide.startMinute || endMinute != rightSide.endMinute)
			return false;
		else if (startHour != rightSide.startHour || endHour != rightSide.endHour)
			return false;
		else if (startDay != rightSide.startDay || endDay != rightSide.endDay)
			return false;
		else if (startMonth != rightSide.startMonth || endMonth != rightSide.endMonth)
			return false;
		else if (startYear != rightSide.startYear || endYear != rightSide.endYear)
			return false;
		else
			return true;
	}
};