#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int number;
    char answer;
} Answer;

int compare(const void *a, const void *b){
    return ((Answer*)a)->number-((Answer*)b)->number;
}

int main(){
	// nama extension file diubah karena dengan .in tidak mendapatkan outputnya
    FILE *fp = fopen("testdata.txt", "r");
    if(fp==NULL) {
        printf("Gagal membuka file!");
        return 1;
    }

    int T;
    fscanf(fp, "%d", &T);

    for (int t=1; t<=T; t++){
    
        int N;
        fscanf(fp, "%d", &N);
        Answer answers[N];
        for (int i=0; i<N; i++){
            fscanf(fp, "%d. %c", &answers[i].number, &answers[i].answer);
        }

        qsort(answers, N, sizeof(Answer), compare);

        printf("Case #%d:\n", t);
        for (int i=0; i<N; i++) {
            printf("%d. %c\n", answers[i].number, answers[i].answer);
        }
    }

    fclose(fp);
    
    return 0;
}

