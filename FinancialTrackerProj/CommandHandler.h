#pragma once
#include <string>
#include <iostream>
#include <map>
#include "Transaction.h"
#include "FileManager.h"
#include "Record.h"

using namespace std;
class CommandHandler
{
	public:
		CommandHandler();
		~CommandHandler();
		void executeCommand(string command,Record* record ,FileManager* fileManager) const;
	private:
		string command;
		void printCommands()const;
};

