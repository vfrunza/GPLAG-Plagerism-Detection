#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int i=0,stepen,minuta,sekunda,n,brojac=0;
	int stepeni[500],minute[500],sekunde[500];
	double niz[500],step,min,sek;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	printf("Uglovi su:\n");
	while(i<n) {
		scanf("%lf",&niz[i]);
		niz[i]*=(180/PI);
		step=niz[i];
		stepen=(int)step;
		min=fabs(step-stepen)*60;
		minuta=(int)min;
		sek=(min-minuta)*60;
		sekunda=(int)sek;
		if(fabs(sek-sekunda)>=0.5) sekunda++;
		if(sekunda==60) {
			sekunda=0;
			minuta++;
		}
		if(minuta==60) {
			minuta=0;
			if(stepen<=0) stepen--;
			else stepen++;
		}
		if(sekunda<=30) {
			printf("%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekunda);
			stepeni[brojac]=stepen;
			minute[brojac]=minuta;
			sekunde[brojac]=sekunda;
			brojac++;
		}
		i++;
	}
	return 0;
}