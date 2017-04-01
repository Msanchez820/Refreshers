#include "LinkedList.h"
#include <iostream>

LinkedList::~LinkedList()
{
	node *temp = NULL;
	for (unsigned int i = 0; i < this->listLength; i++)
	{
		temp = this->head;
		this->head = this->head->next;
		delete temp->mTask;
		delete temp;
	}
}

void LinkedList::Add(Task * t)
{
	if (this->head == NULL)
	{
		this->head = new node(t);
		this->listLength++;
	}
	else
	{
		node * temp = head, *temp2 = head;
		while (temp)
		{
			if ((*t) < *(temp->mTask))
			{
				temp2 = temp;
				temp = new node(t);
				temp->next = temp2;
				this->listLength++;
				break;
			}
			else if (!temp->next)
			{
				temp->next = new node(t);
				this->listLength++;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}

void LinkedList::Remove(unsigned int n)
{
	if (!this->head)
		return;
	node *temp = this->head, *temp2 = NULL;
	for (unsigned int i = 0; i < (n-1); i++)
	{
		temp2 = temp;
		temp = temp->next;
	}
	if(temp2)
		temp2->next = temp->next;
	delete temp->mTask;
	delete temp;
	temp = NULL;
	if (!temp2)
		head = NULL;
	this->listLength--;
}

Task* LinkedList::operator[](unsigned int n)
{
	if (!this->head)
		return NULL;
	node *temp = this->head;
	for (unsigned int i = 0; i < (n - 1); i++)
	{
		temp = temp->next;
	}
	return temp->mTask;
}