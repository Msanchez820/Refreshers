#include "STask.h"
#include <iostream>

STask::STask(): Task()
{
	mType = 's';
}

STask::STask(std::string s, DueDate d) : Task(s,d)
{
	mType = 's';
}

STask::~STask()
{

}

void STask::AddItems(std::string s)
{
	this->mItems.push_back(s);
}

void STask::Print(bool detailed)
{
	this->Task::Print(detailed);
	if (detailed)
	{
		for (unsigned int i = 0; i < this->mItems.size(); i++)
		{
			std::cout << this->mItems[i] << std::endl;
		}
	}
}