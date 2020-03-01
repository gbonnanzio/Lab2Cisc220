/*
 *  PlayGame.cpp
 *	Geoff B.
 *	Nick S.
 *  The functions in this file relate to running the game board
*/
#include "PlayGame.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;


char** makeVisibleBoard(int size){
	/*	This function takes as an input parameter the integer for the size of the 2-D matrix of characters that will
	 * 	be created in this function and returned from this function. The 2-D matrix will be initialized to all '-'
	 * 	It will be the board that is displayed to the user as the user plays the game.
	 *
	 */
	char **ptrToCharBoard;
		ptrToCharBoard = new char*[size];
		for(int i = 0; i<size; i++){
			ptrToCharBoard[i] = new char[size];
			for(int j = 0; j<size; j++){
				ptrToCharBoard[i][j] = '-';
			}
		}
		return ptrToCharBoard;
}

void printVisible(char **charmat, int size){
	/* Function takes a pointer to a 2D array of chars
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
			if(charmat[i][j] != 0){
				cout << charmat[i][j] << "\t";
			}
			else{
				cout << "\t";
			}
		}
		cout<< "" << endl;
	}
}




bool chooseSquare(int** intmat, char** charmat, int size){
	/*	This function takes as input parameters the pointer to the board matrix of ints, the pointer to the visible
	*	matrix of chars, and the size.
	*	It uses cout and cin to allow the user to choose a square (the x and the y position on the matrix
	*	respectively) and then sets the visible matrix at that square to be the value in the board matrix.
	*	This function returns a boolean - false if the square chosen was a bomb, and true otherwise
	*/
	int x;
	int y;
	cout << "Choose square x:" << endl;
	cin >> x;
	while(x >= size){
		cout << "Invalid square. Choose again:" << endl;
		cin >> x;
	}
	cout << "Choose square y:" << endl;
	cin >> y;
	while(y >= size){
		cout << "Invalid square. Choose again:" << endl;
		cin >> y;
	}
	char *c = new char;
	itoa(intmat[x][y],c,10);
	charmat[x][y] = *c;
	if( *c == '9'){
		return false;
	}
	else{
		return true;
	}
}


bool addBomb(char** charmat, int size, int* bombsfound){
	/* This function takes as input parameters the pointer to the visible matrix of chars, the size int, and a pointer
	 *  to the number of bombs found. It returns a boolean value (true if the number of bombs found is equal
	 *  to size + 1, false otherwise
	 *  this function is allowing the user to choose a square where they think a bomb is and mark it as bomb in
	 *  the visible matrix
	 *  '9' denotes a bomb
	 */
	int col;
	int row; //work
	int tempVal = *bombsfound;
	cout << "Add Bomb: Choose Square x:" << endl;
	cin >> row;
	while(row >= size){
		cout << "Invalid square. Choose again:" << endl;
		cin >> row;
		}
	cout << "Add Bomb: Choose Square y:" << endl;
		cin >> col;
		while(col >= size){
			cout << "Invalid square. Choose again:" << endl;
			cin >> col;
		}
	charmat[row][col] = '9';
	tempVal++;
	*bombsfound = tempVal;
	if(tempVal == size + 1){
		return true;
	}
	else{
		return false;
	}
}



void removeBomb(char** charmat, int size, int* bombsfound){
	/*	This function takes as input parameters the pointer to the visible matrix of chars, the size int, and a pointer
	 *	to the number of bombs found.
	 *	this function is allowing the user to choose a square where they previously placed a bomb and unmark the square.
	 */
	int col;
	int row;
	cout << "Remove Bomb: Choose Square x:" << endl;
	cin >> row;
	while(row >= size){
		cout << "Invalid square. Choose again:" << endl;
		cin >> row;
	}
	cout << "Remove Bomb: Choose Square y:" << endl;
	cin >> col;
	while(col >= size){
		cout << "Invalid square. Choose again:" << endl;
		cin >> col;
	}
	if(charmat[row][col] == '9'){
		charmat[row][col] = '-';
		*bombsfound--;
	}
}



bool checkForWin(int** intmat, char** charmat, int size){
	/*	this function takes as input the pointer to the board matrix of integers, the pointer to the visible matrix
	 * 	of characters, and the int size
	 * 	It checks to make sure that each bomb in the board matrix has been marked as a bomb on the visible
	 * 	matrix. It returns a boolean value - true if all the bombs have been found, and false otherwise
	 */
	for(int i = 0; i < size; i++){
		for(int j = 0;j < size; j++){
			if(intmat[j][i] == 9){
				if(charmat[j][i] != '9'){
					return false;
				}
			}
		}
	}
	return true;
}



void removeBoard(int** intmat, int size){
	/*This function takes as input parameters the pointer to the 2-D integer matrix that is the board, along with the
	 * size integer, and removes the matrix from the heap. It returns nothing.
	 */
	delete []intmat;
	return;
}


void removeVisible(char** charmat, int size){
	/*This function takes as input parameters the pointer to the 2-D character matrix that is the visible board, along with the
	 * size integer, and removes the matrix from the heap. It returns nothing.
	 */
	delete []charmat;
	return;
}
