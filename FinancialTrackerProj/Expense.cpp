#pragma once
#include "Expense.h"
#include <iomanip>
#include <iostream>
using namespace std;
Expense::Expense() {
	cin.ignore();
	cout << "Enter description for expense: " << endl;
	getline(cin,description,'\n');
	
	cout << "Enter the amount in numbers:" << endl;
	cin >> amount;

	type = "Expense";

	cout << "Transaction created " << endl<< endl;
}

Expense::Expense(string description, int amount, string date){
	type = "Expense";
	this->description = description;
	this->amount = amount;
	this->date = date + '\n';
}


string Expense::toString()const {
	return type +','+ description + "," + to_string(amount) + "," + date;
}

void Expense::print()const {
	cout << left << setw(12) << type << left << setw(25) << description << '-' << left << setw(12) << amount << date;
}

int Expense::getAmount()const {
	return -amount;
}