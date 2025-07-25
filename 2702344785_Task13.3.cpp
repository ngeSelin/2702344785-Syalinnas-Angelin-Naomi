#include<stdio.h>

int main(){
	
    int A[4][4]={
        {3, 4, 5, 5},
        {5, 6, 7, 9},
        {1, 7, 11, 10},
        {2, 8, 9, 4}
    };

    int B[4][4]={
        {1, 2, 3, 4},
        {8, 7, 6, 5},
        {9, 10, 11, 2},
        {6, 5, 4, 3}
    };

    int C[4][4];
    int i, j;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            C[i][j] = A[i][j]+B[i][j];
        }
    }
    
    printf("Hasil Matriks:\n");
    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

