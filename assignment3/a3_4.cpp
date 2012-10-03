/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 3.4
 *  
 * This program calculates gross cost and net cost of a call given a
 * start time and a call length. The user will be prompted for both 
 * the start time and call length.  The program will then take those
 * values and use given criteria to calculate the gross cost of the call,
 * whether to apply any discounts, and the federal tax on the call. The 
 * program will then return the gross cost and net cost of the call.
 *
 */

#include <iostream>
#include <iomanip>
using namespace std;

const double callFactor = .40;
const double startNightDiscount = 1800;
const double endNightDiscount = 800;
const double nightDiscount = .5;
const double minLongCall = 60;
const double longCallDiscount = .15;
const double fedTax = 1.04;

int main()
{
	double startTime;
	double callLength;
	double grossCost;
	double netCost;
	
	cout << "Enter start time: ";
	cin >> startTime;
	cout << "Enter length of call in minutes: ";
	cin >> callLength;
	
	grossCost = callFactor * callLength;
	cout << setprecision(2) << fixed << "gross cost: $" << grossCost << endl;
	
	if ((startTime >= startNightDiscount) || (startTime <= endNightDiscount))  {
		grossCost = grossCost * nightDiscount;		
	}
	if (callLength > minLongCall) {
		double totalDiscount;
		totalDiscount = grossCost * longCallDiscount;
		grossCost = grossCost - totalDiscount;
	}
	netCost = grossCost * fedTax;
	cout << setprecision(2) << fixed << "net cost: $" << netCost << endl;
}


