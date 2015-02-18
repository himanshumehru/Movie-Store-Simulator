/********************************************************************
* File Name: movieFactory.h
* Class Name: MovieFactory
* Description: This class defines a Factory of Movies
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "movies.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"

#include <iostream>

class MovieFactory
{
public:
	MovieFactory();//constructor
	virtual ~MovieFactory();//destructor
	virtual Movies *createMovie(char);//create a movie object

private:
	static const int SIZE = 3;//could be set to 26 for all chars
	// Array that holds a variety of movie objects.
	Movies *movieArray[SIZE];
	int movieHash(char);//hash function for movies.
};
#endif


