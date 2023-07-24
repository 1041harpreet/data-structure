#include <bits/stdc++.h>
bool isSafe(int row, int col, vector<vector<int>> &board, int value) {
  for (int i = 0; i < board.size(); i++) {
    if (board[row][i] == value) {
      return false;
    }
    if (board[i][col] == value) {
      return false;
    }
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) {
      return false;
    }
  }
  return true;
}
bool solve(vector<vector<int>> &sudoku) {
  int n = sudoku[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (sudoku[i][j] == 0) {
        for (int val = 1; val <= 9; val++) {
          if (isSafe(i, j, sudoku, val)) {
            sudoku[i][j] = val;
            bool next = solve(sudoku);
            if (next) {
              return true;
            } else {
              sudoku[i][j] = 0;
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}

void solveSudoku(vector<vector<int>> &sudoku) { solve(sudoku); }


//tc 9^m where m is empty cell and space is O(1)