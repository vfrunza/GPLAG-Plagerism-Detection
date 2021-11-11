#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,cifra1,cifra2,m=1,suma=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	cifra1=n%10;
	n=n/10;
	while(!(n==0)) {
		cifra2=n%10;
		suma+=abs(cifra1-cifra2)*m;
		m*=10;
		cifra1=cifra2;
		n=n/10;
	}
	printf("%d", suma);
	return 0;
}
