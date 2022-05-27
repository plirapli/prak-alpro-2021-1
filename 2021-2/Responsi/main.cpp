#include <iostream>
#include <fstream>
#include <conio.h>
#include <cmath>
#include <algorithm>

#define CLEAR "cls"

using namespace std;

struct Bakteri
{
  string nama;
  int ukuran, jmlAnakPembelahan;
};

// R/W File
void readFile(Bakteri bakteri[], int &jml);
void writeFile(Bakteri bakteri[], int jml);

// Menu Program
void addBakteri(Bakteri bakteri[], int jml);
void cetakBakteri(Bakteri bakteri[], int jml, int awal = 0);
void editData(Bakteri bakteri[], int jml, int inputIndex);
void kosongkanData(Bakteri bakteri[], int jml);
void cariBakteri(Bakteri bakteri[], int jml);
void urutkanBakteri(Bakteri bakteri[], int jml);
void simulasiPembelahan(Bakteri bakteri[], int jml, int indeks);

// CRUD Method
void selectionSort(Bakteri bakteri[], int jml);
int search(Bakteri bakteri[], int jml, string input);
void insertionSort(Bakteri bakteri[], int jml);

string replaceSpasi(string str);
string replaceHyphen(string str);

void pressAnyKey();

int main()
{
  Bakteri bakteri[100];
  int jmlBakteri;
  char inputMenu;
  bool isExit = 0;

  do
  {
    readFile(bakteri, jmlBakteri); // Membaca data dari file

    cout << "Menu: \n"
         << "[1] Input Bakteri \n"
         << "[2] Cetak Data \n"
         << "[3] Edit Data \n"
         << "[4] Hapus Data \n"
         << "[5] Cari Bakteri \n"
         << "[6] Urutkan Bakteri \n"
         << "[7] Simulasi Pembelahan \n"
         << "Pilih > ";
    cin >> inputMenu;
    system(CLEAR);

    switch (inputMenu)
    {
    case '1':
      addBakteri(bakteri, jmlBakteri);
      break;

    case '2':
      cetakBakteri(bakteri, jmlBakteri);
      break;

    case '3':
    {
      int nomor;

      cetakBakteri(bakteri, jmlBakteri);
      cout << "Masukkan Nomor: ";
      cin >> nomor;

      if (nomor > 0 && nomor <= jmlBakteri)
      {
        system(CLEAR);

        // nomor - 1 karena index merupakan nomor dikurangi 1
        cetakBakteri(bakteri, nomor, nomor - 1);
        editData(bakteri, jmlBakteri, nomor - 1);
      }
      else
      {
        cout << "Bakteri tidak ditemukan \n\n";
        pressAnyKey();
      }
      break;
    }

    case '4':
    {
      if (jmlBakteri > 0) // Melakukan pengecekan bakteri yang ada
      {
        cout << "[1] Hapus Bakteri \n"
             << "[2] Kosongkan Data \n"
             << "[...] Kembali \n"
             << "Pilih > ";
        cin >> inputMenu;

        switch (inputMenu)
        {
        case '1':
        {
          int nomor;
          bool repeat = 1;

          do
          {
            cetakBakteri(bakteri, jmlBakteri);

            cout << "Masukkan Bakteri ke-n: ";
            cin >> nomor;
            cout << "\n";

            if (nomor > 0 && nomor <= jmlBakteri)
            {
              // Menaikkan baris
              for (int i = nomor - 1; i < jmlBakteri; i++)
                bakteri[i] = bakteri[i + 1];

              jmlBakteri--;                   // Mengurangi jumlah bakteri
              writeFile(bakteri, jmlBakteri); // Melakukan overwrite terhadap file
              repeat = 0;                     // Menghentikan perulangan

              cout << "Data telah dihapus! \n\n";
            }
            else
              cout << "Bakteri tidak ditemukan \n\n";

            pressAnyKey();
          } while (repeat);
        }
        break;

        case '2':
          kosongkanData(bakteri, jmlBakteri);
          pressAnyKey();
          break;

        default:
          break;
        }
      }
      else
      {
        cout << "Data masih kosong \n\n";
        pressAnyKey();
      }
      break;
    }

    case '5':
      cariBakteri(bakteri, jmlBakteri);
      break;

    case '6':
      if (jmlBakteri > 0)
        urutkanBakteri(bakteri, jmlBakteri);
      else
      {
        cout << "Bakteri masih kosong! \n\n";
        pressAnyKey();
      }

      break;

    case '7':
    {
      int indexBakteri;
      string nama;

      cout << "Masukkan nama bakteri: ";
      cin.ignore();
      getline(cin, nama);

      indexBakteri = search(bakteri, jmlBakteri, nama);

      if (indexBakteri != -1)
        simulasiPembelahan(bakteri, jmlBakteri, indexBakteri);
      else
        cout << "Bakteri tidak ditemukan! \n\n";

      pressAnyKey();
      break;
    }

    default:
      isExit = 1;
      break;
    }
  } while (!isExit);

  cout << "Terima kasih";

  return 0;
}

void readFile(Bakteri bakteri[], int &jml)
{
  string fileName = "data-bakteri.txt";

  ifstream myFile(fileName);
  jml = 0;

  if (myFile.is_open())
  {
    int i = jml;
    while (!myFile.eof())
    {
      myFile >> bakteri[i].nama >> bakteri[i].ukuran >> bakteri[i].jmlAnakPembelahan;
      bakteri[i].nama = replaceHyphen(bakteri[i].nama); // Menghilangkan "-"
      i++;
    }

    jml += i - 1;
    myFile.close();
  }
  else
    cout << "Gagal membuka file. \n";
}

void writeFile(Bakteri bakteri[], int jml)
{
  int i;
  string fileName = "data-bakteri.txt";

  for (i = 0; i < jml; i++)
    bakteri[i].nama = replaceSpasi(bakteri[i].nama);

  ofstream myFile(fileName);
  if (myFile.is_open())
  {
    for (i = 0; i < jml; i++)
    {
      // Contoh format file:
      // e-coli 2 6

      myFile << bakteri[i].nama << " "
             << bakteri[i].ukuran << " "
             << bakteri[i].jmlAnakPembelahan << "\n";
    }
    myFile.close();
  }
  else
    cout << "Gagal membuka file. \n";
}

void addBakteri(Bakteri bakteri[], int jml)
{
  cout << "Tambah Bakteri \n";
  cout << "Nama: ";
  cin.ignore();
  getline(cin, bakteri[jml].nama);

  cout << "Ukuran: ";
  cin >> bakteri[jml].ukuran;

  cout << "Jumlah anak per pembalahan: ";
  cin >> bakteri[jml].jmlAnakPembelahan;

  cout << "Bakteri berhasil ditambahkan. \n\n";
  jml++;

  writeFile(bakteri, jml); // File di-overwrite oleh struct yang telah ditambahkan
  pressAnyKey();
}

void cetakBakteri(Bakteri bakteri[], int jml, int awal)
{
  if (jml > 0)
  {
    cout << "[Informasi Bakteri] \n";
    for (int i = awal; i < jml; i++)
    {
      cout << "Bakteri ke-" << i + 1 << "\n"
           << "Nama: " << bakteri[i].nama << "\n"
           << "Ukuran: " << bakteri[i].ukuran << " mikron \n"
           << "Jumlah anak/pembelahan: " << bakteri[i].jmlAnakPembelahan << "\n\n";
    }
  }
  else
    cout << "Bakteri masih kosong! \n\n";
}

void editData(Bakteri bakteri[], int jml, int inputIndex)
{
  char menu;
  int ukuran, jmlAnak;
  string nama;

  cout << "Pilih yang ingin diubah: \n"
       << "[1] Nama \n"
       << "[2] Ukuran \n"
       << "[3] Jumlah anak per pembelahan \n"
       << "[...] Kembali \n"
       << "Pilih > ";
  cin >> menu;

  switch (menu)
  {
  case '1':
    cout << "Ubah Nama: ";
    cin.ignore();
    getline(cin, nama);

    bakteri[inputIndex].nama = nama;

    cout << "\n"
         << "Berhasil mengubah nama! \n\n";
    pressAnyKey();
    break;

  case '2':
    cout << "Ubah Ukuran: ";
    cin >> ukuran;

    bakteri[inputIndex].ukuran = ukuran;

    cout << "\n"
         << "Berhasil mengubah ukuran! \n\n";
    pressAnyKey();
    break;

  case '3':
    cout << "Ubah Jumlah anak per pembalahan: ";
    cin >> jmlAnak;

    bakteri[inputIndex].jmlAnakPembelahan = jmlAnak;

    cout << "\n"
         << "Berhasil mengubah jumlah anak! \n\n";
    pressAnyKey();
    break;

  default:
    break;
  }

  writeFile(bakteri, jml);
}

void kosongkanData(Bakteri bakteri[], int jml)
{
  string fileName = "data-bakteri.txt";

  ofstream myFile(fileName);
  if (myFile.is_open())
  {
    myFile.close();
    cout << "Data berhasil dikosongkan! \n\n";
  }
  else
    cout << "Gagal membuka file. \n\n";
}

void cariBakteri(Bakteri bakteri[], int jml)
{
  int indexBakteri;
  string inputBakteri;

  cout << "[Cari Bakteri] \n"
       << "Masukkan nama bakteri: ";
  cin.ignore();
  getline(cin, inputBakteri);

  indexBakteri = search(bakteri, jml, inputBakteri);

  if (indexBakteri != -1)
    cetakBakteri(bakteri, indexBakteri + 1, indexBakteri);
  else
    cout << "Bakteri tidak ditemukan! \n\n";

  pressAnyKey();
}

void urutkanBakteri(Bakteri bakteri[], int jml)
{
  Bakteri sortedBakteri[100];
  bool isBack;
  char inputMenu;

  // Copy Data
  for (int i = 0; i < jml; i++)
    sortedBakteri[i] = bakteri[i];

  cout << "[1] Selection Sort \n"
       << "[2] Insertion Sort \n"
       << "[...] Kembali \n"
       << "Pilih > ";
  cin >> inputMenu;
  cout << "\n";

  switch (inputMenu)
  {
  case '1':
    selectionSort(sortedBakteri, jml);
    break;

  case '2':
    insertionSort(sortedBakteri, jml);
    break;

  default:
    isBack = 1;
    break;
  }

  if (!isBack)
  {
    cout << "[Mengurutkan Bakteri Berdasarkan Ukuran] \n";
    cetakBakteri(sortedBakteri, jml);
    pressAnyKey();
  }
}

void simulasiPembelahan(Bakteri bakteri[], int jml, int indeks)
{
  int total = 0;
  int ukuran = bakteri[indeks].ukuran;
  int jmlAnak = bakteri[indeks].jmlAnakPembelahan;

  cetakBakteri(bakteri, indeks + 1, indeks); // Mencetak informasi bakteri

  total = pow(ukuran, jmlAnak);

  cout << "Jumlah bakteri setelah proses pembelahan: "
       << total << " Bakteri \n\n";
}

void selectionSort(Bakteri bakteri[], int jml)
{
  int i, j, min_idx;

  // One by one move boundary of
  // unsorted subarray
  for (i = 0; i < jml - 1; i++)
  {

    // Find the minimum element in
    // unsorted array
    min_idx = i;
    for (j = i + 1; j < jml; j++)
      if (bakteri[j].ukuran < bakteri[min_idx].ukuran)
        min_idx = j;

    // Swap the found minimum element
    // with the first element
    swap(bakteri[min_idx], bakteri[i]);
  }
}

int search(Bakteri bakteri[], int jml, string input)
{
  int found;
  string nama;

  for (int i = 0; i < jml; i++)
  {
    nama = bakteri[i].nama;
    found = nama.find(input);
    if (found <= nama.length())
      return i;
  }
  return -1;
}

void insertionSort(Bakteri bakteri[], int jml)
{
  int i, j;
  Bakteri key;

  for (i = 0; i < jml; i++)
  {
    key = bakteri[i];
    j = i - 1;

    /* Bandingkan key sama elemen di kirinya. Kalo key lebih kecil,
       tuker sampe key lebih besar dari elemen di kirinya
       atau mentok paling ujung kiri */
    while (bakteri[j].ukuran > key.ukuran && j >= 0)
    {
      bakteri[j + 1] = bakteri[j];
      j--;
    }
    bakteri[j + 1] = key;
  }
}

string replaceSpasi(string str)
{
  for (int i = 0; i < str.length(); i++)
    if (str[i] == ' ')
      str[i] = '-';

  return str;
}

string replaceHyphen(string str)
{
  for (int i = 0; i < str.length(); i++)
    if (str[i] == '-')
      str[i] = ' ';

  return str;
}

void pressAnyKey()
{
  cout << "[Tekan tombol apa saja untuk melanjutkan.]";
  getch();
  system(CLEAR);
}