#pragma once
#include "CommandHandler.h"
#include <sstream>
#include "Expense.h"
#include "Income.h"
#include "Transaction.h"
#include "Record.h"
using namespace std;
/*
Command handler executes commands given in the main program.
 */

CommandHandler::CommandHandler() {
	command = "";
	printCommands();
}


CommandHandler::~CommandHandler(){

}

//Decides to correct command and executes it. 
void CommandHandler::executeCommand(string command,Record* record,FileManager* fileManager) const {
	int x = 0;
	if (command.compare("clear") == 0) {
		fileManager->clearDisk(record);
		cout << "Datafile cleared." << endl;
	}
	else if (command.compare("save") == 0) {
		fileManager->saveToDisk(record);

		record->flushRecord();
		cout << "Temporary memory saved to disk. Temporary memory cleared." << endl;
	}
	else if (command.compare("read") == 0) {
		fileManager->readFromDisk(record);
		cout << "Data read from disk." << endl;
	}
	else if (command.compare("add") == 0) {
		unique_ptr<Income> income = make_unique<Income>();
		record->add(move(income));
	}
	else if (command.compare("spend") == 0) {

		unique_ptr<Expense> expense = make_unique<Expense>();
		record->add(move(expense));
	}
	else if(command.compare("print")==0) {
		record->print();
	}
	else if (command.compare("commands") == 0) {
		printCommands();
	}
	else if (command.compare("exit") == 0) {
		cout << "Exiting program...";
	}
	else if (command.compare("flush")==0) {
		cout << "Temporary data deleted" << endl;
	}
	else if (command.compare("help") == 0) {
		cout << endl;
		cout << "Financial Tracker works by saving transactions into temporary memory \nthat need to be saved to disk with the \"save\"command" << endl;
		cout << "Data saved to disk need to be read into temporary memory for viewing, through the \"read\" command." << endl;
		cout << "Saving data to disk clears the temporary memory, but reading does not clear disk." << endl;
		cout << "To avoid multiplication of entries, after reading from disk and before entering new transactions \nuse \"flush\" to clear temporary memory." ;
	}
	else {
		cout << "Invalid input. Type help to view available commands." << endl;
	}
}

void CommandHandler::printCommands()const {
	cout << "Launching FinanceTracker\n";
	cout << "Commands:\n" << endl;
	cout << left << setw(15) << "clear"<< "-Clear the disk completely, all previously saved data is deleted." << endl;
	cout << left << setw(15) << "save"<< "-Saves current session into disk. Enables data to be accessable in different sessions" << endl;
	cout << left << setw(15) << "read"<< "-Reads saved data from disk." << endl;
	cout << left << setw(15) << "add"<< "-Creates an income transaction." << endl;
	cout << left << setw(15) << "spend"<<"-Creates an expense transaction. " << endl;
	cout << left << setw(15) << "print"<< "-Prints the record of transactions." << endl;
	cout << left << setw(15) << "flush" << "-Clears temporary memory." << endl;
	cout << left << setw(15) << "commands" << "-Prints all commands" << endl;
	cout << left << setw(15) << "help" << "-Prints information about the programs alghoritm" << endl;
	cout << left << setw(15) << "exit"	<< "-Closes the program." << endl;
	
}