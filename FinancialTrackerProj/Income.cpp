#pragma once
#include "Transaction.h"
#include "Income.h"

Income::Income() {
	cin.ignore();
	cout << "Enter description for income: " << endl;
	getline(cin, description, '\n');
	description = description.length() > 35 ? description.substr(0, 35) : description;

	cout << "Enter the amount in numbers:" << endl;
	try {
		cin >> amount;
		if (cin.fail()) {
			throw 99;
		}
	
	}
	catch (int x) {
		if (x == 99) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "Error 99. Invalid input, expected a double. Please input a proper number(such as 100 or 100.50): " << endl;
			cin >> amount;
		}
	}
	type = "Income";
	cout << "Transaction created " << endl<< endl;
}
Income::Income(string description, double amount, string date) {
	type = "Income";
	this->description = description;
	this->amount = amount;
	this->date = date + '\n';
}


//Returns the transaction in a string type.
string Income::toString()const {
	return type + ',' + description + "," + to_string(amount) + "," + date;
}
//Prints data in columns.
void Income::print()const {
	cout << left << setw(12) << type << left << setw(35) << description<< '+' << left << setw(12) << amount << date;
}
//Get member "amount".Expense returns negative, Income returns positive.
double Income::getAmount()const {
	return amount;
}