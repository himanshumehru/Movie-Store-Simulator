/********************************************************************
* File Name: drama.h
* Class Name: Drama
* Description: This class defines the Drama Movie
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#ifndef DRAMA_H
#define DRAMA_H

#include "movies.h"
class Drama : public Movies
{
public:
	Drama() : Movies() {};// constructor
	~Drama() {};//destructor

	// Creates a new movie object.
	virtual Movies* createMovie() const;
	//print all available movie info
	virtual string display() const;

	//mutator functions
	virtual void setQuantity(int);
	virtual void setYear(int&);
	virtual void setDirector(string&);
	virtual void setTitle(string&);
	//accessor functions
	virtual int getQuantity();
	//operator overloading functions
	virtual bool operator< (const Movies &)const;
	virtual bool operator> (const Movies &)const;
	virtual bool operator== (const Movies &)const;
};
#endif



