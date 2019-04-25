/* Input a value and compute 
               Fibonacci number */

#include <stdio.h>
#include <conio.h>


int n, F, Fn_1 = 1, Fn_2 = 1;

/* Function Fibonacci
 * use dynamic programming and compute the nth Fibo number
 */
int Fibonacci() {
	if (n == 1 || n == 2) return 1;
	
	for (int i = 3; i <= n; i++) {
		F = Fn_2 + Fn_1;
		Fn_2 = Fn_1;
		Fn_1 = F;
	}
	return F;
}

int main() {
	printf("Nhap gia tri n = ", n);
	scanf("%d", &n);
	
	printf("F(%d) = %d", n, Fibonacci());
}
