#include<stdio.h>

int isPrimeCalc(int X, int i){
    if(i==1) return 1;
    if(X%i==0) return 0;
    return isPrimeCalc(X, i-1);
}

int isPrime(int X){
    if(X<=1) return 0;
    return isPrimeCalc(X, X-1);
}

int main(){
	
    int T, X;
    scanf("%d", &T);
    
    for (int i=1; i<=T; i++){
        scanf("%d", &X);
        if(isPrime(X))
            printf("Case #%d: Prime Number\n", i);
        else
            printf("Case #%d: Not Prime Number\n", i);
    }
    return 0;
}

