#include <iostream>
#include "CommandHandler.h"
#include "Expense.h"
#include "Record.h"

/*
Jere Luhtanen 14.1.2020
Metropolia University of Applied Sciences-Smart Systems 
Object Oriented Programming with C++
*/
using namespace std;
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{	
	{
		//Reserve resources 
		FileManager* fileManager = new FileManager;
		Record* record = new Record;

		CommandHandler commandHandler;

		string command;
		cout << "Setup complete. Waiting for inputs."<< endl;;
		//Takes inputs and executes actions based on the command given.
		
		while (!(command.compare("exit") == 0)) {
			cin >> command;

			commandHandler.executeCommand(command, *record, *fileManager);
		}
		
		//Release resources
		delete record;
		delete fileManager;
	}
	_CrtDumpMemoryLeaks();
}

