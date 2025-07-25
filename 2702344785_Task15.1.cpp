#include<stdio.h>

int main(){
	
    int i;
	int N;

    printf("Masukkan bilangan N: "); // N untuk menentukan batas
    scanf("%d", &N);
    for(i=1; i<=N; i++){
        if(i%2 != 0){
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}

