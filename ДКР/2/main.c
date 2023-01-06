#include <stdio.h>
#include <stdlib.h>

#define N 4

void sort_matrix_rows(int a[N][N], int b[N][N]) {
    // Create an array of size N to store the sums of the rows
    int sums[N];

    // Calculate the sums of the rows of matrix a and store them in the sums array
    for (int i = 0; i < N; i++) {
        sums[i] = 0;
        for (int j = 0; j < N; j++) {
            sums[i] += a[i][j];
        }
    }

    // Sort the rows of matrix a based on the values in the sums array
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (sums[i] > sums[j]) {
                // Swap rows i and j in both matrices a and b
                for (int k = 0; k < N; k++) {
                  int temp = b[i][k];
                    b[i][k] = b[j][k];
                    b[j][k] = temp;
                }

                // Also swap the values in the sums array
                int temp = sums[i];
                sums[i] = sums[j];
                sums[j] = temp;
            }
        }
    }
}

int main() {
    // Initialize matrices a and b with random values
    int a[N][N], b[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % (7-3+1)+3;
            b[i][j] = a[i][j];
        }
    }

    // Sort the rows of the matrices
    sort_matrix_rows(a, b);

    // Print the matrices
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
