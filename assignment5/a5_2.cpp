/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 5.2
 *  
 * This program will calculate the sum of the squares from 1 to a given number inputted by the user for as long as the user continues to input 
 * numbers greater than 0. The program will first ask the user to enter a number greater than 0. It will also inform the user that they may quit 
 * the program by entering a number less than 1. If the user enters an appropriate number, the program will then do the calculation and return 
 * the results. It will then ask again if the user wants to make this calculation. The program will run until the user inputs something other
 * than a a number greater than 0, at which it will exit.  
 */

#include <iostream>
using namespace std;

int main()
{
	int num;
	int count;
	int sumSoFar;
	int square;
	
	cout << "Enter a number greater than 0 (less than 1 to quit): ";
	cin	>> num;
	
	do {
		sumSoFar = 0;
		for (count = 1; count <= num; count++) {
			square = count * count;
			sumSoFar = sumSoFar + square;
		}
		cout << "The sum of the given squares from 1 to " << num << " is " << sumSoFar << endl;
		cout << "Enter a number greater than 0 (less than 1 to quit): ";
		cin	>> num;
		
	} while (num >= 1);
}
	