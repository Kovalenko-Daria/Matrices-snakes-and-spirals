#include "pattern.h"

int main() {
    int **matrix = NULL;
    int **result = NULL;
    int n, m;

    if (input(&matrix, &n, &m)) {
        printf("\n");
        sort_matrix(matrix, n, m);
        create_result(&result, n, m);
        printf("Vertical snake\n");
        sort_vertical(matrix, n, m, result);
        output(result, n, m);
        printf("\n\n");
        printf("Horizontal snake\n");
        sort_horizontal(matrix, n, m, result);
        output(result, n, m);
        if (n == m) {
            printf("\n\n");
            printf("Clockwise spiral to center\n");
            sort_clockwise_to_center(matrix, n, result);
            output(result, n, m);
            printf("\n\n");
            printf("Counterclockwise spiral to center\n");
            sort_counterclockwise_to_center(matrix, n, result);
            output(result, n, m);
            printf("\n\n");
            printf("Clockwise spiral from center\n");
            sort_clockwise_from_center(matrix, n, result);
            output(result, n, m);
            printf("\n\n");
            printf("Couterclockwise spiral from center\n");
            sort_counterclockwise_from_center(matrix, n, result);
            output(result, n, m);
        }
        free(result);
    } else {
        printf("Error in input");
    }
    if (matrix) {
        free(matrix);
    }
    return 0;
}