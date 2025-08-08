#include<stdio.h>

int main(){
    FILE *src = fopen("test.c", "r");
    FILE *dest = fopen("try.c", "w");

    if(src==NULL || dest==NULL){
        printf("Gagal membuka file!\n");
        return 1;
    }

    char ch;
    while((ch=fgetc(src))!=EOF){
        fputc(ch, dest);
    }

    printf("File berhasil dicopy.\n");

    fclose(src);
    fclose(dest);
    return 0;
}

