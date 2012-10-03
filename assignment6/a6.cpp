/*
 *  Nicole Fronda  
 *	CIS 15A
 *  6/11/2012
 *  Dave Harden
 *  Assignment 6.1 
 *
 * This program draws a rocket given the user inputted dimensions. The user will be prompted
 * to enter the height and width of each 'stage' of the rocket, and how many stages the rocket
 * should have. The program will pass on this information to helper functions that will draw 
 * the rocket. The program will first use the width given to draw an appropriate top cone for the
 * top of the rocket. This requires the calling of several other functions in order for the cone 
 * to be perfectly alligned with the rest of the rocket. After the cone, the program will then 
 * use width, height, and the number of stages given to draw the middle part of the rocket. This
 * process also requires a few helper functions in order draw each edge of the stage for the 
 * given number of stages.  After the stages, the program will then draw the bottom cone of the rocket.  
 * 
 */

#include <iostream>
using namespace std;

void drawSpace(int numSpaces);
void drawOddConeTip(int width_val);
void drawEvenConeTip(int width_val);
void drawOddConeMiddle(int width_val);
void drawEvenConeMiddle(int width_val);
void drawConeBottom(int width_val);
void drawConeEven(int width_val);
void drawConeOdd(int width_val);
void drawCone(int width_val);
void drawBox(int height_val, int width_val);
void drawBoxEdge(int width_val);
void drawBoxSides(int height_val, int width_val);
void getDimensions(int &height_val, int &width_val, int &stage_val);
void drawRocket(int height_val, int width_val, int stage_val);
void drawStages(int height_val, int width_val, int stage_val);

// Main function. First calls the getDimenstions function to get the dimensions that
// will be passed on to later called functions, then calls the drawRocket function to take 
// draw the rocket with the user inputted dimensions.
int main()
{
	int height_val;
	int width_val;
	int stage_val;
	
	getDimensions(height_val, width_val, stage_val);
	drawRocket(height_val, width_val, stage_val	);
	
}

// Gets the dimenstions of the rocket in order to pass on the dimensions to other functions.
void getDimensions(int &height_val, int &width_val, int &stage_val)
{
	cout << "Height of stage: ";
	cin >> height_val;
	cout << "Width of stage: ";
	cin >> width_val;
	cout << "Number of stages: ";
	cin	>> stage_val;
}


// Draws the rocket with the given dimensions.  Calls the drawCone and
// drawStages functions in order to draw each section of the rocket.
void drawRocket(int height_val, int width_val, int stage_val)
{
	drawCone(width_val);
	drawStages(height_val, width_val, stage_val);
	drawCone(width_val);
}



// Here are the functions needed to draw the cones for the rocket.



// This is the main function to draw the cone. It takes in the width of the cone,
// which is the same width as the whole rocket, and then decides whether to call
// an even-width cone or an odd-width cone needs to be drawn, and then calls the
// appropriate function.

void drawCone(int width_val)
{
	if (0 == (width_val % 2)) {
		drawConeEven(width_val);
	}
	else {
		drawConeOdd(width_val);
	}
}


// These functions draw the odd-width and even-width cone. It calls the functions
// to draw the tip of the cone, the middle section of the cone, and then the
// bottom of the cone.

void drawConeOdd(int width_val)
{	
	
	drawOddConeTip(width_val);
	drawOddConeMiddle(width_val);
	drawConeBottom(width_val);
}


void drawConeEven(int width_val)
{
	drawEvenConeTip(width_val);
	drawEvenConeMiddle(width_val);
	drawConeBottom(width_val); 
}


// These functions draw the tip of the cone. Calculates how much
// blank space needs to be on the left and right, then calls
// the drawSpace function, outputs a '*' or '**' - depending on
// if the cone has even or odd width - for the tip of 
// the cone, then calls the drawSpace function again.  

void drawOddConeTip(int width_val)
{
	int numSpaceLeft;
	int numSpaceRight;
	
	numSpaceLeft = numSpaceRight = (width_val-1)/2;
	
	drawSpace(numSpaceLeft);
	cout << "*";
	drawSpace(numSpaceRight);
	cout << endl;
}


void drawEvenConeTip(int width_val)
{
	int numSpaceLeft;
	int numSpaceRight;
	
	numSpaceLeft = numSpaceRight = (width_val-2)/2;
	
	drawSpace(numSpaceLeft);
	cout << "**";
	drawSpace(numSpaceRight);
	cout << endl;
}	

// These functions draws the middle section of the odd-width
// or even-width cone. For each row, it calculates the black space needed
// on the left, the middle, and the right, then calls
// the drawSpace function between '*' in order to draw each row of the
// this section of the cone correctly.

void drawOddConeMiddle(int width_val)
{
	int count;
	int rows;
	int numSpaceLeft;
	int numSpaceMid;
	int numSpaceRight;
	
	rows = ((width_val+1)/2)-2;
	for (count = 0; count < rows; count++) {
		
		numSpaceLeft = numSpaceRight = rows-count;
		numSpaceMid = (count*2)+1;
		
		drawSpace(numSpaceLeft);
		cout << "*";
		drawSpace(numSpaceMid);
		cout << "*";
		drawSpace(numSpaceRight);	
		cout << endl;
	}
	
}


void drawEvenConeMiddle(int width_val)
{
	int count;
	int rows;
	int numSpaceLeft;
	int numSpaceMid;
	int numSpaceRight;
	
	rows = (width_val/2)-2;
	for (count = 0; count < rows; count++) {
		
		numSpaceLeft = numSpaceRight = rows-count;
		numSpaceMid = (count+1)*2;
		
		drawSpace(numSpaceLeft);
		cout << "*";
		drawSpace(numSpaceMid);
		cout << "*";
		drawSpace(numSpaceRight);	
		cout << endl;
	}
}


// Draws the bottom of the cone by calling the drawSpace function between two '*'.

void drawConeBottom(int width_val)
{	
	int numSpaceMid;
	numSpaceMid = width_val-2;
	cout << "*";
	drawSpace(numSpaceMid);
	cout << "*";
	cout << endl;
}


// Here are the functions needed to draw the stages (the middle boxes)
// of the rocket.


// This is the main function to draw the stages. Takes in the number
// of stages needed and calls the drawBox function for that many
// times passing on the information for the height and width of each
// box.

void drawStages(int height_val, int width_val, int stage_val)
{
	int countStage;
	for (countStage = 0; countStage < stage_val; countStage++) {
		drawBox(height_val, width_val);
	}
}	
	

// Draws an individual box of the rocket.  Calls the drawBoxEdge,
// and the drawBoxSides functions in order to draw the top and bottom
// edges of the box and the left and right sides of the box.

void drawBox(int height_val, int width_val)
{
	drawBoxEdge(width_val);
	drawBoxSides(height_val, width_val);
	drawBoxEdge(width_val);
}


// Draws an edge (top or bottom) of the box by outputting a '*' for each
// unit width of the box.

void drawBoxEdge(int width_val)
{
	int count;
	for (count = 0; count < width_val; count++) {
		cout << "*";
	}
	cout << endl;
}


// Draws the left and right sides of box. For each middle row needed,
// it calls the drawSpace function to draw the black space between
// the sides of the box.  

void drawBoxSides(int height_val, int width_val)
{
	int countRow;
	
	for (countRow = 0; countRow < height_val-2; countRow++) {
		cout << "*";
		drawSpace(width_val-2);
		cout << "*";
		cout << endl;
	}
}	


// This the auxiliary function needed to draw the blank space to the
// left or the right of a '*', or between two '*'.

void drawSpace(int numSpaces)
{
	int count;
	for (count = 0; count < numSpaces; count++) {
		cout << " ";
	}
}
