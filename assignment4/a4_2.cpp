/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 4.2
 *  
 * This program will convert pounds to ounces for as long as the user continues to input 
 * positive numbers. The program will first ask the user to enter the number of pounds to
 * make this conversion. It will also inform the user that they may quit the program by
 * entering a negative number. If the user enters a positive number, the program will then
 * do the appropriate calculation and return the results. It will then ask again if the user
 * wants to make this conversion. The program will run until the user inputs something other
 * than a positive number, at which it will exit.  
 *  
 */

#include <iostream>
using namespace std;

const double POUNDSCONVERTER = 16;

int main()
{
	double pounds_val;
	double ounces_val;
	
	cout << "enter number of pounds (negative number to quit): ";
	cin >> pounds_val;
	while (pounds_val >= 0){
		ounces_val = pounds_val * POUNDSCONVERTER;
		cout << pounds_val << " pounds is " << ounces_val << " ounces." <<endl;
		cout << "enter number of pounds (negative number to quit): ";
		cin >> pounds_val;
	}
}


