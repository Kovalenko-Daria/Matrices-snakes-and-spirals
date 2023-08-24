#ifndef PATTERN_H
#define PATTERN_H

#include <stdio.h>
#include <stdlib.h>

#define MIN_INT -2147483647

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void sort_clockwise_to_center(int **matrix, int n, int **result_matrix);
void sort_counterclockwise_to_center(int **matrix, int n, int **result_matrix);
void sort_clockwise_from_center(int **matrix, int n, int **result_matrix);
void sort_counterclockwise_from_center(int **matrix, int n, int **result_matrix);
void napr1(int** result_matrix, int n, int* row, int* col, int* ud, int* pl, int* napr);
void napr2(int** result_matrix, int n, int* row, int* col, int* ud, int* pl, int* napr);

void set_min(int** result_matrix, int n);

int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int read_size(int *rows, int *columns);
int input_row(int *row, int len);
void print_array(int *array, int length);
void create_result(int ***matrix, int n, int m);
void sort_matrix(int **matrix, int n, int m);

#endif