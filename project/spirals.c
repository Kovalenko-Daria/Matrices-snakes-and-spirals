#include "pattern.h"

void sort_clockwise_to_center(int **matrix, int n, int **result_matrix) {
    set_min(result_matrix, n);
    int row = 0, col = 0, ud = 1, pl = 1, napr = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result_matrix[row][col] = matrix[i][j];
            napr1(result_matrix, n, &row, &col, &ud, &pl, &napr);
    }
    }
}

void sort_counterclockwise_to_center(int **matrix, int n, int **result_matrix){
    set_min(result_matrix, n);
    int row = 0, col = 0, ud = 1, pl = 1, napr = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result_matrix[row][col] = matrix[i][j];
            napr2(result_matrix, n, &row, &col, &ud, &pl, &napr);
    }
    }
}

void sort_clockwise_from_center(int **matrix, int n, int **result_matrix){
    set_min(result_matrix, n);
    int row = 0, col = 0, ud = 1, pl = 1, napr = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            result_matrix[row][col] = matrix[i][j];
            napr2(result_matrix, n, &row, &col, &ud, &pl, &napr);
    }
    }
}

void sort_counterclockwise_from_center(int **matrix, int n, int **result_matrix){
    set_min(result_matrix, n);
    int row = 0, col = 0, ud = 1, pl = 1, napr = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            result_matrix[row][col] = matrix[i][j];
            napr1(result_matrix, n, &row, &col, &ud, &pl, &napr);
    }
    }
}

void napr1(int** result_matrix, int n, int* row, int* col, int* ud, int* pl, int* napr) {
    if (*napr) {
                if (*pl){
                    if (*col + 1 < n && result_matrix[*row][*col + 1] == MIN_INT) {
                        (*col)++;
                    }
                    else {
                        *napr = 0;
                        *pl = 0;
                        (*row)++;
                    }
                }
                else {
                    if (*col - 1 >= 0 && result_matrix[*row][*col - 1] == MIN_INT) {
                        (*col)--;
                    }
                    else {
                        *napr = 0;
                        *pl = 1;
                        (*row)--;
                    }
                }
            }
            else {
                if (*ud){
                    if (*row + 1 < n && result_matrix[*row + 1][*col] == MIN_INT) {
                        (*row)++;
                    }
                    else {
                        *napr = 1;
                        *ud = 0;
                        (*col)--;
                    }
                }
                else {
                    if (*row - 1 >= 0 && result_matrix[*row - 1][*col] == MIN_INT) {
                        (*row)--;
                    }
                    else {
                        *napr = 1;
                        *ud = 1;
                        (*col)++;
                    }
                }
            }
}

void napr2(int** result_matrix, int n, int* row, int* col, int* ud, int* pl, int* napr) {
    if (*napr) {
                if (*pl){
                    if (*col + 1 < n && result_matrix[*row][*col + 1] == MIN_INT) {
                        (*col)++;
                    }
                    else {
                        *napr = 0;
                        *pl = 0;
                        (*row)--;
                    }
                }
                else {
                    if (*col - 1 >= 0 && result_matrix[*row][*col - 1] == MIN_INT) {
                        (*col)--;
                    }
                    else {
                        *napr = 0;
                        *pl = 1;
                        (*row)++;
                    }
                }
            }
            else {
                if (*ud){
                    if (*row + 1 < n && result_matrix[*row + 1][*col] == MIN_INT) {
                        (*row)++;
                    }
                    else {
                        *napr = 1;
                        *ud = 0;
                        (*col)++;
                    }
                }
                else {
                    if (*row - 1 >= 0 && result_matrix[*row - 1][*col] == MIN_INT) {
                        (*row)--;
                    }
                    else {
                        *napr = 1;
                        *ud = 1;
                        (*col)--;
                    }
                }
            }
}

void set_min(int** result_matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result_matrix[i][j] = MIN_INT;
    }
    }
}