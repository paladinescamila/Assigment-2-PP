#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 500
#define M 100


// Build an array of random numbers with the given dimensions
void buildMatrix(int matrix[N][N], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % M;
   }
}


// Print a matrix
void printMatrix(int matrix[N][N], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}


// Multiply two matrices
double multiplyMatrices(int A[N][N], int B[N][N], int C[N][N], int r1, int c1, int r2, int c2){
    double t_start, t_wall_clock;
    // omp_set_nested(1);
    t_start = omp_get_wtime();

    // #pragma omp parallel for
    for (int i = 0; i < r1; i++){
        // #pragma omp parallel for
        for (int j = 0; j < c2; j++){
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    t_wall_clock = omp_get_wtime() - t_start;
    return t_wall_clock;
}


// Tests with different dimensions of C
int main(int argc, char *argv[]){
    int A[N][N], B[N][N], C[N][N], max, iter;
    scanf("%d %d", &max, &iter);

    for (int i = iter; i <= max; i += iter){
        buildMatrix(A, i, i);
        buildMatrix(B, i, i);
        double t_wall_clock = multiplyMatrices(A, B, C, i, i, i, i);
        printf("Time (N = %d): %f\n", i, t_wall_clock);
    }

    
    return 0;
}