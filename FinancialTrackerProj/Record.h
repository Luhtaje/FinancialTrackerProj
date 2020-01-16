#pragma once
#include "Transaction.h"
#include "Expense.h"
#include "Income.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
using namespace std;

/*
Record holds transaction in a vector. Uses FileHandler to save and read, and transactions to hold data.
*/
class Record
{
	friend ostream& operator<<(ofstream& , Record&);
	friend ostream& operator>>(ifstream& , Record& );
private:

public:
	Record();
	~Record();
	vector<shared_ptr<Transaction >> sharedPtrVector;
	void print()const;
	void add(shared_ptr<Transaction>);
	void flushRecord();
};
