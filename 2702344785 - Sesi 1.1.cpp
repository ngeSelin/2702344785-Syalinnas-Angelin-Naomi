#include<stdio.h>

int main(){
	
	char name[50];
	int age;
	
	scanf("%s", name);
	scanf("%d", &age);
	
	printf("\n");
	printf("Siapa kamu? %s\n", name);
	printf("Umur kamu berapa? %d\n", age);
	
	return 0;
}
