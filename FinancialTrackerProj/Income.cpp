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
		cout << "Transaction created " << endl<< ndl;
	}
	Income::Income(string description, int amount, string date) {
		type = "Income";
		this->description = description;
		this->amount = amount;
		this->date = date + '\n';
	}



	string Income::toString()const {
		return type + ',' + description + "," + to_string(amount) + "," + date + "\n";
	}

	void Income::print()const {
		cout << left << setw(12) << type << left << setw(25) << description<< '+' << left << setw(12) << amount << date;
	}

	int Income::getAmount()const {
		return amount;
	}