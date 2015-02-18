/********************************************************************
* File Name: return.cpp
* Class Name: Return
* Description: This class implements the Return Transaction
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/

#include "return.h"

/********************************************************************
* @desc: Creates a new Return Transaction
********************************************************************/
Transaction* Return::createTransaction() const
{
	return new Return();
}

/********************************************************************
* @desc: Prints all the information of this return transaction
* @return: stringstream containing display information
********************************************************************/
string Return::display()
{
	stringstream output;
	output << "Return: " << movies->display();
	return output.str();
}

/********************************************************************
* @desc:sets this transaction's movie to the parameter
* @param: returned movie
********************************************************************/
void Return::setMovie(Movies *returned)
{
	movies = returned;
}

