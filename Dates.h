#pragma once
struct Dates
{
	int startDay;
	int startMonth;
	int startYear;

	int dueDay;
	int dueMonth;
	int dueYear;

	bool operator ==(const Dates& rightSide) const
	{
		if (startDay != rightSide.startDay || dueDay != rightSide.dueDay)
			return false;

		else if (startMonth != rightSide.startMonth || dueMonth != rightSide.dueMonth)
			return false;

		else if (startYear != rightSide.startYear || dueYear != rightSide.dueYear)
			return false;

		else
			return true;
	}
};
