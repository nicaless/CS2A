/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 2.1 *
 *
 * This program states the degrees Fahrenheit given a value for degrees
 * Celsius. At the start of the program, the user will be prompted to input
 * a value for degrees Celsius. The program will then calculate the degrees
 * Fahrenheit by multiplying '9/5' to the given degrees Celsius and then adding
 * '32' to the result. The program will then return the old value for degrees 
 * Celsius with its equivalent degrees Fahrenheit. This program will not work 
 * properly if any other value besides an integer is inputted.
 *
 */

#include <iostream>
using namespace std;

int main()
{
	double Fdegrees;
	double Cdegrees;
	
	cout << "enter degrees Celsius: ";
	cin >> Cdegrees;
	Fdegrees = ((9.0 / 5.0) * Cdegrees) + 32;
	
	cout << Cdegrees << " degrees Celsius is " << Fdegrees << " degrees Fahrenheit." << endl;

}
	
	

