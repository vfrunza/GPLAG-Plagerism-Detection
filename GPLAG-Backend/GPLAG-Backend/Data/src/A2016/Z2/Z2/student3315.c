#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#include <stdlib.h>

int main() {
	int k,broj_sekundi[500],broj_minuta[500],broj_stepeni[500],u;
	double niz[500],stepen,sekunda,minuta;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&u);
	
	/* Petlja pretvaranja stepeni u minute i sekunde */
	
	for(k=0;k<u;k++) {
		scanf("%lf",&niz[k]);
		broj_stepeni[k]=niz[k]*180/PI;
		stepen=fabs(niz[k]*180./PI)-abs(broj_stepeni[k]);
		
		broj_minuta[k]=stepen*60;
		minuta=stepen*60.-broj_minuta[k];
		
		sekunda=minuta*60.;
		broj_sekundi[k]=minuta*60;
	
		
		if(sekunda-abs(broj_sekundi[k])+0.5>=1) {
			broj_sekundi[k]++;
		}
		
		if(broj_sekundi[k]+0.05>=60) {
			broj_sekundi[k]=0;
			broj_minuta[k]++;
		}
		
		if(broj_minuta[k]+0.05>=60) {
			broj_minuta[k]=0;
			
			
		if(broj_stepeni[k]<0)
		   broj_stepeni[k]--;
		   else
		   broj_stepeni[k]++;
		}
		
		
		if(abs(broj_sekundi[k])>30) 
			niz[k]=(-1);
		
	}
		printf("Uglovi su: \n");
		for(k=0;k<u;k++) {
		if(niz[k]!=(-1)){
			printf("%d stepeni %d minuta %d sekundi\n",broj_stepeni[k],broj_minuta[k],broj_sekundi[k]);
		}
		
	}
	
	return 0;
	}
