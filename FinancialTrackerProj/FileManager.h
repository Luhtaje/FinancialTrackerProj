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
	friend ostream& operator<<(ofstream& datafile, unique_ptr<Transaction>);
	//friend istream& operator>>(ifstream& datafile, Record* record);

public:
	void saveToDisk(Record* recordobj);
	void readFromDisk(Record* recordobj);
	void clearDisk(Record* recordobj);
	FileManager();
	~FileManager()=default;
private: 
	void saveTransaction(string)const;
};

