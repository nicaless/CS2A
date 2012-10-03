/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 4.3
 *  
 * This program takes a number of ages of attendees for an event along with the gender of each attendee and then returns how many attendees were in a certain 
 * age group (0-18, 19-30, etc), how many males and females were in attendance, what the average age was, the age of the youngest person, and the age of the
 * oldest person. The program will continue to collect the ages and genders of each attendee until the user inputs a negative number.  As it is collecting 
 * this information, the program will count the number of attendees inputted.  It will input each attendee in the correct gender group, then group the attendee 
 * in the correct age group. It will also compare the age of each attendee with the age of the current youngest and oldest attendees in order to see if it must 
 * change this information.  The program will also add the age of each attendee to the total age of the group in order to later calculate an average age.
 * Upon input of a negative number, the program will then return the information it has collected, calculated, and organized. If the user first inputs a negative 
 * number, the program will output "No attendees" and then exit.  
 */

#include <iostream>
using namespace std;

const int GROUPONEEND = 18;
const int GROUPTWOSTART = 19;
const int GROUPTWOEND = 30;
const int GROUPTHREESTART = 31;
const int GROUPTHREEEND = 40;
const int GROUPFOURSTART = 41;
const int GROUPFOUREND = 60;

int main()
{
	int count;
	int ageTotal;
	int countGroupOne;
	int countGroupTwo;
	int countGroupThree;
	int countGroupFour;
	int countGroupFive;
	int youngest;
	int oldest;
	int age;
	int average;
	int malesCount;
	int femalesCount;
	char gender;
	
	count = 0;
	ageTotal = 0;
	countGroupOne = 0;
	countGroupTwo = 0;
	countGroupThree = 0;
	countGroupFour = 0;
	countGroupFive = 0;
	
	cout << "Enter age of attendee (negative number to quit): ";
	cin >> age;	
	
	youngest = age;
	oldest = age;
	
	while (age >= 0) {
		count++;
		
		cout << "Enter gender (M or F): ";
		cin >> gender;		
		if (gender == 'M') {
			malesCount++;
		}
		if (gender == 'F') {
			femalesCount++;
		}
		ageTotal = ageTotal + age;
		if (age < youngest) {
			youngest = age;
		}
		if (age > oldest) {
			oldest = age;
		}
		if ((age >= 0) && (age <= GROUPONEEND)) {
			countGroupOne = countGroupOne + 1;
		}
		if ((age >= GROUPTWOSTART) && (age <= GROUPTWOEND)) {
			countGroupTwo = countGroupTwo + 1;
		}
		if ((age >= GROUPTHREESTART) && (age <= GROUPTHREEEND)) {
			countGroupThree = countGroupThree + 1;
		}
		if ((age >= GROUPFOURSTART) && (age <= GROUPFOUREND)) {
			countGroupFour = countGroupFour + 1;
		}
		if (age > GROUPFOUREND) {
			countGroupFive = countGroupFive + 1;
		}
		cout << "Enter age of attendee (negative number to quit): ";
		cin >> age;
	}
	if (count == 0) {
		cout << "No attendees" << endl;
	}
	else {

	average = ageTotal / count;
	cout << "age 0  to 18: " << countGroupOne << endl;
	cout << "age 19 to 30: " << countGroupTwo << endl;
	cout << "age 31 to 40: " << countGroupThree << endl;
	cout << "age 41 to 60: " << countGroupFour << endl;
	cout << "over 60: " << countGroupFive << endl;
	cout << "" << endl;
	cout << "males: " << malesCount << endl;
	cout << "females: " << femalesCount << endl;
	cout << "The average age was " << average << "." << endl;
	cout << "The youngest person in attendance was " << youngest << "." << endl;
	cout << "The oldest person in attendance was " << oldest << "." << endl;
	}
}

