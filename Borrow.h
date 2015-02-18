/********************************************************************
 * File Name: borrow.h
 * Class Name: Borrow
 * Description: This class defines the Borrow Transaction 
 * Authors: Himanshu Mehru, Igor Ummel
 * Date: December 03, 2013
 * Version: v1.0
 * Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
 *******************************************************************/
#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"

class Borrow : public Transaction
{
public:
	Borrow() : Transaction() {};//constructor
	~Borrow() {};//destructor

	//creates a transaction of type borrow
	virtual Transaction* createTransaction() const;
	//display transaction info
	virtual string display();

	// sets borrowed movie
	virtual void setMovie(Movies*);

};
#endif


