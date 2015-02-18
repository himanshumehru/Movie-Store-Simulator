/********************************************************************
* File Name: movieCollection.cpp
* Class Name: MovieCollection
* Description: This class implements a Collection of Movies
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#include "movieCollection.h"

/********************************************************************
* @desc: default Constructor
********************************************************************/
MovieCollection::MovieCollection()
{
	for (int i = 0; i < SIZE; i++)
	{
		treeArray[i] = NULL;
	}
}

/********************************************************************
* @desc:Destructor
********************************************************************/
MovieCollection::~MovieCollection()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (treeArray[i] != NULL)
		{
			deleteHelper(treeArray[i]);
		}
	}
}

/********************************************************************
* @desc:helper method for emptying this collection
* @param: current: the current movie node
********************************************************************/
void MovieCollection::deleteHelper(MovieNode* current)
{
	if (current != NULL)
	{
		//delete all the movies to the left
		if (current->left != NULL)
		{
			deleteHelper(current->left);
		}
		//delete all the movies to the right
		if (current->right != NULL)
		{
			deleteHelper(current->right);
		}
		delete current;
		current = NULL;
	}
}

/********************************************************************
* @desc:add a movie to this collection
* @param: type: genre of the movie, and the movie object
********************************************************************/
bool MovieCollection::addMovie(const char type, Movies* movieObject)
{
	// Maps the search key into a location of treeArray
	// that will contain the item.
	int movieIndex = type % SIZE;

	MovieNode *movieNode = new MovieNode;

	// MovieNode's MovieData pointer now points to object
	// that was created by MovieFactory.
	movieNode->movieData = movieObject;
	movieNode->left = NULL;
	movieNode->right = NULL;

	// If the pointer points to null in the mapped
	// location of the treeArray, then the tree is empty.
	if (treeArray[movieIndex] == NULL)
	{
		// Add the node to the tree.
		treeArray[movieIndex] = movieNode;
		return true;
	}

	else
	{
		// Search the tree find correct insert location.
		return addMovieHelper(treeArray[movieIndex], movieNode);
	}
	return true;
}

/********************************************************************
* @desc:helper method for adding the movie
* @param: current: the current movie node, and the node to be inserted
********************************************************************/
bool MovieCollection::addMovieHelper
(MovieNode* current, MovieNode* insertMovieNode)
{
	// If node to be inserted is less than current node...
	if (*insertMovieNode->movieData < *current->movieData)
	{
		// If the current node has no left child...
		if (current->left == NULL)
		{
			//Insert node as current's left child.
			current->left = insertMovieNode;
		}
		else
		{
			// Traverse the current node's left subtree.
			return addMovieHelper(current->left, insertMovieNode);
		}
	}
	// If node to be inserted is greater than current node...
	else if (*insertMovieNode->movieData > *current->movieData)
	{
		// If the current node has no right child...
		if (current->right == NULL)
		{
			//Insert node as current's right child.
			current->right = insertMovieNode;
		}
		else
		{
			// Traverse the current node's right subtree.
			return addMovieHelper(current->right, insertMovieNode);
		}
	}

	// If node to be inserted is equal to current node.
	else if (*insertMovieNode->movieData == *current->movieData)
	{
		// Because a duplicate movie is being inserted, add the two 
		// quantities together.
		current->movieData->setQuantity(current->movieData->getQuantity()
			+ insertMovieNode->movieData->getQuantity());

		// and then delete the insertMovieNode becuase 
		// it has already been inserted.
		delete insertMovieNode;
		insertMovieNode = NULL;
	}
	// If the movie cannot be inserted...
	return false;
}

/********************************************************************
* @desc:Prints all the movies in this collection
********************************************************************/
void MovieCollection::displayMovies()
{
	// Map out the ditinct location in the treeArray.
	int movieIndex = 'C' % SIZE;
	cout << "CLASSIC" << endl << endl;
	cout << "YEAR " << " MONTH " << " ACTOR "
		<< " TITLE " << " DIRECTOR " << endl;
	if (treeArray[movieIndex] != NULL)
	{
		displayMoviesHelper(treeArray[movieIndex]);
	}

	movieIndex = 'D' % SIZE;
	cout << "DRAMA" << endl << endl;
	cout << "DIRECTOR " << " TITLE " << "YEAR" << endl;
	if (treeArray[movieIndex] != NULL)
	{
		displayMoviesHelper(treeArray[movieIndex]);
	}

	movieIndex = 'F' % SIZE;
	cout << "COMEDY" << endl << endl;
	cout << "TITLE " << " YEAR " << "DIRECTOR" << endl;
	if (treeArray[movieIndex] != NULL)
	{
		displayMoviesHelper(treeArray[movieIndex]);
	}
}

// Inorder traversal of all the movies in this collection
void MovieCollection::displayMoviesHelper(MovieNode* root)
{
	//print all the movies info to the left
	if (root->left != NULL)
	{
		displayMoviesHelper(root->left);
	}
	cout << root->movieData->getQuantity() <<
		" " << root->movieData->display();
	//print all the movies info to the right
	if (root->right != NULL)
	{
		displayMoviesHelper(root->right);
	}
}

/********************************************************************
* @desc:finds a movie in this collection
* @param: findCopy: available copy of the movie , and genre type
********************************************************************/
Movies* MovieCollection::findMovie(Movies* findCopy, const char type)
{
	int movieIndex = type % SIZE;
	// Set current pointer to the root of the tree.
	MovieNode* current = treeArray[movieIndex];

	while (current != NULL)
	{
		if (*findCopy == *current->movieData)
		{
			return current->movieData;
		}
		else if (*findCopy < *current->movieData)
		{
			current = current->left;
		}
		else if (*findCopy > *current->movieData)
		{
			current = current->right;
		}
	}
	return NULL;
}



