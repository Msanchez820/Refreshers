#ifndef User_functions_h_
#define User_functions_h_

#include "LinkedList.h"
#include <iostream>

void toLower(std::string &s);

std::string LowerCopy(std::string s);

void BaseInput(std::string&, std::string&, DueDate&);

bool CheckInput(std::string s, LinkedList *list);

bool IsValidDate(int month,int day,int year);

void Add(LinkedList *list);

void Print(LinkedList *list, bool bDetailed);

void Remove(LinkedList *list);

void Complete(LinkedList *list);

void Completed(LinkedList *list);

void Save(LinkedList *list);

void Load(LinkedList *list);

#endif // !User_functions_h_