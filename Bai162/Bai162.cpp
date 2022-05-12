#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void Xoay90(float[][100], int&, int&);
void Xoay180(float[][100], int&, int&);

int main()
{
	float b[100][100];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	cout << "\nMa tran duoc xoay mot goc 180 do: " << endl;
	Xoay180(b, k, l);
	Xuat(b, k, l);

	return 0;
}

void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = -100.0
			+ (rand() / (RAND_MAX / (100.0 - (-100.0))));
}

void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(3);
			cout << a[i][j];
		}
		cout << "\n";
	}
}

void Xoay90(float a[][100], int& m, int& n)
{
	float c[100][100];
	int q, r;

	q = n;
	r = m;
	for (int i = 0; i < q; i++)
		for (int j = 0; j < r; j++)
			c[i][j] = a[j][n - 1 - i];

	m = q;
	n = r;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = c[i][j];
}

void Xoay180(float a[][100], int& m, int& n)
{
	Xoay90(a, m, n);
	Xoay90(a, m, n);
}