/********************************************************************
* File Name: transactionFactory.h
* Class Name: TransactionFactory
* Description: This class defines a factory of transactions
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "transaction.h"
#include "borrow.h"
#include "return.h"

class TransactionFactory
{
public:
	TransactionFactory();//constructor
	~TransactionFactory();//destructor

	//create a new transaction
	Transaction *createTransaction(char);

private:
	static const int SIZE = 2;//borrow or return?
	//all the types of transactions
	Transaction *transactionArray[SIZE];
};
#endif

