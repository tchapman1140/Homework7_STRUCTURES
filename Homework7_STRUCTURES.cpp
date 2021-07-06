// Homework7_STRUCTURES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
//constant varibles
const string FILENAME = "BowlingScores.txt";
const int COL = 5;	//4 collumns of scores in txt file
const int NUM_OF_BOWLERS = 10; //rows, 10 bowlers in .txt file

//5 scores for github................

///////////////////////////////////////////////////////////////////////////////
//Defining structure
///////////////////////////////////////////////////////////////////////////////
struct Bowling
{
	string names;
	int scores[COL]; //col=5, one-dimensional array of integers to store the bowler's 4 scores.
	int average;
};
//Declaring object
Bowling bowlers[10];


///////////////////////////////////////////////////////////////////////////////
//read and store data into an array of structures.
//The function should take as input parameters the file name and an empty array of structures
////////////////////////////////////////////////////////////////////////////////
bool GetBowlingData(string FILENAME, Bowling bowlers[]) {	//returns true or false
	//opening file
	ifstream infile;
	infile.open(FILENAME);

	if (!infile)//if file does not open
	{
		cout << "Error with file name.." << endl;
		return false;
	}

	for (int i = 0; i < NUM_OF_BOWLERS; i++)	//first loop assigned names to a single array, 1st collum
	{	//i must be set to 0 because it can illiterate up to 9 (10 total loopings)
		infile >> bowlers[i].names;	//using dot to access data within structure

		for (int j = 0; j < COL; j++)	//second loop assignes scores, col2-5. COL=4
		{
			infile >> bowlers[i].scores[j];	//parallel array
		}
	}
	return true;
	//closing file.. no longer need data from file. they are stored in arrays
	infile.close();
}

///////////////////////////////////////////////////////////////////////////////
//calculate the average bowling score. 
//The function should take as input the array of structures which it should fill with the average score of each bowler.
///////////////////////////////////////////////////////////////////////////////
void GetAverageScore(Bowling bowlers[]) {
	//start of for loop
	for (int i = 0; i < NUM_OF_BOWLERS; i++)	//loops 10 times, for 10 average scores
	{
		bowlers[i].average = 0; //initally empty array
		for (int j = 0; j < COL; j++)	//loops 4 times per person
		{
			bowlers[i].average += bowlers[i].scores[j]; //adding up the 4 score collumns... this will repeat 10 times
		}
		bowlers[i].average = bowlers[i].average / COL;	//setting average scores into their own array. must divide by 4
	}
}

///////////////////////////////////////////////////////////////////////////////
//to output the results, i.e.bowler name, scoresand average.
///////////////////////////////////////////////////////////////////////////////

void PrettyPrintResults(Bowling bowlers[]) {
	//Heading for collums
	// '\t' is tab.......
	cout << left << setw(10) << setfill(' ') << "Bowlers:" << "\tGame 1\tGame 2\tGame 3\tGame 4\tGame 5\tAverage " << endl << endl;
	//ouput data from file, which is stored in arrays
	for (int i = 0; i < NUM_OF_BOWLERS; i++)
	{
		cout << setw(10) << left << bowlers[i].names << "\t"; //printing out names (TAB)
		for (int j = 0; j < COL; j++) {	//printing out 4 scores per name
			cout << bowlers[i].scores[j] << "\t"; //spaced out by 1 tab
		}
		//printing out the last collum(which is average)
		cout << setw(5)  << bowlers[i].average << endl;	//goes to next line till all 10 bowlers are ouputed
	}

}

int main() {

	//Header
	cout << setw(80) << setfill('*') << "" << endl;
	cout << setw(40) << setfill('*') << right << "Using Stuctures!" << left << setw(40) << setfill('*') << "" << endl;	//centering my text within 80 collumns
	cout << setw(80) << setfill('*') << "" << endl;
	//calling functions
	if (GetBowlingData(FILENAME, bowlers))	//if this is true(BOOL)
	{
		GetAverageScore(bowlers);
		PrettyPrintResults(bowlers);

	}
	else
	{
		cout << "FILE ERROR......" << endl;
	}
}

