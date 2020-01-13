
#pragma once
#include "Record.h"
#include <iostream>
#include <iomanip>

/*
Record holds transaction in a vector. Record works as a interface between FileHandler and Transactions.
*/
using namespace std;
Record::Record() {
}

Record::~Record() {
	
}


//Prints all transactions in columns.
void Record::print() const{	
	int total =0;
	//Print header.
	cout << left << setw(12) << "Type" << left << setw(25) << "Description"  << left << setw(12) << "Amount" << "date" << endl;

	//Print the data in the vector.
	for (int i = 0; i != record.size(); ++i) {
		record[i]->print();
		total += record[i]->getAmount();
	}
	cout << "Total sum of transactions: " << total<< endl;
}

//Transfers transaction to the vector.
void Record::add(unique_ptr<Transaction> transaction) {
	record.push_back(move(transaction));
}

//Clears the vector of transactions.
void Record::flushRecord() {
	record.clear();
}