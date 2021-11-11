#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define bre 500

int main() {
	
	int i,n,stepeni,minute,sekunde,negativan=0;
	double niz[bre],step,min,sek;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++) {
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su: ");
	for(i=0;i<n;i++) {
		if(niz[i]<0) { negativan=1; niz[i]=fabs(niz[i]); }
		
		stepeni=(niz[i]*180)/PI;
		step=(niz[i]*180)/PI;
		
		minute=(step-stepeni)*60;
		min=(step-stepeni)*60;
		
		sek=(min-minute)*60;
		sekunde=sek+0.5;
		
		if(sekunde>=60) { sekunde=0; minute++;};
		if(minute>=60) { minute=0; stepeni++; }
		if(sekunde>30) {negativan=0; continue;}
		if(negativan == 1) { printf("\n-%d stepeni %d minuta %d sekundi",stepeni,minute,sekunde); negativan=0;continue; }
		else printf("\n%d stepeni %d minuta %d sekundi",stepeni,minute,sekunde);
		
	}

	return 0;
}
