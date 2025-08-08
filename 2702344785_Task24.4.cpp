#include<stdio.h>

struct Mhs{
    char name[20];
    int nim;
    float gpa;
};

int main(){
    FILE *fp;
    struct Mhs m;
    int i;

    fp = fopen("Mhs.dat", "ab");
    if(fp == NULL){
        printf("Cannot open file!\n");
        return 1;
    }

    for(i=0; i<5; i++){
        printf("New Student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", m.name);
        printf("NIM: ");
        scanf("%d", &m.nim);
        printf("GPA: ");
        scanf("%f", &m.gpa);

        fwrite(&m, sizeof(struct Mhs), 1, fp);
    }

    fclose(fp);
    return 0;
}

