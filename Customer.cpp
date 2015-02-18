/********************************************************************
* File Name: customer.cpp
* Class Name: Customer
* Description: This class implements a Customer
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#include "customer.h"

///********************************************************************
// * @desc:this is the default constructor
//********************************************************************/
//Customer::Customer()
//{
//	customerID = -1;
//	firstName = "";
//	lastName = "";
//
//}

/********************************************************************
* @desc:Constructor with parameters
* @param: customer id, last name, first name
********************************************************************/
Customer::Customer(int ID, string last, string first)
{
	customerID = ID;
	lastName = last;
	firstName = first;
}

//retrieve this customer's id
int Customer::getID() const
{
	return customerID;
}

/********************************************************************
* @desc: Prints all the information of this customer
* @return: stringstream containing display information
********************************************************************/
string Customer::display()
{
	stringstream output;
	output << customerID << "  " << firstName << "  " << lastName;
	return output.str();
}

