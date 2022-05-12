#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);

int DemCon(float a[][100], int m, int n, float b[][100], int k, int l);

int main()
{
	float a[100][100], b[100][100];
	int m, k;
	int n, l;

	cout << "\nNhap ma tran A" << endl;
	Nhap(a, m, n);
	cout << "Ma tran A:";
	cout << "\n";
	Xuat(a, m, n);

	cout << "\nNhap ma tran B" << endl;
	Nhap(b, k, l);
	cout << "Ma tran B:";
	cout << "\n";
	Xuat(b, k, l);

	int dem = DemCon(a, m, n, b, k, l);
	cout << "\nSo lan xuat hien cua A trong B la: " << dem << endl;
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

int DemCon(float a[][100], int m, int n, float b[][100], int k, int l)
{
	if (m > k || n > l)
		return 0;
	int dem = 0;
	for (int d = 0; d <= k - m; d++)
		for (int c = 0; c <= l - n; c++)
		{
			int flag = 1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (b[d + i][c + j] != a[i][j])
						flag = 0;
			if (flag == 1)
				dem++;
		}
	return dem;
}
