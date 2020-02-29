/*
 * PlayGame.h
 *	Geoff B.
 *	Nick S.
 *  The functions in this file relate to running the game board
 *
 */

#ifndef PLAYGAME_H_
#define PLAYGAME_H_

char** makeVisibleBoard(int size);

bool chooseSquare(int** intmat, char** charmat, int size);

bool addBomb(char** charmat, int size, int* bombsfound);

void removeBomb(char** charmat, int size, int* bombsfound);

bool checkForWin(int** intmat, char** charmat, int size);

void removeBoard(int** intmat, int size);

void removeVisible(char** charmat, int size);

#endif /* PLAYGAME_H_ */
