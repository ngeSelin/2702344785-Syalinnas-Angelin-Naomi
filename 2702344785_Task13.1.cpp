#include<stdio.h>

int main(){
	
    int arr[10];
	int i, max, min; 
	int res = 0;
    float avg;

    printf("Masukkan 10 angka:\n");
    for(i=0; i<10; i++){
        scanf("%d", &arr[i]);
        res += arr[i];
        if(i==0){
            max = min = arr[i];
        }
		else{
            if(arr[i]>max) max=arr[i];
            if(arr[i]<min) min=arr[i];
        }
    }
    avg = res/10.0;

    printf("Maksimum = %d\n", max);
    printf("Minimum  = %d\n", min);
    printf("Rata-rata = %.2f\n", avg);

    return 0;
}

