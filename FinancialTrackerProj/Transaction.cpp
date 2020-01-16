#pragma once
#include "Transaction.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Transaction::Transaction() {
	setDate();
}

string Transaction::toString()const {
	string temp = description + "," + to_string(amount) + "," + date + "\n";
	return temp;
}

void Transaction::setDate() {
	time_t now = time(0);
	char* dt = ctime(&now);
	date = string(dt);
}

void Transaction::print()const {
	cout << "printing from baseclass";
}
double Transaction::getAmount()const {
	return amount;
}

Transaction::~Transaction() {};