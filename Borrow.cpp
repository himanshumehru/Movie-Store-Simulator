/********************************************************************
 * File Name: borrow.cpp
 * Class Name: Borrow
 * Description: This class implements the Borrow Transaction 
 * Authors: Himanshu Mehru, Igor Ummel
 * Date: December 03, 2013
 * Version: v1.0
 * Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
 *******************************************************************/
#include "borrow.h"


/********************************************************************
 * @desc: Creates a new Borrow Transaction
********************************************************************/
Transaction* Borrow::createTransaction() const
{
	return new Borrow();
}

/********************************************************************
 * @desc: Prints all the information of this borrow transaction
 * @return: stringstream containing display information
********************************************************************/
string Borrow::display()
{
	stringstream output;
	output << "Borrow: " << movies->display();
	return output.str();
}

/********************************************************************
 * @desc:sets this transaction's movie to the parameter
 * @param: Borrowed movie
********************************************************************/
void Borrow::setMovie(Movies *borrowed)
{
	movies = borrowed;
}

