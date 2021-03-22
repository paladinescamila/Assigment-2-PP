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

// Print the matrix
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
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++)
            C[i][j] = 0;
    }
    t_start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    t_wall_clock = omp_get_wtime() - t_start;
    return t_wall_clock;
}

// Tests with different dimensions of C
int main(int argc, char *argv[]){
    int num_threads = omp_get_num_threads(), tid;
    int A[N][N], B[N][N], C[N][N], max;
    printf("Max size: ");
    scanf("%d", &max);

    for (int i=100; i<=max; i+=100){
        int  r1 = i, c1 = i, r2 = i, c2 = i;
        buildMatrix(A, r1, c1);
        buildMatrix(B, r2, c2);
        double t_wall_clock = multiplyMatrices(A, B, C, r1, c1, r2, c2);
        printf("Time (N = %d): %f\n", i, t_wall_clock);
    }

    
    return 0;
}