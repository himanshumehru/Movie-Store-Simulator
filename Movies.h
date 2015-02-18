/********************************************************************
* File Name: movies.h
* Class Name: Movies
* Description: This class defines the base class of Movies
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#ifndef MOVIES_H
#define MOVIES_H

//#include <string>
#include <sstream>
//#include <iostream>
using namespace std;
class Movies
{
public:
	Movies() {};//default constructor
	virtual ~Movies() {};// destructor

	// Creates a new movie object.
	virtual Movies* createMovie() const = 0;
	// Function used to print out information about the media object.
	virtual string display() const = 0;

	//virtual void setData(string &) = 0;

	// mutator functions
	virtual void setQuantity(int) = 0;
	virtual void setYear(int&) = 0;
	virtual void setDirector(string&) = 0;
	virtual void setTitle(string&) = 0;

	//accessor functions
	virtual int getQuantity() = 0;
	//virtual int getYear() = 0;
	//virtual string getDirector() = 0;
	//virtual string getTitle() = 0;

	//Operator overloading functions
	virtual bool operator< (const Movies &)const = 0;
	virtual bool operator> (const Movies &)const = 0;
	virtual bool operator== (const Movies &)const = 0;


protected:
	int quantity;// copies of a movie
	int year;// year of release
	string title;// title of the movie
	string director;//name of the director
};

#endif

