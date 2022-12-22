#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void masuk_antrian();
void keluar_antrian();
void tampil_antrian();
void tampil_parkir();
void keluar_parkir();
void masuk_parkir();

struct node* phead = NULL;

struct node{
    int data;
    char plat[10];
    char jenis[10];
    struct node* next;
}; typedef struct node node;

int main(){
    int pilih;
    printf("--- MENU ---\n\n");
    printf("* Program Parkir Dengan Stack dan Queue *\n\n");
    printf("1. Masuk antrian parkir\n");
    printf("2. Keluar antrian parkir\n");
    printf("3. Tampilkan antrian parkir\n");
    printf("4. Tampilkan data kendaraan yang parkir\n");
    printf("5. Masuk parkir\n");
    printf("6. Keluar parkir\n");
    printf("\n0. Keluar program\n\n");
    printf("Pilih : ");
    scanf("%d", &pilih);
    switch(pilih){
        case 1:
            masuk_antrian();
            break;
        case 2:
            keluar_antrian();
            break;
        case 3:
            tampil_antrian();
            break;
        case 4:
            tampil_parkir();
            break;
        case 5:
            masuk_parkir();
            break;
        case 6:
            keluar_parkir();
            break;
        case 0:
            printf("Keluar program\n");
            return 0;
            break;
        default:
            printf("Pilihan tidak ada\n");
            break;
    }
}

void masuk_antrian(){
    struct node* pnew = (struct node*)malloc(sizeof(struct node));
    printf("Masukan plat nomor : ");
    fflush(stdin);
    gets(pnew->plat);
    printf("Masukan jenis kendaraan : ");
    fflush(stdin);
    gets(pnew->jenis);
    pnew->next = NULL;
    if (phead == NULL){
        phead = pnew;
    }else{
        struct node* pcurrent = phead;
        while(pcurrent->next != NULL){
            pcurrent = pcurrent->next;
        }
        pcurrent->next = pnew;
    }
    printf("Data berhasil dimasukkan\n");
    main();
}


void keluar_antrian(){
    if (phead == NULL){
        printf("Antrian kosong\n");
        main();
    }
    printf("Masukan plat nomor yang akan dihapus : ");
    char plat[10];
    fflush(stdin);
    gets(plat);
    struct node* pcurrent = phead;
    struct node* pprev = NULL;
    while(pcurrent != NULL){
        if(strcmp(pcurrent->plat, plat) == 0){
            if(pprev == NULL){
                phead = pcurrent->next;
            }else{
                pprev->next = pcurrent->next;
            }
            free(pcurrent);
            printf("Data berhasil dihapus\n");
            main();
        }
        pprev = pcurrent;
        pcurrent = pcurrent->next;
    }
}

//print data
void tampil_antrian(){
    struct node* pcurrent = phead;
    int i = 1;
    if (phead == NULL){
        printf("Antrian kosong\n");
        main();
    }
    printf("--- Antrian parkir ---\n\n");
    while(pcurrent != NULL){
        printf("%d. ", i);
        printf("Plat nomor : %s\n", pcurrent->plat);
        pcurrent = pcurrent->next;
        i++;
    }
    main();
}

void tampil_parkir(){
    printf("Kendaraan yang sudah masuk parkir\n");
    struct node* pcurrent = phead;
    int i = 1;
    if (phead == NULL){
        printf("Parkir kosong\n");
        main();
    }
    printf("--- Parkir ---\n\n");
    while(pcurrent != NULL){
        printf("Plat nomor : %s\n", pcurrent->plat);
        printf("Jenis kendaraan : %s\n", pcurrent->jenis);
        pcurrent = pcurrent->next;
    }
    main();
}

void masuk_parkir(){
    if (phead == NULL){
        printf("Parkir kosong\n");
        main();
    }
    printf("Kendaraan dari antrian akan di masukkan ke parkiran\n");
    struct node* pprev = phead;
    phead = phead->next;
    free(pprev);
    printf("Mobil berhasil masuk\n");
    main();
}

void keluar_parkir(){
    if (phead == NULL){
        printf("Parkir kosong\n");
        main();
    }
    struct node* pprev = phead;
    phead = phead->next;
    free(pprev);
    printf("Mobil berhasil keluar\n");
    main();
}
