#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

void DaoDong(float[][100], int, int, int);
void ChieuGuongDoc(float[][100], int, int);
int main()
{
	float b[100][100];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	cout << "\nMa tran duoc chieu guong theo truc doc: " << endl;
	ChieuGuongDoc(b, k, l);
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

void DaoDong(float a[][100], int m, int n, int d)
{
	int dd = 0;
	int cc = n - 1;
	while (dd < cc)
	{
		float temp = a[d][dd];
		a[d][dd] = a[d][cc];
		a[d][cc] = temp;
		dd++;
		cc--;
	}
}

void ChieuGuongDoc(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		DaoDong(a, m, n, i);
}
