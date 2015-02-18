/********************************************************************
* File Name: transaction.h
* Class Name: Transaction
* Description: This class defines the base Transaction class
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "movies.h"
#include "customer.h"

class Transaction
{
public:
	Transaction() {};//constructor
	virtual ~Transaction() {};//destructor
	//create a new transaction
	virtual Transaction* createTransaction() const = 0;
	//print all transaction info
	virtual string display() = 0;
	//this transaction's movie
	virtual void setMovie(Movies*) = 0;

protected:
	Movies *movies;//related movie
	Customer* customer;//related customer
	char transactionType;// borrow or return?
	bool isBorrowed;//is currently borrowed

};
#endif

