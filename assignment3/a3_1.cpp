/*
 Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 3.1
 *  
 * This program will calculate the area of a 2D figure given the necessary inputs 
 * a user. First, the user will be prompted to give the type of figure (square or 
 * triangle).  If the user enters 's' for square, the program will then ask for 
 * the length of a side.  If the user enters 't' for triangle, the program will
 * ask for the length of the base and then the length of the height. The program
 * will then do the appropriate calculations to find the area of the square or 
 * triangle.
 *
 */

#include <iostream>
using namespace std;

const double triangleFactor = .5;

int main()
{
	char figureType;
	double area;
	
	cout << "Enter the type of figure (s or t): ";
	cin >> figureType;
	
	if (figureType == 's') {
		double side;
		cout << "Enter the length of a side: ";
		cin >> side;
		area = side * side;
	}
	if (figureType == 't') {
		double base;
		double height;
		cout << "Enter the base: ";
		cin >> base;
		cout << "Enter the height: ";
		cin >> height;
		area = triangleFactor * base * height;
	}
	cout << "The area is " << area << endl;
}
	

