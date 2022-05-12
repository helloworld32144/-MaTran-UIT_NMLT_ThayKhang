#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void DaoCot(float[][100], int, int, int);
void ChieuGuongNgang(float[][100], int, int);
int main()
{
	float b[100][100];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	cout << "\nMa tran duoc chieu guong theo truc ngang: " << endl;
	ChieuGuongNgang(b, k, l);
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

void DaoCot(float a[][100], int m, int n, int c)
{
	int dd = 0;
	int cc = m - 1;
	while (dd < cc)
	{
		float temp = a[dd][c];
		a[dd][c] = a[cc][c];
		a[cc][c] = temp;
		dd++;
		cc--;
	}
}

void ChieuGuongNgang(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		DaoCot(a, m, n, i);
}
