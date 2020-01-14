#pragma once
#include "Transaction.h"
#include "Income.h"

Income::Income() {
	cin.ignore();
	cout << "Enter description for income: " << endl;
	getline(cin, description, '\n');

	cout << "Enter the amount in numbers:" << endl;
	cin >> amount;

	type = "Income";
	cout << "Transaction created " << endl<< endl;
}
Income::Income(string description, int amount, string date) {
	type = "Income";
	this->description = description;
	this->amount = amount;
	this->date = date + '\n';
}


////Returns the transaction in a string type.
string Income::toString()const {
	return type + ',' + description + "," + to_string(amount) + "," + date + "\n";
}
//Prints data in columns.
void Income::print()const {
	cout << left << setw(12) << type << left << setw(25) << description<< '+' << left << setw(12) << amount << date;
}
//Get member "amount".
int Income::getAmount()const {
	return amount;
}