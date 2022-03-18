#include <iostream>

using namespace std;

struct DataFilm
{
  int kodeFilm, tahun;
  string judul;
};

void addFilm(DataFilm film[], int &n);
void showFilms(DataFilm film[], int n);
void showFilm(DataFilm profil[], int i);
int searchFilmByCode(DataFilm film[], int n, int input);
int searchFilmByTitle(DataFilm film[], int n, string input);
int DeretGanjil(int awal, int akhir);

int main()
{
  DataFilm film[20];
  int jmlFilm = 0;
  char inputMenu;

  do
  {
    cout << "Menu: \n"
         << "[1] Tambah Data Film \n"
         << "[2] Lihat Daftar Film \n"
         << "[3] Cari Film \n"
         << "[4] Deret Bilangan Ganjil \n"
         << "[Lainnya] Keluar \n"
         << "Pilih > ";
    cin >> inputMenu;
    system("CLS");

    switch (inputMenu)
    {
    case '1':
      cout << "Tambah data film \n";
      addFilm(film, jmlFilm);
      cout << "\n";
      break;

    case '2':
      showFilms(film, jmlFilm);
      cout << "\n";
      break;

    case '3':
    {
      int kodeFilm, index, sentinelIndex;
      char metodeCari;
      string judulFilm;

      showFilms(film, jmlFilm);
      cout << "\n";

      if (jmlFilm != 0)
      {

        cout << "Cari Berdasarkan: \n"
             << "[1] Kode Film \n"
             << "[Lainnya] Judul Film \n"
             << "Input > ";
        cin >> metodeCari;

        if (metodeCari == '1')
        {
          cout << "Cari kode film: ";
          cin >> kodeFilm;
          system("CLS");

          index = searchFilmByCode(film, jmlFilm, kodeFilm);
        }
        else
        {
          cout << "Cari judul film: ";
          cin.ignore();
          getline(cin, judulFilm);
          system("CLS");

          index = searchFilmByTitle(film, jmlFilm, judulFilm);
        }

        cout << "Hasil pencarian film \n";
        if (index != -1)
        {
          cout << "Index ke-" << index << "\n";
          showFilm(film, index);
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

      cout << "Deret Bilangan Ganjil \n";
      cout << "Bilangan awal: ";
      cin >> awal;

      do
      {
        cout << "Bilangan akhir: ";
        cin >> akhir;

        if (akhir < awal)
          cout << "Bil. akhir harus lebih besar dari " << awal << "! \n\n";

      } while (akhir < awal);

      cout << "Deret: " << DeretGanjil(awal, akhir);
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

void addFilm(DataFilm film[], int &n)
{
  bool isExist; // Untuk mengecek apakah kode film sudah terpakai/belum

  do
  {
    cout << "Kode Film: ";
    cin >> film[n].kodeFilm;

    isExist = ((searchFilmByCode(film, n, film[n].kodeFilm) == -1) ? 0 : 1);

    if (isExist)
      cout << "Kode Film sudah ada! \n\n";

  } while (isExist);

  cout << "Judul: ";
  cin.ignore();
  getline(cin, film[n].judul);

  cout << "Tahun: ";
  cin >> film[n].tahun;

  cout << "Film berhasil ditambahkan. \n";
  n++;
}

void showFilms(DataFilm film[], int n)
{
  cout << "Daftar Film: \n";
  if (n > 0)
    for (int i = 0; i < n; i++)
    {
      cout << i + 1 << ". " << film[i].kodeFilm << " - "
           << film[i].judul << " [" << film[i].tahun << "] \n";
    }
  else
    cout << "Film belum ada. \n";
}

void showFilm(DataFilm film[], int i)
{
  cout << i + 1 << ". " << film[i].kodeFilm << " - "
       << film[i].judul << " [" << film[i].tahun << "] \n";
}

int searchFilmByCode(DataFilm film[], int n, int input)
{
  for (int i = 0; i < n; i++)
    if (input == film[i].kodeFilm)
      return i;
  return -1;
}

int searchFilmByTitle(DataFilm film[], int n, string input)
{
  for (int i = 0; i < n; i++)
    if (input == film[i].judul)
      return i;
  return -1;
}

int DeretGanjil(int awal, int akhir)
{
  if (awal % 2 == 0)
    awal++;

  if (awal <= akhir)
    cout << awal << ((awal >= akhir || awal + 1 >= akhir) ? " = " : " + ");

  return (awal <= akhir) ? (awal + DeretGanjil(awal + 2, akhir)) : 0;
}