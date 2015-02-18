/********************************************************************
* File Name: return.h
* Class Name: Return
* Description: This class defines the Return Transaction
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/

#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"
class Return : public Transaction
{
public:
	Return() : Transaction() {};//constructor
	~Return() {};//destructor
	//create a new return transaction
	virtual Transaction* createTransaction() const;
	//print return transaction info
	virtual string display();
	//movie that has been returned
	virtual void setMovie(Movies*);
};
#endif


