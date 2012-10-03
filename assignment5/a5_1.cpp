/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 5.1
 *  
 * This program will take any number of numbers entered and return where the positions of the first and last 7 entered.
 * The program will first as the user the total number of numbers to be entered. The user will then continue to be
 * prompted to enter numbers until the program finds it has all the numbers it was told it would be given.  As the
 * user is entering the numbers, the program will be keeping track of the positions of the first and last 7s entered.
 * After all the numbers have been entered, the program will then return the positions of the first and last 7s. If no
 * 7s were entered at all, the program will state this.  Afterwards, the program will exit. 
 *
 */

#include <iostream>
using namespace std;

const int SEVENCHECKER = 7;

int main()
{
	int count;
	int totalNum;
	int num;
	int firstSeven;
	int lastSeven;
	
	firstSeven = 0;
	
	cout << "How many numbers will be entered? ";
	cin >> totalNum;

	for (count = 1; count <= totalNum; count++) {
		cout << "Enter num: ";
		cin >> num;
		if (num == SEVENCHECKER) {
			if (firstSeven == 0) {
				firstSeven = count;
			}
			lastSeven = count;
		}
	}
	if (firstSeven == 0) {
		cout << "Sorry, no sevens were entered" << endl;
	} 
	else {
		cout << "The first 7 was in position " << firstSeven << endl;
		cout << "The last 7 was in position " << lastSeven << endl;
}
}
		