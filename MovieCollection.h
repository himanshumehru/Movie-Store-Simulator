/********************************************************************
* File Name: movieCollection.h
* Class Name: MovieCollection
* Description: This class defines a Collection of Movies
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/

#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include "movies.h"
#include <iostream>

class MovieCollection
{
public:
	MovieCollection();//constructor
	~MovieCollection();//destructor


	// Adds movies to movie collection.
	bool addMovie(const char, Movies*);

	// Searches movie collection to see if the movie
	// in the transaction is part of the collection
	virtual Movies *findMovie(Movies*, const char);
	//print all movies
	void displayMovies();
private:

	// 239 is a prime number closest to 
	// the highest printable ascii value * 2
	static const int SIZE = 239;

	//data stucture to hold movies (bst)
	struct MovieNode
	{
		Movies *movieData;//root movie
		MovieNode *left;//movie to the left
		MovieNode *right;//movie to the right

	};

	MovieNode *treeArray[SIZE];
	virtual void deleteHelper(MovieNode*);//remove a movie helper
	//add a movie to the collection helper
	virtual bool addMovieHelper(MovieNode*, MovieNode*);
	//print all available movies helper
	void displayMoviesHelper(MovieNode*);

};
#endif


