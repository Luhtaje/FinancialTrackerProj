#pragma once
#include <sstream>
#include "FileManager.h"

/*
FileManager handles all actions with files- saving,reading and clearing.
*/
using namespace std;
FileManager::FileManager() {

}

//Goes through the vector in temporary memory and saves transaction strings into the datafile.
void FileManager::saveToDisk(Record* recordobj){
	int counter = 0;

	for (int i = 0; i != recordobj->record.size(); i++) {
		//Fetches a string from Transaction object and pushes it into the datafile.
		saveTransaction(recordobj->record[i]->toString());
	}
}

//Saves a transaction to datafile.
void FileManager::saveTransaction(string transaction)const {

	ofstream datafile("datafile.txt", std::ios_base::app);
	if (datafile.is_open()) {
		datafile << transaction;
		datafile.close();
	}
	else {
		cout << "Error opening datafile." << endl;
	}

}

/*
Reads data from the disk and creates transactions in to the record.
Record needs to be empty when reading from the disk.
*/
void FileManager::readFromDisk(Record* recordobj) {
	string datastring;
	ifstream datafile("datafile.txt");

	string type;
	string description;
	string date;
	string amountstring;
	int amount;


	if (datafile.is_open())
	{
		if (recordobj->record.empty()) {
			//Tokenize the line read from the datafile and construct transactions.
			//Transactions are pushed to the the record(temporary memory) after construction.
			while (getline(datafile,datastring)){
				stringstream stream(datastring);
				getline(stream,type, ',');
				getline(stream, description, ',');
				getline(stream, amountstring, ',');
				amount = stoi(amountstring);
				getline(stream, date, ',');

				//Construct transaction objects based on the "type" token.
				if (type.compare("Expense") == 0) {
					unique_ptr<Expense> expense = make_unique<Expense>(description, amount, date);
					recordobj->add(move(expense));
				}
				else if(type.compare("Income")==0){
					unique_ptr<Income> income = make_unique<Income>(description, amount, date);
					recordobj->add(move(income));
				}
			}
		}
		//Prints out error msg if trying to read while having transactions in Record.
		else {
			cout << "Error: Record not empty. Please save recently made transactions before reading from disk" << endl;
		}
	}
	datafile.close();
}

//Deletes all contets of the datafile.
void FileManager::clearDisk(Record* recordobj) {
	fstream datafile;
	fclose(fopen("datafile.txt", "w"));

}

//Doesn't work, prints pointer address or just garbage.
ostream& operator<<(ofstream& datafile, unique_ptr<Transaction> transaction) {
	return datafile << transaction->toString();
}
