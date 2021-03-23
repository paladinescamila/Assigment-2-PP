#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 500
#define M 10
#define lli long long int

void buildRandomMatrix(int matrix[N][N], lli rows, lli cols){
    for (lli i = 0; i < rows; i++){
        for (lli j = 0; j < cols; j++)
            matrix[i][j] = rand() % M;
   }
}

double multiplyMatrices(int A[N][N], int B[N][N], int C[N][N], lli r1, lli c1, lli r2, lli c2){
    double t_start, t_wall_clock;
    omp_set_nested(1);
    t_start = omp_get_wtime();
    #pragma omp parallel for
    for (lli i = 0; i < r1; i++){
        #pragma omp parallel for
        for (lli j = 0; j < c2; j++){
            C[i][j] = 0;
            for (lli k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    t_wall_clock = omp_get_wtime() - t_start;
    return t_wall_clock;
}

int main(int argc, char *argv[]){
    int A[N][N], B[N][N], C[N][N];
    lli max=500;
    buildRandomMatrix(A, max, max);
    buildRandomMatrix(B, max, max);
    double t_wall_clock = multiplyMatrices(A, B, C, max, max, max, max);
    printf("Time (N = %lld): %f\n", max, t_wall_clock);
    return 0;
}