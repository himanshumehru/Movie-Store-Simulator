/********************************************************************
* File Name: drama.cpp
* Class Name: Drama
* Description: This class implements the Drama Movie
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#include "drama.h"

/********************************************************************
* @desc:creates a new Drama movie object
* @return: a new Drama movie object
********************************************************************/
Movies* Drama::createMovie() const
{
	return new Drama();
}

/********************************************************************
* @desc: Displays all available information about movie
********************************************************************/
string Drama::display() const
{
	stringstream output;
	output << director << "  " << title << "  " << year << endl;
	return output.str();
}

//---------------mutator functions
void Drama::setQuantity(int DramaCount)
{
	quantity = DramaCount;
}

void Drama::setYear(int& DramaYear)
{
	year = DramaYear;
}

void Drama::setDirector(string& DramaDirector)
{
	director = DramaDirector;
}

void Drama::setTitle(string& DramaTitle)
{
	title = DramaTitle;
}

//----------------Accessor functions---------
int Drama::getQuantity()
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

bool Drama::operator< (const Movies &rhs) const
{
	int compareDirector =
		director.compare(static_cast<const Drama&>(rhs).director);

	// Return true if title is less than rhs title.
	if (compareDirector < 0)
	{
		return true;
	}

	// If the directors are the same, then compare the titles.
	else if (compareDirector == 0)
	{
		int compareTitle =
			title.compare(static_cast<const Drama&>(rhs).title);

		if (compareTitle < 0)
		{
			return true;
		}

		return false;
	}
	return false;
}

bool Drama::operator>(const Movies &rhs) const
{
	int compareDirector =
		director.compare(static_cast<const Drama&>(rhs).director);

	// Return true if title is greater than rhs title.
	if (compareDirector > 0)
	{
		return true;
	}

	// If the directors are the same, then compare the titles.
	else if (compareDirector == 0)
	{
		int compareTitle =
			title.compare(static_cast<const Drama&>(rhs).title);

		if (compareTitle > 0)
		{
			return true;
		}

		return false;
	}
	return false;
}

bool Drama::operator== (const Movies &rhs) const
{
	int compareDirector =
		director.compare(static_cast<const Drama&>(rhs).director);
	int compareTitle =
		title.compare(static_cast<const Drama&>(rhs).title);

	// If the comedy titles and years are the same.
	if (compareDirector == 0 && compareTitle == 0)
	{
		return true;
	}

	return false;

}

