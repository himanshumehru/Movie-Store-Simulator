/********************************************************************
* File Name: movieFactory.cpp
* Class Name: MovieFactory
* Description: This class implements a Factory of Movies
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#include "movieFactory.h"

/********************************************************************
* @desc:default constructor
********************************************************************/
MovieFactory::MovieFactory()
{
	movieArray[0] = new Classic;
	movieArray[1] = new Drama;
	movieArray[2] = new Comedy;
}

/********************************************************************
* @desc:destructor
********************************************************************/
MovieFactory::~MovieFactory()
{
	for (int i = 0; i < SIZE; i++)
	{
		delete movieArray[i];
		movieArray[i] = NULL;
	}
}

/********************************************************************
* @desc:create a new movie
* @param: type/genre of the movie
********************************************************************/
Movies* MovieFactory::createMovie(char type)
{
	int movieIndex = movieHash(type);
	return movieArray[movieIndex]->createMovie();
}

/********************************************************************
* @desc:hash function for movies bucketed by type of movie
********************************************************************/
int MovieFactory::movieHash(char type)
{
	switch (type)
	{
		// If typecode is a classic...
	case 'C':
		return 0;
		break;
		// If typecode is a drama...
	case 'D':
		return 1;
		break;

		// If typecode is a comedy...
	case 'F':
		return 2;
		break;

	default: cout << "Cannot map movie type.";
	}
}

