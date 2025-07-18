#include<stdio.h>

int main(){
	
    int pilihan;

    printf("PILIHAN STREAMING COMPUTER SCIENCE\n");
    printf("==================================\n");
    printf("1. Software Engineering\n");
    printf("2. Intelligent System\n");
    printf("3. Interactive Multimedia\n");
    printf("4. Database Technology\n");
    printf("5. Network Technology\n");

    printf("Masukkan pilihan streaming Anda (1-5): ");
    scanf("%d", &pilihan);

    switch(pilihan){
        case 1:
            printf("Anda memilih Streaming Software Engineering.\n");
            break;
        case 2:
            printf("Anda memilih Streaming Intelligent System.\n");
            break;
        case 3:
            printf("Anda memilih Streaming Interactive Multimedia.\n");
            break;
        case 4:
            printf("Anda memilih Streaming Database Technology.\n");
            break;
        case 5:
            printf("Anda memilih Streaming Network Technology.\n");
            break;
        default:
            printf("Pilihan tidak valid. Silahkan pilih antara angka 1-5.\n");
            break;
    }

    return 0;
}

