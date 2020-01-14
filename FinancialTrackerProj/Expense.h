#pragma once
#include "Transaction.h"
#include "Record.h"
//Derived class from transaction. Fundamental data class for the program.
class Expense : public Transaction
{
public:
	Expense();
	Expense(string description, int amount,string date);
	~Expense()=default;
	string toString()const;
	void print()const ;
	int getAmount()const;
private:
	string type;
};

