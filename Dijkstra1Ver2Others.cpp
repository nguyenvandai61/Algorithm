
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define INF 32767
#define MAX 100
// Parameter n: Number of vertices
// Parameter a: starting Vertice - 1-a, 2-b
bool check[MAX];

void Read_File(int W[MAX][MAX], int &n, int &a)
{
	ifstream _File("Dijkstra1Ver2Others.txt");
	if (_File.is_open())
	{
	_File >> n >> a;
	cout << "Do thi nhap vao: " << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			_File >> W[i][j];
			if(W[i][j] != INF) cout << setw(4) << W[i][j];
			else cout << "NULL";
		}
		cout << endl;	
	}
	_File.close();
	}
	else {
		cout << "Khong tim thay File!";
	}	
}

void Dijkstra(int W[MAX][MAX], int &n, int &a)
{
	int L[MAX];
	int P[MAX];
	int minP = INF;
	int save;
	int num = n-1;
	
	for (int i = 1; i <= n; i++)
	{
		L[i] = INF; 
		P[i] = a;
	}
	L[a] = 0;
	check[a] = true;
	
	// -> D = [INF, 10, INF, 30, 100];
	int v = a;
	while (num > 0)
	{
		
	minP = INF;
	for (int u = 1; u <= n; u++)
	{
		if (!check[u]  ) {
			if (W[v][u]!=INF && L[u] > W[v][u] + L[v])
			{
				L[u] = W[v][u] + L[v];
				P[u] = v;
			}				
		
			if (L[u] < minP) {
				minP = L[u];
				save = u;
			}
		}
	}
	check[save] = true;
	v = save;
	num--;
	}
	
	
	cout << "Bang L" << endl;
	for (int v = 1; v <= n; v++)
		cout << L[v] << "  ";
	cout << endl;
	cout << "Bang P" << endl;
	for (int v = 1; v <= n; v++)
		cout << P[v] << "  ";
	cout << endl;
	
	for (int i = 1; i <= n; i++)
	{
		if (i != a) {
			cout << "Khoang cach tu " << a << " den " << i << ": " <<  L[i];
			cout << "     Theo duong: " << i; 
		
			int v = P[i];
			while (v != a)
			{
				cout << "<-" << v;
				v = P[v];
			}
			cout << "<-" << a <<endl;		
		}
	}
}

int main()
{
	int W[MAX][MAX], n, a;
	Read_File(W, n, a);
	Dijkstra(W, n, a);
}
