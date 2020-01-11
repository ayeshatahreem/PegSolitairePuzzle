#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <stack>
#include "PegBoard.h"

using namespace std;
using s = chrono::seconds;
using ns = chrono::nanoseconds;
using get_time = chrono::steady_clock;

void main()
{

	system("Color 8F");
	// to measure the overall runtime of the program
	auto start = get_time::now(); //use auto keyword to minimize typing strokes :)
	cout << '\t' << '\t' << '\t' << '\t' << "Agent star reporting on duty" << endl;

	PegBoard *obj = new PegBoard();
	obj->getInputFromFile();
	cout << '\n'<<"INITIAL CONFIGURATION" << '\n' << '\n';
	obj->printBoard();
	bool solvable = obj->ifSolvable();	
	if (solvable) 
	{
		cout << "Pls wait, I'm searching very hard for the solution :') " << endl;
		obj->searchForGoal();
	}
	
	auto end = get_time::now();
	auto diff = end - start;

	cout << "I took " << chrono::duration_cast<ns>(diff).count() << " ns or simply "
		<< chrono::duration_cast<s>(diff).count() << " sec to solve it. Acknowledge my efficiency!" << endl;
	system("PAUSE");
}