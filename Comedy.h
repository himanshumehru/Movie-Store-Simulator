/********************************************************************
* File Name: comedy.h
* Class Name: Comedy
* Description: This class defines the Comedy Movie
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#ifndef COMEDY_H
#define COMEDY_H

#include "movies.h"
class Comedy : public Movies
{
public:
	Comedy() : Movies() {};
	~Comedy() {};

	// Creates a new movie object.
	virtual Movies* createMovie() const;
	// prints all available movie info
	virtual string display() const;

	//mutator functions
	virtual void setQuantity(int);
	virtual void setYear(int&);
	virtual void setDirector(string&);
	virtual void setTitle(string&);

	//accessor functions
	virtual int getQuantity();
	//virtual int getYear();
	//virtual string getDirector();
	//virtual string getTitle();

	//overloading operator functions
	virtual bool operator< (const Movies &)const;
	virtual bool operator> (const Movies &)const;
	virtual bool operator== (const Movies &)const;
};

#endif



