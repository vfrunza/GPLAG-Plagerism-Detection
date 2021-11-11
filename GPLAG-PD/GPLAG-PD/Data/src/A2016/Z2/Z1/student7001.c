#include <stdio.h>
#include <math.h>
int main() {
	int broj, x, brojac=0, n, i, y, novi_broj=0;
	printf ("Unesite broj: ");
	scanf ("%d", &broj);
	if (broj>=0 && broj<10) {
		printf ("0");
		return 0;
		}
	else if (broj<=0 && broj>-10) {
		printf ("0");
		return 0;
		}
	else {
		x=fabs(broj);
		while (x!=0) {
			x/=10;
			brojac++;
		}
		n=brojac;
		y=fabs(broj);
		for (i=0; i<n-1; i++) {
			novi_broj+=(fabs(y%10-(y/10)%10))*pow(10,i);
			y=y/10;
		}
		printf ("%d", novi_broj);
	}
	return 0;
}