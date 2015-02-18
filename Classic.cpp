/********************************************************************
* File Name: classic.cpp
* Class Name: Classic
* Description: This class implements the Classic Movie
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#include "classic.h"

/********************************************************************
* @desc:creates a new Classic movie object
* @return: a new classic movie object
********************************************************************/
Movies* Classic::createMovie() const
{
	return new Classic();
}

/********************************************************************
* @desc: Displays all available information about movie
********************************************************************/
string Classic::display() const
{
	stringstream output;
	output << year << "  " << month << "  "
		<< actorLastName << ", " << actorFirstName << "  "
		<< title << "  " << director << endl;
	return output.str();
}
//---------------mutator functions
void Classic::setQuantity(int classicCount)
{
	quantity = classicCount;
}

void Classic::setMonth(int& classicMonth)
{
	month = classicMonth;
}
void Classic::setYear(int& classicYear)
{
	year = classicYear;
}

void Classic::setDirector(string& classicDirector)
{
	director = classicDirector;
}

void Classic::setTitle(string& classicTitle)
{
	title = classicTitle;
}

void Classic::setActorFirstName(string& classicFirstName)
{
	actorFirstName = classicFirstName;
}

void Classic::setActorLastName(string& classicLastName)
{
	actorLastName = classicLastName;
}
//----------------Accessor functions---------
int Classic::getQuantity()
{
	return quantity;
}

//int Comedy::getYear()
//{
//	return year;
//}
//
//string Comedy::getDirector()
//{
//	return director;
//}
//
//string Comedy::getTitle()
//{
//	return title;
//}


// Overloading operator functions.

bool Classic::operator< (const Movies &rhs) const
{
	// First compare the years...
	int rhsYear = static_cast<const Classic&>(rhs).year;
	if (year < rhsYear)
	{
		return true;
	}
	// If the years are the same, then compare the months.
	else if (year == rhsYear)
	{
		int rhsMonth = static_cast<const Classic&>(rhs).month;
		if (month < rhsMonth)
		{
			return true;
		}
		// If the months are the same, then compare the actors' last names.
		else if (month == rhsMonth)
		{
			int compareLastName =
				actorLastName.compare(static_cast<const
				Classic&>(rhs).actorLastName);
			if (compareLastName < 0)
			{
				return true;
			}
			// If the actors' last names are the same, 
			// then compare the actors' first names.
			else if (compareLastName == 0)
			{
				int compareFirstName =
					actorFirstName.compare(static_cast<const
					Classic&>(rhs).actorFirstName);
				if (compareFirstName < 0)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}
	return false;
}

bool Classic::operator>(const Movies &rhs) const
{
	// First compare the years...
	int rhsYear = static_cast<const Classic&>(rhs).year;
	if (year > rhsYear)
	{
		return true;
	}
	// If the years are the same, then compare the months.
	else if (year == rhsYear)
	{
		int rhsMonth = static_cast<const Classic&>(rhs).month;
		if (month > rhsMonth)
		{
			return true;
		}
		// If the months are the same, then compare the actors' last names.
		else if (month == rhsMonth)
		{
			int compareLastName =
				actorLastName.compare(static_cast<const
				Classic&>(rhs).actorLastName);
			if (compareLastName > 0)
			{
				return true;
			}
			// If the actors' last names are the same, 
			// then compare the actors' first names.
			else if (compareLastName == 0)
			{
				int compareFirstName =
					actorFirstName.compare(static_cast<const
					Classic&>(rhs).actorFirstName);
				if (compareFirstName > 0)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}
	return false;
}

bool Classic::operator== (const Movies &rhs) const
{
	//If rhs is niether less than or greater than this movie
	// it must be equal.
	int rhsYear = static_cast<const Classic&>(rhs).year;
	int rhsMonth = static_cast<const Classic&>(rhs).month;
	int compareLastName =
		actorLastName.compare(static_cast<const Classic&>(rhs).actorLastName);
	int compareFirstName =
		actorFirstName.compare(static_cast<const Classic&>(rhs).actorFirstName);

	if (year == rhsYear && month == rhsMonth &&
		compareLastName == 0 && compareFirstName == 0)
	{
		return true;
	}

	return false;

}

