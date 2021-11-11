#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	const double PI = 3.1415926;
	int broj_unosa = 0, broj_uglova = 0;
	int stepeni, minute, sekunde, i = 0, j = 0;
	double niz[500], decimalni_stepeni, d_sekunde;
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_uglova);
	
	for(; i < broj_uglova && i < 500; ++i)
		scanf("%lf", &niz[i]);

	broj_unosa = i;
	for(i = 0; i < broj_unosa; ++i){
		decimalni_stepeni = niz[i]*180/PI;
		stepeni = decimalni_stepeni;
		minute = (decimalni_stepeni - stepeni)*60;
		d_sekunde = (decimalni_stepeni - stepeni - minute / 60.) * 3600;
		sekunde = floor(d_sekunde + 0.5);
		
		if(abs(sekunde) == 60){
			sekunde = 0;
			minute += niz[i] < 0 ? -1 : 1 ;
		}
		if(abs(minute) == 60){
			minute = 0;
			stepeni += niz[i] < 0 ? -1 : 1 ;
		}
			
		if(abs(sekunde) > 30){
			for(j = i + 1; j < broj_unosa ; ++j){
				niz[j - 1] = niz [j];
			}
			--i;
			--broj_unosa;
		}
		
	}
	printf("Uglovi su: \n");
	for(i = 0; i < broj_unosa; ++i){
		decimalni_stepeni = niz[i]*180/PI;
		stepeni = decimalni_stepeni;
		minute = (decimalni_stepeni - stepeni)*60;
		d_sekunde = (decimalni_stepeni - stepeni - minute / 60.) * 3600;
		sekunde = floor(d_sekunde + 0.5);
		
		if(abs(sekunde) == 60){
			sekunde = 0;
			minute += niz[i] < 0 ? -1 : 1 ;
		}
		if(abs(minute) == 60){
			minute = 0;
			stepeni += niz[i] < 0 ? -1 : 1 ;
		}
		
		printf("%d stepeni %d minuta %d sekundi\n", stepeni, abs(minute), abs(sekunde));
		
	}
	
	return 0;
}
