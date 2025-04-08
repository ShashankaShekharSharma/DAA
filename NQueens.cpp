#include <iostream>
using namespace std;

const int MAX = 20; // Max board size
int board[MAX];
int n;

// Check if it's safe to place queen at row, col
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check column & diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Recursive function to solve N Queens
bool solveNQueens(int row) {
    if (row == n) {
        // All queens placed, print solution
        cout << "One possible solution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        return true; // Return true to show one solution
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (solveNQueens(row + 1))
                return true; // stop at one solution
        }
    }

    return false; // No solution
}

int main() {
    cout << "Enter the number of queens (N): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Invalid input. Please enter N between 1 and " << MAX << ".\n";
        return 0;
    }

    if (!solveNQueens(0))
        cout << "No solution exists for N = " << n << endl;

    return 0;
}
