#include <bits/stdc++.h>

void addSolution(int n, vector<vector<int>> &ans, vector<vector<int>> board) {
  vector<int> temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp.push_back(board[i][j]);
    }
  }
  ans.push_back(temp);
}
bool isSafe(int row, int col, int n, vector<vector<int>> &board) {
  int r = row;
  int c = col;
  while (c >= 0) {
    if (board[r][c] == 1) {
      return false;
    }
    c--;
  }
  r = row;
  c = col;
  //diagnal left upward
  while (c >= 0 && r >= 0) {
    if (board[r][c] == 1) {
      return false;
    }
    c--;
    r--;
  }
  r = row;
  c = col;
//   bottom diagnal
  while (c >= 0 && r < n) {
    if (board[r][c] == 1) {
      return false;
    }
    c--;
    r++;
  }
  return true;
}
void solve(int col, int n, vector<vector<int>> &ans,
           vector<vector<int>> &board) {
  if (col == n) {
    addSolution(n, ans, board);
    return;
  }

  for (int row = 0; row < n; row++) {
    if (isSafe(row, col, n, board)) {
      board[row][col] = 1;
      solve(col + 1, n, ans, board);
      board[row][col] = 0;
    }
  }
}
vector<vector<int>> nQueens(int n) {
  vector<vector<int>> ans;
  vector<vector<int>> board(n, vector<int>(n, 0));
  solve(0, n, ans, board);
  return ans;
}
//as we are usign while loop to queen is present or not , so we can optimize it using map , store row,col and bool in map and check if present 
