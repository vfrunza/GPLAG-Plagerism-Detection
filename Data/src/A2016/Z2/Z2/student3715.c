#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int i,j,broj_uglova, stepeni=0,minuti=0,sekundi=0;
	double niz[500], ukupno_stepeni=0, ukupno_minuti=0, ukupno_sekundi=0;
	do{
	  printf("Unesite broj uglova: ");
	  scanf("%d", &broj_uglova);
	}while(broj_uglova<0 || broj_uglova>500);
	
	for(i=0;i<broj_uglova;i++)
	{
		scanf("%lf", &niz[i]);
	}
	for(i=0;i<broj_uglova;i++)
	{
		
		ukupno_stepeni = niz[i]*180/PI;
		stepeni = (int)ukupno_stepeni;
		ukupno_minuti = ukupno_stepeni - stepeni;
		ukupno_minuti = ukupno_minuti*60;
		minuti = abs((int)ukupno_minuti);
		ukupno_sekundi=fabs(ukupno_minuti) - minuti;
		ukupno_sekundi=ukupno_sekundi*60;
		sekundi = abs(round(ukupno_sekundi));
		
	
	if(sekundi==60){
		minuti++;
		sekundi=0;
	}
	if(minuti==60){
		if(stepeni<0){
			stepeni--;
		}else{
			stepeni++;
		}
		minuti=0;
	}

	if(sekundi>30){
		for(j=i;j<(broj_uglova-1);j++){
			niz[j]=niz[j+1];
		}
		broj_uglova--;
		i--;
	}
}
    printf("Uglovi su: \n");
	for(i=0;i<broj_uglova;i++){
		ukupno_stepeni = niz[i]*180/PI;
		stepeni = (int)ukupno_stepeni;
		ukupno_minuti = ukupno_stepeni - stepeni;
		ukupno_minuti = ukupno_minuti*60;
		minuti = abs((int)ukupno_minuti);
		ukupno_sekundi=fabs(ukupno_minuti) - minuti;
		ukupno_sekundi=ukupno_sekundi*60;
		sekundi = abs(round(ukupno_sekundi));
		
		
		if(sekundi==60){
		minuti++;
		sekundi=0;
	    }
	    if(minuti==60){
		   if(stepeni<0){
			  stepeni--;
		   }else{
			stepeni++;
		   }
	    	minuti=0;
	    }
	
	    printf("%d stepeni %d minuta %d sekundi\n",stepeni,minuti,sekundi);
		
	}
	
	
 return 0;	
}
