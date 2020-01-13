#pragma once
#include <string>
#include <ctime>
/*
Base class for each transaction. Holds important information about each transaction and sets up an interface
*/
using namespace std;

class Transaction
{
public:
	Transaction();
	~Transaction();
	void save()const;
	virtual string toString()const;
	virtual void print()const;
	virtual int getAmount() const;

protected:
	string description;
	int amount;
	string date;
	
private:
	void setDate();
};

