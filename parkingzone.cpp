#include <iostream>
#include <string>

using namespace std;

struct antrian
{
  char plat[10];
  char jenis[10];
  antrian *next;
};

struct parkir
{
  char plat[10];
  char jenis[10];
  parkir *next;
};

struct antrian *phead = NULL;
struct antrian *ptail = NULL;
struct parkir *phead2 = NULL;
struct parkir *ptail2 = NULL;

void tambahAntrian()
{
  antrian *baru;
  baru = new antrian;
  cout << "Masukkan Plat: ";
  cin.ignore();
  cin.getline(baru->plat, 10);
  cout << "Masukkan Jenis: ";
  cin.getline(baru->jenis, 10);
  baru->next = NULL;
  if (phead == NULL)
  {
    phead = baru;
    ptail = baru;
  }
  else
  {
    ptail->next = baru;
    ptail = baru;
  }
}

void hapusAntrian();
void tambahParkir()
{
  // Menyambungkan antrian ke parkir
  // Jika tambah parkir, maka antrian pertama akan dihapus
  if (phead == NULL)
  {
    cout << "Antrian Kosong!" << endl;
    return;
  }
  struct parkir *baru;
  baru = new struct parkir;
  strcpy(baru->plat, phead->plat);
  strcpy(baru->jenis, phead->jenis);
  baru->next = NULL;
  if (phead2 == NULL)
  {
    phead2 = baru;
    ptail2 = baru;
  }
  else
  {
    ptail2->next = baru;
    ptail2 = baru;
  }
  hapusAntrian();
}

void tampilAntrian()
{
  antrian *bantu;
  bantu = phead;
  if (bantu == NULL)
  {
    cout << "Antrian Kosong!" << endl;
  }
  else
  {
    while (bantu != NULL)
    {
      cout << "Plat: " << bantu->plat << endl;
      cout << "Jenis: " << bantu->jenis << endl
           << endl;
      bantu = bantu->next;
    }
  }
}

void tampilParkir()
{
  parkir *bantu;
  bantu = phead2;
  if (bantu == NULL)
  {
    cout << "Parkir Kosong!" << endl;
  }
  else
  {
    while (bantu != NULL)
    {
      cout << "Plat: " << bantu->plat << endl;
      cout << "Jenis: " << bantu->jenis << endl
           << endl;
      bantu = bantu->next;
    }
  }
}

void hapusAntrian()
{
  antrian *hapus;
  hapus = phead;
  if (hapus == NULL)
  {
    cout << "Antrian Kosong!" << endl;
  }
  else
  {
    phead = hapus->next;
    delete hapus;
  }
}

void hapusParkir()
{
  parkir *hapus;
  hapus = phead2;
  if (hapus == NULL)
  {
    cout << "Parkir Kosong!" << endl;
  }
  else
  {
    while (hapus->next != ptail2)
    {
      hapus = hapus->next;
    }
    ptail2 = hapus;
    hapus = hapus->next;
    ptail2->next = NULL;
    delete hapus;
  }
}

int main()
{
  int pilih;

  do
  {
    system("cls");
    cout << "--- MENU ---\n\n";
    cout << "* Program Parkir Dengan Stack dan Queue *\n\n";
    cout << "1. Tambah Antrian\n";
    cout << "2. Tambah Parkir\n";
    cout << "3. Tampilkan Antrian\n";
    cout << "4. Tampilkan Parkir\n";
    cout << "5. Hapus Antrian\n";
    cout << "6. Hapus Parkir\n";
    cout << "\n0. Keluar program\n\n";
    cout << "Pilih : ";
    cin >> pilih;

    switch (pilih)
    {
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
      hapusAntrian();
      break;
    case 6:
      hapusParkir();
      break;
    default:
      system("cls");
      {
        cout << "pilihan salah!\n"
             << endl;
      }
    }
    system("pause");
  } while (pilih != 6);
}
