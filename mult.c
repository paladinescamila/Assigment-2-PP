#include <stdio.h>
#define N 10

// Get matrix elements
void getMatrix(int matrix[][N], int rows, int cols){
    for (int i = 0; i < rows; i++){
        printf("Row %d: ", i+1);
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
   }
}

// Matrix multiplication
void multiply(int one[][N], int two[][N], int ans[][N], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < cols2; j++)
            ans[i][j] = 0;
    }
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < cols2; j++){
            for (int k = 0; k < cols1; k++)
                ans[i][j] += one[i][k] * two[k][j];
      }
   }
}

// Print the matrix
void printMatrix(int ans[][N], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}

int main(){
    int one[N][N], two[N][N], ans[N][N], rows1, cols1, rows2, cols2;
    printf("Rows and columns matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Rows and columns matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    
    if (cols1 == rows2){
        printf("\nMATRIX 1\n");
        getMatrix(one, rows1, cols1);
        printf("\nMATRIX 2\n");
        getMatrix(two, rows2, cols2);
        
        multiply(one, two, ans, rows1, cols1, rows2, cols2);

        printf("\nRESULT\n");
        printMatrix(ans, rows1, cols2);
    }
    else{
        printf("The number of columns in matrix 1 must be the same as the number of rows in matrix 2.\n");
    }
    return 0;
}