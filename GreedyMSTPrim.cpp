// Prim’s Minimum Spanning Tree (MST) 
/*
1) Create a set mstSet that keeps track of vertices already included in MST.
2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. 
Assign key value as 0 for the first vertex so that it is picked first.
3) While mstSet doesn’t include all vertices
….a) Pick a vertex u which is not there in mstSet and has minimum key value.
….b) Include u to mstSet.
….c) Update key value of all adjacent vertices of u. To update the key 
values, iterate through all adjacent vertices. For every adjacent vertex v, 
if weight of edge u-v is less than the previous key value of v, update the
 key value as weight of u-v
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define INF 32767

int a[100][100];
int n; // So dinh cua do thi
int m; // So canh cua do thi
int sc; // So canh cua cay khung nho nhat
int w; // Do dai cay khung nho nhat
bool check[100];

int cck[100][3];
void nhap() {
	int i, j, k;
	ifstream _File("Prim.txt");
	if (_File.is_open()) {
		_File >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				a[i][j] = INF;
		}
		for (int p = 1; p <= m; p++) {
			_File >> i >> j >> k;
			a[i][j] = k;
			a[j][i] = k;
		}
		_File.close();
	}	
	else {
		cout << "Khong ton tai file!!";
	}
} 

void prim() {
	int k, top, min, l, t, u;
	int s[100];
	sc = 0; w = 0;
	u = 1;
	top = 1;
	s[top] = u;
	check[u] = true;
	
	
	while(sc < n - 1) {
		min = INF;
		
		for (int i = 1; i <= top; i++) {
			t = s[i];
			for (int j = 1; j <= n; j++) {
				if (!check[j] && min > a[t][j]) {
					min = a[t][j];
					k = t;
					l = j;
				}
			}
		}
		
		sc++;
		w = w + min;
		
		cck[sc][1] = k;
		cck[sc][2] = l;
		
		check[l] = false;
		top++;
		s[top] = l;
	}
}

void result() {
	cout << "Doi dai ngan nhat: " << w << endl;
	cout << "Cac canh cua cay khung nho nhat: " << endl;
	for (int i = 1; i <= sc; i++) {
		cout << cck[i][1] << " " << cck[i][2] << endl;
	}
}

int main() {
	nhap();
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(a[i][j] != INF) cout << setw(4) << a[i][j];
			else cout << "NULL";
		}
		cout << endl;	
	}
	
	prim();
	result();
}
