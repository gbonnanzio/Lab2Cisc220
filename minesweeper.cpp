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
#include "PlayGame.h"
using namespace std;

int main() {
srand(time(NULL));
int size = 0;
int bombsfound = 0;
getSize(size);
cout << "Size is " << size << endl;
int **mat = makeBoard(size);
//printBoard(mat, size); - for testing purposes
placeBombs(mat,size);
//printBoard(mat, size); - for testing purposes
placeCounts(mat, size);
//printBoard(mat, size); - for testing purposes
char **visible = makeVisibleBoard(size);
/* For testing purposes: */
printVisible(visible,size);
chooseSquare(mat,visible,size);
printVisible(visible,size);
addBomb(visible, size, &bombsfound);
printVisible(visible,size);
removeBomb(visible, size, &bombsfound);
printVisible(visible,size);
checkForWin(mat, visible, size);
/* End of testing */
char c;
bool flag = true;
char again = 'n';
while (flag) {
printVisible(visible,size);
cout << "Choose: A for choose square, B for add Bomb, C for remove bomb: " << endl;
cin >> c;
if (c == 'A' || c == 'a') {
flag = chooseSquare(mat, visible, size);
if (!flag) {
cout << "YOU LOSE! YOU HIT A BOMB!!" << endl;
printBoard(mat, size);
cout << "\n\nDo you want to play again?" <<endl;
cin >> again;
}
}
if (c == 'B' || c == 'b') {
if (addBomb(visible, size, &bombsfound)) {
cout << "Bombs found: " << bombsfound << endl;
cout << "You appear to think you've found all the bombs" << endl;
cout << "Choose: D for check for Win, or C for remove bomb:" << endl;
cin >> c;
if (c == 'D' || c == 'd') {
if (checkForWin(mat, visible, size)) {
cout <<"YOU WON!!! WOO WOO!!!" << endl;
printBoard(mat, size);
}
else {
cout <<"Sorry, you were wrong. Boo hoo." << endl;
printBoard(mat, size);
}
removeBoard(mat, size);
removeVisible(visible, size);
bombsfound = 0;
flag = false;
}
cout << "\n\nDo you want to play again? (y or n)" <<endl;
cin >> again;
}
}
if (c == 'C' || c == 'c') {
removeBomb(visible, size, &bombsfound);
}
if (!flag && (again == 'y' || again == 'Y')) {
flag = true;
bombsfound = 0;
getSize(size);
cout << "Size is " << size << endl;
mat = makeBoard(size);
//printBoard(mat, size); - for testing purposes
placeBombs(mat,size);
//printBoard(mat, size); - for testing purposes
placeCounts(mat, size);
//printBoard(mat, size); - for testing purposes
visible = makeVisibleBoard(size);
}
}
return 0;
}
