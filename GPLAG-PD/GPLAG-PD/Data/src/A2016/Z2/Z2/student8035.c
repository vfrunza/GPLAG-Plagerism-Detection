#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926

int main() {
	int n, i, j, s, m, sec;
	double uglovi[500], stepeni;
	short neg;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		scanf("%lf", uglovi + i);
	}

	for (i = 0; i < n; ++i) {
		stepeni = uglovi[i] * (180./PI);
		
		neg = 0;
		if (stepeni < 0) {
			neg = 1;
			stepeni = fabs(stepeni);
		}
		
		s = (int)stepeni;
		m = (int)((stepeni - s) * 60);
		sec = (int)(((stepeni - s - m/60.) * 3600.) + 0.5);
		
		if (sec == 60) { sec = 0; ++m; }
		if (m == 60) { m = 0; ++s; }
		
		if (sec > 30) {
			for (j = i; j < n - 1; ++j) {
				uglovi[j] = uglovi[j + 1];
			}
			--n;
			--i;
		}
	}
	
	printf("Uglovi su:\n");
	for (i = 0; i < n; ++i) {
		stepeni = uglovi[i] * (180./PI);
		
		neg = 0;
		if (stepeni < 0) {
			stepeni = fabs(stepeni);
			neg = 1;
		}
		
		s = (int)stepeni;
		m = (int)((stepeni - s) * 60);
		sec = (int)(((stepeni - s - m/60.) * 3600.) + 0.5);
		
		if (sec == 60) { sec = 0; ++m; }
		if (m == 60) { m = 0; ++s; }
		
		if (neg) 
			printf("-%d stepeni %d minuta %d sekundi\n", s, m, sec);
		else
			printf("%d stepeni %d minuta %d sekundi\n", s, m, sec);
	}
	
	return 0;
}
