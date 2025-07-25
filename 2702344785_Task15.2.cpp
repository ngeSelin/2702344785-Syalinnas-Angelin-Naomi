#include<stdio.h>

int main(){
	
    int num;

    printf("Masukkan angka: ");
    scanf("%d", &num);

    if(num>0){
        printf("Angka ini adalah bilangan positif.\n");
    }
	else if(num<0){
        printf("Angka ini adalah bilangan negatif.\n");
    }
	else{
        printf("Angka ini adalah nol.\n");
    }

    return 0;
}

