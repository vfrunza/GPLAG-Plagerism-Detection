#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, power;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n = abs(n);
	m = 0;
	if (n < 10) {
			m = 0;
	} else {
		power = 1;
		while (n > 9) {
			m += abs(n % 10 - (n / 10) % 10) *  power; 
			n /= 10;
			power *= 10;
		}
	}
	printf("%d", m);
	return 0;
}
