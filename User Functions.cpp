#include "User Functions.h"
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "STask.h"

using namespace std;

void toLower(string &s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
}

string LowerCopy(std::string s)
{
	string copy = s;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		copy[i] = tolower(s[i]);
	}
	return copy;
}

void BaseInput(string &DateInput, string &Description, DueDate &date)
{
	string month = "00", day = "00", year = "0000";
	cout << "When is this task due?\n";
	while (true)
	{
		getline(cin, DateInput);
		if (DateInput.length() != 10 || DateInput[2] != '/' || DateInput[5] != '/')
			cout << "Please enter a valid date\n";
		else
		{
			for (int i = 0; i < 2; i++)
				month[i] = DateInput[i];
			for (int i = 0; i < 2; i++)
				day[i] = DateInput[i + 3];
			for (int i = 0; i < 4; i++)
				year[i] = DateInput[i + 6];
			date.mMonth = stoi(month);
			date.mDay = stoi(day);
			date.mYear = stoi(year);
			if (IsValidDate(date.mMonth, date.mDay, date.mYear))
				break;
			else
				cout << "Please enter a valid date\n";
		}
	}
	cout << "How would you describe this task?\n";
	getline(cin, Description);
}

bool CheckInput(std::string s, LinkedList *list)
{
	bool keepGoing = true;
	if (s.compare("add") == 0)
	{
		Add(list);
	}
	else if (s.compare("print") == 0)
	{
		Print(list, false);
	}
	else if (s.compare("detailed") == 0)
	{
		Print(list, true);
	}
	else if (s.compare("remove") == 0)
	{
		Remove(list);
	}
	else if (s.compare("complete") == 0)
	{
		Complete(list);
	}
	else if (s.compare("completed") == 0)
	{
		Completed(list);
	}
	else if (s.compare("save") == 0)
	{

	}
	else if (s.compare("load") == 0)
	{

	}
	else if (s.compare("exit") == 0)
		keepGoing = false;
	return keepGoing;
}

bool IsValidDate(int month, int day, int year)
{
	if (month < 1 || month > 12 || year < 2017 || day > 31 || day < 1)
		return false;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	else if (month == 2 && (year % 4) == 0 && day > 29)
		return false;
	else if (month == 2 && (year%4) != 0 && day > 28)
		return false;
	else
		return true;
}

void Add(LinkedList *list)
{
	string input, DateInput, Description;
	DueDate date;
	STask *shopping = NULL;

	while (true)
	{
		cout << "What type of task is this? [G:Generic, S : Shopping, E : Event, H : Homework]" << endl;
		getline(cin,input);
		if (input.length() != 1)
		{
			cout << "I'm sorry, that command was invalid. Please try again.\n";
			continue;
		}
		input[0] = tolower(input[0]);
		switch (input[0])
		{
		case 'g':
			BaseInput(DateInput, Description, date);
			list->Add(new Task(Description, date));
			cout << "Task added successfully.\n";
			return;
		case 's':
			BaseInput(DateInput, Description, date);
			shopping = new STask(Description, date);
			cout << "What items do you need to buy? [Type your item and press ENTER to add another item.Type DONE to complete the list.]\n";
			while (true)
			{
				getline(cin, input);
				if (LowerCopy(input).compare("done") == 0)
					break;
				shopping->AddItems(input);
			}
			list->Add(shopping);
			cout << "Task added successfully.\n";
			return;
		case 'e':
			return;
		case 'h':
			return;
		default:
			cout << "I'm sorry, that command was invalid. Please try again.\n";
			input[0] = 0;
			break;
		}
	}
}

void Print(LinkedList *list, bool bDetailed)
{
	unsigned int length= list->GetLength();
	if (length == 0 )
	{
		std::cout << "You have no outstanding tasks!\n";
		return;
	}
	for (unsigned int i = 1; i <= length; i++)
	{
		if (!(*list)[i]->mIsCompleted)
		{
			cout << i << ". ";
			(*list)[i]->Print(bDetailed);
		}
	}
}

void Remove(LinkedList *list)
{
	string input;
	unsigned int Uinput;
	if (!list->GetLength())
	{
		cout << "You have no outstanding tasks!\n";
		return;
	}
	cout << "Which task would you like to remove?\n";
	getline(cin, input);
	Uinput = stoi(input);
	if (Uinput > list->GetLength())
	{
		cout << "Invalid selection.\n";
		return;
	}
	list->Remove(Uinput);
	cout << "Task removed successfully.\n";
}

void Complete(LinkedList *list)
{
	string input;
	unsigned int Uinput;
	if (!list->GetLength())
	{
		cout << "You have no outstanding tasks!\n";
		return;
	}
	cout << "Which task would you like to complete?\n";
	getline(cin, input);
	Uinput = stoi(input);
	if (Uinput > list->GetLength())
	{
		cout << "Invalid selection.\n";
		return;
	}
	(*list)[Uinput]->mIsCompleted = true;
	cout << "Task marked complete successfully.\n";
}

void Completed(LinkedList *list)
{
	unsigned int length = list->GetLength();
	if (length == 0)
	{
		std::cout << "You have no outstanding tasks!\n";
		return;
	}
	for (unsigned int i = 1; i <= length; i++)
	{
		if ((*list)[i]->mIsCompleted)
		{
			cout << i << ". ";
			(*list)[i]->Print(false);
		}
	}
}

void Save(LinkedList *list)
{

}

void Load(LinkedList *list)
{

}