#include<stdio.h>
#include<ctype.h>

struct studentScore{
    char subjectCode[5];
    int sks;
    char grade;
};

int getWeight(char grade){
	grade = toupper(grade);
    switch (grade){
        case 'A': return 4;
        case 'B': return 3;
        case 'C': return 2;
        case 'D': return 1;
        case 'E': return 0;
        default: return 0;
    }
}

int main(){
    struct studentScore scores[5];
    int totalSKS = 0, totalNilai = 0;

    for (int i = 0; i < 5; i++){
        printf("\nMata Kuliah ke-%d\n", i + 1);
        printf("Kode MK: ");
        scanf(" %[^\n]", scores[i].subjectCode);
        printf("SKS: ");
        scanf("%d", &scores[i].sks);
        printf("Grade (A-E): ");
        scanf(" %c", &scores[i].grade);

        totalSKS += scores[i].sks;
        totalNilai += getWeight(scores[i].grade)*scores[i].sks;
    }

    float gpa = (float)totalNilai/totalSKS;
    printf("\n===== IPK SEMESTER 1 =====");
    printf("\nTotal SKS: %d\nTotal Nilai: %d\nIPK: %.2f\n", totalSKS, totalNilai, gpa);

    return 0;
}

