#pragma once
#include "Expense.h"
#include "Income.h"
#include "Record.h"

using namespace std;
class FileManager
{
public:
	void saveToDisk(Record* recordobj)const;
	void readFromDisk(Record* recordobj)const;
	void clearDisk()const;
	
	FileManager();
	~FileManager()=default;
};

