#include "PegBoard.h"

void PegBoard::getInputFromFile()
{
	ifstream file;
	file.open("input.txt", ios_base::in);
	if (file.is_open())
	{
		if (!file.eof())
		{
			file >> version >> k;
			if (version == 5)
				cout << '\t' << '\t' << "Solving English version of puzzle for an ultimate " << k << " peg goals" << endl;
			else if (version == 7)
				cout << '\t' << '\t' << "Solving European version of puzzle for an ultimate " << k << " peg goals" << endl;

			for (int a = 0; a < 7; a++)
			{
				for (int b = 0; b < 7; b++)
					file >> board[a][b];
			}
		}
		file.close();
	}
	else
		cout << "Error while opening the file" << endl;
}

bool PegBoard::ifSolvable()
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == 1)
				count++;
		}
	}
	if (k > count)
	{
		cout << "Number of pegs on board are less than required pegs >.<" << endl;
		return false;
	}
	else if (k == count)
	{
		cout << "Number of pegs on board equals the required pegs. I have nothing to do ^.^" << endl;
		return false;
	}
	else
	{
		cout << "Number of pegs on board are more than required pegs -_-" << endl;
		return true;
	}

}

void PegBoard::printBoard()
{
	int printNum;
	for (int a = 0; a < 7; a++)
	{
		for (int b = 0; b < 7; b++)
		{
			printNum = board[a][b];
			if (printNum == 2)
				cout << " ";
			else
				cout << printNum;
		}
		cout << endl;
	}
	cout << endl;
}

bool PegBoard::isGoal()
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == 1)
				count++;
		}
	}
	if (k == count)
		return true;
	else
		return false;
}

bool PegBoard::ifConsecutivePegsOnBoard()
{
	if (version == 5)
	{
		for (int a = 0; a < 7; a++)
		{
			for (int b = 0; b < 7; b++)
			{
				if (a == 0 || a == 1  || (a == 2 && b == 0) || (a == 2 && b == 1) || (a == 2 && b == 5) || (a == 2 && b == 6) || 
				   (a == 3 && b == 0) || (a == 3 && b == 1) || (a == 3 && b == 5) || (a == 3 && b == 6))
				{ 
					if(board[a][b] == 1  && board[a - 1][b] == 1 && board[a - 2][b] == 0) 
						return true; //up
				}
				if (a == 5 || a == 6 || (a == 4 && b == 0) || (a == 4 && b == 1) || (a == 4 && b == 5) || (a == 4 && b == 6) ||
					    (a == 3 && b == 0)|| (a == 3 && b == 1) || (a == 3 && b == 5) || (a == 3 && b == 6))
				{
					if(board[a][b] == 1 && board[a + 1][b] == 1 && board[a + 2][b] == 0) 
						return true; //down
				}
			    if (b == 5 || b == 6 || (a == 0 && b == 3) || (a == 1 && b == 3) || (a == 5 && b == 3) || (a == 6 && b == 3) || 
					    (a == 0 && b == 4) || (a == 1 && b == 4) || (a == 5 && b == 4) || (a == 6 && b == 4))
				{ 
				    if(board[a][b] == 1 && board[a][b + 1] == 1 && board[a][b + 2] == 0) 
						return true; //right
				}
				if (b == 0 || b == 1 || (a == 0 && b == 3) || (a == 1 && b == 3) || (a == 5 && b == 3) || (a == 6 && b == 3)
					|| (a == 0 && b == 2) || (a == 1 && b == 2) || (a == 5 && b == 2) || (a == 6 && b == 2))
				{
				    if (board[a][b] == 1 && board[a][b - 1] == 1 && board[a][b - 2] == 0) 
						return true; //bottom
				}
			}
		}
		return false;
	}
	else if (version == 7)
	{
		for (int a = 0; a < 7; a++)
		{
			for (int b = 0; b < 7; b++)
			{
				if (a == 0 || a == 1 || (a == 2 && b == 0) || (a == 2 && b == 1) || (a == 2 && b == 5) || (a == 2 && b == 6) ||
					(a == 3 && b == 0) || (a == 3 && b == 6))
				{
					if (board[a][b] == 1 && board[a - 1][b] == 1 && board[a - 2][b] == 0) 
						return true;
				}
				if (a == 5 || a == 6 || (a == 4 && b == 0) || (a == 4 && b == 1) || (a == 4 && b == 5) || (a == 4 && b == 6) ||
					(a == 3 && b == 0) || (a == 3 && b == 6))
				{
					if (board[a][b] == 1 && board[a + 1][b] == 1 && board[a + 2][b] == 0) 
						return true;
				}
				if (b == 5 || b == 6 || (a == 0 && b == 3) || (a == 6 && b == 3) || (a == 0 && b == 4) || (a == 1 && b == 4) ||
					(a == 5 && b == 4) || (a == 6 && b == 4))
				{
					if (board[a][b] == 1 && board[a][b + 1] == 1 && board[a][b + 2] == 0) 
						return true;
				}
				if (b == 0 || b == 1 || (a == 0 && b == 3) || (a == 6 && b == 3) || (a == 0 && b == 2) || (a == 1 && b == 2) ||
					(a == 5 && b == 2) || (a == 6 && b == 2))
				{
					if (board[a][b] == 1 && board[a][b - 1] == 1 && board[a][b - 2] == 0) 
						return true;
				}
			}
		}
		return false;
	}
}

bool PegBoard::checkBoardState(int a, int b, int action)
{
	if (version == 5)
	{
		if (action == 1) //up
		{
			if (a == 0 || a == 1 || (a == 2 && b == 0) || (a == 2 && b == 1) || (a == 2 && b == 5) || (a == 2 && b == 6)
				|| (a == 3 && b == 0) || (a == 3 && b == 1) || (a == 3 && b == 5) || (a == 3 && b == 6))
				return false;
			else if (board[a][b] == 1 && board[a - 1][b] == 1 && board[a - 2][b] == 0)
				return true;
		}

		if (action == 2) //down
		{
			if (a == 5 || a == 6 || (a == 4 && b == 0) || (a == 4 && b == 1) || (a == 4 && b == 5) || (a == 4 && b == 6)
				|| (a == 3 && b == 0) || (a == 3 && b == 1) || (a == 3 && b == 5) || (a == 3 && b == 6))
				return false;
			else if (board[a][b] == 1 && board[a + 1][b] == 1 && board[a + 2][b] == 0)
				return true;
		}

		if (action == 3) //right
		{
			if (b == 5 || b == 6 || (a == 0 && b == 3) || (a == 1 && b == 3) || (a == 5 && b == 3) || (a == 6 && b == 3)
				|| (a == 0 && b == 4) || (a == 1 && b == 4) || (a == 5 && b == 4) || (a == 6 && b == 4))
				return false;
			else if (board[a][b] == 1 && board[a][b + 1] == 1 && board[a][b + 2] == 0)
				return true;
		}

		if (action == 4) //left
		{
			if (b == 0 || b == 1 || (a == 0 && b == 3) || (a == 1 && b == 3) || (a == 5 && b == 3) || (a == 6 && b == 3)
				|| (a == 0 && b == 2) || (a == 1 && b == 2) || (a == 5 && b == 2) || (a == 6 && b == 2))
				return false;
			else if (board[a][b] == 1 && board[a][b - 1] == 1 && board[a][b - 2] == 0)
				return true;
		}
		return false;
	}
	else if (version == 7)
	{
		if (action == 1) //up
		{
			if (a == 0 || a == 1 || (a == 2 && b == 0) || (a == 2 && b == 1) || (a == 2 && b == 5) 
				|| (a == 2 && b == 6) || (a == 3 && b == 0) || (a == 3 && b == 6))
				return false;
			else if (board[a][b] == 1 && board[a - 1][b] == 1 && board[a - 2][b] == 0)
				return true;
		}

		if (action == 2) //down
		{
			if (a == 5 || a == 6 || (a == 4 && b == 0) || (a == 4 && b == 1) || (a == 4 && b == 5) 
				|| (a == 4 && b == 6) || (a == 3 && b == 0) || (a == 3 && b == 6))
				return false;
			else if (board[a][b] == 1 && board[a + 1][b] == 1 && board[a + 2][b] == 0)
				return true;
		}

		if (action == 3) //right
		{
			if (b == 5 || b == 6 || (a == 0 && b == 3) || (a == 6 && b == 3) || (a == 0 && b == 4) 
				|| (a == 1 && b == 4) || (a == 5 && b == 4) || (a == 6 && b == 4))
				return false;
			else if (board[a][b] == 1 && board[a][b + 1] == 1 && board[a][b + 2] == 0)
				return true;
		}

		if (action == 4) //left
		{
			if (b == 0 || b == 1 || (a == 0 && b == 3) || (a == 6 && b == 3) || (a == 0 && b == 2) 
				|| (a == 1 && b == 2) || (a == 5 && b == 2) || (a == 6 && b == 2))
				return false;
			else if (board[a][b] == 1 && board[a][b - 1] == 1 && board[a][b - 2] == 0)
				return true;
		}
		return false;
	}
}

void PegBoard::applyAction(int a, int b, int action)
{
	if (action == 1)      //up
	{
		upAction(a, b);
	}
	else if (action == 2) //down
	{
		downAction(a, b);
	}
	else if (action == 3) //right
	{
		rightAction(a, b);
	}
	else if (action == 4) //left
	{
		leftAction(a, b);
	}
}

int PegBoard::totalRemPegs()
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == 1)
				count++;
		}
	}
	return count;
}

bool PegBoard::applyheuristic(int a, int b, int action)
{
	int upCount = 0, downCount = 0, rightCount = 0, leftCount = 0;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == 1) upCount++;
		}
	}
	for (int i = 5; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == 1) downCount++;
		}
	}
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			if (board[i][j] == 1) leftCount++;
		}
	}
	for (int j= 5; j < 6; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			if (board[i][j] == 1) rightCount++;
		}
	}
	if (downCount > upCount && downCount > leftCount && downCount > rightCount)
	{
		return true;
	}
	else if (rightCount > upCount && rightCount > leftCount && rightCount >downCount)
	{
		return true;
	}
	else if (upCount > leftCount && upCount>rightCount && upCount >downCount)
	{
		return true;
	}
	else if (leftCount > upCount && leftCount>rightCount && leftCount >downCount)
	{
		return true;
	}

	return true; //always optimistic saying that goal is next
}

void PegBoard::upAction(int a, int b)
{
	board[a][b] = 0;
	board[a - 1][b] = 0;
	board[a - 2][b] = 1;
}

void PegBoard::downAction(int a, int b)
{
	board[a][b] = 0;
	board[a + 1][b] = 0;
	board[a + 2][b] = 1;
}

void PegBoard::rightAction(int a, int b)
{
	board[a][b] = 0;
	board[a][b + 1] = 0;
	board[a][b + 2] = 1;
}

void PegBoard::leftAction(int a, int b)
{
	board[a][b] = 0;
	board[a][b - 1] = 0;
	board[a][b - 2] = 1;
}

void PegBoard::searchForGoal()
{
	bool goalFound = isGoal();
	if (goalFound)
	{
		cout << "----------" << endl;
		printBoard();
		return;
	}
	else
	{
		int count = totalRemPegs();
		bool track=true;
		//bool makeMoves = ifConsecutivePegsOnBoard(); && makeMoves
		while (k != count )
		{
			for (int a = 0; a < 7; a++)
			{
				for (int b = 0; b < 7; b++)
				{
					for (int action = 1; action <= 4; action++)
					{
						track = checkBoardState(a,b,action);
						if (track)
						{
							bool toDo = applyheuristic(a, b, action);
							if (toDo) 
							{
								applyAction(a, b, action);
								count = totalRemPegs();
								//makeMoves = ifConsecutivePegsOnBoard();
								cout << "----------" << endl;
								cout << "Goal Pegs: " << k << '\t' << ",  Board Pegs: " << count << '\n' << '\n';
								printBoard();
							}
						}
					}
				}
			}
		}
		if (k != count)
		{
			cout << "Tried solving but could not reach up the goal !" << endl;
			//popping up from stack and seeing other possible moves that could lead up to solution
		}
		else
		{
			cout << "Cheers! Final solution by agent has came.  " << endl;
		}

	}
}