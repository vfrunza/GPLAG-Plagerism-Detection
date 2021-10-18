#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define BROJ_EL 500

int main() {
	double niz[BROJ_EL], a=0, b=0, c=0, d=0, f=0;
	int i, deg, min, sec, n=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su:");
	for(i=0; i<n; i++) {
		a=niz[i]*180/PI;
		deg=(int)a;
		d=fabs(a-deg);
		b=(d*60);
		min=(abs((int)b));
		c=b-min;
		f=c*60;
    sec=abs((int)(f+0.5));
		if(deg>0) {
		if(sec==60) {sec=0;
		min++;
		}
		if(min==60) {min=0;
		deg++;
		}
		}
		else if(deg<0) {
			if(sec==60) {sec=0;
			min++;
		}
		if(min==60) {min=0;
		deg--;
		}
		}

		
		if(sec<=30)printf("\n%d stepeni %d minuta %d sekundi", deg, min, sec);
	}

	return 0;
}