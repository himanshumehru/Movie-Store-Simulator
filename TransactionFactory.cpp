/********************************************************************
* File Name: transactionFactory.cpp
* Class Name: TransactionFactory
* Description: This class implements a factory of transactions
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#include "transactionFactory.h"

/********************************************************************
* @desc:default constructor
********************************************************************/
TransactionFactory::TransactionFactory()
{
	transactionArray[0] = new Borrow();
	transactionArray[1] = new Return();
}

/********************************************************************
* @desc:destructor
********************************************************************/
TransactionFactory::~TransactionFactory()
{
	for (int i = 0; i < SIZE; i++)
	{
		delete transactionArray[i];
		transactionArray[i] = NULL;
	}
}

/********************************************************************
* @desc:create a new transaction
* @param: type of transaction
********************************************************************/
Transaction *TransactionFactory::createTransaction(char action)
{
	if (action == 'B')
	{
		return transactionArray[0]->createTransaction();
	}
	else if (action == 'R')
	{
		return transactionArray[1]->createTransaction();
	}
	return 0;
}


