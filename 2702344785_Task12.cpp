#include <stdio.h>

int main(){
	
    char lulus = 't';
    int langkah = 1;
    char hal[100];

    printf("Hal-hal yang harus dilakukan agar lulus Mata kuliah ini...\n");

    while (lulus!='y' && lulus!='Y'){
        printf("\nLangkah ke-%d:\n", langkah);
        printf("Apa yang harus kamu lakukan? ");

        getchar();

        fgets(hal, sizeof(hal), stdin);

        printf("Apakah sudah lulus? (y/t): ");
        scanf(" %c", &lulus); 
        langkah++;
    }

    printf("\nSelamat! Kamu akhirnya lulus Mata Kuliah ini!\n");

    return 0;
}

