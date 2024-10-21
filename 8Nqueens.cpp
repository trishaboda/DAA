#include <iostream>
using namespace std;

#define MAX 20

void printBoard(int board[MAX][MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
}

bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[MAX][MAX], int col, int N) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1, N)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

int main() {
    int N;
    cout << "Enter the size of the board (N): ";
    cin >> N;

    int board[MAX][MAX] = {0}; 

    if (solveNQueens(board, 0, N)) {
        cout << "Solution for " << N << "-Queens problem:" << endl;
        printBoard(board, N); 
    } else {
        cout << "No solution exists for " << N << "-Queens problem." << endl;
    }
    return 0;
}
