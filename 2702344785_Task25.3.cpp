#include<stdio.h>
#include<string.h>

void bubbleSort(char arr[][20], int n){
    char temp[20];
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(strcmp(arr[j], arr[j+1])>0){
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

int main(){
    char nama[10][20] = {
        "Ali", "Ani", "Tono", "Bayu", "Amir", "Ani", "Budi", "Tini", "Ucok", "Paijo"
    };
    
    printf("Before sorting: %s\n", nama);
    for(int i=0; i<10; i++){
        printf("%s\n", nama[i]);
    }
    printf("\n");

    bubbleSort(nama, 10);

    printf("After sorting:\n");
    for(int i=0; i<10; i++){
        printf("%s\n", nama[i]);
    }

    return 0;
}

