/*
 * Nicole Fronda
 * CIS 15A
 * Assignment 8
 *
 * fraction.h
 *
 * This is the header file for a FRACTION CLASS that can create fractions given a user inputted numerator and denominator.  It can add, subtract, multiply, divide, and compare fractions them to other fractions.  
 * The PUBLIC member functions of the FRACTION CLASS:
 * fraction() : Pre-condition: none 
 *			  : Post-condition: a fraction object of numerator 0 and denominator 1 will be initialized
 * fraction(int inNumer, int inDenom) : Pre-condition: inNumer and inDenom must be positive numbers and inDenom must not be 0
 *									  : Post-condition: a fraction object of numerator inNumer and denominator inDenom will be initialized and then stored in reduced form
 * MultipliedBy(const fraction otherFraction) const : Pre-condition: none
 *													: Post-condition: multiplies the calling fraction by the parameter fraction to initialize a new fraction
 * AddedTo(const fraction otherFraction) const : Pre-condition: none
 *											   : Post-condition: adds the calling fraction by the parameter fraction to initialize a new fraction
 * Subtract(const fraction otherFraction) const : Pre-condition: none
 *												: Post-condition: subtracts the calling fraction by the parameter fraction to initialize a new fraction
 * DividedBy(const fraction otherFraction) const : Pre-condition: none
 *												: Post-condition: divides the calling fraction by the parameter fraction to create a new fraction
 * isEqualTo(const fraction otherFraction) const : Pre-condition: none
 *												 : Post-condition: returns a 'true' or 'false' after comparing two fractions to see if they are equal
 * print() const : Pre-condition: none
 *				 : Post-condition: the calling fraction will be printed in the form of 'numerator/denominator'.  Improper fractions are not converted to mixed numbers
 */
#ifndef FRACTION_H
#define FRACTION_H

class fraction {
	public:
		fraction();
		fraction(int inNumer, int inDenom);
		fraction MultipliedBy(const fraction otherFraction) const;
		fraction AddedTo(const fraction otherFraction) const;
		fraction Subtract(const fraction otherFraction) const;
		fraction DividedBy(const fraction otherFraction) const;
		bool isEqualTo(const fraction otherFraction) const;
		void print() const;
	private:
		void Reduce();
		int numer;
		int denom;
};

#endif