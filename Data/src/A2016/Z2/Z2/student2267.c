#include <stdio.h>
#include <math.h>
#define DUZINA 1000
#define PI 3.1415926

int main() {
	double niz[DUZINA], Sek, Min, x, y, z, t, r, e, l, o;
	int i, j, u;
	printf ("Unesite broj uglova: ");
	scanf ("%d", &u);
	for (j=0; j<u; j++) {
		scanf("%lf", &niz[j]);
	}
	printf("Uglovi su:\n");
    for (i=0; i<u; i++) {
    	niz[i] =  niz[i] * (180.00/PI);
    	y = niz[i]; 
    	z = (int) y;
    	x = y - z;
    	Min = x * 60.00;
    	t = Min;
    	r = (int) Min;
    	e = t - r;
    	r = fabs(r);
    	Sek = e * 60.00;
    	l = fabs(Sek) + 0.50;
    	l = (int) l;
    	o = fabs(l);
    	if (o >= 59.50) {
    			o = 0;
    		}
    	if (o > 30) {
    		for (j=i; j<u-1; j++) {
    			niz[j]=niz[j+1];
    		}
    		i--;
    		u--;
    		}

    }
    for (i=0;i<u;i++) {
    	y = niz[i]; 
    	z = (int) y;
    	x = y - z;
    	Min = x * 60.00;
    	t = Min;
    	r = (int) Min;
    	e = t - r;
    	r = fabs(r);
    	Sek = e * 60.00;
    	l = fabs(Sek) + 0.50;
    	l = (int) l;
    	o = fabs(l);
    	if (o >= 59.50) {
    			o = 0;
    			r++;
    		}
    		if (r >= 59.50) {
    			r = 0;
    			z++;
    		}
    		printf("%.0lf stepeni %.0lf minuta %.0lf sekundi\n", z, r, o);
    }
	return 0;
}
