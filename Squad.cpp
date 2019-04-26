#include <iostream>
#include <iomanip>
using namespace std;
#define NMAX 129

int n;
int table[NMAX][NMAX];

void schedule(int A[NMAX][NMAX], int n){
	// Hai doi thi dau
	if (n == 2) {
		A[1][1] = 2;
		A[2][1] = 1;
	}
	// Nhieu doi thi dau
	else {
		// Vung 1 tren
		int m;
		m = n/2;
		schedule(A, m);
		
		// Vung 2 duoi
		for (int i = m+1; i <= n; i++) {
			for (int j = 1; j <= m-1; j++) {
				A[i][j] = A[i-m][j] + m;
			}
		}
		
		//
		int x;
		for (int i = 1; i <= m; i++) {
			for (int j = m; j <= n-1; j++) {
				int x = i + j;	
				if (x > n)
					x-= m;
				// Vung 3 tren
				A[i][j] = x;  
				// Vung 4 duoi
				A[x][j] = i;
				
			}
		}
	}
}

void printTable(int A[NMAX][NMAX], int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n-1; j++) {
			cout << setw(3) << A[i][j];		
		}
		cout << endl;
	}
}


int main() {
	cin >> n;
	
	
	schedule(table, n);
	printTable(table, n);	
}


