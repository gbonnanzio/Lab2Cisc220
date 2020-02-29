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
	/* Function takes a reference to an int
	 * and generates a random number between 7 and 20
	 * returns nothing.
	 */
	boardSize = rand()%14 + 7;
}

int** makeBoard(int size){
	/* Function takes an int equal to the length
	 * and width of the square and creates a 2D array
	 * filled with 0's
	 * returns a pointer to the array
	 */
	int **ptrToIntBoard;
	ptrToIntBoard = new int*[size];
	for(int i = 0; i<size; i++){
		ptrToIntBoard[i] = new int[size];
		for(int j = 0; j<size; j++){
			ptrToIntBoard[i][j] = 0;
		}
	}
	return ptrToIntBoard;
}

void printBoard(int **intBoard, int size){
	/* Function takes a pointer to a 2D array of integers
	 * and the size of the square 2D array and
	 * prints out the board with indices around the edges.
	 * Prints a space instead of a 0, when a 0 appears.
	 * Returns nothing.
	 */
	cout << "*" << "\t";
	for(int i = 0; i<size; i++){
		cout << i << "\t";
	}
	cout << "" << endl;
	for(int i =0; i<size; i++){
		cout << i << "\t";
		for(int j = 0; j<size; j++){
			if(intBoard[i][j] != 0){
				cout << intBoard[i][j] << "\t";
			}
			else{
				cout << "\t";
			}
		}
		cout<< "" << endl;
	}
}



