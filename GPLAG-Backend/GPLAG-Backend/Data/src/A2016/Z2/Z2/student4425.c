#include <stdio.h>
#include <math.h>

#define PI 3.1415926
#define EPS 0.00001


int main() {
	
	int broj_uglova, i, j;
	double uglovi[500] = { 0 };
	double stepeni=0, stepeni_raw=0, minute=0, minute_raw=0, minute_raw1=0, sekunde=0, sekunde_raw=0;
	
	printf ("Unesite broj uglova: ");
	scanf ("%d", &broj_uglova);
	
	for (i = 0; i < broj_uglova; i++) {
		scanf ("%lf", &uglovi[i]);
	}
	
	for (i = 0; i < broj_uglova; i++) {
		
				stepeni_raw = fabs (uglovi[i] * 180. / PI);
		stepeni = trunc (stepeni_raw);
				minute_raw = (stepeni_raw - stepeni) * 60;
				minute_raw1 = trunc (minute_raw);
		minute = round (minute_raw);
				sekunde_raw = (minute_raw - minute_raw1) * 60;
		sekunde = round (sekunde_raw);
		
		if (fabs (sekunde - 60) < EPS || sekunde > 60) {
			sekunde = 0;
			minute = floor (minute_raw + 1);
			if (minute > 60 || fabs (minute - 60) < EPS) {
				minute = 0;
				stepeni+=1;
			}
		}
		
		if (sekunde - EPS > 30) {
			for (j = i; j < broj_uglova - 1; j++) {
				uglovi [j] = uglovi [j+1];
			}
			broj_uglova--;
			i--;
		}
	}
	
	printf ("Uglovi su: \n");
	
	for (i = 0; i < broj_uglova; i++) {
		
				stepeni_raw = fabs (uglovi[i] * 180. / PI);
		stepeni = trunc (stepeni_raw);
				minute_raw = (stepeni_raw - stepeni) * 60;
				minute_raw1 = trunc (minute_raw);
		minute = round (minute_raw);
				sekunde_raw = (minute_raw - minute_raw1) * 60;
		sekunde = round (sekunde_raw);
		
		if (fabs (sekunde - 60) < EPS || sekunde > 60) {
			sekunde = 0;
			minute = floor (minute_raw + 1);
			if (minute > 60 || fabs (minute - 60) < EPS) {
				minute = 0;
				stepeni+=1;
			}
		}
		
		if (fabs (sekunde - 30) < EPS) {
			minute = floor ((minute_raw)-EPS);
		}
		
		if (uglovi[i] < 0) stepeni = - stepeni;
		
		printf ("%g stepeni %g minuta %g sekundi\n", stepeni, minute, sekunde);
	}
	
	return 0;
}