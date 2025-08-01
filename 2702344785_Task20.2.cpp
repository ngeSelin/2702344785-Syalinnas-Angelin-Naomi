#include<stdio.h>

struct Address{
    char street[30];
    int number;
    char city[20];
    char province[20];
};

struct DOB{
    int day;
    int month;
    int year;
};

struct Student{
    char studentNumber[15];
    char name[50];
    struct Address address;
    struct DOB birth;
};

int main(){
    struct Student students[5];

    printf("Input Data Mahasiswa\n");
    printf("=======================");

    for (int i = 0; i < 5; i++){
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("NIM: ");
        scanf(" %[^\n]", students[i].studentNumber);
        printf("Nama: ");
        scanf(" %[^\n]", students[i].name);
        printf("Alamat\n");
        printf("  Jalan: ");
        scanf(" %[^\n]", students[i].address.street);
        printf("  Nomor: ");
        scanf("%d", &students[i].address.number);
        printf("  Kota: ");
        scanf(" %[^\n]", students[i].address.city);
        printf("  Provinsi: ");
        scanf(" %[^\n]", students[i].address.province);
        printf("Tanggal Lahir (dd mm yyyy): ");
        scanf("%d %d %d", &students[i].birth.day, &students[i].birth.month, &students[i].birth.year);
    }

    printf("\n=== DATA MAHASISWA ===\n");

    for (int i = 0; i < 5; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("NIM           : %s\n", students[i].studentNumber);
        printf("Nama          : %s\n", students[i].name);
        printf("Alamat        : %s No. %d, %s - %s\n",
               students[i].address.street, students[i].address.number,
               students[i].address.city, students[i].address.province);
        printf("Tanggal lahir : %02d/%02d/%04d\n",
               students[i].birth.day, students[i].birth.month, students[i].birth.year);
    }

    return 0;
}

