#ifndef LinkedList_h
#define LinkedList_h

#include "Task.h"

struct node
{
	Task *mTask;
	node *next;

	node(Task* t) : mTask(t), next(NULL) {}
};

class LinkedList
{
private:
	node *head;
	unsigned int listLength;

public:
	LinkedList() : head(0), listLength(0) {}
	~LinkedList();

	void Add(Task * t);

	void Remove(unsigned int n);

	Task* operator[](unsigned int);

	unsigned int GetLength() { return listLength; }
};

#endif