#include <stdio.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

int main() {
	int x, c, radix = 1, rez = 0;
	
	printf("Unesite broj: ");
	
	scanf("%d", &x);
	
	x = abs(x);
	
	while (x >= 10) {
		c = x % 10;
		x /= 10;
		rez += radix * abs(c - x % 10);
		radix *= 10;
	}
	printf("%d", rez);
	
	return 0;
}