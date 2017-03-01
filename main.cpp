
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
	//cin >> n;
	n=4;
	cout << "Введите количество ребер m: ";
	//cin	>> m;
	m=4;
	cout << "Введите 1, если граф ориентированый или 0, если нет: ";
	cin >> s;
	cout << "Введите граф: " << endl;
	/*for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> A[i][j];
	}*/
     ////////////////////////////////
     A[0][0]=1;
     A[0][1]=2;
     A[1][0]= 2;
     A[1][1]=3;
     A[2][0]= 2;
     A[2][1]= 4;
     A[3][0]=3;
     A[3][1]=4;
     ////////////////

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
		if (s == 1)
            {
                if (q==w) c[q-1][j]=2;
        else
        {
			c[q - 1][j] = -1;
			c[w - 1][j] = 1;
        }
		     }
		else {
			c[q - 1][j] = 1;
			c[w - 1][j] = 1;
		}

	}

	cout << "Матрица инцидентности:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(4)<< c[i][j];
		cout << endl;
	}
///////////////////////////// Новый массив  для степени
 int Step [19], temp=0;

  for ( int i=0; i<n;i++)
  {
      for ( int j=0 ;j<m;j++)
      {
          if (c[i][j]!=0)
            temp++;
      }
      Step[i]=temp;
      temp=0;
       cout << "d(v"<<i+1<<") = "<<Step[i]<<endl;
  }

  ///PRIVET



	cin.get();
}
