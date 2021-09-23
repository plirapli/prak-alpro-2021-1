#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const int hargaKuota = 6000;
	int instansi, kuotaSiswa, kuotaPengajar, jmlSiswa, jmlPengajar, biayaSiswa, biayaPengajar, totalBiaya;

	do
	{
		cout << "1. PAUD"
				 << "\n"
				 << "2. SD"
				 << "\n"
				 << "3. SMP"
				 << "\n"
				 << "4. SMA"
				 << "\n"
				 << "5. Mahasiswa"
				 << "\n";
		cout << "Masukkan kategori instansi (angka): ";
		cin >> instansi;
		cout << "\n";
	} while (instansi <= 0 || instansi > 5);

	if (instansi == 1)
		kuotaSiswa = 20, kuotaPengajar = 42;
	else if (instansi == 2 || instansi == 3 || instansi == 4)
		kuotaSiswa = 35, kuotaPengajar = 42;
	else if (instansi == 5)
		kuotaSiswa = 50, kuotaPengajar = 50;
	else
		cout << "Input tidak valid";

	cout << "Masukkan jumlah siswa: ";
	cin >> jmlSiswa;
	cout << "Masukkan jumlah pengajar: ";
	cin >> jmlPengajar;
	cout << "\n";

	biayaSiswa = kuotaSiswa * jmlSiswa * hargaKuota;
	biayaPengajar = kuotaPengajar * jmlPengajar * hargaKuota;
	totalBiaya = biayaSiswa + biayaPengajar;

	cout << "ANGGARAN BIAYA KUOTA"
			 << "\n";
	cout << setfill('-') << setw(44) << "-"
			 << "\n";

	cout << setfill(' ') << "|  "
			 << setw(16) << left << "Biaya Siswa"
			 << setw(3) << "|"
			 << setw(4) << "Rp"
			 << setw(12) << right << biayaSiswa << ",00"
			 << setw(3) << "|"
			 << "\n";

	cout << "|  "
			 << setw(16) << left << "Biaya Pengajar"
			 << setw(3) << "|"
			 << setw(4) << "Rp"
			 << setw(12) << right << biayaPengajar << ",00"
			 << setw(3) << "|"
			 << "\n";

	cout << "|" << setfill('-') << setw(19) << "|"
			 << "  "
			 //  << setfill(' ') << setw(3) << "-"
			 << setfill('-') << setw(20) << "+"
			 << " |"
			 << "\n";

	cout << setfill(' ') << "|  "
			 << setw(16) << left << "Total"
			 << setw(3) << "|"
			 << setw(4) << "Rp"
			 << setw(12) << right << totalBiaya << ",00"
			 << setw(3) << "|"
			 << "\n";

	cout << setfill('-') << setw(44) << "-";

	return 0;
}