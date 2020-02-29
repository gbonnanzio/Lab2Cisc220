/*
 * makeBoard.cpp
 *
 *  Geoffrey Bonnanzio
 *  Partner: Nick Samulewicz
 *  The functions in this file relate to creating the game board and
 *  printing it to the screen
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//Header file for function definitions
#include "makeBoard.h"


void getSize(int &boardSize){
	boardSize = rand()%14 + 7; //generates a random number between 7 and 20;
}


