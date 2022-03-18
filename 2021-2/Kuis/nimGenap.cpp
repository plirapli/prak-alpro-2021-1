#include <iostream>

using namespace std;

struct DataLagu
{
  int kodeLagu;
  string judul, penyanyi, album;
};

void addLagu(DataLagu lagu[], int &n);
void showLagu(DataLagu lagu[], int n);
void showLaguDetail(DataLagu profil[], int i);
int searchLagu(DataLagu lagu[], int awal, int akhir, int num);
int DeretGenap(int awal, int akhir);

int main()
{
  DataLagu lagu[20];
  int jmlLagu = 0;
  char inputMenu;

  do
  {
    if (jmlLagu == 0)
    {
      cout << "Input data lagu \n";
      addLagu(lagu, jmlLagu);
      cout << "\n";
    }

    cout << "Menu: \n"
         << "[1] Tambah Data Lagu \n"
         << "[2] Lihat Daftar Lagu \n"
         << "[3] Cari Lagu \n"
         << "[4] Deret Bilangan Genap \n"
         << "[Lainnya] Keluar \n"
         << "Pilih > ";
    cin >> inputMenu;
    system("CLS");

    switch (inputMenu)
    {
    case '1':
      cout << "Tambah data lagu \n";
      addLagu(lagu, jmlLagu);
      cout << "\n";
      break;

    case '2':
      showLagu(lagu, jmlLagu);
      cout << "\n";
      break;

    case '3':
    {
      int kodeLagu, index, sentinelIndex;

      showLagu(lagu, jmlLagu);
      cout << "\n";

      if (jmlLagu != 0)
      {
        cout << "Cari kode lagu: ";
        cin >> kodeLagu;
        system("CLS");

        index = searchLagu(lagu, 0, jmlLagu - 1, kodeLagu);

        cout << "Hasil pencarian lagu dengan kode: " << kodeLagu << "\n";
        if (index != -1)
        {
          cout << "Index ke-" << index << "\n";
          showLaguDetail(lagu, index);
        }
        else
          cout << "Tidak ditemukan. \n";
      }
      cout << "\n";
      break;
    }

    case '4':
    {
      int awal, akhir;

      cout << "Deret Bilangan Genap \n";
      cout << "Bilangan awal: ";
      cin >> awal;

      do
      {
        cout << "Bilangan akhir: ";
        cin >> akhir;

        if (akhir < awal)
          cout << "Bil. akhir harus lebih besar dari " << awal << "! \n\n";

      } while (akhir < awal);

      cout << "Deret: " << DeretGenap(awal, akhir);
      cout << "\n\n";

      break;
    }

    default:
      inputMenu = -1;
      break;
    }
  } while (inputMenu != -1);

  cout << "Terima kasih.";

  return 0;
}

void addLagu(DataLagu lagu[], int &n)
{
  cout << "Kode Lagu: ";
  cin >> lagu[n].kodeLagu;

  cout << "Judul: ";
  cin.ignore();
  getline(cin, lagu[n].judul);

  cout << "Penyanyi: ";
  getline(cin, lagu[n].penyanyi);

  cout << "Album: ";
  getline(cin, lagu[n].album);

  cout << "Lagu berhasil ditambahkan. \n";
  n++;
}

void showLagu(DataLagu lagu[], int n)
{
  cout << "Daftar Lagu: \n";
  if (n > 0)
    for (int i = 0; i < n; i++)
    {
      cout << i + 1 << ". " << lagu[i].kodeLagu << " - "
           << lagu[i].judul << "\n"
           << "Penyanyi: " << lagu[i].penyanyi << "\n"
           << "Album: " << lagu[i].album << "\n\n";
    }
  else
    cout << "Lagu belum ada. \n";
}

void showLaguDetail(DataLagu lagu[], int i)
{
  cout << lagu[i].kodeLagu << " - "
       << lagu[i].judul << "\n"
       << "Penyanyi: " << lagu[i].penyanyi << "\n"
       << "Album: " << lagu[i].album << "\n";
}

int searchLagu(DataLagu lagu[], int awal, int akhir, int num)
{
  if (awal <= akhir)
  {
    int tengah = (awal + akhir) / 2;

    return (num == lagu[tengah].kodeLagu)  ? tengah
           : (num < lagu[tengah].kodeLagu) ? searchLagu(lagu, awal, tengah - 1, num)
                                           : searchLagu(lagu, tengah + 1, akhir, num);
  }
  return -1;
}

int DeretGenap(int awal, int akhir)
{
  if (awal % 2 != 0)
    awal++;

  if (awal <= akhir)
    cout << awal << ((awal == akhir || awal + 1 == akhir) ? " = " : " + ");

  return (awal <= akhir) ? (awal + DeretGenap(awal + 2, akhir)) : 0;
}