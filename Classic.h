/********************************************************************
* File Name: classic.h
* Class Name: Classic
* Description: This class defines the Classic Movie
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#ifndef CLASSIC_H
#define CLASSIC_H

#include "movies.h"
class Classic : public Movies
{
public:
	Classic() : Movies() {};//constructor
	~Classic() {};//destructor

	// Creates a new movie object.
	virtual Movies* createMovie() const;
	// print movie information
	virtual string display() const;

	// Mutator functions
	virtual void setQuantity(int);
	virtual void setMonth(int&);
	virtual void setYear(int&);
	virtual void setDirector(string&);
	virtual void setTitle(string&);
	virtual void setActorFirstName(string&);
	virtual void setActorLastName(string&);

	// Accessor functions
	virtual int getQuantity();
	//virtual int getYear();
	//virtual string getDirector();
	//virtual string getTitle();

	// operator overloading functions
	virtual bool operator< (const Movies &)const;
	virtual bool operator> (const Movies &)const;
	virtual bool operator== (const Movies &)const;

private:
	string actorFirstName;// first name of main actor
	string actorLastName;// last name of main actor
	int month;// month of release
};

#endif

