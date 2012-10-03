/*
 *  a6.cpp
 *  assignment6
 *
 *  Created by Nicole Fronda on 6/21/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
using namespace std;

void drawCone();
void drawBox(int height_val, int width_val);
void getDimensions(int &height_val, int &width_val, int &stage_val);
void drawRocket(int height_val, int width_val, int stage_val);

int main()
{
	int height_val;
	int width_val;
	int stage_val;
	
	getDimensions(height_val, width_val, stage_val);
	drawRocket(height_val, width_val, stage_val	);
	
}

void getDimensions(int &height_val, int &width_val, int &stage_val)
{
	cout << "Height of stage: ";
	cin >> height_val;
	cout << "Width of stage: ";
	cin >> width_val;
	cout << "Number of stages: ";
	cin	>> stage_val;
}

void drawRocket(int height_val, int width_val, int stage_val)
{
	int countStage;
	drawCone();
	for (countStage = 0; countStage < stage_val; countStage++) {
		drawBox(height_val, width_val);
	}
	drawCone();
}

void drawCone()
{
	cout << "  *  " << endl;
	cout << " * * " << endl;
	cout << "*   *" << endl;
}

void drawBox(int height_val, int width_val)
{
	int countRow;
	int countSpace;
	
	for (countSpace = 0; countSpace < width_val; countSpace++) {
		cout << "*";
	}
	cout << endl;
	for (countRow = 0; countRow < height_val-2; countRow++) {
		cout << "*";
		for (countSpace = 0; countSpace < width_val-2; countSpace++) {
			cout << " ";
		}
		cout << "*" << endl;
	}
	for (countSpace = 0; countSpace < width_val; countSpace++) {
		cout << "*";
	}
	cout << endl;
}


