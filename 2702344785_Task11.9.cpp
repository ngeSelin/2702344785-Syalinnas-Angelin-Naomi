#include<stdio.h>

int main(){
	
    int pilihan;
    int i;

    printf("Program Menampilkan Bilangan Ganjil dari 11 sampai 188\n");
    printf("Pilih metode:\n");
    printf("1. Menggunakan for\n");
    printf("2. Menggunakan while\n");
    printf("3. Menggunakan do-while\n");
    printf("Masukkan pilihan (1/2/3): ");
    scanf("%d", &pilihan);

    switch (pilihan){
        case 1:
            printf("\nMetode for:\n");
            for (i=11; i<=188; i+=2){
                printf("%d ", i);
            }
            break;

        case 2:
            printf("\nMetode while:\n");
            i = 11;
            while (i<=188) {
                printf("%d ", i);
                i+=2;
            }
            break;

        case 3:
            printf("\nMetode do-while:\n");
            i = 11;
            do {
                printf("%d ", i);
                i+=2;
            } 
			while (i<=188);
            break;

        default:
            printf("Pilihan tidak valid.\n");
    }

    return 0;
}

