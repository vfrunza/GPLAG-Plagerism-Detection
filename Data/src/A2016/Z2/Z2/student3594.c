#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926


int main() {
	
	int i, broj_uglova, stepeni_cijeli_dio;
	float uglovi_u_radijanima[500], uglovi_u_stepenima[500];
	float konverzija, stepeni_decimalni_dio, minute, minute_decimalni_dio, sekunde;
	
	
	konverzija=(180.00f)/PI;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_uglova);
	
	if(broj_uglova<0 || broj_uglova>500){
		printf("Pogresan broj uglova");
		return 0;
	}
	
	for(i=0; i<broj_uglova; i++){
		scanf("%f", &uglovi_u_radijanima[i]);
	}
	printf("Uglovi su: ");
	
	for(i=0; i<broj_uglova; i++){
	
		uglovi_u_stepenima[i] = uglovi_u_radijanima[i]*konverzija;
		stepeni_cijeli_dio = (int)uglovi_u_stepenima[i];
		stepeni_decimalni_dio = uglovi_u_stepenima[i] - stepeni_cijeli_dio;
		
		minute = (int)(stepeni_decimalni_dio*60);
		minute_decimalni_dio = (stepeni_decimalni_dio*60) - minute;
		sekunde= roundf (minute_decimalni_dio*60);
	
		
		if(sekunde<0){
			sekunde*=-1;
		}
		if(minute<0){
			minute*=-1;
		}
		if((int)sekunde==60){
			sekunde-=60;
			minute+=1;
		}
		if((int)minute==60){
			minute-=60;
			if(stepeni_cijeli_dio>0) stepeni_cijeli_dio+=1;
		    else stepeni_cijeli_dio-=1;
			
		}
		
		if(sekunde<=30){

		printf("\n%d stepeni %g minuta %g sekundi", stepeni_cijeli_dio, minute, sekunde);
		}
		
	}
		
	

	
	return 0;
}
