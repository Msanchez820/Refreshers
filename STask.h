#ifndef STask_h_
#define STask_h_

#include "Task.h"
#include <vector>

class STask : public Task
{
public:
	std::vector<std::string> mItems;

	STask();
	STask(std::string s, DueDate d);
	~STask();
	
	void AddItems(std::string);

	void Print(bool);
};

#endif // !STask_h_