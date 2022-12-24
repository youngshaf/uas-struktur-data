#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

struct node *phead = NULL;

struct node
{
	int data;
	char plat[10];
	char jenis[10];
	struct node *next;
};
typedef struct node node;

void masuk_antrian()
{
	struct node *pnew = (struct node *)malloc(sizeof(struct node));
	
	cout << "Masukan plat nomor : ";
	cin >> pnew->plat;
	cout << "Masukan jenis kendaraan : ";
	cin >> pnew->jenis;
	pnew->next = NULL;
	if (phead == NULL)
	{
		phead = pnew;
	}
	else
	{
		struct node *pcurrent = phead;
    	while (pcurrent->next != NULL)
    	{
			pcurrent = pcurrent->next;
    	}
    	pcurrent->next = pnew;
	}
	cout << "Data berhasil dimasukkan\n";
	return;
}

void keluar_antrian()
{
	if (phead == NULL)
	{
    	cout << "Antrian kosong\n";
	}
	cout << "Masukan plat nomor yang akan dihapus : ";
	char plat[10];
	cin >> plat;
	struct node *pcurrent = phead;
	struct node *pprev = NULL;
	while (pcurrent != NULL)
	{
    	if ((pcurrent->plat, plat) == 0)
    	{
			if (pprev == NULL)
			{
        		phead = pcurrent->next;
			}
			else
			{
			pprev->next = pcurrent->next;
			}
			free(pcurrent);
			cout << "Data berhasil dihapus\n";
    	}
		pprev = pcurrent;
		pcurrent = pcurrent->next;	
	}
}

void tampil_antrian()
{
	struct node *pcurrent = phead;
	int i = 1;
	if (phead == NULL)
	{
    	cout << "Antrian kosong\n";
	}
	cout << "--- Antrian parkir ---\n\n";
	while (pcurrent != NULL)
	{
		cout << i << ". ";
    	cout << "Plat nomor : " << pcurrent->plat << endl;
		pcurrent = pcurrent->next;
		i++;
	}
}

void tampil_parkir()
{
	cout << "Kendaraan yang sudah masuk parkir\n";
	struct node *pcurrent = phead;
	int i = 1;
	if (phead == NULL)
	{
		cout << "Parkir kosong\n";
  	}
	cout << "--- Parkir ---\n\n";
	while (pcurrent != NULL)
	{
		cout << "Plat nomor : " << pcurrent->plat << endl;
		cout << "Jenis kendaraan : " << pcurrent->jenis << endl;
		pcurrent = pcurrent->next;
	}
}

void masuk_parkir()
{
	if (phead == NULL)
	{
		cout << "Parkir kosong\n";
	}
	cout << "Kendaraan dari antrian akan di masukkan ke parkiran\n";
	struct node *pprev = phead;
	phead = phead->next;
	free(pprev);
	cout << "Mobil berhasil masuk\n";
}

void keluar_parkir()
{
	if (phead == NULL)
	{
	cout << "Parkir kosong\n";
	}
	struct node *pprev = phead;
	phead = phead->next;
	free(pprev);
	cout << "Mobil berhasil keluar\n";
}

int main()
{
	int pilih;
	do
	{
		system("cls");
    	cout << "--- MENU ---\n\n";
    	cout << "* Program Parkir Dengan Stack dan Queue *\n\n";
	    cout << "1. Masuk antrian parkir\n";
	    cout << "2. Keluar antrian parkir\n";
	    cout << "3. Tampilkan antrian parkir\n";
	    cout << "4. Tampilkan data kendaraan yang parkir\n";
	    cout << "5. Masuk parkir\n";
	    cout << "6. Keluar parkir\n";
	    cout << "\n0. Keluar program\n\n";
	    cout << "Pilih : ";
	    cin >> pilih;

	    switch (pilih)
	    {
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
	    	default:
	      		system("cls");
				{
					cout << "pilihan salah!\n" << endl;
				}
	    }
	    getch();
	} while (pilih != 6);
}
