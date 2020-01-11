#ifndef ACTION_H
#define ACTION_H
#include<iostream>
#include<string>

class state;
class action 
{
public:

	//Cubemove* move;
	action();
	state* RightDown( state* givenstate); //columnfixed
	state* LeftDown( state* givenstate); //columnfixed
	state* RightUp( state* givenstate); //columnfixed
	state* LeftUp(state* givenstate); //columnfixed
	state* UpperRight(state* givenstate); //rowfixed
	state* LowerRight(state* givenstate); //rowfixed
	state* UpperLeft(state* givenstate); //rowfixed
	state* LowerLeft(state* givenstate); //rowfixed
	state* FrontAnticlockwise(state* givenstate);
	state* FrontClockwise(state* givenstate);
	state* BackAnticlockwise(state* givenstate);
	state* BackClockwise(state* givenstate);

	void apply(state* State, state* goalState); //state to which action is applied
	void setAction(int rowAction, int columnAction);
	
};

#endif 
