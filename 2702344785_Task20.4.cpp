#include<stdio.h>

struct ipkmhs{
    char nim[11];
    char name[30];
    float gpa;
};

int main(){
    struct ipkmhs mhs[5];

    for (int i = 0; i < 5; i++){
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("NIM: ");
        scanf(" %[^\n]", mhs[i].nim);
        printf("Nama: ");
        scanf(" %[^\n]", mhs[i].name);
        printf("GPA: ");
        scanf("%f", &mhs[i].gpa);
    }

    printf("\nMahasiswa dengan GPA >= 3.0:\n");
    for (int i = 0; i < 5; i++)
        if (mhs[i].gpa >= 3.0)
            printf("%s\n", mhs[i].name);

    printf("\nMahasiswa dengan GPA < 3.0:\n");
    for (int i = 0; i < 5; i++)
        if (mhs[i].gpa < 3.0)
            printf("%s\n", mhs[i].name);

    return 0;
}

