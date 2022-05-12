#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
int DemChuSo(int);
int DemCot(int[][100], int, int, int);
int DemLonNhat(int[][100], int, int);
void LietKe(int[][100], int, int);
int main()
{
	int b[100][100];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	cout << endl;
	LietKe(b, k, l);

	return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			//a[i][j] = -100.0 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
			cin >> a[i][j];
}

void Xuat(int a[][100], int m, int n)
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

int DemChuSo(int k)
{
	if (k == 0)
		return 1;
	int dem = 0;
	for (int t = k; t != 0; t = t / 10)
		dem++;
	return dem;
}

int DemCot(int a[][100], int m, int n, int c)
{
	int s = 0;
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		s = DemChuSo(a[i][c]);
		d += s;
	}
	return d;
}

int DemLonNhat(int a[][100], int n, int m)
{
	int lc = DemCot(a, n, m, 0);
	for (int j = 0; j < m; j++)
		if (DemCot(a, n, m, j) > lc)
			lc = DemCot(a, n, m, j);
	return lc;
}

void LietKe(int a[][100], int n, int m)
{
	cout << "\nCac cot co nhieu chu so nhat: ";
	int lc = DemLonNhat(a, n, m);
	for (int j = 0; j < m; j++)
		if (DemCot(a, n, m, j) == lc)
			cout << j << " ";
}
