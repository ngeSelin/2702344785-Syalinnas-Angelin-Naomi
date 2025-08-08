#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char tanggal[11];
    int day, month, year;
    int current_year = 2025;
    int age;

    int above_51 = 0;
    int between_44_51 = 0;
    int between_36_43 = 0;
    int between_28_35 = 0;
    int below_28 = 0;

    fp = fopen("birth.txt", "r");
    if(fp==NULL){
        printf("File tidak bisa dibuka!\n");
        return 1;
    }

    while(fscanf(fp, "%d/%d/%d", &day, &month, &year)==3){
        if(year<25){
            year += 2000;
        }
		else{
            year += 1900;
        }

        age = current_year-year;

        if(age>51){
            above_51++;
        }
		else if(age>=44 && age<=51){
            between_44_51++;
        }
		else if(age>=36 && age<=43){
            between_36_43++;
        }
		else if(age>=28 && age<=35){
            between_28_35++;
        }
		else{
            below_28++;
        }
    }

    fclose(fp);

    printf("Jumlah karyawan:\n");
    printf("Usia > 51       : %d\n", above_51);
    printf("Usia 44 - 51    : %d\n", between_44_51);
    printf("Usia 36 - 43    : %d\n", between_36_43);
    printf("Usia 28 - 35    : %d\n", between_28_35);
    printf("Usia < 28       : %d\n", below_28);

    return 0;
}

