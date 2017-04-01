#include "Due Date.h"

bool DueDate::operator<(DueDate n)
{
	if (this->mYear < n.mYear)
		return true;
	else if (this->mYear > n.mYear)
		return false;
	else if (this->mMonth < n.mMonth)
		return true;
	else if (this->mMonth > n.mMonth)
		return false;
	else if (this->mDay < n.mDay)
		return true;
	else
		return false;
}

bool DueDate::operator==(DueDate n)
{
	if (this->mYear == n.mYear && this->mMonth == n.mMonth && this->mDay == n.mDay)
		return true;
	else
		return false;
}

DueDate::DueDate()
{
}

DueDate::DueDate(int m, int d, int y)
{
	this->mMonth = m;
	this->mDay = d;
	this->mYear = y;
}

DueDate::~DueDate()
{
}