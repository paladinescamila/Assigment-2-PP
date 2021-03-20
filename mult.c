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
void printMatrix(int ans[][N], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            printf("%d\t", ans[i][j]);
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    int num_threads = omp_get_max_threads(), tid;
    int one[N][N], two[N][N], ans[N][N], rows1, cols1, rows2, cols2;

    printf("Rows and columns matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Rows and columns matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    
    if (cols1 == rows2){
        printf("\nMATRIX 1\n");
        buildMatrix(one, rows1, cols1);
        printMatrix(one, rows1, cols1);
        printf("\nMATRIX 2\n");
        buildMatrix(two, rows2, cols2);
        printMatrix(two, rows2, cols2);
        
        for (int i = 0; i < rows1; i++){
            for (int j = 0; j < cols2; j++)
                ans[i][j] = 0;
        }
        
        #pragma omp parallel private(tid){
            #pragma omp parallel for
            for (int i = 0; i < rows1; i++){
                for (int j = 0; j < cols2; j++){
                    for (int k = 0; k < cols1; k++)
                        ans[i][j] += one[i][k] * two[k][j];
                }
            }
        }

        printf("\nRESULT\n");
        printMatrix(ans, rows1, cols2);
    }
    else{
        printf("The number of columns in matrix 1 must be the same as the number of rows in matrix 2.\n");
    }
    return 0;
}