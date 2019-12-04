//
// Created by Elias Salfinger on 04.12.19.
//

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H

#ifndef WIDTH
#  define WIDTH 50
#endif
#ifndef HEIGHT
#  define HEIGHT 30
#endif

extern char board[HEIGHT][WIDTH];

#define EMPTY (' ')
#define DEAD ('X')

enum borderMode { box, loop, torus };

void clearBoard();

borderMode initGame();

void iterate(borderMode mode);

void printBoard();
#endif //GAMEOFLIFE_GAME_H
