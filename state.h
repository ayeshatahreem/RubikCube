#ifndef STATE_H
#define STATE_H

#include<iostream>
#include<string>
#include "RubikCube.h"
#include "action.h"
using namespace std;

class action;
class RubikCube;
class state 
{
public:
	action* actions;
	string Data[6][3][3];
	//int spacePosition[3];  //3dimensional
	//RubikCube* cube;
	
	state();
	void successor_func(int child_name, action* curr_action);
	bool isGoal(state* goalState);
	void showState();
	bool compare(state* a , state* b);
	int compstates(state* a, state* b);
	int heuristic(state* initialState,state* goalState, action* a);

};

#endif // STATE_H
