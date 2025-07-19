#include<stdio.h>

int main(){
	
    int x;
    
    scanf("%d", &x);

    if(x % 2 == 0){
        printf("%d is even number\n", x);
    }
	else{
        printf("%d is odd number\n", x);
    }

    return 0;
}

