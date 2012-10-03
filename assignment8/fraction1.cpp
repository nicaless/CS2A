/*
 * Nicole Fronda
 * CIS 15A
 * Assignment 8
 *
 * fraction.cpp
 * 
 * Private Data Members:
 *
 * numer : an int member variable that represents the numerator 
 * denom : an int member variable that represents the denominator
 * Reduce() : a member function that reduces a fraction to its lowest terms, called everytime a fraction is initialized.
 * 
 * Fraction objects will always be stored in its lowest terms.  A new fraction object will be initialized everytime two fractions are added, subtracted, multiplied, or divided, to find a resulting fraction.
 *
 */ 

#include <iostream>
#include "fraction.h"
using namespace std;


fraction::fraction()
{
	numer = 0;
	denom = 1;
}

fraction::fraction(int inNumer, int inDenom)
{
	numer = inNumer;
	denom = inDenom;
	Reduce();
}

// Called everytime a new fraction is initialized.  First it determines the greatest common denominator (gcd) of the numerator and denominator of the function, then divides each the numer and denom by the gcd,
// storing fraction in its lowest terms.
void fraction::Reduce()
{
	int remainder;
	int firstNum;
	int secNum;
	int gcd;
	
	if ((numer > denom) || (numer == 0)) {
		firstNum = numer;
		secNum = denom;
	} else {
		firstNum = denom;
		secNum = numer;	}
	remainder = firstNum % secNum;
	while (remainder > 0) { 
		firstNum = secNum; 
		secNum = remainder; 
		remainder = firstNum % secNum; 
	}
	gcd = secNum;
	numer = numer / gcd;
	denom = denom / gcd;
}
	

fraction fraction::MultipliedBy(const fraction otherFraction) const
{
	int newNumer;
	int newDenom;
	newNumer = numer * otherFraction.numer;
	newDenom = denom * otherFraction.denom;
	fraction newFraction(newNumer, newDenom);
	return newFraction;
}

fraction fraction::AddedTo(const fraction otherFraction) const
{
	int newNumer;
	int newDenom;
	newDenom = denom * otherFraction.denom;
	newNumer = (numer * otherFraction.denom) + (denom * otherFraction.numer);
	fraction newFraction(newNumer, newDenom);
	return newFraction;
}

fraction fraction::Subtract(const fraction otherFraction) const
{
	int newNumer;
	int newDenom;
	newDenom = denom * otherFraction.denom;
	newNumer = (numer * otherFraction.denom) - (denom * otherFraction.numer);
	fraction newFraction(newNumer, newDenom);
	return newFraction;
}

fraction fraction::DividedBy(const fraction otherFraction) const
{
	int newNumer;
	int newDenom;
	newNumer = numer * otherFraction.denom;
	newDenom = denom * otherFraction.numer;
	fraction newFraction(newNumer, newDenom);
	return newFraction;
}

bool fraction::isEqualTo(const fraction otherFraction) const
{	
	return ((numer == otherFraction.numer) && (denom == otherFraction.denom));
} 

void fraction::print() const
{
	cout << numer << "/" << denom;
}