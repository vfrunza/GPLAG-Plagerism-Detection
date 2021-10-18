#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define BROJ_EL 500

int main() {
	double niz[BROJ_EL], decst=0, decmin=0, decsek=0;
	int i, st, min, sek, n=0;
	printf ("Unesite broj uglova: ");
	scanf ("%d", &n);
	for (i=0; i<n; i++) {
		scanf ("%lf", &niz[i]);
	}
	printf ("Uglovi su:");
	for (i=0; i<n; i++) {
		decst=niz[i]*180/PI;
		st=(int)decst;
		decmin=fabs((decst-st)*60);
		min=(abs((int)decmin));
		decsek=fabs((decmin-min)*60);
		sek=abs((int)(decsek+0.5));
		if (st>0) {
		if (sek==60) {
			sek=0;
		min++;
	}
	if (min==60) {
		min=0;
		st++;
	}
	} else if (st<0) {
		if (sek==60) { 
			sek=0;
			min++;
			if(min==60){min=0;
			st--;
	}
		}
	}
	if (sek<=30) printf("\n%d stepeni %d minuta %d sekundi", st, min, sek);
	}	return 0;
}
