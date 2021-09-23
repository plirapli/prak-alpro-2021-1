#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Muhammad Rafli / 123210078
	const int hargaKuota = 6000;
	int i, total, totalBiayaSiswa = 0, totalBiayaPengajar = 0;
	int sekolah[5][4] = {{20, 42}, {35, 42}, {35, 42}, {35, 42}, {50, 50}},
			biayaSiswa[5],
			biayaPengajar[5];
	string jenisInstansi[5] = {"PAUD", "SD", "SMP", "SMA", "PT"};

	for (i = 0; i < 5; i++)
	{
		cout << jenisInstansi[i] << ":\n";
		cout << "Masukkan jumlah siswa" << setw(7) << ": ";
		cin >> sekolah[i][2];
		cout << "Masukkan jumlah pengajar" << setw(4) << ": ";
		cin >> sekolah[i][3];
		cout << "\n";

		// Menghitung total biaya masing-masing siswa dan pengajar
		biayaSiswa[i] = sekolah[i][0] * sekolah[i][2] * hargaKuota;
		biayaPengajar[i] = sekolah[i][1] * sekolah[i][3] * hargaKuota;

		// Menghitung total biaya siswa dan pengajar
		totalBiayaSiswa += biayaSiswa[i];
		totalBiayaPengajar += biayaPengajar[i];
	}

	total = totalBiayaSiswa + totalBiayaPengajar;

	cout << "ANGGARAN BIAYA KUOTA"
			 << "\n";

	cout << setfill('-') << setw(102) << "-"
			 << "\n"
			 << setfill(' ');

	cout << "|  No  |"
			 << setw(10) << "Kategori" << setw(3) << "|"
			 << setw(14) << "Jumlah Siswa" << setw(3) << "|"
			 << setw(17) << "Jumlah Pengajar" << setw(3) << "|"
			 << setw(16) << "Biaya Siswa" << setw(6) << "|"
			 << setw(18) << "Biaya Pengajar" << setw(4) << "|"
			 << "\n";

	cout << setfill('-') << setw(102) << "-"
			 << "\n"
			 << setfill(' ');

	for (i = 0; i < 5; i++)
	{
		cout << "|   " << i + 1 << "  |"
				 << setw(jenisInstansi[i].length() + 2) << jenisInstansi[i]
				 << setw(8 - jenisInstansi[i].length() + 3) << "|"
				 << setw(8) << right << sekolah[i][2] << " Orang" << setw(3) << "|"
				 << setw(11) << right << sekolah[i][3] << " Orang" << setw(3) << "|"
				 << setw(4) << "Rp" << setw(12) << right << biayaSiswa[i] << ",00" << setw(3) << "|"
				 << setw(4) << "Rp" << setw(12) << right << biayaPengajar[i] << ",00" << setw(3) << "|"
				 << "\n";
	}

	cout << setfill('-') << setw(102) << "-"
			 << "\n"
			 << setfill(' ');

	cout << "|"
			 << setw(54) << "Subtotal" << setw(3) << "|"
			 << setw(4) << "Rp" << setw(12) << right << totalBiayaSiswa << ",00" << setw(3) << "|"
			 << setw(4) << "Rp" << setw(12) << right << totalBiayaPengajar << ",00" << setw(3) << "|"
			 << "\n";

	cout << setfill('-') << setw(102) << "-"
			 << "\n"
			 << setfill(' ');

	cout << "|"
			 << setw(54) << "Total" << setw(3) << "|"
			 << setw(4) << "Rp" << setw(34) << right << total << ",00" << setw(3) << "|"
			 << "\n";

	cout << setfill('-') << setw(102) << "-";

	cout << "\n"
			 << "*Harga 1 GB = Rp6000,00";

	return 0;
}