#include<stdio.h>

struct Mhs{
    char name[20];
    int nim;
    float gpa;
};

int main(){
    FILE *fp;
    struct Mhs m;

    fp = fopen("Mhs.dat", "rb");
    if(fp==NULL){
        printf("Cannot open file!\n");
        return 1;
    }

    printf("NIM\t\tName\t\tGPA\n");
    printf("----\t\t----\t\t----\n");

    while(fread(&m, sizeof(struct Mhs), 1, fp)==1){
        printf("%d\t\t%s\t\t%.2f\n", m.nim, m.name, m.gpa);
    }

    fclose(fp);
    return 0;
}

