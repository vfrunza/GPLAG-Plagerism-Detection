#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main () {
	float ugao[500];
	int i, n, j, stepeni, minute, sekunde;
	do {
		printf ("Unesite broj uglova: ");
		scanf ("%d", &n);
	} while (n<0 || n>499);
	for (i=0; i<n; i++) {
		scanf ("%f", &ugao[i]);
	}
	printf ("Uglovi su: ");
	for (i=0; i<n; i++) {
		ugao[i]=(float)(ugao[i]*180/PI);
		stepeni=(int)(ugao[i]);
		minute=(int)((fabs(ugao[i])-fabs(stepeni))*60);
		sekunde=(int)((((fabs(ugao[i])-fabs(stepeni))*60)-fabs(minute))*60 + 0.5);
		
		if (ugao[i]>0 && sekunde>=60) {
			minute++;
			sekunde-=60;
		}
		else if (ugao[i]<0 && sekunde>=60) {
			minute++;
			sekunde-=60;
		}
		if (ugao[i]>0 && minute>=60) {
			stepeni++;
			minute-=60;
		}
		else if (ugao[i]<0 && minute>=60) {
			stepeni--;
			minute-=60;
		}
		if (sekunde>30) {
			for (j=i; j<n-1; j++) {
				ugao[i]=ugao[i+1];
			}
			n--;
			i--;
		}
		else printf ("\n%d stepeni %d minuta %d sekundi", stepeni, minute, sekunde);
	}
	return 0;
}