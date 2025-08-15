#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define FILE_NAME "crate_djpanda.csv"
#define MAX_SONGS 500

typedef struct {
    char id[15];     
    char judul[50];
    char artis[50];
    int  bpm;          
    int  rating;        
    int  play;       
} Lagu;

typedef int (*Comparator)(const Lagu*, const Lagu*);

Lagu songs[MAX_SONGS];
int nSongs = 0;

void trim_newline(char *s){
    size_t n = strlen(s);
    if(n && s[n-1]=='\n') s[n-1] = '\0';
}
void strip_pipes(char *s){ 
    for(; *s; ++s) if(*s=='|') *s='/';
}
void readLine(const char *prompt, char *buf, size_t sz){
    printf("%s", prompt);
    if(!fgets(buf, (int)sz, stdin)){ buf[0]='\0'; return; }
    trim_newline(buf);
    strip_pipes(buf);
}
long readInt(const char *prompt, long mn, long mx){
    char tmp[128], *end;
    long v;
    for(;;){
        printf("%s", prompt);
        if(!fgets(tmp, sizeof(tmp), stdin)) { puts("Input error."); continue; }
        v = strtol(tmp, &end, 10);
        if(end==tmp || (*end!='\n' && *end!='\0')){
            puts("Masukkan angka yang valid."); continue;
        }
        if(mn!=mx){ 
            if(v<mn || v>mx){ printf("Masukkan rentang %ld..%ld.\n", mn, mx); continue; }
        }
        return v;
    }
}
void toLowerStr(const char *src, char *dst){
    while(*src){ *dst++ = (char)tolower((unsigned char)*src++); }
    *dst = '\0';
}
bool containsIgnoreCase(const char *hay, const char *needle){
    char a[256], b[256];
    toLowerStr(hay, a);
    toLowerStr(needle, b);
    return strstr(a, b) != NULL;
}
void pressEnter(){
    printf("\n(Enter untuk lanjut)");
    int c; while((c=getchar())!='\n' && c!=EOF){}
}

void saveToFile(){
    FILE *fp = fopen(FILE_NAME, "w");
    if(!fp){ perror("Gagal simpan"); return; }
    for(int i=0;i<nSongs;i++){
        fprintf(fp, "%s|%s|%s|%d|%d|%d\n",
            songs[i].id, songs[i].judul, songs[i].artis,
            songs[i].bpm, songs[i].rating, songs[i].play);
    }
    fclose(fp);
    puts("Data tersimpan ke " FILE_NAME ".");
}
void loadFromFile(){
    FILE *fp = fopen(FILE_NAME, "r");
    if(!fp){ puts("Belum ada file crate, mulai baru."); return; }
    char line[256];
    nSongs = 0;
    while(fgets(line, sizeof(line), fp)){
        trim_newline(line);
        if(line[0]=='\0') continue;
        Lagu s; memset(&s, 0, sizeof(s));
        char *tok = strtok(line, "|");
        if(!tok) continue; strncpy(s.id, tok, sizeof(s.id)-1);
        tok = strtok(NULL, "|"); if(!tok) continue; strncpy(s.judul, tok, sizeof(s.judul)-1);
        tok = strtok(NULL, "|"); if(!tok) continue; strncpy(s.artis, tok, sizeof(s.artis)-1);
        tok = strtok(NULL, "|"); if(!tok) continue; s.bpm = (int)strtol(tok, NULL, 10);
        tok = strtok(NULL, "|"); if(!tok) continue; s.rating = (int)strtol(tok, NULL, 10);
        tok = strtok(NULL, "|"); if(!tok) continue; s.play   = (int)strtol(tok, NULL, 10);
        if(nSongs < MAX_SONGS) songs[nSongs++] = s;
    }
    fclose(fp);
    printf("Memuat %d lagu dari file.\n", nSongs);
}

int findById(const char *id){
    for(int i=0;i<nSongs;i++){
        if(strcmp(songs[i].id, id)==0) return i;
    }
    return -1;
}
void listSongs(){
    if(nSongs==0){ puts("Belum ada lagu."); return; }
    printf("\n%-8s | %-26s | %-20s | %4s | %6s | %5s\n", "ID", "Judul", "Artis", "BPM", "Rating", "Play");
    printf("-------------------------------------------------------------------------------\n");
    for(int i=0;i<nSongs;i++){
        printf("%-8s | %-26s | %-20s | %4d | %6d | %5d\n",
            songs[i].id, songs[i].judul, songs[i].artis,
            songs[i].bpm, songs[i].rating, songs[i].play);
    }
}
void addSong(){
    if(nSongs >= MAX_SONGS){ puts("Kapasitas penuh."); return; }
    Lagu s;
    readLine("ID (unik): ", s.id, sizeof(s.id));
    if(s.id[0]=='\0'){ puts("ID tidak boleh kosong."); return; }
    if(findById(s.id)!=-1){ puts("ID sudah dipakai."); return; }
    readLine("Judul     : ", s.judul, sizeof(s.judul));
    readLine("Artis     : ", s.artis, sizeof(s.artis));
    s.bpm    = (int)readInt("BPM (50..220): ", 50, 220);
    s.rating = (int)readInt("Rating (1..5): ", 1, 5);
    s.play   = 0;
    songs[nSongs++] = s;
    puts("Lagu ditambahkan.");
}
void editSong(){
    char id[16];
    readLine("ID lagu yang diedit: ", id, sizeof(id));
    int idx = findById(id);
    if(idx==-1){ puts("ID tidak ditemukan."); return; }
    Lagu *p = &songs[idx];
    char buf[64];
    printf("Edit '%s' - %s (ID:%s)\n", p->judul, p->artis, p->id);
    readLine("Judul baru (kosong=skip): ", buf, sizeof(buf));
    if(buf[0]) { strncpy(p->judul, buf, sizeof(p->judul)-1); p->judul[sizeof(p->judul)-1]='\0'; }
    readLine("Artis baru (kosong=skip): ", buf, sizeof(buf));
    if(buf[0]) { strncpy(p->artis, buf, sizeof(p->artis)-1); p->artis[sizeof(p->artis)-1]='\0'; }
    long v = readInt("BPM baru (-1=skip): ", -1, 10000);
    if(v>=0) p->bpm = (int)v;
    v = readInt("Rating baru (-1=skip): ", -1, 100);
    if(v>=0) { if(v<1||v>5) puts("Rating harus 1..5, diabaikan."); else p->rating=(int)v; }
    puts("Lagu diperbarui.");
}
void deleteSong(){
    char id[16];
    readLine("ID lagu yang dihapus: ", id, sizeof(id));
    int idx = findById(id);
    if(idx==-1){ puts("ID tidak ditemukan."); return; }
    for(int i=idx;i<nSongs-1;i++) songs[i]=songs[i+1];
    nSongs--;
    puts("Lagu dihapus.");
}
void playSong(){
    char id[16];
    readLine("ID lagu yang diputar: ", id, sizeof(id));
    int idx = findById(id);
    if(idx==-1){ puts("ID tidak ditemukan."); return; }
    songs[idx].play++;
    printf("Now Playing: %s - %s | BPM %d | Rating %d | Total Play %d\n",
           songs[idx].artis, songs[idx].judul, songs[idx].bpm, songs[idx].rating, songs[idx].play);
}

void searchSongs(){
    if(nSongs==0){ puts("Belum ada lagu."); return; }
    puts("Cari berdasarkan:");
    puts("1) ID (tepat)");
    puts("2) Judul (mengandung)");
    puts("3) Artis (mengandung)");
    puts("4) BPM range");
    int p = (int)readInt("Pilih: ", 1, 4);
    if(p==1){
        char id[16]; readLine("Masukkan ID: ", id, sizeof(id));
        int idx = findById(id);
        if(idx==-1) puts("Tidak ketemu.");
        else {
            Lagu *x = &songs[idx];
            printf("Ketemu: %s | %s | %s | BPM %d | Rating %d | Play %d\n",
                   x->id, x->judul, x->artis, x->bpm, x->rating, x->play);
        }
    } else if(p==2){
        char key[64]; readLine("Kata kunci judul: ", key, sizeof(key));
        int hit=0;
        for(int i=0;i<nSongs;i++){
            if(containsIgnoreCase(songs[i].judul, key)){
                if(hit==0) puts("Hasil:");
                printf(" - %s | %s | %s | BPM %d | Rating %d | Play %d\n",
                    songs[i].id, songs[i].judul, songs[i].artis, songs[i].bpm, songs[i].rating, songs[i].play);
                hit++;
            }
        }
        if(hit==0) puts("Tidak ada yang cocok.");
    } else if(p==3){
        char key[64]; readLine("Kata kunci artis: ", key, sizeof(key));
        int hit=0;
        for(int i=0;i<nSongs;i++){
            if(containsIgnoreCase(songs[i].artis, key)){
                if(hit==0) puts("Hasil:");
                printf(" - %s | %s | %s | BPM %d | Rating %d | Play %d\n",
                    songs[i].id, songs[i].judul, songs[i].artis, songs[i].bpm, songs[i].rating, songs[i].play);
                hit++;
            }
        }
        if(hit==0) puts("Tidak ada yang cocok.");
    } else {
        int lo = (int)readInt("BPM min: ", 0, 10000);
        int hi = (int)readInt("BPM max: ", 0, 10000);
        if(lo>hi){ int t=lo; lo=hi; hi=t; }
        int hit=0;
        for(int i=0;i<nSongs;i++){
            if(songs[i].bpm>=lo && songs[i].bpm<=hi){
                if(hit==0) puts("Hasil:");
                printf(" - %s | %s | %s | BPM %d | Rating %d | Play %d\n",
                    songs[i].id, songs[i].judul, songs[i].artis, songs[i].bpm, songs[i].rating, songs[i].play);
                hit++;
            }
        }
        if(hit==0) puts("Tidak ada yang cocok.");
    }
}

int cmpJudulAsc(const Lagu* a, const Lagu* b){ return strcmp(a->judul, b->judul); }
int cmpArtisAsc(const Lagu* a, const Lagu* b){ return strcmp(a->artis, b->artis); }
int cmpBpmAsc(const Lagu* a, const Lagu* b){ return (a->bpm > b->bpm) - (a->bpm < b->bpm); }
int cmpBpmDesc(const Lagu* a, const Lagu* b){ return (b->bpm > a->bpm) - (b->bpm < a->bpm); }
int cmpRatingDesc(const Lagu* a, const Lagu* b){ return (b->rating > a->rating) - (b->rating < a->rating); }
int cmpPlayDesc(const Lagu* a, const Lagu* b){ return (b->play > a->play) - (b->play < a->play); }

void selection_sort(Lagu arr[], int n, Comparator cmp){
    for(int i=0;i<n-1;i++){
        int minIdx = i;
        for(int j=i+1;j<n;j++){
            if(cmp(&arr[j], &arr[minIdx]) < 0) minIdx = j;
        }
        if(minIdx!=i){ Lagu t=arr[i]; arr[i]=arr[minIdx]; arr[minIdx]=t; }
    }
}
void sortSongs(){
    if(nSongs==0){ puts("Belum ada lagu."); return; }
    puts("Urutkan berdasarkan:");
    puts("1) Judul (A-Z)");
    puts("2) Artis (A-Z)");
    puts("3) BPM (naik)");
    puts("4) BPM (turun)");
    puts("5) Rating (tertinggi)");
    puts("6) Paling sering diputar");
    int p = (int)readInt("Pilih: ", 1, 6);
    Comparator cmp = NULL;
    switch(p){
        case 1: cmp = cmpJudulAsc; break;
        case 2: cmp = cmpArtisAsc; break;
        case 3: cmp = cmpBpmAsc; break;
        case 4: cmp = cmpBpmDesc; break;
        case 5: cmp = cmpRatingDesc; break;
        case 6: cmp = cmpPlayDesc; break;
    }
    selection_sort(songs, nSongs, cmp);
    puts("Data telah diurutkan.");
    listSongs();
}

void reportTopPlayed(){
    if(nSongs==0){ puts("Belum ada lagu."); return; }
    Lagu tmp[MAX_SONGS];
    for(int i=0;i<nSongs;i++) tmp[i]=songs[i];
    selection_sort(tmp, nSongs, cmpPlayDesc);

    int k = (int)readInt("Tampilkan TOP berapa? ", 1, 100000);
    if(k>nSongs) k=nSongs;

    printf("\nTOP %d Paling Sering Diputar:\n", k);
    printf("%-8s | %-26s | %-20s | %4s | %6s\n", "ID", "Judul", "Artis", "BPM", "Play");
    printf("---------------------------------------------------------------\n");
    for(int i=0;i<k;i++){
        printf("%-8s | %-26s | %-20s | %4d | %6d\n",
               tmp[i].id, tmp[i].judul, tmp[i].artis, tmp[i].bpm, tmp[i].play);
    }
}

void printMenu(){
    puts("\n=== DJ PANDA CRATE MANAGER ===");
    puts("1. Tambah lagu");
    puts("2. Tampilkan semua lagu");
    puts("3. Edit lagu");
    puts("4. Hapus lagu");
    puts("5. Putar lagu (+1 play)");
    puts("6. Cari lagu");
    puts("7. Urutkan lagu");
    puts("8. Laporan TOP play");
    puts("9. Simpan ke file");
    puts("10. Muat dari file");
    puts("0. Keluar");
}

int main(void){
    loadFromFile();
    for(;;){
        printMenu();
        int p = (int)readInt("Pilih menu: ", -100000, 100000);
        switch(p){
            case 1: 
			addSong(); 
			break;
            case 2: 
			listSongs(); 
			break;
            case 3: 
			editSong(); 
			break;
            case 4: 
			deleteSong(); 
			break;
            case 5: 
			playSong(); 
			break;
            case 6: 
			searchSongs(); 
			break;
            case 7: 
			sortSongs(); 
			break;
            case 8: 
			reportTopPlayed(); 
			break;
            case 9: 
			saveToFile(); 
			break;
            case 10: 
			loadFromFile(); 
			break;
            case 0:
                saveToFile();
                puts("\nByeee....");
                return 0;
            default:
                puts("Pilihan tidak valid.");
        }
        pressEnter();
    }
}

