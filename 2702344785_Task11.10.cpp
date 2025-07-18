#include<stdio.h>

int main(){
	
    int n;
    
    printf("Input N: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        printf("%d ", (i%7) + 1);
    }

    return 0;
}
