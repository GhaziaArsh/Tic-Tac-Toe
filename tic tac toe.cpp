#include <iostream>
#include <windows.h>
using namespace std;

const int BOARD_SIZE = 10;

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << " " << board[i][j] << " ";
            if (j < size - 1) {
                cout << " |";
            }
        }
        cout << endl;
        if (i < size - 1) {
            for (int k = 0; k < size; k++) {
                cout << "----";
                if (k < size - 1) {
                    cout << "|";
                }
            }
            cout << endl;
        }
    }
}

void askForMove(char board[BOARD_SIZE][BOARD_SIZE], int size, int &row, int &col) {
    cout<<"rows and columns are started from 0"<<endl;
    cout<<endl;
    cout << " Enter Row of your choice: ";
    cin >> row;
    cout << " Enter Column of your choice: ";
    cin >> col;
}

bool checkLegality(char board[BOARD_SIZE][BOARD_SIZE], int size, int row, int col) {
    return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ';
}

void changeTurn(int &turn) {
    turn = 1 - turn;
}

bool isDraw(char board[BOARD_SIZE][BOARD_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void writeOnBoard(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char symbol, int &turn) {
    board[row][col] = symbol;
}

bool isWin(char board[BOARD_SIZE][BOARD_SIZE], int size, char symbol) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != symbol) {
                break;
            }
            if (j == size - 1) {
                return true; // Win in a row
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[j][i] != symbol) {
                break;
            }
            if (j == size - 1) {
                return true; // Win in a column
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (board[i][i] != symbol) {
            break;
        }
        if (i == size - 1) {
            return true; // Win in the main diagonal
        }
    }

    for (int i = 0; i < size; i++) {
        if (board[i][size - i - 1] != symbol) {
            break;
        }
        if (i == size - 1) {
            return true; // Win in the other diagonal
        }
    }

    return false;
}

int main() {
    cout<< "                                          Welcom to tic tac toe                                              "<<endl;


    int size, row, col, turn = 0;
    char symbols[2] = {'O', 'X'};
    char board[BOARD_SIZE][BOARD_SIZE];
cout<<endl;
    cout << " Enter Dimension for board: ";
    cin >> size;

    initializeBoard(board, size);
    displayBoard(board, size);

    while (!isWin(board, size, symbols[turn]) && !isDraw(board, size)) {
        askForMove(board, size, row, col);

        if (checkLegality(board, size, row, col)) {
            writeOnBoard(board, row, col, symbols[turn], turn);
            displayBoard(board, size);

            if (isWin(board, size, symbols[turn])) {
                cout << " Yahoooo! Player " << symbols[turn] << " wins!" << endl;
            } else if (isDraw(board, size)) {
                cout << "The game is a draw." << endl;
            } else {
                changeTurn(turn);
            }
        } else {
            cout << "Invalid move...... Please try again" << endl;
        }
    }

    return 0;
}
