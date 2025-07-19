#include<stdio.h>

void conBinary(int n){
    if(n==0)return;
    conBinary(n/2);
    printf("%d", n%2);
}

int main(){
    int T, N;
    scanf("%d", &T);

    for(int i=1; i<=T; i++){
        scanf("%d", &N);
        printf("Case #%d: ", i);
        if(N==0){
            printf("0");
        } 
		else{
            conBinary(N);
        }
        printf("\n");
        
    }
    return 0;
    
}

