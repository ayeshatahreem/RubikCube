#include "RubikCube.h"
#include "state.h"
#include<iostream>
using namespace std;

RubikCube::RubikCube()
{
	initialState = new state();
	goalState = new state();
}

void RubikCube::initCube()
{
	ifstream file;
	file.open("input.txt", ios_base::in);
	if (file.is_open())
	{
		if (!file.eof())
		{
			//initialState
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						file >> this->initialState->Data[i][j][k];
					}
				}
			}
			//goalState
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						file >> this->goalState->Data[i][j][k];
					}
				}
			}
		}
		file.close();
	}
	else
		cout << "Error while opening the file" << endl;

		

}

void RubikCube::initActions()
{
	initialState->actions->apply(initialState, goalState);
}

void RubikCube::showCube()
{
	cout << "\n\n\n\t\tSolving Puzzle with Initial State\n\n";
	this->initialState->showState();
	cout << "\n\n\n\t\t\tand Goal State\n\n";
	goalState->showState();
}

bool RubikCube::IsGoal(state* currstate)
{
	if (currstate == this->goalState)
	{
		return true;
	}
	else
		return false;
}

RubikCube* RubikCube::getCube()
{
	return this;
}