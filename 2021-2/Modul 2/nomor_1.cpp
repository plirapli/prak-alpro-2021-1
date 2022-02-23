#include <iostream>

using namespace std;

struct Pegawai
{
	string nama;
	int nip, hariKerja, gaji, totalGaji;
} pegawai[10];

void showPegawai(Pegawai pegawai[], int pegawaiAktif);
void addPegawai(Pegawai pegawai[], int &pegawaiAktif);

int main()
{
	int pegawaiAktif = 0;
	char inMenu;

	do
	{
		cout << "Menu: \n"
				 << "[1] Lihat Pegawai \n"
				 << "[2] Tambah Pegawai \n"
				 << "[Others] Exit \n"
				 << "Input > ";
		cin >> inMenu;
		system("CLS");

		switch (inMenu)
		{
		case '1':
			showPegawai(pegawai, pegawaiAktif);
			break;

		case '2':
			addPegawai(pegawai, pegawaiAktif);
			break;

		default:
			inMenu = '0';
			break;
		}

	} while (inMenu != '0');

	cout << "Terima kasih. \n";
	return 0;
}

void showPegawai(Pegawai pegawai[], int pegawaiAktif)
{
	if (pegawaiAktif > 0)
	{
		cout << "Daftar Pegawai: \n";
		for (int i = 0; i < pegawaiAktif; i++)
		{
			cout << "NIP: " << pegawai[i].nip << "\n"
					 << "Nama: " << pegawai[i].nama << "\n"
					 << "Hari Kerja: " << pegawai[i].hariKerja << "\n"
					 << "Gaji harian: " << pegawai[i].gaji << "\n"
					 << "Total Gaji: " << pegawai[i].totalGaji << "\n\n";
		}
	}
	else
		cout << "Pegawai belum ada. \n\n";
}

void addPegawai(Pegawai pegawai[], int &pegawaiAktif)
{
	cout << "Nama: ";
	cin.ignore();
	getline(cin, pegawai[pegawaiAktif].nama);

	cout << "NIP: ";
	cin >> pegawai[pegawaiAktif].nip;

	cout << "Hari Kerja: ";
	cin >> pegawai[pegawaiAktif].hariKerja;

	cout << "Gaji: ";
	cin >> pegawai[pegawaiAktif].gaji;

	pegawai[pegawaiAktif].totalGaji =
			pegawai[pegawaiAktif].gaji *
			pegawai[pegawaiAktif].hariKerja;

	cout
			<< "\n"
			<< "Data berhasil ditambahkan. \n\n";

	pegawaiAktif++;
}