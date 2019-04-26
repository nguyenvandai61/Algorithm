#include <iostream>
using namespace std;

int n;

void chuyen(int n, char x, char y, char z) {
	if (n==1) 
		cout << "Chuyen "<< x << " --> "<< y <<"\n";
	else{
	chuyen(n-1, x, z, y);
	chuyen(1, x, y, z);
	chuyen(n-1, z, y, x);
	}
}	

int main(){
	cin >> n;
	
	char x, y, z
	
	x = 'x';
	y = 'y';
	z = 'z';
	chuyen(n, x, y, z);
}
