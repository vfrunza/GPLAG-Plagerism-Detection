#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	
	int n, i, j, stepeni, minute, intsec;
	double uglovi[500], sekunde;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		scanf ("%lf", &uglovi[i]);
	}
	
	printf ("Uglovi su:\n");
	for (i=0; i<n; i++) {
		sekunde = fabs((180/PI)*uglovi[i]*3600);
		stepeni = (int)sekunde/3600;
		minute = (int)sekunde/60 - stepeni*60;
		intsec = (int)((sekunde - minute*60 - stepeni*3600) + .5);
		
		if (intsec>=60) {
			minute++;
			intsec = 0;
		}
		if (minute>=60) {
			stepeni++;
			minute = 0;
		}
		
		if (intsec > 30) {
			for (j=i; j<n; j++)
			uglovi[j] = uglovi[j+1];
			n--;
			i--;
		}
		else {
		if (uglovi[i]<0)
		stepeni = stepeni*(-1);
		printf ("%d stepeni %d minuta %d sekundi\n", stepeni, minute, intsec);
		}
	}
	
	return 0;
}
