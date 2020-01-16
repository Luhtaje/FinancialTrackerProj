#pragma once
#include "Expense.h"
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
Expense::Expense() {
	cin.ignore();
	cout << "Enter description for expense: " << endl;
	getline(cin,description,'\n');
	description = description.length() > 35 ? description.substr(0, 35): description;
	
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
			cout << "Error 99. Invalid input, expected a double. Please input a proper number(such as 100 or 2.50): " << endl;
			cin >> amount;
		}
	}
	type = "Expense";

	cout << "Transaction created " << endl<< endl;
}

Expense::Expense(string description, double amount, string date){
	type = "Expense";
	this->description = description;
	this->amount = amount;
	this->date = date + '\n';
}

//Returns the transaction in a string type.
string Expense::toString()const {
	return type +','+ description + "," + to_string(amount) + "," + date;
}

//Prints data separated in columns.
void Expense::print()const {
	cout << left << setw(12) << type << left << setw(35) << description << '-' << left << setw(12) << amount << date;
}

//Get member "amount". Expense returns negative, Income returns positive.
double Expense::getAmount()const {
	return -amount;
}