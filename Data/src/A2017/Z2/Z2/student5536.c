#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define broj 1000

int main() {
	int n, i, j; 
	double stepeni, minute, sekunde, niz[broj];
	printf ("Unesite broj uglova: ");
	scanf ("%d", &n);
	for (i=0; i<n; i++){
		scanf ("%lf", &niz[i]);
		niz[i] = niz[i] * (180/PI);
	}
	for (i=0; i<n; i++){
		stepeni = (int) niz[i];
		minute  = (niz[i] - stepeni) * 60;
		sekunde = (minute - (int) minute) * 60;
		if (sekunde > 0){
			sekunde = sekunde + 0.5;
		} else if (sekunde < 0){
			sekunde = sekunde - 0.5;
		}
		sekunde = (int) sekunde;
		if (fabs(sekunde) >= 59.5){
			sekunde = 0;
		}
		if (fabs(sekunde) > 30){
			for (j=i; j<n-1; j++){
				niz[j] = niz[j+1];
			}
			n--;
			i--;
		}
	}
	printf ("Uglovi su: \n");
	for (i=0; i<n ;i++){
		stepeni = (int) niz[i];
		minute  = (niz[i] - stepeni) * 60;
		sekunde = (minute - (int) minute) * 60;
		if (sekunde > 0){
			sekunde = sekunde + 0.5;
		} else if (sekunde < 0){
			sekunde = sekunde - 0.5;
		}
		sekunde = (int) sekunde;
		
		minute = (int) minute;
		if (sekunde >= 59.5){
			sekunde = 0;
			minute++;
		} else if (sekunde <= -59.5){
			sekunde = 0;
			minute--;
		}
		if (minute >= 59.5){
			minute=0;
			stepeni++;
		} else if (minute <= -59.5){
			minute = 0;
			stepeni--;
		}
		printf ("%.f stepeni ", stepeni);
		printf ("%.f minuta ", fabs(minute));
		printf ("%.f sekundi ", fabs(sekunde));
		printf ("\n");
	}
	
	return 0;
}
