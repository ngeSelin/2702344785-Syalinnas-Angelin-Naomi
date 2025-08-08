#include<stdio.h>

int main(){
    if(remove("test.c")==0){
        printf("File berhasil dihapus.\n");
    }
	else{
        printf("Gagal menghapus file.\n");
    }
    
    return 0;
}

