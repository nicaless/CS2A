/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 3.3
 *  
 * This program works as a simple calculator. The user will first be prompted to
 * enter a number. Then they will be prompted for an operator (+, -, x, /). Then
 * they will be prompted for another number. The program will then do the appropriate
 * operation with the numbers in the order they were entered. It will then return the 
 * answer.
 *
 */

#include <iostream>
using namespace std;

int main()
{
	double firstNum;
	double secondNum;
	double answer;
	char oprtr;
	
	cout << "Enter a number: ";
	cin >> firstNum;
	cout << "Enter an operator (+ , - , x, /): ";
	cin >> oprtr;
	cout << "Enter another number: ";
	cin >> secondNum;
	
	switch (oprtr) {
		case '+':
			answer = firstNum + secondNum;
			break;
		case '-':
			answer = firstNum - secondNum;
			break;
		case 'x':
			answer = firstNum * secondNum;
			break;
		case '/':
			answer = firstNum / secondNum;
			break;			
	}
	cout << firstNum << oprtr << secondNum << " is " << answer << endl;
}

