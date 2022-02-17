#include <iostream>

using namespace std;

int main()
{
	// * left align (standard)
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * hollow left align
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == 9 || j == 0 || j == i)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * inverted left align
	for (int i = 10; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * inverted hollow left align
	for (int i = 10; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (i == 10 || j == i - 1 || j == 0)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * right align
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j < 9 - i)
				cout << "  ";
			else
				cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * hollow right align
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 9 || j == 9 - i || j == 9)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * inverted right align
	for (int i = 10; i > 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j < 10 - i)
				cout << "  ";
			else
				cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * inverted hollow right align
	for (int i = 10; i > 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 10 || j == 10 - i || j == 9)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * triangle
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (j < 9 - i || j > 9 + i)
				cout << "  ";
			else
				cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * hollow triangle
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (i == 9 || j == 9 - i || j == 9 + i)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * inverted triangle
	for (int i = 10; i > 0; i--)
	{
		for (int j = 0; j < 19; j++)
		{
			if (j < 10 - i || j >= 9 + i)
				cout << "  ";
			else
				cout << "* ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * inverted hollow triangle
	for (int i = 10; i > 0; i--)
	{
		for (int j = 0; j < 19; j++)
		{
			if (i == 10 || j == 10 - i || j == 8 + i)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * hollow square star pattern with diagonal
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 || i == 9 || j == 9 - i || j == i || j == 0 || j == 9)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	cout << "\n";

	// * N with rectangle
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 || i == 9 || j == 0 || j == 9 || i == j)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "\n";
	}

	return 0;
}