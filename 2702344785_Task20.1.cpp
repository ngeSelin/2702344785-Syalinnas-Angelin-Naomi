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
    struct Student s;

    printf("Input Data Mahasiswa\n");
    printf("====================\n");
    printf("NIM: ");
    scanf(" %[^\n]", s.studentNumber);
    printf("Nama: ");
    scanf(" %[^\n]", s.name);
    printf("Alamat\n");
    printf("  Jalan: ");
    scanf(" %[^\n]", s.address.street);
    printf("  Nomor: ");
    scanf("%d", &s.address.number);
    printf("  Kota: ");
    scanf(" %[^\n]", s.address.city);
    printf("  Provinsi: ");
    scanf(" %[^\n]", s.address.province);
    printf("Tanggal Lahir (dd mm yyyy): ");
    scanf("%d %d %d", &s.birth.day, &s.birth.month, &s.birth.year);

    printf("\n=== DATA MAHASISWA ===\n");
    printf("NIM           : %s\n", s.studentNumber);
    printf("Nama          : %s\n", s.name);
    printf("Alamat        : %s No. %d, %s - %s\n",
           s.address.street, s.address.number,
           s.address.city, s.address.province);
    printf("Tanggal lahir : %02d/%02d/%04d\n",
           s.birth.day, s.birth.month, s.birth.year);

    return 0;
}

