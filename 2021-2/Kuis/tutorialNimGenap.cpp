#include <iostream>

using namespace std;

struct DataLagu
{
  int kodeLagu;
  string judul, penyanyi, album;
};

int searchLagu(DataLagu lagu[], int awal, int akhir, int input);
int deretGenap(int awal, int akhir);

int main()
{
  DataLagu lagu[20]; // Objek lagu
  int jmlLagu = 0;   // Variabel jmlLagu untuk menyimpan jumlah lagu
  char inputMenu;    // Menyimpan input ketika memilih salah satu menu.

  do
  {
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
      // Input Kode Lagu
      cout << "Input Data Lagu \n";
      cout << "Kode Lagu: ";
      cin >> lagu[jmlLagu].kodeLagu;

      // Input Judul Lagu
      cout << "Judul: ";
      cin.ignore();
      getline(cin, lagu[jmlLagu].judul);

      // Input Penyanyi
      cout << "Penyanyi: ";
      getline(cin, lagu[jmlLagu].penyanyi);

      // Input Album
      cout << "Album: ";
      getline(cin, lagu[jmlLagu].album);

      cout << "Lagu berhasil ditambahkan. \n\n";
      jmlLagu++; // Ketika lagu berhasil ditambahkan, maka variabel jmlLagu akan bertambah 1
      break;

    case '2':
      cout << "Daftar Lagu: \n";
      if (jmlLagu > 0) // Melakukan pengecekan ada tidaknya lagu
      {
        for (int i = 0; i < jmlLagu; i++)
        {
          cout << i + 1 << ". Kode Lagu: " << lagu[i].kodeLagu << "\n";
          cout << "Judul: " << lagu[i].judul << "\n";
          cout << "Penyanyi: " << lagu[i].penyanyi << "\n";
          cout << "Album: " << lagu[i].album << "\n\n";
        }
      }
      else // Jika tidak ada lagu, maka tampilkan tulisan "Lagu belum ada."
        cout << "Lagu belum ada. \n";
      break;

    case '3':
    {
      if (jmlLagu != 0) // Melakukan pengecekan ada tidaknya lagu
      {
        int kodeLagu; // Menyimpan input dari kode lagu yang dicari
        int index;    // Menyimpan index hasil pencarian

        // Input kode lagu yang ingin dicari
        cout << "Cari kode lagu: ";
        cin >> kodeLagu;

        system("CLS");

        /* Melakukan pemanggilan fungsi search lagu dengan ketentuan parameter:
           1. Lagu sebagai objek dari DataLagu
           2. Index nilai awal = 0
           3. Index nilai akhir = jmlLagu - 1
           4. kodeLagu sebagai input yang ingin dicari
           Setelah itu, Fungsi searchLagu akan me-return index hasil pencarian
           dan disimpan ke dalam variabel yang bernama index */
        index = searchLagu(lagu, 0, jmlLagu - 1, kodeLagu);

        cout << "Hasil pencarian lagu dengan kode: " << kodeLagu << "\n";
        if (index != -1) // Ketika fungsi searchLagu tidak me-return nilai -1, maka lagu ditemukan
        {
          cout << "Index ke-" << index << "\n";
          cout << "Kode Lagu: " << lagu[index].kodeLagu << "\n";
          cout << "Judul: " << lagu[index].judul << "\n";
          cout << "Penyanyi: " << lagu[index].penyanyi << "\n";
          cout << "Album: " << lagu[index].album << "\n\n";
        }
        else // Ketika fungsi searchLagu me-return nilai -1, maka lagu tidak ditemukan
          cout << "Tidak ditemukan. \n";
      }
      else // Jika tidak ada lagu, maka tampilkan tulisan "Lagu belum ada."
        cout << "Lagu belum ada \n";

      cout << "\n";
      break;
    }

    case '4':
    {
      int awal, akhir;

      cout << "Deret Bilangan Genap \n";
      cout << "Bilangan awal: ";
      cin >> awal;

      cout << "Bilangan akhir: ";
      cin >> akhir;

      cout << "Deret: " << deretGenap(awal, akhir);
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

int searchLagu(DataLagu lagu[], int awal, int akhir, int input)
{
  if (awal <= akhir)
  {
    int tengah = (awal + akhir) / 2;

    if (input == lagu[tengah].kodeLagu) // Jika input = nilai tengah
      return tengah;
    else if (input < lagu[tengah].kodeLagu) // Jika input < nilai tengah
      return searchLagu(lagu, awal, tengah - 1, input);
    else // Jika input > nilai tengah
      return searchLagu(lagu, tengah + 1, akhir, input);
  }
  return -1;
}

int deretGenap(int awal, int akhir)
{
  if (awal % 2 != 0)
    awal++;

  if (awal <= akhir)
  {
    cout << awal;
    if (awal == akhir || awal + 1 == akhir)
      cout << " = ";
    else
      cout << " + ";

    return awal + deretGenap(awal + 2, akhir);
  }
  else
    return 0;
}