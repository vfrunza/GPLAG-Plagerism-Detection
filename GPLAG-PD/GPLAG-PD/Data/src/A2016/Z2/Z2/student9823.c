#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
/*
Kao što znamo, uglovi mogu biti predstavljeni u radijanima ili u stepenima.
Iz radijana se mogu dobiti stepeni tako što vrijednost pomnožimo sa 180/π. 
Svaki stepen se sastoji od 60 minuta, a svaka minuta od 60 sekundi.

Primjer ulaza i izlaza:
	Unesite broj uglova: 3
	1.2
	2.8
	2.0
	Uglovi su:
	68 stepeni 45 minuta 18 sekundi
	114 stepeni 35 minuta 30 sekundi


*/

int main() {
	int broj_uglova, stepeni;
	double e, e1=-0.5, e2=0.5;
	int i, j, cijeli;
	double niz[500], x;
	printf("Unesite broj uglova: ");
	do {
		scanf("%d", &broj_uglova);
	}while(broj_uglova<=0 || broj_uglova>500);
	
	for(i=0;i<broj_uglova;i++)
	{
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<broj_uglova;i++)
	{
		
		
		if(niz[i]<0) e=e1; 
		else e=e2;
		
		
		stepeni= (int)((niz[i]*180)/PI);
		
		cijeli = (int)((niz[i]*180)/PI);
		x=((niz[i]*180)/PI - cijeli);
		 
		long double minutes = x * 60.0;
		int min = (int)(minutes);
		 
		
		long double seconds = (minutes - min) * 60.0;
		int secondsINT = (int)(seconds+e);
		
		if(secondsINT>=60) { secondsINT-=60; min+=1; } else if(secondsINT<=-60) { secondsINT-=-60; min-=1; }
		if(min>=60) { stepeni+=1; min-=60;  } else if(min<=-60) { stepeni-=1; min-=-60; }
 		
 		minutes= fabs(minutes);
 		min = abs(min);
 		secondsINT= abs(secondsINT);
 		
 		//printf("%d ", stepeni);
		//printf("%g ", minutes);	
		//printf("%d ", secondsINT);
 		
 		// printf("%d ", min);
		
		// printf("%d ", seconds1); 0.977382 0.97738 -0.977382 -1
		
		if(secondsINT>30 || secondsINT<-30){
			
			for(j=i;j<broj_uglova-1;j++)
			{
				niz[j] = niz[j+1];
			}
			broj_uglova--;
			i--;
			
		} else  printf("%d stepeni %d minuta %d sekundi\n", stepeni, min, secondsINT); 
		
	}
	
	
	
	
	
	return 0;
}
