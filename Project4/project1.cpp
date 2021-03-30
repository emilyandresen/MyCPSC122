/*
Name: Emily Andresen
Class: CPSC 122, Section 2
Date: January 29, 2021
Assignment: Project 1
Description:  Program generates the number of prime numbers requested by the user,
			  arranges them in the number of columns requested by the user and 
			  prints them to an output file inputted in the command line. This 
			  program uses 6k+-1 optimization to decide whether or not a number 
			  is prime.
Notes: I used the following Wikipedia page for the primality check algorithm:
	   https://en.wikipedia.org/wiki/Primality_test 
*/

#include <iostream>
#include <fstream>
using namespace std;

//initialize functions for later use
bool isPrime(int);
void formatPrimes(int, int, char*);

int main(int argc, char* argv[])
{	
	if (argc != 2) //check for incorrect number of inputs
	{
		cout << "ERROR: Incorrect number of inputs" << endl;
		return 1;
	}

	int numPrimes, numCols; //initialize variables for user input

	//collect and store user input for number of primes and columns
	cout << "Enter number of primes: ";
	cin >> numPrimes;
   
	cout << "Enter number of columns: ";
	cin >> numCols;

	formatPrimes(numPrimes, numCols, argv[1]); //format primes and print to output file
	
	return 0;
	
}

bool isPrime(int num)
{
	/*
	Description: Determines whether input integer is prime
	Input: integer whose primality is to be judged
	Returns: true if num is prime, false otherwise
	*/
	
	int i = 5;
	
	if (num <= 3) //returns 2 and 3 as primes
		return true;
		
	else if (num % 2 == 0 | num % 3 == 0) //excludes any number factorable by 2 or 3
		return false;
	
	while (i * 2 <= num)
	{
		if (num % i == 0 | num % (i + 2) == 0) //excludes any other factorable number
			return false;
			
		i += 6;
	}
	return true; //returns any other prime number
}

void formatPrimes(int nPrimes, int nCols, char* filename)
{
	/*
	Description: formats a table of prime numbers and arranges them in columns
	Inputs: integer specifying the number of primes to find, integer specifying the
			number of columns in which the numbers shall be arranged, char* specifying filename
	Return: none
	*/

    //initialize counter variable and starting value to be judged
	int count = 0;
	int testNum = 2;

	ofstream fout;  //declare output stream

	fout.open(filename);

	while (count < nPrimes) 
	{
		if (isPrime(testNum)) //check for primality
		{
			//print number and increase counter
			fout << testNum << " ";
			count++;
			
			//add new line if the desired number of columns has been reached
			if (count % nCols == 0)
				fout << endl;
		}
		
		testNum++; //increase value being evaluated
	}	
	
    fout.close();
}
