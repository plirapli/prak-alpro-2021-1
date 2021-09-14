#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Fungsi menentukan nilai terbesar pada array
// int cekNilaiMax(int varStore, string arr[], int arrIndex, int arrTotal);

int main()
{
	string dataMhs[5][3];
	int i, namaTerbesar, nimTerbesar, plugTerbesar, jmlStrip, jmlBaris = 0;

	// Input data
	cout << "Masukan"
			 << "\n"
			 << "-------"
			 << "\n";

	while (jmlBaris > 5 || jmlBaris <= 0)
	{
		cout << "Jumlah baris tidak boleh lebih dari 5."
				 << "\n";

		cout << "Baris" << setw(5) << ": ";
		cin >> jmlBaris;
		cin.ignore(1, '\n');

		cout << "\n";
	}

	for (i = 0; i < jmlBaris; i++)
	{
		cout << "Baris ke-" << i + 1;

		cout << "\n"
				 << "Nama" << setw(6) << ": ";
		getline(cin, dataMhs[i][0]);

		cout << "NIM" << setw(7) << ": ";
		getline(cin, dataMhs[i][1]);

		cout << "Plug" << setw(6) << ": ";
		getline(cin, dataMhs[i][2]);

		cout << "\n";
	}

	// Output data Mhs
	cout << "\n"
			 << "Inilah data Anda :"
			 << "\n";

	for (i = 0; i < jmlBaris; i++)
	{
		cout << "dataMhs ke-" << i + 1 << "\n";
		cout << "Nama" << setw(6) << ": " << dataMhs[i][0] << "\n";
		cout << "NIM" << setw(7) << ": " << dataMhs[i][1] << "\n";
		cout << "Plug" << setw(6) << ": " << dataMhs[i][2] << "\n";
		cout << "\n";
	}

	namaTerbesar = dataMhs[0][0].length();
	nimTerbesar = dataMhs[0][1].length();
	plugTerbesar = dataMhs[0][2].length();

	for (int i = 0; i < jmlBaris; i++)
	{
		int dataKeN = dataMhs[i][0].length();

		// Mengecek apakah nilai sebelumnya lebih kecil dari nilai sekarang.
		// Jika iya, nilai sebelumnya = nilai sekarang.
		namaTerbesar = (dataKeN > namaTerbesar ? dataKeN : namaTerbesar);
	}

	for (int i = 0; i < jmlBaris; i++)
	{
		int dataKeN = dataMhs[i][1].length();
		nimTerbesar = (nimTerbesar < dataKeN ? dataKeN : nimTerbesar);
	}

	for (int i = 0; i < jmlBaris; i++)
	{
		int dataKeN = dataMhs[i][2].length();
		plugTerbesar = (plugTerbesar < dataKeN ? dataKeN : plugTerbesar);
	}

	cout << "\n";
	cout << "Nama Terbesar: " << namaTerbesar << "\n";
	cout << "NIM Terbesar: " << nimTerbesar << "\n";
	cout << "Plug Terbesar: " << plugTerbesar << "\n";

	// Menghitung total karakter untuk menentukan jumlah strip (=)
	// 6 merupakan jml spasi dari header
	// 11 merupakan jml karakter keterangan tabel ("Nama" + "NIM" + "Plug" = 11 karakter)
	jmlStrip = namaTerbesar + nimTerbesar + plugTerbesar + 6 + 11;

	// TABLE
	cout << "\n"
			 << "Dalam bentuk tabel :" << endl;

	// ========== Header ==========
	cout << setfill('=') << setw(jmlStrip) << "="
			 << "\n";

	cout << setfill(' ')
			 << setw(5) << "NIM" << setw(nimTerbesar)
			 << "|" << setw(6) << "Nama" << setw(namaTerbesar)
			 << "|" << setw(6) << "Plug" << setw(plugTerbesar) << "|"
			 << "\n";

	cout << setfill('=') << setw(jmlStrip) << "="
			 << "\n";
	// ========== End Header ==========

	for (i = 0; i < jmlBaris; i++)
	{
		// ========== Row ==========
		cout << setfill(' ')
				 << setw(nimTerbesar + 2) << dataMhs[i][1] << setw(3)
				 << "|" << setw(namaTerbesar + 2) << dataMhs[i][0] << setw(4) << "|"
				 << setw(plugTerbesar + 2) << dataMhs[i][2] << setw(4) << "|"
				 << "\n";
		// ========= End Row ==========
	}

	cout << setfill('=') << setw(jmlStrip) << "="
			 << "\n";
	// END TABLE

	return 0;
}