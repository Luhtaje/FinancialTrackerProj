
#pragma once
#include "Record.h"
/*
Record holds transaction in a vector. Record works as a interface between FileHandler and Transactions.
*/
using namespace std;
Record::Record() {
}

//Prints all transactions in columns.
void Record::print() const{	
	double total =0;
	//Print header.
	cout << left << setw(12) << "Type" << left << setw(35) << "Description"  << left << setw(13) << "Amount" << "Date" << endl;

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

ostream& operator<<(ofstream& datafile, Record* recordobj) {

	for (int i = 0; i != recordobj->record.size(); i++) {
		//Fetches a string from Transaction object and pushes it into the datafile.

		if (datafile.is_open()) {
			datafile << recordobj->record[i]->toString();
		}
		else {
			cout << "Error opening datafile." << endl;
		}
	}
	return datafile;
}

//Reads datafile and creates transactions into the vector (temporary memory).
ostream& operator>>(ifstream& datafile, Record* recordobj) {
	//Tokens
	string datastring;
	string type;
	string description;
	string amountstring;
	string date;
	double amount;

	if (recordobj->record.empty()) {
		//Tokenize the line read from the datafile and construct transactions.
		//Transactions are pushed to the the record(temporary memory) after construction.
		while (getline(datafile, datastring)) {
			stringstream stream(datastring);
			getline(stream, type, ',');
			getline(stream, description, ',');
			getline(stream, amountstring, ',');
			amount = stod(amountstring);
			getline(stream, date, ',');

			//Construct transaction objects based on the "type" token.
			if (type.compare("Expense") == 0) {
				unique_ptr<Expense> expense = make_unique<Expense>(description, amount, date);
				recordobj->add(move(expense));
			}
			else if (type.compare("Income") == 0) {
				unique_ptr<Income> income = make_unique<Income>(description, amount, date);
				recordobj->add(move(income));
			}
		}
	}
	//Prints out error msg if trying to read while having transactions in Record.
	else {
		cout << "Error: Record not empty. Please \"save\" or \"flush\" before reading from disk" << endl;
	
	}

	//Theres probably a better way to do this.
	
	return std::cout;
}