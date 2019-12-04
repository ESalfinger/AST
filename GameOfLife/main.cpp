#include <iostream>
#include "headers/Game.h"

char board[HEIGHT][WIDTH];

int main(int argc, char** argv)
{
    bool keepPlaying = true;

    clearBoard();

    borderMode mode = initGame();

    printBoard();

    if (getchar() == 'q') {
        keepPlaying = false;
    }

    while (keepPlaying) {

        iterate(mode);

        printBoard();

        if (getchar() == 'q') {
            keepPlaying = false;
        }
    }

    return 0;
}
