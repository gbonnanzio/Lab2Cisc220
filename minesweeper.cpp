/*
 * minesweeper.cpp
 *
 *  Geoffrey Bonnanzio
 *  Nick Samulewicz
 *  Due 3/1/2020
 *
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "makeBoard.h"
using namespace std;

//main function to run program
int main(){
	//creates a random seed
	srand(time(NULL));

	//create a new board
	int length = 4;
	//getSize(length);
	int **testBoard = makeBoard(4);
	for(int i =0; i<length; i++){
		for(int j = 0; j<length; j++){
			cout<<testBoard[i][j];
		}
		cout << "" <<endl;
	}
	int dummyMatrix[length][length] = {{9,1,2,3},{6,3,0,5},{9,6,7,0},{9,6,7,0}};
		for(int i =0; i<length; i++){
			for(int j =0; j<length; j++ ){
				testBoard[i][j] = dummyMatrix[i][j];
			}
		}
	printBoard(testBoard,length);

	return 0;
}





