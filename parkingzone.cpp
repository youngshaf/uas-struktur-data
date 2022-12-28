#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct antrian{
	char plat[12];
	char jenis[12];
	antrian *next;
};

struct parkir{
	char plat[12];
	char jenis[12];
	parkir *next;
};

struct antrian *phead = NULL;
struct antrian *ptail = NULL;
struct parkir *phead2 = NULL;
struct parkir *ptail2 = NULL;

void tambahAntrian(){
	antrian *baru;
	baru = new antrian;
	cout << "\t >> TAMBAH ANTRIAN <<" << endl;
	cout << "\t   ---------------" << endl;
	cout << " ---------------------------" << endl;
	cout << " =   Masukkan Plat  : ";
	cin.ignore();
	cin.getline(baru->plat, 12);
	cout << " =   Masukkan Jenis : ";
	cin.getline(baru->jenis, 12);
	baru->next = NULL;
	if (phead == NULL){
    	phead = baru;
    	ptail = baru;
	}
	else{
    	ptail->next = baru;
    	ptail = baru;
	}
}


void hapusAntrian();
void tambahParkir(){
	if (phead == NULL){
		cout << "Antrian Kosong!" << endl;
    	return;
	}
	struct parkir *baru;
	baru = new struct parkir;
	strcpy(baru->plat, phead->plat);
	strcpy(baru->jenis, phead->jenis);
	baru->next = NULL;
	if (phead2 == NULL){
		phead2 = baru;
		ptail2 = baru;
	}
	else{
		ptail2->next = baru;
    ptail2 = baru;
  }
  hapusAntrian();
}


void tampilAntrian(){
	antrian *bantu;
	bantu = phead;
	if (bantu == NULL){
    	cout << "Antrian Kosong!" << endl;
	}
	else{
		while (bantu != NULL){
			cout << "Plat: " << bantu->plat << endl;
			cout << "Jenis: " << bantu->jenis << endl << endl;
			bantu = bantu->next;
    	}
	}
}


void tampilParkir(){
	parkir *bantu;
	bantu = phead2;
	if (bantu == NULL){
    	cout << "Parkir Kosong!" << endl;
	}
	else{
		while (bantu != NULL){
			cout << "\t >> PARKIR <<" << endl;
			cout << "\t   -------" << endl;
			cout << " ----------------------" << endl;
			cout << "Plat: " << bantu->plat << endl;
			cout << "Jenis: " << bantu->jenis << endl << endl;
			bantu = bantu->next;
		}
	}
}


void hapusAntrian(){
	antrian *hapus;
	hapus = phead;
	if (hapus == NULL){
		cout << "Antrian Kosong!" << endl;
	}
	else{
		phead = hapus->next;
		delete hapus;
	}
}


// update hapusParkir(fixed)
void hapusParkir(){
	parkir *hapus;
	hapus = phead2;
	if (hapus == NULL){
    	cout << "Parkir Kosong!" << endl;
	}
	else if (phead2 == ptail2){
    	delete phead2;
    	phead2 = NULL;
    	ptail2 = NULL;
	}
	else{
    	while (hapus->next != ptail2){
			hapus = hapus->next;
		}
		ptail2 = hapus;
	    hapus = hapus->next;
	    ptail2->next = NULL;
	    delete hapus;
	}
}


int main(){
	int pilih, pilihan;
	
	do{
	    system("cls");
	    cout << "\t >> PARKING-ZONE FASILKOM <<" << endl;
		cout << "\t   -----------------------" << endl;
		cout << " ------------------------------------------" << endl;
		cout << " = What operation do you want to perform? =" << endl;
		cout << " = Select Option number. Enter 0 to exit. =" << endl;
		cout << " = -------------------------------------- =" << endl;
		cout << " =                                        =" << endl;
	    cout << " =     * MAIN       1. Informasi Antrian  =" << endl;
	    cout << " =       MENU *     2. Informasi Parkir   =" << endl;
		cout << " =                                        =" << endl;
		cout << " ------------------------------------------" << endl;
	    cout << " =       Masukkan Pilihan : "; cin >> pilih;
	
		switch (pilih){
			case 1:system("cls");{
				cout << "1. Tambah Antrian\n";
				cout << "2. Tampilkan Antrian\n";
				cout << "3. Hapus Antrian\n";
				cout << "Pilihan Anda : ";
				cin >> pilihan;
				if (pilihan == 1){
					system("cls");
    				tambahAntrian();
				}
				else if (pilihan == 2){
					system("cls");
			    	tampilAntrian();
				}
				else if (pilihan == 3){
					system("cls");
					hapusAntrian();
				}
				else cout <<"\nInputan Salah!\n";
				break;
			}
			case 2:system("cls");{
				cout << "1. Masuk Parkir\n";
				cout << "2. Tampilkan Parkir\n";
				cout << "3. Hapus Parkir\n";
				cout << "Pilihan Anda : ";
				cin >> pilihan;
				if (pilihan == 1){
					system("cls");
    				tambahParkir();
				}
				else if (pilihan == 2){
					system("cls");
			    	tampilParkir();
				}
				else if (pilihan == 3){
					
					hapusParkir();
				}
				else cout <<"\nInputan Salah!\n";
				break;
			}
			default: system("cls");{
        		cout << "pilihan salah!\n" << endl;
			}
		}
		system("pause");
	}
	while (pilih != 0);
}
