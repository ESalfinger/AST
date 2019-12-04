#include <iostream>
#include <sstream>
#include <cstdlib>
#include "headers/Game.h"

using namespace std;

char block[2][2] = {
        {'0', '0'},
        {'0', '0'}
};
char boat[3][3] = {
        {'0',   '0', EMPTY},
        {'0', EMPTY, '0'},
        {EMPTY, '0', EMPTY}
};
char blinker[3] = {'0', '0', '0'};
char toad[2][4] = {
        {EMPTY, '0', '0', '0'},
        {'0',   '0', '0', EMPTY}
};
char exploder[5][5] = {
        {'0', EMPTY, '0',   EMPTY, '0'},
        {'0', EMPTY, EMPTY, EMPTY, '0'},
        {'0', EMPTY, EMPTY, EMPTY, '0'},
        {'0', EMPTY, EMPTY, EMPTY, '0'},
        {'0', EMPTY, '0',   EMPTY, '0'}
};
char spaceship[4][5] = {
        {EMPTY, '0', EMPTY, EMPTY, '0'},
        {'0', EMPTY, EMPTY, EMPTY, EMPTY},
        {'0', EMPTY, EMPTY, EMPTY, '0'},
        {'0',   '0', '0', '0',     EMPTY}
};
char tenCellRow[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};

int gen = 0;

void clearBoard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = EMPTY;

        }
    }
}

borderMode initGame() {
    cout << "PLAY MODE" << endl;
    cout << "[1] Block" << endl;
    cout << "[2] Boat" << endl;
    cout << "[3] Blinker" << endl;
    cout << "[4] Toad" << endl;
    cout << "[5] Exploder" << endl;
    cout << "[6] Spaceship" << endl;
    cout << "[7] 10 Cell Row" << endl;
    cout << "[8] random Cells" << endl;

    int answer = 0;
    string input;
    stringstream tmpStream;

    do {
        getline(cin, input);
        tmpStream.str(input);
        tmpStream >> answer;
        tmpStream.clear();

        switch (answer) {
            case 1:
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        board[HEIGHT / 2 - 1 + i][WIDTH / 2 - 1 + j] = block[i][j];
                    }
                }
                break;
            case 2:
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        board[HEIGHT / 2 - 1 + i][WIDTH / 2 - 1 + j] = boat[i][j];
                    }
                }
                break;
            case 3:
                for (int i = 0; i < 3; i++) {
                    board[HEIGHT / 2][WIDTH / 2 - 1 + i] = blinker[i];
                }
                break;
            case 4:
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 4; j++) {
                        board[HEIGHT / 2 - 1 + i][WIDTH / 2 - 2 + j] = toad[i][j];
                    }
                }
                break;
            case 5:
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        board[HEIGHT / 2 - 2 + i][WIDTH / 2 - 2 + j] = exploder[i][j];
                    }
                }
                break;
            case 6:
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 5; j++) {
                        board[HEIGHT / 2 - 2 + i][WIDTH / 2 - 2 + j] = spaceship[i][j];
                    }
                }
                break;
            case 7:
                for (int i = 0; i < 10; i++) {
                    board[HEIGHT / 2][WIDTH / 2 - 5 + i] = tenCellRow[i];
                }
                break;
            case 8:
                int random;
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        random = rand() % 5;
                        if (random == 0) {
                            board[i][j] = '0';
                        } else {
                            board[i][j] = EMPTY;
                        }
                    }
                }
                break;
            default:
                cout << " Type in a number to choose your mode.\n";
        }
    } while (answer <= 0 || answer > 9);

    cout << "BORDER BEHAVIOR" << endl;
    cout << "[1] Torus" << endl;
    cout << "[2] Box" << endl;
    cout << "[3] Loop" << endl;
    borderMode mode = torus;

    do {
        getline(cin, input);
        tmpStream.str(input);
        tmpStream >> answer;
        tmpStream.clear();

        switch (answer) {
            case 1:
                mode = torus;
                break;
            case 2:
                mode = box;
                break;
            case 3:
                mode = loop;
                break;
            default:
                cout << " Type in a number to choose border behavior.\n";
        }
    } while (answer <= 0 || answer > 3);
    return mode;
}

int countSurroundingAlive(char (*tempArray)[WIDTH], int i, int j) {
    int aliveCount = 0;
    if (tempArray[i - 1][j - 1] != EMPTY && i > 0 && j > 0) aliveCount++;
    if (tempArray[i][j - 1] != EMPTY && j > 0) aliveCount++;
    if (tempArray[i - 1][j] != EMPTY && i > 0) aliveCount++;
    if (tempArray[i - 1][j + 1] != EMPTY && i > 0 && j + 1 < WIDTH) aliveCount++;
    if (tempArray[i][j + 1] != EMPTY && j + 1 < WIDTH) aliveCount++;
    if (tempArray[i + 1][j] != EMPTY && i + 1 < HEIGHT) aliveCount++;
    if (tempArray[i + 1][j - 1] != EMPTY && i + 1 < HEIGHT && j > 0) aliveCount++;
    if (tempArray[i + 1][j + 1] != EMPTY && i + 1 < HEIGHT && j + 1 < WIDTH) aliveCount++;

    return aliveCount;
}

int loopHorizontal(char (*tempArray)[WIDTH], int i, int j, int aliveCount) {
    if (j == 0) {
        if (tempArray[i - 1][WIDTH - 1] != EMPTY && i > 0) aliveCount++;
        if (tempArray[i][WIDTH - 1] != EMPTY) aliveCount++;
        if (tempArray[i + 1][WIDTH - 1] != EMPTY && i + 1 < HEIGHT) aliveCount++;
    }

    if (j == HEIGHT - 1) {
        if (tempArray[i - 1][0] != EMPTY && i > 0) aliveCount++;
        if (tempArray[i][0] != EMPTY) aliveCount++;
        if (tempArray[i + 1][0] != EMPTY && i + 1 < HEIGHT) aliveCount++;
    }
}

int loopVertical(char (*tempArray)[WIDTH], int i, int j, int aliveCount) {
    if (i == 0) {
        if (tempArray[HEIGHT - 1][j - 1] != EMPTY && j > 0) aliveCount++;
        if (tempArray[HEIGHT - 1][j] != EMPTY) aliveCount++;
        if (tempArray[HEIGHT - 1][j + 1] != EMPTY && j + 1 < WIDTH) aliveCount++;

    }

    if (i == WIDTH - 1) {
        if (tempArray[0][j - 1] != EMPTY && j > 0) aliveCount++;
        if (tempArray[0][j] != EMPTY) aliveCount++;
        if (tempArray[0][j + 1] != EMPTY && j + 1 < WIDTH) aliveCount++;

    }
}

void iterate(borderMode mode) {
    gen++;
    char tempArray[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            tempArray[i][j] = board[i][j];
        }
    }

    int aliveCount = 0;
    if (mode == box) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                aliveCount = countSurroundingAlive(tempArray, i, j);

                int compare = (int) tempArray[i][j] - 48;

                if (tempArray[i][j] != EMPTY) {
                    if (aliveCount == 2 || aliveCount == 3) {
                        board[i][j] += 1;
                        if (compare >= 9 || compare == -6) {
                            board[i][j] = '*';
                        }
                    } else {
                        board[i][j] = EMPTY;
                    }
                } else if (tempArray[i][j] == EMPTY && aliveCount == 3) {
                    board[i][j] = '0';
                }
            }
        }
    }

    if (mode == torus) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                aliveCount = countSurroundingAlive(tempArray, i, j);

                int compare = (int) tempArray[i][j] - 48;

                loopHorizontal(tempArray, i, j, aliveCount);

                loopVertical(tempArray, i, j, aliveCount);

                if (tempArray[i][j] != EMPTY) {
                    if (aliveCount == 2 || aliveCount == 3) {
                        board[i][j] += 1;
                        if (compare >= 9 || compare == -6) {
                            board[i][j] = '*';
                        }
                    } else {
                        board[i][j] = EMPTY;
                    }
                } else if (tempArray[i][j] == EMPTY && aliveCount == 3) {
                    board[i][j] = '0';
                }
            }
        }
    }

    if (mode == loop) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                aliveCount = countSurroundingAlive(tempArray, i, j);

                int compare = (int) tempArray[i][j] - 48;

                loopHorizontal(tempArray, i, j, aliveCount);

                if (tempArray[i][j] != EMPTY) {
                    if (aliveCount == 2 || aliveCount == 3) {
                        board[i][j] += 1;
                        if (compare >= 9 || compare == -6) {
                            board[i][j] = '*';
                        }
                    } else {
                        board[i][j] = EMPTY;
                    }
                } else if (tempArray[i][j] == EMPTY && aliveCount == 3) {
                    board[i][j] = '0';
                }
            }
        }
    }
}

void printBoard() {
    cout << "\nGENERATION: " << gen << endl;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}
