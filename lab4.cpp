/********************************************************************
* File Name: lab4.cpp
* Class Name: main of the program
* Description: This class implements main for a MOVIE Store
* Authors: Himanshu Mehru, Igor Ummel
* Date: December 03, 2013
* Version: v1.0
* Faculty: Prof. Carol Zander (CSS 343 Fall 2013)
*******************************************************************/

#include "store.h"
#include <iostream>
#include <fstream>

int main()
{
	Store movieStore;

	ifstream infile1("data4movies.txt");
	if (!infile1)
	{
		cout << "data4movies.txt could not be opened." << endl;
		return 0;
	}

	ifstream infile2("data4customers.txt");
	if (!infile2)
	{
		cout << "data4customers.txt could not be opened." << endl;
		return 0;
	}

	ifstream infile3("data4commands.txt");
	if (!infile3)
	{
		cout << "data4commands.txt could not be opened." << endl;
		return 0;
	}

	movieStore.addMovies(infile1);
	movieStore.addCustomers(infile2);
	movieStore.runStore(infile3);

	return 0;
}

