#include <stdio.h>
#include <math.h>

int main() {
	int  k, y, z, q, i=0, x = 0;
	printf("Unesite broj: ");
	scanf("%d", &k);
	k = fabs(k);
	if (10 > k) {
		k = 0;
	}
	while (k > 9) {
		y = k % 10;
		z = ((k / 10) % 10);
		q = y - z;
		if (q < 0) {
			q = fabs(q);
		}
		x += q * (pow(10,i));
		i++;
		k = k / 10;
	}
	printf("%d", x);
	return 0;
}