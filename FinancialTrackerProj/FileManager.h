#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <algorithm>
#include "Expense.h"
#include "Income.h"
#include "Record.h"

using namespace std;
class FileManager
{
	//friend ostream& operator<<(ofstream& datafile, Transaction transaction);
	//friend istream& operator>>(ifstream& datafile, Record* record);

public:
	void saveToDisk(Record* recordobj);
	void readFromDisk(Record* recordobj);
	void clearDisk(Record* recordobj);
	FileManager();
	~FileManager();
private: 
	void saveTransaction(string)const;
};

