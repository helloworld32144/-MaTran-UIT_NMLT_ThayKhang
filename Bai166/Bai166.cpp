#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int ktCon(float[][100], int, int, int, int);
void ConDau(float[][100], int, int, int&, int&);
void MaTranCon(float[][100], int, int);

int main()
{
	float b[100][100];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	MaTranCon(b, k, l);

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
			//a[i][j] = -100.0 + (rand() / (RAND_MAX / (100.0 - (-100.0))));
			cin >> a[i][j];
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

int ktCon(float a[][100], int m, int n, int vtd, int vtc)
{
	int flag = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[vtd + i][vtc + j] <= 0)
				flag = 0;
	return flag;
}

void ConDau(float a[][100], int m, int n, int& vtd, int& vtc)
{
	for (vtd = 0; vtd <= m - 3; vtd++)
		for (vtc = 0; vtc <= n - 3; vtc++)
			if (ktCon(a, m, n, vtd, vtc) == 1)
				return;
	vtd = vtc = -1;
}

void MaTranCon(float a[][100], int m, int n)
{
	int vtd, vtc;
	ConDau(a, m, n, vtd, vtc);
	if (vtd < 0 || vtc < 0)
		cout << "\nKhong co ma tran thoa man" << endl;
	else
	{
		cout << "\nMa tran con 3x3 dau tien toan duong: " << endl;
		for (int i = vtd; i < vtd + 3; i++)
		{
			for (int j = vtc; j < vtc + 3; j++)
			{
				cout << setw(8);
				cout << setprecision(3);
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
}