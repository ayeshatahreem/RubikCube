#ifndef RUBIKCUBE_H
#define RUBIKCUBE_H

#include<vector>
#include <fstream>
#include "state.h"
#include "action.h"

class state;
class RubikCube 
{
private:
	state* initialState;
	state* goalState;
	
public:
	RubikCube();
	RubikCube* getCube();
	void initCube();
	void initActions();
	bool IsGoal(state* currstate);
	void showCube();
};

#endif 
