#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define KAPACITET 500
int main()
{
	double uglovi[KAPACITET];
	int i, j, brojUglova, h, m, s, y;
	printf("Unesite broj uglova: ");
	scanf ("%d", &brojUglova);

	for (i=0; i<brojUglova; i++) {
		scanf("\n%lf", &uglovi[i]);
	}

	for (i=0; i<brojUglova; i++) {
		y=(uglovi[i]*180*3600)/PI+0.5;
		h=y/3600;
		m=(y%3600)/60;
		s=(y%3600)%60;
		if (s>=60) {
			m++;
			s=abs(s)-60;
		}
		if (m>=60) {
			h++;
			m=abs(m)-60;
			
		}
		
		
		if (abs(s)>30) {
			for (j=i; j<brojUglova-1; j++) {
				uglovi[j]=uglovi[j+1];
			}
			brojUglova--;
			i--;

		}

	}

	printf ("Uglovi su:");
	for (i=0; i<brojUglova; i++) {
		y=(uglovi[i]*180*3600)/PI+0.5;
		h=y/3600;
		m=(y%3600)/60;
		s=(y%3600)%60;
		if (s>=60) {
			m++;
			s=abs(s)-60;
		}
		if (m>=60) {
			h++;
			m=abs(m)-60;
			
		}
		if (abs(s)>30) {
			for (j=i; j<brojUglova-1; j++) {
				uglovi[j]=uglovi[j+1];
			}
			brojUglova--;
			i--;

		}

		printf("\n%d stepeni %d minuta %d sekundi", h, abs(m), abs(s));
	}


	return 0;
}
