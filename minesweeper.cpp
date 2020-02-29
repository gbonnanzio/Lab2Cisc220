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
	int length = 3;
	getSize(length);
	int **testBoard = makeBoard(3);
	for(int i =0; i<3; i++){
		for(int j = 0; j<3; j++){
			cout<<testBoard[i][j];
		}
		cout << "" <<endl;
	}
	int dummyMatrix[3][3] = {{0,1,2},{3,0,5},{6,7,0}};
		for(int i =0; i<3; i++){
			for(int j =0; j<3; j++ ){
				testBoard[i][j] = dummyMatrix[i][j];
			}
		}
	printBoard(testBoard,3);

	return 0; //test
}





