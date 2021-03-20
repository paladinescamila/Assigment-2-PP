#include<stdio.h>    
#include<stdlib.h>  

int main(){  
    int a[10][10],b[10][10],mul[10][10],r,c,i,j,k;    
    system("cls");  
    printf("Rows: ");    
    scanf("%d",&r);
    printf("Columns: ");    
    scanf("%d",&c);
    printf("First matrix element: \n");    
    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++) scanf("%d",&a[i][j]);
    }
    
    printf("Second matrix element: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++) scanf("%d",&b[i][j]);    
    }
    
    printf("Multiply of the matrix: \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            mul[i][j]=0;
            for(k=0;k<c;k++) mul[i][j]+=a[i][k]*b[k][j];
        }
    }

    for(i=0;i<r;i++){
        for(j=0;j<c;j++) printf("%d\t",mul[i][j]);
        printf("\n");    
    }

    return 0;
} 