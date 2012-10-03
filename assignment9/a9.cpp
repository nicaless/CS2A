/*
 *  Nicole Fronda  
 *	CIS 15A
 *  Assignment 9
 *
 * This program prompts the user to enter a string of characters. The program reads the string until the user enters a period. The program does not read any characters after the user enters the first period.
 * The program will count any alphabet letters inputted before the period, storing the count of each letter in an array. Once the user is done entering characters (the user presses <enter>), the program will
 * sort the array in descending order. It will then print the letters that were inputted along with the number of times each was inputted. The program will not print any letters the user did not input, and it 
 * will not print any other characters besides alphabet letters.
 */


#include <iostream>
#include <iomanip>
using namespace std;


// Defines the struct for the array. Each array will have a 'letter' and a number that counts the 'frequency' of that letter in the user's input.
struct ArrayStruct
{
	int frequency;
	char letter;
};

	


const int NUM_LETTERS = 25; // The size of the array will be 26. Each element of the array will represent a letter of the alphabet.

void createArray(ArrayStruct charCount[]);
void readInput(ArrayStruct charCount[]); 
void sortArray(ArrayStruct charCount[]); 
int indexOfLargest(const ArrayStruct charCount[], int startingIndex); 
void printArrayExcept(ArrayStruct charCount[], int numToSkip); 





int main()
{
	ArrayStruct charCount[NUM_LETTERS];
	createArray(charCount);
	readInput(charCount);
	sortArray(charCount);
	printArrayExcept(charCount, 0);
}
















// Fills the initially empty array 'charCount'. Puts a different letter and its starting frequency count 0 in its own array element. Element 0 of the array will be for letter 'a', element 1 will be for letter 'b', and so on. 
void createArray(ArrayStruct charCount[])
{
	for (int count = 0; count < NUM_LETTERS; count++) {
		charCount[count].letter = (char)(count + 'a');
		charCount[count].frequency = 0; 
	}
}



















// Reads the user input. As long as the inputted character is not a period, this function will check to see if the character is an alphebet letter, put it in its lower case form, and the increase the
// frequency count of the array element in the array 'charCount' with that letter.
void readInput(ArrayStruct charCount[])
{
	cout << "Enter a sequence of characters (end with '.'): " ;
	char ch;
	while (ch != '.') {
		cin.get(ch);
		if (isalpha(ch)) {
			ch = tolower(ch);
			charCount[ch - 'a'].frequency++;
		}
	}
}

















// Sorts the array 'charCount' in descending order of frequency of each letter. This function is based on the code for the selection sort function in Lesson 10.6.   
void sortArray(ArrayStruct charCount[])
{
	for (int count = 0; count < NUM_LETTERS; count++){
		swap(charCount[indexOfLargest(charCount, count)], 
			 charCount[count]);
	}	
}


















// Finds the element in the array 'charCount', starting at the 'startingIndex', that has the largest frequency count for its letter and returns the index of that element. 
// This function is based on the code for the indexOfSmallest function in Lesson 10.6.
int indexOfLargest(const ArrayStruct charCount[], int startingIndex)
{
	int targetIndex = startingIndex;
    
	for (int count = startingIndex + 1; count < NUM_LETTERS; count++){
		if (charCount[count].frequency > charCount[targetIndex].frequency){
			targetIndex = count;
		}
	}
	return targetIndex;
}

















// Prints the elements in the array 'charCount'. Prints the letters that were inputted along with each one's frequency, as long as the frequency count of that letter does not equal the 'numToSkip'. 
void printArrayExcept(ArrayStruct charCount[], int numToSkip)
{
	cout << endl;
	cout << "Letter:" << "    " << "Number of Occurrences" << endl;
	for (int count = 0; count < NUM_LETTERS; count++) {
		if (charCount[count].frequency != numToSkip) {
			cout << setw(6) << charCount[count].letter << "     " << charCount[count].frequency << endl;
		}
	}
}

