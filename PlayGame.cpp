/*
 *  PlayGame.cpp
 *	Geoff B.
 *	Nick S.
 *  The functions in this file relate to running the game board
*/
#include "PlayGame.h"


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
	char c = intmat[y][x];
	charmat[y][x] = c;
	if(x || y >= size){
		cout << "Invalid square. Choose again" << endl;
		chooseSquare(intmat, charmat, size);
	}
	if( c == '9'){
		return false;
	}
	else{
		return true;
	}
}

bool addBomb(char** charmat, int size, int* bombsfound){

}

