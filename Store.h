/********************************************************************
* File Name: store.h
* Class Name: Store
* Description: This class defines the main Movie Store
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#ifndef STORE_H
#define STORE_H

#include "customerCollection.h"
#include "movies.h"
#include "movieFactory.h"
#include "movieCollection.h"
#include "transaction.h"
#include "transactionFactory.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class Store
{
public:
	Store();//constructor
	~Store();//destructor

	// Adding movies from a text file.
	void addMovies(istream &);
	// Adding customers from a text file.
	void addCustomers(istream &);
	// Interpreting movie store commands from a text file.
	void runStore(istream &);

	// Creating a movie object.
	Movies* movieCopy(istream &, char, char);



private:
	MovieFactory movieFactory;// factory that creates movies
	//factory that creates transactions
	TransactionFactory transactionFactory;
	MovieCollection *movieCollection;//movie database
	CustomerCollection *customerCollection;//customer database
	Transaction* transaction;
	Movies* movieObject;
	Customer* customer;
};

#endif


