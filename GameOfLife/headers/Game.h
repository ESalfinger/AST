#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H

#ifndef WIDTH
#  define WIDTH 40
#endif
#ifndef HEIGHT
#  define HEIGHT 30
#endif

extern char board[HEIGHT][WIDTH];

#define EMPTY (' ')

enum borderMode { box, loop, torus };

int countSurroundingAlive(char (*tempArray)[WIDTH], int i, int j);

int loopHorizontal(char (*tempArray)[WIDTH], int i, int j, int aliveCount);

int loopVertical(char (*tempArray)[WIDTH], int i, int j, int aliveCount);

void clearBoard();

borderMode initGame();

void iterate(borderMode mode);

void printBoard();
#endif //GAMEOFLIFE_GAME_H
