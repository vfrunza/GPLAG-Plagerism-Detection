#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	
	int n, i, j, minute, stepeni, sekunde; 
	double pom, z, y, niz[500];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		scanf("%lf", &niz[i]);
	}
	
	printf("Uglovi su:\n");
	
	for(i=0; i<n; i++) {
		pom=niz[i];
		pom=pom*(180/PI);
		stepeni=(int)pom;
		z=(pom-stepeni)*60;
		minute=(int)z;
		y=(z-minute)*60;
		minute=abs(minute);
		sekunde=round(y);
		sekunde=abs(sekunde);
		
		if(sekunde>30 && sekunde <60) {
			for(j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
			}
			n--;
			i--;
			continue;
		}
		else if(sekunde>=60) {
			sekunde=sekunde-60;
			minute=minute+1;
			if(minute>=60) {
				minute=minute-60;
				if(stepeni>0) stepeni=stepeni+1;
				else stepeni=stepeni-1;
			}
		}
		printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);
	}
	return 0;
}
