/********************************************************************
* File Name: store.cpp
* Class Name: Store
* Description: This class implements the main Movie Store
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/
#include "store.h"

/********************************************************************
* @desc:default constructor
********************************************************************/
Store::Store()
{
	movieCollection = new MovieCollection;
	customerCollection = new CustomerCollection;
}

/********************************************************************
* @desc:detructor
********************************************************************/
Store::~Store()
{
	delete movieCollection;
	movieCollection = NULL;

	delete customerCollection;
	customerCollection = NULL;

	delete transaction;
	transaction = NULL;

	delete movieObject;
	movieObject = NULL;

	delete customer;
	customer = NULL;

}

/********************************************************************
* @desc:adds movies to the store inventory
* @param: infile: stream of movies
********************************************************************/
void Store::addMovies(istream &infile)
{
	char movieType;
	int month, year;
	string movieTitle, director, actorFirstName, actorLastName;

	while (!infile.eof())
	{
		// Read in the type of movie.
		infile >> movieType;
		// If the movie is a classic...
		if (movieType == 'C')
		{
			infile.get();
			getline(infile, director, ',');
			infile.get();
			getline(infile, movieTitle, ',');
			infile >> actorFirstName >> actorLastName >> month >> year;

			movieObject = movieFactory.createMovie(movieType);
			movieObject->setDirector(director);
			movieObject->setTitle(movieTitle);
			movieObject->setYear(year);
			movieObject->setQuantity(10);
			static_cast<Classic*>(movieObject)->
				setActorFirstName(actorFirstName);
			static_cast<Classic*>(movieObject)->
				setActorLastName(actorLastName);
			static_cast<Classic*>(movieObject)->
				setMonth(month);

			movieCollection->addMovie(movieType, movieObject);

		}
		//// If the movie is a drama...
		else if (movieType == 'D')
		{
			// Get drama information from file
			infile.get();
			getline(infile, director, ',');
			infile.get();
			getline(infile, movieTitle, ',');
			infile >> year;

			movieObject = movieFactory.createMovie(movieType);
			movieObject->setDirector(director);
			movieObject->setTitle(movieTitle);
			movieObject->setYear(year);
			movieObject->setQuantity(10);

			movieCollection->addMovie(movieType, movieObject);

		}

		// If the movie is a comedy...
		else if (movieType == 'F')
		{
			// Get comedy information from file
			infile.get();
			getline(infile, director, ',');
			infile.get();
			getline(infile, movieTitle, ',');
			infile >> year;

			movieObject = movieFactory.createMovie(movieType);
			movieObject->setDirector(director);
			movieObject->setTitle(movieTitle);
			movieObject->setYear(year);
			movieObject->setQuantity(10);

			movieCollection->addMovie(movieType, movieObject);
		}

		else
		{
			// If the movie type does not match.
			// Read in the line and store it in a variable.
			string invalid;
			getline(infile, invalid);
		}

	}
}

/********************************************************************
* @desc:adds customers to the store customer database
* @param: infile: stream of customers
********************************************************************/
void Store::addCustomers(istream &infile)
{
	int id;
	string lname;
	string fname;

	while (!infile.eof())
	{
		infile >> id >> lname >> fname;
		customer = new Customer(id, lname, fname);
		customerCollection->addCustomer(customer);
	}

}

/********************************************************************
* @desc:runs the store based on inputed commands
* @param: infile: stream of commands
********************************************************************/
void Store::runStore(istream &infile)
{
	char command, mediaType, movieType;
	int customerID;

	while (!infile.eof())
	{
		infile >> command;

		if (command == 'B')
		{
			infile >> customerID >> mediaType >> movieType;
			// Create a movie object based on data from the text file.
			Movies* copyPtr = movieCopy(infile, mediaType, movieType);

			if (copyPtr != NULL)
			{
				Movies* movieResult = movieCollection->findMovie(copyPtr, movieType);
				if (movieResult != NULL && movieResult->getQuantity() > 0)
				{
					// Decrement the count becuase the movie is borrowed.
					movieResult->setQuantity(movieResult->getQuantity() - 1);
					transaction =
						transactionFactory.createTransaction(command);
					transaction->setMovie(movieResult);
					customerCollection->
						addTransaction(transaction, customerID);
				}
				else
				{
					cout << "MOVIE CANNOT BE BORROWED" << endl;
				}
				delete copyPtr;
				copyPtr = NULL;
			}
			string s;
			getline(infile, s);
		}
		else if (command == 'R')
		{
			infile >> customerID >> mediaType >> movieType;
			// Create a movie object based on data from the text file.
			Movies* copyPtr = movieCopy(infile, mediaType, movieType);

			if (copyPtr != NULL)
			{
				Movies* movieResult = movieCollection->findMovie(copyPtr, movieType);
				if (movieResult != NULL && movieResult->getQuantity() > 0)
				{
					// Increment the count becuase the movie is borrowed.
					movieResult->setQuantity(movieResult->getQuantity() + 1);
					transaction =
						transactionFactory.createTransaction(command);
					transaction->setMovie(movieResult);
					customerCollection->
						addTransaction(transaction, customerID);
				}
				else
				{
					cout << "MOVIE CANNOT BE RETURNED" << endl;
				}
				delete copyPtr;
				copyPtr = NULL;
			}
			string s;
			getline(infile, s);
		}
		else if (command == 'H')
		{
			int customerID;
			infile >> customerID;

			Customer* customerResult = customerCollection->findCustomer(customerID);
			if (customerResult != NULL)
			{
				cout << customerResult->display() << endl;
				customerCollection->displayHistory(customerID);
			}
			string s;
			getline(infile, s);
		}
		else if (command == 'S')
		{
			movieCollection->displayMovies();
		}
		else
		{
			// If the command type does not match.
			// Read in the line and store it in a variable.
			string invalid;
			getline(infile, invalid);
		}
	}
}
// movieCopy creates a new movie object that holds the
// information found in the commands text file.
Movies *Store::movieCopy(istream & infile, char mediatype, char movietype)
{
	int month, year;
	string director, title, firstName, lastName;

	// If the movie is not a DVD.
	if (mediatype != 'D')
	{
		cout << "MEDIA TYPE NOT FOUND" << endl;
		return NULL;
	}

	if (movietype == 'C')
	{
		infile >> month >> year >> firstName >> lastName;

		Movies* movieObject = movieFactory.createMovie(movietype);
		movieObject->setYear(year);
		static_cast<Classic*>(movieObject)->
			setActorFirstName(firstName);
		static_cast<Classic*>(movieObject)->
			setActorLastName(lastName);
		static_cast<Classic*>(movieObject)->
			setMonth(month);

		return movieObject;
	}

	else if (movietype == 'D')
	{
		infile.get();
		getline(infile, director, ',');
		infile.get();
		getline(infile, title, ',');

		Movies* movieObject = movieFactory.createMovie(movietype);
		movieObject->setDirector(director);
		movieObject->setTitle(title);

		return movieObject;
	}

	else if (movietype == 'F')
	{
		infile.get();
		getline(infile, title, ',');
		infile >> year;

		Movies* movieObject = movieFactory.createMovie(movietype);
		movieObject->setTitle(title);
		movieObject->setYear(year);

		return movieObject;
	}

	else
	{
		cout << "MEDIA TYPE NOT FOUND" << endl;
		return NULL;
	}
	return NULL;
}

