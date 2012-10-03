/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 2.1
 *  
 *  This program states how to make change in pennies, nickels, dimes,
 *  and quarters given a number of cents inputted by the user.
 *  At the start of the program, the user is prompted for a value of cents.
 *  The user inputted value is then saved. If an appropriate
 *  value is entered the program proceeds to calculate how many quarters
 *  are needed and the remaining value of cents. The program then uses the
 *  remaining value of dimes, nickels and pennies in the same manner. 
 *  After the calculations, the program returns the the number of each coin
 *  required and exits. This program will not work correctly if any other value
 *  besides positive integers are inputted.
 */

#include <iostream>
using namespace std;

int main()
{
	int cents;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
	
	cout << "enter number of cents: ";
	
	cin >> cents;
	
	quarters = cents / 25;
	cents = cents % 25;
	dimes = cents / 10;
	cents = cents % 10;
	nickels = cents / 5;
	cents = cents % 5;
	pennies = cents;
	
	cout << "pennies: " << pennies << endl;
	cout << "nickels: " << nickels << endl;
	cout << "dimes: " << dimes << endl;
	cout << "quarters: " << quarters << endl;
}



