#include "state.h"
#include "RubikCube.h"
#include<iostream>
using namespace std;

state::state()
{
	actions = new action();
}

void state::showState()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout<< this->Data[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
	}
}

void state::successor_func(int i, action* obj)
{
	if (i == 0)
	{
		obj->RightDown(this);
	}

	if (i == 1)
	{
		obj->UpperLeft(this);
	}

	if (i == 2)
	{
		obj->LowerRight(this);
	}

	if (i == 3)
	{
		obj->LowerLeft(this);
	}

	if (i == 4)
	{
		obj->RightUp(this);
	}

	if (i == 5)
	{
		obj->UpperRight(this);
	}

	if (i == 6)
	{
		obj->LeftUp(this);
	}

	if (i == 7)
	{
		obj->LeftDown(this);
	}

	if (i == 8)
	{
		obj->FrontClockwise(this);
	}

	if (i == 9)
	{
		obj->FrontAnticlockwise(this);
	}

	if (i == 10)
	{
		obj->BackClockwise(this);
	}

	if (i== 11)
	{
		obj->BackAnticlockwise(this);
	}	
}

bool state::isGoal(state* goalState)
{
	if (compare(this, goalState) == true)
	{
		return true;
	}
	else
		return false;
}

bool state::compare(state* a, state* b)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (a->Data[i][j][k] != b->Data[i][j][k])
				{
					return false;
				}
			}
		}
	}
	return true;
}

int state::compstates(state* a, state* b)
{
	int value = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (a->Data[i][j][k] == b->Data[i][j][k])
				{
					value++;
				}
			}
		}
	}
	return value;
}

int state::heuristic(state* init, state* goal, action* a)
{
	int checked = 0;
	int i = 0;
	while (i<6)  //faces
	{
		for (int j = 0; j < 3; j++) //rows
		{
			for (int k = 0; k < 3; k++) //cols
			{
				if (init->Data[0][j][k] != goal->Data[0][j][k])
				{
					for (int l = 0; l < 12; l++)
					{
						init->successor_func(l, a);
						if (init->Data[0][i][k] == goal->Data[0][i][k])
						{
							checked++;
							break;
						}

					}
				}
				else
					checked++;
			}
		}
	}
	return checked;
}