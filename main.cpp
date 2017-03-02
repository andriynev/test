#define MIN(x,y) ((x)<(y)?(x):(y))
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
	//n=4;
	cout << "Введите количество ребер m: ";
	cin	>> m;
	//m=3;
	cout << "Введите 1, если граф ориентированый или 0, если нет: ";
	cin >> s;
	cout << "Введите граф: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> A[i][j];
	}
     ////////////////////////////////
     /*A[0][0]=1;
     A[0][1]=2;
     A[1][0]= 2;
     A[1][1]=3;
     A[2][0]= 3;
     A[2][1]= 4;*/
     ////////////////

	for (int i = 0; i < n; i++)
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
///////////////////////////// Новый массив  для степени SUMijnist
if (s==0)
{ int w[20],s[20],d=0,k=0;
 int Step [19], temp=0;

  for ( int i=0; i<n;i++)
  {
      for ( int j=0 ;j<m;j++)
      {
          if (c[i][j]!=0)
            temp++;
      }
      Step[i]=temp;
      if (temp==1) {w[d]=i;d++;}
      if(temp==0) {s[k]=i;k++;}
      temp=0;
       cout << "Степень вершины d(v"<<i+1<<") = "<<Step[i]<<endl;
  }
    for (int i=0;i<d;i++)
    cout <<"Вершина "<<"v"<<w[i]+1<<" --Висячая\n";
    for (int i=0;i<k;i++)
    cout <<"Вершина "<<"v"<<s[i]+1<<" --Изолирована\n";
    for (int i =0;i<=n;i++)
    if (Step[i]==Step[i+1])  {cout << "Система одрородная ";}
    else {cout<<"Система не однородная \n"; break; cout << endl;}
}
else
{ int temp1=0, temp2=0;

    int Step2 [20][2];
      for ( int i=0; i<n;i++)
  {
      for ( int j=0 ;j<m;j++)
      {
          if (c[i][j]==1) temp1++;
          if (c[i][j]==-1) temp2++;
          if (c[i][j]==2) {temp1++;temp2++;}
      }
      Step2[i][0]=temp1; //VHOD
      Step2[i][1]=temp2; // VIHOD
      temp1=0; temp2=0;
       cout << "Cтепень полувхода вершины  "<<i+1<<" = "<< Step2[i][0]<<endl;
       cout << "Cтепень полувыхода вершины "<<i+1<<" = "<< Step2[i][1]<<endl;
  }
}
///////////////////////////// Изолированые вершины
int prov=0;
for (int i=0;i<n;i++)
{
    for (int j=0;j<m;j++)
    {
    if (c[i][j]==0) prov++;
    }
        if(prov==m) cout <<"Вершина "<<i+1<<"- изолированая\n";
        prov=0;
}
/////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////////////////////////////*/
    int **edge = new int *[n];
    for (int i = 0; i < n; i++)
        edge[i] = new int [n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            edge[i][j] = b[i][j];
            if (!edge[i][j])
                edge[i][j] = 10000;
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    edge[i][j] = MIN(edge[i][j], edge[i][k]+edge[k][j]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (edge[i][j] == 10000)
                edge[i][j] = 0;
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }
    int min, max;
    int *ecc = new int [n];
    int *rad = new int [n];
    int *deg = new int [n];
    for (int i = 0; i < n; i++) {
        rad[i] = ecc[i] = 0;
        min = edge[i][1];
        max = edge[i][1];
        deg[i] = 0;
        for (int j = i+1; j < n; j++) {
            if(edge[i][j] < min)
            {
                min = edge[i][j];
            }
            if(edge[i][j] > max)
                max = edge[i][j];
        }
        deg[i] = min;
        ecc[i] = max;
    }

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(deg[i] == ecc[i])
                rad[j++] = i;
    }
    cout << "\nЦентры графа: ";
    for(int i = 0; i < j; i++)
        cout << rad[i]+1 << " ";
   ///////////////////////////////////
 int mi=999,ma=0,  l[n];
  for (int i=0;i<n;i++) l[i]=0; // Zero vector

  for (int i=0;i<n;i++) // Max in string AND print Matrix
    {
      l[i]=edge[i][0];
      for (j=0;j<n;j++)
       {
         if(edge[i][j]>l[i]) l[i]=edge[i][j];
       }
    }

  for (int i=0;i<n;i++)
    {
       if (mi>l[i]) mi=l[i];
       if (ma<l[i]) ma=l[i];
    }

  printf("\n\nRadius raven %i;",mi);
  printf("\nDiametr raven %i;",ma);




	cin.get();
}

