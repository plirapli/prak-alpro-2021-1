#include <iostream>

using namespace std;

int main()
{
	int rowSize, colSize;

	cout << "Masukkan jumlah baris matriks A: ";
	cin >> rowSize;
	cout << "Masukkan jumlah kolom matriks A: ";
	cin >> colSize;
	cout << "\n";

	int a[rowSize][colSize],
			transposed[colSize][rowSize];

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			cout << "Masukkan matriks A[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> a[i][j];
		}
		cout << "\n";
	}
	system("CLS");

	cout << "Matriks A[" << rowSize << "][" << colSize << "]: \n";
	for (int i = 0; i < rowSize; i++)
	{
		cout << "[ ";
		for (int j = 0; j < colSize; j++)
			cout << a[i][j] << " ";
		cout << "] \n";
	}
	cout << "\n";

	cout << "Hasil transpose matriks A[" << colSize << "][" << rowSize << "]: \n";
	for (int i = 0; i < colSize; i++)
	{
		cout << "[ ";
		for (int j = 0; j < rowSize; j++)
		{
			transposed[i][j] = a[j][i];
			cout << transposed[i][j] << " ";
		}
		cout << "] \n";
	}

	return 0;
}