#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define vel 500

int main() {
	int br, i, j;
	float niz[vel], hr, min, sec, rem, rem1;
	
	/*Unos broja uglova*/
	
	printf("Unesite broj uglova: ");
	scanf ("%d", &br);
	
	/*Unos uglova*/
	
	
	for (i = 0; i < br; i++) {
		scanf ("%f", &niz[i]);
	}
	
	printf ("Uglovi su: \n");
	
	for (i = 0; i < br; i++) {
		
		/*Racunanje radijana u stepene*/
		
		hr = niz[i] * (180 / PI);
		rem = hr - (int)hr;
		hr = (int)hr;
		min = rem * 60;
		rem1 = min - (int)min;
		min = (int)min;
		sec = rem1 * 60;
		
		/*Zaokruzivanje*/
		
		if (sec >= 59.5) {
			min++;
			sec = 0;
		}
		if (sec <= -59.5) {
			min--;
			sec = 0;
		}
		if (min >= 59.5) {
			hr++;
			min = 0;
		}
		if (min <= -59.5) {
			hr--;
			min = 0;
		}
		
		if (sec > 30 || sec < -30) {
			for (j = i; j < br; j++) {
				niz[j] = niz[j + 1];
			}
			i--;
			br--;
			continue;
		}
		
		if (min < 0) {
			min = -min;
		}
		
		if (sec < 0) {
			sec = -sec;
		}
		
		/*Ispis*/
		
	printf ("%.f stepeni %.f minuta %.f sekundi\n", hr, min, sec);
	}
	return 0;
}
