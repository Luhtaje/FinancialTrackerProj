#pragma once
#include <string>
#include <iostream>
#include "Transaction.h"
#include "FileManager.h"
#include "Record.h"

using namespace std;
class CommandHandler
{
	public:
		CommandHandler();
		~CommandHandler()=default;
		void executeCommand(string command,Record* record ,FileManager* fileManager) const;
	private:
		void printCommands()const;
};

