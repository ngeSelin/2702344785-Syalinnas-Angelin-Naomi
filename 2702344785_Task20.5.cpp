#include<stdio.h>

struct studentScore{
    char nim[11];
    char name[30];
    char subjectCode[5];
    int sks;
    char grade;
};

int main(){
    struct studentScore s;

    printf("NIM: ");
    scanf(" %[^\n]", s.nim);
    printf("Nama: ");
    scanf(" %[^\n]", s.name);
    printf("Kode Mata Kuliah: ");
    scanf(" %[^\n]", s.subjectCode);
    printf("SKS: ");
    scanf("%d", &s.sks);
    printf("Grade (A-E): ");
    scanf(" %c", &s.grade);

    printf("\n=====Display Grade=====\n");
    printf("NIM		: %s\n", s.nim);
    printf("Nama		: %s\n", s.name);
    printf("Kode Mata Kuliah: %s\n", s.subjectCode);
    printf("SKS		: %d\n", s.sks);
	printf("Grade		: %c\n", s.grade);
	
    return 0;
}

