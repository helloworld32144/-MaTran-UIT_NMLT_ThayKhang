#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);

void DichTraiDong(float[][500], int, int, int);
void DichTrai(float[][500], int, int);

int main()
{
	float b[500][500];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	cout << "\nMa tran duoc dich trai xoay vong cac cot: " << endl;
	DichTrai(b, k, l);
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

void DichTraiDong(float a[][500], int m, int n, int d)
{
	float temp = a[d][0];
	for (int j = 0; j <= n - 2; j++)
		a[d][j] = a[d][j + 1];
	a[d][n - 1] = temp;
}

void DichTrai(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
		DichTraiDong(a, m, n, i);
}