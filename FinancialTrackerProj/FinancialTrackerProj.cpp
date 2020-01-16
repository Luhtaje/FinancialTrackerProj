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

int main()
{	
	//Reserve resources 
	CommandHandler* commandHandler = new CommandHandler;
	FileManager* fileManager= new FileManager;
	Record* record = new Record;
	string command;
	cout << "Setup complete. Waiting for inputs." << endl << endl;;

	//Takes inputs and executes actions based on the command given.
	while (!(command.compare("exit") == 0)) {
		cin >> command;

		commandHandler->executeCommand(command, record, fileManager);
	}
	//Release resources
	delete record;
	delete fileManager;
	delete commandHandler;
}

