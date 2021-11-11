#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int n,i,j;
	double niz[500];
	double stepeni1,stepeni,minute1,minute,sekunde1,sekunde2,sekunde;
	
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	for (i=0;i<n;i++) {
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su: ");
	for (i=0;i<n;i++) {
		stepeni1=niz[i]*180/PI;
		stepeni=(int)(stepeni1);
		minute1=fabs(stepeni1-stepeni)*60;
		minute=(int)fabs(minute1);
		sekunde1=(minute1-minute)*60;
		sekunde2=(int)(fabs(sekunde1)+0.5);
		sekunde=fabs(sekunde2);
	
	if (sekunde>=60) {
		sekunde-=60;
		minute++;
	}
	
	if (minute>=60) {
		minute-=60;
		if (stepeni<=0) stepeni--;
		else stepeni++;
	}
	if (sekunde<=30) printf("\n%g stepeni %g minuta %g sekundi",stepeni,minute,sekunde);
	if (sekunde>30) {
		for (j=i;j<n-1;j++) {
			niz[j]=niz[j+1];
		}
		n--;
		i--;
	}
		}
	
	return 0;
}
