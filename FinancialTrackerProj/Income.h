#pragma once
#include <iomanip>
#include <iostream>
//Derived class from transaction. Fundamental data class for the program.
class Income : public Transaction
{
public:
	Income();
	Income(string description, double amount, string date);
	~Income()=default;
	string toString()const;
	void print()const;
	double getAmount()const;
private:
	string type;
};


