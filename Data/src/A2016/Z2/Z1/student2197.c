#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
	int broj=0, i=0, m=0, n=0, r=0, k=0, brojac=1;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	broj=abs(broj);
	if(broj%10==0 && abs(broj/10==0)) k=0;
	else
	for (i=broj; i>9; i=i/10) {
		n=i%10;
		m=(i%100-n)/10;
		r=abs(m-n);
		k+=brojac*r;
		brojac*=10;
	}
	printf("%d", k);
	return 0;
}
