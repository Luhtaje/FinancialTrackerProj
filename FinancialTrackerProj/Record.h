#pragma once
#include "Transaction.h"
#include <algorithm>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

/*
Record holds transaction in a vector. Uses FileHandler to save and read, and transactions to hold data.
*/
class Record
{

private:

public:
	Record();
	~Record()=default;

	vector<unique_ptr<Transaction>> record;
	void print()const;
	void add(unique_ptr<Transaction>);
	void flushRecord();
};
