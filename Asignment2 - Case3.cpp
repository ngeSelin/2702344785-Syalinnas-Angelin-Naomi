#include<stdio.h>
#include<string.h>

int main(){
	
	// nama file dan extension diubah karena tidak bisa menggunakan .in
    FILE *fp = fopen("testdata2.txt", "r");
    int T;
    fscanf(fp, "%d", &T);

    for(int t=1; t<=T; t++){
        int N;
        fscanf(fp, "%d", &N);
        
        char names[N][31];
        char search[31];
        int found = -1;

        for(int i=0; i<N; i++){
            fscanf(fp, "%s", names[i]);
        }

        fscanf(fp, "%s", search);

        for(int i=0; i<N; i++){
            if(strcmp(names[i], search)==0){
                found = i+1;
                break;
            }
        }

        if(found==-1){
            printf("Case #%d: Not found\n", t);
        }
		else{
            printf("Case #%d: %d\n", t, found);
    	}
    }

    fclose(fp);
    return 0;
}

