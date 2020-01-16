#pragma once
#include "Transaction.h"
#include "Record.h"
//Derived class from transaction. Fundamental data class for the program.
class Expense : public Transaction
{
public:
	Expense();
	Expense(string description, double amount,string date);
	~Expense()=default;
	string toString()const;
	void print()const ;
	double getAmount()const;
private:
	string type;
};

