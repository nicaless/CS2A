/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 3.2
 *  
 * This program will state the education level of a person given a user
 * input of the number of years in school. User will first be prompted 
 * to enter the number of years of schooling.  The program will then take
 * that number and see which range it fits into in order to return the 
 * appropriate education level. If the number of years is 0 or less, 
 * the program will return 'none'.  If it is greater than 0 but less than
 * 7, the program will return 'elementary'. If it is equal or greater than
 * 7 but less than 9, the program will return 'middle school' and so on.
 *
 */

#include <iostream>
using namespace std;

const int endElem = 6;
const int startMid = 7;
const int endMid = 8;
const int startHS = 9;
const int endHS = 12;

int main()
{
	int years;
	cout << "Enter number of years of schooling: ";
	cin >> years;
	
	if (years <= 0) {
		cout << "none" << endl;
	}
	if ((years >= 1) && (years <= endElem)) {
		cout << "elementary school" << endl;
	}
	if ((years >= startMid) && (years <= endMid)) {
		cout << "middle school" << endl;
	}
	if ((years >= startHS) && (years <= endHS)) {
		cout << "high school" << endl;
	}
	if (years > endHS) {
		cout << "college" << endl;
	}
}


