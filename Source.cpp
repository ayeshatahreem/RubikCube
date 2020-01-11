#include<iostream>
#include <fstream>
#include "RubikCube.h"
#include "state.h"

using namespace std;

void main()
{
	RubikCube* cube = new RubikCube();
	cube->initCube();
	cube->showCube();
	cout << "Searching for required solution..." << endl;
	cube->initActions();
	system("pause");
}