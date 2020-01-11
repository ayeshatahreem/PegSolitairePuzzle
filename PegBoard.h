#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

class PegBoard
{
protected:
	int k, version;
	int board[7][7];
	stack <int> backtrack;
public:
	void getInputFromFile();
	bool ifSolvable();
	void printBoard();
	bool isGoal();
	bool ifConsecutivePegsOnBoard();
	void searchForGoal();
	bool checkBoardState(int, int, int);
	void applyAction(int, int, int);
	int totalRemPegs();
	bool applyheuristic(int, int, int);
	void upAction(int, int);
	void downAction(int, int);
	void rightAction(int, int);
	void leftAction(int, int);
};