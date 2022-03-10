#include <iostream>

using namespace std;

struct Mahasiswa
{
  int NIM;
  string nama;
};

void addMahasiswa(Mahasiswa mhs[], int &n);
void readMahasiswa(Mahasiswa mhs[], int n);
void readProfil(Mahasiswa profil[], int i);
int searchMhs(Mahasiswa mhs[], int n, int input);         // Seq Search
int searchMhsSentinel(Mahasiswa mhs[], int n, int input); // Seq Search (Sentinel)

int main()
{
  Mahasiswa mahasiswa[10];
  int mhsAktif = 0;
  char inputMenu;

  do
  {
    cout << "Menu: \n"
         << "[1] Tambah Mahasiswa \n"
         << "[2] Lihat Daftar Mahasiswa \n"
         << "[3] Cari Mahasiswa \n"
         << "[Lainnya] Keluar \n"
         << "Pilih > ";
    cin >> inputMenu;
    system("CLS");

    switch (inputMenu)
    {
    case '1':
      addMahasiswa(mahasiswa, mhsAktif);
      break;

    case '2':
      readMahasiswa(mahasiswa, mhsAktif);
      break;

    case '3':
    {
      int nim, index, sentinelIndex;

      readMahasiswa(mahasiswa, mhsAktif);
      cout << "\n";

      if (mhsAktif != 0)
      {
        cout << "Cari NIM: ";
        cin >> nim;
        system("CLS");

        index = searchMhs(mahasiswa, mhsAktif, nim);
        sentinelIndex = searchMhsSentinel(mahasiswa, mhsAktif, nim);

        cout << "Hasil pencarian mahasiswa dengan NIM: " << nim << "\n";
        cout << "Sequential Search: ";
        if (index != -1)
          readProfil(mahasiswa, index);
        else
          cout << "Tidak ditemukan. \n";

        cout << "Sequential Search (Sentinel): ";
        if (sentinelIndex != -1)
          readProfil(mahasiswa, sentinelIndex);
        else
          cout << "Tidak ditemukan. \n";
      }
      break;
    }

    default:
      inputMenu = -1;
      break;
    }
    cout << "\n";
  } while (inputMenu != -1);

  cout << "Terima kasih.";

  return 0;
}

void addMahasiswa(Mahasiswa mhs[], int &n)
{
  cout << "Tambah Mahasiswa \n";
  cout << "NIM: ";
  cin >> mhs[n].NIM;

  cout << "Nama: ";
  cin.ignore();
  getline(cin, mhs[n].nama);

  cout << "Mahasiswa berhasil ditambahkan. \n";
  n++;
}

void readMahasiswa(Mahasiswa mhs[], int n)
{
  cout << "Daftar Mahasiswa: \n";
  if (n > 0)
    for (int i = 0; i < n; i++)
      cout << i + 1 << ". [" << mhs[i].NIM << "] " + mhs[i].nama + "\n";
  else
    cout << "Mahasiswa belum ada. \n";
}

void readProfil(Mahasiswa profil[], int i)
{
  cout << "[" << profil[i].NIM << "] " + profil[i].nama << "\n";
}

int searchMhs(Mahasiswa mhs[], int n, int input)
{
  for (int i = 0; i < n; i++)
    if (input == mhs[i].NIM)
      return i;
  return -1;
}

int searchMhsSentinel(Mahasiswa mhs[], int n, int input)
{
  int last = mhs[n - 1].NIM, i = 0;

  mhs[n - 1].NIM = input;
  while (input != mhs[i].NIM)
    i++;
  mhs[n - 1].NIM = last;

  return (i < n - 1) || (input == mhs[n - 1].NIM) ? i : -1;
}