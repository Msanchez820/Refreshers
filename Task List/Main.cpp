#include <iostream>
#include "LinkedList.h"
#include "User Functions.h"
using namespace std;

int main()
{
	string userInput;
	LinkedList Tasks;

	while (true)
	{
		cout << "What would you like to do? ";
		getline(cin, userInput);

		toLower(userInput);
	
		if (!CheckInput(userInput,&Tasks))
			break;
		
	}
	cout << "Thank you for using To-Do List!\n";
	return 0;
}