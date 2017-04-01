#include "Task.h"
#include <iostream>

Task::~Task()
{

}

bool Task::operator<(Task t)
{
	if (this->mDate < t.mDate)
		return true;
	else if (this->mDate == t.mDate && ( this->mDescription.compare(t.mDescription) < 0))
		return true;
	else
		return false;
}

std::string Task::GetDate(void)
{
	std::string month, day;
	if (this->mDate.mMonth>9)
		month = std::to_string(this->mDate.mMonth);
	else 
		month = "0" + std::to_string(this->mDate.mMonth);
	if (this->mDate.mDay>9)
		day = std::to_string(this->mDate.mDay);
	else
		day = "0" + std::to_string(this->mDate.mDay);
	return month + "/" + day + "/" + std::to_string(this->mDate.mYear);
}

void Task::Print(bool isDetailed)
{
	std::cout << this->GetDate() << " - ";
	switch (this->mType)
	{
	case 'e':
		std::cout << "[Event] ";
		break;
	case 'h':
		std::cout << "[Homework] ";
		break;
	case 's':
		std::cout << "[Shopping] ";
		break;
	default:
		break;
	}
	std::cout << this->mDescription << std::endl;
}