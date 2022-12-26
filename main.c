#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct antrian{
    char plat[10];
    char jenis[10];
    struct antrian *next;
}; 

struct parkir{
    char plat[10];
    char jenis[10];
    struct parkir *next;
};

void tambahAntrian();
void tambahParkir();
void tampilAntrian();
void tampilParkir();
void hapusAntrian();
void hapusParkir();

struct antrian *head = NULL;
struct antrian *tail = NULL;
struct parkir *head2 = NULL;
struct parkir *tail2 = NULL;

int main(){
    int pilih;
    do{
        printf("1. Tambah Antrian\n");
        printf("2. Masuk Parkir\n");
        printf("3. Tampilkan Antrian\n");
        printf("4. Tampilkan Parkir\n");
        printf("5. Keluar Program\n");
        printf("6. Keluar Antrian\n");
        printf("7. Keluar Parkir\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        switch(pilih){
            case 1:
                tambahAntrian();
                break;
            case 2:
                tambahParkir();
                break;
            case 3:
                tampilAntrian();
                break;
            case 4:
                tampilParkir();
                break;
            case 5:
                printf("Keluar");
                return 0;
                break;
            case 6:
                hapusAntrian();
                break;
            case 7:
                hapusParkir();
                break;
            default:
                printf("Pilihan tidak ada");
        }
    }while(pilih != 5);
}

void tambahAntrian(){
    struct antrian *baru;
    baru = (struct antrian*)malloc(sizeof(struct antrian));
    printf("Masukkan Plat : ");
    fflush(stdin);
    gets(baru->plat);
    printf("Masukkan Jenis : ");
    fflush(stdin);
    gets(baru->jenis);
    baru->next = NULL;
    if(head == NULL){
        head = baru;
        tail = baru;
    }else{
        tail->next = baru;
        tail = baru;
    }
}

void tambahParkir(){
    // Menyambungkan antrian ke parkir
    // Jika tambah parkir, maka antrian pertama akan dihapus
    if (head == NULL){
        printf("Antrian Kosong!\n");
        return;
    }
    struct parkir *baru;
    baru = (struct parkir*)malloc(sizeof(struct parkir));
    strcpy(baru->plat, head->plat);
    strcpy(baru->jenis, head->jenis);
    baru->next = NULL;
    if(head2 == NULL){
        head2 = baru;
        tail2 = baru;
    }else{
        tail2->next = baru;
        tail2 = baru;
    }
    hapusAntrian();
}

void tampilAntrian(){
    struct antrian *bantu;
    bantu = head;
    if(bantu == NULL){
        printf("Antrian Kosong!\n");
    }else{
        while(bantu != NULL){
            printf("Plat : %s\n", bantu->plat);
            printf("Jenis : %s\n\n", bantu->jenis);
            bantu = bantu->next;
        }
    }
}

void tampilParkir(){
    struct parkir *bantu;
    bantu = head2;
    if(bantu == NULL){
        printf("Parkir Kosong!\n");
    }else{
        while(bantu != NULL){
            printf("Plat : %s\n", bantu->plat);
            printf("Jenis : %s\n\n", bantu->jenis);
            bantu = bantu->next;
        }
    }
}

void hapusAntrian(){
    struct antrian *hapus;
    hapus = head;
    if(hapus == NULL){
        printf("Antrian Kosong!\n");
    }else{
        head = hapus->next;
        free(hapus);
    }
}

void hapusParkir(){
    struct parkir *hapus;
    hapus = head2;
    if(hapus == NULL){
        printf("Parkir Kosong!\n");
    }
    else if (hapus->next == NULL){
        head2 = NULL;
        tail2 = NULL;
        free(hapus);
    }
    else{
        while(hapus->next != tail2){
            hapus = hapus->next;
        }
        tail2 = hapus;
        hapus = hapus->next;
        tail2->next = NULL;
        free(hapus);
    }
}
