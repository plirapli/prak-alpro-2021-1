#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
     string nama, nim, plug;
     int jmlStrip;

     // Input Data
     cout << "Masukan"
          << "\n"
          << "----------"
          << "\n";

     cout << "Nama" << setw(6) << ": ";
     getline(cin, nama);

     cout << "NIM" << setw(7) << ": ";
     getline(cin, nim);

     cout << "Plug" << setw(6) << ": ";
     getline(cin, plug);

     // Output data
     cout << "\n"
          << "Inilah data Anda :"
          << "\n";

     cout << "Nama" << setw(6) << ": " << nama << "\n";
     cout << "NIM" << setw(7) << ": " << nim << "\n";
     cout << "Plug" << setw(6) << ": " << plug << "\n";

     // Menghitung total karakter untuk menentukan jumlah strip (=)
     jmlStrip = nama.length() + nim.length() + plug.length() + 6 + 11;

     // TABEL
     // ========== Header ==========
     cout << "\n"
          << "Dalam bentuk tabel :" << endl;

     cout << setfill('=') << setw(jmlStrip - 2) << "="
          << "\n";

     cout << setfill(' ')
          << "NIM" << setw(nim.length())
          << "|" << setw(6) << "Nama" << setw(nama.length())
          << "|" << setw(6) << "Plug" << setw(plug.length()) << "|"
          << "\n";

     cout << setfill('=') << setw(jmlStrip - 2) << "="
          << "\n";
     // ========== End Header ==========

     // ========== Row ==========
     cout << setfill(' ')
          << nim << setw(3)
          << "|" << setw(nama.length() + 2) << nama << setw(4) << "|"
          << setw(plug.length() + 2) << plug << setw(4) << "|"
          << "\n";

     cout << setfill('=') << setw(jmlStrip - 2) << "="
          << "\n";
     // ========= End Row ==========

     return 0;
}