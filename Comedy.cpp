/********************************************************************
* File Name: comedy.cpp
* Class Name: Comedy
* Description: This class implements the Comedy Movie
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#include "comedy.h"

/********************************************************************
* @desc:creates a new Comedy movie object
* @return: a new Comedy movie object
********************************************************************/
Movies* Comedy::createMovie() const
{
	return new Comedy();
}

/********************************************************************
* @desc: Displays all available information about movie
********************************************************************/
string Comedy::display() const
{
	stringstream output;
	output << title << "  " << year << "  " << director << endl;
	return output.str();
}
//---------------mutator functions
void Comedy::setQuantity(int comedyCount)
{
	quantity = comedyCount;
}

void Comedy::setYear(int& comedyYear)
{
	year = comedyYear;
}

void Comedy::setDirector(string& comedyDirector)
{
	director = comedyDirector;
}

void Comedy::setTitle(string& comedyTitle)
{
	title = comedyTitle;
}

//----------------Accessor functions---------
int Comedy::getQuantity()
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


// Overloading comparison operators.

bool Comedy::operator< (const Movies &rhs) const
{
	int compareTitle =
		title.compare(static_cast<const Comedy&>(rhs).title);

	// Return true if title is less than rhs title.
	if (compareTitle < 0)
	{
		return true;
	}

	// If the titles are the same, then compare the years.
	else if (compareTitle == 0)
	{
		int rhsYear = static_cast<const Comedy&>(rhs).year;
		if (year < rhsYear)
		{
			return true;
		}
		return false;
	}
	return false;
}

bool Comedy::operator>(const Movies &rhs) const
{
	int compareTitle =
		title.compare(static_cast<const Comedy&>(rhs).title);

	// Return true if title is greater than rhs title.
	if (compareTitle > 0)
	{
		return true;
	}

	// If the titles are the same, then compare the years.
	else if (compareTitle == 0)
	{
		int rhsYear = static_cast<const Comedy&>(rhs).year;
		if (year > rhsYear)
		{
			return true;
		}

		return false;
	}
	return false;
}

bool Comedy::operator== (const Movies &rhs) const
{
	int compareTitle =
		title.compare(static_cast<const Comedy&>(rhs).title);
	int rhsYear = static_cast<const Comedy&>(rhs).year;

	// If the comedy titles and years are the same.
	if (compareTitle == 0 && year == rhsYear)
	{
		return true;
	}

	return false;

}

