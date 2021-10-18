#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int  broj_clanova, i, stepen, minuta, j;
	float  stepen1, minuta1, sekunda1, sekunda;
	double niz[500];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_clanova);
	
	for(i=0; i<broj_clanova; i++) {
		scanf("%lf", &niz[i]);
		}
	
	printf("Uglovi su: ");
	
	for(i=0; i<broj_clanova; i++) {
		
		stepen1=(niz[i]*180)/PI;
		stepen=(int)stepen1;
		minuta1=(stepen1-stepen)*60;
		minuta=(int)minuta1;
		sekunda1=(minuta1-minuta)*60;
		sekunda=round(sekunda1);
		if(fabs(sekunda)>59) {
			sekunda-=60;
			minuta++;
		}
		if(fabs(minuta)>59) {
			minuta-=60;
			stepen++;
		}
		
		if(fabs(sekunda)>30) {
			
			for(j=i; j<broj_clanova-1; j++) {
					niz[j]=niz[j+1];
			}
				broj_clanova--;
				i--;
				continue;
			}
	sekunda=fabs(sekunda);
	minuta=fabs(minuta);
	printf("\n%d stepeni %d minuta %g sekundi ", stepen, minuta, sekunda);
		
	}
	return 0;
}
