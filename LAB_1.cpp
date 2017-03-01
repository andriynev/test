#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int A[10][10]; 	
int b[10][10];
int c[10][10];
int n, m, s; 			
//=============== головна функцiя ================ 
int main()
{
	setlocale(0, "Russian");
	cout << "Введите количество вершин n: ";
	cin >> n;
	cout << "Введите количество ребер m: ";
	cin	>> m; 
	cout << "Введите 1, если граф ориентированый или 0, если нет: ";
	cin >> s;
	cout << "Введите граф: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> A[i][j];
	}

	
	for (int i = 0; i < m; i++)
	{
		int q =A[i][0];
		int w = A[i][1];
		if (s == 1) {
			b[q - 1][w - 1] = 1;
		}
		else {
			b[q - 1][w - 1]+= 1;
			b[w - 1][q - 1]+= 1;
		}
	}
	
	cout << "Матрица смежности:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << b[i][j];
		cout << endl;
	}
	cout << endl;

	
	for (int j = 0; j < m; j++)
	{
		int q = A[j][0];
		int w = A[j][1];
		if (s == 1){
			c[q - 1][j] += -1;
			c[w - 1][j] += 1;
		}
		else {
			c[q - 1][j] += 1;
			c[w - 1][j] += 1;
		}

	}

	cout << "Матрица инцидентности:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(4)<< c[i][j];
		cout << endl;
	}
	
	system("pause");
}
привет