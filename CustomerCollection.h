/********************************************************************
* File Name: customerCollection.h
* Class Name: CustomerCollection
* Description: This class defines a Collection of Customers
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/

#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H

#include "customer.h"
#include "transaction.h"
#include <iostream>
using namespace std;

class CustomerCollection
{
public:
	CustomerCollection();//constructor
	~CustomerCollection();//destructor

	//add a customer to the collection
	void addCustomer(Customer*);
	//print all cumstomers
	void displayCustomers();
	//add a transaction to the history of a particular customer
	void addTransaction(Transaction*, int);
	//print the entire transaction history
	void displayHistory(int);
	//lookup a customer
	Customer *findCustomer(const int);
private:
	// For the customer collection, an array of 10,000
	// is small enough to hold a 4 digit customer ID
	// without collisions.
	static const int SIZE = 10000;

	// Transaction node data structure for a linked list.
	struct TransactionNode
	{
		TransactionNode *next;
		Transaction* transactionData;
	};

	// customer node data structure for linked list
	struct CustomerNode
	{
		Customer *customerData;
		TransactionNode *transactionHead;
	};
	CustomerNode *customerArray[SIZE];//collection of customers
};
#endif


