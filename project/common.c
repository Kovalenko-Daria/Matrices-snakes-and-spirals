#include "pattern.h"

int input(int ***matrix, int *n, int *m) {
    printf("Input amount of rows and columns: ");
    int f = read_size(n, m);
    if (f) {
        printf("Input matrix:\n");
        *matrix = malloc((*n) * (*m) * sizeof(int) + (*n) * sizeof(int *));
        int *start = (int *)(*matrix + (*n));
        for (int i = 0; i < (*n); i++) {
            (*matrix)[i] = start + (*m) * i;
            f = input_row((*matrix)[i], (*m));
            if (!f) {
                break;
            }
        }
    }
    return f;
}

int read_size(int *rows, int *columns) {
    int size[2];
    int f = input_row(size, 2);
    if (!f || size[0] <= 0 || size[1] <= 0) {
        f = 0;
    } else {
        *rows = size[0];
        *columns = size[1];
    }
    return f;
}

int input_row(int *row, int len) {
    char sym;
    float num;
    int amount = 0, f = 1;
    while (f) {
        if (scanf("%f%c", &num, &sym) == 2 && num == (int)num && (sym == 32 || sym == 10)) {
            if (amount <= len) {
                row[amount] = (int)num;
                amount++;
            } else {
                f = 0;
                break;
            }
        } else {
            f = 0;
            break;
        }
        if (sym == 10) {
            if (amount != len) {
                f = 0;
            }
            break;
        }
    }
    return f;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        print_array(matrix[i], m);
        if (i != n - 1) {
            printf("\n");
        }
    }
}

void print_array(int *array, int length) {
    for (int *p = array; p - array < length; p++) {
        printf("%d", *p);
        if (p - array != length - 1) {
            printf(" ");
        }
    }
}

void create_result(int ***result_matrix, int n, int m) {
    *result_matrix = malloc(n * m * sizeof(int) + n * sizeof(int *));
    int *start = (int *)(*result_matrix + n);
    for (int i = 0; i < n; i++) {
        (*result_matrix)[i] = start + m * i;
    }
}

void sort_matrix(int **matrix, int n, int m) {
    int *start = (int *)(matrix + n);
    int len = n * m;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (start[j] < start[i]) {
                int a = start[i];
                start[i] = start[j];
                start[j] = a;
            }
        }
    }
}