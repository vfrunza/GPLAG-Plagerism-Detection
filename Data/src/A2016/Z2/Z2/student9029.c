#include <stdio.h>
#include <math.h>
#define PI 3.1415926


int main() {
	
	int broj_uglova, unos=0, stepeni, minute, sekunde, i;
	double radian, stepen_cijeli, niz[500], minute_cijele, sekunde_cijele;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_uglova);
	
	if(broj_uglova>500) return 0;
	
	
	while(unos<broj_uglova){
		
		scanf("%lf", &radian);
		stepen_cijeli=(180/PI)*radian;
		niz[unos]=stepen_cijeli;
		unos++;
		
	}
	
	printf("Uglovi su: \n");
	
	for(i=0;i<unos;i++){
		
		stepeni=niz[i];

		minute_cijele=(niz[i]-stepeni)*60;
		minute=minute_cijele;
	
		sekunde_cijele=(minute_cijele-minute)*60;
        sekunde=roundf(sekunde_cijele);

        if(minute==60){minute=0; stepeni++;}
        if(sekunde==60) { sekunde=0; minute++; if(minute==60){minute=0; stepeni++;}}
        
        if(minute==-60){minute=0; stepeni--;}
        if(sekunde==-60) { sekunde=0; minute--; if(minute==-60){minute=0; stepeni--;}}
        
        if(sekunde>30 || sekunde<-30) continue;
        
        printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);

	}
	
	return 0;
}
