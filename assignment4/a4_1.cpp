/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 4.1
 *  
 * This program will convert pounds to ounces for as long as the user confirms that he/she
 * wants it to continue to do so. The program will first ask the user to respond yes (Y) or
 * no (N) if he/she wants to make this conversion. If the user responds yes, the program will
 * then prompt the user to enter the number of pounds for conversion.  The program will then
 * do the appropriate calculation and return the results. It will then ask again if the user
 * wants to make this conversion. The program will run until the user inputs something other
 * than the affirmative (Y), at which it will exit.  
 */

#include <iostream>
using namespace std;

const double POUNDSCONVERTER = 16;

int main()
{
	double pounds_val;
	double ounces_val;
	char response;
	
	cout << "Do you want to convert pounds to ounces (Y/N)? ";
	cin >> response;
	
	while (response == 'Y'){
		cout << "enter number of pounds: ";
		cin >> pounds_val;
		ounces_val = pounds_val * POUNDSCONVERTER;
		cout << pounds_val << " pounds is " << ounces_val << " ounces." <<endl;
		cout << "Do you want to convert pounds to ounces (Y/N)? ";
		cin >> response;
	}
}
	