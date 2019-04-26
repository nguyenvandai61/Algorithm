#include <stdio.h>

#define MAX 9

int coinValue[MAX] = {500, 200, 100, 50, 20,
 						10, 5, 2, 1};


void minCoin(int coinValue[MAX], int amount) {
	for (int i = 0; i < 9; i++) {
		while (amount >= coinValue[i]) {			
			amount = amount - coinValue[i];
			printf("%d ", coinValue[i]);
		}
	}		
}

int main() {
	int amount = 123;
	minCoin(coinValue, amount);
}
 


