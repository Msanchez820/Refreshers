#ifndef Task_h_
#define Task_h_

#include <string>
#include "Due Date.h"

class Task
{
public:
	std::string mDescription;
	DueDate mDate;
	char mType;
	bool mIsCompleted;

	Task() : mType('g'), mIsCompleted(false) {}
	Task(std::string s, DueDate d) : mDescription(s), mDate(d), mType('g'), mIsCompleted(false){}
	~Task();

	bool operator<(Task t);

	void AddInfo(std::string s, DueDate d) { mDescription = s; mDate = d;}

	std::string GetDate(void);

	virtual void Print(bool);

private:
};
#endif // !Task