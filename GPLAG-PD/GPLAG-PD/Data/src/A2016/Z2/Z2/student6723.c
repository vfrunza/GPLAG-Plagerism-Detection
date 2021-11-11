#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n,i,step,min,sek,j;
	float x,niz[500];
	do {
		printf("Unesite broj uglova: ");
	scanf("%d",&n); } while(n>500);
	for(i=0;i<n;i++) {
		scanf("%f",&niz[i]);
	}
	printf("Uglovi su:");
	for(i=0;i<n;i++) {
		x= fabs(niz[i]);
		x=x*180/PI;
		step=(int)x;
		min=(int)((x-step)*3600)/60;
		sek=(int)((x-step)*3600+0.5)/60;
		if (sek==60) { min++; }
		sek=(int)((x-step)*3600+0.5)%60;
		if(min==60) {step++;
		min=min%60; }
	
		if(sek>30) {
			for(j=i;j<n-1;j++) {
				niz[j]==niz[j+1];
			}
		}
		
else {
     if(niz[i]<0) printf("\n%d stepeni %d minuta %d sekundi", (-1)*step,min,sek);
	else printf("\n%d stepeni %d minuta %d sekundi",step,min,sek);
}
}
	return 0;
}
