#include<stdio.h>
#include<string.h>

struct Song{
    char title_song[50];
    char singer[50];
    int duration;
};

void merge(struct Song arr[], int left, int mid, int right){
    int n1 = mid- left+1;
    int n2 = right-mid;

    struct Song L[n1], R[n2];

    for(int i=0; i<n1; i++){
        L[i] = arr[left+i];
	}
    for(int j=0; j<n2; j++){
		R[j] = arr[mid+1+j];	
	}

    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(L[i].duration<=R[j].duration){
            arr[k++]=L[i++];
        } 
		else{
            arr[k++]=R[j++];
        }
    }

    while(i<n1){
        arr[k++]=L[i++];
	}
    while(j<n2){
		arr[k++]=R[j++];
	}
}

void mergeSort(struct Song arr[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void printSongs(struct Song arr[], int n){
    for(int i=0; i<n; i++){
        printf("%-25s %-20s %d:%02d\n", arr[i].title_song, arr[i].singer, arr[i].duration/60,arr[i].duration%60);
    }
}

int main(){
    int n;
    printf("Enter the number of songs: ");
    scanf("%d", &n);
    getchar(); 

    struct Song playlist[n];

    for(int i=0; i<n; i++){
        printf("\nSong %d:\n", i+1);

        printf("Enter song title: ");
        fgets(playlist[i].title_song, sizeof(playlist[i].title_song), stdin);
        playlist[i].title_song[strcspn(playlist[i].title_song, "\n")]=0; 

        printf("Enter singer name: ");
        fgets(playlist[i].singer, sizeof(playlist[i].singer), stdin);
        playlist[i].singer[strcspn(playlist[i].singer, "\n")] = 0;

        printf("Enter duration (in seconds): ");
        scanf("%d", &playlist[i].duration);
        getchar();
    }

    printf("\nPlaylist before sorting:\n");
    printSongs(playlist, n);

    mergeSort(playlist, 0, n-1);

    printf("\nPlaylist after sorting (ascending):\n");
    printSongs(playlist, n);

    return 0;
}

