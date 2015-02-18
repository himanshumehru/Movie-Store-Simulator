/********************************************************************
* File Name: customerCollection.cpp
* Class Name: CustomerCollection
* Description: This class implements a Collection of Customers
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/

#include "customerCollection.h"

/********************************************************************
* @desc: default constructor
********************************************************************/
CustomerCollection::CustomerCollection()
{
	for (int i = 0; i < SIZE; i++)
	{
		customerArray[i] = NULL;
	}
}

/********************************************************************
* @desc: Destructor of this collection
********************************************************************/
CustomerCollection::~CustomerCollection()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (customerArray[i] != NULL)// if the collection is not empty
		{
			if (customerArray[i]->transactionHead != NULL)
				//if the customer's transaction history is not empty
			{
				//traverse through the history and remove all transactions
				TransactionNode* current = customerArray[i]->transactionHead->next;
				TransactionNode* toDelete = customerArray[i]->transactionHead;
				while (toDelete != NULL)
				{
					delete toDelete;
					toDelete = current;
					if (current != NULL)
					{
						current = current->next;
					}
				}
			}
		}
	}
}

/********************************************************************
* @desc: Adds a customer to this collection
* @param: customerObject: a new customer to add to this collection
********************************************************************/
void CustomerCollection::addCustomer(Customer* customerObject)
{
	int customerIndex = customerObject->getID();

	if (customerArray[customerIndex] == NULL)
	{
		// create a new node
		customerArray[customerIndex] = new CustomerNode;
		//set it's data pointer to the customer
		customerArray[customerIndex]->customerData = customerObject;
		//initialize customer's transaction history
		customerArray[customerIndex]->transactionHead = NULL;
	}
}

/********************************************************************
* @desc: Prints out all the customers' information
********************************************************************/
void CustomerCollection::displayCustomers()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (customerArray[i] != NULL)
		{
			cout << customerArray[i]->customerData->display() << endl;
		}
	}
}

/********************************************************************
* @desc: Prints the transation history of a customer
* @param: id : customer in question
********************************************************************/
void CustomerCollection::displayHistory(int id)
{
	if (customerArray[id] != NULL)
	{
		if (customerArray[id]->transactionHead != NULL)
		{
			TransactionNode* current = customerArray[id]->transactionHead;
			while (current)
			{
				cout << current->transactionData->display() << endl;
				current = current->next;
			}
		}
		else
		{//if the customer has no history
			cout << "CUSTOMER #" << id << " HAS NO HISTORY" << endl;
		}
	}
}

/********************************************************************
* @desc: adds a transaction to a customer's transaction history
* @param: transaction to be added and the customer's id
********************************************************************/
void CustomerCollection::addTransaction(Transaction* transactionObject,
	int id)
{
	TransactionNode *transactionNode = new TransactionNode;
	transactionNode->transactionData = transactionObject;
	transactionNode->next = NULL;
	TransactionNode *nodePtr;

	if (customerArray[id] == NULL)
	{
		//customer doesn't exist
		cout << "INVALID CUSTOMER ID" << endl;
	}
	else
	{//first ever transaction
		if (customerArray[id]->transactionHead == NULL)
		{
			customerArray[id]->transactionHead = transactionNode;
		}
		else
		{
			nodePtr = customerArray[id]->transactionHead;
			//traverse the history and add this transaction to the end
			while (nodePtr->next)
			{
				nodePtr = nodePtr->next;
			}
			nodePtr->next = transactionNode;
		}
	}
}

/********************************************************************
* @desc: Look up a customer in this collection
* @return: customer found
********************************************************************/
Customer *CustomerCollection::findCustomer(const int id)
{
	if (customerArray[id] != NULL)
	{
		return customerArray[id]->customerData;
	}
	return NULL;
}



