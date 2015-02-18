/********************************************************************
* File Name: customer.h
* Class Name: Customer
* Description: This class defines a Customer
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <sstream>
using namespace std;
class Customer
{
public:
	//Customer();// default constructor
	// constructor with first, last names and id
	Customer(int, string, string);
	// destructor
	~Customer(){};

	//accessor functions
	int getID() const;
	//prints customer info
	string display();

private:
	int customerID;//customer's id number
	string lastName;//customer's last name
	string firstName;//customer's first name
};
#endif


