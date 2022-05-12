#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);

void DichXuongCot(float[][500], int, int, int);
void DichXuong(float[][500], int, int);

int main()
{
	float b[500][500];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	cout << "\nMa tran duoc dich xuong xoay vong cac hang: " << endl;
	DichXuong(b, k, l);
	Xuat(b, k, l);

	return 0;
}

void Nhap(float  a[][500], int& m, int& n)
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

void Xuat(float a[][500], int m, int n)
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

void DichXuongCot(float a[][500], int m, int n, int c)
{
	float temp = a[m - 1][c];
	for (int i = m - 1; i >= 1; i--)
		a[i][c] = a[i - 1][c];
	a[0][c] = temp;
}

void DichXuong(float a[][500], int m, int n)
{
	for (int j = 0; j < n; j++)
		DichXuongCot(a, m, n, j);
}