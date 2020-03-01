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

void placeBombs(int **intBoard, int size){
	/* Function takes a pointer to the board (2D array
	 * of integers, and the size of the board
	 * Places a bomb randomly on the board and checks
	 * whether a bomb is already there
	 * returns nothing.
	 */
	int xIndex = rand()%size;
	int yIndex = rand()%size;
	while(intBoard[xIndex][yIndex] == 9){
		xIndex = rand()%size;
		yIndex = rand()%size;
	}
	intBoard[xIndex][yIndex] = 9;
}

void placeCounts(int **intBoard, int size){
	/* Function takes a pointer to the board (2D array
	 * of integers, and the size of the board
	 * Counts how many bombs (the number 9) are adjacent
	 * to each spot on the board
	 * returns nothing
	 */
	int bombs = 0;
	for(int i = 0; i<size; i++){
		for(int j =0; j<size; j++){
			bombs =0;
			if(intBoard[i][j]!=9){
				//first row
				if(i == 0){
					//top left corner
					if(j == 0){
						if(intBoard[i][j+1]==9){
							bombs++;
						}
						if(intBoard[i+1][j]==9){
							bombs++;
						}
						if(intBoard[i+1][j+1]==9){
							bombs++;
						}
					}
					//top right corner
					else if(j==size-1){
						if(intBoard[i][j-1]==9){
							bombs++;
						}
						if(intBoard[i+1][j-1]==9){
							bombs++;
						}
						if(intBoard[i+1][j]==9){
							bombs++;
						}
					}
					//top row (not corners)
					else{
						if(intBoard[i][j-1]==9){
							bombs++;
							cout<<"test 4"<<endl;
						}
						if(intBoard[i][j+1]==9){
							bombs++;
							cout<<"test 5"<<endl;
						}
						for(int b = j-1; b<=j+1; b++){
							if(intBoard[i+1][b] == 9){
								bombs++;
								cout<<"test 6"<<endl;
							}
						}
					}
				}
				//bottom row
				else if(i == size -1){
					//bottom left corner
					if(j == 0){
						if(intBoard[i-1][j]==9){
							bombs++;
						}
						if(intBoard[i-1][j+1]==9){
							bombs++;
						}
						if(intBoard[i][j+1]==9){
							bombs++;
						}
					}
					//bottom right corner
					else if(j==size-1){
						if(intBoard[i][j-1]==9){
							bombs++;
						}
						if(intBoard[i-1][j-1]==9){
							bombs++;
						}
						if(intBoard[i-1][j]==9){
							bombs++;
						}
					}
					//bottom row (not corners)
					else{
						if(intBoard[i][j-1]==9){
							bombs++;
						}
						if(intBoard[i][j+1]==9){
							bombs++;
						}
						for(int b = j-1; b<=j+1; b++){
							if(intBoard[i-1][b] == 9){
								bombs++;
							}
						}
					}
				}
				else{
					if(j == 0){
						//left edge (not corners)
						if(intBoard[i-1][j]==9){
							bombs++;
						}
						if(intBoard[i+1][j]==9){
							bombs++;
						}
						for(int a = i-1; a<=i+1; a++){
							if(intBoard[a][j+1] == 9){
								bombs++;
							}
						}
					}
					else if(j == size -1){
						//right edge (not corners)
						if(intBoard[i-1][j]==9){
							bombs++;
						}
						if(intBoard[i+1][j]==9){
							bombs++;
						}
						for(int a = i-1; a<=i+1; a++){
							if(intBoard[a][j-1] == 9){
								bombs++;
							}
						}
					}
					else{
						//center pieces
						for(int a = i-1; a<=i+1; a++){
							for(int b = j-1; b<=j+1; b++){
								if(!(a == i && b == j)){
									if(intBoard[a][b]==9){
										bombs++;
									}
								}
							}
						}
					}
				}
			intBoard[i][j]=bombs;
			}
		}
	}
}




