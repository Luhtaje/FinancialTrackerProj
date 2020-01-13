#include <iostream>
#include "CommandHandler.h"
#include "Expense.h"
#include "Record.h"

using namespace std;

int main()
{
	CommandHandler* commandHandler = new CommandHandler;
	FileManager* fileManager= new FileManager;
	Record* record = new Record;
	string command;


	while (!(command.compare("exit")==0)) {
		cin >> command;

		//Had to pass managers in order to be able to use them. 
		commandHandler->executeCommand(command,record,fileManager);
	}

	delete record;
	delete fileManager;
	delete commandHandler;
}

