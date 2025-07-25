#include<stdio.h>

void inputAngka(int *a, int *b){
    printf("Masukkan angka pertama: ");
    scanf("%d", a);
    printf("Masukkan angka kedua: ");
    scanf("%d", b);
}

int hitungJumlah(int a, int b){
    return a+b;
}

int hitungKali(int a, int b){
    return a*b;
}

int main(){
	
    int x, y, hasilPenjumlahan, hasilPerkalian;

    inputAngka(&x, &y);

    hasilPenjumlahan = hitungJumlah(x, y);
    hasilPerkalian = hitungKali(x, y);
    
    printf("\n");

    printf("Hasil penjumlahan: %d\n", hasilPenjumlahan);
    printf("Hasil perkalian: %d\n", hasilPerkalian);

    return 0;
}

