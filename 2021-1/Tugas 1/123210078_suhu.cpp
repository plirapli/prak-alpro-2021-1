#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  float r, f, c, k;

  // input data suhu celsius
  cout << "Konversi Suhu C++"
       << "\n"
       << "---------------------"
       << "\n";
  cout << "Masukkan Suhu (Celsius) : ";
  cin >> c;

  // Rumus konversi suhu
  r = (c * 4 / 5);
  f = (c * 9 / 5) + 32;
  k = c + 273;

  // Cetak hasil konversi
  cout << "Reamur" << setw(7) << ": " << r << " derajat R"
       << "\n";
  cout << "Fahrenheit" << setw(3) << ": " << f << " derajat F"
       << "\n";
  cout << "Kelvin" << setw(7) << ": " << k << " derajat K"
       << "\n";

  return 0;
}