#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string odp, zona, kabKota, prov;
	int week1, week2, death;

	cout << "Nama Kabupaten/Kota: ";
	getline(cin, kabKota);

	cout << "Nama Provinsi: ";
	getline(cin, prov);

	cout << "Jumlah kasus positif minggu pertama: ";
	cin >> week1;
	cout << "Jumlah kasus positif minggu kedua: ";
	cin >> week2;
	cout << "Jumlah kematian: ";
	cin >> death;

	(death > 0 || week1 > 0 || week2 > 0) ? odp = "y" : odp = "n";

	if (week2 > 0)
		zona = (death > 0 && odp == "y") ? "HITAM" : "MERAH";
	else if (week2 <= 0)
		zona = (odp == "y") ? "ORANYE" : "HIJAU";
	else
		zona = "Input tidak valid";

	cout << "\n"
			 << "Wilayah " << kabKota << " Provinsi " << prov << ":"
			 << "\n";
	cout << "Kasus Minggu Pertama: " << week1 << " Orang"
			 << "\n";
	cout << "Kasus Minggu Kedua: " << week2 << " Orang"
			 << "\n";
	cout << "Jumlah Kematian: " << death << " Jiwa"
			 << "\n";
	cout << "Status: ZONA " << zona << "\n\n";

	cout << "Keterangan:"
			 << "\n";
	cout << "Jika [TERDAPAT KASUS] pada minggu pertama DAN minggu kedua, dan [TERDAPAT KEMATIAN]: ZONA HITAM"
			 << "\n";
	cout << "Jika [TERDAPAT KASUS] pada minggu pertama DAN minggu kedua, dan [TIDAK TERDAPAT KEMATIAN]: ZONA MERAH"
			 << "\n";
	cout << "Jika [TIDAK TERDAPAT KASUS] minggu kedua: ZONA ORANYE"
			 << "\n";
	cout << "Jika [TIDAK TERDAPAT KASUS]: ZONA HIJAU";

	return 0;
}

/*
hitam
merah
orange
hijau

week 1 y & week 2 y, week 2 > week 1, death y && odp y = HITAM
week 1 y & week 2 y, week 2 > week 1, death n && odp y = MERAH
week 1 y & week 2 y, week 2 < week 1, death y && odp y = HITAM
week 1 y & week 2 y, week 2 < week 1, death n && odp y = MERAH
week 1 n & week 2 y, death y && odp y = HITAM
week 1 n & week 2 y, death n && odp y = MERAH

week 1 a & week 2 0, death y && odp y = ORANGE
week 1 a & week 2 0, death n && odp y = ORANGE
week 1 0 & week 2 0, death n && odp n = HIJAU

positif & positif (meningkat)
kematian & odp = zona hitam
!kematian & odp = zona merah

!(positif & positif) || positif & positif (menurun)
!kematian & odp = orange
!kematian & !odp = hijau

1stWeek, 2ndWeek, kematian, odp

*/