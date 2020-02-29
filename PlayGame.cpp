/*
 *  PlayGame.cpp
 *	Geoff B.
 *	Nick S.
 *  The functions in this file relate to running the game board
*/
#include "PlayGame.h"
#include <stdio.h>
using namespace std;


/*	This function takes as input parameters the pointer to the board matrix of ints, the pointer to the visible
*	matrix of chars, and the size.
*	It uses cout and cin to allow the user to choose a square (the x and the y position on the matrix
*	respectively) and then sets the visible matrix at that square to be the value in the board matrix.
*	This function returns a boolean - false if the square chosen was a bomb, and true otherwise
*/
bool chooseSquare(int** intmat, char** charmat, int size){
	int x;
	int y;
	cout << "Choose square x:" >> endl;
	cin >> x;
	cout << "Choose square y;" >> endl;
	cin >> y;
	char c = intmat[x][y];
	charmat[x][y] = c;
	if(x >= size || y >= size){
		cout << "Invalid square. Choose again:" << endl;
		chooseSquare(intmat, charmat, size);
	}
	if( c == '9'){
		return false;
	}
	else{
		return true;
	}
}

/* This function takes as input parameters the pointer to the visible matrix of chars, the size int, and a pointer
 *  to the number of bombs found. It returns a boolean value (true if the number of bombs found is equal
 *  to size + 1, false otherwise
 *  this function is allowing the user to choose a square where they think a bomb is and mark it as bomb in
 *  the visible matrix
 *  '9' denotes a
 */
bool addBomb(char** charmat, int size, int* bombsfound){
	int col;
	int row;
	cout << "Add Bomb: Choose Square x:" << endl;
	cin >> row;
	cout << "Add Bomb: Choose Square y:" << endl;
	cin >> col;
	charmat[row][col] = '9';
	return true;


}

