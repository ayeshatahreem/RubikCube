#include<iostream>
#include "RubikCube.h"
#include "action.h"

using namespace std;

action::action()
{}

state* action::RightDown( state* givenstate)  //downmove
{
	//this->givenstate->Data[i][j][col];
	string tmp1, tmp2, tmp3;
	int col = 2;
	tmp1 = givenstate->Data[0][0][col];
	tmp2 = givenstate->Data[0][1][col];
	tmp3 = givenstate->Data[0][2][col];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			givenstate->Data[i][j][col] = givenstate->Data[i + 1][j][col];
		}
	}
	givenstate->Data[3][0][col] = tmp1;
	givenstate->Data[3][1][col] = tmp2;
	givenstate->Data[3][2][col] = tmp3;

	string temp1[3], temp2[3], temp3[3];


	for (int i = 0; i<3; i++)                    // upper side copied to the temp arrays
	{
		temp1[i] = givenstate->Data[5][i][0];
		temp2[i] = givenstate->Data[5][i][1];
		temp3[i] = givenstate->Data[5][i][2];
	}

	for (int i = 0; i<3; i++)
	{
		givenstate->Data[5][2][i] = temp1[i];
		givenstate->Data[5][1][i] = temp2[i];
		givenstate->Data[5][0][i] = temp3[i];
	}

	return givenstate;
}


state* action::LeftDown(state* givenstate)   //downmove
{
	//this->givenstate->Data[i][j][col];
	string tmp1, tmp2, tmp3;
	int col = 0;
	tmp1 = givenstate->Data[0][0][col];
	tmp2 = givenstate->Data[0][1][col];
	tmp3 = givenstate->Data[0][2][col];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			givenstate->Data[i][j][col] = givenstate->Data[i + 1][j][col];
		}
	}
	givenstate->Data[3][0][col] = tmp1;
	givenstate->Data[3][1][col] = tmp2;
	givenstate->Data[3][2][col] = tmp3;

	string temp1[3], temp2[3], temp3[3];

	for (int i = 0; i<3; i++)                    // upper side copied to the temp arrays
	{
		temp1[i] = givenstate->Data[4][i][0];
		temp2[i] = givenstate->Data[4][i][1];
		temp3[i] = givenstate->Data[4][i][2];
	}
	int j = 0;
	for (int i = 2; i>=0; i--)
	{
		givenstate->Data[4][0][i] = temp1[j];
		givenstate->Data[4][1][i] = temp2[j];
		givenstate->Data[4][2][i] = temp3[j];
		j++;
	}

	return givenstate;
}


state* action::RightUp( state* givenstate)  //upmove
{
	//this->givenstate->Data[i][j][col];
	string tmp1, tmp2, tmp3;
	int col = 2;
	tmp1 = givenstate->Data[3][0][col];
	tmp2 = givenstate->Data[3][1][col];
	tmp3 = givenstate->Data[3][2][col];
	for (int i = 3; i > 0; i--)
	{
		for (int j = 0; j < 3; j++)
		{
			givenstate->Data[i][j][col] = givenstate->Data[i - 1][j][col];
		}
	}
	givenstate->Data[0][0][col] = tmp1;
	givenstate->Data[0][1][col] = tmp2;
	givenstate->Data[0][2][col] = tmp3;

	string temp1[3], temp2[3], temp3[3];

	for (int i = 0; i<3; i++)                    // upper side copied to the temp arrays
	{
		temp1[i] = givenstate->Data[5][i][0];
		temp2[i] = givenstate->Data[5][i][1];
		temp3[i] = givenstate->Data[5][i][2];
	}

	int j = 0;
	for (int i = 2; i>=0; i--)
	{
		givenstate->Data[5][0][i] = temp1[j];
		givenstate->Data[5][1][i] = temp2[j];
		givenstate->Data[5][2][i] = temp3[j];
		j++;
	}

	return givenstate;
}


state* action::LeftUp(state* givenstate) //upmove
{
	//this->givenstate->Data[i][j][col];
	string tmp1, tmp2, tmp3;
	int col = 0;
	tmp1 = givenstate->Data[3][0][col];
	tmp2 = givenstate->Data[3][1][col];
	tmp3 = givenstate->Data[3][2][col];
	for (int i = 3; i > 0; i--)
	{
		for (int j = 0; j < 3; j++)
		{
			givenstate->Data[i][j][col] = givenstate->Data[i - 1][j][col];
		}
	}
	givenstate->Data[0][0][col] = tmp1;
	givenstate->Data[0][1][col] = tmp2;
	givenstate->Data[0][2][col] = tmp3;

	string temp1[3], temp2[3], temp3[3];

	for (int i = 0; i<3; i++)                    // upper side copied to the temp arrays
	{
		temp1[i] = givenstate->Data[4][i][0];
		temp2[i] = givenstate->Data[4][i][1];
		temp3[i] = givenstate->Data[4][i][2];
	}
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		givenstate->Data[4][2][i] = temp1[j];
		givenstate->Data[4][1][i] = temp2[j];
		givenstate->Data[4][0][i] = temp3[j];
		j++;
	}



	return givenstate;
}


state* action::UpperLeft(state* givenstate)  //leftmove
{
	//this->givenstate->Data[i][j][col];
	int arr[4] = { 5, 2, 4, 0 };
	string tmp1, tmp2, tmp3;
	int row = 0;
	tmp1 = givenstate->Data[5][row][0];
	tmp2 = givenstate->Data[5][row][1];
	tmp3 = givenstate->Data[5][row][2];

	int i,x = 0;
	while (x < 3 )
	{
		i = arr[x];
		for (int j = 0; j < 3; j++)
		{
			givenstate->Data[i][row][j] = givenstate->Data[arr[x+1]][row][j];
		}
		x++;

	}
	givenstate->Data[0][row][0] = tmp1;
	givenstate->Data[0][row][1] = tmp2;
	givenstate->Data[0][row][2] = tmp3;

	return givenstate;
}


state* action::LowerLeft(state* givenstate)  //leftmove
{
	//this->givenstate->Data[i][j][col];
	int arr[4] = { 5, 2, 4, 0 };
	string tmp1, tmp2, tmp3;
	int row = 2;
	tmp1 = givenstate->Data[5][row][0];
	tmp2 = givenstate->Data[5][row][1];
	tmp3 = givenstate->Data[5][row][2];

	int i, x = 0;
	while (x < 3)
	{
		i = arr[x];
		for (int j = 0; j < 3; j++)
		{
			givenstate->Data[i][row][j] = givenstate->Data[arr[x + 1]][row][j];
		}
		x++;

	}
	givenstate->Data[0][row][0] = tmp1;
	givenstate->Data[0][row][1] = tmp2;
	givenstate->Data[0][row][2] = tmp3;

	return givenstate;
}

state* action::UpperRight(state* givenstate)  //rightmove
{
	//this->givenstate->Data[i][j][col];
	int arr[4] = { 0,4,2,5 };
	string tmp1, tmp2, tmp3;
	int row = 0;
	tmp1 = givenstate->Data[0][row][0];
	tmp2 = givenstate->Data[0][row][1];
	tmp3 = givenstate->Data[0][row][2];

	int i, x = 0;
	while (x < 3)
	{
		i = arr[x];
		for (int j = 0; j < 3; j++)
		{
			givenstate->Data[i][row][j] = givenstate->Data[arr[x + 1]][row][j];
		}
		x++;

	}
	givenstate->Data[5][row][0] = tmp1;
	givenstate->Data[5][row][1] = tmp2;
	givenstate->Data[5][row][2] = tmp3;

	return givenstate;
}


state* action::LowerRight(state* givenstate)  //rightmove
{
	//this->givenstate->Data[i][j][col];
	int arr[4] = { 0, 4, 2, 5 };
	string tmp1, tmp2, tmp3;
	int row = 2;
	tmp1 = givenstate->Data[0][row][0];
	tmp2 = givenstate->Data[0][row][1];
	tmp3 = givenstate->Data[0][row][2];

	int i, x = 0;
	while (x < 3)
	{
		i = arr[x];
		for (int j = 0; j < 3; j++)
		{
			givenstate->Data[i][row][j] = givenstate->Data[arr[x + 1]][row][j];
		}
		x++;

	}
	givenstate->Data[5][row][0] = tmp1;
	givenstate->Data[5][row][1] = tmp2;
	givenstate->Data[5][row][2] = tmp3;

	return givenstate;
}

state* action:: FrontAnticlockwise(state* givenstate)
{
	//cout << "face anti clock wise" << endl;
	string tmp[3];                  

	for (int i = 2; i >= 0; i--)                 			
	{
		tmp[i] = givenstate->Data[3][0][i];
		givenstate->Data[3][0][i] = givenstate->Data[4][i][2];
		givenstate->Data[4][i][2] = givenstate->Data[1][2][i]; 
		givenstate->Data[1][2][i] = givenstate->Data[5][i][0];
		givenstate->Data[5][i][0] = tmp[i];
	}
	string tmp1[3], tmp2[3], tmp3[3];

	for (int i = 0; i<3; i++)                    // upper side copied to the temp arrays
	{
		tmp1[i] = givenstate->Data[0][0][i];
		tmp2[i] = givenstate->Data[0][1][i];
		tmp3[i] = givenstate->Data[0][2][i];
	}

	for (int i = 0, j = 2; i<3; i++, j--)
	{
		givenstate->Data[0][j][0] = tmp1[i];
		givenstate->Data[0][j][1] = tmp2[i];
		givenstate->Data[0][j][2] = tmp3[i];
	}

	return givenstate;
}


state* action::FrontClockwise(state* givenstate)
{
	//cout << "face clock wise" << endl;
	string tmp[3];

	for (int i = 2; i >= 0; i--)
	{
		tmp[i] = givenstate->Data[3][0][i];
		givenstate->Data[3][0][i] = givenstate->Data[5][i][0];
		givenstate->Data[5][i][0] = givenstate->Data[1][2][i];
		givenstate->Data[1][2][i] = givenstate->Data[4][i][2];
		givenstate->Data[4][i][2] = tmp[i];
	}
	string tmp1[3], tmp2[3], tmp3[3];
	for (int i = 0; i<3; i++)                    // upper side copied to the temp arrays
	{
		tmp1[i] = givenstate->Data[0][0][i];
		tmp2[i] = givenstate->Data[0][1][i];
		tmp3[i] = givenstate->Data[0][2][i];
	}

	for (int i = 0; i<3; i++)
	{
		givenstate->Data[0][i][2] = tmp1[i];
		givenstate->Data[0][i][1] = tmp2[i];
		givenstate->Data[0][i][0] = tmp3[i];
	}
	return givenstate;
}


state* action::BackAnticlockwise(state* givenstate)
{
	//cout << "back anti clock wise" << endl;
	string tmp[3];

	for (int i = 2; i >= 0; i--)
	{
		tmp[i] = givenstate->Data[3][2][i];
		givenstate->Data[3][2][i] = givenstate->Data[4][i][0];
		givenstate->Data[4][i][0] = givenstate->Data[1][0][i];
		givenstate->Data[1][0][i] = givenstate->Data[5][i][2];
		givenstate->Data[5][i][2] = tmp[i];
	}
	string tmp1[3], tmp2[3], tmp3[3];

	for (int i = 0; i<3; i++)                    // upper side copied to the temp arrays
	{
		tmp1[i] = givenstate->Data[2][0][i];
		tmp2[i] = givenstate->Data[2][1][i];
		tmp3[i] = givenstate->Data[2][2][i];
	}

	for (int i = 0, j = 2; i<3; i++, j--)
	{
		givenstate->Data[2][j][0] = tmp1[i];
		givenstate->Data[2][j][1] = tmp2[i];
		givenstate->Data[2][j][2] = tmp3[i];
	}

	return givenstate;
}


state* action::BackClockwise(state* givenstate)
{
	//cout << "back clock wise" << endl;
	string tmp[3];

	for (int i = 2; i >= 0; i--)
	{
		tmp[i] = givenstate->Data[3][2][i];
		givenstate->Data[3][2][i] = givenstate->Data[5][i][2];
		givenstate->Data[5][i][2] = givenstate->Data[1][0][i];
		givenstate->Data[1][0][i] = givenstate->Data[4][i][0];
		givenstate->Data[4][i][0] = tmp[i];
	}
	string tmp1[3], tmp2[3], tmp3[3];
	for (int i = 0; i<3; i++)                    
	{
		tmp1[i] = givenstate->Data[2][0][i];
		tmp2[i] = givenstate->Data[2][1][i];
		tmp3[i] = givenstate->Data[2][2][i];
	}

	for (int i = 0; i<3; i++)
	{
		givenstate->Data[2][i][2] = tmp1[i];
		givenstate->Data[2][i][1] = tmp2[i];
		givenstate->Data[2][i][0] = tmp3[i];
	}
	return givenstate;
}

void action::apply(state* givenstate, state* goalState)
{
	int check = 0;
	int sum = 0;
	for (int i = 0; i < 22; i++)
	{
		if (givenstate->compare(givenstate, goalState) == true)
		{
			check = 1;
			cout << "\n GOAL STATE ACHIEVED!" << endl;
			givenstate->showState();
		}

		if (check == 1){ break; }

		else
		{
			givenstate->successor_func(i, this);
			for (int i = 0; i < 4; i++)   //manhattan distance
			{
				sum = sum + givenstate->heuristic(givenstate, goalState, this);
			}
			if (givenstate->isGoal(goalState) == true)
			{
				check = 1;
				cout << "\n GOAL STATE ACHIEVED!" << endl;
				givenstate->showState();
				//return givenstate;
			}
		}		
	}
	if (check != 1)
	{
		cout << "\n GOAL STATE NOT ACHIEVED!" << endl;
		givenstate->showState();
		//return givenstate;
	}	
}