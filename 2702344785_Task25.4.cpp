#include<stdio.h>
#include<string.h>

struct mhs {
    char nim[20]; 
    float gpa;
    char name[50];
};

void selectionSort(struct mhs arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if (arr[j].gpa<arr[minIdx].gpa ||
               (arr[j].gpa==arr[minIdx].gpa && strcmp(arr[j].name, arr[minIdx].name)<0)){
                minIdx = j;
            }
        }
        
        if(minIdx!=i){
            struct mhs tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
        }
    }
}

int main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar();

    struct mhs data[n];

    for(int i=0; i<n; i++){
        printf("\nStudent %d:\n", i + 1);

        printf("Enter NIM: ");
        fgets(data[i].nim, sizeof(data[i].nim), stdin);
        data[i].nim[strcspn(data[i].nim, "\n")] = 0;

        printf("Enter GPA: ");
        scanf("%f", &data[i].gpa);
        getchar();
        
        printf("Enter Name: ");
        fgets(data[i].name, sizeof(data[i].name), stdin);
        data[i].name[strcspn(data[i].name, "\n")] = 0;
    }

    selectionSort(data, n);

    printf("\nAfter Sorting:\n");
    for(int i=0; i<n; i++){
        printf("NIM: %s, GPA: %.2f, Name: %s\n", data[i].nim, data[i].gpa, data[i].name);
    }

    return 0;
}

