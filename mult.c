#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 100

// Build an array of random numbers with the given dimensions
void buildMatrix(int matrix[][N], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % M;
   }
}

// Print the matrix
void printMatrix(int matrix[][N], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    // int num_threads = omp_get_max_threads(), tid;
    int A[N][N], B[N][N], C[N][N], r1, c1, r2, c2;

    printf("Rows and columns matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Rows and columns matrix 2: ");
    scanf("%d %d", &r2, &c2);
    
    if (c1 == r2){
        printf("\nMATRIX 1\n");
        buildMatrix(A, r1, c1);
        printMatrix(A, r1, c1);
        printf("\nMATRIX 2\n");
        buildMatrix(B, r2, c2);
        printMatrix(B, r2, c2);
        
        for (int i = 0; i < r1; i++){
            for (int j = 0; j < c2; j++)
                C[i][j] = 0;
        }
        #pragma omp parallel for
        for (int i = 0; i < r1; i++){
            for (int j = 0; j < c2; j++){
                for (int k = 0; k < c1; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }
        }

        printf("\nRESULT\n");
        printMatrix(C, r1, c2);
    }
    else{
        printf("The number of columns in matrix 1 must be the same as the number of rows in matrix 2.\n");
    }
    return 0;
}