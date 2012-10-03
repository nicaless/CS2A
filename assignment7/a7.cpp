/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 7.1 
 *
 * This program outputs 3 different sets of problems - addition, subtraction, and multiplication for a user to answer. The user chooses how many problems are
 * in each set and the highest number to be calculated in a set.  The program will then output the appropriate problems for each set and have the user anser
 * the problems.  The program will keep track of how many problems the user answers correctly in each set.  Then, once the user has finished answering all
 * of the problems, the program will output a grade report of how well the user did.  
 */


#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void doOneSet(char operand,double probsPerSet, double &numCorrect);
void generateOperands(char oprtr, int maxNum, int &firstNum, int &secNum, int &usrAns);
double doOneProblem(char oprtr, int maxNum);
void calculateCorrectAnswer(int firstNum, int SecNum, char oprtr,  int &correctAns);
void checkAnswer(int usrAns, int correctAns, bool &score);
void getProbsPerSet(double &probsPerSet);
void getMaxNum(int &maxNum);
void printHeader(char oprtr);
void printReport(double numCorrect1, double numCorrect2, double numCorrect3, double probsPerSet);




// The main function of the program. First calls the getProbsPerSet function to get the number of problems for each set.
// Then it calls the doOneSet function three times for three different kinds of problem sets. Then it calls the printReport
// function to print the user's grade for each problem set and an overall grade for all three sets.

int main()
{
	double probsPerSet;
	double numCorrect1;
	double numCorrect2;
	double numCorrect3;
	
	srand(time(0));
	getProbsPerSet(probsPerSet);
	doOneSet('+', probsPerSet, numCorrect1);
	doOneSet('-', probsPerSet, numCorrect2);
	doOneSet('*', probsPerSet, numCorrect3);
	printReport(numCorrect1, numCorrect2, numCorrect3, probsPerSet);
}


// Prompts the user to enter the number of problems per set and passes the information to other functions in the main function that require it.

void getProbsPerSet(double &probsPerSet)
{
	cout << "Enter problems per set: ";
	cin >> probsPerSet;
	cout << endl;
}



// Takes in a specific operator, the number of problems for the set using that operator, and then keeps track of the number correct answers in the set.
// First calls the printHeader function for the header of the set. Then calls the getMaxNum function to get the max number for the set. Then
// calls the doOneProblem to output a problem for the amount of problems inputted. The doOneProblem function returns a 1 for a correct answer and a 0
// for an incorrect answer and this function adds the numbers up to determine the number of correct answers in the set to pass on to the main function.

void doOneSet(char oprtr, double probsPerSet, double &numCorrect) 
{
	int count;
	int maxNum;
	
	printHeader(oprtr);
	getMaxNum(maxNum);
	
	numCorrect = 0;
	for (count = 0; count < probsPerSet; count++) {
		numCorrect = numCorrect + doOneProblem(oprtr, maxNum);
	}
}



// Prints the header of a specific set depending on the operator to be used in the problems of that set.

void printHeader(char oprtr)
{
	switch (oprtr) {
		case '+':
			cout << "Set #1" << endl;
			break;
		case '-':
			cout << "Set #2" << endl;
			break;
		case '*':
			cout << "Set # 3" << endl;
			break;
	}
	cout << "----------" << endl;
	cout << endl;
}



// Prompts the user to enter the number of problems per set and passes on this information to the other functions in the doOneSet function that require it.

void getMaxNum(int &maxNum)
{
	cout << "What is the maximum number for this set? ";
	cin	>> maxNum;
	cout << endl;
}



// Given an operator and the max number of a set, this function does one problem in a set. First it calls the generateOperands function to generate the first
// and second numbers of the problem, outpur the problem to the user, and the the user's answer. Then in calls the calculateCorrecAnswer function to calculate 
// the correct answer to the generated problem. Lastly, it calls the checkAnswer function to check the user's answer with the correct answer. The checkAnswer
// function will pass boolean variable called score which will have a true or false value for a correct or incorrect answer. This function will then return a 
// 1 or 0 - depending on the value of the score variable - to the doOneSet function to keep track of the number of  correct answers by the user.

double doOneProblem(char oprtr, int maxNum)
{
	int firstNum;
	int secNum;
	int correctAns;
	int usrAns;
	bool score;
	
	generateOperands(oprtr, maxNum, firstNum, secNum, usrAns);
	calculateCorrectAnswer(firstNum, secNum, oprtr, correctAns);
	checkAnswer(usrAns, correctAns, score);
	if (score) {
		return 1;
	}
	else {
		return 0;
	}

}	



// This function randomly generates the first and second number of a problem, outputs the problem for the user to answer, then passes this information
// on to the other functions in the doOneProblem function that require it. 
void generateOperands(char oprtr, int maxNum, int &firstNum, int &secNum, int &usrAns)
{
	firstNum = rand() % (maxNum+1);
	secNum = rand() % (maxNum+1);
	cout << firstNum;
	cout << " " << oprtr << " ";
	cout << secNum;
	cout << " = ";
	cin	>> usrAns;
}



// Given the first and second number and the operator of a problem, this function calculates the correct answer of the problem and passes this
// information to the other functions in the doOneProblem function that require it.
void calculateCorrectAnswer(int firstNum, int secNum, char oprtr, int &correctAns)
{
	switch (oprtr) {
		case '+':
			correctAns = firstNum + secNum;
			break;
		case '-':
			correctAns = firstNum - secNum;
			break;
		case '*':
			correctAns = firstNum * secNum;
			break;
	}
}



// Given the user's answer and the correct answer, this function will check of the user's answer is correct. It will then set the score equal to
// true or false for a correct or incorrect answer and pass the information to the doOneProblem function which will then return it to the 
// doOneSet function to keep track of the number of correct answers by the user.
void checkAnswer(int usrAns, int correctAns, bool &score)
{
	if (usrAns == correctAns) {
		cout << "correct" << endl;
		score = true;
	}
	else {
		cout << "incorrect" << endl;
		score = false;
	}
}



// Takes the number of correct answers from each set and the number of problems per set and calculates the user's grade for each set along with an
// overall grade.  It then outputs the grade report for the user to see.
void printReport(double numCorrect1, double numCorrect2, double numCorrect3, double probsPerSet)
{
	double gradeSet1;
	double gradeSet2;
	double gradeSet3;
	double totalCorrect;
	double totalProbs;
	double gradeOverall;
	
	gradeSet1 = numCorrect1 / probsPerSet * 100;
	gradeSet2 = numCorrect2 / probsPerSet * 100;
	gradeSet3 = numCorrect3 / probsPerSet * 100;
	totalCorrect = numCorrect1 + numCorrect2 + numCorrect3;
	totalProbs = probsPerSet * 3;
	gradeOverall = totalCorrect / totalProbs * 100;
	cout << endl;
	cout << setprecision(0) << fixed << "Set#1: You got " << numCorrect1 << " correct out of " << probsPerSet << " for " << gradeSet1 << "%" << endl;
	cout << setprecision(0) << fixed << "Set#2: You got " << numCorrect2 << " correct out of " << probsPerSet << " for " << gradeSet2 << "%" << endl;
	cout << setprecision(0) << fixed << "Set#3: You got " << numCorrect3 << " correct out of " << probsPerSet << " for " << gradeSet3 << "%" << endl;
	cout << setprecision(0) << fixed << "Overall you got " << totalCorrect << " correct out of " << totalProbs << " for " << gradeOverall << "%" << endl;
}



