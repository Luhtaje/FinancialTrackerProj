#pragma once
#include <iomanip>
#include <iostream>
//Derived class from transaction. Fundamental data class for the program.
class Income : public Transaction
{
public:
	Income();
	Income(string description, int amount, string date);
	~Income()=default;
	string toString()const;
	void print()const;
	int getAmount()const;
private:
	string type;
};


