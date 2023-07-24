#include <bits/stdc++.h>

void setZeros(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Keep track of rows and columns to be zeroed out
    vector<bool> zeroRows(rows, false);
    vector<bool> zeroCols(cols, false);

    // Traverse the matrix and mark rows and columns to be zeroed
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    // Zero out the marked rows
    for (int i = 0; i < rows; i++) {
        if (zeroRows[i]) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out the marked columns
    for (int j = 0; j < cols; j++) {
        if (zeroCols[j]) {
            for (int i = 0; i < rows; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}
