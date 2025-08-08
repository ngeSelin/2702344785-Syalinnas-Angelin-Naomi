#include<stdio.h>

struct Mhs{
    char name[20];
    int nim;
    float gpa;
};

int main(){
    FILE *fp;
    struct Mhs m[5];
    int i;

    fp = fopen("Mhs.dat", "wb");
    if(fp==NULL){
        printf("Cannot open file!\n");
        return 1;
    }

    for(i=0; i<5; i++){
        printf("Student %d\n", i+1);
        printf("Name: ");
        scanf("%s", m[i].name);
        printf("NIM: ");
        scanf("%d", &m[i].nim);
        printf("GPA: ");
        scanf("%f", &m[i].gpa);

        fwrite(&m[i], sizeof(struct Mhs), 1, fp);
    }

    fclose(fp);
    return 0;
}

