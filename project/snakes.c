#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int row = 0, col = 0, ud = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result_matrix[row][col] = matrix[i][j];
            if (ud) {
                if (row + 1 < n) {
                    row++;
                } else {
                    ud = 0;
                    col++;
                }
            } else {
                if (row - 1 >= 0) {
                    row--;
                } else {
                    ud = 1;
                    col++;
                }
            }
        }
    }
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int row = 0, col = 0, ud = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result_matrix[row][col] = matrix[i][j];
            if (ud) {
                if (col + 1 < m) {
                    col++;
                } else {
                    ud = 0;
                    row++;
                }
            } else {
                if (col - 1 >= 0) {
                    col--;
                } else {
                    ud = 1;
                    row++;
                }
            }
        }
    }
}