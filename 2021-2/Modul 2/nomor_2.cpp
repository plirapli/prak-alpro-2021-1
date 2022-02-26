#include <iostream>

using namespace std;

struct Penduduk
{
  string nama, alamat, agama, golDar, status;
  int umur;
} penduduk[10];

void showPenduduk(Penduduk penduduk[], int pendudukAktif);
int findPenduduk(Penduduk penduduk[], string nama, int pendudukAktif);
void addPenduduk(Penduduk penduduk[], int &pendudukAktif);
void delPenduduk(Penduduk penduduk[], int n, int &pendudukAktif);

int main()
{
  int pendudukAktif = 0;
  char inMenu;

  do
  {
    cout << "Menu: \n"
         << "[1] Lihat Penduduk \n"
         << "[2] Tambah Penduduk \n"
         << "[3] Cari Penduduk \n"
         << "[4] Hapus Penduduk \n"
         << "[Others] Exit \n"
         << "Input > ";
    cin >> inMenu;
    system("CLS");

    switch (inMenu)
    {
    case '1':
      showPenduduk(penduduk, pendudukAktif);
      break;

    case '2':
      addPenduduk(penduduk, pendudukAktif);
      break;

    case '4':
    {
      int index;

      do
      {
        showPenduduk(penduduk, pendudukAktif);
        cout << "Baris yang ingin dihapus: ";
        cin >> index;

        if (index > pendudukAktif || index <= 0)
        {
          cout << "Penduduk dengan nama "
               << penduduk[index - 1].nama << " telah dihapus. \n";
          delPenduduk(penduduk, index, pendudukAktif);
        }
        else
          cout << "Input tidak valid. \n";
      } while (index > pendudukAktif);
      break;
    }

    default:
      inMenu = '0';
      break;
    }

  } while (inMenu != '0');

  cout << "Terima kasih. \n";
  return 0;
}

void showPenduduk(Penduduk penduduk[], int pendudukAktif)
{
  if (pendudukAktif > 0)
  {
    cout << "Daftar Penduduk: \n";
    for (int i = 0; i < pendudukAktif; i++)
    {
      cout << "Nama: " << penduduk[i].nama << "\n"
           << "Alamat: " << penduduk[i].alamat << "\n"
           << "Umur: " << penduduk[i].umur << " tahun \n"
           << "Agama: " << penduduk[i].agama << "\n"
           << "Gol. Darah: " << penduduk[i].golDar << "\n"
           << "Status: " << penduduk[i].status << " kawin \n\n";
    }
  }
  else
    cout << "Penduduk belum ada. \n\n";
}

int findPenduduk(Penduduk penduduk[], string nama, int pendudukAktif)
{
  int index;
  for (int i = 0; i < pendudukAktif; i++)
  {
    index = (nama == penduduk[i].nama) ? i : pendudukAktif;
    if (index != pendudukAktif)
      break;
  }
  return index;
}

void addPenduduk(Penduduk penduduk[], int &pendudukAktif)
{
  cout << "Nama: ";
  cin.ignore();
  getline(cin, penduduk[pendudukAktif].nama);

  cout << "Alamat: ";
  getline(cin, penduduk[pendudukAktif].alamat);

  cout << "Umur: ";
  cin >> penduduk[pendudukAktif].umur;

  cout << "Agama: ";
  cin >> penduduk[pendudukAktif].agama;

  cout << "Gol. Darah [A/B/AB/O]: ";
  cin >> penduduk[pendudukAktif].golDar;

  cout << "Status [Sudah/Belum Kawin]: ";
  cin >> penduduk[pendudukAktif].status;

  cout
      << "\n"
      << "Data berhasil ditambahkan. \n\n";

  pendudukAktif++;
}

void delPenduduk(Penduduk penduduk[], int n, int &pendudukAktif)
{
  for (int i = n - 1; i < pendudukAktif; i++)
    penduduk[i] = penduduk[i + 1];
  pendudukAktif--;
}